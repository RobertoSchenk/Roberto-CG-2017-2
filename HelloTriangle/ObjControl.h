#pragma once
#include "Object3D.h"
#include "Input.h"
class ObjControl
{
private:
	Object3D* controlledObj = nullptr;
	void Rotate();
	void Scale();
	void Translate();
public:
	ObjControl();
	~ObjControl();
	void SetControlledObj(Object3D* objToControl);
	void Update();

	float speed = 5, rotateSpeed = 15, scaleSpeed = 1;

};

