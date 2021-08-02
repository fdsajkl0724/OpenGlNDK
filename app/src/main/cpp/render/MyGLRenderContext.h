//
// Created by Administrator on 2021-07-14.
//

#ifndef OPENGLNDK_MYGLRENDERCONTEXT_H
#define OPENGLNDK_MYGLRENDERCONTEXT_H
#include <GLES3/gl3.h>
#include <GLSampleBase.h>
#include <TriangleSample.h>
#include <TextureMapSample.h>
#include <NV21TextureMapSample.h>
#include <VaoSample.h>

class MyGLRenderContext {

    MyGLRenderContext();
    ~MyGLRenderContext();



public:
    static MyGLRenderContext *GetInstance();

    static void DestroyInstance();

    void OnSurfaceCreated();

    void OnSurfaceChanged(int width, int height);

    void OnDrawFrame();
    void SetImageData(int format, int width, int height, uint8_t *pData);

    void SetParamsInt(int paramType, int value0, int value1);

    void UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY);

    void SetImageDataWithIndex(int index, int format, int width, int height, uint8_t *pData);

    void SetParamsShortArr(short *const pShortArr, int arrSize);

    void SetParamsFloat(int paramType, float value0, float value1);


private:
    static MyGLRenderContext *m_pContext;
    GLSampleBase *m_pBeforeSample;
    GLSampleBase *m_pCurSample;
    int m_ScreenW;
    int m_ScreenH;

};


#endif //OPENGLNDK_MYGLRENDERCONTEXT_H
