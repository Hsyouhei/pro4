#include<GL/glut.h>
#include<math.h>

#define M_PI 3.14159265358979323846 

/*リスト8*/
void idle(void) {
	glutPostRedisplay();
}
/*リスト11*/
static void timer(int dummy) {
	glutTimerFunc(100, timer, 0);
	glutPostRedisplay();
}
/*リスト9*/
double rotAng = 0.0;

void display(void) {
	int i;
	double theta, dt, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	dt = M_PI / 2;
	theta = rotAng;
	glBegin(GL_POLYGON);
	for (i = 0; i < 4; i++) {
		x = cos(theta);
		y = sin(theta);
		glVertex2d(x, y);
		theta += dt;
	}
	glEnd();
	glFlush();
	rotAng += 3.0*M_PI / 180.0;
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
	glutInitWindowSize(640.0, 480.0);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	//glutIdleFunc(idle);
	glutTimerFunc(10,timer,0);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}