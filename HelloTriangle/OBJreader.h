#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Material.h"
using namespace std;

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class OBJreader
{
protected:


public:
	OBJreader();
	~OBJreader();

	OBJreader(string path, vector<GLfloat>* vertices, vector<GLuint>* EBO, vector<GLfloat>* normals);

	//OBJreader(string path, Object3D* p_object);
};

