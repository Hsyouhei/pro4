#include<GL/glut.h>
#include<math.h>

#define M_PI 3.14159265358979323846 

void display(void) {
	int i;
	double theta, dt, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	dt = M_PI / 2.0;
	theta = 0.0;
	glBegin(GL_TRIANGLES);

	for (i = 0; i < 5 ; i++) {
		x = -sin(theta);
		y = sin(theta);
		glVertex2d(x, y);
		theta += dt;
	}
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
