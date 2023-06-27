#include<stdio.h>
#include<GL/glut.h>
typedef float point[3];
point v[] = { {0.0,0.0,-1.0},{0.0,0.9423,-0.3333},{-0.8164,-0.4714,-0.3333},{0.8164,-0.4714,-0.5} };
int n;

void tri(point a, point b, point c)
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void divide_tri(point a, point b, point c, int m)
{
	point v1, v2, v3;
	if (m > 0)
	{
		for (int j = 0; j < 3; j++)
		{
			v1[j] = (a[j] + b[j]) / 2;
			v2[j] = (a[j] + c[j]) / 2;
			v3[j] = (b[j] + c[j]) / 2;
		}
		divide_tri(a, v1, v2, m - 1);
		divide_tri(c, v2, v3, m - 1);
		divide_tri(b, v3, v1, m - 1);
		
	}
	else
		tri(a, b, c);
}
void tet(int m)
{
	glColor3f(1.0, 0.0, 0.0);
	divide_tri(v[0], v[1], v[2], m);
	glColor3f(0.0, 1.0, 0.0);
	divide_tri(v[3], v[2], v[1], m);
	glColor3f(0.0, 0.0, 1.0);
	divide_tri(v[0], v[3], v[1], m);
	glColor3f(0.0, 0.0, 0.0);
	divide_tri(v[0], v[2], v[3], m);
}

void display()
{
	glViewport(0, 0, 700, 700);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	tet(n);
	glFlush();
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	printf("\nEnter the division\n");
	scanf("%d", &n);
	glutInitWindowSize(700, 700);
	glutCreateWindow("SIERPINKS GASKET");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glClearColor(1, 1, 1, 1);
	glutMainLoop();
	return 0;
}










