#pragma once
#include "Mouse.h"
#include "Time.h"
enum MouseAxis { MOUSE_AXIS_X, MOUSE_AXIS_Y };

class Input
{
private:
	static Mouse mouse;
	static bool keys[348];
public:
	Input();
	~Input();
	static bool GetKey(int key);
	static float GetMouseAxis(MouseAxis axis);
	static void RegisterKey(int key, int action);
	static void RegisterMouse(double pos_x, double pos_y);
};

