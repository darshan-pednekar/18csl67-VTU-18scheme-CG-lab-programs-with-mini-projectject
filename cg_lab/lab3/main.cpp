#include<GL/glut.h>
#include<stdio.h>
float v[]={-0.5,-0.5,-0.5, -0.5,0.5,-0.5, 0.5,0.5,-0.5, 0.5,-0.5,-0.5, -0.5,-0.5,0.5, -0.5,0.5,0.5, 0.5,0.5,0.5, 0.5,-0.5,0.5};
float c[]={0,0,0, 0,0,1, 1,0,1, 0,1,1, 1,1,0, 0,1,0, 1,1,1};
GLubyte d[]={0,1,2,3, 2,3,7,6, 4,5,6,7, 4,5,1,0, 5,6,2,1, 0,3,7,4};
int gx=0,gy=0,gz=1;
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glRotated(0.1,gx,gy,gz);
glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,d);
glFlush();
}
void Mouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
gx=1;gy=0;gz=0;
}
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
{
gx=0;gy=1;gz=0;
}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
{
gx=0;gy=0;gz=1;
}
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitWindowSize(700,700);
glutCreateWindow("Cube");
glutDisplayFunc(display);
glutIdleFunc(display);
glutMouseFunc(Mouse);
glEnableClientState(GL_VERTEX_ARRAY);
glEnableClientState(GL_COLOR_ARRAY);
glVertexPointer(3,GL_FLOAT,0,v);
glColorPointer(3,GL_FLOAT,0,c);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
}





