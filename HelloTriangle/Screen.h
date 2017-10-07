#pragma once
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
class Screen
{
public:
	Screen() {};
	~Screen() {};
	static void SetSize(int w, int h);
	
	static int WIDTH, HEIGHT;
	static GLFWwindow* WINDOW;
};

