#pragma once
#include "Input.h"
using namespace std;
using namespace glm;
class Camera
{
public:
	Camera();
	~Camera();
	Camera(vec3 position, vec3 rotation);

	float speed = 5;
	void Update();
	mat4 GetViewMatrix();
	vec3 GetPosition();

private:
	vec3 _position;
	vec3 _up, _right, _front;
	mat4 _view;
	float pitch = 0, yaw = 0, roll = 0;

	void Move();

	void Rotate();

	void UpdateVectors();

};

