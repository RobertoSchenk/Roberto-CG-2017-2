#pragma once
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "STB.h"

using namespace std;

class Image
{
public:
	Image();
	Image(std::string path);
	~Image();
	int width, height, colorChannels;
	unsigned char* image;

};

