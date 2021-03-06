﻿#include<GL/glut.h>
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

	if (h > w) {
		gluOrtho2D(
			-w / w, w / w,
			-h / w, h / w
		);
	}

	if (w > h) {
		gluOrtho2D(
			-w / h, w / h,
			-h / h, h / h
		);
	}
}

void init(void) {
	/*初期化命令*/
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(380.0, 200.0);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}