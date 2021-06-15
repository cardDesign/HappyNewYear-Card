#include <windows.h>
#include <GL/glut.h>
#include <math.h>
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_TIMES_ROMAN_10;
void init()
{
    glClearColor(0.0f,0.0f,0.1f,0.0f);

}
void renderBitmapString(float x,float y,void *font,const char *string)
{
    const char *c;

    glRasterPos2f(x,y);
    for(c=string;*c!='\0';c++)
    {
        glutBitmapCharacter(font,*c);
    }
}
void DrawCircle(float radiusX, float radiusY, int posX,int posY)
{
	glBegin(GL_POLYGON);
	for(int i=0;i<360;i++)
	{
	  float theta=i*3.142/180;
	  glVertex2f(posX+0.1*cos(theta)*radiusX,posY+0.1*sin(theta)*radiusY);          
	}
	glEnd();
}
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glColor3f(1.0,1.0,0.0);
   renderBitmapString(510,250,(void *)font1,"HAPPY");
   renderBitmapString(495,210,(void *)font1,"NEW YEAR");
   glColor3f(1.0,1.0,1.0);
   renderBitmapString(500,170,(void *)font2,"May this year bring new");
   renderBitmapString(500,150,(void *)font2,"happiness, new goals, new");
   renderBitmapString(500,130,(void *)font2,"achievements and a lot of new");
   renderBitmapString(500,110,(void *)font2,"inspirations on your life");
    glutSwapBuffers();

}
void reshape(int w, int h)
{
   glViewport(0, 0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0, w, 0, h);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}


int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(700,400);
    glutCreateWindow("New Year Card");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();


return 0;
}
