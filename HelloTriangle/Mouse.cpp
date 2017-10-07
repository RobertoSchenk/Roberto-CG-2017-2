#include "Mouse.h"
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



Mouse::Mouse()
{
	_lastX = 400;
	_lastY = 300;
	offsetX = 0;
	offsetY = 0;
	_firstMouse = true;
}


Mouse::~Mouse()
{
}

void Mouse::Update(double p_posX, double p_posY)
{
	if (_firstMouse)
	{
		_lastX = p_posX;
		_lastY = p_posY;
		_firstMouse = false;
	}

	offsetX = p_posX - _lastX;
	offsetY = _lastY - p_posY;
	offsetX *= 0.05f;
	offsetY *= 0.05f;

	_lastX = p_posX;
	_lastY = p_posY;

	/*if (abs(offsetX) <= 0.5f) offsetX = 0;
	if (abs(offsetY) <= 0.5f) offsetY = 0;*/
	
}
