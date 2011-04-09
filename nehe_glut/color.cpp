//
// this program used to draw some polygons on screen and paint some color, very basic OpenGL program :)
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

float color_red[] = { 1.0f, 0.0f, 0.0f };
float color_green[] = { 0.0f, 1.0f, 0.0f };
float color_blue[] = { 0.0f, 0.0f, 1.0f };

static void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3fv(color_red);
		glVertex3fv(ptA);

		glColor3fv(color_green);
		glVertex3fv(ptB);

		glColor3fv(color_blue);
		glVertex3fv(ptC);
	glEnd();

	glBegin(GL_POINTS);
		for (int i=0; i<300; ++i)
		{
			float random_vectex[3];
			
			random_vectex[0] = rand() % 10 * -1.0f;
			random_vectex[1] = rand() % 10 * -1.0f;
			random_vectex[2] = rand() % 10 * -1.0f;
			
			float factor = 1.0 / 255.0f;
			glColor3f(rand() % 255 * factor, rand() % 255 * factor, rand() % 255 * factor);
			glVertex3fv(random_vectex);
		}
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
