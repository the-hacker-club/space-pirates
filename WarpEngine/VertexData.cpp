#include "VertexData.h"

namespace WarpEngine
{
    VertexData::VertexData(vector<float> * vertices, vector<vAttribute> * vAttributes): VertexData(vertices, NULL, vAttributes)
    {

    }

    VertexData::VertexData(vector<float> * vertices, vector<int> * indices, vector<vAttribute> * vAttributes): vertices(vertices), indices(indices), vAttributes(vAttributes)
    {

    }

    VertexData::~VertexData()
    {

    }
}
