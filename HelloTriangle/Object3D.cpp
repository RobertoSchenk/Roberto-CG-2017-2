#include "Object3D.h"



Object3D::Object3D()
{
}


Object3D::~Object3D()
{
}

Object3D::Object3D(string path)
{
	Initialize(path);

}

void Object3D::Initialize(string path)
{
	OBJreader* objReader_ptr = new OBJreader(path, &vertexi, &indicies, &normals);
	delete objReader_ptr;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &nVBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexi.size() * sizeof(GLfloat), vertexi.data(), GL_STATIC_DRAW); //pegamos o tamanho do vector dos vertices e usamos o .data() para acessar os dados do vector

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(GLuint), indicies.data(), GL_STATIC_DRAW); //pegamos o tamanho do EBO e passamos seu valores tambem

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);


	glBindBuffer(GL_ARRAY_BUFFER, nVBO);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(GLfloat), normals.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
	glEnableVertexAttribArray(1);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	scaleVector.x = 1;
	scaleVector.z = 1;
	scaleVector.y = 1;
	Translate(glm::vec3(0, 0, 0));
}

Object3D::Object3D(string path, glm::vec3 position)
{
	Initialize(path);
	Translate(position);
}

Object3D::Object3D(string path, float x, float y, float z)
{
	Initialize(path);
	Translate(x, y, z);
}

void Object3D::Translate(glm::vec3 translation)
{
	translate = glm::translate(translate, translation);
}

void Object3D::Translate(float x, float y, float z)
{
	translate = glm::translate(translate, glm::vec3(x, y, z) * Time::deltaTime);
}

void Object3D::Rotate(float x, float y, float z)
{
	rotation = glm::rotate(rotation, glm::radians(x * Time::deltaTime), glm::vec3(1.0f, 0.0f, 0.0f));
	rotation = glm::rotate(rotation, glm::radians(y * Time::deltaTime), glm::vec3(0.0f, 1.0f, 0.0f));
	rotation = glm::rotate(rotation, glm::radians(z * Time::deltaTime), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Object3D::Scale(float x, float y, float z)
{
	scaleVector.x += x * Time::deltaTime;
	scaleVector.y += y * Time::deltaTime;
	scaleVector.z += z * Time::deltaTime;
	scale = glm::scale(scale, scaleVector);
	scaleVector = glm::vec3(1, 1, 1);
}

void Object3D::SetScale(float x, float y, float z)
{
	scaleVector = glm::vec3(x, y, z);
	scale = glm::scale(scale, scaleVector);
	scaleVector = glm::vec3(1, 1, 1);
}

glm::mat4 Object3D::GetModelMatrix()
{
	return translate * rotation * scale;
}

int Object3D::GetFacesToDraw()
{
	return indicies.size();
}
