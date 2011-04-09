//
// this program used to draw some polygons on screen, very basic OpenGL program :)
// but, I still do this. why not ?
//
// author : kongque
// date   : 04/09/2011
//

#include <GL/glut.h>
#include <stdlib.h>


static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1, 1, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

float ptA[] = {-5.0f, 2.5f, -9.0f };
float ptB[] = {-2.5f, 5.0f, -9.0f };
float ptC[] = { 0.0f, 2.5f, -9.0f };

static void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw a triangle
	//glBegin(GL_TRIANGLES);
	//	glVertex3f(ptA[0], ptA[1], ptA[2]);
	//	glVertex3f(ptB[0], ptB[1], ptB[2]);
	//	glVertex3f(ptC[0], ptC[1], ptC[2]);
	//glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3fv(ptA);
		glVertex3fv(ptB);
		glVertex3fv(ptC);
	glEnd();

	glutSwapBuffers();
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

	glutMainLoop();

	return 0;
}
