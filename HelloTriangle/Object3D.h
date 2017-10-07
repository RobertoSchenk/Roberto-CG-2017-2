#pragma once
#include "OBJreader.h"
#include "Time.h"


class Object3D
{
private:
	vector<GLfloat> vertexi;
	vector<GLfloat> normals;
	vector<GLuint> indicies;
	glm::mat4 translate, scale, rotation;
	glm::vec3 scaleVector;
	void Initialize(string filePath);


public:
	Object3D();
	~Object3D();
	Object3D(string path);
	Object3D(string path, glm::vec3);
	Object3D(string path, float x, float y, float z);
	void Translate(glm::vec3 translation);
	void Translate(float x, float y, float z);
	void Rotate(float x, float y, float z);
	void Scale(float x, float y, float z);
	void SetScale(float x, float y, float z);
	glm::mat4 GetModelMatrix();
	int GetFacesToDraw();
	
	GLuint VAO, EBO, VBO, nVBO;
};

