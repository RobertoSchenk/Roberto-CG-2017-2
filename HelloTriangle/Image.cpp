#include "Image.h"



Image::Image()
{
}

Image::Image(std::string path)
{
	image = stbi_load(path.c_str(), &width, &height, &colorChannels, 0);
}


Image::~Image()
{
}
