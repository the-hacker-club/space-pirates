#include "vAttribute.h"

namespace WarpEngine
{

    vAttribute::vAttribute(unsigned int index, int size, vType type, bool normalized, int stride, int offset):
        index(index), size(size), type(type), normalized(normalized), stride(stride), offset(offset)
    {

    }

    vAttribute::~vAttribute()
    {

    }

    void vAttribute::enable()
    {
        size_t stride;
        if (type == vType::FLOAT) {
            stride = this->stride * sizeof(float);
        }

        size_t offset;
        if (type == vType::FLOAT) {
            offset = this->offset * sizeof(float);
        }

        glVertexAttribPointer(index, size, (GLenum)type, normalized, stride, (void*)offset);
        glEnableVertexAttribArray(index);
    }

    void vAttribute::disable()
    {

    }
}
