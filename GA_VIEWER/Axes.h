#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>

ref class Axes
{
public:
	Axes(void);
	void paintAxes();
	void paintOppositeAxes();
};
