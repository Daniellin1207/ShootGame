#pragma once

#include <vector>
#include <string>
#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
	Model(std::string path);
	void loadModel(std::string path);
	~Model();
	std::vector<Mesh> meshes;
	std::string directory;
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
};

