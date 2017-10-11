#pragma once

#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


class Material
{
public:
	Material();
	Material(GLfloat ka, GLfloat ks, GLfloat kb);
	~Material();

	GLfloat ka, ks, kd;
	GLuint textureID;


};

