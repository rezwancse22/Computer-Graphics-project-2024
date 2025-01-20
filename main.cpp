#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#define PI 3.141516
#include<cstdio>




float sunPosition=0.2;
float sunSpeed=0.01;
float cloud1position=-1.0;
float cloud1speed=0.02;
float cloud2position=1.0;
float cloud2speed=0.02;
float ambulance_position=0;
float ambulance_speed=0.03;
float policecar_position=0;
float policecar_speed=0.007;
float human1_Position=0.3f;
float human1_Speed=0.008;
float human2_Position=0.8f;
float human2_Speed=0.01;
float human3_Position=0.5f;
float human3_Speed=0.007;
float human4_Position=0.0f;
float human4_Speed=0.0;
float plane_position = 0.0f;
float plane_speed = 0.015;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}



void Circle(GLfloat x, GLfloat y, GLfloat radius) {  ///circle code
    int i;
    int triangleAmount = 100; // # of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // Center of circle
        for(i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}


void update_cloud1(int value) {    ///left update cloud

    if(cloud1position <-1.0)
        cloud1position = 2.0f;

    cloud1position -= cloud1speed;

	glutPostRedisplay();


	glutTimerFunc(100, update_cloud1, 0);
}

void update_cloud2(int value1) {    ///right update cloud

    if(cloud2position <-1.0)
        cloud2position= 3.0f;

    cloud2position -= cloud2speed;

	glutPostRedisplay();


	glutTimerFunc(100, update_cloud2, 0);
}



void update_Sun(int value)///update sun
    {
    sunPosition+=sunSpeed;
    if(sunPosition>1.0)
    {
        sunPosition=-0.5;
    }

    glutPostRedisplay();
    glutTimerFunc(80, update_Sun, 0);
    }

    void update_ambulance(int value) {    ///update ambulance

    if(ambulance_position >=2.5)
        ambulance_position = -1.0f;

    ambulance_position += ambulance_speed;

	glutPostRedisplay();
glutTimerFunc(100, update_ambulance, 0);
    }


    void update_policecar(int value) {    ///update police car

    if(policecar_position >=2.5)
        policecar_position = -1.0f;

    policecar_position += policecar_speed;

	glutPostRedisplay();
glutTimerFunc(100, update_policecar, 0);
}


void update_human1(int value)                 ///AFID-6
{
    human1_Position+=human1_Speed;
    if(human1_Position>1.0)
    {
        human1_Position=-1.0;
    }


        glutPostRedisplay();
    glutTimerFunc(100, update_human1, 0);
}

void update_human2(int value)                 ///AFID-6
{
     human2_Position-=human2_Speed;
    if(human2_Position<-1.0)
    {
        human2_Position=+1.0;
    }

        glutPostRedisplay();
    glutTimerFunc(100, update_human2, 0);
}
void update_human3(int value)                 ///AFID-6
{
    human3_Position+=human3_Speed;
    if(human3_Position>1.0)
    {
        human3_Position=-1.0;
    }


        glutPostRedisplay();
    glutTimerFunc(100, update_human3, 0);
}
void update_human4(int value)                 ///AFID-6
{
    human4_Position+=human4_Speed;
    if(human4_Position>=0.80)
    {
        human4_Position=0.00;
    }


        glutPostRedisplay();
    glutTimerFunc(100, update_human4, 0);
}

void update_plane(int value) {
    if(plane_position <-1.8)
        plane_position = 1.0f;
    plane_position -= plane_speed;
	glutPostRedisplay();
	glutTimerFunc(100, update_plane, 0);
}
void sound()
{

    //PlaySound("Police Car Sound FX.mp3", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("Airplane Sound Effect.wav",  NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}




void sky(){
///sky
glBegin(GL_QUADS);
glColor3f(0.4f, 0.4f, 0.4f); // Sky color using glColor3f
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glColor3f(0.1f, 0.1f, 0.1f);
glVertex2f(1.0f, 1.0f);
glVertex2f(-1.0f, 1.0f);
glEnd();

///line separating sky
glBegin(GL_LINES);
glColor3f(0.45f, 0.45f, 0.45f); // Line color using glColor3f
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glEnd();

}

void star(){
//star
glPointSize(3);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);

glVertex2f(-0.9f, 0.9f);
glVertex2f(-0.85f, 0.85f);
glVertex2f(-0.8f, 0.75f);
glVertex2f(-0.75f, 0.85f);
glVertex2f(-0.78f, 0.75f);
glVertex2f(-0.65f, 0.75f);
glVertex2f(-0.6f, 0.9f);
glVertex2f(-0.55f, 0.85f);
glVertex2f(-0.45f, 0.85f);
glVertex2f(-0.38f, 0.75f);
glVertex2f(-0.2f, 0.9f);
glVertex2f(-0.15f, 0.85f);
glVertex2f(-0.1f, 0.85f);
glVertex2f(-0.0f, 0.75f);
glVertex2f(-0.7f, 0.9f);
glVertex2f(-0.3f, 0.85f);
glVertex2f(-0.48f, 0.85f);
glVertex2f(-0.25f, 0.75f);
glVertex2f(-0.32f, 0.75f);
glVertex2f(-0.18f, 0.75f);

glVertex2f(0.32f, 0.75f);
glVertex2f(0.18f, 0.75f);
glVertex2f(0.9f, 0.9f);
glVertex2f(0.85f, 0.85f);
glVertex2f(0.75f, 0.85f);
glVertex2f(0.78f, 0.75f);
glVertex2f(0.6f, 0.9f);
glVertex2f(0.55f, 0.85f);
glVertex2f(0.45f, 0.85f);
glVertex2f(0.38f, 0.75f);
glVertex2f(0.2f, 0.9f);
glVertex2f(0.15f, 0.85f);
glVertex2f(0.1f, 0.85f);
glVertex2f(0.0f, 0.75f);
glVertex2f(0.7f, 0.9f);
glVertex2f(0.3f, 0.85f);
glVertex2f(0.48f, 0.85f);
glVertex2f(0.25f, 0.75f);
glVertex2f(-0.25f, 0.75f);
glVertex2f(-0.35f, 0.75f);

// Additional stars
for (int i = 0; i < 50; i++) {
    float x = ((float)rand() / RAND_MAX) * 2.0f - 1.0f; // Random x between -1 and 1
    float y = ((float)rand() / RAND_MAX) * 0.9f + 0.1f; // Random y between 0.1 and 1.0
    glVertex2f(x, y);
}
glEnd();
}
void moon(){

     ///moon
    glColor3f(0.89,0.84,0.67);
    Circle(-0.65, 0.85, 0.07);
}
void plane(){
 ///plane

    glPushMatrix();
glTranslatef(plane_position, 0.0f, 0.0f);
glBegin(GL_QUADS); // Plane
    glColor3f(0.85f, 0.85f, 0.85f); // body
    glVertex2f(0.22f, 0.76f);
    glVertex2f(0.62f, 0.76f);
    glColor3f(0.2f, 0.57f, 0.94f);
    glVertex2f(0.62f, 0.82f);
    glVertex2f(0.28f, 0.82f);

    glColor3f(0.85f, 0.85f, 0.85f); // back body
    glVertex2f(0.6f, 0.82f);
    glVertex2f(0.62f, 0.76f);
     glColor3f(0.2f, 0.57f, 0.94f);
    glVertex2f(0.7f, 0.88f);
    glVertex2f(0.66f, 0.88f);

glColor3f(0.2f, 0.57f, 0.94f);
    glVertex2f(0.38f, 0.82f);// wing1
    glVertex2f(0.46f, 0.9f);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(0.51f, 0.9f);


    glVertex2f(0.43f, 0.82f);
    glColor3f(0.2f, 0.57f, 0.94f);
    glVertex2f(0.38f, 0.76f);// wing2
    glVertex2f(0.44f, 0.64f);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(0.48f, 0.64f);
    glVertex2f(0.42f, 0.76f);
glEnd();

glPointSize(15);
glBegin(GL_POINTS); // plane window
    glColor3f(0.89f, 1.0f, 0.58f);
    glVertex2f(0.3f, 0.79f);
    glVertex2f(0.38f, 0.79f);
    glVertex2f(0.46f, 0.79f);
    glVertex2f(0.54f, 0.79f);
glEnd(); // End Plane
glPopMatrix();
}
void cloud(){
/// Draw cloud 1 right
 glPushMatrix();
 glTranslatef(cloud1position,0,0);
    glColor3f(0.5f, 0.5f, 0.5f); // White color for cloud

    /// Base circles1
    Circle(-0.7f, 0.8f, 0.1f); // First circle
    Circle(-0.6f, 0.8f, 0.13f); // Second circle
    Circle(-0.5f, 0.8f, 0.1f); // Third circle

    /// Top circles 1
    Circle(-0.65f, 0.85f, 0.1f); // Fourth circle
    Circle(-0.55f, 0.85f, 0.1f);  // Fifth circle

      glPopMatrix();

    ///cloud 2 left
    glPushMatrix();
    glTranslatef(-cloud2position,0,0);
      glColor3f(0.5f, 0.5f, 0.5f); // White color for cloud

    /// Base circles
    Circle(0.5f, 0.65f, 0.1f); // First circle
    Circle(0.4f, 0.65f, 0.13f); // Second circle
    Circle(0.3f, 0.65f, 0.1f); // Third circle

    /// Top circles
    Circle(0.46f, 0.7f, 0.1f); // Fourth circle
    Circle(0.35f, 0.7f, 0.1f);  // Fifth circle

    glPopMatrix();
}

void greenquad(){

    ///green quads

 glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
   glColor3f(0.40f, 0.65f, 0.19f);
    glVertex2f(1.0f, 0.25f);
    glVertex2f(-1.0f, 0.25f);
    glEnd();
        glBegin(GL_LINES);
   glColor3f(0.45f, 0.45f, 0.45f);
   glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glEnd();
}

void building(){
///building behind 3 with updated building color

glBegin(GL_QUADS);
glColor3f(0.9f, 0.4f, 0.2f); // Deep orange and light red mixed color
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.3f, 0.1f); // Deep orange and light red mixed color
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glEnd();

///windows remain the same color
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f); // Window color remains unchanged
glVertex2f(-0.90f, 0.60f);
glVertex2f(-0.87f, 0.60f);
glVertex2f(-0.87f, 0.66f);
glVertex2f(-0.90f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.82f, 0.60f);
glVertex2f(-0.85f, 0.60f);
glVertex2f(-0.85f, 0.66f);
glVertex2f(-0.82f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.90f, 0.68f);
glVertex2f(-0.87f, 0.68f);
glVertex2f(-0.87f, 0.74f);
glVertex2f(-0.90f, 0.74f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.82f, 0.68f);
glVertex2f(-0.85f, 0.68f);
glVertex2f(-0.85f, 0.74f);
glVertex2f(-0.82f, 0.74f);
glEnd();

///building behind 4 moved down by 0.2 on y-axis and building color changed

glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.763f, 0.654f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "HOTEL");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.3f, 0.7f); // Changed color
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glVertex2f(-0.65f, 0.2f);
glVertex2f(-0.77f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.2f, 0.6f); // Changed color
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glVertex2f(-0.62f, 0.2f);
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.77f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.62f, 0.62f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.2f);
glEnd();

///windows (no color change, only y-axis shift)
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.75f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.72f, 0.54f);
glVertex2f(-0.72f, 0.60f);
glVertex2f(-0.75f, 0.60f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.67f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.70f, 0.54f);
glVertex2f(-0.70f, 0.60f);
glVertex2f(-0.67f, 0.60f);
glEnd();

///building behind 5 with updated position and golden yellow color
    glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.40f, 0.733f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AIUB");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.7f, 0.1f); // Golden yellow
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glVertex2f(-0.30f, 0.2f);
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.6f, 0.1f); // Golden yellow (darker shade)
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glVertex2f(-0.27f, 0.2f);
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.27f, 0.70f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.5 x-axis
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.40f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.55f);
glVertex2f(-0.37f, 0.61f);
glVertex2f(-0.40f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.32f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.55f);
glVertex2f(-0.35f, 0.61f);
glVertex2f(-0.32f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.40f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.63f);
glVertex2f(-0.37f, 0.69f);
glVertex2f(-0.40f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.32f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.63f);
glVertex2f(-0.35f, 0.69f);
glVertex2f(-0.32f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.40f, 0.47f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.47f);
glVertex2f(-0.37f, 0.53f);
glVertex2f(-0.40f, 0.53f);
glEnd();

/// Updated Building Code behind 11
//glMatrixMode();
//glScalef(0,0,0);
glColor3f(1.0,0.0,0.0);
renderBitmapString(0.05f, 0.59f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "CMH");

// Building structure (shifted 0.76 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // Green color for building
glVertex2f(0.02f, 0.59f); // Shifted by 0.76 on x-axis
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.0f, 0.0f); // Darker green for the side
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glVertex2f(0.14f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.14f, 0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glEnd();

// Windows (shifted by 0.13 x-axis)
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(0.05f, 0.41f);
glVertex2f(0.08f, 0.41f);
glVertex2f(0.08f, 0.47f);
glVertex2f(0.05f, 0.47f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(0.05f, 0.49f);
glVertex2f(0.08f, 0.49f);
glVertex2f(0.08f, 0.55f);
glVertex2f(0.05f, 0.55f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(0.13f, 0.49f);
glVertex2f(0.10f, 0.49f);
glVertex2f(0.10f, 0.55f);
glVertex2f(0.13f, 0.55f);
glEnd();
//glPopMatrix();

/// Updated Building Code behind 10

// Building structure (shifted 0.63 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(0.01f, 0.90f, 0.98f); // Green color for building
glVertex2f(-0.11f, 0.65f); // Shifted by 0.63 on x-axis
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.80f, 0.88f); // Darker green for the side
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glVertex2f(0.01f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(0.01f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.08f, 0.47f);
glVertex2f(-0.05f, 0.47f);
glVertex2f(-0.05f, 0.53f);
glVertex2f(-0.08f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(0.00f, 0.47f);
glVertex2f(-0.03f, 0.47f);
glVertex2f(-0.03f, 0.53f);
glVertex2f(0.00f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.08f, 0.55f);
glVertex2f(-0.05f, 0.55f);
glVertex2f(-0.05f, 0.61f);
glVertex2f(-0.08f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(0.00f, 0.55f);
glVertex2f(-0.03f, 0.55f);
glVertex2f(-0.03f, 0.61f);
glVertex2f(0.00f, 0.61f);
glEnd();

/// Updated Building Code behind 9

// Building structure (shifted 0.5 on x-axis, changed color to blue)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // Blue color for building
glVertex2f(-0.24f, 0.60f); // Shifted by 0.5 on x-axis
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.8f); // Darker color for the side
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glVertex2f(-0.12f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.12f, 0.60f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.21f, 0.42f);
glVertex2f(-0.18f, 0.42f);
glVertex2f(-0.18f, 0.48f);
glVertex2f(-0.21f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.13f, 0.42f);
glVertex2f(-0.16f, 0.42f);
glVertex2f(-0.16f, 0.48f);
glVertex2f(-0.13f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.21f, 0.50f);
glVertex2f(-0.18f, 0.50f);
glVertex2f(-0.18f, 0.56f);
glVertex2f(-0.21f, 0.56f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.13f, 0.50f);
glVertex2f(-0.16f, 0.50f);
glVertex2f(-0.16f, 0.56f);
glVertex2f(-0.13f, 0.56f);
glEnd();

///building behind 8 moved by 0.07 on x-axis and 0.2 on y-axis with cyan-red mixed color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.8f, 0.7f); // Cyan-red mixed
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glVertex2f(-0.45f, 0.2f);
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.7f, 0.6f); // Cyan-red mixed (darker shade)
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glVertex2f(-0.42f, 0.2f);
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.42f, 0.62f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.07 and y-axis shift by 0.2)
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.545f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.515f, 0.56f);
glVertex2f(-0.515f, 0.62f);
glVertex2f(-0.545f, 0.62f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.47f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.50f, 0.56f);
glVertex2f(-0.50f, 0.62f);
glVertex2f(-0.47f, 0.62f);
glEnd();

///building behind 7 moved down by 0.2 on y-axis and shifted by 0.1 on x-axis with red-yellow mixed color
    glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.61f, 0.553f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "SCHOOL");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.5f, 0.2f); // Red-yellow mixed
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glVertex2f(-0.49f, 0.2f);
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.4f, 0.1f); // Red-yellow mixed (lighter shade)
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glVertex2f(-0.46f, 0.2f);
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.46f, 0.52f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.1 and y-axis shift by -0.2)
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.585f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.44f);
glVertex2f(-0.555f, 0.50f);
glVertex2f(-0.585f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.51f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.44f);
glVertex2f(-0.54f, 0.50f);
glVertex2f(-0.51f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.585f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.36f);
glVertex2f(-0.555f, 0.42f);
glVertex2f(-0.585f, 0.42f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.51f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.36f);
glVertex2f(-0.54f, 0.42f);
glVertex2f(-0.51f, 0.42f);
glEnd();

///building behind 6 with updated position and blue-yellow mixed color
    glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.34f, 0.533f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "OFFICE");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.5f, 0.0f); // Blue-yellow mixed (dominantly blue)
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glVertex2f(-0.23f, 0.2f);
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.4f, 0.1f); // Blue-yellow mixed (lighter shade)
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glVertex2f(-0.20f, 0.2f);
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.20f, 0.50f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.07 x-axis
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.33f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.35f);
glVertex2f(-0.30f, 0.41f);
glVertex2f(-0.33f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.25f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.35f);
glVertex2f(-0.28f, 0.41f);
glVertex2f(-0.25f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.33f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.43f);
glVertex2f(-0.30f, 0.49f);
glVertex2f(-0.33f, 0.49f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(-0.25f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.43f);
glVertex2f(-0.28f, 0.49f);
glVertex2f(-0.25f, 0.49f);
glEnd();

   ///building behind 2
       glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.88f, 0.603f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "POLICE");
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(-0.89f,0.60f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.77f,0.2f);
    glVertex2f(-0.89f,0.2f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.74f,0.57f);
    glVertex2f(-0.74f,0.2f);
    glVertex2f(-0.77f,0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.89f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.77f, 0.60f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.77f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.74f, 0.57f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.74f, 0.57f);
    glVertex2f(-0.74f, 0.2f);
    glEnd();
    ///window

      glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.86f, 0.42f);
    glVertex2f(-0.83f, 0.42f);
    glVertex2f(-0.83f, 0.48f);
    glVertex2f(-0.86f, 0.48f);
    glEnd();

          glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.78f, 0.42f);
    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.81f, 0.48f);
    glVertex2f(-0.78f, 0.48f);
    glEnd();

     glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.86f, 0.50f);
    glVertex2f(-0.83f, 0.50f);
    glVertex2f(-0.83f, 0.56f);
    glVertex2f(-0.86f, 0.56f);
    glEnd();

          glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.78f, 0.50f);
    glVertex2f(-0.81f, 0.50f);
    glVertex2f(-0.81f, 0.56f);
    glVertex2f(-0.78f, 0.56f);
    glEnd();

///building
     glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glEnd();
       glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);

    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.98f, 0.31f);
    glVertex2f(-0.95f, 0.31f);
    glVertex2f(-0.95f, 0.35f);
    glVertex2f(-0.98f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.94f, 0.31f);
    glVertex2f(-0.91f, 0.31f);
    glVertex2f(-0.91f, 0.35f);
    glVertex2f(-0.94f, 0.35f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.98f, 0.37f);
    glVertex2f(-0.95f, 0.37f);
    glVertex2f(-0.95f, 0.41f);
    glVertex2f(-0.98f, 0.41f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.94f, 0.37f);
    glVertex2f(-0.91f, 0.37f);
    glVertex2f(-0.91f, 0.41f);
    glVertex2f(-0.94f, 0.41f);
    glEnd();

    ///p3

       glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.98f, 0.43f);
    glVertex2f(-0.95f, 0.43f);
    glVertex2f(-0.95f, 0.47f);
    glVertex2f(-0.98f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.94f, 0.43f);
    glVertex2f(-0.91f, 0.43f);
    glVertex2f(-0.91f, 0.47f);
    glVertex2f(-0.94f, 0.47f);
    glEnd();

    ///1 building

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-1.0f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

///window
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.99f, 0.26f);
    glVertex2f(-0.96f, 0.26f);
    glVertex2f(-0.96f, 0.22f);
    glVertex2f(-0.99f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.95f, 0.26f);
    glVertex2f(-0.92f, 0.26f);
    glVertex2f(-0.92f, 0.22f);
    glVertex2f(-0.95f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glEnd();

    ///2 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glEnd();

    ///windows
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.84f, 0.22f);
    glVertex2f(-0.81f, 0.22f);
    glVertex2f(-0.81f, 0.26f);
    glVertex2f(-0.84f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, 0.22f);
    glVertex2f(-0.77f, 0.22f);
    glVertex2f(-0.77f, 0.26f);
    glVertex2f(-0.8f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.84f, 0.28f);
    glVertex2f(-0.81f, 0.28f);
    glVertex2f(-0.81f, 0.32f);
    glVertex2f(-0.84f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, 0.28f);
    glVertex2f(-0.77f, 0.28f);
    glVertex2f(-0.77f, 0.32f);
    glVertex2f(-0.8f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.84f, 0.34f);
    glVertex2f(-0.81f, 0.34f);
    glVertex2f(-0.81f, 0.38f);
    glVertex2f(-0.84f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8f, 0.34f);
    glVertex2f(-0.77f, 0.34f);
    glVertex2f(-0.77f, 0.38f);
    glVertex2f(-0.8f, 0.38f);
    glEnd();

    ///3 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.70f, 0.22f);
    glVertex2f(-0.67f, 0.22f);
    glVertex2f(-0.67f, 0.26f);
    glVertex2f(-0.70f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.66f, 0.22f);
    glVertex2f(-0.63f, 0.22f);
    glVertex2f(-0.63f, 0.26f);
    glVertex2f(-0.66f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.67f, 0.28f);
    glVertex2f(-0.67f, 0.32f);
    glVertex2f(-0.7f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.66f, 0.28f);
    glVertex2f(-0.63f, 0.28f);
    glVertex2f(-0.63f, 0.32f);
    glVertex2f(-0.66f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.7f, 0.34f);
    glVertex2f(-0.67f, 0.34f);
    glVertex2f(-0.67f, 0.38f);
    glVertex2f(-0.7f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.66f, 0.34f);
    glVertex2f(-0.63f, 0.34f);
    glVertex2f(-0.63f, 0.38f);
    glVertex2f(-0.66f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.67f, 0.40f);
    glVertex2f(-0.67f, 0.44f);
    glVertex2f(-0.7f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.66f, 0.40f);
    glVertex2f(-0.63f, 0.40f);
    glVertex2f(-0.63f, 0.44f);
    glVertex2f(-0.66f, 0.44f);
    glEnd();

     glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.7f, 0.46f);
    glVertex2f(-0.67f, 0.46f);
    glVertex2f(-0.67f, 0.50f);
    glVertex2f(-0.7f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.66f, 0.46f);
    glVertex2f(-0.63f, 0.46f);
    glVertex2f(-0.63f, 0.50f);
    glVertex2f(-0.66f, 0.50f);
    glEnd();

    ///4 building 4

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glEnd();


    ///windows
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.56f, 0.22f);
    glVertex2f(-0.53f, 0.22f);
    glVertex2f(-0.53f, 0.26f);
    glVertex2f(-0.56f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.52f, 0.22f);
    glVertex2f(-0.49f, 0.22f);
    glVertex2f(-0.49f, 0.26f);
    glVertex2f(-0.52f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.52f, 0.28f);
    glVertex2f(-0.49f, 0.28f);
    glVertex2f(-0.49f, 0.32f);
    glVertex2f(-0.52f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.53f, 0.28f);
    glVertex2f(-0.53f, 0.32f);
    glVertex2f(-0.56f, 0.32f);
    glEnd();

    ///5 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.43f, 0.22f);
    glVertex2f(-0.4f, 0.22f);
    glVertex2f(-0.4f, 0.26f);
    glVertex2f(-0.43f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.39f, 0.22f);
    glVertex2f(-0.36f, 0.22f);
    glVertex2f(-0.36f, 0.26f);
    glVertex2f(-0.39f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.43f, 0.28f);
    glVertex2f(-0.4f, 0.28f);
    glVertex2f(-0.4f, 0.32f);
    glVertex2f(-0.43f, 0.32f);
    glEnd();
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.39f, 0.28f);
    glVertex2f(-0.36f, 0.28f);
    glVertex2f(-0.36f, 0.32f);
    glVertex2f(-0.39f, 0.32f);
    glEnd();
    ///p3
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.43f, 0.34f);
    glVertex2f(-0.4f, 0.34f);
    glVertex2f(-0.4f, 0.38f);
    glVertex2f(-0.43f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.39f, 0.34f);
    glVertex2f(-0.36f, 0.34f);
    glVertex2f(-0.36f, 0.38f);
    glVertex2f(-0.39f, 0.38f);
    glEnd();
    ///p4
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.43f, 0.40f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(-0.4f, 0.44f);
    glVertex2f(-0.43f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.39f, 0.40f);
    glVertex2f(-0.36f, 0.40f);
    glVertex2f(-0.36f, 0.44f);
    glVertex2f(-0.39f, 0.44f);
    glEnd();

    ///6 building
        glColor3f(1.0,0.0,0.0);
renderBitmapString(-0.29f, 0.362f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "FOOD");
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glEnd();
    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.28f, 0.22f);
    glVertex2f(-0.25f, 0.22f);
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.28f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.24f, 0.22f);
    glVertex2f(-0.21f, 0.22f);
    glVertex2f(-0.21f, 0.26f);
    glVertex2f(-0.24f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.28f, 0.28f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.25f, 0.32f);
    glVertex2f(-0.28f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.24f, 0.28f);
    glVertex2f(-0.21f, 0.28f);
    glVertex2f(-0.21f, 0.32f);
    glVertex2f(-0.24f, 0.32f);
    glEnd();

    ///7 building
    glBegin(GL_QUADS);
    glColor3f(0.37f, 0.50f, 0.96f);
    glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.50f, 0.86f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glEnd();
    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.16f, 0.22f);
    glVertex2f(-0.13f, 0.22f);
    glVertex2f(-0.13f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.09f, 0.22f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.12f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.16f, 0.28f);
    glVertex2f(-0.13f, 0.28f);
    glVertex2f(-0.13f, 0.32f);
    glVertex2f(-0.16f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.12f, 0.28f);
    glVertex2f(-0.09f, 0.28f);
    glVertex2f(-0.09f, 0.32f);
    glVertex2f(-0.12f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.16f, 0.34f);
    glVertex2f(-0.13f, 0.34f);
    glVertex2f(-0.13f, 0.38f);
    glVertex2f(-0.16f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.12f, 0.34f);
    glVertex2f(-0.09f, 0.34f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.12f, 0.38f);
    glEnd();

    ///8 building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glVertex2f(0.04f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.03f, 0.22f);
    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.03f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.01f, 0.22f);
    glVertex2f(0.03f, 0.22f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.01f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.03f, 0.28f);
    glVertex2f(-0.01f, 0.28f);
    glVertex2f(-0.01f, 0.32f);
    glVertex2f(-0.03f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.01f, 0.28f);
    glVertex2f(0.03f, 0.28f);
    glVertex2f(0.03f, 0.32f);
    glVertex2f(0.01f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.03f, 0.34f);
    glVertex2f(-0.01f, 0.34f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(-0.03f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.01f, 0.34f);
    glVertex2f(0.03f, 0.34f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.01f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.03f, 0.40f);
    glVertex2f(-0.01f, 0.40f);
    glVertex2f(-0.01f, 0.44f);
    glVertex2f(-0.03f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.01f, 0.40f);
    glVertex2f(0.03f, 0.40f);
    glVertex2f(0.03f, 0.44f);
    glVertex2f(0.01f, 0.44f);
    glEnd();

    ///9 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glEnd();
    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.09f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.26f);
    glVertex2f(0.09f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.13f, 0.22f);
    glVertex2f(0.16f, 0.22f);
    glVertex2f(0.16f, 0.26f);
    glVertex2f(0.13f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.09f, 0.28f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.12f, 0.32f);
    glVertex2f(0.09f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.13f, 0.28f);
    glVertex2f(0.16f, 0.28f);
    glVertex2f(0.16f, 0.32f);
    glVertex2f(0.13f, 0.32f);
    glEnd();

      glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.09f, 0.34f);
    glVertex2f(0.12f, 0.34f);
    glVertex2f(0.12f, 0.38f);
    glVertex2f(0.09f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.13f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.16f, 0.38f);
    glVertex2f(0.13f, 0.38f);
    glEnd();

      glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.09f, 0.40f);
    glVertex2f(0.12f, 0.40f);
    glVertex2f(0.12f, 0.44f);
    glVertex2f(0.09f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.13f, 0.40f);
    glVertex2f(0.16f, 0.40f);
    glVertex2f(0.16f, 0.44f);
    glVertex2f(0.13f, 0.44f);
    glEnd();

      glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.12f, 0.46f);
    glVertex2f(0.12f, 0.50f);
    glVertex2f(0.09f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.13f, 0.46f);
    glVertex2f(0.16f, 0.46f);
    glVertex2f(0.16f, 0.50f);
    glVertex2f(0.13f, 0.50f);
    glEnd();
}

void tree(){
 ///tree
   ///leaf
 glColor3f(0.17f, 0.38f, 0.2f); // White color for cloud
    /// Base circles
    Circle(0.98f, 0.53f, 0.08f); // First circle
    Circle(0.88f, 0.51f, 0.10f); // Second circle
    Circle(0.78f, 0.53f, 0.08f); // Third circle

    /// Top circles
    Circle(0.94f, 0.65f, 0.08f); // Fourth circle
    Circle(0.83f, 0.65f, 0.08f);  // Fifth circle
    Circle(0.88f, 0.75f, 0.08f);

glColor3f(0.36f, 0.16f, 0.09f); // Brown color for the trunk

// Polygon 1
glBegin(GL_POLYGON);
glColor3f(0.36f, 0.16f, 0.09f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.83f, 0.64f);
glVertex2f(0.8f, 0.64f);
glEnd();

// Polygon 2
glBegin(GL_POLYGON);
glColor3f(0.36f, 0.16f, 0.09f);
glVertex2f(0.905f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.93f, 0.68f);
glVertex2f(0.925f, 0.63f);
glEnd();

// Polygon 3
glBegin(GL_POLYGON);
glColor3f(0.36f, 0.16f, 0.09f);
glVertex2f(0.905f, 0.3f);
glVertex2f(0.905f, 0.575f);

glVertex2f(0.86f, 0.575f);
glVertex2f(0.86f, 0.3f);
glVertex2f(0.882f,0.2f);
glEnd();

// Polygon 4
glBegin(GL_POLYGON);
glColor3f(0.36f, 0.16f, 0.09f);
glVertex2f(0.95f, 0.25f);
glVertex2f(0.82f, 0.25f);
glVertex2f(0.86f, 0.30f);
glVertex2f(0.905f, 0.30f);
glEnd();

// triangle 1
glBegin(GL_TRIANGLES);
glColor3f(0.36f, 0.16f, 0.09f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.905f, 0.575f);
glEnd();

// triangle 2
glBegin(GL_TRIANGLES);
glColor3f(0.36f, 0.16f, 0.09f);
glVertex2f(0.86f, 0.445f);
glVertex2f(0.84f, 0.420f);
glVertex2f(0.86f, 0.470f);
glEnd();

}
void bench(){
///bench left

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.334f, 0.20f);
    glVertex2f(0.338f, 0.20f);
    glVertex2f(0.338f, 0.30f);
    glVertex2f(0.334f, 0.30f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.458f, 0.20f);
    glVertex2f(0.462f, 0.20f);
    glVertex2f(0.462f, 0.30f);
    glVertex2f(0.458f, 0.30f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.32f, 0.22f);
    glVertex2f(0.47f, 0.22f);
    glVertex2f(0.47f, 0.21f);
    glVertex2f(0.32f, 0.21f);
    glEnd();

       glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.53f);
    glVertex2f(0.31f, 0.24f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.48f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.30f, 0.24f);
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.49f, 0.25f);
    glVertex2f(0.49f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.31f, 0.26f);
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.49f, 0.25f);
    glVertex2f(0.48f, 0.26f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
     glVertex2f(0.304f, 0.25f);
    glVertex2f(0.486f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.32f, 0.23f);
    glVertex2f(0.325f, 0.23f);
    glVertex2f(0.325f, 0.20f);
    glVertex2f(0.32f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.47f, 0.23f);
    glVertex2f(0.475f, 0.23f);
    glVertex2f(0.475f, 0.20f);
    glVertex2f(0.47f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.31f, 0.28f);
    glVertex2f(0.48f, 0.28f);
    glVertex2f(0.48f, 0.27f);
    glVertex2f(0.31f, 0.27f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.31f, 0.285f);
    glVertex2f(0.48f, 0.285f);
    glVertex2f(0.48f, 0.295f);
    glVertex2f(0.31f, 0.295f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.31f, 0.30f);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.48f, 0.310f);
    glVertex2f(0.31f, 0.310f);
    glEnd();

     ///bench right

      glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.634f, 0.20f);
    glVertex2f(0.638f, 0.20f);
    glVertex2f(0.638f, 0.30f);
    glVertex2f(0.634f, 0.30f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.758f, 0.20f);
    glVertex2f(0.762f, 0.20f);
    glVertex2f(0.762f, 0.30f);
    glVertex2f(0.758f, 0.30f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.62f, 0.22f);
    glVertex2f(0.77f, 0.22f);
    glVertex2f(0.77f, 0.21f);
    glVertex2f(0.62f, 0.21f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.53f);
    glVertex2f(0.61f, 0.24f);
    glVertex2f(0.78f, 0.24f);
    glVertex2f(0.78f, 0.23f);
    glVertex2f(0.61f, 0.23f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.60f, 0.24f);
    glVertex2f(0.60f, 0.25f);
    glVertex2f(0.79f, 0.25f);
    glVertex2f(0.79f, 0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.61f, 0.26f);
    glVertex2f(0.60f, 0.25f);
    glVertex2f(0.79f, 0.25f);
    glVertex2f(0.78f, 0.26f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
     glVertex2f(0.604f, 0.25f);
    glVertex2f(0.786f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.62f, 0.23f);
    glVertex2f(0.625f, 0.23f);
    glVertex2f(0.625f, 0.20f);
    glVertex2f(0.62f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.77f, 0.23f);
    glVertex2f(0.775f, 0.23f);
    glVertex2f(0.775f, 0.20f);
    glVertex2f(0.77f, 0.20f);
    glEnd();///

       glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.61f, 0.28f);
    glVertex2f(0.78f, 0.28f);
    glVertex2f(0.78f, 0.27f);
    glVertex2f(0.61f, 0.27f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.61f, 0.285f);
    glVertex2f(0.78f, 0.285f);
    glVertex2f(0.78f, 0.295f);
    glVertex2f(0.61f, 0.295f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.70f, 0.34f);
    glVertex2f(0.61f, 0.30f);
    glVertex2f(0.78f, 0.30f);
    glVertex2f(0.78f, 0.310f);
    glVertex2f(0.61f, 0.310f);
    glEnd();

}
void lamppost(){
///lamp post 1 left
   glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.26f, 0.22f);
    glVertex2f(0.285f, 0.22f);
    glVertex2f(0.285f, 0.20f);
    glVertex2f(0.26f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.269f, 0.21f);
    glVertex2f(0.277f, 0.21f);
    glVertex2f(0.277f, 0.28f);
    glVertex2f(0.269f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.271f, 0.37f);
    glVertex2f(0.275f, 0.37f);
    glVertex2f(0.275f, 0.28f);
    glVertex2f(0.271f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.26f, 0.37f);
    glVertex2f(0.285f, 0.37f);
    glVertex2f(0.285f, 0.377f);
    glVertex2f(0.26f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.265f, 0.377f);
    glVertex2f(0.28f, 0.377f);
    glVertex2f(0.28f, 0.385f);
    glVertex2f(0.265f, 0.385f);
    glEnd();
        ///light color
       glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.283f, 0.41f);
    glVertex2f(0.262f, 0.41f);
    glVertex2f(0.265f, 0.385f);
    glVertex2f(0.28f, 0.385f);
    glEnd();

///lines
    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.265f, 0.385f);
   glVertex2f(0.262f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.28f, 0.385f);
   glVertex2f(0.283f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.272f, 0.385f);
   glVertex2f(0.272f,0.41f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.255f, 0.41f);
   glVertex2f(0.289f,0.41f);
   glVertex2f(0.272f,0.43f);
    glEnd();

///lamp post 2 right
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.81f, 0.22f);
    glVertex2f(0.835f, 0.22f);
    glVertex2f(0.835f, 0.20f);
    glVertex2f(0.81f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.819f, 0.21f);
    glVertex2f(0.827f, 0.21f);
    glVertex2f(0.827f, 0.28f);
    glVertex2f(0.819f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.821f, 0.37f);
    glVertex2f(0.825f, 0.37f);
    glVertex2f(0.825f, 0.28f);
    glVertex2f(0.821f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.81f, 0.37f);
    glVertex2f(0.835f, 0.37f);
    glVertex2f(0.835f, 0.377f);
    glVertex2f(0.81f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.815f, 0.377f);
    glVertex2f(0.83f, 0.377f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();

        ///light color
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.812f, 0.41f);
    glVertex2f(0.833f, 0.41f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();

///lines
    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.815f, 0.385f);
   glVertex2f(0.812f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.83f, 0.385f);
   glVertex2f(0.833f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.822f, 0.385f);
   glVertex2f(0.822f,0.41f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.805f, 0.41f);
   glVertex2f(0.839f,0.41f);
   glVertex2f(0.822f,0.43f);
    glEnd();

    ///double lamp post middle

    ///left
       glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.535f, 0.22f);
    glVertex2f(0.560f, 0.22f);
    glVertex2f(0.560f, 0.20f);
    glVertex2f(0.535f, 0.20f);
    glEnd();


      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.544f, 0.21f);
    glVertex2f(0.552f, 0.21f);
    glVertex2f(0.552f, 0.28f);
    glVertex2f(0.544f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.546f, 0.37f);
    glVertex2f(0.55f, 0.37f);
    glVertex2f(0.55f, 0.28f);
    glVertex2f(0.546f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.515f, 0.37f);
    glVertex2f(0.580f, 0.37f);
    glVertex2f(0.580f, 0.377f);
    glVertex2f(0.515f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.52f, 0.377f);
    glVertex2f(0.535f, 0.377f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();
    ///light color
       glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.517f, 0.41f);
    glVertex2f(0.538f, 0.41f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();

///lines
        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.52f, 0.385f);
   glVertex2f(0.517f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.535f, 0.385f);
   glVertex2f(0.538f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.527f, 0.385f);
   glVertex2f(0.527f,0.41f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.509f, 0.41f);
   glVertex2f(0.544f,0.41f);
   glVertex2f(0.527f,0.43f);
    glEnd();

    ///right

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.575f, 0.377f);
    glVertex2f(0.560f, 0.377f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();

    ///light color
       glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.578f, 0.41f);
    glVertex2f(0.557f, 0.41f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();

///lines
        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.560f, 0.385f);
   glVertex2f(0.557f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.575f, 0.385f);
   glVertex2f(0.578f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.567f, 0.385f);
   glVertex2f(0.567f,0.41f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);
    glVertex2f(0.549f, 0.41f);
   glVertex2f(0.585f,0.41f);
   glVertex2f(0.567f,0.43f);
    glEnd();

}
void boarde(){
    /// black boarder
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f,0.2f);
    glVertex2f(-1.0f,0.19f);
    glVertex2f(1.0f,0.19f);
    glVertex2f(1.0f,0.2f);
    glEnd();
}
void upfootpath(){
    ///footpath
    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.63f, 0.58f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.19f);
    glVertex2f(-1.0f, 0.19f);
    glEnd();
}
void human2(){
///human 2
glPushMatrix();
glTranslatef(human2_Position, 0, 0);
glRotatef(65, 0, 1, 0);

///body
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for the body (new dress color)
glVertex2f(0.0f, 0.17f);  // Shifted by +0.03
glVertex2f(0.07f, 0.17f);
glVertex2f(0.07f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(0.0f, 0.16f);  // Shifted by +0.03
glVertex2f(-0.015f, 0.16f);
glVertex2f(-0.012f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for sleeve (matching dress)
glVertex2f(0.0f, 0.19f);  // Shifted by +0.03
glVertex2f(-0.015f, 0.19f);
glVertex2f(-0.012f, 0.22f);
glVertex2f(0.0f, 0.22f);
glEnd();

///right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(0.07f, 0.16f);  // Shifted by +0.03
glVertex2f(0.085f, 0.16f);
glVertex2f(0.082f, 0.22f);
glVertex2f(0.07f, 0.22f);
glEnd();

///right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.8f, 0.2f); // Light green for sleeve (matching dress)
glVertex2f(0.07f, 0.19f);  // Shifted by +0.03
glVertex2f(0.085f, 0.19f);
glVertex2f(0.082f, 0.22f);
glVertex2f(0.07f, 0.22f);
glEnd();

///legs
glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f); // Gray for left leg (new pant color)
glVertex2f(0.0f, 0.12f);  // Shifted by +0.03
glVertex2f(0.02f, 0.12f);
glVertex2f(0.07f, 0.17f);
glVertex2f(0.0f, 0.17f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f); // Gray for right leg (new pant color)
glVertex2f(0.05f, 0.12f);  // Shifted by +0.03
glVertex2f(0.07f, 0.12f);
glVertex2f(0.07f, 0.17f);
glVertex2f(0.03f, 0.17f);
glEnd();

///shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(0.0f, 0.11f);  // Shifted by +0.03
glVertex2f(0.02f, 0.11f);
glVertex2f(0.02f, 0.12f);
glVertex2f(0.0f, 0.12f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
glVertex2f(0.05f, 0.11f);  // Shifted by +0.03
glVertex2f(0.07f, 0.11f);
glVertex2f(0.07f, 0.12f);
glVertex2f(0.05f, 0.12f);
glEnd();

///neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(0.025f, 0.22f);  // Shifted by +0.03
glVertex2f(0.045f, 0.22f);
glVertex2f(0.045f, 0.24f);
glVertex2f(0.025f, 0.24f);
glEnd();

///face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(0.01f, 0.24f);  // Shifted by +0.03
glVertex2f(0.06f, 0.24f);
glVertex2f(0.06f, 0.27f);
glVertex2f(0.01f, 0.27f);
glEnd();

///hair
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // Black for the hair (new hair color)
glVertex2f(0.01f, 0.27f);  // Shifted by +0.03
glVertex2f(0.06f, 0.27f);
glVertex2f(0.05f, 0.29f);
glVertex2f(0.02f, 0.29f);
glEnd();
glPopMatrix();
}
void human1(){
  ///human 1
     glPushMatrix();
    glTranslatef(human1_Position,0,0);
    glRotatef(65, 0,1,0);
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Dark green for body
glVertex2f(0.0f, 0.09f);  // Shifted by +0.04
glVertex2f(0.07f, 0.09f);
glVertex2f(0.07f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(0.0f, 0.08f);  // Shifted by +0.04
glVertex2f(-0.015f, 0.08f);
glVertex2f(-0.012f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Red for sleeve
glVertex2f(0.0f, 0.11f);  // Shifted by +0.04
glVertex2f(-0.015f, 0.11f);
glVertex2f(-0.012f, 0.14f);
glVertex2f(0.0f, 0.14f);
glEnd();

///right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(0.07f, 0.08f);  // Shifted by +0.04
glVertex2f(0.085f, 0.08f);
glVertex2f(0.082f, 0.14f);
glVertex2f(0.07f, 0.14f);
glEnd();

///right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.43f, 0.62f, 0.94f); // Blue for sleeve
glVertex2f(0.07f, 0.11f);  // Shifted by +0.04
glVertex2f(0.085f, 0.11f);
glVertex2f(0.082f, 0.14f);
glVertex2f(0.07f, 0.14f);
glEnd();

///legs
glBegin(GL_QUADS);
glColor3f(0.08f, 0.26f, 0.54f); // Navy blue for left leg
glVertex2f(0.0f, 0.04f);  // Shifted by +0.04
glVertex2f(0.02f, 0.04f);
glVertex2f(0.07f, 0.09f);
glVertex2f(0.0f, 0.09f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.08f, 0.26f, 0.54f); // Slightly lighter navy blue for right leg
glVertex2f(0.05f, 0.04f);  // Shifted by +0.04
glVertex2f(0.07f, 0.04f);
glVertex2f(0.07f, 0.09f);
glVertex2f(0.03f, 0.09f);
glEnd();

///shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(0.0f, 0.03f);  // Shifted by +0.04
glVertex2f(0.02f, 0.03f);
glVertex2f(0.02f, 0.04f);
glVertex2f(0.0f, 0.04f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
glVertex2f(0.05f, 0.03f);  // Shifted by +0.04
glVertex2f(0.07f, 0.03f);
glVertex2f(0.07f, 0.04f);
glVertex2f(0.05f, 0.04f);
glEnd();

///neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(0.025f, 0.14f);  // Shifted by +0.04
glVertex2f(0.045f, 0.14f);
glVertex2f(0.045f, 0.16f);
glVertex2f(0.025f, 0.16f);
glEnd();

///face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(0.01f, 0.16f);  // Shifted by +0.04
glVertex2f(0.06f, 0.16f);
glVertex2f(0.06f, 0.19f);
glVertex2f(0.01f, 0.19f);
glEnd();

///head
glBegin(GL_QUADS);
glColor3f(0.58f, 0.36f, 0.31f); // Black for hat
glVertex2f(0.01f, 0.19f);  // Shifted by +0.04
glVertex2f(0.06f, 0.19f);
glVertex2f(0.05f, 0.21f);
glVertex2f(0.02f, 0.21f);
glEnd();
glPopMatrix();
}

void roadlamppost(){
///lamp(road)
///lamp 1 left

    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.80f, -0.1f); // Bottom-left
    glVertex2f(-0.808f, -0.1f); // Top-left
    glVertex2f(-0.808f, 0.3f); // Top-right
    glVertex2f(-0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole2
   glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.808f, 0.27f); // Bottom-left
    glVertex2f(-0.88f, 0.27f); // Top-left
    glVertex2f(-0.88f, 0.285f); // Top-right
    glVertex2f(-0.808f, 0.285f); // Bottom-right
    glEnd();

    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.85f, 0.27f); // Bottom-left
    glVertex2f(-0.875f, 0.27f); // Bottom-right
    glVertex2f(-0.875f, 0.255f); // Top-right
    glVertex2f(-0.85f, 0.255f); // Top-left
    glEnd();

      ///lamp 2
    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f, -0.1f); // Bottom-left
    glVertex2f(-0.608f, -0.1f); // Top-left
    glVertex2f(-0.608f, 0.3f); // Top-right
    glVertex2f(-0.60f, 0.3f); // Bottom-right
    glEnd();

   /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.608f, 0.27f); // Bottom-left
    glVertex2f(-0.68f, 0.27f); // Top-left
    glVertex2f(-0.68f, 0.285f); // Top-right
    glVertex2f(-0.608f, 0.285f); // Bottom-right
    glEnd();
    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, 0.27f); // Bottom-left
    glVertex2f(-0.675f, 0.27f); // Bottom-right
    glVertex2f(-0.675f, 0.255f); // Top-right
    glVertex2f(-0.65f, 0.255f); // Top-left
    glEnd();
      ///lamp 3
    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.1f); // Bottom-left
    glVertex2f(-0.408f, -0.1f); // Top-left
    glVertex2f(-0.408f, 0.3f); // Top-right
    glVertex2f(-0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.408f, 0.27f); // Bottom-left
    glVertex2f(-0.48f, 0.27f); // Top-left
    glVertex2f(-0.48f, 0.285f); // Top-right
    glVertex2f(-0.408f, 0.285f); // Bottom-right
    glEnd();

    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, 0.27f); // Bottom-left
    glVertex2f(-0.475f, 0.27f); // Bottom-right
    glVertex2f(-0.475f, 0.255f); // Top-right
    glVertex2f(-0.45f, 0.255f); // Top-left
    glEnd();

    ///lamp 4
    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.1f); // Bottom-left
    glVertex2f(-0.208f, -0.1f); // Top-left
    glVertex2f(-0.208f, 0.3f); // Top-right
    glVertex2f(-0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
     glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.208f, 0.27f); // Bottom-left
    glVertex2f(-0.28f, 0.27f); // Top-left
    glVertex2f(-0.28f, 0.285f); // Top-right
    glVertex2f(-0.208f, 0.285f); // Bottom-right
    glEnd();

    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, 0.27f); // Bottom-left
    glVertex2f(-0.275f, 0.27f); // Bottom-right
    glVertex2f(-0.275f, 0.255f); // Top-right
    glVertex2f(-0.25f, 0.255f); // Top-left
    glEnd();

    ///lamp 5
    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.00f, -0.1f); // Bottom-left
    glVertex2f(-0.008f, -0.1f); // Top-left
    glVertex2f(-0.008f, 0.3f); // Top-right
    glVertex2f(-0.00f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.008f, 0.27f); // Bottom-left
    glVertex2f(-0.08f, 0.27f); // Top-left
    glVertex2f(-0.08f, 0.285f); // Top-right
    glVertex2f(-0.008f, 0.285f); // Bottom-right
    glEnd();
    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.27f); // Bottom-left
    glVertex2f(-0.075f, 0.27f); // Bottom-right
    glVertex2f(-0.075f, 0.255f); // Top-right
    glVertex2f(-0.05f, 0.255f); // Top-left
    glEnd();

    ///lamp 6
    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, -0.1f); // Bottom-left
    glVertex2f(0.208f, -0.1f); // Top-left
    glVertex2f(0.208f, 0.3f); // Top-right
    glVertex2f(0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, 0.27f); // Bottom-left
    glVertex2f(0.112f, 0.27f); // Top-left
    glVertex2f(0.112f, 0.285f); // Top-right
    glVertex2f(0.20f, 0.285f); // Bottom-right
    glEnd();

    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.142f, 0.27f); // Bottom-left
    glVertex2f(0.117f, 0.27f); // Bottom-right
    glVertex2f(0.117f, 0.255f); // Top-right
    glVertex2f(0.142f, 0.255f); // Top-left
    glEnd();

          ///lamp 7
    /// Light pole

     glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, -0.1f); // Bottom-left
    glVertex2f(0.408f, -0.1f); // Top-left
    glVertex2f(0.408f, 0.3f); // Top-right
    glVertex2f(0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, 0.27f); // Bottom-left
    glVertex2f(0.312f, 0.27f); // Top-left
    glVertex2f(0.312f, 0.285f); // Top-right
    glVertex2f(0.40f, 0.285f); // Bottom-right
    glEnd();
    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.342f, 0.27f); // Bottom-left
    glVertex2f(0.317f, 0.27f); // Bottom-right
    glVertex2f(0.317f, 0.255f); // Top-right
    glVertex2f(0.342f, 0.255f); // Top-left
    glEnd();

      ///lamp 8
    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, -0.1f); // Bottom-left
    glVertex2f(0.608f, -0.1f); // Top-left
    glVertex2f(0.608f, 0.3f); // Top-right
    glVertex2f(0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, 0.27f); // Bottom-left
    glVertex2f(0.512f, 0.27f); // Top-left
    glVertex2f(0.512f, 0.285f); // Top-right
    glVertex2f(0.60f, 0.285f); // Bottom-right
    glEnd();

    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.542f, 0.27f); // Bottom-left
    glVertex2f(0.517f, 0.27f); // Bottom-right
    glVertex2f(0.517f, 0.255f); // Top-right
    glVertex2f(0.542f, 0.255f); // Top-left
    glEnd();

       ///lamp 9
    /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, -0.1f); // Bottom-left
    glVertex2f(0.808f, -0.1f); // Top-left
    glVertex2f(0.808f, 0.3f); // Top-right
    glVertex2f(0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, 0.27f); // Bottom-left
    glVertex2f(0.712f, 0.27f); // Top-left
    glVertex2f(0.712f, 0.285f); // Top-right
    glVertex2f(0.80f, 0.285f); // Bottom-right
    glEnd();

    /// Light
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.742f, 0.27f); // Bottom-left
    glVertex2f(0.717f, 0.27f); // Bottom-right
    glVertex2f(0.717f, 0.255f); // Top-right
    glVertex2f(0.742f, 0.255f); // Top-left
    glEnd();
}
void trafficlight(){
///traffic light
    /// Light pole
    glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.08f, -0.1f); // Bottom-left
    glVertex2f(0.07f, -0.1f); // Top-left
    glVertex2f(0.07f, 0.25f); // Top-right
    glVertex2f(0.08f, 0.25f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.07f, 0.22f); // Bottom-left
    glVertex2f(-0.04f, 0.22f); // Top-left
    glVertex2f(-0.04f, 0.235f); // Top-right
    glVertex2f(0.07f, 0.235f); // Bottom-right
    glEnd();

    /// Light red
    glColor3f(1.0f, 0.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.033f, 0.22f); // Bottom-left
    glVertex2f(-0.013f, 0.22f); // Bottom-right
    glVertex2f(-0.013f, 0.195f); // Top-right
    glVertex2f(-0.033f, 0.195f); // Top-left
    glEnd();

    /// Light green
    glColor3f(0.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.003f, 0.22f); // Bottom-left
    glVertex2f(0.017f, 0.22f); // Bottom-right
    glVertex2f(0.017f, 0.195f); // Top-right
    glVertex2f(-0.003f, 0.195f); // Top-left
    glEnd();

    /// Light yellow
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.027f, 0.22f); // Bottom-left
    glVertex2f(0.047f, 0.22f); // Bottom-right
    glVertex2f(0.047f, 0.195f); // Top-right
    glVertex2f(0.027f, 0.195f); // Top-left
    glEnd();
}
void road(){
///road
   glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(-1.0f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.05f);
    glVertex2f(1.0f, -0.05f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -0.05f);
    glVertex2f(-0.80f, -0.05f);
    glVertex2f(-0.80f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.60f, -0.05f);
    glVertex2f(-0.40f, -0.05f);
    glVertex2f(-0.40f, 0.0f);
    glVertex2f(-0.60f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.05f);
    glVertex2f(0.00f, -0.05f);
    glVertex2f(0.00f, 0.0f);
    glVertex2f(-0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.20f, -0.05f);
    glVertex2f(0.40f, -0.05f);
    glVertex2f(0.40f, 0.0f);
    glVertex2f(0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.60f, -0.05f);
    glVertex2f(0.80f, -0.05f);
    glVertex2f(0.80f, 0.0f);
    glVertex2f(0.60f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(-1.0f, -0.37f);
    glVertex2f(-0.80f, -0.37f);
    glVertex2f(-0.80f, -0.4f);
    glVertex2f(-1.0f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(-0.60f, -0.37f);
    glVertex2f(-0.40f, -0.37f);
    glVertex2f(-0.40f, -0.4f);
    glVertex2f(-0.60f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(-0.20f, -0.37f);
    glVertex2f(0.00f, -0.37f);
    glVertex2f(0.00f, -0.4f);
    glVertex2f(-0.20f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.20f, -0.37f);
    glVertex2f(0.40f, -0.37f);
    glVertex2f(0.40f, -0.4f);
    glVertex2f(0.20f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.37f);
    glVertex2f(0.80f, -0.37f);
    glVertex2f(0.80f, -0.4f);
    glVertex2f(0.60f, -0.4f);
    glEnd();
}
void zebracrossing(){
 ///zebra crossing
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.11f);
    glVertex2f(0.00f, -0.11f);
    glVertex2f(0.00f, -0.16f);
    glVertex2f(-0.20f, -0.16f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.22f);
    glVertex2f(0.00f, -0.22f);
    glVertex2f(0.00f, -0.27f);
    glVertex2f(-0.20f, -0.27f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.33f);
    glVertex2f(0.00f, -0.33f);
    glVertex2f(0.00f, -0.38f);
    glVertex2f(-0.20f, -0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.44f);
    glVertex2f(0.00f, -0.44f);
    glVertex2f(0.00f, -0.49f);
    glVertex2f(-0.20f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.55f);
    glVertex2f(0.00f, -0.55f);
    glVertex2f(0.00f, -0.60f);
    glVertex2f(-0.20f, -0.60f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.66f);
    glVertex2f(0.00f, -0.66f);
    glVertex2f(0.00f, -0.71f);
    glVertex2f(-0.20f, -0.71f);
    glEnd();
}
void human4(){
///human 4(moved left and colors changed)

///body
 glPushMatrix();
    glTranslatef(0,-human4_Position,0);
    glRotatef(65, 0,1,0);
glBegin(GL_QUADS);
glColor3f(0.60f, 0.30f, 0.10f); // Red for body
glVertex2f(-0.2f, 0.07f);  // Shifted left
glVertex2f(-0.13f, 0.07f);
glVertex2f(-0.13f, 0.12f);
glVertex2f(-0.2f, 0.12f);
glEnd();

///left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(-0.2f, 0.06f);  // Shifted left
glVertex2f(-0.215f, 0.06f);
glVertex2f(-0.212f, 0.12f);
glVertex2f(-0.2f, 0.12f);
glEnd();

///left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.3f, 0.10f); // Red for sleeve
glVertex2f(-0.2f, 0.09f);  // Shifted left
glVertex2f(-0.215f, 0.09f);
glVertex2f(-0.212f, 0.12f);
glVertex2f(-0.2f, 0.12f);
glEnd();

///right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(-0.13f, 0.06f);  // Shifted left
glVertex2f(-0.115f, 0.06f);
glVertex2f(-0.118f, 0.12f);
glVertex2f(-0.13f, 0.12f);
glEnd();

///right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.6f, 0.3f, 0.10f); // Red for sleeve
glVertex2f(-0.13f, 0.09f);  // Shifted left
glVertex2f(-0.115f, 0.09f);
glVertex2f(-0.118f, 0.12f);
glVertex2f(-0.13f, 0.12f);
glEnd();

///legs
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.50f); // Green for left leg
glVertex2f(-0.2f, 0.02f);  // Shifted left
glVertex2f(-0.18f, 0.02f);
glVertex2f(-0.13f, 0.07f);
glVertex2f(-0.2f, 0.07f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.10f, 0.1f, 0.50f); // Green for right leg
glVertex2f(-0.15f, 0.02f);  // Shifted left
glVertex2f(-0.13f, 0.02f);
glVertex2f(-0.13f, 0.07f);
glVertex2f(-0.17f, 0.07f);
glEnd();

///shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(-0.2f, 0.01f);  // Shifted left
glVertex2f(-0.18f, 0.01f);
glVertex2f(-0.18f, 0.02f);
glVertex2f(-0.2f, 0.02f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for right shoe
glVertex2f(-0.15f, 0.01f);  // Shifted left
glVertex2f(-0.13f, 0.01f);
glVertex2f(-0.13f, 0.02f);
glVertex2f(-0.15f, 0.02f);
glEnd();

///neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(-0.175f, 0.12f);  // Shifted left
glVertex2f(-0.155f, 0.12f);
glVertex2f(-0.155f, 0.14f);
glVertex2f(-0.175f, 0.14f);
glEnd();

///face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(-0.19f, 0.14f);  // Shifted left
glVertex2f(-0.14f, 0.14f);
glVertex2f(-0.14f, 0.17f);
glVertex2f(-0.19f, 0.17f);
glEnd();

///head
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // Blonde for hat/hair
glVertex2f(-0.19f, 0.17f);  // Shifted left
glVertex2f(-0.14f, 0.17f);
glVertex2f(-0.15f, 0.19f);
glVertex2f(-0.18f, 0.19f);
glEnd();
glPopMatrix();
}
void ambulance(){
/// ambulance
     glPushMatrix();
     glTranslatef(ambulance_position,0,0);
    glBegin(GL_QUADS);/// white ambulance down body
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.35f, -0.15f);
    glVertex2f(-0.36f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);/// yellow quads
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.39f, -0.05f);
    glVertex2f(-0.39f, -0.07f);
    glVertex2f(-0.357f, -0.07f);
    glVertex2f(-0.36f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance start
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.71f, -0.13f);
    glVertex2f(-0.71f, -0.15f);
    glVertex2f(-0.69f, -0.15f);
    glVertex2f(-0.69f, -0.13f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance end
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.36f, -0.13f);
    glVertex2f(-0.36f, -0.15f);
    glVertex2f(-0.34f, -0.15f);
    glVertex2f(-0.34f, -0.13f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle line
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.36f, -0.05f);
    glVertex2f(-0.363f, -0.043f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance middle body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.363f, -0.043f);
    glVertex2f(-0.39f, -0.01f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle body end
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.7f, -0.043f);
    glVertex2f(-0.69f, -0.043f);
    glVertex2f(-0.69f, -0.01f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.65f, 0.13f);
    glVertex2f(-0.7f, -0.01f);
    glVertex2f(-0.39f, -0.01f);
    glVertex2f(-0.43f, 0.13f);
    glEnd();

    glBegin(GL_QUADS);   ///ambulance up body alarm
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.55f, 0.13f);
    glVertex2f(-0.53f, 0.13f);
    glVertex2f(-0.53f, 0.15f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue right quads
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-0.49f, 0.11f);
    glVertex2f(-0.49f, -0.01f);
    glVertex2f(-0.41f, -0.01f);
    glVertex2f(-0.45f, 0.11f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue left quads
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-0.57f, 0.11f);
    glVertex2f(-0.57f, -0.01f);
    glVertex2f(-0.5f, -0.01f);
    glVertex2f(-0.5f, 0.11f);
    glEnd();

    glBegin(GL_QUADS);/// ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.65f, 0.06f);
    glVertex2f(-0.65f, 0.04f);
    glVertex2f(-0.58f, 0.04f);
    glVertex2f(-0.58f, 0.06f);
    glEnd();

    glBegin(GL_QUADS);///  ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.62f, 0.11f);
    glVertex2f(-0.62f, -0.01f);
    glVertex2f(-0.61f, -0.01f);
    glVertex2f(-0.61f, 0.11f);
    glEnd();

    /// ambulance wheels
      glColor3f(0.0f, 0.0f, 0.0f);
    Circle(-0.62f, -0.15f, 0.05f); // First circl
      glColor3f(0.0f, 0.0f, 0.0f);
    Circle(-0.44f, -0.15f, 0.05f); // second circl

      glColor3f(0.5f, 0.5f, 0.5f);
    Circle(-0.62f, -0.15f, 0.03f);

     glColor3f(0.5f, 0.5f, 0.5f);
    Circle(-0.44f, -0.15f, 0.03f);
    glPopMatrix();
}
void policecar(){
 ///police car

      glPushMatrix();
     glTranslatef(-ambulance_position,0,0);
    glBegin(GL_QUADS);/// white policeCar down body
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.37f, -0.47f);
    glVertex2f(0.35f, -0.59f);
    glVertex2f(0.7f, -0.59f);
    glVertex2f(0.69f, -0.47f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down start line
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.34f, -0.57f);
    glVertex2f(0.34f, -0.59f);
    glVertex2f(0.37f, -0.59f);
    glVertex2f(0.37f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down end line
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.68f, -0.57f);
    glVertex2f(0.68f, -0.59f);
    glVertex2f(0.72f, -0.59f);
    glVertex2f(0.72f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);    ///policeCar middle line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.366f, -0.49f);
    glVertex2f(0.363f, -0.51f);
    glVertex2f(0.39f, -0.51f);
    glVertex2f(0.39f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar middle line
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.4f, -0.49f);
    glVertex2f(0.4f, -0.51f);
    glVertex2f(0.66f, -0.51f);
    glVertex2f(0.66f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);   ///policeCar middle line
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.67f, -0.49f);
    glVertex2f(0.67f, -0.51f);
    glVertex2f(0.695f, -0.51f);
    glVertex2f(0.693f, -0.49f);
    glEnd();

    glBegin(GL_QUADS);/// white policeCar up body
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.46f, -0.4f);
    glVertex2f(0.41f, -0.47f);
    glVertex2f(0.65f, -0.47f);
    glVertex2f(0.62f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.465f, -0.415f);
    glVertex2f(0.42f, -0.47f);
    glVertex2f(0.52f, -0.47f);
    glVertex2f(0.52f, -0.415f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.53f, -0.415f);
    glVertex2f(0.53f, -0.47f);
    glVertex2f(0.64f, -0.47f);
    glVertex2f(0.615f, -0.415f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.475f, -0.38f);
    glVertex2f(0.475f, -0.4f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.49f, -0.38f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar upper light
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.49f, -0.38f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.505f, -0.4f);
    glVertex2f(0.505f, -0.38f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.505f, -0.38f);
    glVertex2f(0.505f, -0.4f);
    glVertex2f(0.52f, -0.4f);
    glVertex2f(0.52f, -0.38f);
    glEnd();

    ///police car wheels
    glColor3f(0.0f,0.0f,0.0f);
     Circle(0.44f, -0.61f, 0.05f); // Black outer circle (tire)
     glColor3f(0.5f,0.5f,0.5f);
    Circle(0.44f, -0.61f, 0.03f); // Gray inner circle (rim)

    // Front wheel
      glColor3f(0.0f,0.0f,0.0f);
    Circle(0.62f, -0.61f, 0.05f); // Black outer circle (tire)
    glColor3f(0.5f,0.5f,0.5f);
    Circle(0.62f, -0.61f, 0.03f); // Gray inner circle (rim)
    glPopMatrix();
}
void downfootpath(){
/// down footpath
    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.63f, 0.58f);
    glVertex2f(-1.0f, -0.72f);
    glVertex2f(1.0f, -0.72f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}
void downblackboarder(){
  glBegin(GL_QUADS);///black boarder
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(1.0f, -0.70f);
    glVertex2f(1.0f, -0.72f);
    glVertex2f(-1.0f, -0.72f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(-0.80f, -0.70f);
    glVertex2f(-0.80f, -0.72f);
    glVertex2f(-1.0f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.60f, -0.70f);
    glVertex2f(-0.40f, -0.70f);
    glVertex2f(-0.40f, -0.72f);
    glVertex2f(-0.60f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.20f, -0.70f);
    glVertex2f(0.00f, -0.70f);
    glVertex2f(0.00f, -0.72f);
    glVertex2f(-0.20f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.20f, -0.70f);
    glVertex2f(0.40f, -0.70f);
    glVertex2f(0.40f, -0.72f);
    glVertex2f(0.20f, -0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.60f, -0.70f);
    glVertex2f(0.80f, -0.70f);
    glVertex2f(0.80f, -0.72f);
    glVertex2f(0.60f, -0.72f);
    glEnd();
}
void human3(){
///human 3
     glPushMatrix();
    glTranslatef(-human3_Position,0,0);
    glRotatef(65, 0,1,0);
// Body
glBegin(GL_QUADS);
glColor3f(0.8f, 0.1f, 0.1f); // New color for body (e.g., red)
glVertex2f(0.0f, -0.81f);
glVertex2f(0.07f, -0.81f);
glVertex2f(0.07f, -0.76f);
glVertex2f(0.0f, -0.76f);
glEnd();

// Left hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
glVertex2f(0.0f, -0.82f);
glVertex2f(-0.015f, -0.82f);
glVertex2f(-0.012f, -0.76f);
glVertex2f(0.0f, -0.76f);
glEnd();

// Left hand sleeve
glBegin(GL_QUADS);
glColor3f(0.8f, 0.1f, 0.1f); // Red for sleeve
glVertex2f(0.0f, -0.79f);
glVertex2f(-0.015f, -0.79f);
glVertex2f(-0.012f, -0.76f);
glVertex2f(0.0f, -0.76f);
glEnd();

// Right hand
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
glVertex2f(0.07f, -0.82f);
glVertex2f(0.085f, -0.82f);
glVertex2f(0.082f, -0.76f);
glVertex2f(0.07f, -0.76f);
glEnd();

// Right hand sleeve
glBegin(GL_QUADS);
glColor3f(0.8f, 0.1f, 0.1f); // Red for sleeve
glVertex2f(0.07f, -0.79f);
glVertex2f(0.085f, -0.79f);
glVertex2f(0.082f, -0.76f);
glVertex2f(0.07f, -0.76f);
glEnd();

// Legs
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.8f); // New color for pants (e.g., blue)
glVertex2f(0.0f, -0.86f);
glVertex2f(0.02f, -0.86f);
glVertex2f(0.07f, -0.81f);
glVertex2f(0.0f, -0.81f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.8f); // Slightly lighter blue for the right leg
glVertex2f(0.05f, -0.86f);
glVertex2f(0.07f, -0.86f);
glVertex2f(0.07f, -0.81f);
glVertex2f(0.03f, -0.81f);
glEnd();

// Shoes
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
glVertex2f(0.0f, -0.87f);
glVertex2f(0.02f, -0.87f);
glVertex2f(0.02f, -0.86f);
glVertex2f(0.0f, -0.86f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for right shoe
glVertex2f(0.05f, -0.87f);
glVertex2f(0.07f, -0.87f);
glVertex2f(0.07f, -0.86f);
glVertex2f(0.05f, -0.86f);
glEnd();

// Neck
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
glVertex2f(0.025f, -0.76f);
glVertex2f(0.045f, -0.76f);
glVertex2f(0.045f, -0.74f);
glVertex2f(0.025f, -0.74f);
glEnd();

// Face
glBegin(GL_QUADS);
glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
glVertex2f(0.01f, -0.74f);
glVertex2f(0.06f, -0.74f);
glVertex2f(0.06f, -0.71f);
glVertex2f(0.01f, -0.71f);
glEnd();

// Hair
glBegin(GL_QUADS);
glColor3f(0.3f, 0.2f, 0.1f); // New hair color (e.g., brown)
glVertex2f(0.01f, -0.71f);
glVertex2f(0.06f, -0.71f);
glVertex2f(0.05f, -0.69f);
glVertex2f(0.02f, -0.69f);
glEnd();
glPopMatrix();
}
void night_view() {    /// night_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
     glLoadIdentity();
sky();
star();
moon();
plane();
cloud();
greenquad();
building();
tree();
bench();
lamppost();
boarde();
upfootpath();
human2();
human1();
roadlamppost();
trafficlight();
road();
zebracrossing();
downfootpath();
downblackboarder();
human4();
ambulance();
policecar();
human3();
glFlush();
}



void sky1(){
///sky
        glBegin(GL_QUADS);
glColor3f(0.988f, 0.639f, 0.239f); // sky
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glColor3f(0.0f, 0.522f, 1.0f); // sky transition
glVertex2f(1.0f, 1.0f);
glVertex2f(-1.0f, 1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.95f, 0.951f, 0.951f); // line
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glEnd();

    ///sky
        glBegin(GL_QUADS);
glColor3f(0.988f, 0.639f, 0.239f); // sky
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glColor3f(0.0f, 0.522f, 1.0f); // sky transition
glVertex2f(1.0f, 1.0f);
glVertex2f(-1.0f, 1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.95f, 0.951f, 0.951f); // line
glVertex2f(-1.0f, 0.1f);
glVertex2f(1.0f, 0.1f);
glEnd();
}
void sun(){
      ///sun
    glColor3f(1.0,0.3,0.0);
    glPushMatrix();
    glTranslatef(0,sunPosition,0);
    Circle(0.7, 0.8, 0.07);
    glPopMatrix();
}
void cloud1(){

 /// Draw cloud 1 right
 glPushMatrix();
 glTranslatef(cloud1position,0,0);
    glColor3f(0.70f, 0.68f, 0.67f); // White color for cloud

    /// Base circles1
    Circle(-0.7f, 0.8f, 0.1f); // First circle
    Circle(-0.6f, 0.8f, 0.13f); // Second circle
    Circle(-0.5f, 0.8f, 0.1f); // Third circle

    /// Top circles 1
    Circle(-0.65f, 0.85f, 0.1f); // Fourth circle
    Circle(-0.55f, 0.85f, 0.1f);  // Fifth circle
      glPopMatrix();

    ///cloud 2 left
    glPushMatrix();
 glTranslatef(-cloud2position,0,0);
      glColor3f(0.70f, 0.68f, 0.67f); // White color for cloud

    /// Base circles
    Circle(0.5f, 0.65f, 0.1f); // First circle
    Circle(0.4f, 0.65f, 0.13f); // Second circle
    Circle(0.3f, 0.65f, 0.1f); // Third circle

    /// Top circles
    Circle(0.46f, 0.7f, 0.1f); // Fourth circle
    Circle(0.35f, 0.7f, 0.1f);  // Fifth circle

    glPopMatrix();
}
void building1(){
///building behind 3 with updated building color

glBegin(GL_QUADS);
glColor3f(0.9f, 0.4f, 0.2f); // Deep orange and light red mixed color
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.3f, 0.1f); // Deep orange and light red mixed color
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glEnd();

///windows remain the same color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.90f, 0.60f);
glVertex2f(-0.87f, 0.60f);
glVertex2f(-0.87f, 0.66f);
glVertex2f(-0.90f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.82f, 0.60f);
glVertex2f(-0.85f, 0.60f);
glVertex2f(-0.85f, 0.66f);
glVertex2f(-0.82f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.90f, 0.68f);
glVertex2f(-0.87f, 0.68f);
glVertex2f(-0.87f, 0.74f);
glVertex2f(-0.90f, 0.74f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.82f, 0.68f);
glVertex2f(-0.85f, 0.68f);
glVertex2f(-0.85f, 0.74f);
glVertex2f(-0.82f, 0.74f);
glEnd();


///building behind 4 moved down by 0.2 on y-axis and building color changed

glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.763f, 0.654f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "HOTEL");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.3f, 0.7f); // Changed color
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glVertex2f(-0.65f, 0.2f);
glVertex2f(-0.77f, 0.2f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.1f, 0.2f, 0.6f); // Changed color
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glVertex2f(-0.62f, 0.2f);
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.77f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.62f, 0.62f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.2f);
glEnd();

///windows (no color change, only y-axis shift)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.75f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.72f, 0.54f);
glVertex2f(-0.72f, 0.60f);
glVertex2f(-0.75f, 0.60f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.67f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.70f, 0.54f);
glVertex2f(-0.70f, 0.60f);
glVertex2f(-0.67f, 0.60f);
glEnd();


///building behind 5 with updated position and golden yellow color
    glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.40f, 0.733f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AIUB");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.7f, 0.1f); // Golden yellow
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glVertex2f(-0.30f, 0.2f);
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.6f, 0.1f); // Golden yellow (darker shade)
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glVertex2f(-0.27f, 0.2f);
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.27f, 0.70f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.5 x-axis
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.55f);
glVertex2f(-0.37f, 0.61f);
glVertex2f(-0.40f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.32f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.55f);
glVertex2f(-0.35f, 0.61f);
glVertex2f(-0.32f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.63f);
glVertex2f(-0.37f, 0.69f);
glVertex2f(-0.40f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.32f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.63f);
glVertex2f(-0.35f, 0.69f);
glVertex2f(-0.32f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.40f, 0.47f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.47f);
glVertex2f(-0.37f, 0.53f);
glVertex2f(-0.40f, 0.53f);
glEnd();

/// Updated Building Code behind 11
//glMatrixMode();
//glScalef(0,0,0);
glColor3f(1.0,1.0,0.0);
renderBitmapString(0.05f, 0.59f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "CMH");

// Building structure (shifted 0.76 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // Green color for building
glVertex2f(0.02f, 0.59f); // Shifted by 0.76 on x-axis
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.0f, 0.0f); // Darker green for the side
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glVertex2f(0.14f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.14f, 0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glEnd();

// Windows (shifted by 0.13 x-axis)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(0.05f, 0.41f);
glVertex2f(0.08f, 0.41f);
glVertex2f(0.08f, 0.47f);
glVertex2f(0.05f, 0.47f);
glEnd();



glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(0.05f, 0.49f);
glVertex2f(0.08f, 0.49f);
glVertex2f(0.08f, 0.55f);
glVertex2f(0.05f, 0.55f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(0.13f, 0.49f);
glVertex2f(0.10f, 0.49f);
glVertex2f(0.10f, 0.55f);
glVertex2f(0.13f, 0.55f);
glEnd();
//glPopMatrix();




/// Updated Building Code behind 10

// Building structure (shifted 0.63 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(0.01f, 0.90f, 0.98f); // Green color for building
glVertex2f(-0.11f, 0.65f); // Shifted by 0.63 on x-axis
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.80f, 0.88f); // Darker green for the side
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glVertex2f(0.01f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(0.01f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(-0.08f, 0.47f);
glVertex2f(-0.05f, 0.47f);
glVertex2f(-0.05f, 0.53f);
glVertex2f(-0.08f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(0.00f, 0.47f);
glVertex2f(-0.03f, 0.47f);
glVertex2f(-0.03f, 0.53f);
glVertex2f(0.00f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(-0.08f, 0.55f);
glVertex2f(-0.05f, 0.55f);
glVertex2f(-0.05f, 0.61f);
glVertex2f(-0.08f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(0.00f, 0.55f);
glVertex2f(-0.03f, 0.55f);
glVertex2f(-0.03f, 0.61f);
glVertex2f(0.00f, 0.61f);
glEnd();

/// Updated Building Code behind 9

// Building structure (shifted 0.5 on x-axis, changed color to blue)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // Blue color for building
glVertex2f(-0.24f, 0.60f); // Shifted by 0.5 on x-axis
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.8f); // Darker color for the side
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glVertex2f(-0.12f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.12f, 0.60f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(-0.21f, 0.42f);
glVertex2f(-0.18f, 0.42f);
glVertex2f(-0.18f, 0.48f);
glVertex2f(-0.21f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(-0.13f, 0.42f);
glVertex2f(-0.16f, 0.42f);
glVertex2f(-0.16f, 0.48f);
glVertex2f(-0.13f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(-0.21f, 0.50f);
glVertex2f(-0.18f, 0.50f);
glVertex2f(-0.18f, 0.56f);
glVertex2f(-0.21f, 0.56f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(-0.13f, 0.50f);
glVertex2f(-0.16f, 0.50f);
glVertex2f(-0.16f, 0.56f);
glVertex2f(-0.13f, 0.56f);
glEnd();






///building behind 8 moved by 0.07 on x-axis and 0.2 on y-axis with cyan-red mixed color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.8f, 0.7f); // Cyan-red mixed
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glVertex2f(-0.45f, 0.2f);
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.7f, 0.6f); // Cyan-red mixed (darker shade)
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glVertex2f(-0.42f, 0.2f);
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.42f, 0.62f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.07 and y-axis shift by 0.2)


glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.545f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.515f, 0.56f);
glVertex2f(-0.515f, 0.62f);
glVertex2f(-0.545f, 0.62f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.47f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.50f, 0.56f);
glVertex2f(-0.50f, 0.62f);
glVertex2f(-0.47f, 0.62f);
glEnd();


///building behind 7 moved down by 0.2 on y-axis and shifted by 0.1 on x-axis with red-yellow mixed color
    glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.61f, 0.553f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "SCHOOL");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.5f, 0.2f); // Red-yellow mixed
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glVertex2f(-0.49f, 0.2f);
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.4f, 0.1f); // Red-yellow mixed (lighter shade)
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glVertex2f(-0.46f, 0.2f);
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.46f, 0.52f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.1 and y-axis shift by -0.2)
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.585f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.44f);
glVertex2f(-0.555f, 0.50f);
glVertex2f(-0.585f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.51f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.44f);
glVertex2f(-0.54f, 0.50f);
glVertex2f(-0.51f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.585f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.36f);
glVertex2f(-0.555f, 0.42f);
glVertex2f(-0.585f, 0.42f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // No change in window color
glVertex2f(-0.51f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.36f);
glVertex2f(-0.54f, 0.42f);
glVertex2f(-0.51f, 0.42f);
glEnd();




///building behind 6 with updated position and blue-yellow mixed color
    glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.34f, 0.533f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "OFFICE");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.5f, 0.0f); // Blue-yellow mixed (dominantly blue)
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glVertex2f(-0.23f, 0.2f);
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.4f, 0.1f); // Blue-yellow mixed (lighter shade)
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glVertex2f(-0.20f, 0.2f);
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.20f, 0.50f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.07 x-axis
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.33f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.35f);
glVertex2f(-0.30f, 0.41f);
glVertex2f(-0.33f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.25f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.35f);
glVertex2f(-0.28f, 0.41f);
glVertex2f(-0.25f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.33f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.43f);
glVertex2f(-0.30f, 0.49f);
glVertex2f(-0.33f, 0.49f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f); // Window color remains unchanged
glVertex2f(-0.25f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.43f);
glVertex2f(-0.28f, 0.49f);
glVertex2f(-0.25f, 0.49f);
glEnd();

   ///building behind 2
       glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.88f, 0.603f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "POLICE");
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(-0.89f,0.60f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.77f,0.2f);
    glVertex2f(-0.89f,0.2f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.74f,0.57f);
    glVertex2f(-0.74f,0.2f);
    glVertex2f(-0.77f,0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.89f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.77f, 0.60f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.77f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.74f, 0.57f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.74f, 0.57f);
    glVertex2f(-0.74f, 0.2f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.86f, 0.42f);
    glVertex2f(-0.83f, 0.42f);
    glVertex2f(-0.83f, 0.48f);
    glVertex2f(-0.86f, 0.48f);
    glEnd();

          glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.78f, 0.42f);
    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.81f, 0.48f);
    glVertex2f(-0.78f, 0.48f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.86f, 0.50f);
    glVertex2f(-0.83f, 0.50f);
    glVertex2f(-0.83f, 0.56f);
    glVertex2f(-0.86f, 0.56f);
    glEnd();

          glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.78f, 0.50f);
    glVertex2f(-0.81f, 0.50f);
    glVertex2f(-0.81f, 0.56f);
    glVertex2f(-0.78f, 0.56f);
    glEnd();






///building
     glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glEnd();
       glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);

    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.98f, 0.31f);
    glVertex2f(-0.95f, 0.31f);
    glVertex2f(-0.95f, 0.35f);
    glVertex2f(-0.98f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.94f, 0.31f);
    glVertex2f(-0.91f, 0.31f);
    glVertex2f(-0.91f, 0.35f);
    glVertex2f(-0.94f, 0.35f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.98f, 0.37f);
    glVertex2f(-0.95f, 0.37f);
    glVertex2f(-0.95f, 0.41f);
    glVertex2f(-0.98f, 0.41f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.94f, 0.37f);
    glVertex2f(-0.91f, 0.37f);
    glVertex2f(-0.91f, 0.41f);
    glVertex2f(-0.94f, 0.41f);
    glEnd();

    ///p3

       glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.98f, 0.43f);
    glVertex2f(-0.95f, 0.43f);
    glVertex2f(-0.95f, 0.47f);
    glVertex2f(-0.98f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.94f, 0.43f);
    glVertex2f(-0.91f, 0.43f);
    glVertex2f(-0.91f, 0.47f);
    glVertex2f(-0.94f, 0.47f);
    glEnd();



    ///1 building

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-1.0f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

///window
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.99f, 0.26f);
    glVertex2f(-0.96f, 0.26f);
    glVertex2f(-0.96f, 0.22f);
    glVertex2f(-0.99f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.95f, 0.26f);
    glVertex2f(-0.92f, 0.26f);
    glVertex2f(-0.92f, 0.22f);
    glVertex2f(-0.95f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glEnd();




    ///2 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glEnd();




    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.84f, 0.22f);
    glVertex2f(-0.81f, 0.22f);
    glVertex2f(-0.81f, 0.26f);
    glVertex2f(-0.84f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.8f, 0.22f);
    glVertex2f(-0.77f, 0.22f);
    glVertex2f(-0.77f, 0.26f);
    glVertex2f(-0.8f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.84f, 0.28f);
    glVertex2f(-0.81f, 0.28f);
    glVertex2f(-0.81f, 0.32f);
    glVertex2f(-0.84f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.8f, 0.28f);
    glVertex2f(-0.77f, 0.28f);
    glVertex2f(-0.77f, 0.32f);
    glVertex2f(-0.8f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.84f, 0.34f);
    glVertex2f(-0.81f, 0.34f);
    glVertex2f(-0.81f, 0.38f);
    glVertex2f(-0.84f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.8f, 0.34f);
    glVertex2f(-0.77f, 0.34f);
    glVertex2f(-0.77f, 0.38f);
    glVertex2f(-0.8f, 0.38f);
    glEnd();

    ///3 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.70f, 0.22f);
    glVertex2f(-0.67f, 0.22f);
    glVertex2f(-0.67f, 0.26f);
    glVertex2f(-0.70f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.66f, 0.22f);
    glVertex2f(-0.63f, 0.22f);
    glVertex2f(-0.63f, 0.26f);
    glVertex2f(-0.66f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.67f, 0.28f);
    glVertex2f(-0.67f, 0.32f);
    glVertex2f(-0.7f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.66f, 0.28f);
    glVertex2f(-0.63f, 0.28f);
    glVertex2f(-0.63f, 0.32f);
    glVertex2f(-0.66f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7f, 0.34f);
    glVertex2f(-0.67f, 0.34f);
    glVertex2f(-0.67f, 0.38f);
    glVertex2f(-0.7f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.66f, 0.34f);
    glVertex2f(-0.63f, 0.34f);
    glVertex2f(-0.63f, 0.38f);
    glVertex2f(-0.66f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.67f, 0.40f);
    glVertex2f(-0.67f, 0.44f);
    glVertex2f(-0.7f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.66f, 0.40f);
    glVertex2f(-0.63f, 0.40f);
    glVertex2f(-0.63f, 0.44f);
    glVertex2f(-0.66f, 0.44f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.7f, 0.46f);
    glVertex2f(-0.67f, 0.46f);
    glVertex2f(-0.67f, 0.50f);
    glVertex2f(-0.7f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.66f, 0.46f);
    glVertex2f(-0.63f, 0.46f);
    glVertex2f(-0.63f, 0.50f);
    glVertex2f(-0.66f, 0.50f);
    glEnd();

    ///4 building 4

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glEnd();


    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.56f, 0.22f);
    glVertex2f(-0.53f, 0.22f);
    glVertex2f(-0.53f, 0.26f);
    glVertex2f(-0.56f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.52f, 0.22f);
    glVertex2f(-0.49f, 0.22f);
    glVertex2f(-0.49f, 0.26f);
    glVertex2f(-0.52f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.52f, 0.28f);
    glVertex2f(-0.49f, 0.28f);
    glVertex2f(-0.49f, 0.32f);
    glVertex2f(-0.52f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.53f, 0.28f);
    glVertex2f(-0.53f, 0.32f);
    glVertex2f(-0.56f, 0.32f);
    glEnd();

    ///5 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.43f, 0.22f);
    glVertex2f(-0.4f, 0.22f);
    glVertex2f(-0.4f, 0.26f);
    glVertex2f(-0.43f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.39f, 0.22f);
    glVertex2f(-0.36f, 0.22f);
    glVertex2f(-0.36f, 0.26f);
    glVertex2f(-0.39f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.43f, 0.28f);
    glVertex2f(-0.4f, 0.28f);
    glVertex2f(-0.4f, 0.32f);
    glVertex2f(-0.43f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.39f, 0.28f);
    glVertex2f(-0.36f, 0.28f);
    glVertex2f(-0.36f, 0.32f);
    glVertex2f(-0.39f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.43f, 0.34f);
    glVertex2f(-0.4f, 0.34f);
    glVertex2f(-0.4f, 0.38f);
    glVertex2f(-0.43f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.39f, 0.34f);
    glVertex2f(-0.36f, 0.34f);
    glVertex2f(-0.36f, 0.38f);
    glVertex2f(-0.39f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.43f, 0.40f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(-0.4f, 0.44f);
    glVertex2f(-0.43f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.39f, 0.40f);
    glVertex2f(-0.36f, 0.40f);
    glVertex2f(-0.36f, 0.44f);
    glVertex2f(-0.39f, 0.44f);
    glEnd();

    ///6 building
        glColor3f(1.0,1.0,0.0);
renderBitmapString(-0.29f, 0.362f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "FOOD");
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.28f, 0.22f);
    glVertex2f(-0.25f, 0.22f);
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.28f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.24f, 0.22f);
    glVertex2f(-0.21f, 0.22f);
    glVertex2f(-0.21f, 0.26f);
    glVertex2f(-0.24f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.28f, 0.28f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.25f, 0.32f);
    glVertex2f(-0.28f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.24f, 0.28f);
    glVertex2f(-0.21f, 0.28f);
    glVertex2f(-0.21f, 0.32f);
    glVertex2f(-0.24f, 0.32f);
    glEnd();

    ///7 building
    glBegin(GL_QUADS);
    glColor3f(0.37f, 0.50f, 0.96f);
    glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.50f, 0.86f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.16f, 0.22f);
    glVertex2f(-0.13f, 0.22f);
    glVertex2f(-0.13f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.09f, 0.22f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.12f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.16f, 0.28f);
    glVertex2f(-0.13f, 0.28f);
    glVertex2f(-0.13f, 0.32f);
    glVertex2f(-0.16f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.12f, 0.28f);
    glVertex2f(-0.09f, 0.28f);
    glVertex2f(-0.09f, 0.32f);
    glVertex2f(-0.12f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.16f, 0.34f);
    glVertex2f(-0.13f, 0.34f);
    glVertex2f(-0.13f, 0.38f);
    glVertex2f(-0.16f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.12f, 0.34f);
    glVertex2f(-0.09f, 0.34f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.12f, 0.38f);
    glEnd();

    ///8 building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glVertex2f(0.04f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.03f, 0.22f);
    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.03f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.01f, 0.22f);
    glVertex2f(0.03f, 0.22f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.01f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.03f, 0.28f);
    glVertex2f(-0.01f, 0.28f);
    glVertex2f(-0.01f, 0.32f);
    glVertex2f(-0.03f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.01f, 0.28f);
    glVertex2f(0.03f, 0.28f);
    glVertex2f(0.03f, 0.32f);
    glVertex2f(0.01f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.03f, 0.34f);
    glVertex2f(-0.01f, 0.34f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(-0.03f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.01f, 0.34f);
    glVertex2f(0.03f, 0.34f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.01f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.03f, 0.40f);
    glVertex2f(-0.01f, 0.40f);
    glVertex2f(-0.01f, 0.44f);
    glVertex2f(-0.03f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.01f, 0.40f);
    glVertex2f(0.03f, 0.40f);
    glVertex2f(0.03f, 0.44f);
    glVertex2f(0.01f, 0.44f);
    glEnd();

    ///9 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glEnd();




    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.09f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.26f);
    glVertex2f(0.09f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.13f, 0.22f);
    glVertex2f(0.16f, 0.22f);
    glVertex2f(0.16f, 0.26f);
    glVertex2f(0.13f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.09f, 0.28f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.12f, 0.32f);
    glVertex2f(0.09f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.13f, 0.28f);
    glVertex2f(0.16f, 0.28f);
    glVertex2f(0.16f, 0.32f);
    glVertex2f(0.13f, 0.32f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.09f, 0.34f);
    glVertex2f(0.12f, 0.34f);
    glVertex2f(0.12f, 0.38f);
    glVertex2f(0.09f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.13f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.16f, 0.38f);
    glVertex2f(0.13f, 0.38f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.09f, 0.40f);
    glVertex2f(0.12f, 0.40f);
    glVertex2f(0.12f, 0.44f);
    glVertex2f(0.09f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.13f, 0.40f);
    glVertex2f(0.16f, 0.40f);
    glVertex2f(0.16f, 0.44f);
    glVertex2f(0.13f, 0.44f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.12f, 0.46f);
    glVertex2f(0.12f, 0.50f);
    glVertex2f(0.09f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.13f, 0.46f);
    glVertex2f(0.16f, 0.46f);
    glVertex2f(0.16f, 0.50f);
    glVertex2f(0.13f, 0.50f);
    glEnd();
}
void tree1(){
//tree

   ///leaf

 glColor3f(0.12f, 0.41f, 0.20f); // White color for cloud

    /// Base circles
    Circle(0.98f, 0.53f, 0.08f); // First circle
    Circle(0.88f, 0.51f, 0.10f); // Second circle
    Circle(0.78f, 0.53f, 0.08f); // Third circle

    /// Top circles
    Circle(0.94f, 0.65f, 0.08f); // Fourth circle
    Circle(0.83f, 0.65f, 0.08f);  // Fifth circle
    Circle(0.88f, 0.75f, 0.08f);


glColor3f(0.530f, 0.271f, 0.075f); // Brown color for the trunk

// Polygon 1
glBegin(GL_POLYGON);
glColor3f(0.530f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.83f, 0.64f);
glVertex2f(0.8f, 0.64f);
glEnd();

// Polygon 2
glBegin(GL_POLYGON);
glColor3f(0.530f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.93f, 0.68f);
glVertex2f(0.925f, 0.63f);
glEnd();

// Polygon 3
glBegin(GL_POLYGON);
glColor3f(0.530f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.3f);
glVertex2f(0.905f, 0.575f);

glVertex2f(0.86f, 0.575f);
glVertex2f(0.86f, 0.3f);
glVertex2f(0.882f,0.2f);
glEnd();

// Polygon 4
glBegin(GL_POLYGON);
glColor3f(0.530f, 0.271f, 0.075f);
glVertex2f(0.95f, 0.25f);
glVertex2f(0.82f, 0.25f);
glVertex2f(0.86f, 0.30f);
glVertex2f(0.905f, 0.30f);
glEnd();

// triangle 1
glBegin(GL_TRIANGLES);
glColor3f(0.530f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.905f, 0.575f);
glEnd();

// triangle 2
glBegin(GL_TRIANGLES);
glColor3f(0.530f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.445f);
glVertex2f(0.84f, 0.420f);
glVertex2f(0.86f, 0.470f);
glEnd();

}

void lamppost1(){
///lamp post 1

   glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.22f);
    glVertex2f(0.285f, 0.22f);
    glVertex2f(0.285f, 0.20f);
    glVertex2f(0.26f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.269f, 0.21f);
    glVertex2f(0.277f, 0.21f);
    glVertex2f(0.277f, 0.28f);
    glVertex2f(0.269f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.271f, 0.37f);
    glVertex2f(0.275f, 0.37f);
    glVertex2f(0.275f, 0.28f);
    glVertex2f(0.271f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.37f);
    glVertex2f(0.285f, 0.37f);
    glVertex2f(0.285f, 0.377f);
    glVertex2f(0.26f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.377f);
    glVertex2f(0.28f, 0.377f);
    glVertex2f(0.28f, 0.385f);
    glVertex2f(0.265f, 0.385f);
    glEnd();
        ///light color
       glBegin(GL_QUADS);
glColor3f(0.90f, 0.80f, 0.0f);
    glVertex2f(0.283f, 0.41f);
    glVertex2f(0.262f, 0.41f);
    glVertex2f(0.265f, 0.385f);
    glVertex2f(0.28f, 0.385f);
    glEnd();

///lines
        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.385f);
   glVertex2f(0.262f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.28f, 0.385f);
   glVertex2f(0.283f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.272f, 0.385f);
   glVertex2f(0.272f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.255f, 0.41f);
   glVertex2f(0.289f,0.41f);
   glVertex2f(0.272f,0.43f);
    glEnd();



///lamp post 2


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.22f);
    glVertex2f(0.835f, 0.22f);
    glVertex2f(0.835f, 0.20f);
    glVertex2f(0.81f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.819f, 0.21f);
    glVertex2f(0.827f, 0.21f);
    glVertex2f(0.827f, 0.28f);
    glVertex2f(0.819f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.821f, 0.37f);
    glVertex2f(0.825f, 0.37f);
    glVertex2f(0.825f, 0.28f);
    glVertex2f(0.821f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.37f);
    glVertex2f(0.835f, 0.37f);
    glVertex2f(0.835f, 0.377f);
    glVertex2f(0.81f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.377f);
    glVertex2f(0.83f, 0.377f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();

        ///light color
       glBegin(GL_QUADS);
glColor3f(0.90f, 0.80f, 0.0f);
    glVertex2f(0.812f, 0.41f);
    glVertex2f(0.833f, 0.41f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();

///lines

        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.385f);
   glVertex2f(0.812f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.83f, 0.385f);
   glVertex2f(0.833f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.822f, 0.385f);
   glVertex2f(0.822f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.805f, 0.41f);
   glVertex2f(0.839f,0.41f);
   glVertex2f(0.822f,0.43f);
    glEnd();


    ///double lamp post

    ///left

       glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.535f, 0.22f);
    glVertex2f(0.560f, 0.22f);
    glVertex2f(0.560f, 0.20f);
    glVertex2f(0.535f, 0.20f);
    glEnd();


      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.544f, 0.21f);
    glVertex2f(0.552f, 0.21f);
    glVertex2f(0.552f, 0.28f);
    glVertex2f(0.544f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.546f, 0.37f);
    glVertex2f(0.55f, 0.37f);
    glVertex2f(0.55f, 0.28f);
    glVertex2f(0.546f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.515f, 0.37f);
    glVertex2f(0.580f, 0.37f);
    glVertex2f(0.580f, 0.377f);
    glVertex2f(0.515f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.377f);
    glVertex2f(0.535f, 0.377f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();
    ///light color
       glBegin(GL_QUADS);
glColor3f(0.90f, 0.80f, 0.0f);
    glVertex2f(0.517f, 0.41f);
    glVertex2f(0.538f, 0.41f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();

///lines
        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.385f);
   glVertex2f(0.517f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.535f, 0.385f);
   glVertex2f(0.538f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.527f, 0.385f);
   glVertex2f(0.527f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.509f, 0.41f);
   glVertex2f(0.544f,0.41f);
   glVertex2f(0.527f,0.43f);
    glEnd();

    ///right

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.377f);
    glVertex2f(0.560f, 0.377f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();

    ///light color
       glBegin(GL_QUADS);
    glColor3f(0.90f, 0.80f, 0.0f);
    glVertex2f(0.578f, 0.41f);
    glVertex2f(0.557f, 0.41f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();

///lines
        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.560f, 0.385f);
   glVertex2f(0.557f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.385f);
   glVertex2f(0.578f,0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.567f, 0.385f);
   glVertex2f(0.567f,0.41f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.549f, 0.41f);
   glVertex2f(0.585f,0.41f);
   glVertex2f(0.567f,0.43f);
    glEnd();
}

void roadlamppost1(){
///lamp(road)
///lamp 1 left

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.80f, -0.1f); // Bottom-left
    glVertex2f(-0.808f, -0.1f); // Top-left
    glVertex2f(-0.808f, 0.3f); // Top-right
    glVertex2f(-0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.808f, 0.27f); // Bottom-left
    glVertex2f(-0.88f, 0.27f); // Top-left
    glVertex2f(-0.88f, 0.285f); // Top-right
    glVertex2f(-0.808f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.85f, 0.27f); // Bottom-left
    glVertex2f(-0.875f, 0.27f); // Bottom-right
    glVertex2f(-0.875f, 0.255f); // Top-right
    glVertex2f(-0.85f, 0.255f); // Top-left
    glEnd();


      ///lamp 2

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f, -0.1f); // Bottom-left
    glVertex2f(-0.608f, -0.1f); // Top-left
    glVertex2f(-0.608f, 0.3f); // Top-right
    glVertex2f(-0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.608f, 0.27f); // Bottom-left
    glVertex2f(-0.68f, 0.27f); // Top-left
    glVertex2f(-0.68f, 0.285f); // Top-right
    glVertex2f(-0.608f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, 0.27f); // Bottom-left
    glVertex2f(-0.675f, 0.27f); // Bottom-right
    glVertex2f(-0.675f, 0.255f); // Top-right
    glVertex2f(-0.65f, 0.255f); // Top-left
    glEnd();


      ///lamp 3

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.1f); // Bottom-left
    glVertex2f(-0.408f, -0.1f); // Top-left
    glVertex2f(-0.408f, 0.3f); // Top-right
    glVertex2f(-0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.408f, 0.27f); // Bottom-left
    glVertex2f(-0.48f, 0.27f); // Top-left
    glVertex2f(-0.48f, 0.285f); // Top-right
    glVertex2f(-0.408f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, 0.27f); // Bottom-left
    glVertex2f(-0.475f, 0.27f); // Bottom-right
    glVertex2f(-0.475f, 0.255f); // Top-right
    glVertex2f(-0.45f, 0.255f); // Top-left
    glEnd();

    ///lamp 4

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.1f); // Bottom-left
    glVertex2f(-0.208f, -0.1f); // Top-left
    glVertex2f(-0.208f, 0.3f); // Top-right
    glVertex2f(-0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.208f, 0.27f); // Bottom-left
    glVertex2f(-0.28f, 0.27f); // Top-left
    glVertex2f(-0.28f, 0.285f); // Top-right
    glVertex2f(-0.208f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, 0.27f); // Bottom-left
    glVertex2f(-0.275f, 0.27f); // Bottom-right
    glVertex2f(-0.275f, 0.255f); // Top-right
    glVertex2f(-0.25f, 0.255f); // Top-left
    glEnd();

    ///lamp 5

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.00f, -0.1f); // Bottom-left
    glVertex2f(-0.008f, -0.1f); // Top-left
    glVertex2f(-0.008f, 0.3f); // Top-right
    glVertex2f(-0.00f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.008f, 0.27f); // Bottom-left
    glVertex2f(-0.08f, 0.27f); // Top-left
    glVertex2f(-0.08f, 0.285f); // Top-right
    glVertex2f(-0.008f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.27f); // Bottom-left
    glVertex2f(-0.075f, 0.27f); // Bottom-right
    glVertex2f(-0.075f, 0.255f); // Top-right
    glVertex2f(-0.05f, 0.255f); // Top-left
    glEnd();

        ///lamp 6

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, -0.1f); // Bottom-left
    glVertex2f(0.208f, -0.1f); // Top-left
    glVertex2f(0.208f, 0.3f); // Top-right
    glVertex2f(0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, 0.27f); // Bottom-left
    glVertex2f(0.112f, 0.27f); // Top-left
    glVertex2f(0.112f, 0.285f); // Top-right
    glVertex2f(0.20f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.142f, 0.27f); // Bottom-left
    glVertex2f(0.117f, 0.27f); // Bottom-right
    glVertex2f(0.117f, 0.255f); // Top-right
    glVertex2f(0.142f, 0.255f); // Top-left
    glEnd();

          ///lamp 7

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, -0.1f); // Bottom-left
    glVertex2f(0.408f, -0.1f); // Top-left
    glVertex2f(0.408f, 0.3f); // Top-right
    glVertex2f(0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, 0.27f); // Bottom-left
    glVertex2f(0.312f, 0.27f); // Top-left
    glVertex2f(0.312f, 0.285f); // Top-right
    glVertex2f(0.40f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.342f, 0.27f); // Bottom-left
    glVertex2f(0.317f, 0.27f); // Bottom-right
    glVertex2f(0.317f, 0.255f); // Top-right
    glVertex2f(0.342f, 0.255f); // Top-left
    glEnd();

      ///lamp 8

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, -0.1f); // Bottom-left
    glVertex2f(0.608f, -0.1f); // Top-left
    glVertex2f(0.608f, 0.3f); // Top-right
    glVertex2f(0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, 0.27f); // Bottom-left
    glVertex2f(0.512f, 0.27f); // Top-left
    glVertex2f(0.512f, 0.285f); // Top-right
    glVertex2f(0.60f, 0.285f); // Bottom-right
    glEnd();


    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.542f, 0.27f); // Bottom-left
    glVertex2f(0.517f, 0.27f); // Bottom-right
    glVertex2f(0.517f, 0.255f); // Top-right
    glVertex2f(0.542f, 0.255f); // Top-left
    glEnd();

       ///lamp 9

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, -0.1f); // Bottom-left
    glVertex2f(0.808f, -0.1f); // Top-left
    glVertex2f(0.808f, 0.3f); // Top-right
    glVertex2f(0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, 0.27f); // Bottom-left
    glVertex2f(0.712f, 0.27f); // Top-left
    glVertex2f(0.712f, 0.285f); // Top-right
    glVertex2f(0.80f, 0.285f); // Bottom-right
    glEnd();

    /// Light
glColor3f(0.90f, 0.80f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.742f, 0.27f); // Bottom-left
    glVertex2f(0.717f, 0.27f); // Bottom-right
    glVertex2f(0.717f, 0.255f); // Top-right
    glVertex2f(0.742f, 0.255f); // Top-left
    glEnd();

}

void twilight_view() {    /// twilight_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    sky1();
    sun();
    cloud1();
    greenquad();
    building1();
    tree1();
    bench();
    lamppost1();
    boarde();
    upfootpath();
    human2();
    human1();
    roadlamppost1();
    trafficlight();
    road();
    zebracrossing();
    downfootpath();
downblackboarder();
   human4();
   ambulance();
   policecar();

   human3();

    glFlush();
}
void sound1()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("police-car-siren-in-traffic-14655.wav ", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void sky2(){
 ///sky
    glBegin(GL_QUADS);
            glColor3f(1.0f,1.0f,1.0f);
             glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
   glColor3f(0.10f, 0.63f, 0.97f);

    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
        glBegin(GL_LINES);
   glColor3f(0.45f, 0.45f, 0.45f);
   glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glEnd();
}

void sun1(){
    ///sun
    glColor3f(1.0, 0.80, 0.0);
glPushMatrix();
glTranslatef(sunPosition, sunPosition, 0);
Circle(0.7, 0.8, 0.07); // Draw the sun's main circle

// Sun rays
int numRays = 60; // Number of rays
float radius = 0.07; // Sun's radius
float longRayLength = 0.07; // Length of long rays
float shortRayLength = 0.03; // Length of short rays
float centerX = 0.7; // Sun's center X
float centerY = 0.8; // Sun's center Y
float angleStep = 2.0f * M_PI / numRays;

glBegin(GL_LINES); // Start buffering for rays
for (int i = 0; i < numRays; ++i) {
    float angle = i * angleStep;
    float rayLength = (i % 2 == 0) ? longRayLength : shortRayLength; // Alternate lengths

    float rayStartX = centerX + radius * cosf(angle);
    float rayStartY = centerY + radius * sinf(angle);
    float rayEndX = centerX + (radius + rayLength) * cosf(angle);
    float rayEndY = centerY + (radius + rayLength) * sinf(angle);

    glColor3f(1.0f, 0.8f, 0.3f); // Bright yellow for rays
    glVertex2f(rayStartX, rayStartY); // Start of the ray
    glVertex2f(rayEndX, rayEndY);     // End of the ray
    glutSwapBuffers();
}
glEnd(); // End buffering for rays

glPopMatrix();
}

void cloud2(){
/// Draw cloud 1 right
 glPushMatrix();
 glTranslatef(cloud1position,0,0);
    glColor3f(1.0f, 1.0f, 1.0f); // White color for cloud

    /// Base circles1
    Circle(-0.7f, 0.8f, 0.1f); // First circle
    Circle(-0.6f, 0.8f, 0.13f); // Second circle
    Circle(-0.5f, 0.8f, 0.1f); // Third circle

    /// Top circles 1
    Circle(-0.65f, 0.85f, 0.1f); // Fourth circle
    Circle(-0.55f, 0.85f, 0.1f);  // Fifth circle

      glPopMatrix();

    ///cloud 2 left
    glPushMatrix();
 glTranslatef(-cloud2position,0,0);
      glColor3f(1.0f, 1.0f, 1.0f); // White color for cloud

    /// Base circles
    Circle(0.5f, 0.65f, 0.1f); // First circle
    Circle(0.4f, 0.65f, 0.13f); // Second circle
    Circle(0.3f, 0.65f, 0.1f); // Third circle

    /// Top circles
    Circle(0.46f, 0.7f, 0.1f); // Fourth circle
    Circle(0.35f, 0.7f, 0.1f);  // Fifth circle

    glPopMatrix();

}

void building2(){
///building behind 3 with updated building color

glBegin(GL_QUADS);
glColor3f(0.9f, 0.4f, 0.2f); // Deep orange and light red mixed color
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.3f, 0.1f); // Deep orange and light red mixed color
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.92f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.92f, 0.78f);
glVertex2f(-0.80f, 0.78f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.80f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.80f, 0.78f);
glVertex2f(-0.77f, 0.75f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.77f, 0.75f);
glVertex2f(-0.77f, 0.2f);
glEnd();

///windows remain the same color
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f); // Window color remains unchanged
glVertex2f(-0.90f, 0.60f);
glVertex2f(-0.87f, 0.60f);
glVertex2f(-0.87f, 0.66f);
glVertex2f(-0.90f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);glVertex2f(-0.82f, 0.60f);
glVertex2f(-0.85f, 0.60f);
glVertex2f(-0.85f, 0.66f);
glVertex2f(-0.82f, 0.66f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);glVertex2f(-0.90f, 0.68f);
glVertex2f(-0.87f, 0.68f);
glVertex2f(-0.87f, 0.74f);
glVertex2f(-0.90f, 0.74f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);glVertex2f(-0.82f, 0.68f);
glVertex2f(-0.85f, 0.68f);
glVertex2f(-0.85f, 0.74f);
glVertex2f(-0.82f, 0.74f);
glEnd();


///building behind 4 moved down by 0.2 on y-axis and building color changed

glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.763f, 0.654f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "HOTEL");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.3f, 0.7f); // Changed color
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glVertex2f(-0.65f, 0.2f);
glVertex2f(-0.77f, 0.2f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.1f, 0.2f, 0.6f); // Changed color
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glVertex2f(-0.62f, 0.2f);
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.77f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.65f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.65f, 0.65f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.62f, 0.62f); // -0.2 to y-coordinates
glVertex2f(-0.62f, 0.2f);
glEnd();

///windows (no color change, only y-axis shift)
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.75f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.72f, 0.54f);
glVertex2f(-0.72f, 0.60f);
glVertex2f(-0.75f, 0.60f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);glVertex2f(-0.67f, 0.54f); // -0.2 to y-coordinates
glVertex2f(-0.70f, 0.54f);
glVertex2f(-0.70f, 0.60f);
glVertex2f(-0.67f, 0.60f);
glEnd();


///building behind 5 with updated position and golden yellow color
    glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.40f, 0.733f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AIUB");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.7f, 0.1f); // Golden yellow
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glVertex2f(-0.30f, 0.2f);
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.6f, 0.1f); // Golden yellow (darker shade)
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glVertex2f(-0.27f, 0.2f);
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.42f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.73f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.30f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.30f, 0.73f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.70f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.27f, 0.70f); // +0.5 to x-coordinates
glVertex2f(-0.27f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.5 x-axis
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.40f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.55f);
glVertex2f(-0.37f, 0.61f);
glVertex2f(-0.40f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.32f, 0.55f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.55f);
glVertex2f(-0.35f, 0.61f);
glVertex2f(-0.32f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.40f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.63f);
glVertex2f(-0.37f, 0.69f);
glVertex2f(-0.40f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.32f, 0.63f); // +0.5 to x-coordinates
glVertex2f(-0.35f, 0.63f);
glVertex2f(-0.35f, 0.69f);
glVertex2f(-0.32f, 0.69f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.40f, 0.47f); // +0.5 to x-coordinates
glVertex2f(-0.37f, 0.47f);
glVertex2f(-0.37f, 0.53f);
glVertex2f(-0.40f, 0.53f);
glEnd();

/// Updated Building Code behind 11
//glMatrixMode();
//glScalef(0,0,0);
glColor3f(0.0,0.0,0.0);
renderBitmapString(0.05f, 0.59f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "CMH");

// Building structure (shifted 0.76 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // Green color for building
glVertex2f(0.02f, 0.59f); // Shifted by 0.76 on x-axis
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.0f, 0.0f); // Darker green for the side
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glVertex2f(0.14f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.02f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.02f, 0.59f);
glVertex2f(0.14f, 0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.14f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.14f, 0.59f);
glVertex2f(0.17f, 0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.17f, 0.56f);
glVertex2f(0.17f, 0.2f);
glEnd();

// Windows (shifted by 0.13 x-axis)
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(0.05f, 0.41f);
glVertex2f(0.08f, 0.41f);
glVertex2f(0.08f, 0.47f);
glVertex2f(0.05f, 0.47f);
glEnd();



glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(0.05f, 0.49f);
glVertex2f(0.08f, 0.49f);
glVertex2f(0.08f, 0.55f);
glVertex2f(0.05f, 0.55f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(0.13f, 0.49f);
glVertex2f(0.10f, 0.49f);
glVertex2f(0.10f, 0.55f);
glVertex2f(0.13f, 0.55f);
glEnd();
//glPopMatrix();




/// Updated Building Code behind 10

// Building structure (shifted 0.63 on x-axis, changed color to green)
glBegin(GL_QUADS);
glColor3f(0.01f, 0.90f, 0.98f); // Green color for building
glVertex2f(-0.11f, 0.65f); // Shifted by 0.63 on x-axis
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.80f, 0.88f); // Darker green for the side
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glVertex2f(0.01f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(-0.11f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.11f, 0.65f);
glVertex2f(0.01f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.01f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.01f, 0.65f);
glVertex2f(0.04f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.04f, 0.62f);
glVertex2f(0.04f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.08f, 0.47f);
glVertex2f(-0.05f, 0.47f);
glVertex2f(-0.05f, 0.53f);
glVertex2f(-0.08f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(0.00f, 0.47f);
glVertex2f(-0.03f, 0.47f);
glVertex2f(-0.03f, 0.53f);
glVertex2f(0.00f, 0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.08f, 0.55f);
glVertex2f(-0.05f, 0.55f);
glVertex2f(-0.05f, 0.61f);
glVertex2f(-0.08f, 0.61f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(0.00f, 0.55f);
glVertex2f(-0.03f, 0.55f);
glVertex2f(-0.03f, 0.61f);
glVertex2f(0.00f, 0.61f);
glEnd();

/// Updated Building Code behind 9

// Building structure (shifted 0.5 on x-axis, changed color to blue)
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // Blue color for building
glVertex2f(-0.24f, 0.60f); // Shifted by 0.5 on x-axis
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.8f); // Darker color for the side
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glVertex2f(-0.12f, 0.2f);
glEnd();

// Building edges
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.24f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f, 0.60f);
glVertex2f(-0.12f, 0.60f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.12f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.12f, 0.60f);
glVertex2f(-0.09f, 0.57f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.09f, 0.57f);
glVertex2f(-0.09f, 0.2f);
glEnd();

// Windows (no changes to coordinates or colors)
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.21f, 0.42f);
glVertex2f(-0.18f, 0.42f);
glVertex2f(-0.18f, 0.48f);
glVertex2f(-0.21f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.13f, 0.42f);
glVertex2f(-0.16f, 0.42f);
glVertex2f(-0.16f, 0.48f);
glVertex2f(-0.13f, 0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.21f, 0.50f);
glVertex2f(-0.18f, 0.50f);
glVertex2f(-0.18f, 0.56f);
glVertex2f(-0.21f, 0.56f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.13f, 0.50f);
glVertex2f(-0.16f, 0.50f);
glVertex2f(-0.16f, 0.56f);
glVertex2f(-0.13f, 0.56f);
glEnd();






///building behind 8 moved by 0.07 on x-axis and 0.2 on y-axis with cyan-red mixed color
glBegin(GL_QUADS);
glColor3f(0.2f, 0.8f, 0.7f); // Cyan-red mixed
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glVertex2f(-0.45f, 0.2f);
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.7f, 0.6f); // Cyan-red mixed (darker shade)
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glVertex2f(-0.42f, 0.2f);
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.57f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.57f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.65f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.45f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.45f, 0.65f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.42f, 0.62f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.42f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.07 and y-axis shift by 0.2)


glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.545f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.515f, 0.56f);
glVertex2f(-0.515f, 0.62f);
glVertex2f(-0.545f, 0.62f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.47f, 0.56f); // +0.07 to x-coordinates, +0.2 to y-coordinates
glVertex2f(-0.50f, 0.56f);
glVertex2f(-0.50f, 0.62f);
glVertex2f(-0.47f, 0.62f);
glEnd();


///building behind 7 moved down by 0.2 on y-axis and shifted by 0.1 on x-axis with red-yellow mixed color
    glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.61f, 0.553f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "SCHOOL");
glBegin(GL_QUADS);
glColor3f(0.9f, 0.5f, 0.2f); // Red-yellow mixed
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glVertex2f(-0.49f, 0.2f);
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8f, 0.4f, 0.1f); // Red-yellow mixed (lighter shade)
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glVertex2f(-0.46f, 0.2f);
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.61f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.61f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.55f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.49f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.49f, 0.55f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.52f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.46f, 0.52f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.46f, 0.2f);
glEnd();

///windows (no color change, only x-axis shift by 0.1 and y-axis shift by -0.2)
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.585f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.44f);
glVertex2f(-0.555f, 0.50f);
glVertex2f(-0.585f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.51f, 0.44f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.44f);
glVertex2f(-0.54f, 0.50f);
glVertex2f(-0.51f, 0.50f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.585f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.555f, 0.36f);
glVertex2f(-0.555f, 0.42f);
glVertex2f(-0.585f, 0.42f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.51f, 0.36f); // +0.1 to x-coordinates, -0.2 to y-coordinates
glVertex2f(-0.54f, 0.36f);
glVertex2f(-0.54f, 0.42f);
glVertex2f(-0.51f, 0.42f);
glEnd();




///building behind 6 with updated position and blue-yellow mixed color
    glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.34f, 0.533f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "OFFICE");
glBegin(GL_QUADS);
glColor3f(0.2f, 0.5f, 0.0f); // Blue-yellow mixed (dominantly blue)
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glVertex2f(-0.23f, 0.2f);
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.4f, 0.1f); // Blue-yellow mixed (lighter shade)
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glVertex2f(-0.20f, 0.2f);
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.35f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.35f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.23f, 0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.23f, 0.53f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.50f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f); // Lines remain black
glVertex2f(-0.20f, 0.50f); // +0.07 to x-coordinates
glVertex2f(-0.20f, 0.2f);
glEnd();

///windows remain the same color and are shifted by +0.07 x-axis
glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.33f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.35f);
glVertex2f(-0.30f, 0.41f);
glVertex2f(-0.33f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.25f, 0.35f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.35f);
glVertex2f(-0.28f, 0.41f);
glVertex2f(-0.25f, 0.41f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.33f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.30f, 0.43f);
glVertex2f(-0.30f, 0.49f);
glVertex2f(-0.33f, 0.49f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
glVertex2f(-0.25f, 0.43f); // +0.07 to x-coordinates
glVertex2f(-0.28f, 0.43f);
glVertex2f(-0.28f, 0.49f);
glVertex2f(-0.25f, 0.49f);
glEnd();

   ///building behind 2
       glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.88f, 0.603f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "POLICE");
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(-0.89f,0.60f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.77f,0.2f);
    glVertex2f(-0.89f,0.2f);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(0.5f,0.5f,0.5f);
    glVertex2f(-0.77f,0.60f);
    glVertex2f(-0.74f,0.57f);
    glVertex2f(-0.74f,0.2f);
    glVertex2f(-0.77f,0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.89f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, 0.60f);
    glVertex2f(-0.77f, 0.60f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.77f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.77f, 0.60f);
    glVertex2f(-0.74f, 0.57f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.74f, 0.57f);
    glVertex2f(-0.74f, 0.2f);
    glEnd();
    ///window

      glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.86f, 0.42f);
    glVertex2f(-0.83f, 0.42f);
    glVertex2f(-0.83f, 0.48f);
    glVertex2f(-0.86f, 0.48f);
    glEnd();

          glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.78f, 0.42f);
    glVertex2f(-0.81f, 0.42f);
    glVertex2f(-0.81f, 0.48f);
    glVertex2f(-0.78f, 0.48f);
    glEnd();

     glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.86f, 0.50f);
    glVertex2f(-0.83f, 0.50f);
    glVertex2f(-0.83f, 0.56f);
    glVertex2f(-0.86f, 0.56f);
    glEnd();

          glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.78f, 0.50f);
    glVertex2f(-0.81f, 0.50f);
    glVertex2f(-0.81f, 0.56f);
    glVertex2f(-0.78f, 0.56f);
    glEnd();






///building
     glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.90f, 0.53f);
    glEnd();
       glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, 0.53f);
    glVertex2f(-0.99f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.90f, 0.53f);
    glVertex2f(-0.87f, 0.50f);

    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.87f, 0.50f);
    glVertex2f(-0.87f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.98f, 0.31f);
    glVertex2f(-0.95f, 0.31f);
    glVertex2f(-0.95f, 0.35f);
    glVertex2f(-0.98f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.94f, 0.31f);
    glVertex2f(-0.91f, 0.31f);
    glVertex2f(-0.91f, 0.35f);
    glVertex2f(-0.94f, 0.35f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.98f, 0.37f);
    glVertex2f(-0.95f, 0.37f);
    glVertex2f(-0.95f, 0.41f);
    glVertex2f(-0.98f, 0.41f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.94f, 0.37f);
    glVertex2f(-0.91f, 0.37f);
    glVertex2f(-0.91f, 0.41f);
    glVertex2f(-0.94f, 0.41f);
    glEnd();

    ///p3

       glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.98f, 0.43f);
    glVertex2f(-0.95f, 0.43f);
    glVertex2f(-0.95f, 0.47f);
    glVertex2f(-0.98f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.94f, 0.43f);
    glVertex2f(-0.91f, 0.43f);
    glVertex2f(-0.91f, 0.47f);
    glVertex2f(-0.94f, 0.47f);
    glEnd();



    ///1 building

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glVertex2f(-1.0f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();
///window

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.99f, 0.26f);
    glVertex2f(-0.96f, 0.26f);
    glVertex2f(-0.96f, 0.22f);
    glVertex2f(-0.99f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.95f, 0.26f);
    glVertex2f(-0.92f, 0.26f);
    glVertex2f(-0.92f, 0.22f);
    glVertex2f(-0.95f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-1.0f, 0.30f);
    glVertex2f(-0.90f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.90f, 0.2f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.90f, 0.30f);
    glVertex2f(-0.88f, 0.29f);
    glEnd();

        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.88f, 0.29f);
    glVertex2f(-0.88f, 0.2f);
    glEnd();




    ///2 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.86f, 0.41f);
    glVertex2f(-0.86f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.2f);
    glVertex2f(-0.76f, 0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.76f, 0.41f);
    glVertex2f(-0.73f, 0.38f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.73f, 0.38f);
    glVertex2f(-0.73f, 0.2f);
    glEnd();




    ///windows
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.84f, 0.22f);
    glVertex2f(-0.81f, 0.22f);
    glVertex2f(-0.81f, 0.26f);
    glVertex2f(-0.84f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.8f, 0.22f);
    glVertex2f(-0.77f, 0.22f);
    glVertex2f(-0.77f, 0.26f);
    glVertex2f(-0.8f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.84f, 0.28f);
    glVertex2f(-0.81f, 0.28f);
    glVertex2f(-0.81f, 0.32f);
    glVertex2f(-0.84f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.8f, 0.28f);
    glVertex2f(-0.77f, 0.28f);
    glVertex2f(-0.77f, 0.32f);
    glVertex2f(-0.8f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.84f, 0.34f);
    glVertex2f(-0.81f, 0.34f);
    glVertex2f(-0.81f, 0.38f);
    glVertex2f(-0.84f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.8f, 0.34f);
    glVertex2f(-0.77f, 0.34f);
    glVertex2f(-0.77f, 0.38f);
    glVertex2f(-0.8f, 0.38f);
    glEnd();

    ///3 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.72f, 0.53f);
    glVertex2f(-0.62f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.62f, 0.53f);
    glVertex2f(-0.59f, 0.50f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.59f, 0.50f);
    glVertex2f(-0.59f, 0.2f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.70f, 0.22f);
    glVertex2f(-0.67f, 0.22f);
    glVertex2f(-0.67f, 0.26f);
    glVertex2f(-0.70f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.66f, 0.22f);
    glVertex2f(-0.63f, 0.22f);
    glVertex2f(-0.63f, 0.26f);
    glVertex2f(-0.66f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.7f, 0.28f);
    glVertex2f(-0.67f, 0.28f);
    glVertex2f(-0.67f, 0.32f);
    glVertex2f(-0.7f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.66f, 0.28f);
    glVertex2f(-0.63f, 0.28f);
    glVertex2f(-0.63f, 0.32f);
    glVertex2f(-0.66f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.7f, 0.34f);
    glVertex2f(-0.67f, 0.34f);
    glVertex2f(-0.67f, 0.38f);
    glVertex2f(-0.7f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.66f, 0.34f);
    glVertex2f(-0.63f, 0.34f);
    glVertex2f(-0.63f, 0.38f);
    glVertex2f(-0.66f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.67f, 0.40f);
    glVertex2f(-0.67f, 0.44f);
    glVertex2f(-0.7f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.66f, 0.40f);
    glVertex2f(-0.63f, 0.40f);
    glVertex2f(-0.63f, 0.44f);
    glVertex2f(-0.66f, 0.44f);
    glEnd();

     glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.7f, 0.46f);
    glVertex2f(-0.67f, 0.46f);
    glVertex2f(-0.67f, 0.50f);
    glVertex2f(-0.7f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.66f, 0.46f);
    glVertex2f(-0.63f, 0.46f);
    glVertex2f(-0.63f, 0.50f);
    glVertex2f(-0.66f, 0.50f);
    glEnd();

    ///4 building 4

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.58f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.58f, 0.36f);
    glVertex2f(-0.48f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.48f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.48f, 0.36f);
    glVertex2f(-0.46f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.46f, 0.34f);
    glVertex2f(-0.46f, 0.2f);
    glEnd();


    ///windows
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.56f, 0.22f);
    glVertex2f(-0.53f, 0.22f);
    glVertex2f(-0.53f, 0.26f);
    glVertex2f(-0.56f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.52f, 0.22f);
    glVertex2f(-0.49f, 0.22f);
    glVertex2f(-0.49f, 0.26f);
    glVertex2f(-0.52f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.52f, 0.28f);
    glVertex2f(-0.49f, 0.28f);
    glVertex2f(-0.49f, 0.32f);
    glVertex2f(-0.52f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.53f, 0.28f);
    glVertex2f(-0.53f, 0.32f);
    glVertex2f(-0.56f, 0.32f);
    glEnd();

    ///5 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.45f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.45f, 0.47f);
    glVertex2f(-0.35f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.35f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.35f, 0.47f);
    glVertex2f(-0.33f, 0.44f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.33f, 0.44f);
    glVertex2f(-0.33f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.43f, 0.22f);
    glVertex2f(-0.4f, 0.22f);
    glVertex2f(-0.4f, 0.26f);
    glVertex2f(-0.43f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.39f, 0.22f);
    glVertex2f(-0.36f, 0.22f);
    glVertex2f(-0.36f, 0.26f);
    glVertex2f(-0.39f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.43f, 0.28f);
    glVertex2f(-0.4f, 0.28f);
    glVertex2f(-0.4f, 0.32f);
    glVertex2f(-0.43f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.39f, 0.28f);
    glVertex2f(-0.36f, 0.28f);
    glVertex2f(-0.36f, 0.32f);
    glVertex2f(-0.39f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.43f, 0.34f);
    glVertex2f(-0.4f, 0.34f);
    glVertex2f(-0.4f, 0.38f);
    glVertex2f(-0.43f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.39f, 0.34f);
    glVertex2f(-0.36f, 0.34f);
    glVertex2f(-0.36f, 0.38f);
    glVertex2f(-0.39f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.43f, 0.40f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(-0.4f, 0.44f);
    glVertex2f(-0.43f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.39f, 0.40f);
    glVertex2f(-0.36f, 0.40f);
    glVertex2f(-0.36f, 0.44f);
    glVertex2f(-0.39f, 0.44f);
    glEnd();

    ///6 building

        glColor3f(0.0,0.0,0.0);
renderBitmapString(-0.29f, 0.362f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "FOOD");
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.3f, 0.36f);
    glVertex2f(-0.2f, 0.36f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.2f, 0.36f);
    glVertex2f(-0.18f, 0.34f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.18f, 0.34f);
    glVertex2f(-0.18f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.28f, 0.22f);
    glVertex2f(-0.25f, 0.22f);
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.28f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.24f, 0.22f);
    glVertex2f(-0.21f, 0.22f);
    glVertex2f(-0.21f, 0.26f);
    glVertex2f(-0.24f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.28f, 0.28f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(-0.25f, 0.32f);
    glVertex2f(-0.28f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.24f, 0.28f);
    glVertex2f(-0.21f, 0.28f);
    glVertex2f(-0.21f, 0.32f);
    glVertex2f(-0.24f, 0.32f);
    glEnd();


    ///7 building
    glBegin(GL_QUADS);
    glColor3f(0.37f, 0.50f, 0.96f);
    glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.50f, 0.86f);
    glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.17f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.17f, 0.42f);
    glVertex2f(-0.08f, 0.42f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.08f, 0.42f);
    glVertex2f(-0.06f, 0.40f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.06f, 0.40f);
    glVertex2f(-0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.16f, 0.22f);
    glVertex2f(-0.13f, 0.22f);
    glVertex2f(-0.13f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.09f, 0.22f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.12f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.16f, 0.28f);
    glVertex2f(-0.13f, 0.28f);
    glVertex2f(-0.13f, 0.32f);
    glVertex2f(-0.16f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.12f, 0.28f);
    glVertex2f(-0.09f, 0.28f);
    glVertex2f(-0.09f, 0.32f);
    glVertex2f(-0.12f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.16f, 0.34f);
    glVertex2f(-0.13f, 0.34f);
    glVertex2f(-0.13f, 0.38f);
    glVertex2f(-0.16f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.12f, 0.34f);
    glVertex2f(-0.09f, 0.34f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.12f, 0.38f);
    glEnd();

    ///8 building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glVertex2f(0.04f, 0.2f);
    glEnd();
     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(-0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.04f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-0.04f, 0.47f);
    glVertex2f(0.04f, 0.47f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.04f, 0.47f);
    glVertex2f(0.06f, 0.45f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.06f, 0.45f);
    glVertex2f(0.06f, 0.2f);
    glEnd();


    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.03f, 0.22f);
    glVertex2f(-0.01f, 0.22f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.03f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.01f, 0.22f);
    glVertex2f(0.03f, 0.22f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.01f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.03f, 0.28f);
    glVertex2f(-0.01f, 0.28f);
    glVertex2f(-0.01f, 0.32f);
    glVertex2f(-0.03f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.01f, 0.28f);
    glVertex2f(0.03f, 0.28f);
    glVertex2f(0.03f, 0.32f);
    glVertex2f(0.01f, 0.32f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.03f, 0.34f);
    glVertex2f(-0.01f, 0.34f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(-0.03f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.01f, 0.34f);
    glVertex2f(0.03f, 0.34f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.01f, 0.38f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(-0.03f, 0.40f);
    glVertex2f(-0.01f, 0.40f);
    glVertex2f(-0.01f, 0.44f);
    glVertex2f(-0.03f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.01f, 0.40f);
    glVertex2f(0.03f, 0.40f);
    glVertex2f(0.03f, 0.44f);
    glVertex2f(0.01f, 0.44f);
    glEnd();

    ///9 building
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.08f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.08f, 0.53f);
    glVertex2f(0.18f, 0.53f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.18f, 0.2f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.18f, 0.53f);
    glVertex2f(0.20f, 0.51f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(0.20f, 0.51f);
    glVertex2f(0.20f, 0.2f);
    glEnd();




    ///windows
    ///p1
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.09f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.26f);
    glVertex2f(0.09f, 0.26f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.13f, 0.22f);
    glVertex2f(0.16f, 0.22f);
    glVertex2f(0.16f, 0.26f);
    glVertex2f(0.13f, 0.26f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.09f, 0.28f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.12f, 0.32f);
    glVertex2f(0.09f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.13f, 0.28f);
    glVertex2f(0.16f, 0.28f);
    glVertex2f(0.16f, 0.32f);
    glVertex2f(0.13f, 0.32f);
    glEnd();

      glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.09f, 0.34f);
    glVertex2f(0.12f, 0.34f);
    glVertex2f(0.12f, 0.38f);
    glVertex2f(0.09f, 0.38f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.13f, 0.34f);
    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.16f, 0.38f);
    glVertex2f(0.13f, 0.38f);
    glEnd();

      glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.09f, 0.40f);
    glVertex2f(0.12f, 0.40f);
    glVertex2f(0.12f, 0.44f);
    glVertex2f(0.09f, 0.44f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.13f, 0.40f);
    glVertex2f(0.16f, 0.40f);
    glVertex2f(0.16f, 0.44f);
    glVertex2f(0.13f, 0.44f);
    glEnd();

      glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.12f, 0.46f);
    glVertex2f(0.12f, 0.50f);
    glVertex2f(0.09f, 0.50f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.94f, 0.89f, 0.77f);
    glVertex2f(0.13f, 0.46f);
    glVertex2f(0.16f, 0.46f);
    glVertex2f(0.16f, 0.50f);
    glVertex2f(0.13f, 0.50f);
    glEnd();
}

void tree2(){
///tree

   ///leaf

 glColor3f(0.0f, 0.5f, 0.0f); // White color for cloud

    /// Base circles
    Circle(0.98f, 0.53f, 0.08f); // First circle
    Circle(0.88f, 0.51f, 0.10f); // Second circle
    Circle(0.78f, 0.53f, 0.08f); // Third circle

    /// Top circles
    Circle(0.94f, 0.65f, 0.08f); // Fourth circle
    Circle(0.83f, 0.65f, 0.08f);  // Fifth circle
    Circle(0.88f, 0.75f, 0.08f);


glColor3f(0.545f, 0.271f, 0.075f); // Brown color for the trunk

// Polygon 1
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.83f, 0.64f);
glVertex2f(0.8f, 0.64f);
glEnd();

// Polygon 2
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.93f, 0.68f);
glVertex2f(0.925f, 0.63f);
glEnd();

// Polygon 3
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.905f, 0.3f);
glVertex2f(0.905f, 0.575f);

glVertex2f(0.86f, 0.575f);
glVertex2f(0.86f, 0.3f);
glVertex2f(0.882f,0.2f);
glEnd();

// Polygon 4
glBegin(GL_POLYGON);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.95f, 0.25f);
glVertex2f(0.82f, 0.25f);
glVertex2f(0.86f, 0.30f);
glVertex2f(0.905f, 0.30f);
glEnd();

// triangle 1
glBegin(GL_TRIANGLES);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.575f);
glVertex2f(0.882f, 0.6f);
glVertex2f(0.905f, 0.575f);
glEnd();

// triangle 2
glBegin(GL_TRIANGLES);
glColor3f(0.545f, 0.271f, 0.075f);
glVertex2f(0.86f, 0.445f);
glVertex2f(0.84f, 0.420f);
glVertex2f(0.86f, 0.470f);
glEnd();
}

void lamppost2(){
///lamp post 1

   glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.22f);
    glVertex2f(0.285f, 0.22f);
    glVertex2f(0.285f, 0.20f);
    glVertex2f(0.26f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.269f, 0.21f);
    glVertex2f(0.277f, 0.21f);
    glVertex2f(0.277f, 0.28f);
    glVertex2f(0.269f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.271f, 0.37f);
    glVertex2f(0.275f, 0.37f);
    glVertex2f(0.275f, 0.28f);
    glVertex2f(0.271f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.26f, 0.37f);
    glVertex2f(0.285f, 0.37f);
    glVertex2f(0.285f, 0.377f);
    glVertex2f(0.26f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.377f);
    glVertex2f(0.28f, 0.377f);
    glVertex2f(0.28f, 0.385f);
    glVertex2f(0.265f, 0.385f);
    glEnd();
        ///light color
       glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.283f, 0.41f);
    glVertex2f(0.262f, 0.41f);
    glVertex2f(0.265f, 0.385f);
    glVertex2f(0.28f, 0.385f);
    glEnd();

///lines


        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.265f, 0.385f);
   glVertex2f(0.262f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.28f, 0.385f);
   glVertex2f(0.283f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.272f, 0.385f);
   glVertex2f(0.272f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.255f, 0.41f);
   glVertex2f(0.289f,0.41f);
   glVertex2f(0.272f,0.43f);
    glEnd();



///lamp post 2


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.22f);
    glVertex2f(0.835f, 0.22f);
    glVertex2f(0.835f, 0.20f);
    glVertex2f(0.81f, 0.20f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.819f, 0.21f);
    glVertex2f(0.827f, 0.21f);
    glVertex2f(0.827f, 0.28f);
    glVertex2f(0.819f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.821f, 0.37f);
    glVertex2f(0.825f, 0.37f);
    glVertex2f(0.825f, 0.28f);
    glVertex2f(0.821f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.81f, 0.37f);
    glVertex2f(0.835f, 0.37f);
    glVertex2f(0.835f, 0.377f);
    glVertex2f(0.81f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.377f);
    glVertex2f(0.83f, 0.377f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();

        ///light color
       glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.812f, 0.41f);
    glVertex2f(0.833f, 0.41f);
    glVertex2f(0.83f, 0.385f);
    glVertex2f(0.815f, 0.385f);
    glEnd();

///lines

        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.815f, 0.385f);
   glVertex2f(0.812f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.83f, 0.385f);
   glVertex2f(0.833f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.822f, 0.385f);
   glVertex2f(0.822f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.805f, 0.41f);
   glVertex2f(0.839f,0.41f);
   glVertex2f(0.822f,0.43f);
    glEnd();


    ///double lamp post

    ///left

       glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.535f, 0.22f);
    glVertex2f(0.560f, 0.22f);
    glVertex2f(0.560f, 0.20f);
    glVertex2f(0.535f, 0.20f);
    glEnd();


      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.544f, 0.21f);
    glVertex2f(0.552f, 0.21f);
    glVertex2f(0.552f, 0.28f);
    glVertex2f(0.544f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.546f, 0.37f);
    glVertex2f(0.55f, 0.37f);
    glVertex2f(0.55f, 0.28f);
    glVertex2f(0.546f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.515f, 0.37f);
    glVertex2f(0.580f, 0.37f);
    glVertex2f(0.580f, 0.377f);
    glVertex2f(0.515f, 0.377f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.377f);
    glVertex2f(0.535f, 0.377f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();
    ///light color
       glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.517f, 0.41f);
    glVertex2f(0.538f, 0.41f);
    glVertex2f(0.535f, 0.385f);
    glVertex2f(0.52f, 0.385f);
    glEnd();

///lines
        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.52f, 0.385f);
   glVertex2f(0.517f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.535f, 0.385f);
   glVertex2f(0.538f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.527f, 0.385f);
   glVertex2f(0.527f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.509f, 0.41f);
   glVertex2f(0.544f,0.41f);
   glVertex2f(0.527f,0.43f);
    glEnd();

    ///right

     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.377f);
    glVertex2f(0.560f, 0.377f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();

    ///light color
       glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.578f, 0.41f);
    glVertex2f(0.557f, 0.41f);
    glVertex2f(0.560f, 0.385f);
    glVertex2f(0.575f, 0.385f);
    glEnd();

///lines
        glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.560f, 0.385f);
   glVertex2f(0.557f,0.41f);
    glEnd();

           glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.575f, 0.385f);
   glVertex2f(0.578f,0.41f);
    glEnd();

               glBegin(GL_LINES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.567f, 0.385f);
   glVertex2f(0.567f,0.41f);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.46f, 0.52f);

    glVertex2f(0.549f, 0.41f);
   glVertex2f(0.585f,0.41f);
   glVertex2f(0.567f,0.43f);
    glEnd();
}

void roadlamppost2(){
///lamp(road)
///lamp 1 left

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.80f, -0.1f); // Bottom-left
    glVertex2f(-0.808f, -0.1f); // Top-left
    glVertex2f(-0.808f, 0.3f); // Top-right
    glVertex2f(-0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.808f, 0.27f); // Bottom-left
    glVertex2f(-0.88f, 0.27f); // Top-left
    glVertex2f(-0.88f, 0.285f); // Top-right
    glVertex2f(-0.808f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.85f, 0.27f); // Bottom-left
    glVertex2f(-0.875f, 0.27f); // Bottom-right
    glVertex2f(-0.875f, 0.255f); // Top-right
    glVertex2f(-0.85f, 0.255f); // Top-left
    glEnd();


      ///lamp 2

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f, -0.1f); // Bottom-left
    glVertex2f(-0.608f, -0.1f); // Top-left
    glVertex2f(-0.608f, 0.3f); // Top-right
    glVertex2f(-0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.608f, 0.27f); // Bottom-left
    glVertex2f(-0.68f, 0.27f); // Top-left
    glVertex2f(-0.68f, 0.285f); // Top-right
    glVertex2f(-0.608f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.65f, 0.27f); // Bottom-left
    glVertex2f(-0.675f, 0.27f); // Bottom-right
    glVertex2f(-0.675f, 0.255f); // Top-right
    glVertex2f(-0.65f, 0.255f); // Top-left
    glEnd();


      ///lamp 3

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.1f); // Bottom-left
    glVertex2f(-0.408f, -0.1f); // Top-left
    glVertex2f(-0.408f, 0.3f); // Top-right
    glVertex2f(-0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.408f, 0.27f); // Bottom-left
    glVertex2f(-0.48f, 0.27f); // Top-left
    glVertex2f(-0.48f, 0.285f); // Top-right
    glVertex2f(-0.408f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, 0.27f); // Bottom-left
    glVertex2f(-0.475f, 0.27f); // Bottom-right
    glVertex2f(-0.475f, 0.255f); // Top-right
    glVertex2f(-0.45f, 0.255f); // Top-left
    glEnd();

    ///lamp 4

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.1f); // Bottom-left
    glVertex2f(-0.208f, -0.1f); // Top-left
    glVertex2f(-0.208f, 0.3f); // Top-right
    glVertex2f(-0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.208f, 0.27f); // Bottom-left
    glVertex2f(-0.28f, 0.27f); // Top-left
    glVertex2f(-0.28f, 0.285f); // Top-right
    glVertex2f(-0.208f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, 0.27f); // Bottom-left
    glVertex2f(-0.275f, 0.27f); // Bottom-right
    glVertex2f(-0.275f, 0.255f); // Top-right
    glVertex2f(-0.25f, 0.255f); // Top-left
    glEnd();

    ///lamp 5

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.00f, -0.1f); // Bottom-left
    glVertex2f(-0.008f, -0.1f); // Top-left
    glVertex2f(-0.008f, 0.3f); // Top-right
    glVertex2f(-0.00f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.008f, 0.27f); // Bottom-left
    glVertex2f(-0.08f, 0.27f); // Top-left
    glVertex2f(-0.08f, 0.285f); // Top-right
    glVertex2f(-0.008f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.27f); // Bottom-left
    glVertex2f(-0.075f, 0.27f); // Bottom-right
    glVertex2f(-0.075f, 0.255f); // Top-right
    glVertex2f(-0.05f, 0.255f); // Top-left
    glEnd();

        ///lamp 6

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, -0.1f); // Bottom-left
    glVertex2f(0.208f, -0.1f); // Top-left
    glVertex2f(0.208f, 0.3f); // Top-right
    glVertex2f(0.20f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.20f, 0.27f); // Bottom-left
    glVertex2f(0.112f, 0.27f); // Top-left
    glVertex2f(0.112f, 0.285f); // Top-right
    glVertex2f(0.20f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.142f, 0.27f); // Bottom-left
    glVertex2f(0.117f, 0.27f); // Bottom-right
    glVertex2f(0.117f, 0.255f); // Top-right
    glVertex2f(0.142f, 0.255f); // Top-left
    glEnd();

          ///lamp 7

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, -0.1f); // Bottom-left
    glVertex2f(0.408f, -0.1f); // Top-left
    glVertex2f(0.408f, 0.3f); // Top-right
    glVertex2f(0.40f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.40f, 0.27f); // Bottom-left
    glVertex2f(0.312f, 0.27f); // Top-left
    glVertex2f(0.312f, 0.285f); // Top-right
    glVertex2f(0.40f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.342f, 0.27f); // Bottom-left
    glVertex2f(0.317f, 0.27f); // Bottom-right
    glVertex2f(0.317f, 0.255f); // Top-right
    glVertex2f(0.342f, 0.255f); // Top-left
    glEnd();

      ///lamp 8

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, -0.1f); // Bottom-left
    glVertex2f(0.608f, -0.1f); // Top-left
    glVertex2f(0.608f, 0.3f); // Top-right
    glVertex2f(0.60f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.60f, 0.27f); // Bottom-left
    glVertex2f(0.512f, 0.27f); // Top-left
    glVertex2f(0.512f, 0.285f); // Top-right
    glVertex2f(0.60f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.542f, 0.27f); // Bottom-left
    glVertex2f(0.517f, 0.27f); // Bottom-right
    glVertex2f(0.517f, 0.255f); // Top-right
    glVertex2f(0.542f, 0.255f); // Top-left
    glEnd();

       ///lamp 9

    /// Light pole
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, -0.1f); // Bottom-left
    glVertex2f(0.808f, -0.1f); // Top-left
    glVertex2f(0.808f, 0.3f); // Top-right
    glVertex2f(0.80f, 0.3f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, 0.27f); // Bottom-left
    glVertex2f(0.712f, 0.27f); // Top-left
    glVertex2f(0.712f, 0.285f); // Top-right
    glVertex2f(0.80f, 0.285f); // Bottom-right
    glEnd();


    /// Light
    glColor3f(1.0f, 1.0f, 1.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.742f, 0.27f); // Bottom-left
    glVertex2f(0.717f, 0.27f); // Bottom-right
    glVertex2f(0.717f, 0.255f); // Top-right
    glVertex2f(0.742f, 0.255f); // Top-left
    glEnd();


      ///traffic light

    /// Light pole
    glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.08f, -0.1f); // Bottom-left
    glVertex2f(0.07f, -0.1f); // Top-left
    glVertex2f(0.07f, 0.25f); // Top-right
    glVertex2f(0.08f, 0.25f); // Bottom-right
    glEnd();

        /// Light pole
glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.07f, 0.22f); // Bottom-left
    glVertex2f(-0.04f, 0.22f); // Top-left
    glVertex2f(-0.04f, 0.235f); // Top-right
    glVertex2f(0.07f, 0.235f); // Bottom-right
    glEnd();


    /// Light red
    glColor3f(1.0f, 0.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.033f, 0.22f); // Bottom-left
    glVertex2f(-0.013f, 0.22f); // Bottom-right
    glVertex2f(-0.013f, 0.195f); // Top-right
    glVertex2f(-0.033f, 0.195f); // Top-left
    glEnd();


    /// Light green
    glColor3f(0.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.003f, 0.22f); // Bottom-left
    glVertex2f(0.017f, 0.22f); // Bottom-right
    glVertex2f(0.017f, 0.195f); // Top-right
    glVertex2f(-0.003f, 0.195f); // Top-left
    glEnd();

    /// Light yellow
    glColor3f(1.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.027f, 0.22f); // Bottom-left
    glVertex2f(0.047f, 0.22f); // Bottom-right
    glVertex2f(0.047f, 0.195f); // Top-right
    glVertex2f(0.027f, 0.195f); // Top-left
    glEnd();
}

void day_view() {    /// day_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    sky2();
    sun1();
    cloud2();
    greenquad();
    building2();
    tree2();
    bench();
    lamppost2();
    boarde();
    upfootpath();
    human2();
    human1();
    roadlamppost2();
    trafficlight();
    road();
    zebracrossing();
    downfootpath();
downblackboarder();
   human4();
   ambulance();
   policecar();

   human3();

    glFlush();
}
void sound2()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("ambulance siren .wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}
void trafficlight1(){
///traffic light red change
    /// Light pole
    glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.08f, -0.1f); // Bottom-left
    glVertex2f(0.07f, -0.1f); // Top-left
    glVertex2f(0.07f, 0.25f); // Top-right
    glVertex2f(0.08f, 0.25f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.07f, 0.22f); // Bottom-left
    glVertex2f(-0.04f, 0.22f); // Top-left
    glVertex2f(-0.04f, 0.235f); // Top-right
    glVertex2f(0.07f, 0.235f); // Bottom-right
    glEnd();

    /// Light red
    glColor3f(1.0f, 0.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.033f, 0.22f); // Bottom-left
    glVertex2f(-0.013f, 0.22f); // Bottom-right
    glVertex2f(-0.013f, 0.195f); // Top-right
    glVertex2f(-0.033f, 0.195f); // Top-left
    glEnd();

    /// Light green
    glColor3f(0.0f, 0.55f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.003f, 0.22f); // Bottom-left
    glVertex2f(0.017f, 0.22f); // Bottom-right
    glVertex2f(0.017f, 0.195f); // Top-right
    glVertex2f(-0.003f, 0.195f); // Top-left
    glEnd();

    /// Light yellow
    glColor3f(0.72f, 0.70f, 0.32f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.027f, 0.22f); // Bottom-left
    glVertex2f(0.047f, 0.22f); // Bottom-right
    glVertex2f(0.047f, 0.195f); // Top-right
    glVertex2f(0.027f, 0.195f); // Top-left
    glEnd();
}
void day_view1() {    /// day_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    sky2();
    sun1();
    cloud2();
    greenquad();
    building2();
    tree2();
    bench();
    lamppost2();
    boarde();
    upfootpath();
    human2();
    human1();
    roadlamppost2();
    trafficlight1();
    road();
    zebracrossing();
    downfootpath();
downblackboarder();
   human4();
   ambulance();
   policecar();

   human3();

    glFlush();
}
void trafficlight2(){
///traffic light green change
    /// Light pole
    glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.08f, -0.1f); // Bottom-left
    glVertex2f(0.07f, -0.1f); // Top-left
    glVertex2f(0.07f, 0.25f); // Top-right
    glVertex2f(0.08f, 0.25f); // Bottom-right
    glEnd();

        /// Light pole
    glColor3f(0.45f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.07f, 0.22f); // Bottom-left
    glVertex2f(-0.04f, 0.22f); // Top-left
    glVertex2f(-0.04f, 0.235f); // Top-right
    glVertex2f(0.07f, 0.235f); // Bottom-right
    glEnd();

    /// Light red
    glColor3f(0.55f, 0.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.033f, 0.22f); // Bottom-left
    glVertex2f(-0.013f, 0.22f); // Bottom-right
    glVertex2f(-0.013f, 0.195f); // Top-right
    glVertex2f(-0.033f, 0.195f); // Top-left
    glEnd();

    /// Light green
    glColor3f(0.0f, 1.0f, 0.0f); // White light
    glBegin(GL_QUADS);
    glVertex2f(-0.003f, 0.22f); // Bottom-left
    glVertex2f(0.017f, 0.22f); // Bottom-right
    glVertex2f(0.017f, 0.195f); // Top-right
    glVertex2f(-0.003f, 0.195f); // Top-left
    glEnd();

    /// Light yellow
    glColor3f(0.72f, 0.70f, 0.32f); // White light
    glBegin(GL_QUADS);
    glVertex2f(0.027f, 0.22f); // Bottom-left
    glVertex2f(0.047f, 0.22f); // Bottom-right
    glVertex2f(0.047f, 0.195f); // Top-right
    glVertex2f(0.027f, 0.195f); // Top-left
    glEnd();
}
void day_view2() {    /// day_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    sky2();
    sun1();
    cloud2();
    greenquad();
    building2();
    tree2();
    bench();
    lamppost2();
    boarde();
    upfootpath();
    human2();
    human1();
    roadlamppost2();
    trafficlight2();
    road();
    zebracrossing();
    downfootpath();
downblackboarder();
   human4();
   ambulance();
   policecar();

   human3();

    glFlush();
}

 void twilight_view1() {    /// twilight_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);
    sky1();
    sun();
    cloud1();
    greenquad();
    building1();
    tree1();
    bench();
    lamppost1();
    boarde();
    upfootpath();
    human2();
    human1();
    roadlamppost1();
    trafficlight1();
    road();
    zebracrossing();
    downfootpath();
downblackboarder();
    human4();
    ambulance();
    policecar();

    human3();


    glFlush();
}
 void twilight_view2() {    /// twilight_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    sky1();
    sun();
    cloud1();
    greenquad();
    building1();
    tree1();
    bench();
    lamppost1();
    boarde();
    upfootpath();
    human2();
    human1();
    roadlamppost1();
    trafficlight2();
    road();
    zebracrossing();
    downfootpath();
downblackboarder();
   human4();
   ambulance();
   policecar();

   human3();

    glFlush();
}
void night_view1() {    /// night_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
sky();
star();
moon();
plane();
cloud();
greenquad();
building();
tree();
bench();
lamppost();
boarde();
upfootpath();
human2();
human1();
roadlamppost();
trafficlight1();
road();
zebracrossing();
downfootpath();
downblackboarder();
human4();
ambulance();
policecar();
human3();
glFlush();
}
void night_view2() {    /// night_view
     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
sky();
star();
moon();
plane();
cloud();
greenquad();
building();
tree();
bench();
lamppost();
boarde();
upfootpath();
human2();
human1();
roadlamppost();
trafficlight2();
road();
zebracrossing();
downfootpath();
downblackboarder();
human4();
ambulance();
policecar();
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
human3();
glFlush();
}




                        ///past view


bool isNight = false;
bool isPaused = false ;
/*
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isPaused = !isPaused; //
       //  button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isPaused5 = !isPaused5;
    }
}
*/

void sound3()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("videoplayback.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawHalfCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 90;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}


float sunY = 0.75; // Initial Y position
float speed7 = 0.00009; // Speed of movement
bool movingUp = true; // Direction of movement

void drawSunorMoon() {
    if (isNight) {
        glColor3f(0.9f, 0.9f, 0.9f); // Moon color (light grey)
        drawCircle(0.6, sunY, 0.10);
    } else {
        glColor3f(1.0f, 0.8f, 0.2f); // Sun color (gold)
        drawCircle(0.6, sunY, 0.10);
        glColor3f(0.98,0.98,0.439); // Sun halo (lighter gold)
        drawCircle(0.6, sunY, 0.08);
    }
}

void updateSunPosition() {
    if (movingUp) {
        sunY += speed7;

        if (sunY >= 1.12) {
            sunY = 0.45; //cycle 2++
        }
    }
        glutPostRedisplay();

}

void drawHouse(float x, float y) {
// Walls of the house
glColor3f(0.4f, 0.35f, 0.25f); // Darker bamboo color
     //glBegin(GL_LINE_STRIP);
    glBegin(GL_POLYGON);

    glVertex2f(x - 0.18, y);       // Bottom left
    glVertex2f(x + 0.18, y);       // Bottom right
    glVertex2f(x + 0.18, y + 0.2); // Top right
    glVertex2f(x - 0.18, y + 0.2); // Top left
    glEnd();

  //shadow
 glColor3f(0.37, 0.34, 0.32);
     //glBegin(GL_LINE_STRIP);
    glBegin(GL_POLYGON);
     glVertex2f(x - 0.18, y);       // Bottom left
    glVertex2f(x + 0.18, y);
     glVertex2f(x+0.22 , y-0.1 );
     glVertex2f(x-0.1 , y-0.1 );
    glEnd();
// Base of the house
glColor3f(0.4f, 0.35f, 0.25f); // Darker bamboo color
    glBegin(GL_POLYGON);
//glBegin(GL_LINE_STRIP);
    glVertex2f(x - 0.2, y);      // Bottom left
    glVertex2f(x + 0.2, y);      // Bottom right
    glVertex2f(x + 0.2, y + 0.02); // Top right
    glVertex2f(x - 0.2, y + 0.02); // Top left
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
     //glBegin(GL_LINE_STRIP);
    glBegin(GL_LINES);
     glVertex2f(x +0.22, y+0.1);
     glVertex2f(x+0.22 , y-0.1 );
     glEnd();

     glColor3f(0.0, 0.0, 0.0);
     //glBegin(GL_LINE_STRIP);
    glBegin(GL_LINES);
      glVertex2f(x - 0.1, y+0.1 );
     glVertex2f(x-0.1 , y-0.1 );
     glEnd();

    // Roof of the house
    glColor3f(0.55, 0.35, 0.2); // Thatched color
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.20, y + 0.2); // Bottom left
    glVertex2f(x + 0.20, y + 0.2); // Bottom right
    glVertex2f(x, y + 0.35);        // Top
    glEnd();

    // Door of the house
    glColor3f(0.3, 0.2, 0.1); // Dark brown color for the door
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.05, y);      // Bottom left
    glVertex2f(x + 0.05, y);      // Bottom right
    glVertex2f(x + 0.05, y + 0.08); // Top right
    glVertex2f(x - 0.05, y + 0.08); // Top left
    glEnd();

    // Window of the house
    glColor3f(0.3, 0.2, 0.1); // Dark brown color for the window
    glBegin(GL_POLYGON);
    glVertex2f(x + 0.07, y + 0.05); // Bottom left
    glVertex2f(x + 0.11, y + 0.05); // Bottom right
    glVertex2f(x + 0.11, y + 0.1);  // Top right
    glVertex2f(x + 0.07, y + 0.1);  // Top left
    glEnd();

  // Walls of the house
  glColor3f(0.0,0.0,0.0); // Dark brown color for the window
    glBegin(GL_LINE_STRIP);

    glVertex2f(x - 0.18, y);       // Bottom left
    glVertex2f(x + 0.18, y);       // Bottom right
    glVertex2f(x + 0.18, y + 0.2); // Top right
    glVertex2f(x - 0.18, y + 0.2); // Top left
    glVertex2f(x - 0.18, y);
   glEnd();

// rombosh

     glColor3f(0.55, 0.35, 0.2);
     //glBegin(GL_LINE_STRIP);
    glBegin(GL_POLYGON);

    glVertex2f(x - 0.18, y+0.2);
    glVertex2f(x + 0.15, y+0.2);
    glVertex2f(x +0.22, y+0.1);
    glVertex2f(x - 0.1, y+0.1 );
    glEnd();


    // Roof of the house
    glColor3f(0.0, 0.0, 0.0); // Thatched color
    glBegin(GL_LINE_STRIP);
    glVertex2f(x - 0.20, y + 0.2); // Bottom left
    glVertex2f(x + 0.20, y + 0.2); // Bottom right
    glVertex2f(x, y + 0.35);        // Top
     glVertex2f(x - 0.20, y + 0.2);
    glEnd();

 // Door of the house
   glColor3f(0.0,0.0,0.0); // Dark brown color for the window
    glBegin(GL_LINE_STRIP);
    glVertex2f(x - 0.05, y);      // Bottom left
    glVertex2f(x + 0.05, y);      // Bottom right
    glVertex2f(x + 0.05, y + 0.08); // Top right
    glVertex2f(x - 0.05, y + 0.08); // Top left
    glEnd();

    // Window of the house
    glColor3f(0.0,0.0,0.0); // Dark brown color for the window
    glBegin(GL_LINE_STRIP);
    glVertex2f(x + 0.07, y + 0.05); // Bottom left
    glVertex2f(x + 0.11, y + 0.05); // Bottom right
    glVertex2f(x + 0.11, y + 0.1);  // Top right
    glVertex2f(x + 0.07, y + 0.1);  // Top left
    glVertex2f(x + 0.07, y + 0.05);
    glEnd();
}


//  houses
void drawHouses() {
    drawHouse(-0.3, 0.1); // l 1
    drawHouse(-0.7, -0.2); //l2
    drawHouse(0.55, 0.1);  // r1

}

// cloud
float cloudX = 0.1f;      // Initial position of the cloud
float cloudXSpeed = 0.0015f; // Speed of cloud movement
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void drawCloud(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glColor3f(1.0, 1.0, 1.0); // White color for clouds
    if (isNight) {
        glColor3f(0.5, 0.5, 0.5); // Grey clouds for night
    }

    float radius = 0.04f;
    drawCircle(0.0f, 0.0f, radius); // Center circle
    drawCircle(0.05f, 0.02f, radius); // Top right circle
    drawCircle(-0.05f, 0.02f, radius); // Top left circle
    drawCircle(0.03f, -0.02f, radius); // Bottom right circle
    drawCircle(-0.03f, -0.02f, radius); // Bottom left circle
    drawCircle(0.02f, 0.05f, radius); // Upper right circle
    drawCircle(-0.02f, 0.05f, radius); // Upper left circle

    glPopMatrix();
}


void animateCloud() {
    cloudX += cloudXSpeed;

    if (cloudX > 1.3f) {
           cloudX=-1.5f;
    }
}

void timerCloud(int value) {
   if (!isPaused) {
    animateCloud();
    }

    glutPostRedisplay();
    glutTimerFunc(16, timerCloud, 0);
}

void drawClouds() {
    drawCloud(cloudX+0.5, 0.85);
    drawCloud(cloudX-0.2, 0.85);
}

float yPosition = -1.0f;
float ySpeed = 0.0002f;

void drawHuman(float x , float y ){
    glPushMatrix();
    glTranslatef(x, y + yPosition, 0); //y axis translate

    ///human body
    glBegin(GL_QUADS);
    glColor3f(0.43f, 0.62f, 0.94f); // Dark green for body
    glVertex2f(0.0f, 0.09f);
    glVertex2f(0.07f, 0.09f);
    glVertex2f(0.07f, 0.14f);
    glVertex2f(0.0f, 0.14f);
    glEnd();

    // Left hand
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
    glVertex2f(0.0f, 0.08f);
    glVertex2f(-0.015f, 0.08f);
    glVertex2f(-0.012f, 0.14f);
    glVertex2f(0.0f, 0.14f);
    glEnd();

    // Left hand sleeve
    glBegin(GL_QUADS);
    glColor3f(0.43f, 0.62f, 0.94f); // Red for sleeve
    glVertex2f(0.0f, 0.11f);
    glVertex2f(-0.015f, 0.11f);
    glVertex2f(-0.012f, 0.14f);
    glVertex2f(0.0f, 0.14f);
    glEnd();

    // Right hand
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
    glVertex2f(0.07f, 0.08f);
    glVertex2f(0.085f, 0.08f);
    glVertex2f(0.082f, 0.14f);
    glVertex2f(0.07f, 0.14f);
    glEnd();

    // Right hand sleeve
    glBegin(GL_QUADS);
    glColor3f(0.43f, 0.62f, 0.94f); // Blue for sleeve
    glVertex2f(0.07f, 0.11f);
    glVertex2f(0.085f, 0.11f);
    glVertex2f(0.082f, 0.14f);
    glVertex2f(0.07f, 0.14f);
    glEnd();

    // Legs
    glBegin(GL_QUADS);
    glColor3f(0.08f, 0.26f, 0.54f); // Navy blue for left leg
    glVertex2f(0.0f, 0.04f);
    glVertex2f(0.02f, 0.04f);
    glVertex2f(0.07f, 0.09f);
    glVertex2f(0.0f, 0.09f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.08f, 0.26f, 0.54f); // Slightly lighter navy blue for right leg
    glVertex2f(0.05f, 0.04f);
    glVertex2f(0.07f, 0.04f);
    glVertex2f(0.07f, 0.09f);
    glVertex2f(0.03f, 0.09f);
    glEnd();

    // Shoes
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
    glVertex2f(0.0f, 0.03f);
    glVertex2f(0.02f, 0.03f);
    glVertex2f(0.02f, 0.04f);
    glVertex2f(0.0f, 0.04f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
    glVertex2f(0.05f, 0.03f);
    glVertex2f(0.07f, 0.03f);
    glVertex2f(0.07f, 0.04f);
    glVertex2f(0.05f, 0.04f);
    glEnd();

    // Neck
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
    glVertex2f(0.025f, 0.14f);
    glVertex2f(0.045f, 0.14f);
    glVertex2f(0.045f, 0.16f);
    glVertex2f(0.025f, 0.16f);
    glEnd();

    // Face
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
    glVertex2f(0.01f, 0.16f);
    glVertex2f(0.06f, 0.16f);
    glVertex2f(0.06f, 0.19f);
    glVertex2f(0.01f, 0.19f);
    glEnd();

    // Head (Hat)
    glBegin(GL_QUADS);
    glColor3f(0.58f, 0.36f, 0.31f); // Black for hat
    glVertex2f(0.01f, 0.19f);
    glVertex2f(0.06f, 0.19f);
    glVertex2f(0.05f, 0.21f);
    glVertex2f(0.02f, 0.21f);
    glEnd();

    glPopMatrix();
}

void drawHumans(){
    drawHuman(0.0f, 0.0f);
}

void updateHumanPosition() {

    yPosition += ySpeed;


    if (yPosition > 0.22f) {
        ySpeed = -0.0002f;
    } else if (yPosition < -2.0f) {
        ySpeed = 0.0002f;
    }
}

float boatX = -1.0f; // Initial position of the boat
float boatSpeed = 0.00015f; // Speed of the boat

void drawBoat(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glColor3f(0.5f, 0.35f, 0.05f); // Boat body color
    if (isNight) {
        glColor3f(0.3f, 0.3f, 0.3f); // Darker boat for night
    }

    glBegin(GL_POLYGON);
    glVertex2f(0.4f, 0.05f);
    glVertex2f(0.3f, 0.025f);
    glVertex2f(0.2f, 0.025f);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.2f, 0.015f);
    glVertex2f(0.3f, 0.015f);
    glEnd();

    // Boat sail
    glColor3f(0.8f, 0.8f, 0.8f); // White sail color
    if (isNight) {
        glColor3f(0.6f, 0.6f, 0.6f); // Grey sail for night
    }

    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.3f, 0.05f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

    glPopMatrix();
}


void drawBoats(){
drawBoat(boatX, 0.38f);
//drawBoat(boatX+1.8f, 0.38f);

}
void animateBoat() {
    boatX += boatSpeed; // Update the boat's position

    if (boatX > 1.3f) {
        boatSpeed = -0.00015f; // Reverse the direction
    }
    if (boatX < -1.3f) {
        boatSpeed = 0.00015f; // Reverse the direction
    }
}
void timer(int value) {
    glutPostRedisplay(); // Request a redraw of the window
    glutTimerFunc(16, timer, 0); // Call the timer function again after 16ms
}


void drawRiver() {
     glColor3f(0.643,0.953,1.0); // Light blue for river
    if (isNight) {
                glColor3f(0.3,0.4,0.4); // Dark blue for night

                //(136,187,187)
    }

    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, 0.53f);
    glVertex2f(1.0f, 0.53f);
    glVertex2f(1.0f, 0.33f);
    glVertex2f(1.0f, 0.18f);
    glVertex2f(0.9f, 0.28f);
    glVertex2f(0.8f, 0.23f);
    glVertex2f(0.7f, 0.33f);
    glVertex2f(-1.0f, 0.33f);
    glEnd();


   // drawBoat(boatX, 0.38f);

   // fench l 1
    glColor3f(0.35f, 0.16f, 0.14f);
    glBegin(GL_QUADS);
    glVertex2f(-1.05f, 0.32f);
    glVertex2f(0.15f, 0.32f);
    glVertex2f(0.15f, 0.31f);
    glVertex2f(-1.05f, 0.31f);
    glEnd();



    glColor3f(0.35f, 0.16f, 0.14f);


    glBegin(GL_QUADS);
    glVertex2f(-1.05f, 0.30f);  // First
    glVertex2f(0.15f, 0.30f);
    glVertex2f(0.15f, 0.29f);
    glVertex2f(-1.05f, 0.29f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-1.05f, 0.28f);  // Second
    glVertex2f(0.15f, 0.28f);
    glVertex2f(0.15f, 0.27f);
    glVertex2f(-1.05f, 0.27f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-1.05f, 0.26f);  // Third
    glVertex2f(0.15f, 0.26f);
    glVertex2f(0.15f, 0.25f);
    glVertex2f(-1.05f, 0.25f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.25f);  // paya
    glVertex2f(-0.51f, 0.25f);
    glVertex2f(-0.51f, 0.33f);
    glVertex2f(-0.5f, 0.33f);
    glEnd();

    glBegin(GL_QUADS); //paya

    glVertex2f(0.1f, 0.25f);
    glVertex2f(0.11f, 0.25f);
    glVertex2f(0.11f, 0.33f);
    glVertex2f(0.1f, 0.33f);
    glEnd();




    //fench r 1
    glBegin(GL_QUADS);
    glVertex2f(0.5f, 0.25f);    // Left side of the second part
    glVertex2f(1.05f, 0.17f);   // Right side of the second part
    glVertex2f(1.05f, 0.16f);   // Slightly below the river
    glVertex2f(0.5f, 0.24f);    // Slightly below the river
    glEnd();


    // Crossbars for the second part of the fence (from 0.5 to 1.05)
    glBegin(GL_QUADS);
    glVertex2f(0.5f, 0.23f);  // First crossbar
    glVertex2f(1.05f, 0.15f);
    glVertex2f(1.05f, 0.14f);
    glVertex2f(0.5f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.5f, 0.21f);  // Second crossbar
    glVertex2f(1.05f, 0.13f);
    glVertex2f(1.05f, 0.12f);
    glVertex2f(0.5f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.5f, 0.19f);  // Third crossbar
    glVertex2f(1.05f, 0.11f);
    glVertex2f(1.05f, 0.10f);
    glVertex2f(0.5f, 0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.8f, 0.23f);  // Third
    glVertex2f(0.79f, 0.23f);
    glVertex2f(0.79f, 0.13f);
    glVertex2f(0.8f, 0.13f);
    glEnd();
}

void drawStar(float x, float y, float size) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i) {
        float angle = 2.0f * 3.14159f * i / 5.0f;
        glVertex2f(x + size * cos(angle), y + size * sin(angle));
    }
    glEnd();
}

void drawSky() {
    if (isNight) {
        glColor3f(0.13,0.4,0.4); // Dark blue for night
        //34,102,102
    } else {
        glColor3f(0.804, 0.96, 1.0); // Light blue for day
    }

    // Draw the sky
    glBegin(GL_POLYGON);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, 0.55);
    glVertex2f(-1.0, 0.55);
    glVertex2f(-1.0, 1.0);
    glEnd();

    //star
    if (isNight) {
        glColor3f(1.0f, 1.0f, 1.0f); // White color for stars
        for (int i = 0; i < 100; ++i) { // Change the number for more or fewer stars
            float x = (rand() % 500) / 100.0 - 1.0; // Random x in range [-1.0, 1.0]
            float y = (rand() % 500) / 100.0 + 0.55; // Random y in range [0.55, 1.0]
            drawStar(x, y, 0.002); // Draw a star with a fixed size
        }
    }
}




//birds
float birdX1 = -0.6f, birdY1 = 0.8f, birdSpeed1 = 0.00085f;
float birdX2 = -0.5f, birdY2 = 0.75f, birdSpeed2 = 0.00085f;
float birdX3 = -0.4f, birdY3 = 0.78f, birdSpeed3 = 0.00085f;
float birdX4 = 0.4f, birdY4 = 0.82f, birdSpeed4 = 0.00085f;
float birdX5 = 0.5f, birdY5 = 0.77f, birdSpeed5 = 0.00085f;

float birdSize = 0.01f;
void drawBird(float x, float y, float size) {
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for birds
    glBegin(GL_LINES);
    glVertex2f(x, y); // Body
    glVertex2f(x - size, y - size); // Left wing
    glVertex2f(x, y); // Body
    glVertex2f(x + size, y - size); // Right wing
    glEnd();
}

void animateBirds() {
    // Bird 1 (moving left to right with sine wave effect)
    birdX1 += birdSpeed1;
    birdY1 = 0.8f + 0.05f * sin(birdX1 * 3.0f); // Sine wave for smooth up and down movement
    if (birdX1 > 1.0f) birdX1 = -1.0f; // Reset bird's position when it moves out of screen

    // Bird 2
    birdX2 += birdSpeed2;
    birdY2 = 0.75f + 0.05f * sin(birdX2 * 3.0f);
    if (birdX2 > 1.0f) birdX2 = -1.0f;

    // Bird 3
    birdX3 += birdSpeed3;
    birdY3 = 0.78f + 0.05f * sin(birdX3 * 3.0f);
    if (birdX3 > 1.0f) birdX3 = -1.0f;

    // Bird 4
    birdX4 += birdSpeed4;
    birdY4 = 0.82f + 0.05f * sin(birdX4 * 3.0f);
    if (birdX4 > 1.0f) birdX4 = -1.0f;

    // Bird 5
    birdX5 += birdSpeed5;
    birdY5 = 0.77f + 0.05f * sin(birdX5 * 3.0f);
    if (birdX5 > 1.0f) birdX5 = -1.0f;
}

// Function to draw multiple birds
void drawBirds() {
    drawBird(birdX1, birdY1, birdSize); // Bird 1
    drawBird(birdX2, birdY2, birdSize); // Bird 2
    drawBird(birdX3, birdY3, birdSize); // Bird 3
    drawBird(birdX4, birdY4, birdSize); // Bird 4
    drawBird(birdX5, birdY5, birdSize); // Bird 5
}


void drawMountains() {
    glColor3f(0.42, 0.26, 0.15); // Brown color for mountains
    float baseY = 0.55;
    float peakY = 0.68;
    float stepX = 0.4;

    for (float x = -1.0; x < 1.0; x += stepX) {
        glBegin(GL_TRIANGLES);
        glVertex2f(x, baseY);          // Bottom left
        glVertex2f(x + stepX, baseY); // Bottom right
        glVertex2f(x + stepX / 2, peakY);
        glEnd();
    }

    //grass
    glColor3f(0.05, 0.35, 0.16);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, baseY);
    glVertex2f(1.0, baseY);
    glVertex2f(1.0, baseY - 0.05);
    glVertex2f(-1.0, baseY - 0.05);
    glEnd();
}
void drawRoad() {
    // Determine color based on day/night
    if (isNight) {
        glColor3f(0.5f, 0.35f, 0.25f); // Dark mud color for night
    } else {
        glColor3f(0.76f, 0.60f, 0.42f); // Mud color for day
    }

    glBegin(GL_POLYGON);
    glVertex2f(0.84, -1.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(-0.9, -0.875);
    glVertex2f(0.54, -0.75);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.2, -1.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.2, -0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.0, -0.3);
    glVertex2f(-0.5, -1.0);
    glVertex2f(0.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.52, -1.0);
    glVertex2f(0.2, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.9, -0.875);
    glVertex2f(-0.2, -0.5);
    glVertex2f(0.2, -1.0);
    glEnd();

    drawHalfCircle(0.4, -0.75, 0.2);

    glBegin(GL_POLYGON);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.5, -0.6);
    glVertex2f(0.2, -1.0);
    glEnd();

    drawHalfCircle(0.2, -0.5, 0.2);

    glBegin(GL_POLYGON);
    glVertex2f(0.42, 0.125);
    glVertex2f(0.42, 0.2);
    glVertex2f(0.3, 0.175);
    glVertex2f(0.2, 0.125);
    glVertex2f(0.3, 0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.2, 0.125);
    glVertex2f(0.1, 0.075);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.2, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.31, -0.04);
    glVertex2f(0.31, -0.08);
    glVertex2f(0.3, -0.2);
    glVertex2f(0.0, -0.2);
    glVertex2f(0.1, -0.18);
    glVertex2f(0.1, -0.14);
    glVertex2f(0.0, -0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.0, -0.2);
    glVertex2f(0.3, -0.2);
    glVertex2f(0.34, -0.24);
    glVertex2f(0.34, -0.28);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.08, -0.34);
    glVertex2f(0.08, -0.30);
    glVertex2f(0.0, -0.1);
    glEnd();

    drawHalfCircle(0.15, -0.1, 0.15);
    glColor3f(0.76f, 0.60f, 0.42f); // Reset color for circle

    //drawCircle(0.0, -1.2, 0.3);
   // glColor3f(0.0f, 0.5f, 0.f); // Green color for grass/ground
}

void drawkari(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
     glColor3f(0.98,0.98,0.439);
    glBegin(GL_POLYGON);
    glVertex2f(x-0.06,y);
    glVertex2f(x+0.06,y);
    glVertex2f(x+0.06, y-0.2);
    glVertex2f(x-0.06,y-0.2);
    glEnd();

drawCircle(x,y,0.06);
         glColor3f(0.98,0.98,0.439);
    glPopMatrix();
}

void drawKaris(){
    drawkari(0.45,0.13);
}

void drawTree(float x, float y, float scaleX, float scaleY) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scaleX, scaleY, 1.0f);
    glColor3f(0.55, 0.27, 0.07); // Brown for trunk

    glBegin(GL_POLYGON);
    glVertex2f(-0.03f, -0.1f);
    glVertex2f(0.03f, -0.1f);
    glVertex2f(0.02f, 0.2f);
    glVertex2f(-0.02f, 0.2f);
    glEnd();

    // Leaves
    glColor3f(0.0f, 0.5f, 0.f); // Green color
    if (isNight) {
        glColor3f(0.1f, 0.2f, 0.1f); // Darker green for night
    }

    drawCircle(0.0f, 0.25f, 0.08f); // Center leaf
    drawCircle(-0.08f, 0.2f, 0.07f); // Left leaf
    drawCircle(0.08f, 0.2f, 0.07f);  // Right leaf
    drawCircle(-0.05f, 0.3f, 0.06f); // Top-left leaf
    drawCircle(0.05f, 0.3f, 0.06f);  // Top-right leaf
    drawCircle(0.0f, 0.15f, 0.07f);  // Bottom-center leaf

    glPopMatrix();
}

void drawTrees() {

    drawTree(-0.6f, 0.56f, 0.2f, 0.2f);  // Normal size tree
    drawTree(0.2f, 0.56f, 0.2f, 0.2f);   // Larger tree
    drawTree(-0.97f, -0.2f, 1.5f, 1.8f);
      // Smaller tree
    // drawTree(0.9f, -0.9f, 1.5f, 1.8f);
}




float cowX = 0.5f;
bool cowHasCrossed = false;


void drawCow(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

     if (isNight) {
        glPopMatrix();
        return;
    }

    // Body of the cow (rectangle)
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray color for the body
    glBegin(GL_POLYGON);
    glVertex2f(-0.08f, -0.04f);
    glVertex2f(0.08f, -0.04f);
    glVertex2f(0.08f, 0.04f);
    glVertex2f(-0.08f, 0.04f);
    glEnd();

    // Head of the cow (rectangle)
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray color for the head
    glBegin(GL_POLYGON);
    glVertex2f(0.08f, 0.0f);       // Top right
    glVertex2f(0.12f, 0.0f);       // Top left
    glVertex2f(0.12f, -0.06f);     // Bottom left
    glVertex2f(0.08f, -0.06f);     // Bottom right
    glEnd();

    // Cow ears (small triangles)
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray color for ears
    glBegin(GL_TRIANGLES);
    glVertex2f(0.1f, 0.0f);     // Base
    glVertex2f(0.12f, 0.02f);   // Top right
    glVertex2f(0.1f, 0.02f);    // Top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.06f, 0.0f);    // Base
    glVertex2f(0.08f, 0.02f);   // Top left
    glVertex2f(0.06f, 0.02f);   // Top right
    glEnd();

    // Cow legs (rectangles)
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray for legs
    glBegin(GL_POLYGON);
    glVertex2f(-0.06f, -0.04f);
    glVertex2f(-0.04f, -0.04f);
    glVertex2f(-0.04f, -0.08f);
    glVertex2f(-0.06f, -0.08f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.04f, -0.04f);
    glVertex2f(0.06f, -0.04f);
    glVertex2f(0.06f, -0.08f);
    glVertex2f(0.04f, -0.08f);
    glEnd();

    // Cow tail (line)
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray color for the tail
    glBegin(GL_LINES);
    glVertex2f(-0.08f, 0.04f);  // Tail base
    glVertex2f(-0.1f, 0.05f);   // Tail tip
    glEnd();

    // Tail tip (circle)
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray color for the tail tip
    drawCircle(-0.1f, 0.05f, 0.01f); // Tail tip

    // Cow eyes (small circles)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the eyes
    drawCircle(0.11f, -0.02f, 0.01f); // Left eye
    drawCircle(0.115f, -0.02f, 0.01f); // Right eye

    glPopMatrix();
}

void animateCow() {
    if (!cowHasCrossed) { // Only move if it hasn't crossed
        cowX += 0.001; // Move cow to the right
        if (cowX > 1.0f) { // Check if it crosses the threshold
            cowHasCrossed = true; // Set flag to true
        }
        if (cowX > 1.2f) {
            cowX = 0.5f; // Reset to left when off-screen
        }
    }
    glutPostRedisplay(); // Request redraw
}

void drawCows() {
    if (!cowHasCrossed) { // Only draw if it hasn't crossed
        drawCow(cowX, -0.5f); // Position the cow
    }
}

void timerCow(int) {
    animateCow();
    glutTimerFunc(16, timerCow, 0); // Repeat every 16ms (~60 FPS)
}


void display1() {
    if (isNight) {
        glClearColor(0.1f, 0.2f, 0.1f, 1.0f); // Dark background for night
              //  glColor3f(); // Darker green for night

    } else {
    glClearColor(0.42f, 0.68f, 0.27f, 1.0f);
    }
    glClear(GL_COLOR_BUFFER_BIT);

    if (!isPaused) {
        updateSunPosition();
        animateBoat();
        animateBirds();
        updateHumanPosition();
        animateCow();
      //  animateCloud();
    }

    drawSky();
    drawSunorMoon(); // Changed from drawSun to drawSunorMoon
   // updateSunPosition();
drawMountains();
    drawRiver();
    drawBoats();
  //  drawKaris();
    drawCows();
    drawTrees();


    //animateBoat();
    drawClouds();
    drawBirds();
    //animateBirds();
    drawRoad();
    drawHouses();
    drawHumans();
    //updateHumanPosition();
    drawCows();

    glutSwapBuffers();
    glFlush();

}


                   ///portal

float angle = 0.0f;// Initial angle for rotating circles
float t5 = 0.0f;
float hourAngle = 0.0f;  // Initial hour hand angle
float minuteAngle = 0.0f; // Initial minute hand angle
float hourIncrement = 360.0f / 60.0f / 4.0f; // Hour hand moves every 5 seconds
float minuteIncrement = 360.0f / 60.0f / 2.0f; // Minute hand moves every 2 seconds
GLfloat position = 0.5f; //for human animation position
GLfloat speed5 = 0.05f;// human speed
bool isMoving = true;
bool isLineMoving=true;
bool isNight5 = true;
bool isPaused5 = false;
#define STARS5 30
float starPositions[STARS5][2];  // Array to store star positions
bool starsInitialized = false;

void sound4()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("space.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void initializeStars() {
    for (int i = 0; i < STARS5; ++i) {
        starPositions[i][0] = static_cast<float>(rand()) / RAND_MAX * 2.0f - 1.0f;  // x coordinate
        starPositions[i][1] = static_cast<float>(rand()) / RAND_MAX * 2.0f - 1.0f;  // y coordinate
    }
    starsInitialized = true;
}

//for human
void update5(int value)
{
    if(!isPaused5 && isMoving) {
        if(position <-1.0)
        position = 0.5f;
        position -= speed5;

         if(isNight5) {
            initializeStars();
        }
    }

    glutPostRedisplay();
    glutTimerFunc(100, update5, 0);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isPaused = !isPaused; //
       //  button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isPaused5 = !isPaused5;
    }
}



// Function to draw circles
void drawCircle5(float x, float y, float radius, float r, float g, float b) {
    glColor3f(r, g, b); // Set color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float theta = i * PI / 180;
        glVertex2f(x + cos(theta) * radius, y + sin(theta) * radius);
    }
    glEnd();
}

void drawText(const char* text, float x, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

void drawHand(float centerX, float centerY, float length, float width, float angle) {
    float radianAngle = angle * PI / 180.0f;
    float x = cos(radianAngle) * length;
    float y = sin(radianAngle) * length;

    //glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(centerX, centerY); // Center of the clock
    glVertex2f(centerX + x, centerY + y);
    glEnd();
}

// Function to draw a line
void drawLine(float x1, float y1, float x2, float y2, float r, float g, float b, float lineWidth) {
    glColor3f(r, g, b); // Set the line color
    //glLineWidth(lineWidth); // Set the line width
    glBegin(GL_LINES); // Begin drawing the line
    glVertex2f(x1, y1); // Starting point
    glVertex2f(x2, y2); // Ending point
    glEnd(); // End drawing
    glColor3f(0.937f, 0.267f, 0.267f);  // Bright red
}

void brightRedLine(float x1, float y1, float x2, float y2, float lineWidth) {
    glColor3f(0.937f, 0.267f, 0.267f); // Set the line color
    //glLineWidth(lineWidth); // Set the line width
    glBegin(GL_LINES); // Begin drawing the line
    glVertex2f(x1, y1); // Starting point
    glVertex2f(x2, y2); // Ending point
    glEnd(); // End drawing
}

void brigthPurpleLine(float x1, float y1, float x2, float y2, float lineWidth) {
    glColor3f(0.941f, 0.671f, 0.988f); // Set the line color
    //glLineWidth(lineWidth); // Set the line width
    glBegin(GL_LINES); // Begin drawing the line
    glVertex2f(x1, y1); // Starting point
    glVertex2f(x2, y2); // Ending point
    glEnd(); // End drawing
    //0.941f, 0.671f, 0.988f
}

//void roseRedLine(float x1, float y1, float x2, float y2, float lineWidth) {
//    glColor3f(0.576f, 0.200f, 0.918f); // Set the line color
//    glLineWidth(lineWidth); // Set the line width
//    glBegin(GL_LINES); // Begin drawing the line
//    glVertex2f(x1, y1); // Starting point
//    glVertex2f(x2, y2); // Ending point
//    glEnd(); // End drawing
//    //0.941f, 0.671f, 0.988f
//}

//void violetLine(float x1, float y1, float x2, float y2, float lineWidth) {
//    glColor3f(0.941f, 0.671f, 0.988f); // Set the line color
//    glLineWidth(lineWidth); // Set the line width
//    glBegin(GL_LINES); // Begin drawing the line
//    glVertex2f(x1, y1); // Starting point
//    glVertex2f(x2, y2); // Ending point
//    glEnd(); // End drawing
//    //0.941f, 0.671f, 0.988f
//}

void violetLine(float x1, float y1, float x2, float y2, float lineWidth) {
    t5 += 0.002f; // Increment t for animation progress

    // Reset t to loop the animation

    if(!isPaused5 && isLineMoving){
        if (t5 > 1.0f) {
            t5= 0.0f;
        }
    }

    // Calculate the midpoint
    float midX = (x1 + x2) / 2.0f;
    float midY = (y1 + y2) / 2.0f;

    // Calculate interpolated points for animation
    float currentX1 = x1 + t5 * (midX - x1);
    float currentY1 = y1 + t5 * (midY - y1);
    float currentX2 = x2 - t5 * (x2 - midX);
    float currentY2 = y2 - t5 * (y2 - midY);

    // Set color and draw the first half of the line (from start to midpoint)

    glColor3f(0.576f, 0.200f, 0.918f);
    //glLineWidth(lineWidth);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(currentX1, currentY1);
    glEnd();

    // Set color and draw the second half of the line (from end to midpoint)
    glColor3f(0.957f, 0.247f, 0.369f);
   // glLineWidth(lineWidth);
    glBegin(GL_LINES);
    glVertex2f(currentX2, currentY2);
    glVertex2f(x2, y2);
    glEnd();

    // Request to redraw the scene
    glutPostRedisplay();
}

void roseRedLine(float x1, float y1, float x2, float y2, float lineWidth) {
    t5 += 0.001f; // Increment t for animation progress

    // Reset t to loop the animation
if(!isPaused5 && isLineMoving){
        if (t5 > 1.0f) {
            t5= 0.0f;
        }
    }
    // Calculate the midpoint
    float midX = (x1 + x2) / 2.0f;
    float midY = (y1 + y2) / 2.0f;

    // Calculate interpolated points for animation
    float currentX1 = x1 + t5 * (midX - x1);
    float currentY1 = y1 + t5 * (midY - y1);
    float currentX2 = x2 - t5 * (x2 - midX);
    float currentY2 = y2 - t5 * (y2 - midY);

    // Set color and draw the first half of the line (from start to midpoint)
    glColor3f(0.957f, 0.247f, 0.369f);

    //glLineWidth(lineWidth);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(currentX1, currentY1);
    glEnd();

    // Set color and draw the second half of the line (from end to midpoint)
    glColor3f(0.576f, 0.200f, 0.918f);
   // glLineWidth(lineWidth);
    glBegin(GL_LINES);
    glVertex2f(currentX2, currentY2);
    glVertex2f(x2, y2);
    glEnd();

    // Request to redraw the scene
    glutPostRedisplay();
}

void drawGradientBackground() {
    glBegin(GL_QUADS); // Begin drawing the rectangle

    // Bottom-left corner (Color 2)
    glColor3f(0.2196f, 0.7412f, 0.9725f);

    if(isNight5) {
        glColor3f(0.180f, 0.063f, 0.396f); // blue
    }
       glVertex2f(-1.0f, -1.0f);

       // Bottom-right corner (Color 1)
    if(isNight5) {
        glColor3f(0.0f, 0.0f, 0.0f); // blue
    }
//       glColor3f(0.0f, 0.0f, 0.0f); // black
       glVertex2f(1.0f, -1.0f);

       // Top-right corner (Color 4)
    if(isNight5) {
        glColor3f(0.0f, 0.0f, 0.0f); // blue
    }
//       glColor3f(0.0f, 0.0f, 0.0f); // Red
       glVertex2f(1.0f, 1.0f);

       // Top-left corner (Color 3)
    if(isNight5) {
        glColor3f(0.0f, 0.0f, 0.2f); // blue
    }
//       glColor3f(0.0f, 0.0f, 0.2f); // Yellow
       glVertex2f(-1.0f, 1.0f);

    glEnd(); // End drawing
}

// Idle function to update the angle continuously
void Idle() {
    if (!isPaused5) {
        angle += 0.05f; // Increment the angle for rotation
        if (angle > 2 * PI) {
            angle -= 2 * PI; // Keep angle within [0, 2*PI]
        }
    }
    glutPostRedisplay(); // Request display update
}

void drawClock(float centerX, float centerY, float radius) {

    // Draw clock circles (outer and inner)
    drawCircle5(centerX, centerY, radius, 1.0f, 0.0f, 1.0f); // Outer circle
    drawCircle5(centerX, centerY, 0.18f, 1.0f, 1.0f, 1.0f);  // Inner circle
    drawCircle5(centerX, centerY, 0.01f, 0.0f, 0.0f, 0.0f);  // Center dot

    // Draw numbers 3, 6, 9, 12
    drawText("3", centerX + radius * 0.75f, centerY, 0.0f, 0.0f, 0.0f);
    drawText("4", centerX + radius * 0.68f, centerY - 0.1f, 0.0f, 0.0f, 0.0f);
    drawText("5", centerX + radius * 0.35f, centerY - 0.15, 0.0f, 0.0f, 0.0f);
    drawText("6", centerX, centerY - radius * 0.85f, 0.0f, 0.0f, 0.0f);
    drawText("7", centerX - 0.065f, centerY - radius * 0.78f, 0.0f, 0.0f, 0.0f);
    drawText("8", centerX - 0.13f, centerY - radius * 0.55f, 0.0f, 0.0f, 0.0f);
    drawText("9", centerX - radius * 0.85f, centerY, 0.0f, 0.0f, 0.0f);
    drawText("10", centerX - radius * 0.72f, centerY + 0.075f, 0.0f, 0.0f, 0.0f);
    drawText("11", centerX - radius * 0.35f, centerY + radius * 0.65f, 0.0f, 0.0f, 0.0f);

    drawText("12", centerX, centerY + radius * 0.65f, 0.0f, 0.0f, 0.0f);
    drawText("1", centerX + 0.062f, centerY + radius * 0.6f, 0.0f, 0.0f, 0.0f);
    drawText("2", centerX + 0.12f, centerY + radius * 0.42f, 0.0f, 0.0f, 0.0f);


    drawHand(centerX, centerY, radius * 0.75f, 2.0f, minuteAngle); // Minute hand
    drawHand(centerX, centerY, radius * 0.5f, 4.0f, hourAngle);  // Hour hand
}

void drawClockTower(float centerX, float centerY, float radius) {

    // Draw clock circles (outer and inner)
    drawCircle5(centerX, centerY, radius, 0.0f, 0.0f, 0.0f); // Outer circle
    drawCircle5(centerX, centerY, radius * 0.9, 1.0f, 1.0f, 1.0f);  // Inner circle
    drawCircle5(centerX, centerY, radius * 0.1, 0.0f, 0.0f, 0.0f);  // Center dot

    // Draw numbers 3, 6, 9, 12
    drawText("3", centerX + radius * 0.7f, centerY, 0.0f, 0.0f, 0.0f);
//    drawText("4", centerX + radius * 0.68f, centerY - 0.1f, 0.0f, 0.0f, 0.0f);
//    drawText("5", centerX + radius * 0.35f, centerY - 0.15, 0.0f, 0.0f, 0.0f);
    drawText("6", centerX, centerY - radius * 0.85f, 0.0f, 0.0f, 0.0f);
//    drawText("7", centerX - 0.065f, centerY - radius * 0.78f, 0.0f, 0.0f, 0.0f);
//    drawText("8", centerX - 0.13f, centerY - radius * 0.55f, 0.0f, 0.0f, 0.0f);
    drawText("9", centerX - radius * 0.85f, centerY, 0.0f, 0.0f, 0.0f);
//    drawText("10", centerX - radius * 0.72f, centerY + 0.075f, 0.0f, 0.0f, 0.0f);
//    drawText("11", centerX - radius * 0.35f, centerY + radius * 0.65f, 0.0f, 0.0f, 0.0f);
//
    drawText("12", centerX, centerY + radius * 0.45f, 0.0f, 0.0f, 0.0f);
//    drawText("1", centerX + 0.062f, centerY + radius * 0.6f, 0.0f, 0.0f, 0.0f);
//    drawText("2", centerX + 0.12f, centerY + radius * 0.42f, 0.0f, 0.0f, 0.0f);
//

    drawHand(centerX, centerY, radius * 0.75f, 2.0f, minuteAngle); // Minute hand
    drawHand(centerX, centerY, radius * 0.5f, 4.0f, hourAngle);  // Hour hand
}

void updateClock() {
    // Decrease the angles for clockwise movement
    minuteAngle -= minuteIncrement; // Decrement minute hand
    if (minuteAngle < 0.0f) {
        minuteAngle += 360.0f; // Reset to 360 after completing a full circle
    }

    hourAngle -= hourIncrement; // Decrement hour hand
    if (hourAngle < 0.0f) {
        hourAngle += 360.0f; // Reset to 360 after completing a full circle
    }

    glutPostRedisplay(); // Request to redraw the scene
}

void timer5(int value) {
    if (!isPaused5) {
        updateClock();
    }
    glutTimerFunc(1000 / 60, timer5, 0); // 60 FPS to keep animation smooth
}

// Display function
void display2() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    drawGradientBackground();



    if(isNight5) {
        glPointSize(3.0f);
        if (!starsInitialized) {
            initializeStars();
        }

        glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f); // White color for stars
        for (int i = 0; i < STARS5; ++i) {
            glVertex2f(starPositions[i][0], starPositions[i][1]);
        }
        glEnd();
    }


    drawClock(-0.6f, 0.75f, 0.19f);

    brigthPurpleLine(-1.0f, -0.90f, 0.53f, 0.46f, 4.0f);
    brightRedLine(-1.0f, -0.99f, 0.55f, 0.5f, 2.0f);
    violetLine(-1.0f, -1.0f, 0.55f, 0.5f, 4.0f); //(-1, -1)
    brightRedLine(-0.96f, -1.0f, 0.55f, 0.495f, 3.0f);
    violetLine(-0.90f, -1.0f, 0.55f, 0.49f, 4.0f);
    brigthPurpleLine(-0.86f, -1.0f, 0.55f, 0.48f, 3.0f);
    roseRedLine(-0.80f, -1.0f, 0.55f, 0.46f, 5.0f);
    brigthPurpleLine(-0.70f, -1.0f, 0.53f, 0.46f, 4.0f);


    violetLine(-0.42f, -1.0f, 0.53f, 0.4f, 5.0f);
    brigthPurpleLine(-0.35f, -1.0f, 0.55f, 0.4f, 5.0f);
    violetLine(-0.25f, -1.0f, 0.55f, 0.4f, 5.0f);
    brightRedLine(-0.15f, -1.0f, 0.55f, 0.4f, 5.0f);
    brigthPurpleLine(-0.07f, -1.0f, 0.55f, 0.4f, 8.0f);
    brigthPurpleLine(0.0f, -1.0f, 0.57f, 0.4f, 4.0f);
    roseRedLine(0.0f, -1.0f, 0.57f, 0.4f, 4.0f);
    roseRedLine(0.1f, -1.0f, 0.57f, 0.4f, 3.0f);
    brigthPurpleLine(0.18f, -1.0f, 0.57f, 0.4f, 4.0f);
    brightRedLine(0.28f, -1.0f, 0.57f, 0.4f, 4.0f);
    violetLine(0.28f, -1.0f, 0.57f, 0.4f, 4.0f);
    brigthPurpleLine(0.36f, -1.0f, 0.57f, 0.4f, 4.0f);
    violetLine(0.36f, -1.0f, 0.57f, 0.4f, 4.0f);
    //
    brigthPurpleLine(0.44f, -1.0f, 0.57f, 0.4f, 4.0f);
    brightRedLine(0.48f, -1.0f, 0.59f, 0.43f, 4.0f);
    brigthPurpleLine(0.58f, -1.0f, 0.60f, 0.43f, 4.0f);
    brigthPurpleLine(0.66f, -1.0f, 0.60f, 0.43f, 4.0f);
    roseRedLine(0.66f, -1.0f, 0.60f, 0.43f, 4.0f);
    roseRedLine(0.75f, -1.0f, 0.60f, 0.46f, 4.0f);
    brigthPurpleLine(0.81f, -1.0f, 0.60f, 0.46f, 4.0f);
    violetLine(0.81f, -1.0f, 0.60f, 0.46f, 4.0f);
    brigthPurpleLine(0.88f, -1.0f, 0.60f, 0.47f, 4.0f);


    violetLine(1.0f, 0.2f, 0.62f, 0.5f, 2.0f);
    brigthPurpleLine(1.0f, 0.15f, 0.61f, 0.5f, 4.0f);
    brigthPurpleLine(1.0f, 0.10f, 0.6f, 0.5f, 4.0f);
    roseRedLine(1.0f, 0.10f, 0.6f, 0.5f, 4.0f);
    violetLine(1.0f, 0.03f, 0.58f, 0.5f, 4.0f);
    brigthPurpleLine(1.0f, -0.08f, 0.58f, 0.5f, 4.0f);

    // Outer circle (dark blue)
    drawCircle5(0.55, 0.5, 0.1, 1.0, 1.0, 1.0);

    // Middle circle (light blue)
    drawCircle5(0.55, 0.5, 0.04, 0.3, 0.6, 1.0);

    // Inner circle (black)
    drawCircle5(0.55, 0.5, 0.02, 0.0, 0.0, 0.0);

    // Rotating smaller circles (white)
    for (int i = 0; i < 3; i++) {
        float theta = angle + i * (2 * PI / 3); // 120-degree separation
        float x = 0.55 + cos(theta) * 0.07; // Adjusted position
        float y = 0.5 + sin(theta) * 0.07; // Adjusted position
        drawCircle5(x, y, 0.015, 0.0f, 0.0f, 0.0f); // Smaller white circles with reduced radius
    }

    ////
    ///

    ///human 1
    glPushMatrix();
    glTranslatef(0.50f,position, 0.0f);
    GLfloat scaleFactor = 1.0f + (0.5f - position) * 0.5f;
    glScalef(scaleFactor, scaleFactor, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.43f, 0.62f, 0.94f); // Dark green for body
    glVertex2f(0.0f, 0.09f);  // Shifted by +0.04
    glVertex2f(0.07f, 0.09f);
    glVertex2f(0.07f, 0.14f);
    glVertex2f(0.0f, 0.14f);
    glEnd();

    ///left hand
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.85f, 0.75f); // Light beige for left hand
    glVertex2f(0.0f, 0.08f);  // Shifted by +0.04
    glVertex2f(-0.015f, 0.08f);
    glVertex2f(-0.012f, 0.14f);
    glVertex2f(0.0f, 0.14f);
    glEnd();

    ///left hand sleeve
    glBegin(GL_QUADS);
    glColor3f(0.43f, 0.62f, 0.94f); // Red for sleeve
    glVertex2f(0.0f, 0.11f);  // Shifted by +0.04
    glVertex2f(-0.015f, 0.11f);
    glVertex2f(-0.012f, 0.14f);
    glVertex2f(0.0f, 0.14f);
    glEnd();

    ///right hand
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.85f, 0.75f); // Light beige for right hand
    glVertex2f(0.07f, 0.08f);  // Shifted by +0.04
    glVertex2f(0.085f, 0.08f);
    glVertex2f(0.082f, 0.14f);
    glVertex2f(0.07f, 0.14f);
    glEnd();

    ///right hand sleeve
    glBegin(GL_QUADS);
    glColor3f(0.43f, 0.62f, 0.94f); // Blue for sleeve
    glVertex2f(0.07f, 0.11f);  // Shifted by +0.04
    glVertex2f(0.085f, 0.11f);
    glVertex2f(0.082f, 0.14f);
    glVertex2f(0.07f, 0.14f);
    glEnd();

    ///legs
    glBegin(GL_QUADS);
    glColor3f(0.08f, 0.26f, 0.54f); // Navy blue for left leg
    glVertex2f(0.0f, 0.04f);  // Shifted by +0.04
    glVertex2f(0.02f, 0.04f);
    glVertex2f(0.07f, 0.09f);
    glVertex2f(0.0f, 0.09f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.08f, 0.26f, 0.54f); // Slightly lighter navy blue for right leg
    glVertex2f(0.05f, 0.04f);  // Shifted by +0.04
    glVertex2f(0.07f, 0.04f);
    glVertex2f(0.07f, 0.09f);
    glVertex2f(0.03f, 0.09f);
    glEnd();

    ///shoes
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for left shoe
    glVertex2f(0.0f, 0.03f);  // Shifted by +0.04
    glVertex2f(0.02f, 0.03f);
    glVertex2f(0.02f, 0.04f);
    glVertex2f(0.0f, 0.04f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); // Slightly lighter gray for right shoe
    glVertex2f(0.05f, 0.03f);  // Shifted by +0.04
    glVertex2f(0.07f, 0.03f);
    glVertex2f(0.07f, 0.04f);
    glVertex2f(0.05f, 0.04f);
    glEnd();

    ///neck
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.8f, 0.7f); // Light skin tone for neck
    glVertex2f(0.025f, 0.14f);  // Shifted by +0.04
    glVertex2f(0.045f, 0.14f);
    glVertex2f(0.045f, 0.16f);
    glVertex2f(0.025f, 0.16f);
    glEnd();

    ///face
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.85f, 0.75f); // Light skin tone for face
    glVertex2f(0.01f, 0.16f);  // Shifted by +0.04
    glVertex2f(0.06f, 0.16f);
    glVertex2f(0.06f, 0.19f);
    glVertex2f(0.01f, 0.19f);
    glEnd();
      /// Head (Hat)
    glBegin(GL_QUADS);
    glColor3f(0.58f, 0.36f, 0.31f); // Black for hat
    glVertex2f(0.01f, 0.19f);
    glVertex2f(0.06f, 0.19f);
    glVertex2f(0.05f, 0.21f);
    glVertex2f(0.02f, 0.21f);
    glEnd();
    glPopMatrix();


    brightRedLine(-1.0f, -0.4f, -0.45f, -0.4f, 2.0f);

    //tower-1
    //bottom quads
    glBegin(GL_QUADS);
    glColor3f(39.0f / 255.0f, 39.0f / 255.0f, 42.0f / 255.0f);
    glVertex2f(-0.95f, -0.4f);
    glVertex2f(-0.74f, -0.4f);
    glVertex2f(-0.74f, -0.35f);
    glVertex2f(-0.95f, -0.35f);
    glEnd();

    //middle red quads
    glBegin(GL_QUADS);
    glColor3f(202.0f / 255.0f, 138.0f / 255.0f, 4.0f / 255.0f);
    glVertex2f(-0.93f, -0.35f);
    glVertex2f(-0.76f, -0.35f);
    glVertex2f(-0.76f, 0.25f);
    glVertex2f(-0.93f, 0.25f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(39.0f / 255.0f, 39.0f / 255.0f, 42.0f / 255.0f);
    glVertex2f(-0.93f, 0.25f);
    glVertex2f(-0.84f, 0.5f);
    glVertex2f(-0.76f, 0.25f);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3f(0.9451f, 0.9608f, 0.9765f);
    if(isNight5){
        glColor3f(253.0f / 255.0f, 224.0f / 255.0f, 71.0f / 255.0f);
    }
    glVertex2f(-0.88f, -0.2f);
    glVertex2f(-0.82f, -0.2f);
    glVertex2f(-0.82f, -0.05f);
    glVertex2f(-0.88f, -0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.85f, -0.2f);
    glVertex2f(-0.85f, -0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.88f, -0.125f);  // Left point of horizontal line
    glVertex2f(-0.82f, -0.125f);  // Right point of horizontal line
    glEnd();

    drawClockTower(-0.845f, 0.1f, 0.08f);


    //tower-2
    //bottom quads
    glBegin(GL_QUADS);
    glColor3f(39.0f / 255.0f, 39.0f / 255.0f, 42.0f / 255.0f);
    glVertex2f(-0.71f, -0.4f);    // Moved right by 0.05f
    glVertex2f(-0.50f, -0.4f);    // Moved right by 0.05f
    glVertex2f(-0.50f, -0.35f);   // Moved right by 0.05f
    glVertex2f(-0.71f, -0.35f);   // Moved right by 0.05f
    glEnd();

    //middle red quads
    glBegin(GL_QUADS);
    glColor3f(220.0f / 255.0f, 38.0f / 255.0f, 38.0f / 255.0f);
    glVertex2f(-0.69f, -0.35f);   // Moved right by 0.05f
    glVertex2f(-0.52f, -0.35f);   // Moved right by 0.05f
    glVertex2f(-0.52f, 0.25f);    // Moved right by 0.05f
    glVertex2f(-0.69f, 0.25f);    // Moved right by 0.05f
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(39.0f / 255.0f, 39.0f / 255.0f, 42.0f / 255.0f);
    glVertex2f(-0.69f, 0.25f);    // Moved right by 0.05f
    glVertex2f(-0.60f, 0.5f);     // Moved right by 0.05f
    glVertex2f(-0.52f, 0.25f);    // Moved right by 0.05f
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3f(0.9451f, 0.9608f, 0.9765f);
    if(isNight5){
        glColor3f(253.0f / 255.0f, 224.0f / 255.0f, 71.0f / 255.0f);
    }
    glVertex2f(-0.64f, -0.2f);    // Moved right by 0.05f
    glVertex2f(-0.58f, -0.2f);    // Moved right by 0.05f
    glVertex2f(-0.58f, -0.05f);   // Moved right by 0.05f
    glVertex2f(-0.64f, -0.05f);   // Moved right by 0.05f
    glEnd();

    //window lines
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.61f, -0.2f);    // Moved right by 0.05f
    glVertex2f(-0.61f, -0.05f);   // Moved right by 0.05f
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.64f, -0.125f);  // Moved right by 0.05f
    glVertex2f(-0.58f, -0.125f);  // Moved right by 0.05f
    glEnd();

    drawClockTower(-0.605f, 0.1f, 0.08f);

    glFlush();
}

// Initialization




    void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
    {
    case '3':
        glutDisplayFunc(twilight_view);
        sound1();


        //
        break;
         case '4':

        glutDisplayFunc(night_view);//
        sound();

        break;
        case '2':
        glutDisplayFunc(day_view);
        sound2();
        break;

         case '1':  ///past
glutDisplayFunc(display1);
sound3();

   break;
            case '5':  ///portal
glutDisplayFunc(display2);
sound4();

   break;

         case 'a': // Stop all movements
            ambulance_speed = 0.0f;
            policecar_speed=0.0f;
            human4_Speed=0.007f;
  glutDisplayFunc(day_view1);//
sound2();

          break;

           case 'b': // privious  movements
       ambulance_speed = 0.03f;
       policecar_speed=0.007f;
       human4_Speed=0.0f;
        glutDisplayFunc(day_view2);
        sound2();
        break;

        case 'c': // Stop all movements
            ambulance_speed = 0.0f;
            policecar_speed=0.0f;
            human4_Speed=0.007f;
  glutDisplayFunc(twilight_view1);//
  sound1();

          break;
           case 'd': // privious  movements
       ambulance_speed = 0.03f;
       policecar_speed=0.007f;
       human4_Speed=0.0f;
        glutDisplayFunc(twilight_view2);
        sound1();
        break;
           case 'e': // Stop all movements
            ambulance_speed = 0.0f;
            policecar_speed=0.0f;
            human4_Speed=0.007f;
  glutDisplayFunc(night_view1);//
sound();
          break;
           case 'f': // privious  movements
       ambulance_speed = 0.03f;
       policecar_speed=0.007f;
       human4_Speed=0.0f;
        glutDisplayFunc(night_view2);
        sound();
        break;
               case 's': // privious  movements
          sunSpeed=0.0;
        break;
           case 'u': // privious  movements
          sunSpeed=0.01;
        break;


     ///past view

        case 'm': // Fallthrough intended

            isNight = true;
            sound3();
            break;

         // Fallthrough intended
        case 'n':
            isNight = false;
            sound3();
            break;

            ///portal
             case 'o':  // Fallthrough intende
            isMoving = !isMoving;
            isLineMoving = !isLineMoving;
            sound4();  // Toggle the movement
            break;
              case 'p':  // Fallthrough intende
            isNight5 = !isNight5;
            sound4();
            // Toggle the movement
            break;





    glutPostRedisplay();

	}
}

  /*  void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}*/

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1520, 800); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("TIME TRAVEL"); // Create a window with the given title
    // Register display callback handler for window re-paint
     //glutDisplayFunc(display2);//
    glutDisplayFunc(night_view);

    glutDisplayFunc(twilight_view);
    glutDisplayFunc(day_view);
         glutDisplayFunc(display1);
           glutDisplayFunc(display2);
    glutTimerFunc(80, update_Sun, 0);
    glutTimerFunc(100, update_cloud1, 0);
    glutTimerFunc(100, update_cloud2, 0);
    glutTimerFunc(100, update_ambulance, 0);
    glutTimerFunc(100, update_human1, 0);
    glutTimerFunc(100, update_human2, 0);
     glutTimerFunc(100, update_human3, 0);
    glutTimerFunc(100, update_human4, 0);
     glutTimerFunc(100, update_plane, 0);
        //glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    // Register display callback
    glutIdleFunc(Idle);        // Register idle function for continuous animation
    glutTimerFunc(1000 / 60, timer5, 0);
    glutTimerFunc(100, update5, 0);
     glutTimerFunc(100, timer, 0); // Start the timer for animation
    glutTimerFunc(25, timerCow, 0); // Start the timer for animation
    glutTimerFunc(25, timerCloud, 0);

     glutKeyboardFunc(handleKeypress);
             glutMouseFunc(mouseClick); // Register mouse click function
              // glutMouseFunc(handleMouseClick5);

    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
