#include <GL/glut.h>
#include <stdlib.h>

#include "common/image.h"
#include <stdio.h>

unsigned char* gImageData = 0;
unsigned int gTex[1];

bool loadImage()
{
	CImage* image = new CImage;
	if (!image->Load("data/earth.tga", false))
		printf("load image failed");
	else
		gImageData = image->getImageData();
	int width = image->getImageWidth();
	int height = image->getImageHeight();
	printf("image width = %d, height = %d\n", width, height);


	glGenTextures(1, &gTex[0]);
	glBindTexture(GL_TEXTURE_2D, gTex[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, gImageData);

	return true;
}

static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, gTex[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0, -1.0, -5.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0, 1.0, -5.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 1.0, -5.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, -1.0, -5.0);
	glEnd();

	glutSwapBuffers();
	glDisable(GL_TEXTURE_2D);
}

static void key(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':
			exit(0);
			break;
	}
}

static void idle()
{
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("Glut framebase");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glEnable(GL_TEXTURE_2D);

	loadImage();

	glutMainLoop();

	return 0;
}
