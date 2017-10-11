#include "Material.h"



Material::Material()
{
	glGenTextures(1, &textureID);

}

Material::Material(GLfloat ka, GLfloat ks, GLfloat kb)
{

}


Material::~Material()
{
}
