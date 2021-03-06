

#include<windows.h>
#include<gl\glut.h>
int c = 0;
void init()
{
// For displaying the window color
glClearColor(0, 1, 1, 0);
// Choosing the type of projection
glMatrixMode(GL_PROJECTION);
// for setting the transformation which here is 2D
gluOrtho2D(0, 800, 0,600);
}

void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
// if color is 0 then draw white box and change value of color = 1
if (c == 0)
{
glColor3f(1, 1, 1); // white color value is 1 1 1
c = 1;
}
// if color is 1 then draw black box and change value of color = 0
else
{
glColor3f(0, 0, 0); // black color value is 0 0 0
c = 0;
}

// Draw Square
glBegin(GL_POLYGON);
glVertex2i(x1, y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4, y4);
glEnd();
}
void chessboard()
{
glClear(GL_COLOR_BUFFER_BIT); // Clear display window
GLint x, y;

for (x = 0; x <= 800; x += 100)
{
for (y = 0; y <= 600; y += 75)
{
drawSquare(x, y + 75, x + 100, y + 75, x + 100, y, x, y);
}
}
// Process all OpenGL routine s as quickly as possible
glFlush();
}

int main(int agrc, char ** argv)
{
// Initialize GLUT
glutInit(&agrc, argv);
// Set display mode
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Set top - left display window position.
glutInitWindowPosition(100, 100);
// Set display window width and height
glutInitWindowSize(800, 600);
// Create display window with the given title
glutCreateWindow("Chess Board using OpenGL in C++");
// Execute initialization procedure
init();
// Send graphics to display window
glutDisplayFunc(chessboard);
// Display everything and wait.
glutMainLoop();
}

On Mon, Feb 13, 2017 at 2:55 PM, Sunil Naravagol <snaravagol@gmail.com> wrote:
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

GLfloat house[2][9] = {{100,100,175,250,250,150,150,200,200},
                       {100,300,400,300,100,100,175,175,100}
                       };
GLfloat h=100,k=100;


void drawhouse()
{
    glColor3f(1,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][0],house[1][0]);
        glVertex2f(house[0][1],house[1][1]);
        glVertex2f(house[0][3],house[1][3]);
        glVertex2f(house[0][4],house[1][4]);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(100,100);
        glVertex2f(100,300);
        glVertex2f(3,300);
        glVertex2f(3,100);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][5],house[1][5]);
        glVertex2f(house[0][6],house[1][6]);
        glVertex2f(house[0][7],house[1][7]);
        glVertex2f(house[0][8],house[1][8]);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(house[0][1],house[1][1]);
        glVertex2f(house[0][2],house[1][2]);
        glVertex2f(house[0][3],house[1][3]);
    glEnd();
    glColor3f(1,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(3,300);
        glVertex2f(100,300);
        glVertex2f(175,400);
        glVertex2f(78,400);
    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawhouse();
    glFlush();
}

void myinit()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,999,-200,999);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Srivatsa's house rotation.");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}
