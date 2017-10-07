#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

Camera::Camera(vec3 position, vec3 rotation)
{
	_position = position;
	yaw = rotation.x;
	pitch = rotation.y;
}

void Camera::Update()
{
	Rotate();
	Move();
	UpdateVectors();
	
	
 }

glm::mat4 Camera::GetViewMatrix()
{
	_view = lookAt(_position, _position + _front, _up);
	return _view;
}

vec3 Camera::GetPosition()
{
	return _position;
}

void Camera::Move()
{
	float __cameraSpeed = speed * Time::deltaTime;
	if (Input::GetKey(GLFW_KEY_W))
	{
		_position += __cameraSpeed * _front;
	}
	if (Input::GetKey(GLFW_KEY_S))
	{
		_position -= __cameraSpeed * _front;

	}
	if (Input::GetKey(GLFW_KEY_A))
	{
		_position -= glm::normalize(glm::cross(_front, _up)) * __cameraSpeed;
	}
	if (Input::GetKey(GLFW_KEY_D))
	{
		_position += glm::normalize(glm::cross(_front, _up)) * __cameraSpeed;
	}
	if (Input::GetKey(GLFW_KEY_X))
	{
		_position += _up * __cameraSpeed;
	}
	if (Input::GetKey(GLFW_KEY_Z))
	{
		_position -= _up * __cameraSpeed;
	}

}

void Camera::Rotate()
{
	
	yaw += Input::GetMouseAxis(MOUSE_AXIS_X);
	pitch += Input::GetMouseAxis(MOUSE_AXIS_Y);
	if (pitch > 89.9f)
	{
		pitch = 89.9f;
	}
	else if (pitch < -89.9f)
	{
		pitch = -89.9f;
	}

	

}

void Camera::UpdateVectors()
{
	_front = vec3(0.0f, 0.0f, 0.0f);
	_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	_front.y = sin(glm::radians(pitch));
	_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	_front = normalize(_front);
	glm::vec3 __worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	_right = glm::normalize(glm::cross(_front, __worldUp));
	_up = normalize(glm::cross(_right, _front));
}

