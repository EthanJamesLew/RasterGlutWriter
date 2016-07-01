#include "glut_utils.h"

char *glut::easel;
int glut::width;
int glut::height;

void glut::setEasel(char *a)
{
	*glut::easel = *a;
}

void glut::setWidth(int a)
{
	glut::width = a;
}

void glut::setHeight(int a)
{
	glut::height = a;
}

void glut::setAll(char *a, int b, int c)
{
	glut::easel = a;
	glut::width = b;
	glut::height = c;
}

void glut::glInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void glut::setPixel(char *buf, int x, int y, RGB r)
{ 
	buf[(y*glut::width + x) * 3 + 0] = r.r;
	buf[(y*glut::width + x) * 3 + 1] = r.g;
	buf[(y*glut::width + x) * 3 + 2] = r.b;
}
void glut::setPixel(char *buf, int x, int y, int r, int g, int b)
{

	buf[(y*glut::width + x) * 3 + 0] = r;
	buf[(y*glut::width + x) * 3 + 1] = g;
	buf[(y*glut::width + x) * 3 + 2] = b;

}


void glut::keyFunc(unsigned char k, int x, int y)
{
	switch (k) {
	case 27:
		// escape key
		break;
	case GLUT_KEY_UP:
		// up arrow
		break;
	case 'a':
		// 'a' key
		break;
	}
}
