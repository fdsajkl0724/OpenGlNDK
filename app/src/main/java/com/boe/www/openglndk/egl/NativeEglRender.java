package com.boe.www.openglndk.egl;

/**
 * Author：HS Create on: 2021-07-15 16:21 description：NativeEglRender email:
 */
public class NativeEglRender {
    // 初始化创建 GLES 环境
    public native void native_EglRenderInit();

    public native void native_EglRenderSetImageData(byte[] data, int width, int height);

    public native void native_EglRenderSetIntParams(int paramType, int param);

    public native void native_EglRenderDraw();

    public native void native_EglRenderUnInit();
}
