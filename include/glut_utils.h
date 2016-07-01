#include <GL\glut.h>
#include "rgb.h"

#ifndef GLUT_UTILS_H
#define GLUT_UTILS_H
namespace glut
{
	extern char *easel;
	extern int width;
	extern int height;

	void setEasel(char *a);
	void setWidth(int a);
	void setHeight(int a);
	void setAll(char *a, int b, int c);

	void glInit();
	void setPixel(char *buf, int x, int y, RGB r);
	void setPixel(char *buf, int x, int y, int r, int g, int b);
	void keyFunc(unsigned char k, int x, int y);
	void defaultDraw();
}
#endif