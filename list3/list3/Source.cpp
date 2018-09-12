#include<GL/glut.h>

void  display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void init(void) {
	glClearColor(0.5, 0.0, 0.2,1.0);/*RÅCGÅCBÇ≈êFÇê›íË*/
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}