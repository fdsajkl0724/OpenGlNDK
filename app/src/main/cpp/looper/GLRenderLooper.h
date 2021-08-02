//
// Created by Administrator on 2021-07-26.
//

#ifndef OPENGLNDK_GLRENDERLOOPER_H
#define OPENGLNDK_GLRENDERLOOPER_H

#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <mutex>
#include "Looper.h"
#include <EglCore.h>
#include <OffscreenSurface.h>
#include <ImageDef.h>
using namespace std;

enum {
    MSG_SurfaceCreated,
    MSG_SurfaceChanged,
    MSG_DrawFrame,
    MSG_SurfaceDestroyed,
};

typedef void (*RenderDoneCallback)(void*, int);

struct GLEnv {
    GLuint inputTexId;
    GLuint program;
    GLuint vboIds[3];
    EGLContext sharedCtx;
    SizeF imgSize;
    RenderDoneCallback renderDone;
    void* callbackCtx;
};
class GLRenderLooper :public Looper{
public:
    GLRenderLooper();
    virtual ~GLRenderLooper();

    static GLRenderLooper* GetInstance();
    static void ReleaseInstance();

private:
    virtual void handleMessage(LooperMessage *msg);

    void OnSurfaceCreated();
    void OnSurfaceChanged(int w, int h);
    void OnDrawFrame();
    void OnSurfaceDestroyed();

    bool CreateFrameBufferObj();

private:
    static mutex m_Mutex;
    static GLRenderLooper* m_Instance;

    GLEnv *m_GLEnv;
    EglCore *m_EglCore = nullptr;
    OffscreenSurface *m_OffscreenSurface = nullptr;
    GLuint m_VaoId;
    GLuint m_FboTextureId;
    GLuint m_FboId;
    int m_FrameIndex = 0;
};


#endif //OPENGLNDK_GLRENDERLOOPER_H
