//
// Created by Administrator on 2021-07-14.
//

#ifndef OPENGLNDK_NV21TEXTUREMAPSAMPLE_H
#define OPENGLNDK_NV21TEXTUREMAPSAMPLE_H


#include "GLSampleBase.h"
#include "../util/ImageDef.h"

class NV21TextureMapSample : public GLSampleBase {
public:
    NV21TextureMapSample() {
        m_yTextureId = GL_NONE;
        m_uvTextureId = GL_NONE;

        m_ySamplerLoc = GL_NONE;
        m_uvSamplerLoc = GL_NONE;

    }
    virtual ~NV21TextureMapSample()
    {
        NativeImageUtil::FreeNativeImage(&m_RenderImage);
    }

    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();

    virtual void Draw(int screenW, int screenH);

    virtual void Destroy();



private:
    GLuint m_yTextureId;
    GLuint m_uvTextureId;

    GLint m_ySamplerLoc;
    GLint m_uvSamplerLoc;

    NativeImage m_RenderImage;


};



#endif //OPENGLNDK_NV21TEXTUREMAPSAMPLE_H
