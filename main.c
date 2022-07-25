#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fi 4
int flag=0;
GLfloat v[][3]={{-35,30,-2.5},{-20,30,-2.5},{-20,40,-2.5},{-35,40,-2.5},{-35,30,2.5},{-20,30,2.5},{-20,40,2.5},{-35,40,2.5}};
GLfloat dx=0,dy=0,tx=0,ty=0,mx=0,my=0,rx=0,ry=0;
GLfloat a,b;
unsigned char keyf=0;
int strflag=0;
void drawstring(float x,float y,float z,const char *str)
{
unsigned int c;
glRasterPos3f(x,y,z);
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[c]);
}
void drawstring1(float x,float y,float z,const char *str)
{
unsigned int c;
glRasterPos3f(x,y,z);
if(strflag==0)
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[c]);
if(strflag==1)
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[c]);
if(strflag==2)
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,str[c]);
}
void drawline(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
glBegin(GL_LINES);
glVertex3f(x1,y1,0);
glVertex3f(x2,y2,0);
glEnd();
}
void drawcircle(GLfloat m, GLfloat n)
{
GLfloat i;
glBegin(GL_LINE_LOOP);
for(i=0;i<=2*3.14;i+=0.0005)
glVertex3f(m+cos(i)*3,n+sin(i)*3,0);
glEnd();
}
void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,1);
 drawstring(-25,60,0.0,"GOVERNMENT ENGINEERING COLLEGE HASSAN");
 glColor3f(0.7,0,1);
 drawstring(-30,50,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
 glColor3f(1,0.5,0);
 drawstring(-12,40,0.0,"A MINI PROJECT ON ");
 glColor3f(1,0,0);
 drawstring(-16,30,0.0,"HUMAN DIGESTIVE SYSTEM");
 glColor3f(1,0.5,0);
 drawstring(-35,15,0.0,"BY:");
 glColor3f(0.5,0,0.5);
 drawstring(-35,10,0.0,"KARUN KUMAR MN (4GH19CS024)");
 strflag=0;
 drawstring(-35,5,0.0,"6th Semester,CSE");
 glColor3f(1,0.5,0);
 drawstring(15,15,0.0,"GUIDE:");
 glColor3f(0.5,0.2,0.2);
 drawstring(15,10,0.0,"Mr VASANTH KUMAR");
 strflag=0;
 drawstring(15,5,0.0,"Assistant Professor,CSE");
 glColor3f(1,0.1,1);
 drawstring(-13,-10,0.0,"PRESS ENTER TO START");
 glFlush();
}
void body()
{
GLfloat i,x,y;
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex3f(x=0+cos(1)*7,y=35+sin(1)*7,0);
for(i=1;i<=3.81;i+=0.05)
glVertex3f(0+cos(i)*7,36.3+sin(i)*7,0);
glVertex3f(-7,35,0);
glVertex3f(-6,27,0);
glEnd();
glColor3ub(255,191,128);
glBegin(GL_POLYGON);
glVertex3f(x,y,0);
glVertex3f(x,y-5,0);
glVertex3f(x,y-5.5,0);
glVertex3f(x,y-6,0);
glVertex3f(x+1.5,y-9,0);
glVertex3f(x,y-9,0);
glVertex3f(x,y-11,0);
glVertex3f(x-0.5,y-12,0);
glVertex3f(x-0.5,y-13,0);
glVertex3f(x-1,y-14,0);
glVertex3f(x-3,y-16,0);
glVertex3f(x-6,y-16,0);
glVertex3f(-6,27,0);
glVertex3f(-5,30,0);
glVertex3f(-4,32.5,0);
glVertex3f(-3.7,35,0);
glVertex3f(-2,35,0);
glEnd();
glBegin(GL_POLYGON);//neck
glVertex3f(1,27,0);
glVertex3f(-4,27,0);
glVertex3f(-4,22,0);
glVertex3f(1,22,0);
glEnd();
glBegin(GL_POLYGON);
for(i=3.14;i>(3.14/2.0);i-=0.05)
glVertex3f(-9+cos(i)*5,15+sin(i)*7,0);
glVertex3f(-9,22,0);
glVertex3f(5,22,0);
for(i=(3.14/2.0);i>0;i-=0.05)
glVertex3f(5+cos(i)*7,15+sin(i)*7,0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(-9,15.1,0);
glVertex3f(7,15.1,0);
glVertex3f(6,0,0);
glVertex3f(-8,0,0);
glEnd();
glBegin(GL_POLYGON);//left hand
glVertex3f(-13.99,15.011,0);
glVertex3f(-9,15.011,0);
glVertex3f(-10,2.011,0);
glVertex3f(-13.59,2.011,0);
glEnd();
glBegin(GL_POLYGON);//Right hand
glVertex3f(12,15.011,0);
glVertex3f(6.7,15.011,0);
glVertex3f(8,1.011,0);
glVertex3f(11.5,1.011,0);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(6,0,0);
glVertex3f(-8,0,0);
glVertex3f(-9,-18,0);
glVertex3f(7,-18,0);
glEnd();
dx=x-1;dy=y-11;
a=x;b=y;
}
GLfloat aa,bb;
void digesdraw()
{
GLfloat i;
body();
glLineWidth(15);
glColor3ub(255,100,50);
glBegin(GL_LINE_STRIP);
glVertex3f(a,b-11,0);
for(i=(3.14/2.0);i<=3.14;i+=0.0005)
glVertex3f(2+cos(i)*3.5,26+sin(i)*3.5,0);//oesophagus1
glVertex3f(-1.5,27,0);
glVertex3f(-1.5,4.5,0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(a,b-11,0);
for(i=(3.14/2.0);i<=3.14;i+=0.0005)
glVertex3f(2.5+cos(i)*3.5,26.2+sin(i)*3.5,0);//oesophagus2
glVertex3f(-1.2,25,0);
glVertex3f(-1.2,4,0);
glEnd();
glBegin(GL_POLYGON);//stomach upper
for(i=(5*3.14/2.0);i>=(3*3.14/2);i-=0.005)
glVertex3f(aa=(1+cos(i)*4),bb=(0+sin(i)*4),0);
glVertex3f(-1.5,5,0);
glEnd();
glBegin(GL_POLYGON);//stomach lower
glVertex3f(aa,bb,0);
for(i=(3.14/2);i<(3*3.14/2);i+=0.005)
glVertex3f(0+cos(i)*2.5,-2+sin(i)*2.5,0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-2.5,-2,0);
for(i=(3.14/2.0);i<=3.14;i+=0.0005)
glVertex3f(aa=-1.4+cos(i)*3,bb=-4.5+sin(i)*3,0);
for(i=(3.14/2.0);i<=3.0;i+=0.0005)
glVertex3f(-1.3+cos(i)*3,-5+sin(i)*3,0);
glEnd();
double freq=0.3,amp=4.5;
glBegin(GL_LINE_STRIP);
glVertex3f(aa,bb,0);
glVertex3f(aa,bb-3,0);
glEnd();
glBegin(GL_LINE_STRIP);//small interestine
for(i=-5;i>=-14;i-=0.005)
glVertex3f((amp*sin(2*3.14*freq*i)),i,0);
glEnd();
glColor3f(0,0,0);//border
glLineWidth(2.5);
glBegin(GL_LINE_LOOP);
glVertex3f(41,51,0);
glVertex3f(-41,51,0);
glVertex3f(-41,-21,0);
glVertex3f(41,-21,0);
glEnd();
glLineWidth(1);
glBegin(GL_LINE_LOOP);
glVertex3f(40,50,0);
glVertex3f(-40,50,0);
glVertex3f(-40,-20,0);
glVertex3f(40,-20,0);
glEnd();
strflag=1;
glColor3ub(0, 207, 119);
drawstring1(-20,-30,0,"HUMAN DIGESTIVE SYSTEM");
strflag=0;
glColor3f(0,0,0);
drawline(a,b-12,a+6.5,b-12);
drawstring1(a+7,b-12,0,"Mouth");
drawline(-10,28,-1,28);
drawstring1(-16,28,0,"Pharynx");
drawline(-12,22,-1.5,22);
drawstring1(-20,22,0,"Oesophagus");
drawline(10,0,3,0);
drawstring1(10.5,0,0,"Stomach");
drawline(-14,-2,-2,-2);
drawstring1(-22,-2,0,"Duodenum");
}
void liver()
{
GLfloat i;
glColor3ub(200,100,50);
glBegin(GL_POLYGON);
glVertex3f(-1.2,4,0);
glVertex3f(-1.5,5,0);
glVertex3f(-1,6,0);
for(i=(3.14/2.0);i<=3.5;i+=0.005)
glVertex3f(0+cos(i)*6,0+sin(i)*7,0);
glEnd();
glLineWidth(1);
strflag=0;
glColor3f(0,0,0);
drawline(-15,4,-4,4);
drawstring1(-20,4,0,"Liver");
}
void largeinstes()
{
glLineWidth(15);
GLfloat i;
glColor3ub(240,150,50);
glBegin(GL_LINE_LOOP);
glVertex3f(-1,-17.5,0);
glVertex3f(-1,-15,0);
glVertex3f(4,-15,0);
glVertex3f(4,-6,0);
glVertex3f(-5.3,-6,0);
glVertex3f(-5.3,-14,0);
glVertex3f(-2,-13,0);
glVertex3f(-2,-14,0);
glVertex3f(-6,-14,0);
glVertex3f(-6,-5,0);
glVertex3f(4.7,-5,0);
glVertex3f(4.7,-16,0);
glVertex3f(3,-16,0);
glVertex3f(1,-16,0);
glVertex3f(-1,-16,0);
glEnd();
glLineWidth(1);
strflag=0;
glColor3f(0,0,0);
drawline(-14,-7,-5,-7);
drawstring1(-24,-7,0,"Large intestine");
drawline(9.5,-9,1,-9);
drawstring1(10,-9,0,"Small intestine");
drawline(9.5,-15,-1,-15);
drawstring1(10,-15,0,"Rectum");
drawline(9.5,-17.5,-1,-17.5);
drawstring1(10,-17.5,0,"Anus");
}
int countd=0;
void food()
{
glPointSize(5);
glColor3ub(20,190,50);
glBegin(GL_POINTS);
glVertex3f(0.9,27,0);
glEnd();
glBegin(GL_POINTS);
glVertex3f(0.65,27.2,0);
glEnd();
}
void foodp()
{
glPointSize(3);//food
glColor3ub(20,190,50);
glBegin(GL_POINTS);
glVertex3f(-4.4,6.5,0);
glVertex3f(-3.9,6.5,0);
glVertex3f(-4.1,7.2,0);
glEnd();
}
void digest()
{
GLfloat i,dy=-1;
digesdraw();
glPushMatrix();
glTranslatef(dx+tx,dy+ty,0.0);
food();
glPopMatrix();
glPushMatrix();
glTranslatef(dx+mx,dy+my,0.0);
foodp();
glPopMatrix();
liver();
largeinstes();
if(countd==1)
{
glColor3ub(115, 183, 0);
glLineWidth(3);
drawline(a+9,b-9,a+9.5,b-10);
drawline(a+9,b-9,a+9.5,b-8);
drawline(a+9,b-9,a+13,b-9);
drawstring(a+14,b-9,0,"Food");
}
glutSwapBuffers();
}
GLfloat theta1=5*3.14/2.0,theta=3.14/2.0,theta2=3.14/2.0;
void animate()
{
if(flag==1)
{
if(tx<20 && ty<20 && theta<=3.14)
{
tx=-1.2+cos(theta)*3.5;
ty=sin(theta)*3.5;
countd=1;
theta+=0.005;
}
if(theta>=3.14 && ty>=-20.5)
{
ty=ty-0.01;
countd=0;
}
if(theta>=3.14 && theta1>= 3*3.14/2.0 && ty<=-20.5 && ty>=-30)
{
mx=-1.5+cos(theta1)*4;
my=-4.8+sin(theta1)*4;
theta1-=0.005;
}
else if(theta1<= 3*3.14/2.0 && my<=-5.79 && my>=-11 && theta2<=3.0)
{
mx=mx-0.01;
my=my-0.01;
}
glutPostRedisplay();
}
}
void mydisplay(void)
{
glViewport(10,-50,980,700);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 if(flag==0)
  frontscreen ();
 if(flag==1)
 {
  digest();
  glutIdleFunc(animate);
 }
glutSwapBuffers();
}
void myKeyboardFunc( unsigned char key)
{
if(flag==0) //Ascii of 'enter' key is 13
    flag=1;
mydisplay();
}
void init()
{
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glOrtho(-60,60,-60,60,-60,60);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB/*|GLUT_DEPTH*/);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(0,0);
glutCreateWindow("Human Anatomy");
init();
glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboardFunc);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
return 0;
}
