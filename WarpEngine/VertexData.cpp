#include "VertexData.h"

namespace WarpEngine
{
    VertexData::VertexData(vector<float> * vertices, vector<vAttribute> * vAttributes): VertexData(vertices, NULL, vAttributes)
    {

    }

    VertexData::VertexData(vector<float> * vertices, vector<int> * indices, vector<vAttribute> * vAttributes): vertices(vertices), indices(indices), vAttributes(vAttributes)
    {
        // TODO: add a check to make sure vAttributes is not null
    }

    VertexData::~VertexData()
    {

    }
}
