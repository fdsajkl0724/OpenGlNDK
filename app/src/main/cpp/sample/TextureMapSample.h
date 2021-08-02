//
// Created by Administrator on 2021-07-14.
//

#ifndef OPENGLNDK_TEXTUREMAPSAMPLE_H
#define OPENGLNDK_TEXTUREMAPSAMPLE_H


#include <ImageDef.h>
#include "GLSampleBase.h"

class TextureMapSample: public GLSampleBase {

public:
    TextureMapSample();
    virtual ~TextureMapSample();
    virtual void Init();

    virtual void Draw(int screenW, int screenH);
    void LoadImage(NativeImage *pImage);
    virtual void Destroy();

private:
    GLuint m_TextureId;
    GLint m_SamplerLoc;
    NativeImage m_RenderImage;



};


#endif //OPENGLNDK_TEXTUREMAPSAMPLE_H
