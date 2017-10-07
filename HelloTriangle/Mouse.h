#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mouse
{
public:
	float offsetX, offsetY;
	Mouse();
	~Mouse();

	void Update(double PositionX, double PositionY);

private:
	double _lastX, _lastY;
	bool _firstMouse;

};

