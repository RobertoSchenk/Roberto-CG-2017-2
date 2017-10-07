#pragma once
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
class Time
{
private:
	static float _currentFrame;
	static float _lastFrame;
public:
	Time();
	~Time();
	static float deltaTime;

	static void FindDeltaTime();
};

