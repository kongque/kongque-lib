#include <GL/glut.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// freetype include
#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftouln.h>
#include <freetype/fttrigon.h>

// This holder all of the information related to any freetype font that we want to create
struct CFT2Interface
{
	float mFontHeight;
	GLuint* mTextures;
	GLuint mListBase;

	// init freetyp2 library and load a font by aFontName parameter
	bool init(const char* aFontName, unsigned int aHeight);

	// free all the resources 
	void clean();

	// print true type string
	void print(float x, float y, const char* fmt, ...);
};

// OpenGL use a texture size must be power of 2, adapter it 
inline int getPOT(int a)
{
	int r = 1;
	while (r < a)
		r <<= 1;
	return r;
}

void make_dlist(FT_Face face, char ch, GLuint base, GLuint* tex_base)
{
	// load glyph for our character
	if (FT_Load_Glyph(face, FT_Get_Char_Index(face, ch), FT_LOAD_DEFAULT))
		throw std::runtime_error("FT_Load_Glyph failed");

	// move the face's glyph to a glyph object
	FT_Glyph glyph;
	if (FT_Get_Flyph(face.glyph, &glyph))
		throw std::runtime_error("FT_Get_Glyph failed");

	// convert the glyph to a bitmap
	FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, 0, 1);
	FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;

	//
	FT_Bitmap& bitmap = bitmap_glyph->bitmap;

	int width = getPOT(bitmap.width);
	int height = getPOT(bitmap.rows);

	// Allocate memory for textuer
	GLubyte* expanded_data = new GLubyte[2 * width * height];

	for (int j=0; j<height; ++j)
	{
		for (int i=0; i<width; ++i)
		{
			expanded_data[2*(i+j*width)] = expanded_data[2*(i+j*width) + 1] = (i>=bitmap.width || j>=bitmap.rows) ? 0 : bitmap.buffer[i+bitmap.width *j];
		}
	}

	glBindTexture(GL_TEXTURE_2D, tex_base[ch]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, expanded_data);

	delete [] expanded_data;
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

	// TODO: draw something
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
