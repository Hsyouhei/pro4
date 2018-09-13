#include<GL/glut.h>
#include<math.h>

#define M_PI 3.14159265358979323846 

void display(void) {
	int i;
	double theta, dt, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	dt = M_PI / 2;
	theta = 0.0;
	glBegin(GL_POLYGON);
	for (i = 0; i < 4; i++) {
		x = cos(theta);
		y = sin(theta);
		glVertex2d(x, y);
		theta += dt;
	}
	glEnd();
	glFlush();
}
void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(
		-w / 200.0, w / 200.0,
		-h / 200.0, h / 200.0
	);
}

void idle(void) {
	glutPostRedisplay();
}

void init(void) {
	/*‰Šú‰»–½—ß*/
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutPostRedisplay();
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}