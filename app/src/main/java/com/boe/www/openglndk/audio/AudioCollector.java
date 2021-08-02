package com.boe.www.openglndk.audio;

import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.os.Handler;
import android.os.Looper;

/**
 * Author：HS Create on: 2021-07-22 16:14 description：AudioCollector email:
 */
public class AudioCollector implements AudioRecord.OnRecordPositionUpdateListener {
    private static final String TAG = "AudioRecorderWrapper";
    private static final int RECORDER_SAMPLE_RATE = 44100;
    private static final int RECORDER_CHANNELS = 1;
    private static final int RECORDER_ENCODING_BIT = 16;
    private static final int RECORDER_AUDIO_ENCODING = AudioFormat.ENCODING_PCM_16BIT;
    private AudioRecord mAudioRecord;
    private Thread mThread;
    private short[] mAudioBuffer;
    private Handler mHandler;
    private int mBufferSize;
    private Callback mCallback;

    public AudioCollector() {
        mBufferSize = 2 * AudioRecord.getMinBufferSize(RECORDER_SAMPLE_RATE,
                RECORDER_CHANNELS, RECORDER_AUDIO_ENCODING);
    }

    public void init() {
        mAudioRecord = new AudioRecord(MediaRecorder.AudioSource.MIC, RECORDER_SAMPLE_RATE, RECORDER_CHANNELS, RECORDER_AUDIO_ENCODING, mBufferSize);
        mAudioRecord.startRecording();
        mThread = new Thread("Audio-Recorder") {
            @Override
            public void run() {
                super.run();
                mAudioBuffer = new short[mBufferSize];
                Looper.prepare();
                mHandler = new Handler(Looper.myLooper());
                mAudioRecord.setRecordPositionUpdateListener(AudioCollector.this, mHandler);
                int bytePerSample = RECORDER_ENCODING_BIT / 8;
                float samplesToDraw = mBufferSize / bytePerSample;
                mAudioRecord.setPositionNotificationPeriod((int) samplesToDraw);
                mAudioRecord.read(mAudioBuffer, 0, mBufferSize);
                Looper.loop();
            }
        };
        mThread.start();
    }

    public void unInit() {
        if(mAudioRecord != null) {
            mAudioRecord.stop();
            mAudioRecord.release();
            mHandler.getLooper().quitSafely();
            mAudioRecord = null;
        }
    }

    public void addCallback(Callback callback) {
        mCallback = callback;
    }


    @Override
    public void onMarkerReached(AudioRecord recorder) {

    }

    @Override
    public void onPeriodicNotification(AudioRecord recorder) {
        if (mAudioRecord.getRecordingState() == AudioRecord.RECORDSTATE_RECORDING
                && mAudioRecord.read(mAudioBuffer, 0, mAudioBuffer.length) != -1)
        {
            if(mCallback != null)
                //通过接口回调将音频数据传到 Native 层
                mCallback.onAudioBufferCallback(mAudioBuffer);
        }

    }

    public interface Callback {
        void onAudioBufferCallback(short[] buffer); //little-endian
    }
}

