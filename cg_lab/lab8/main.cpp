#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void bezierCoefficients(int n,int *c)
{
int k,i;
for(k=0;k<=n;k++)
{
c[k]=1;
for(i=n;i>=k+1;i--)
c[k]*=i;
for(i=n-k;i>=2;i--)
c[k]/=i;
}

}
void display()
{
int cp[4][2]={{100,100},{200,200},{300,100},{400,200}};
int c[4],k,n=3;
float x,y,u,blend;
bezierCoefficients(n,c);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glLineWidth(5.0);
glBegin(GL_LINE_STRIP);
for(u=0;u<1.0;u+=0.1)
{
x=0;y=0;
for(k=0;k<4;k++)
{
blend=c[k]*pow(u,k)*pow(1-u,n-k);
x+=cp[k][0]*blend;
y+=cp[k][1]*blend;
}
glVertex2f(x,y);
}
glEnd();
glFlush();
}
void myInit()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glOrtho(0,500,0,500,1,-1);
}


int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(600,600);
glutCreateWindow("bezier curve");
glutDisplayFunc(display);
myInit();
glutMainLoop();
return 0;
}

