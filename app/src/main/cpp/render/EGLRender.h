//
// Created by Administrator on 2021-07-15.
//

#ifndef OPENGLNDK_EGLRENDER_H
#define OPENGLNDK_EGLRENDER_H


#include <cstdint>
#include <GLES3/gl3.h>
#include <ImageDef.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>

#define EGL_FEATURE_NUM 7

class EGLRender {
public:
    EGLRender();

    ~EGLRender();

    void Init();

    void SetImageData(uint8_t *pData, int width, int height);

    void SetIntParams(int paramType, int param);

    void Draw();

    void DestroyGlesEnv();

    void UnInit();

    int CreateGlesEnv();

    static EGLRender *GetInstance() {
        if (m_Instance == nullptr) {
            m_Instance = new EGLRender();
        }

        return m_Instance;
    }

    static void DestroyInstance() {
        if (m_Instance) {
            delete m_Instance;
            m_Instance = nullptr;
        }

    }

private:
    static EGLRender *m_Instance;
    GLuint m_ImageTextureId;
    GLuint m_FboTextureId;
    GLuint m_FboId;
    GLuint m_VaoIds[1] = {GL_NONE};;
    GLuint m_VboIds[3] = {GL_NONE};;
    GLint m_SamplerLoc;
    GLint m_TexSizeLoc;
    NativeImage m_RenderImage;
    GLuint m_ProgramObj;
    GLuint m_VertexShader;
    GLuint m_FragmentShader;

    EGLConfig m_eglConf;
    EGLSurface m_eglSurface;
    EGLDisplay m_eglDisplay;
    EGLContext m_eglCtx;
    bool m_IsGLContextReady;
    const char *m_fShaderStrs[EGL_FEATURE_NUM];
    int m_ShaderIndex;

};


#endif //OPENGLNDK_EGLRENDER_H
