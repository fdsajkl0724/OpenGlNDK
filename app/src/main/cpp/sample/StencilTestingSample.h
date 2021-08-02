//
// Created by Administrator on 2021-07-16.
//

#ifndef OPENGLNDK_STENCILTESTINGSAMPLE_H
#define OPENGLNDK_STENCILTESTINGSAMPLE_H


#include <detail/type_mat.hpp>
#include <vec3.hpp>
#include <detail/type_mat4x4.hpp>
#include "GLSampleBase.h"

class StencilTestingSample : public GLSampleBase{
public:
    StencilTestingSample();

    virtual ~StencilTestingSample();

    virtual void LoadImage(NativeImage *pImage);

    virtual void Init();
    virtual void Draw(int screenW, int screenH);

    virtual void Destroy();

    virtual void UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY);

    void UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float ratio);

    void UpdateMatrix(glm::mat4 &mvpMatrix, glm::mat4 &modelMatrix, int angleXRotate, int angleYRotate, float scale, glm::vec3 transVec3, float ratio);
private:
    GLuint m_TextureId;
    GLint m_SamplerLoc;
    GLint m_MVPMatLoc;
    GLint m_ModelMatrixLoc;
    GLint m_ViewPosLoc;

    GLuint m_VaoId;
    GLuint m_VboIds[1];
    NativeImage m_RenderImage;
    glm::mat4 m_MVPMatrix;
    glm::mat4 m_ModelMatrix;

    int m_AngleX;
    int m_AngleY;

    GLuint m_FrameProgramObj;
};


#endif //OPENGLNDK_STENCILTESTINGSAMPLE_H
