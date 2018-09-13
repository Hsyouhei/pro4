#include<GL/glut.h>
#include<math.h>

#define M_PI 3.14159265358979323846 

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2d(0, 1);
	glVertex2d(0, 0);
	glVertex2d(1, 0);
	glEnd();
	glColor3b(1.0, 1.0, 0.0);
	glRasterPos2d(0, 0);
	glutBitmapCharacter(
		GLUT_BITMAP_8_BY_13, '0'
	);
	glFlush();
}


void init(void) {
	/*èâä˙âªñΩóﬂ*/
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}