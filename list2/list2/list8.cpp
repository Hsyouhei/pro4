#include<GL/glut.h>
#include<math.h>

#define M_PI 3.14159265358979323846 
/*リスト8*/
void idle(void) {
	glutPostRedisplay();
}

//リスト9
double rotAng = 0.0;

void display(void) {
	int i;
	double theta, dt, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3b(1.0, 0.0, 0.0);
	dt = M_PI / 2.0;
	theta = rotAng;
	//theta = 0.0;
	glBegin(GL_POLYGON);
	for (i = 0; i < 4; i++) {
		x = cos(theta);
		y = sin(theta);
		glVertex2d(x, y);
		theta += dt;
	}
	glEnd();
	glFlush();
	rotAng += 3.0*M_PI/180.0;
}

//リスト10
/*
void display(void) {
	static double rotAng = 0.0;
	int i;
	double theta, dt, x, y;
	//グローバル変数利用と同じ処理
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3b(1.0, 0.0, 0.0);
	dt = 2.0*M_PI / 3.0;
	theta = rotAng;
	glBegin(GL_TRIANGLES);
	for (i = 0; i < 3; i++) {
		x = cos(theta);
		y = sin(theta);
		glVertex2d(x, y);
		theta += dt;
	}
	glFlush();
	rotAng += 3.0*M_PI / 180.0;
	}
*/

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(
		-w / 200.0, w / 200.0,
		-h / 200.0, h / 200.0
	);
}

void init(void) {
	/*初期化命令*/
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutPostRedisplay();
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}