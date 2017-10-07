#include "Screen.h"

int Screen::HEIGHT = 0;
int Screen::WIDTH = 0;
GLFWwindow* Screen::WINDOW = nullptr;

void Screen::SetSize(int w, int h)
{
	WIDTH = w;
	HEIGHT = h;
}
