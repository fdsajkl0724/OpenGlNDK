//
// Created by Administrator on 2021-07-26.
//

#ifndef OPENGLNDK_SHAREDEGLCONTEXTSAMPLE_H
#define OPENGLNDK_SHAREDEGLCONTEXTSAMPLE_H


#include "GLSampleBase.h"
#include <thread>
#include <GLRenderLooper.h>

using namespace std;
class SharedEGLContextSample : public GLSampleBase {
public:
    SharedEGLContextSample();

    virtual ~SharedEGLContextSample();

    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();
    virtual void Draw(int screenW, int screenH);

    virtual void Destroy();

    static void OnAsyncRenderDone(void* callback, int fboTexId);

private:
    GLuint m_ImageTextureId;
    GLuint m_FboTextureId;
    GLuint m_VaoId;
    GLuint m_VboIds[4];
    NativeImage m_RenderImage;
    GLuint m_FboProgramObj;

    mutex m_Mutex;
    condition_variable m_Cond;
    GLEnv m_GLEnv;
};


#endif //OPENGLNDK_SHAREDEGLCONTEXTSAMPLE_H
