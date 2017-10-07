#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include "Shader.h"
#include <cmath>
#include <ctime>
#include <map>
#include "Camera.h"
#include "ObjControl.h"
#include "Screen.h"
using namespace std;
class Buniby
{
private:
	map<string, Object3D*> _objects;
	Camera* camera_ptr = nullptr;
public:
	Buniby();
	~Buniby();

	void StartFrame();

	void SetCamera(Camera* Newcamera)
	{
		camera_ptr = Newcamera;
	}

	void AddObject(string name, Object3D* objectptr)
	{
		_objects[name] = objectptr;
	}

	void AddObject(string name, string path)
	{
		Object3D* __object = new Object3D(path);
		_objects[name] = __object;
	}

	void AddObject(string name, string path, float x, float y, float z)
	{
		Object3D* __object = new Object3D(path, glm::vec3(x, y, z));
		_objects[name] = __object;
	}

	void EndFrame(Shader* shader);
	
	void DealocateBuffers();
	
	Object3D* GetObject(string name)
	{
		return _objects[name];
	}


};

