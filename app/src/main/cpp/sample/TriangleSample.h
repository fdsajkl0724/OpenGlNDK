//
// Created by Administrator on 2021-07-14.
//

#ifndef OPENGLNDK_TRIANGLESAMPLE_H
#define OPENGLNDK_TRIANGLESAMPLE_H


#include "GLSampleBase.h"

class TriangleSample : public GLSampleBase{
public:
    TriangleSample();
    virtual ~TriangleSample();

    virtual void Init();

    virtual void Draw(int screenW, int screenH);
    virtual void Destroy();
};


#endif //OPENGLNDK_TRIANGLESAMPLE_H
