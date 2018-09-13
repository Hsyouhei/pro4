#include<GL/glut.h>
#include<math.h>

#define M_PI 3.14159265358979323846 

void display(void) {
	int i;
	double theta, dt, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	dt = M_PI/2 ;
	theta = 0.0;
	glBegin(GL_POLYGON);
	for (i = 0; i < 4; i++) {
		x = cos(theta);
		y = sin(theta);
		glVertex2d(x, y);
		theta += dt;
	}
	/*
	glBegin(GL_TRIANGLES);
	glVertex2d(-0.5, -0.5);
	glVertex2d(-0.5, 0.5);
	glVertex2d(0.5, 0.5);
	glVertex2d(0.5, -0.5);
	*/
	glEnd();
	glFlush();
}


void init(void) {
	/*‰Šú‰»–½—ß*/
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;

}
