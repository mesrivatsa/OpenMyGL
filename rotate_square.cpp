// ROTATING SQUARE

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <GL/glut.h>
#define DEG_TO_RAD 0.017453
float a=0.0;
GLfloat theta = 0.0;

void mydisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
    glVertex2f(cos(DEG_TO_RAD*theta), sin(DEG_TO_RAD*theta));
  glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-sin(DEG_TO_RAD*theta), cos(DEG_TO_RAD*theta));
  glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-cos(DEG_TO_RAD*theta), -sin(DEG_TO_RAD*theta));
 glColor3f(1.0, 1.0, 1.0);
    glVertex2f(sin(DEG_TO_RAD*theta), -cos(DEG_TO_RAD*theta));
  glEnd();
  glutSwapBuffers();
}

void spinDisplay(void)
{
  theta -= a;
  if (theta < -360.0) theta += 360.0;
  glutPostRedisplay();
}

void myinit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
}
void mouse(int btn,int state,int x ,int y){
    if(btn== GLUT_LEFT_BUTTON && state== GLUT_DOWN){
        a=0.05;
    }
    if(btn== GLUT_RIGHT_BUTTON && state== GLUT_DOWN){
        a=-0.05;
    }

}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(310, 0);
  glutCreateWindow("double buffered");
  myinit();
  glutDisplayFunc(mydisplay);
  glutIdleFunc(spinDisplay);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
