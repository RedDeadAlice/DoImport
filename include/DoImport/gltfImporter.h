#pragma once
#include<rapidjson/document.h>
#include<sstream>
#include<fstream>
#include<iostream>
using namespace std;
using namespace rapidjson;
namespace DoImport{
    class GltfImporter{
private:
        struct Attributes{
            float* positionVectors;
            float* normals;
            float* UV_0_Coords;
            int positionVectorsCount;
            int normalsCount;
            int UV_0_CoordsCount;
        };
        struct Primitvies
        {
            Attributes* attributes;
            unsigned short* indices;
            int indicesCount;
        };
        struct Mesh{
            const char* name;
            Primitvies * primitives;
        };
        struct Node{
            const char* name;
            Mesh* mesh;
        };
        struct Scene{
            const char* name;
            Node* nodes;
            int nodesCount;
        };
        struct Gltf
        {
            Scene* scene;
        };
        stringstream sStream;
        char* readDataFromAccessor(int accessor,int& count,const Document& gltfFile);
        Gltf gltf;
        string gltfFilePath;
public:
        GltfImporter(char*);
        ~GltfImporter();
        float* getPositionVectors(unsigned int& count,int nodeIndex);
        float* getPositionVectors(unsigned int& count,const char* nodeName);  
        float* getNormals(unsigned int& count,int nodeIndex);
        float* getNormals(unsigned int & count,const char* nodeName);
        float* getUV0Coords(unsigned int& count,int nodeIndex);
        float* getUV0Coords(unsigned int& count,const char* nodeName);
        unsigned short* getFacesIndices(unsigned int& count,int nodeIndex);
        unsigned short* getFacesIndices(unsigned int& count,const char* nodeName);
    };
}