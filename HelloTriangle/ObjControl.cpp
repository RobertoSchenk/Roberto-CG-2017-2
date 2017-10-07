#include "ObjControl.h"



ObjControl::ObjControl()
{
}


ObjControl::~ObjControl()
{
}

void ObjControl::SetControlledObj(Object3D * objToControl)
{
	controlledObj = objToControl;
}

void ObjControl::Update()
{
	Translate();
	Scale();
	Rotate();
}

void ObjControl::Rotate()
{
	if (Input::GetKey(GLFW_KEY_LEFT))
	{
		controlledObj->Rotate(0, -rotateSpeed, 0);
	}
	if (Input::GetKey(GLFW_KEY_RIGHT))
	{
		controlledObj->Rotate(0, rotateSpeed, 0);
	}
	if (Input::GetKey(GLFW_KEY_DOWN))
	{
		controlledObj->Rotate(rotateSpeed, 0, 0);
	}
	if (Input::GetKey(GLFW_KEY_UP))
	{
		controlledObj->Rotate(-rotateSpeed, 0, 0);
	}
	if (Input::GetKey(GLFW_KEY_O))
	{
		controlledObj->Rotate(0, 0, rotateSpeed);
	}
	if (Input::GetKey(GLFW_KEY_U))
	{
		controlledObj->Rotate(0, 0, -rotateSpeed);
	}

}

void ObjControl::Scale()
{
	if (Input::GetKey(GLFW_KEY_MINUS))
	{
		controlledObj->Scale(-scaleSpeed, -scaleSpeed, -scaleSpeed);
	}
	if (Input::GetKey(GLFW_KEY_EQUAL))
	{
		controlledObj->Scale(scaleSpeed, scaleSpeed, scaleSpeed);
	}
}

void ObjControl::Translate()
{
	if (Input::GetKey(GLFW_KEY_I))
	{
		controlledObj->Translate(0, 0, speed);
	}
	if (Input::GetKey(GLFW_KEY_K))
	{
		controlledObj->Translate(0, 0, -speed);
	}
	if (Input::GetKey(GLFW_KEY_L))
	{
		controlledObj->Translate(-speed, 0, 0);
	}
	if (Input::GetKey(GLFW_KEY_J))
	{
		controlledObj->Translate(speed, 0, 0);
	}
	if (Input::GetKey(GLFW_KEY_N))
	{
		controlledObj->Translate(0, -speed, 0);
	}
	if (Input::GetKey(GLFW_KEY_M))
	{
		controlledObj->Translate(0, speed, 0);
	}
}