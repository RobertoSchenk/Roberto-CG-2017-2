#include "Input.h"

bool Input::keys[348];
Mouse Input::mouse;

Input::Input()
{
	
}


Input::~Input()
{
}


bool Input::GetKey(int key)
{
	return keys[key];
}

float Input::GetMouseAxis(MouseAxis axis)
{
	float __offset;
	switch (axis)
	{
	case MOUSE_AXIS_X:
		__offset = mouse.offsetX;
		mouse.offsetX = 0;
		return __offset;
		break;
	case MOUSE_AXIS_Y:
		__offset = mouse.offsetY;
		mouse.offsetY = 0;
		return __offset;
		break;
	default:
		return 0;
		break;
	}
}

void Input::RegisterKey(int key, int action)
{
	if (action == GLFW_PRESS)
	{
		keys[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		keys[key] = false;
	}
}

void Input::RegisterMouse(double pos_x, double pos_y)
{
	mouse.Update(pos_x, pos_y);
}
