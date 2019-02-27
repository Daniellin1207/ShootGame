#include "pch.h"
#include "Model.h"
#include <cstdio>


//Model::Model(std::string path)
//{
//	loadModel(path);
//}
//
//void Model::loadModel(std::string path)
//{
//	Assimp::Importer importer;
//	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
//	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
//		printf("Assimp error\n");
//		return;
//	}
//	directory = path.substr(0, path.find_last_of("\\"));
//	processNode(scene->mRootNode, scene);
//}
//
//Model::~Model()
//{
//}
//
//void Model::processNode(aiNode * node, const aiScene * scene)
//{
//	//printf("%s\n", node->mName.data);
//	for (unsigned int i = 0; i < node->mNumMeshes; i++)
//	{
//		aiMesh* curMesh = scene->mMeshes[node->mMeshes[i]];
//		meshes.push_back(processMesh(curMesh, scene));
//	}
//	for (unsigned int i = 0; i < node->mNumChildren; i++)
//	{
//		processNode(node->mChildren[i], scene);
//	}
//}
//
//Mesh Model::processMesh(aiMesh* mesh, const aiScene * scene)
//{
//	std::vector<Vertex> tempVertices;
//	std::vector<unsigned int> tempIndices;
//	std::vector<Texture> tempTextures;
//
//	glm::vec3 tempVec;
//	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
//	{
//		Vertex tempVertex;
//
//		tempVertex.Position.x = mesh->mVertices[i].x;
//		tempVertex.Position.y = mesh->mVertices[i].y;
//		tempVertex.Position.z = mesh->mVertices[i].z;
//
//		tempVertex.Normal.x = mesh->mNormals[i].x;
//		tempVertex.Normal.y = mesh->mNormals[i].y;
//		tempVertex.Normal.z = mesh->mNormals[i].z;
//
//		if (mesh->mTextureCoords[0])
//		{
//			tempVertex.Textures.x = mesh->mTextureCoords[0][i].x;
//			tempVertex.Textures.y = mesh->mTextureCoords[0][i].y;
//		}
//		else {
//			tempVertex.Textures = glm::vec2(0, 0);
//		}
//		tempVertices.push_back(tempVertex);
//	}
//
//	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
//	{
//		for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
//		{
//			tempIndices.push_back(mesh->mFaces[i].mIndices[j]);
//		}
//	}
//
//	return Mesh(tempVertices,tempIndices);
//}
