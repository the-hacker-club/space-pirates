#pragma once
#include "_warpEngine.h"

#include "vAttribute.h"
#include <vector>

using namespace std;

namespace WarpEngine
{

    class VertexData
    {
    public:
		vector<float> * vertices;
		vector<int> * indices;
        vector<vAttribute> * vAttributes;

        VertexData(vector<float> * vertices, vector<vAttribute> * vAttributes);
        VertexData(vector<float> * vertices, vector<int> * indices, vector<vAttribute> * vAttributes);
        ~VertexData();
    };
}
