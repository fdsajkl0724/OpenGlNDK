//
// Created by Administrator on 2021-07-14.
//

#ifndef OPENGLNDK_VAOSAMPLE_H
#define OPENGLNDK_VAOSAMPLE_H


#include "GLSampleBase.h"

class VaoSample: public GLSampleBase {
public:
    VaoSample();

    virtual ~VaoSample();

    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();
    virtual void Draw(int screenW, int screenH);
    virtual void Destroy();

private:
    GLuint  m_VaoId;
    GLuint  m_VboIds[2];
};


#endif //OPENGLNDK_VAOSAMPLE_H
