#include "main.h"
#include <GL\glut.h>
#include "glut_utils.h"
#include "timer.h"
using namespace glut;

extern int k = 0;
extern int frames = 0;
extern long float ti = clock()/1000.0f;

void Draw(void)
{
	if (clock()/1000.0f - ti > 1.0f)
	{
		std::cout << "Wrote " << frames << std::endl;
		ti = clock()/1000.0f;
		frames = 0;
	}
	int i, j;

	k++;
	frames++;
	k = k % 200;

	// set first half of buffer to red
	for (i = 0; i<glut::width; i++) {
		for (j = 0; j<glut::height; j++) {
			// set pixel at coord i,j to 'red'
			if (((i % 100 < 50) && (j % 100 < 50)) | ((i % 100 > 50) && (j % 100 > 50)))
			{
				glut::setPixel(glut::easel, i, j, k, 0, 0);
			}
			else
			{
				glut::setPixel(glut::easel, i, j, 255, 255, 255);
			}
		}
	}
	// drawpixels draws the rgb data stored in 'easel' to the screen
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, easel);

	// in double buffer mode so we swap to avoid a flicker
	glutSwapBuffers();

	// instruct event system to call 'drawfunc' again
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	int width, height;
	// width and height of the window
	width =  800;
	height = 400;

	// create a char buffer, 3 bytes per pixel of the window
	char *easel = new char[width*height * 3];

	// initialize the glut system and create a window
	glutInitWindowSize(width, height);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("YAR-Yet Another Raytracer");

	// initialize some OpenGL state
	glut::glInit();

	// set callback functions.  drawfunc is the function that gets
	// called automatically as fast as possible.  keyfunc only is
	// invoked if the user hits a keyboard key.

	glut::setAll(easel, width, height);
	glutDisplayFunc(Draw);
	glutKeyboardFunc(glut::keyFunc);

	// start the main glut loop, no code runs after this
	glutMainLoop();

}
