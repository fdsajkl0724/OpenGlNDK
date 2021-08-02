//
// Created by Administrator on 2021-07-26.
//

#ifndef OPENGLNDK_RGB2YUVSAMPLE_H
#define OPENGLNDK_RGB2YUVSAMPLE_H


#include "GLSampleBase.h"

class RGB2YUVSample : public GLSampleBase{
public:
    RGB2YUVSample();

    virtual ~RGB2YUVSample();

    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();
    virtual void Draw(int screenW, int screenH);

    virtual void Destroy();

    bool CreateFrameBufferObj();

private:
    GLuint m_ImageTextureId;
    GLuint m_FboTextureId;
    GLuint m_FboId;
    GLuint m_VaoIds[2] = {GL_NONE};
    GLuint m_VboIds[4] = {GL_NONE};
    GLint m_SamplerLoc;
    NativeImage m_RenderImage;
    GLuint m_FboProgramObj;
    GLuint m_FboVertexShader;
    GLuint m_FboFragmentShader;
    GLint m_FboSamplerLoc;
    //GLuint m_YuyvWidth;
};


#endif //OPENGLNDK_RGB2YUVSAMPLE_H