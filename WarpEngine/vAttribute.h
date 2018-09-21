#pragma once
#include "_warpEngine.h"
#include <glad\glad.h>

namespace WarpEngine
{
    enum class vType
    {
        // TODO enum type for each GLTYPE
        FLOAT = GL_FLOAT
    };

    // See https://learnopengl.com/Getting-started/Shaders
    // for more info on glVertexAttribPointer, which is what
    // this class is for
    class vAttribute
    {
    private:
        unsigned int index;
        int size;
        vType type;
        bool normalized;
        int stride;
        int offset;

    public:
        WARPENGINE_API vAttribute(unsigned int index, int size, WarpEngine::vType type, bool normalized, int stride, int offset);
        WARPENGINE_API ~vAttribute();
        WARPENGINE_API void enable();
        WARPENGINE_API void disable();
    };
}