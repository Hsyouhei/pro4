#include <GL/glut.h>
#include<math.h>
#define M_PI 3.14159265358979323846 

/*リスト15*/
static void timer(int dummy) {
	glutTimerFunc(100, timer, 0);
	glMatrixMode(GL_MODELVIEW);
	glRotated(3.0, 0.0, 0.0, 1.0);
	glutPostRedisplay();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glColor3d(0, 1, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 1, 0);
	glColor3d(0, 0, 1);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 1);
	glEnd();
	glFlush();
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 2);
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	/*リスト15呼び出し*/
	glutTimerFunc(10, timer, 0);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}