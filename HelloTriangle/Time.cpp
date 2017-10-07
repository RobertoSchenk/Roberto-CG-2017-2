#include "Time.h"

float Time::deltaTime = 0.0f;
float Time::_currentFrame = 0.0f;
float Time::_lastFrame = 0.0f;

Time::Time()
{
}


Time::~Time()
{
}

void Time::FindDeltaTime()
{
	_currentFrame = glfwGetTime();
	deltaTime = _currentFrame - _lastFrame;
	_lastFrame = _currentFrame;
}
