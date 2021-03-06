#include <windows.h>
#include <GL/glut.h>
#include <math.h>
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_TIMES_ROMAN_10;
float posY=0.4;
void init()
{
    glClearColor(0.0f,0.0f,0.1f,0.0f);
    GLfloat mat_specular[]={1.0f, 1.0f, 1.0f, 1.0f} ;
    GLfloat mat_diffuse[]={1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_ambient[]={ 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat g_light_position[] = { -1.5f, 1.0f, -4.0f, 1.0f };
    GLfloat mat_shininess[] = { 70.0 };
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, g_light_position);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
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
void balloon(float red, float green, float blue)
{
    glEnable(GL_LIGHTING);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,-3.0,0.0);
    glEnd();
    GLfloat Color[] = {red, green, blue, 0.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Color);
    glutSolidSphere(0.8,80,32);
}
void text(void)
{
    glDisable( GL_LIGHTING );
    renderBitmapString(510,250,(void *)font1,"HAPPY");
    renderBitmapString(495,210,(void *)font1,"NEW YEAR");
    glColor3f(1.0,1.0,1.0);
    renderBitmapString(500,170,(void *)font2,"May this year bring new");
    renderBitmapString(500,150,(void *)font2,"happiness, new goals, new");
    renderBitmapString(500,130,(void *)font2,"achievements and a lot of new");
    renderBitmapString(500,110,(void *)font2,"inspirations on your life");
}
void reshape1(int w, int h)
{
    //glViewport(0, 0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55, w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2, 0, 6, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void reshape2(int w,int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    reshape1(w,h);

    ///balloon
    glPushMatrix();
    glTranslatef(-2.0,posY+0.6,0.0);
    balloon(1.0,1.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0,posY+1.6,0.0);
    balloon(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0,posY,0.0);
    balloon(0.4,0.4,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1,posY+0.7,0.0);
    balloon(0.8,0.4 ,0.1);
    glPopMatrix();

    ///Message
    reshape2(w,h);
    text();
    glutSwapBuffers();
}
void timer(int value)
{
    static bool flag=true;
    static int count=5;
    if(count==10)
        flag=false;
    if (count==0)
        flag=true;
    if(flag)
    {
        posY+=0.03;
        count++;
    }
    else
    {
        posY-=0.03;
        count--;
    }

    glutPostRedisplay();
    glutTimerFunc(100,timer,0);
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(700,400);
    glutCreateWindow("New Year Card");
    init();
    glutDisplayFunc(display);
    //glutReshapeFunc(reshape);
    glutTimerFunc(200,timer,0);
    glutMainLoop();


return 0;
}

