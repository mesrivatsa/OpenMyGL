#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

void pyramid(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i=0;i<50;i++){
   
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(200+i,100+i);
    glVertex2f(100+i,300+i);
    glVertex2f(200+i,400+i);
    glVertex2f(300+i,300+i);
    
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(200+i,100+i);
    glVertex2f(200+i,400+i);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(100+i,300+i);
    glVertex2f(300+i,300+i);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(200+i,100+i);
    glVertex2f(100+i,50+i);
    glEnd();
    glFlush();
    _sleep(300);
    glClear(GL_COLOR_BUFFER_BIT);
    }
    

    
}

void jinit()
{
        glClearColor(0,0,0,0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(0,800,0,800);

}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutCreateWindow("Srivatsa's dream kite!");
    jinit();
    glutDisplayFunc(pyramid);
    glutMainLoop();
    return 0;
}
