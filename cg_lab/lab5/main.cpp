#include<stdio.h>
#include<GL/glut.h>
#define outcode int
double xmin=50,ymin=50,xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
const int RIGHT=2,LEFT=1,BOTTOM=4,TOP=8;
outcode computeoutcode(double x,double y);
void csl(double x0,double y0,double x1,double y1)
{
	int outcode0,outcode1,outcodeout;
	bool accept=false,done=false;
	outcode0=computeoutcode(x0,y0);
	outcode1=computeoutcode(x1,y1);
	do{
	if(!(outcode0|outcode1))
	{
	accept=true;
	done=true;
	}
	else 	if(outcode0 & outcode1)
		done=true;
else
{
double x,y;
outcodeout=outcode0?outcode0:outcode1;
if(outcodeout & TOP)
{
x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
y=ymax;
}
else if(outcodeout & BOTTOM)
{
x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
y=ymin;
}
else if(outcodeout & RIGHT)
{
y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
x=xmax;
}
else 
{
y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
x=xmin;
}
if(outcodeout==outcode0)
{
x0=x;
y0=y;
outcode0=computeoutcode(x0,y0);
}
else{
x1=x;
y1=y;
outcode1=computeoutcode(x1,y1);
}

}

}while(!done);
if(accept)
{
double sx=(xvmax-xvmin)/(xmax-xmin);
double sy=(yvmax-yvmin)/(ymax-ymin);
double vx0=xvmin+(x0-xmin)*sx;
double vx1=xvmin+(x1-xmin)*sx;
double vy0=yvmin+(y0-ymin)*sy;
double vy1=yvmin+(y1-ymin)*sy;
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2f(vx0,vy0);
glVertex2f(vx1,vy1);
glEnd();
}
}
int computeoutcode(double x,double y)
{
int code=0;
if(y>ymax) code|=TOP;
else if(y<ymin) code|=BOTTOM;
else if(x>xmax) code|=RIGHT;
else if (x<xmin) code|=LEFT;
return code;
}

void display()
{
double x0=60,y0=95,x1=90,y1=95;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(x0,y0);
glVertex2d(x1,y1);
glEnd();
glColor3f(1.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
glVertex2f(xmin,ymax);
glEnd();
csl(x0,y0,x1,y1);
glFlush();
}
void myInit()
{
glClearColor(0.0,0.0,0.0,1.0);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,500.0,0.0,500.0,1,-1);

}
int main(int argc,char **argv)
{



glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("COHEN SUTHERLAND LINE CLIPPING");
myInit();
glutDisplayFunc(display);

glutMainLoop();

}

