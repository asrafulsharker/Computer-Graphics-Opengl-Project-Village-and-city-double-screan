#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

float xPos = 0.0f; // initialy position 0f
float yPos = 0.0f;// initialy position 0f
void drawCity(); //city function
void drawVillage(); //village function
float bx = 10; //for auto movement bx =10
float cx = 10; //for auto movement cx =10
float rocket_x = 10; //rocket movement var
float car2_x = 10; //car movement var
bool isCityVisible = true; //for initial vissible city








//raindrop
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int NUM_RAINDROPS = 500;

struct Raindrop {
    float x;
    float y;
    float speed;
};

Raindrop raindrops[NUM_RAINDROPS];
bool isRainActive = false;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



    // Initialize raindrop positions and speeds
     for (int i = 0; i < NUM_RAINDROPS; i++) {
        raindrops[i].x = rand() % 50;
        raindrops[i].y = rand() % 50;
        raindrops[i].speed = (float)(rand() % 10 + 1) / 10.0f;
    }
}




// For Draw SUN via triangle fan
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 100;


    GLfloat twicePi = 2.0 * M_PI;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


// For black-white buildings apartments
void drawCircle2(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50;


    GLfloat twicePi = 2.0 * M_PI;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}





void rain()
{


glColor3f(0.7f, 0.7f, 1.0f);

    if (isRainActive) {
        for (int i = 0; i < NUM_RAINDROPS; i++) {
            glBegin(GL_LINES);
            glVertex2f(raindrops[i].x, raindrops[i].y);
            glVertex2f(raindrops[i].x, raindrops[i].y - 0.5);
            glEnd();

            raindrops[i].y -= raindrops[i].speed;

            // Reset raindrop position if it reaches the bottom
            if (raindrops[i].y < 0) {
                raindrops[i].x = rand() % 50;
                raindrops[i].y = 50;
            }
        }
    }

}




// For Draw CLOUDS via triangle fan and  CLOUDS auto Movement




// 1st car AUTO Movement



void car()
{

    glPushMatrix();
    glTranslatef(bx, 0, 0);

    glBegin(GL_QUADS); //Car 1
    glColor3f(0.541, 0.541, 0.533);
    glVertex3f(3.2f, 13.4328f, 0.0f);
    glVertex3f(3.2f, 9.9254f, 0.0f);
    glVertex3f(8.6f, 9.9254f, 0.0f);
    glVertex3f(8.6f, 13.4328f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);//Lower part
    glColor3f(0.153, 0.376, 0.31);
    glVertex3f(3.1333f, 10.1493f, 0.0f);
    glVertex3f(3.1333f, 9.0299f, 0.0f);
    glVertex3f(8.8f, 9.0299f, 0.0f);
    glVertex3f(8.8667f, 10.0746f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);//Head lower part
    glColor3f(0.424, 0.612, 0.549);
    glVertex3f(8.8667f, 10.5224f, 0.0f);
    glVertex3f(8.8667f, 8.6567f, 0.0f);
    glVertex3f(11.8f, 8.6567f, 0.0f);
    glVertex3f(11.8f, 10.5224f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);// head upper head
    glColor3f(0.427, 0.612, 0.549);
    glVertex3f(8.8667f, 10.1493f, 0.0f);
    glVertex3f(11.8667f, 10.1493f, 0.0f);
    glVertex3f(10.8667f, 12.0149f, 0.0f);
    glVertex3f(8.8667f, 12.3134f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);//Window
    glColor3f(0.8, 0.91, 0.922);
    glVertex3f(9.3333f, 10.3731f, 0.0f);
    glVertex3f(11.3333f, 10.4478f, 0.0f);
    glVertex3f(10.4f, 11.5672f, 0.0f);
    glVertex3f(9.2667f, 11.6418f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);//Light
    glColor3f(0.824, 0.875, 0.42);
    glVertex3f(11.4f, 10.0746f, 0.0f);
    glVertex3f(11.4f, 9.403f, 0.0f);
    glVertex3f(11.8667f, 9.403f, 0.0f);
    glVertex3f(11.8667f, 10.0746f, 0.0f);
    glEnd();


// drawing the first car wheel



//1st wheel
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.875, 0.42);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(4.5+cos(angel)*.7,8.6+sin(angel)*.8);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.5, 0.42);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(4.5+cos(angel)*.6,8.6+sin(angel)*.7);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.3, 0.42);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(4.5+cos(angel)*.2,8.6+sin(angel)*.3);
    }
    glEnd();//end



    //2nd wheel
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.875, 0.42);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(7.5+cos(angel)*.7,8.6+sin(angel)*.8);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.5, 0.2);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;


        glVertex2f(7.5+cos(angel)*.6,8.6+sin(angel)*.7);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.5, 0.4);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(7.5+cos(angel)*.2,8.6+sin(angel)*.3);
    }
    glEnd();//end



    glPopMatrix();
    bx += .012;
    if (bx > 40)
        bx = -50;
    glutPostRedisplay();

}
// 1st car done






// 2nd car start


void car2()
{


    // 2nd car Draw

    glBegin(GL_POLYGON);//Car2

    glColor3f(0.235, 0.235, 0.227);
    glVertex3f(38.5333f, 9.5522f, 0.0f);
    glVertex3f(45.5333f, 9.5522f, 0.0f);
    glVertex3f(45.5333f, 5.0746f, 0.0f);
    glVertex3f(35.8667f, 5.1493f, 0.0f);
    glVertex3f(35.9333f, 7.0149f, 0.0f);
    glVertex3f(37.5333f, 7.9851f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);//Window
    glColor3f(0.8, 0.91, 0.922);
    glVertex3f(40.1333f, 7.7612f, 0.0f);
    glVertex3f(37.9333f, 7.7612f, 0.0f);
    glVertex3f(38.7333f, 9.3284f, 0.0f);
    glVertex3f(40.1333f, 9.2537f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);// front light ar nichay sada stripe
    glColor3f(0.847, 0.847, 0.847);
    glVertex3f(44.8f, 5.7463f, 0.0f);
    glVertex3f(44.8f, 4.9254f, 0.0f);
    glVertex3f(46.0f, 4.9254f, 0.0f);
    glVertex3f(46.0f, 5.7463f, 0.0f);
    glEnd();

    glBegin(GL_QUADS); // back light ar nichay sada stripe
    glColor3f(0.847, 0.847, 0.847);
    glVertex3f(36.8667f, 5.0f, 0.0f);
    glVertex3f(36.8667f, 5.8209f, 0.0f);
    glVertex3f(35.7333f, 5.8209f, 0.0f);
    glVertex3f(35.7333f, 5.0f, 0.0f);
    glEnd();


    glBegin(GL_QUADS);//Light
    glColor3f(0.824, 0.875, 0.42);
    glVertex3f(36.2f, 6.2687f, 0.0f);
    glVertex3f(35.8f, 6.2687f, 0.0f);
    glVertex3f(35.8f, 6.8657f, 0.0f);
    glVertex3f(36.2f, 6.8657f, 0.0f);
    glEnd();




// drawing the second car wheel




//1st wheel
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.875, 0.42);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(39+cos(angel),4.8+sin(angel));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 0.5);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(39+cos(angel)*.8,4.8+sin(angel)*.8);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.75, 0.2);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(39+cos(angel)*.3,4.8+sin(angel)*.4);
    }
    glEnd();//end




//2nd wheel
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.875, 0.42);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(43.5+cos(angel),4.8+sin(angel));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 0.5);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(43.5+cos(angel)*.8,4.8+sin(angel)*.8);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.75, 0.2);
    for(int i=0; i<=360; i++)
    {
        float angel = i*3.1416/180;

        glVertex2f(43.5+cos(angel)*.3,4.8+sin(angel)*.4);
    }



}






//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ROCKET¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬




void rocket()
{

    glPushMatrix();
    glTranslatef(rocket_x, 0, 0);






    //rocket

    glBegin(GL_TRIANGLE_FAN);    //bottom smoke
    glColor3f(0.992, 0.996, 0.631);
    glVertex3f(17.2667f, 41.7164f, 0.0f);
    glVertex3f(17.2f, 41.6418f, 0.0f);
    glVertex3f(17.1333f, 41.6418f, 0.0f);
    glVertex3f(17.1333f, 41.5672f, 0.0f);
    glVertex3f(17.0667f, 41.5672f, 0.0f);
    glVertex3f(17.0f, 41.5672f, 0.0f);
    glVertex3f(16.9333f, 41.5672f, 0.0f);
    glVertex3f(16.8667f, 41.5672f, 0.0f);
    glVertex3f(16.8f, 41.5672f, 0.0f);
    glVertex3f(16.8f, 41.4925f, 0.0f);
    glVertex3f(16.7333f, 41.4925f, 0.0f);
    glVertex3f(16.6667f, 41.4925f, 0.0f);
    glVertex3f(16.6f, 41.4925f, 0.0f);
    glVertex3f(16.5333f, 41.4925f, 0.0f);
    glVertex3f(16.5333f, 41.4179f, 0.0f);
    glVertex3f(16.4667f, 41.4179f, 0.0f);
    glVertex3f(16.4f, 41.4179f, 0.0f);
    glVertex3f(16.4f, 41.3433f, 0.0f);
    glVertex3f(16.3333f, 41.3433f, 0.0f);
    glVertex3f(16.2667f, 41.3433f, 0.0f);
    glVertex3f(16.2f, 41.3433f, 0.0f);
    glVertex3f(16.1333f, 41.3433f, 0.0f);
    glVertex3f(16.0667f, 41.3433f, 0.0f);
    glVertex3f(16.0667f, 41.2687f, 0.0f);
    glVertex3f(16.0f, 41.2687f, 0.0f);
    glVertex3f(15.9333f, 41.2687f, 0.0f);
    glVertex3f(15.8667f, 41.2687f, 0.0f);
    glVertex3f(15.8f, 41.2687f, 0.0f);
    glVertex3f(15.7333f, 41.194f, 0.0f);
    glVertex3f(15.6667f, 41.194f, 0.0f);
    glVertex3f(15.6f, 41.194f, 0.0f);
    glVertex3f(15.5333f, 41.194f, 0.0f);
    glVertex3f(15.4667f, 41.194f, 0.0f);
    glVertex3f(15.4f, 41.194f, 0.0f);
    glVertex3f(15.3333f, 41.194f, 0.0f);
    glVertex3f(15.2667f, 41.194f, 0.0f);
    glVertex3f(15.2f, 41.194f, 0.0f);
    glVertex3f(15.1333f, 41.194f, 0.0f);
    glVertex3f(15.1333f, 41.1194f, 0.0f);
    glVertex3f(15.0667f, 41.1194f, 0.0f);
    glVertex3f(15.0f, 41.1194f, 0.0f);
    glVertex3f(14.9333f, 41.1194f, 0.0f);
    glVertex3f(14.9333f, 41.0448f, 0.0f);
    glVertex3f(14.8667f, 41.0448f, 0.0f);
    glVertex3f(14.8667f, 40.9701f, 0.0f);
    glVertex3f(14.8667f, 40.8955f, 0.0f);
    glVertex3f(14.8667f, 40.8209f, 0.0f);
    glVertex3f(14.8667f, 40.7463f, 0.0f);
    glVertex3f(14.8f, 40.6716f, 0.0f);
    glVertex3f(14.8f, 40.597f, 0.0f);
    glVertex3f(14.8f, 40.5224f, 0.0f);
    glVertex3f(14.7333f, 40.5224f, 0.0f);
    glVertex3f(14.7333f, 40.4478f, 0.0f);
    glVertex3f(14.6667f, 40.4478f, 0.0f);
    glVertex3f(14.6667f, 40.3731f, 0.0f);
    glVertex3f(14.6f, 40.2985f, 0.0f);
    glVertex3f(14.6f, 40.2239f, 0.0f);
    glVertex3f(14.5333f, 40.2239f, 0.0f);
    glVertex3f(14.4667f, 40.2239f, 0.0f);
    glVertex3f(14.4f, 40.1493f, 0.0f);
    glVertex3f(14.3333f, 40.1493f, 0.0f);
    glVertex3f(14.3333f, 40.0746f, 0.0f);
    glVertex3f(14.2667f, 40.0f, 0.0f);
    glVertex3f(14.2f, 40.0f, 0.0f);
    glVertex3f(14.1333f, 40.0f, 0.0f);
    glVertex3f(14.1333f, 39.9254f, 0.0f);
    glVertex3f(14.0667f, 39.9254f, 0.0f);
    glVertex3f(14.0f, 39.9254f, 0.0f);
    glVertex3f(13.9333f, 39.9254f, 0.0f);
    glVertex3f(13.8667f, 39.9254f, 0.0f);
    glVertex3f(13.8f, 39.9254f, 0.0f);
    glVertex3f(13.7333f, 39.9254f, 0.0f);
    glVertex3f(13.6667f, 39.9254f, 0.0f);
    glVertex3f(13.6667f, 40.0f, 0.0f);
    glVertex3f(13.6f, 40.0f, 0.0f);
    glVertex3f(13.5333f, 40.0746f, 0.0f);
    glVertex3f(13.5333f, 40.1493f, 0.0f);
    glVertex3f(13.5333f, 40.2239f, 0.0f);
    glVertex3f(13.4667f, 40.2239f, 0.0f);
    glVertex3f(13.4667f, 40.2985f, 0.0f);
    glVertex3f(13.4f, 40.2985f, 0.0f);
    glVertex3f(13.4f, 40.3731f, 0.0f);
    glVertex3f(13.3333f, 40.3731f, 0.0f);
    glVertex3f(13.3333f, 40.4478f, 0.0f);
    glVertex3f(13.2667f, 40.4478f, 0.0f);
    glVertex3f(13.2667f, 40.3731f, 0.0f);
    glVertex3f(13.2667f, 40.2985f, 0.0f);
    glVertex3f(13.2667f, 40.2239f, 0.0f);
    glVertex3f(13.2667f, 40.1493f, 0.0f);
    glVertex3f(13.2667f, 40.0746f, 0.0f);
    glVertex3f(13.2667f, 40.0f, 0.0f);
    glVertex3f(13.2667f, 39.9254f, 0.0f);
    glVertex3f(13.2667f, 39.8507f, 0.0f);
    glVertex3f(13.2667f, 39.7761f, 0.0f);
    glVertex3f(13.2667f, 39.7015f, 0.0f);
    glVertex3f(13.2f, 39.7015f, 0.0f);
    glVertex3f(13.1333f, 39.7015f, 0.0f);
    glVertex3f(13.0667f, 39.7015f, 0.0f);
    glVertex3f(13.0f, 39.7015f, 0.0f);
    glVertex3f(12.9333f, 39.7015f, 0.0f);
    glVertex3f(12.8667f, 39.7015f, 0.0f);
    glVertex3f(12.8f, 39.7015f, 0.0f);
    glVertex3f(12.7333f, 39.7015f, 0.0f);
    glVertex3f(12.6667f, 39.7015f, 0.0f);
    glVertex3f(12.6f, 39.7015f, 0.0f);
    glVertex3f(12.5333f, 39.7015f, 0.0f);
    glVertex3f(12.4667f, 39.7015f, 0.0f);
    glVertex3f(12.4f, 39.7015f, 0.0f);
    glVertex3f(12.3333f, 39.7015f, 0.0f);
    glVertex3f(12.2667f, 39.7015f, 0.0f);
    glVertex3f(12.2f, 39.7015f, 0.0f);
    glVertex3f(12.1333f, 39.7015f, 0.0f);
    glVertex3f(12.0667f, 39.7015f, 0.0f);
    glVertex3f(12.0f, 39.7015f, 0.0f);
    glVertex3f(11.9333f, 39.7015f, 0.0f);
    glVertex3f(11.9333f, 39.7761f, 0.0f);
    glVertex3f(11.8667f, 39.8507f, 0.0f);
    glVertex3f(11.8667f, 39.9254f, 0.0f);
    glVertex3f(11.8667f, 40.0f, 0.0f);
    glVertex3f(11.8f, 40.0f, 0.0f);
    glVertex3f(11.8f, 40.0746f, 0.0f);
    glVertex3f(11.8f, 40.1493f, 0.0f);
    glVertex3f(11.7333f, 40.1493f, 0.0f);
    glVertex3f(11.6667f, 40.2239f, 0.0f);
    glVertex3f(11.6f, 40.2239f, 0.0f);
    glVertex3f(11.5333f, 40.2239f, 0.0f);
    glVertex3f(11.4667f, 40.2239f, 0.0f);
    glVertex3f(11.4667f, 40.1493f, 0.0f);
    glVertex3f(11.4f, 40.1493f, 0.0f);
    glVertex3f(11.4f, 40.0746f, 0.0f);
    glVertex3f(11.4f, 40.0f, 0.0f);
    glVertex3f(11.3333f, 40.0f, 0.0f);
    glVertex3f(11.2667f, 40.0f, 0.0f);
    glVertex3f(11.2f, 40.0f, 0.0f);
    glVertex3f(11.1333f, 40.0f, 0.0f);
    glVertex3f(11.0667f, 40.0f, 0.0f);
    glVertex3f(11.0f, 40.0f, 0.0f);
    glVertex3f(10.9333f, 40.0f, 0.0f);
    glVertex3f(10.8667f, 40.0f, 0.0f);
    glVertex3f(10.8f, 40.0f, 0.0f);
    glVertex3f(10.7333f, 40.0f, 0.0f);
    glVertex3f(10.6667f, 40.0f, 0.0f);
    glVertex3f(10.6667f, 40.0746f, 0.0f);
    glVertex3f(10.6f, 40.0746f, 0.0f);
    glVertex3f(10.6f, 40.1493f, 0.0f);
    glVertex3f(10.5333f, 40.1493f, 0.0f);
    glVertex3f(10.5333f, 40.2239f, 0.0f);
    glVertex3f(10.4667f, 40.2239f, 0.0f);
    glVertex3f(10.4667f, 40.2985f, 0.0f);
    glVertex3f(10.4f, 40.2985f, 0.0f);
    glVertex3f(10.4f, 40.3731f, 0.0f);
    glVertex3f(10.4f, 40.4478f, 0.0f);
    glVertex3f(10.4f, 40.5224f, 0.0f);
    glVertex3f(10.4f, 40.597f, 0.0f);
    glVertex3f(10.3333f, 40.597f, 0.0f);
    glVertex3f(10.2667f, 40.597f, 0.0f);
    glVertex3f(10.2667f, 40.6716f, 0.0f);
    glVertex3f(10.2667f, 40.7463f, 0.0f);
    glVertex3f(10.2667f, 40.8209f, 0.0f);
    glVertex3f(10.2f, 40.8209f, 0.0f);
    glVertex3f(10.2f, 40.8955f, 0.0f);
    glVertex3f(10.1333f, 40.8955f, 0.0f);
    glVertex3f(10.0667f, 40.8955f, 0.0f);
    glVertex3f(10.0f, 40.8955f, 0.0f);
    glVertex3f(9.9333f, 40.8955f, 0.0f);
    glVertex3f(9.8667f, 40.8955f, 0.0f);
    glVertex3f(9.8f, 40.8955f, 0.0f);
    glVertex3f(9.8f, 40.9701f, 0.0f);
    glVertex3f(9.7333f, 40.9701f, 0.0f);
    glVertex3f(9.7333f, 41.0448f, 0.0f);
    glVertex3f(9.6667f, 41.0448f, 0.0f);
    glVertex3f(9.6667f, 41.1194f, 0.0f);
    glVertex3f(9.6f, 41.1194f, 0.0f);
    glVertex3f(9.6f, 41.194f, 0.0f);
    glVertex3f(9.5333f, 41.194f, 0.0f);
    glVertex3f(9.4667f, 41.194f, 0.0f);
    glVertex3f(9.4667f, 41.2687f, 0.0f);
    glVertex3f(9.4f, 41.2687f, 0.0f);
    glVertex3f(9.4f, 41.3433f, 0.0f);
    glVertex3f(9.3333f, 41.3433f, 0.0f);
    glVertex3f(9.3333f, 41.4179f, 0.0f);
    glVertex3f(9.2667f, 41.4925f, 0.0f);
    glVertex3f(9.2f, 41.4925f, 0.0f);
    glVertex3f(9.2f, 41.5672f, 0.0f);
    glVertex3f(9.1333f, 41.5672f, 0.0f);
    glVertex3f(9.1333f, 41.6418f, 0.0f);
    glVertex3f(9.1333f, 41.7164f, 0.0f);
    glVertex3f(9.1333f, 41.791f, 0.0f);
    glVertex3f(9.1333f, 41.8657f, 0.0f);
    glVertex3f(9.0667f, 41.8657f, 0.0f);
    glVertex3f(9.0667f, 41.9403f, 0.0f);
    glVertex3f(9.0667f, 42.0149f, 0.0f);
    glVertex3f(9.0667f, 42.0896f, 0.0f);
    glVertex3f(9.0f, 42.0896f, 0.0f);
    glVertex3f(9.0f, 42.1642f, 0.0f);
    glVertex3f(9.0f, 42.2388f, 0.0f);
    glVertex3f(9.0f, 42.3134f, 0.0f);
    glVertex3f(9.0f, 42.3881f, 0.0f);
    glVertex3f(9.0f, 42.4627f, 0.0f);
    glVertex3f(9.0f, 42.5373f, 0.0f);
    glVertex3f(9.0f, 42.6119f, 0.0f);
    glVertex3f(9.0667f, 42.6119f, 0.0f);
    glVertex3f(9.0667f, 42.6866f, 0.0f);
    glVertex3f(9.0667f, 42.7612f, 0.0f);
    glVertex3f(9.1333f, 42.7612f, 0.0f);
    glVertex3f(9.1333f, 42.8358f, 0.0f);
    glVertex3f(9.1333f, 42.9104f, 0.0f);
    glVertex3f(9.2f, 42.9104f, 0.0f);
    glVertex3f(9.2f, 42.9851f, 0.0f);
    glVertex3f(9.2667f, 42.9851f, 0.0f);
    glVertex3f(9.3333f, 42.9851f, 0.0f);
    glVertex3f(9.3333f, 43.0597f, 0.0f);
    glVertex3f(9.4f, 43.0597f, 0.0f);
    glVertex3f(9.4667f, 43.0597f, 0.0f);
    glVertex3f(9.5333f, 43.1343f, 0.0f);
    glVertex3f(9.6f, 43.1343f, 0.0f);
    glVertex3f(9.6f, 43.209f, 0.0f);
    glVertex3f(9.6667f, 43.209f, 0.0f);
    glVertex3f(9.7333f, 43.2836f, 0.0f);
    glVertex3f(9.8f, 43.2836f, 0.0f);
    glVertex3f(9.8667f, 43.2836f, 0.0f);
    glVertex3f(9.8667f, 43.3582f, 0.0f);
    glVertex3f(9.8667f, 43.4328f, 0.0f);
    glVertex3f(9.8667f, 43.5075f, 0.0f);
    glVertex3f(9.9333f, 43.5075f, 0.0f);
    glVertex3f(9.9333f, 43.5821f, 0.0f);
    glVertex3f(9.9333f, 43.6567f, 0.0f);
    glVertex3f(9.9333f, 43.7313f, 0.0f);
    glVertex3f(9.9333f, 43.806f, 0.0f);
    glVertex3f(10.0f, 43.806f, 0.0f);
    glVertex3f(10.0f, 43.8806f, 0.0f);
    glVertex3f(10.0f, 43.9552f, 0.0f);
    glVertex3f(10.0667f, 43.9552f, 0.0f);
    glVertex3f(10.0667f, 44.0299f, 0.0f);
    glVertex3f(10.1333f, 44.0299f, 0.0f);
    glVertex3f(10.1333f, 44.1045f, 0.0f);
    glVertex3f(10.2f, 44.1045f, 0.0f);
    glVertex3f(10.2f, 44.1791f, 0.0f);
    glVertex3f(10.2667f, 44.1791f, 0.0f);
    glVertex3f(10.2667f, 44.2537f, 0.0f);
    glVertex3f(10.3333f, 44.2537f, 0.0f);
    glVertex3f(10.4f, 44.2537f, 0.0f);
    glVertex3f(10.4667f, 44.2537f, 0.0f);
    glVertex3f(10.5333f, 44.2537f, 0.0f);
    glVertex3f(10.6f, 44.2537f, 0.0f);
    glVertex3f(10.6667f, 44.2537f, 0.0f);
    glVertex3f(10.6667f, 44.1791f, 0.0f);
    glVertex3f(10.7333f, 44.1791f, 0.0f);
    glVertex3f(10.8f, 44.1791f, 0.0f);
    glVertex3f(10.8f, 44.1045f, 0.0f);
    glVertex3f(10.8667f, 44.1045f, 0.0f);
    glVertex3f(10.9333f, 44.1045f, 0.0f);
    glVertex3f(10.9333f, 44.0299f, 0.0f);
    glVertex3f(11.0f, 44.0299f, 0.0f);
    glVertex3f(11.0f, 43.9552f, 0.0f);
    glVertex3f(11.0667f, 43.9552f, 0.0f);
    glVertex3f(11.1333f, 43.9552f, 0.0f);
    glVertex3f(11.2f, 43.9552f, 0.0f);
    glVertex3f(11.2f, 43.8806f, 0.0f);
    glVertex3f(11.2667f, 43.8806f, 0.0f);
    glVertex3f(11.3333f, 43.8806f, 0.0f);
    glVertex3f(11.3333f, 43.806f, 0.0f);
    glVertex3f(11.4f, 43.806f, 0.0f);
    glVertex3f(11.4f, 43.7313f, 0.0f);
    glVertex3f(11.4667f, 43.7313f, 0.0f);
    glVertex3f(11.4667f, 43.6567f, 0.0f);
    glVertex3f(11.5333f, 43.6567f, 0.0f);
    glVertex3f(11.5333f, 43.5821f, 0.0f);
    glVertex3f(11.6f, 43.5821f, 0.0f);
    glVertex3f(11.6667f, 43.5821f, 0.0f);
    glVertex3f(11.6667f, 43.6567f, 0.0f);
    glVertex3f(11.7333f, 43.6567f, 0.0f);
    glVertex3f(11.8f, 43.7313f, 0.0f);
    glVertex3f(11.8f, 43.806f, 0.0f);
    glVertex3f(11.8f, 43.8806f, 0.0f);
    glVertex3f(11.8667f, 43.8806f, 0.0f);
    glVertex3f(11.8667f, 43.9552f, 0.0f);
    glVertex3f(11.8667f, 44.0299f, 0.0f);
    glVertex3f(11.9333f, 44.1045f, 0.0f);
    glVertex3f(11.9333f, 44.1791f, 0.0f);
    glVertex3f(12.0f, 44.1791f, 0.0f);
    glVertex3f(12.0667f, 44.1791f, 0.0f);
    glVertex3f(12.0667f, 44.1045f, 0.0f);
    glVertex3f(12.1333f, 44.0299f, 0.0f);
    glVertex3f(12.2f, 44.0299f, 0.0f);
    glVertex3f(12.2f, 43.9552f, 0.0f);
    glVertex3f(12.2667f, 43.9552f, 0.0f);
    glVertex3f(12.2667f, 43.8806f, 0.0f);
    glVertex3f(12.3333f, 43.8806f, 0.0f);
    glVertex3f(12.4f, 43.8806f, 0.0f);
    glVertex3f(12.4f, 43.9552f, 0.0f);
    glVertex3f(12.4667f, 43.9552f, 0.0f);
    glVertex3f(12.4667f, 44.0299f, 0.0f);
    glVertex3f(12.4667f, 44.1045f, 0.0f);
    glVertex3f(12.4667f, 44.1791f, 0.0f);
    glVertex3f(12.5333f, 44.1791f, 0.0f);
    glVertex3f(12.5333f, 44.2537f, 0.0f);
    glVertex3f(12.6f, 44.3284f, 0.0f);
    glVertex3f(12.6f, 44.403f, 0.0f);
    glVertex3f(12.6f, 44.4776f, 0.0f);
    glVertex3f(12.6f, 44.5522f, 0.0f);
    glVertex3f(12.6667f, 44.5522f, 0.0f);
    glVertex3f(12.6667f, 44.6269f, 0.0f);
    glVertex3f(12.6667f, 44.7015f, 0.0f);
    glVertex3f(12.6667f, 44.7761f, 0.0f);
    glVertex3f(12.7333f, 44.7761f, 0.0f);
    glVertex3f(12.7333f, 44.8507f, 0.0f);
    glVertex3f(12.8f, 44.8507f, 0.0f);
    glVertex3f(12.8667f, 44.8507f, 0.0f);
    glVertex3f(12.8667f, 44.9254f, 0.0f);
    glVertex3f(12.9333f, 44.9254f, 0.0f);
    glVertex3f(13.0f, 44.9254f, 0.0f);
    glVertex3f(13.0667f, 44.9254f, 0.0f);
    glVertex3f(13.1333f, 44.9254f, 0.0f);
    glVertex3f(13.1333f, 44.8507f, 0.0f);
    glVertex3f(13.2f, 44.8507f, 0.0f);
    glVertex3f(13.2667f, 44.8507f, 0.0f);
    glVertex3f(13.2667f, 44.7761f, 0.0f);
    glVertex3f(13.3333f, 44.7761f, 0.0f);
    glVertex3f(13.4f, 44.7761f, 0.0f);
    glVertex3f(13.4667f, 44.7761f, 0.0f);
    glVertex3f(13.4667f, 44.7015f, 0.0f);
    glVertex3f(13.5333f, 44.7015f, 0.0f);
    glVertex3f(13.5333f, 44.6269f, 0.0f);
    glVertex3f(13.6f, 44.6269f, 0.0f);
    glVertex3f(13.6f, 44.5522f, 0.0f);
    glVertex3f(13.6667f, 44.5522f, 0.0f);
    glVertex3f(13.6667f, 44.4776f, 0.0f);
    glVertex3f(13.7333f, 44.4776f, 0.0f);
    glVertex3f(13.7333f, 44.403f, 0.0f);
    glVertex3f(13.7333f, 44.3284f, 0.0f);
    glVertex3f(13.8f, 44.3284f, 0.0f);
    glVertex3f(13.8f, 44.2537f, 0.0f);
    glVertex3f(13.8f, 44.1791f, 0.0f);
    glVertex3f(13.8667f, 44.1791f, 0.0f);
    glVertex3f(13.8667f, 44.1045f, 0.0f);
    glVertex3f(13.8667f, 44.0299f, 0.0f);
    glVertex3f(13.8667f, 43.9552f, 0.0f);
    glVertex3f(13.8667f, 43.8806f, 0.0f);
    glVertex3f(13.8667f, 43.806f, 0.0f);
    glVertex3f(13.8667f, 43.7313f, 0.0f);
    glVertex3f(13.8667f, 43.6567f, 0.0f);
    glVertex3f(13.8667f, 43.5821f, 0.0f);
    glVertex3f(13.8667f, 43.5075f, 0.0f);
    glVertex3f(13.8667f, 43.4328f, 0.0f);
    glVertex3f(13.8667f, 43.3582f, 0.0f);
    glVertex3f(13.8667f, 43.2836f, 0.0f);
    glVertex3f(13.9333f, 43.2836f, 0.0f);
    glVertex3f(13.9333f, 43.209f, 0.0f);
    glVertex3f(13.9333f, 43.1343f, 0.0f);
    glVertex3f(13.9333f, 43.0597f, 0.0f);
    glVertex3f(14.0f, 43.0597f, 0.0f);
    glVertex3f(14.0667f, 43.0597f, 0.0f);
    glVertex3f(14.1333f, 43.0597f, 0.0f);
    glVertex3f(14.1333f, 42.9851f, 0.0f);
    glVertex3f(14.2f, 42.9851f, 0.0f);
    glVertex3f(14.2667f, 42.9851f, 0.0f);
    glVertex3f(14.2667f, 42.9104f, 0.0f);
    glVertex3f(14.3333f, 42.9104f, 0.0f);
    glVertex3f(14.3333f, 42.8358f, 0.0f);
    glVertex3f(14.3333f, 42.7612f, 0.0f);
    glVertex3f(14.4f, 42.7612f, 0.0f);
    glVertex3f(14.4f, 42.6866f, 0.0f);
    glVertex3f(14.4667f, 42.6866f, 0.0f);
    glVertex3f(14.5333f, 42.6866f, 0.0f);
    glVertex3f(14.5333f, 42.6119f, 0.0f);
    glVertex3f(14.6f, 42.6119f, 0.0f);
    glVertex3f(14.6667f, 42.5373f, 0.0f);
    glVertex3f(14.6667f, 42.4627f, 0.0f);
    glVertex3f(14.7333f, 42.4627f, 0.0f);
    glVertex3f(14.8f, 42.4627f, 0.0f);
    glVertex3f(14.8f, 42.3881f, 0.0f);
    glVertex3f(14.8667f, 42.3881f, 0.0f);
    glVertex3f(14.9333f, 42.3881f, 0.0f);
    glVertex3f(15.0f, 42.3134f, 0.0f);
    glVertex3f(15.0667f, 42.3134f, 0.0f);
    glVertex3f(15.1333f, 42.3134f, 0.0f);
    glVertex3f(15.1333f, 42.2388f, 0.0f);
    glVertex3f(15.2f, 42.2388f, 0.0f);
    glVertex3f(15.2667f, 42.2388f, 0.0f);
    glVertex3f(15.2667f, 42.1642f, 0.0f);
    glVertex3f(15.3333f, 42.1642f, 0.0f);
    glVertex3f(15.4f, 42.1642f, 0.0f);
    glVertex3f(15.4f, 42.0896f, 0.0f);
    glVertex3f(15.4667f, 42.0896f, 0.0f);
    glVertex3f(15.5333f, 42.0896f, 0.0f);
    glVertex3f(15.5333f, 42.0149f, 0.0f);
    glVertex3f(15.6f, 42.0149f, 0.0f);
    glVertex3f(15.6667f, 42.0149f, 0.0f);
    glVertex3f(15.7333f, 42.0149f, 0.0f);
    glVertex3f(15.8f, 42.0149f, 0.0f);
    glVertex3f(15.8f, 41.9403f, 0.0f);
    glVertex3f(15.8667f, 41.9403f, 0.0f);
    glVertex3f(15.9333f, 41.9403f, 0.0f);
    glVertex3f(15.9333f, 41.8657f, 0.0f);
    glVertex3f(16.0f, 41.8657f, 0.0f);
    glVertex3f(16.0667f, 41.8657f, 0.0f);
    glVertex3f(16.1333f, 41.8657f, 0.0f);
    glVertex3f(16.2f, 41.8657f, 0.0f);
    glVertex3f(16.2f, 41.791f, 0.0f);
    glVertex3f(16.2667f, 41.791f, 0.0f);
    glVertex3f(16.3333f, 41.791f, 0.0f);
    glVertex3f(16.4f, 41.791f, 0.0f);
    glVertex3f(16.4667f, 41.791f, 0.0f);
    glVertex3f(16.4667f, 41.7164f, 0.0f);
    glVertex3f(16.5333f, 41.7164f, 0.0f);
    glVertex3f(16.6f, 41.7164f, 0.0f);
    glVertex3f(16.6667f, 41.7164f, 0.0f);
    glVertex3f(16.7333f, 41.7164f, 0.0f);
    glVertex3f(16.8f, 41.7164f, 0.0f);
    glVertex3f(16.8667f, 41.7164f, 0.0f);
    glVertex3f(16.8667f, 41.6418f, 0.0f);
    glVertex3f(16.9333f, 41.6418f, 0.0f);
    glVertex3f(17.0f, 41.6418f, 0.0f);
    glVertex3f(17.0667f, 41.6418f, 0.0f);
    glVertex3f(17.1333f, 41.6418f, 0.0f);
    glVertex3f(17.2f, 41.6418f, 0.0f);
    glVertex3f(17.2667f, 41.6418f, 0.0f);
    glVertex3f(17.2667f, 41.5672f, 0.0f);
    glVertex3f(17.3333f, 41.5672f, 0.0f);

    glEnd();




//top smoke

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.914, 0.341, 0.039);


    glVertex3f(15.0f, 42.3134f, 0.0f);
    glVertex3f(15.0f, 42.3881f, 0.0f);
    glVertex3f(15.0f, 42.4627f, 0.0f);
    glVertex3f(15.0f, 42.5373f, 0.0f);
    glVertex3f(15.0f, 42.6119f, 0.0f);
    glVertex3f(15.0f, 42.6866f, 0.0f);
    glVertex3f(15.0f, 42.7612f, 0.0f);
    glVertex3f(15.0f, 42.8358f, 0.0f);
    glVertex3f(14.9333f, 42.9104f, 0.0f);
    glVertex3f(14.9333f, 42.9851f, 0.0f);
    glVertex3f(14.8667f, 43.0597f, 0.0f);
    glVertex3f(14.8667f, 43.1343f, 0.0f);
    glVertex3f(14.8f, 43.1343f, 0.0f);
    glVertex3f(14.7333f, 43.209f, 0.0f);
    glVertex3f(14.6667f, 43.2836f, 0.0f);
    glVertex3f(14.6f, 43.2836f, 0.0f);
    glVertex3f(14.5333f, 43.2836f, 0.0f);
    glVertex3f(14.4667f, 43.2836f, 0.0f);
    glVertex3f(14.4f, 43.2836f, 0.0f);
    glVertex3f(14.3333f, 43.2836f, 0.0f);
    glVertex3f(14.2667f, 43.2836f, 0.0f);
    glVertex3f(14.2f, 43.2836f, 0.0f);
    glVertex3f(14.1333f, 43.2836f, 0.0f);
    glVertex3f(14.1333f, 43.209f, 0.0f);
    glVertex3f(14.0667f, 43.209f, 0.0f);
    glVertex3f(14.0f, 43.209f, 0.0f);
    glVertex3f(13.9333f, 43.209f, 0.0f);
    glVertex3f(13.8667f, 43.209f, 0.0f);
    glVertex3f(13.7333f, 43.1343f, 0.0f);
    glVertex3f(13.7333f, 43.0597f, 0.0f);
    glVertex3f(13.6667f, 43.0597f, 0.0f);
    glVertex3f(13.7333f, 43.209f, 0.0f);
    glVertex3f(13.8f, 43.2836f, 0.0f);
    glVertex3f(13.8f, 43.3582f, 0.0f);
    glVertex3f(13.8667f, 43.4328f, 0.0f);
    glVertex3f(13.9333f, 43.5821f, 0.0f);
    glVertex3f(14.0f, 43.5821f, 0.0f);
    glVertex3f(14.0667f, 43.7313f, 0.0f);
    glVertex3f(14.0667f, 43.806f, 0.0f);
    glVertex3f(14.0667f, 43.8806f, 0.0f);
    glVertex3f(14.0667f, 43.9552f, 0.0f);
    glVertex3f(14.0667f, 44.0299f, 0.0f);
    glVertex3f(14.0667f, 44.1045f, 0.0f);
    glVertex3f(14.0f, 44.2537f, 0.0f);
    glVertex3f(13.9333f, 44.3284f, 0.0f);
    glVertex3f(13.8f, 44.403f, 0.0f);
    glVertex3f(13.7333f, 44.403f, 0.0f);
    glVertex3f(13.6667f, 44.403f, 0.0f);
    glVertex3f(13.6f, 44.403f, 0.0f);
    glVertex3f(13.6f, 44.4776f, 0.0f);
    glVertex3f(13.5333f, 44.4776f, 0.0f);
    glVertex3f(13.4667f, 44.4776f, 0.0f);
    glVertex3f(13.4f, 44.5522f, 0.0f);
    glVertex3f(13.3333f, 44.5522f, 0.0f);
    glVertex3f(13.2667f, 44.5522f, 0.0f);
    glVertex3f(13.2f, 44.5522f, 0.0f);
    glVertex3f(13.1333f, 44.5522f, 0.0f);
    glVertex3f(13.0667f, 44.5522f, 0.0f);
    glVertex3f(13.0f, 44.5522f, 0.0f);
    glVertex3f(12.9333f, 44.5522f, 0.0f);
    glVertex3f(12.8667f, 44.5522f, 0.0f);
    glVertex3f(12.8f, 44.5522f, 0.0f);
    glVertex3f(12.7333f, 44.5522f, 0.0f);
    glVertex3f(12.6667f, 44.4776f, 0.0f);
    glVertex3f(12.6f, 44.4776f, 0.0f);
    glVertex3f(12.5333f, 44.4776f, 0.0f);
    glVertex3f(12.4667f, 44.403f, 0.0f);
    glVertex3f(12.4f, 44.403f, 0.0f);
    glVertex3f(12.3333f, 44.3284f, 0.0f);
    glVertex3f(12.2667f, 44.3284f, 0.0f);
    glVertex3f(12.4f, 44.2537f, 0.0f);
    glVertex3f(12.4f, 44.1791f, 0.0f);
    glVertex3f(12.4667f, 44.1791f, 0.0f);
    glVertex3f(12.4667f, 44.1045f, 0.0f);
    glVertex3f(12.5333f, 44.1045f, 0.0f);
    glVertex3f(12.5333f, 44.1791f, 0.0f);
    glVertex3f(12.4667f, 44.1791f, 0.0f);
    glVertex3f(12.4667f, 44.3284f, 0.0f);
    glVertex3f(12.4f, 44.3284f, 0.0f);
    glVertex3f(12.3333f, 44.403f, 0.0f);
    glVertex3f(12.2667f, 44.403f, 0.0f);
    glVertex3f(12.2f, 44.403f, 0.0f);
    glVertex3f(12.1333f, 44.403f, 0.0f);
    glVertex3f(12.0667f, 44.403f, 0.0f);
    glVertex3f(12.0f, 44.403f, 0.0f);
    glVertex3f(11.9333f, 44.3284f, 0.0f);
    glVertex3f(11.8667f, 44.3284f, 0.0f);
    glVertex3f(11.8f, 44.3284f, 0.0f);
    glVertex3f(11.8f, 44.2537f, 0.0f);
    glVertex3f(11.7333f, 44.1791f, 0.0f);
    glVertex3f(11.6667f, 44.1791f, 0.0f);
    glVertex3f(11.6f, 44.1045f, 0.0f);
    glVertex3f(11.5333f, 44.0299f, 0.0f);
    glVertex3f(11.4667f, 43.9552f, 0.0f);
    glVertex3f(11.4667f, 43.8806f, 0.0f);
    glVertex3f(11.4667f, 43.806f, 0.0f);
    glVertex3f(11.4f, 43.7313f, 0.0f);
    glVertex3f(11.4f, 43.6567f, 0.0f);
    glVertex3f(11.4f, 43.5821f, 0.0f);
    glVertex3f(11.4f, 43.5075f, 0.0f);
    glVertex3f(11.4f, 43.4328f, 0.0f);
    glVertex3f(11.4f, 43.3582f, 0.0f);
    glVertex3f(11.4f, 43.2836f, 0.0f);
    glVertex3f(11.4f, 43.3582f, 0.0f);
    glVertex3f(11.4f, 43.4328f, 0.0f);
    glVertex3f(11.4f, 43.5075f, 0.0f);
    glVertex3f(11.4f, 43.5821f, 0.0f);
    glVertex3f(11.4f, 43.6567f, 0.0f);
    glVertex3f(11.4f, 43.7313f, 0.0f);
    glVertex3f(11.3333f, 43.8806f, 0.0f);
    glVertex3f(11.3333f, 43.9552f, 0.0f);
    glVertex3f(11.2667f, 43.9552f, 0.0f);
    glVertex3f(11.2667f, 44.0299f, 0.0f);
    glVertex3f(11.1333f, 44.1045f, 0.0f);
    glVertex3f(11.1333f, 44.1791f, 0.0f);
    glVertex3f(11.0667f, 44.1791f, 0.0f);
    glVertex3f(11.0667f, 44.2537f, 0.0f);
    glVertex3f(11.0f, 44.3284f, 0.0f);
    glVertex3f(10.9333f, 44.403f, 0.0f);
    glVertex3f(10.8667f, 44.403f, 0.0f);
    glVertex3f(10.8f, 44.403f, 0.0f);
    glVertex3f(10.7333f, 44.403f, 0.0f);
    glVertex3f(10.6f, 44.403f, 0.0f);
    glVertex3f(10.4667f, 44.403f, 0.0f);
    glVertex3f(10.3333f, 44.403f, 0.0f);
    glVertex3f(10.2667f, 44.403f, 0.0f);
    glVertex3f(10.2f, 44.403f, 0.0f);
    glVertex3f(10.1333f, 44.403f, 0.0f);
    glVertex3f(10.0667f, 44.403f, 0.0f);
    glVertex3f(10.0f, 44.3284f, 0.0f);
    glVertex3f(9.9333f, 44.2537f, 0.0f);
    glVertex3f(9.8667f, 44.1791f, 0.0f);
    glVertex3f(9.8667f, 44.1045f, 0.0f);
    glVertex3f(9.8667f, 44.0299f, 0.0f);
    glVertex3f(9.8667f, 43.9552f, 0.0f);
    glVertex3f(9.8667f, 43.8806f, 0.0f);
    glVertex3f(9.8667f, 43.806f, 0.0f);
    glVertex3f(9.8667f, 43.7313f, 0.0f);
    glVertex3f(9.8667f, 43.6567f, 0.0f);
    glVertex3f(9.8667f, 43.5821f, 0.0f);
    glVertex3f(9.9333f, 43.5075f, 0.0f);
    glVertex3f(9.9333f, 43.4328f, 0.0f);
    glVertex3f(9.9333f, 43.3582f, 0.0f);
    glVertex3f(10.0f, 43.2836f, 0.0f);
    glVertex3f(10.0667f, 43.209f, 0.0f);
    glVertex3f(10.1333f, 43.1343f, 0.0f);
    glVertex3f(10.1333f, 43.0597f, 0.0f);
    glVertex3f(10.0667f, 43.0597f, 0.0f);
    glVertex3f(10.0f, 42.9851f, 0.0f);
    glVertex3f(9.9333f, 42.9851f, 0.0f);
    glVertex3f(9.8667f, 42.9851f, 0.0f);
    glVertex3f(9.8f, 42.9851f, 0.0f);
    glVertex3f(9.7333f, 42.9851f, 0.0f);
    glVertex3f(9.6667f, 42.9851f, 0.0f);
    glVertex3f(9.6f, 42.9104f, 0.0f);
    glVertex3f(9.5333f, 42.9104f, 0.0f);
    glVertex3f(9.4667f, 42.9104f, 0.0f);
    glVertex3f(9.4667f, 42.8358f, 0.0f);
    glVertex3f(9.4f, 42.8358f, 0.0f);
    glVertex3f(9.3333f, 42.8358f, 0.0f);
    glVertex3f(9.2667f, 42.8358f, 0.0f);
    glVertex3f(9.2667f, 42.7612f, 0.0f);
    glVertex3f(9.2f, 42.6119f, 0.0f);
    glVertex3f(9.2f, 42.5373f, 0.0f);
    glVertex3f(9.2f, 42.4627f, 0.0f);
    glVertex3f(9.2f, 42.3881f, 0.0f);
    glVertex3f(9.2f, 42.3134f, 0.0f);
    glVertex3f(9.2f, 42.2388f, 0.0f);
    glVertex3f(9.2f, 42.1642f, 0.0f);
    glVertex3f(9.2f, 42.0896f, 0.0f);
    glVertex3f(9.2f, 42.0149f, 0.0f);
    glVertex3f(9.2f, 41.9403f, 0.0f);
    glVertex3f(9.2f, 41.8657f, 0.0f);
    glVertex3f(9.2667f, 41.791f, 0.0f);
    glVertex3f(9.3333f, 41.7164f, 0.0f);
    glVertex3f(9.4f, 41.6418f, 0.0f);
    glVertex3f(9.5333f, 41.6418f, 0.0f);
    glVertex3f(9.5333f, 41.5672f, 0.0f);
    glVertex3f(9.6f, 41.5672f, 0.0f);
    glVertex3f(9.6667f, 41.5672f, 0.0f);
    glVertex3f(9.7333f, 41.5672f, 0.0f);
    glVertex3f(9.8f, 41.5672f, 0.0f);
    glVertex3f(9.8667f, 41.5672f, 0.0f);
    glVertex3f(9.9333f, 41.5672f, 0.0f);
    glVertex3f(10.0f, 41.5672f, 0.0f);
    glVertex3f(10.0667f, 41.5672f, 0.0f);
    glVertex3f(10.1333f, 41.5672f, 0.0f);
    glVertex3f(10.2f, 41.5672f, 0.0f);
    glVertex3f(10.2667f, 41.5672f, 0.0f);
    glVertex3f(10.3333f, 41.5672f, 0.0f);
    glVertex3f(10.2667f, 41.5672f, 0.0f);
    glVertex3f(10.1333f, 41.4925f, 0.0f);
    glVertex3f(10.0667f, 41.4925f, 0.0f);
    glVertex3f(10.0f, 41.4179f, 0.0f);
    glVertex3f(9.9333f, 41.4179f, 0.0f);
    glVertex3f(9.8667f, 41.4179f, 0.0f);
    glVertex3f(9.8667f, 41.3433f, 0.0f);
    glVertex3f(9.8f, 41.3433f, 0.0f);
    glVertex3f(9.8f, 41.194f, 0.0f);
    glVertex3f(9.8f, 41.1194f, 0.0f);
    glVertex3f(9.7333f, 40.9701f, 0.0f);
    glVertex3f(9.6667f, 40.8955f, 0.0f);
    glVertex3f(9.6667f, 40.8209f, 0.0f);
    glVertex3f(9.6667f, 40.7463f, 0.0f);
    glVertex3f(9.6667f, 40.6716f, 0.0f);
    glVertex3f(9.6667f, 40.5224f, 0.0f);
    glVertex3f(9.6667f, 40.3731f, 0.0f);
    glVertex3f(9.6667f, 40.2985f, 0.0f);
    glVertex3f(9.6667f, 40.2239f, 0.0f);
    glVertex3f(9.6667f, 40.1493f, 0.0f);
    glVertex3f(9.7333f, 40.0746f, 0.0f);
    glVertex3f(9.7333f, 40.0f, 0.0f);
    glVertex3f(9.8f, 39.9254f, 0.0f);
    glVertex3f(9.8667f, 39.9254f, 0.0f);
    glVertex3f(9.9333f, 39.9254f, 0.0f);
    glVertex3f(10.0f, 39.9254f, 0.0f);
    glVertex3f(10.0667f, 39.9254f, 0.0f);
    glVertex3f(10.1333f, 39.9254f, 0.0f);
    glVertex3f(10.2f, 39.8507f, 0.0f);
    glVertex3f(10.2667f, 39.8507f, 0.0f);
    glVertex3f(10.3333f, 39.8507f, 0.0f);
    glVertex3f(10.4f, 39.8507f, 0.0f);
    glVertex3f(10.4667f, 39.8507f, 0.0f);
    glVertex3f(10.5333f, 39.8507f, 0.0f);
    glVertex3f(10.6f, 39.8507f, 0.0f);
    glVertex3f(10.6667f, 39.8507f, 0.0f);
    glVertex3f(10.7333f, 39.8507f, 0.0f);
    glVertex3f(10.8f, 39.8507f, 0.0f);
    glVertex3f(10.8667f, 39.8507f, 0.0f);
    glVertex3f(10.9333f, 39.8507f, 0.0f);
    glVertex3f(11.0f, 39.8507f, 0.0f);
    glVertex3f(11.0667f, 39.9254f, 0.0f);
    glVertex3f(11.1333f, 39.9254f, 0.0f);
    glVertex3f(11.2f, 39.9254f, 0.0f);
    glVertex3f(11.2f, 40.0f, 0.0f);
    glVertex3f(11.3333f, 40.0746f, 0.0f);
    glVertex3f(11.4f, 40.0746f, 0.0f);
    glVertex3f(11.4667f, 40.0746f, 0.0f);
    glVertex3f(11.4667f, 40.1493f, 0.0f);
    glVertex3f(11.5333f, 40.1493f, 0.0f);
    glVertex3f(11.6f, 40.1493f, 0.0f);
    glVertex3f(11.6667f, 40.2239f, 0.0f);
    glVertex3f(11.7333f, 40.2239f, 0.0f);
    glVertex3f(11.8667f, 40.1493f, 0.0f);
    glVertex3f(11.8667f, 40.0f, 0.0f);
    glVertex3f(11.8667f, 39.9254f, 0.0f);
    glVertex3f(11.8667f, 39.8507f, 0.0f);
    glVertex3f(11.8667f, 39.7761f, 0.0f);
    glVertex3f(11.9333f, 39.7015f, 0.0f);
    glVertex3f(12.0f, 39.6269f, 0.0f);
    glVertex3f(12.0667f, 39.6269f, 0.0f);
    glVertex3f(12.0667f, 39.5522f, 0.0f);
    glVertex3f(12.0667f, 39.4776f, 0.0f);
    glVertex3f(12.1333f, 39.4776f, 0.0f);
    glVertex3f(12.2f, 39.4776f, 0.0f);
    glVertex3f(12.2667f, 39.4776f, 0.0f);
    glVertex3f(12.3333f, 39.4776f, 0.0f);
    glVertex3f(12.4f, 39.4776f, 0.0f);
    glVertex3f(12.4667f, 39.4776f, 0.0f);
    glVertex3f(12.5333f, 39.4776f, 0.0f);
    glVertex3f(12.6f, 39.4776f, 0.0f);
    glVertex3f(12.6667f, 39.4776f, 0.0f);
    glVertex3f(12.7333f, 39.4776f, 0.0f);
    glVertex3f(12.7333f, 39.5522f, 0.0f);
    glVertex3f(12.8f, 39.5522f, 0.0f);
    glVertex3f(12.8667f, 39.5522f, 0.0f);
    glVertex3f(12.9333f, 39.6269f, 0.0f);
    glVertex3f(13.0f, 39.6269f, 0.0f);
    glVertex3f(13.0667f, 39.6269f, 0.0f);
    glVertex3f(13.1333f, 39.7015f, 0.0f);
    glVertex3f(13.1333f, 39.7761f, 0.0f);
    glVertex3f(13.0667f, 39.7761f, 0.0f);
    glVertex3f(13.0667f, 39.9254f, 0.0f);
    glVertex3f(13.0667f, 40.0f, 0.0f);
    glVertex3f(13.0f, 40.0f, 0.0f);
    glVertex3f(12.9333f, 40.0746f, 0.0f);
    glVertex3f(12.9333f, 40.1493f, 0.0f);
    glVertex3f(12.9333f, 40.2239f, 0.0f);
    glVertex3f(13.0f, 40.2239f, 0.0f);
    glVertex3f(13.0667f, 40.2239f, 0.0f);
    glVertex3f(13.1333f, 40.2239f, 0.0f);
    glVertex3f(13.2f, 40.2239f, 0.0f);
    glVertex3f(13.2667f, 40.2239f, 0.0f);
    glVertex3f(13.3333f, 40.2239f, 0.0f);
    glVertex3f(13.4f, 40.2239f, 0.0f);
    glVertex3f(13.4667f, 40.1493f, 0.0f);
    glVertex3f(13.5333f, 40.1493f, 0.0f);
    glVertex3f(13.6f, 40.1493f, 0.0f);
    glVertex3f(13.6667f, 40.1493f, 0.0f);
    glVertex3f(13.7333f, 40.1493f, 0.0f);
    glVertex3f(13.8f, 40.1493f, 0.0f);
    glVertex3f(13.8667f, 40.1493f, 0.0f);
    glVertex3f(13.9333f, 40.1493f, 0.0f);
    glVertex3f(14.0f, 40.1493f, 0.0f);
    glVertex3f(14.0667f, 40.1493f, 0.0f);
    glVertex3f(14.1333f, 40.2239f, 0.0f);
    glVertex3f(14.2f, 40.2239f, 0.0f);
    glVertex3f(14.2667f, 40.2239f, 0.0f);
    glVertex3f(14.3333f, 40.2239f, 0.0f);
    glVertex3f(14.4f, 40.2239f, 0.0f);
    glVertex3f(14.4667f, 40.2985f, 0.0f);
    glVertex3f(14.5333f, 40.3731f, 0.0f);
    glVertex3f(14.6f, 40.4478f, 0.0f);
    glVertex3f(14.6667f, 40.4478f, 0.0f);
    glVertex3f(14.6667f, 40.597f, 0.0f);
    glVertex3f(14.6667f, 40.6716f, 0.0f);
    glVertex3f(14.6667f, 40.7463f, 0.0f);
    glVertex3f(14.6667f, 40.8209f, 0.0f);
    glVertex3f(14.6667f, 40.9701f, 0.0f);
    glVertex3f(14.6667f, 41.0448f, 0.0f);
    glVertex3f(14.6f, 41.1194f, 0.0f);
    glVertex3f(14.6f, 41.194f, 0.0f);
    glVertex3f(14.6f, 41.2687f, 0.0f);
    glVertex3f(14.6667f, 41.2687f, 0.0f);
    glVertex3f(14.7333f, 41.2687f, 0.0f);
    glVertex3f(14.8f, 41.2687f, 0.0f);
    glVertex3f(14.8667f, 41.2687f, 0.0f);
    glVertex3f(14.9333f, 41.2687f, 0.0f);
    glVertex3f(15.0667f, 41.3433f, 0.0f);
    glVertex3f(15.1333f, 41.3433f, 0.0f);
    glVertex3f(15.2667f, 41.3433f, 0.0f);
    glVertex3f(15.3333f, 41.3433f, 0.0f);
    glVertex3f(15.4f, 41.3433f, 0.0f);
    glVertex3f(15.4667f, 41.4179f, 0.0f);
    glVertex3f(15.5333f, 41.4179f, 0.0f);
    glVertex3f(15.6f, 41.4179f, 0.0f);
    glVertex3f(15.6667f, 41.4179f, 0.0f);
    glVertex3f(15.7333f, 41.4925f, 0.0f);
    glVertex3f(15.8f, 41.4925f, 0.0f);
    glVertex3f(15.8667f, 41.4925f, 0.0f);
    glVertex3f(15.9333f, 41.5672f, 0.0f);
    glVertex3f(16.0f, 41.5672f, 0.0f);
    glVertex3f(16.0667f, 41.5672f, 0.0f);
    glVertex3f(16.1333f, 41.5672f, 0.0f);
    glVertex3f(16.2667f, 41.5672f, 0.0f);
    glVertex3f(16.3333f, 41.5672f, 0.0f);
    glVertex3f(16.4f, 41.5672f, 0.0f);
    glVertex3f(16.5333f, 41.6418f, 0.0f);
    glVertex3f(16.6f, 41.7164f, 0.0f);
    glVertex3f(16.6667f, 41.7164f, 0.0f);
    glVertex3f(16.7333f, 41.7164f, 0.0f);
    glVertex3f(16.8f, 41.7164f, 0.0f);
    glVertex3f(16.8667f, 41.7164f, 0.0f);
    glVertex3f(16.9333f, 41.7164f, 0.0f);
    glVertex3f(16.9333f, 41.791f, 0.0f);
    glVertex3f(17.0f, 41.791f, 0.0f);
    glVertex3f(17.0667f, 41.791f, 0.0f);
    glVertex3f(17.1333f, 41.791f, 0.0f);
    glVertex3f(17.2f, 41.791f, 0.0f);
    glVertex3f(17.2667f, 41.791f, 0.0f);
    glVertex3f(17.3333f, 41.791f, 0.0f);
    glVertex3f(17.4f, 41.791f, 0.0f);
    glVertex3f(17.4667f, 41.791f, 0.0f);
    glVertex3f(17.5333f, 41.791f, 0.0f);
    glVertex3f(17.6f, 41.791f, 0.0f);
    glVertex3f(17.6667f, 41.791f, 0.0f);
    glVertex3f(17.7333f, 41.791f, 0.0f);
    glVertex3f(17.8f, 41.791f, 0.0f);
    glVertex3f(17.7333f, 41.791f, 0.0f);
    glVertex3f(17.6667f, 41.791f, 0.0f);
    glVertex3f(17.6f, 41.791f, 0.0f);
    glVertex3f(17.5333f, 41.791f, 0.0f);
    glVertex3f(17.4667f, 41.791f, 0.0f);
    glVertex3f(17.4f, 41.791f, 0.0f);
    glVertex3f(17.3333f, 41.791f, 0.0f);
    glVertex3f(17.2667f, 41.791f, 0.0f);
    glVertex3f(17.2f, 41.791f, 0.0f);
    glVertex3f(17.1333f, 41.791f, 0.0f);
    glVertex3f(17.0667f, 41.791f, 0.0f);
    glVertex3f(17.0f, 41.791f, 0.0f);
    glVertex3f(16.9333f, 41.791f, 0.0f);
    glVertex3f(16.8667f, 41.791f, 0.0f);
    glVertex3f(16.8f, 41.791f, 0.0f);
    glVertex3f(16.7333f, 41.791f, 0.0f);
    glVertex3f(16.6667f, 41.791f, 0.0f);
    glVertex3f(16.6f, 41.8657f, 0.0f);
    glVertex3f(16.6f, 41.9403f, 0.0f);
    glVertex3f(16.5333f, 41.9403f, 0.0f);
    glVertex3f(16.4667f, 41.9403f, 0.0f);
    glVertex3f(16.4f, 41.9403f, 0.0f);
    glVertex3f(16.3333f, 41.9403f, 0.0f);
    glVertex3f(16.2667f, 41.9403f, 0.0f);
    glVertex3f(16.2f, 41.9403f, 0.0f);
    glVertex3f(16.1333f, 42.0149f, 0.0f);
    glVertex3f(16.0667f, 42.0149f, 0.0f);
    glVertex3f(16.0f, 42.0149f, 0.0f);
    glVertex3f(15.9333f, 42.0149f, 0.0f);
    glVertex3f(15.8667f, 42.0149f, 0.0f);
    glVertex3f(15.8f, 42.0896f, 0.0f);
    glVertex3f(15.8f, 42.1642f, 0.0f);
    glVertex3f(15.6667f, 42.1642f, 0.0f);
    glVertex3f(15.6f, 42.2388f, 0.0f);
    glVertex3f(15.5333f, 42.2388f, 0.0f);
    glVertex3f(15.4667f, 42.2388f, 0.0f);
    glVertex3f(15.4f, 42.2388f, 0.0f);
    glVertex3f(15.4f, 42.3134f, 0.0f);
    glVertex3f(15.3333f, 42.3881f, 0.0f);
    glVertex3f(15.2667f, 42.3881f, 0.0f);
    glVertex3f(15.2f, 42.3881f, 0.0f);
    glVertex3f(15.1333f, 42.3881f, 0.0f);
    glVertex3f(15.0667f, 42.3881f, 0.0f);
    glVertex3f(15.0f, 42.3881f, 0.0f);
    glVertex3f(14.9333f, 42.3881f, 0.0f);
    glVertex3f(14.8667f, 42.3881f, 0.0f);



    glEnd();



//rocket base
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.4, 0.0);
    glVertex3f(17.9333f, 41.194f, 0.0f);
    glVertex3f(18.0667f, 42.0149f, 0.0f);
    glVertex3f(17.5333f, 42.5373f, 0.0f);
    glVertex3f(17.9333f, 43.209f, 0.0f);
    glVertex3f(19.0f, 42.6119f, 0.0f);
    glVertex3f(21.5333f, 42.7612f, 0.0f);
    glVertex3f(23.5333f, 42.3134f, 0.0f);
    glVertex3f(24.3333f, 41.7164f, 0.0f);
    glVertex3f(22.8667f, 40.8209f, 0.0f);
    glVertex3f(21.6667f, 40.597f, 0.0f);
    glVertex3f(19.6667f, 40.597f, 0.0f);
    glVertex3f(19.1333f, 40.597f, 0.0f);
    glVertex3f(18.2f, 40.0f, 0.0f);
    glVertex3f(17.8f, 40.5224f, 0.0f);
    glVertex3f(17.7333f, 40.8955f, 0.0f);
    glVertex3f(17.8667f, 40.8955f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.4, 0.0);
    glVertex3f(19.0667f, 40.2239f, 0.0f);
    glVertex3f(21.0667f, 40.3731f, 0.0f);
    glVertex3f(19.2f, 38.8806f, 0.0f);

    glVertex3f(19.1333f, 43.1343f, 0.0f);
    glVertex3f(19.1333f, 44.4776f, 0.0f);
    glVertex3f(21.2f, 43.0597f, 0.0f);

    glEnd();


    glColor3f(0.875, 0.329, 0.0);
    drawCircle(21.3333, 41.7164, 0.5);



//rocket end





    glPopMatrix();
    rocket_x += .006;
    if (rocket_x > 40)
        rocket_x = -50;
    glutPostRedisplay();


}






//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬CLOUDS¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬




void clouds()
{

    glPushMatrix();
    glTranslatef(cx, 0, 0);



    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬   CLOUD - 1 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.26, 0.45, 0.55); // cloud color and center point to draw all the triangle
    glVertex3f(6.4f, 38.7313f, 0.0f);

    glVertex3f(3.0667f, 37.2388f, 0.0f);
    glVertex3f(3.2f, 37.1642f, 0.0f);
    glVertex3f(3.4f, 37.0896f, 0.0f);
    glVertex3f(3.5333f, 37.0896f, 0.0f);
    glVertex3f(3.8f, 37.0896f, 0.0f);
    glVertex3f(4.1333f, 37.0896f, 0.0f);
    glVertex3f(4.5333f, 37.0896f, 0.0f);
    glVertex3f(4.9333f, 37.0896f, 0.0f);
    glVertex3f(5.3333f, 37.0896f, 0.0f);
    glVertex3f(5.7333f, 37.0896f, 0.0f);
    glVertex3f(6.1333f, 37.0896f, 0.0f);
    glVertex3f(6.4f, 37.0896f, 0.0f);
    glVertex3f(6.6667f, 37.0896f, 0.0f);
    glVertex3f(6.8667f, 37.0896f, 0.0f);
    glVertex3f(7.1333f, 37.0896f, 0.0f);
    glVertex3f(7.3333f, 37.0896f, 0.0f);
    glVertex3f(7.5333f, 37.0896f, 0.0f);
    glVertex3f(7.7333f, 37.0896f, 0.0f);
    glVertex3f(7.8667f, 37.0896f, 0.0f);
    glVertex3f(8.0667f, 37.0896f, 0.0f);
    glVertex3f(8.2667f, 37.0896f, 0.0f);
    glVertex3f(8.4667f, 37.0896f, 0.0f);
    glVertex3f(8.7333f, 37.0896f, 0.0f);
    glVertex3f(8.9333f, 37.0896f, 0.0f);
    glVertex3f(9.1333f, 37.0896f, 0.0f);
    glVertex3f(9.3333f, 37.0896f, 0.0f);
    glVertex3f(9.4667f, 37.0896f, 0.0f);
    glVertex3f(9.6667f, 37.0896f, 0.0f);
    glVertex3f(9.8667f, 37.0896f, 0.0f);
    glVertex3f(10.1333f, 37.0896f, 0.0f);
    glVertex3f(10.5333f, 37.0896f, 0.0f);
    glVertex3f(10.8f, 37.0896f, 0.0f);
    glVertex3f(11.0667f, 37.0896f, 0.0f);
    glVertex3f(11.4f, 37.0896f, 0.0f);
    glVertex3f(11.6667f, 37.0896f, 0.0f);
    glVertex3f(12.0f, 37.0896f, 0.0f);
    glVertex3f(12.2f, 37.0896f, 0.0f);
    glVertex3f(12.4f, 37.0896f, 0.0f);
    glVertex3f(12.4667f, 37.0896f, 0.0f);
    glVertex3f(12.5333f, 37.0896f, 0.0f);
    glVertex3f(12.6f, 37.0896f, 0.0f);
    glVertex3f(12.7333f, 37.0896f, 0.0f);
    glVertex3f(12.8f, 37.0896f, 0.0f);
    glVertex3f(12.8667f, 37.0896f, 0.0f);
    glVertex3f(12.9333f, 37.0896f, 0.0f);
    glVertex3f(13.0f, 37.0896f, 0.0f);
    glVertex3f(13.0667f, 37.0896f, 0.0f);
    glVertex3f(13.2f, 37.0896f, 0.0f);
    glVertex3f(13.3333f, 37.0896f, 0.0f);
    glVertex3f(13.5333f, 37.0896f, 0.0f);
    glVertex3f(13.7333f, 37.0896f, 0.0f);
    glVertex3f(13.8667f, 37.0896f, 0.0f);
    glVertex3f(13.9333f, 37.0896f, 0.0f);
    glVertex3f(14.0f, 37.0896f, 0.0f);
    glVertex3f(14.0667f, 37.0896f, 0.0f);
    glVertex3f(14.1333f, 37.0896f, 0.0f);
    glVertex3f(14.2f, 37.0896f, 0.0f);
    glVertex3f(14.2667f, 37.1642f, 0.0f);
    glVertex3f(14.2667f, 37.2388f, 0.0f);
    glVertex3f(14.2667f, 37.3134f, 0.0f);
    glVertex3f(14.2667f, 37.3881f, 0.0f);
    glVertex3f(14.2667f, 37.5373f, 0.0f);
    glVertex3f(14.2667f, 37.6866f, 0.0f);
    glVertex3f(14.2667f, 37.7612f, 0.0f);
    glVertex3f(14.2667f, 37.9104f, 0.0f);
    glVertex3f(14.2f, 38.0597f, 0.0f);
    glVertex3f(14.1333f, 38.209f, 0.0f);
    glVertex3f(14.1333f, 38.3582f, 0.0f);
    glVertex3f(14.0667f, 38.4328f, 0.0f);
    glVertex3f(14.0667f, 38.5075f, 0.0f);
    glVertex3f(14.0f, 38.5821f, 0.0f);
    glVertex3f(13.9333f, 38.6567f, 0.0f);
    glVertex3f(13.8667f, 38.7313f, 0.0f);
    glVertex3f(13.8f, 38.806f, 0.0f);
    glVertex3f(13.7333f, 38.8806f, 0.0f);
    glVertex3f(13.6f, 38.8806f, 0.0f);
    glVertex3f(13.5333f, 38.8806f, 0.0f);
    glVertex3f(13.4667f, 38.8806f, 0.0f);
    glVertex3f(13.4f, 38.9552f, 0.0f);
    glVertex3f(13.3333f, 39.0299f, 0.0f);
    glVertex3f(13.2667f, 39.0299f, 0.0f);
    glVertex3f(13.2f, 39.0299f, 0.0f);
    glVertex3f(13.1333f, 39.0299f, 0.0f);
    glVertex3f(13.0667f, 39.0299f, 0.0f);
    glVertex3f(13.0f, 39.0299f, 0.0f);
    glVertex3f(12.9333f, 39.0299f, 0.0f);
    glVertex3f(12.8f, 38.9552f, 0.0f);
    glVertex3f(12.7333f, 38.8806f, 0.0f);
    glVertex3f(12.6f, 38.8806f, 0.0f);
    glVertex3f(12.4667f, 38.806f, 0.0f);
    glVertex3f(12.4f, 38.7313f, 0.0f);
    glVertex3f(12.3333f, 38.7313f, 0.0f);
    glVertex3f(12.2667f, 38.806f, 0.0f);
    glVertex3f(12.2667f, 38.8806f, 0.0f);
    glVertex3f(12.2667f, 38.9552f, 0.0f);
    glVertex3f(12.2f, 39.0299f, 0.0f);
    glVertex3f(12.2f, 39.1045f, 0.0f);
    glVertex3f(12.2f, 39.1791f, 0.0f);
    glVertex3f(12.1333f, 39.3284f, 0.0f);
    glVertex3f(12.1333f, 39.403f, 0.0f);
    glVertex3f(12.0667f, 39.4776f, 0.0f);
    glVertex3f(12.0f, 39.6269f, 0.0f);
    glVertex3f(12.0f, 39.7015f, 0.0f);
    glVertex3f(11.9333f, 39.7761f, 0.0f);
    glVertex3f(11.8667f, 39.8507f, 0.0f);
    glVertex3f(11.8f, 39.9254f, 0.0f);
    glVertex3f(11.8f, 40.0f, 0.0f);
    glVertex3f(11.7333f, 40.0746f, 0.0f);
    glVertex3f(11.7333f, 40.1493f, 0.0f);
    glVertex3f(11.6f, 40.1493f, 0.0f);
    glVertex3f(11.5333f, 40.2239f, 0.0f);
    glVertex3f(11.4667f, 40.2985f, 0.0f);
    glVertex3f(11.4f, 40.4478f, 0.0f);
    glVertex3f(11.3333f, 40.4478f, 0.0f);
    glVertex3f(11.1333f, 40.597f, 0.0f);
    glVertex3f(11.0f, 40.6716f, 0.0f);
    glVertex3f(10.8667f, 40.6716f, 0.0f);
    glVertex3f(10.8f, 40.8209f, 0.0f);
    glVertex3f(10.6667f, 40.8955f, 0.0f);
    glVertex3f(10.6f, 40.9701f, 0.0f);
    glVertex3f(10.4667f, 41.0448f, 0.0f);
    glVertex3f(10.3333f, 41.0448f, 0.0f);
    glVertex3f(10.2f, 41.1194f, 0.0f);
    glVertex3f(10.0667f, 41.194f, 0.0f);
    glVertex3f(10.0f, 41.194f, 0.0f);
    glVertex3f(9.8667f, 41.194f, 0.0f);
    glVertex3f(9.7333f, 41.2687f, 0.0f);
    glVertex3f(9.6667f, 41.2687f, 0.0f);
    glVertex3f(9.6f, 41.2687f, 0.0f);
    glVertex3f(9.5333f, 41.2687f, 0.0f);
    glVertex3f(9.4667f, 41.2687f, 0.0f);
    glVertex3f(9.4f, 41.2687f, 0.0f);
    glVertex3f(9.3333f, 41.194f, 0.0f);
    glVertex3f(9.2667f, 41.1194f, 0.0f);
    glVertex3f(9.2f, 41.1194f, 0.0f);
    glVertex3f(9.0667f, 41.0448f, 0.0f);
    glVertex3f(9.0667f, 40.9701f, 0.0f);
    glVertex3f(9.0f, 40.9701f, 0.0f);
    glVertex3f(9.0f, 40.8955f, 0.0f);
    glVertex3f(9.0f, 40.8209f, 0.0f);
    glVertex3f(8.9333f, 40.7463f, 0.0f);
    glVertex3f(8.9333f, 40.6716f, 0.0f);
    glVertex3f(8.9333f, 40.597f, 0.0f);
    glVertex3f(8.8667f, 40.4478f, 0.0f);
    glVertex3f(8.8f, 40.4478f, 0.0f);
    glVertex3f(8.8f, 40.2985f, 0.0f);
    glVertex3f(8.7333f, 40.2239f, 0.0f);
    glVertex3f(8.7333f, 40.1493f, 0.0f);
    glVertex3f(8.7333f, 40.2239f, 0.0f);
    glVertex3f(8.6667f, 40.2985f, 0.0f);
    glVertex3f(8.6667f, 40.3731f, 0.0f);
    glVertex3f(8.6667f, 40.5224f, 0.0f);
    glVertex3f(8.6f, 40.6716f, 0.0f);
    glVertex3f(8.6f, 40.7463f, 0.0f);
    glVertex3f(8.5333f, 40.8955f, 0.0f);
    glVertex3f(8.5333f, 41.1194f, 0.0f);
    glVertex3f(8.4667f, 41.2687f, 0.0f);
    glVertex3f(8.4f, 41.3433f, 0.0f);
    glVertex3f(8.4f, 41.4925f, 0.0f);
    glVertex3f(8.3333f, 41.6418f, 0.0f);
    glVertex3f(8.2667f, 41.791f, 0.0f);
    glVertex3f(8.2f, 41.8657f, 0.0f);
    glVertex3f(8.2f, 42.0149f, 0.0f);
    glVertex3f(8.1333f, 42.0896f, 0.0f);
    glVertex3f(8.0667f, 42.1642f, 0.0f);
    glVertex3f(8.0667f, 42.3134f, 0.0f);
    glVertex3f(8.0f, 42.3881f, 0.0f);
    glVertex3f(7.9333f, 42.4627f, 0.0f);
    glVertex3f(7.8667f, 42.6119f, 0.0f);
    glVertex3f(7.8f, 42.6866f, 0.0f);
    glVertex3f(7.8f, 42.8358f, 0.0f);
    glVertex3f(7.6667f, 42.9104f, 0.0f);
    glVertex3f(7.6f, 42.9851f, 0.0f);
    glVertex3f(7.5333f, 43.1343f, 0.0f);
    glVertex3f(7.4667f, 43.2836f, 0.0f);
    glVertex3f(7.2667f, 43.4328f, 0.0f);
    glVertex3f(7.1333f, 43.5075f, 0.0f);
    glVertex3f(7.0f, 43.6567f, 0.0f);
    glVertex3f(6.8f, 43.7313f, 0.0f);
    glVertex3f(6.5333f, 43.8806f, 0.0f);
    glVertex3f(6.3333f, 43.9552f, 0.0f);
    glVertex3f(6.1333f, 44.0299f, 0.0f);
    glVertex3f(5.9333f, 44.1045f, 0.0f);
    glVertex3f(5.7333f, 44.2537f, 0.0f);
    glVertex3f(5.5333f, 44.2537f, 0.0f);
    glVertex3f(5.4f, 44.3284f, 0.0f);
    glVertex3f(5.2667f, 44.3284f, 0.0f);
    glVertex3f(5.0667f, 44.403f, 0.0f);
    glVertex3f(4.9333f, 44.403f, 0.0f);
    glVertex3f(4.8f, 44.403f, 0.0f);
    glVertex3f(4.6667f, 44.403f, 0.0f);
    glVertex3f(4.5333f, 44.403f, 0.0f);
    glVertex3f(4.2667f, 44.3284f, 0.0f);
    glVertex3f(4.1333f, 44.3284f, 0.0f);
    glVertex3f(3.8667f, 44.2537f, 0.0f);
    glVertex3f(3.6f, 44.1791f, 0.0f);
    glVertex3f(3.4667f, 44.1791f, 0.0f);
    glVertex3f(3.4f, 44.1791f, 0.0f);
    glVertex3f(3.2f, 44.1045f, 0.0f);
    glVertex3f(3.1333f, 44.0299f, 0.0f);
    glVertex3f(3.0f, 44.0299f, 0.0f);
    glVertex3f(2.8667f, 43.9552f, 0.0f);
    glVertex3f(2.8f, 43.8806f, 0.0f);
    glVertex3f(2.7333f, 43.8806f, 0.0f);
    glVertex3f(2.6667f, 43.806f, 0.0f);
    glVertex3f(2.6f, 43.7313f, 0.0f);
    glVertex3f(2.6f, 43.6567f, 0.0f);
    glVertex3f(2.6f, 43.5075f, 0.0f);
    glVertex3f(2.5333f, 43.5075f, 0.0f);
    glVertex3f(2.5333f, 43.3582f, 0.0f);
    glVertex3f(2.4667f, 43.2836f, 0.0f);
    glVertex3f(2.4f, 43.209f, 0.0f);
    glVertex3f(2.4f, 43.1343f, 0.0f);
    glVertex3f(2.4f, 42.9851f, 0.0f);
    glVertex3f(2.4f, 42.8358f, 0.0f);
    glVertex3f(2.4f, 42.7612f, 0.0f);
    glVertex3f(2.3333f, 42.6119f, 0.0f);
    glVertex3f(2.2667f, 42.4627f, 0.0f);
    glVertex3f(2.2667f, 42.3881f, 0.0f);
    glVertex3f(2.2667f, 42.2388f, 0.0f);
    glVertex3f(2.2667f, 42.0896f, 0.0f);
    glVertex3f(2.2667f, 41.9403f, 0.0f);
    glVertex3f(2.2667f, 41.8657f, 0.0f);
    glVertex3f(2.2667f, 41.7164f, 0.0f);
    glVertex3f(2.2667f, 41.4925f, 0.0f);
    glVertex3f(2.2667f, 41.3433f, 0.0f);
    glVertex3f(2.3333f, 41.1194f, 0.0f);
    glVertex3f(2.3333f, 40.9701f, 0.0f);
    glVertex3f(2.4f, 40.7463f, 0.0f);
    glVertex3f(2.4f, 40.6716f, 0.0f);
    glVertex3f(2.4f, 40.5224f, 0.0f);
    glVertex3f(2.4f, 40.3731f, 0.0f);
    glVertex3f(2.4667f, 40.2985f, 0.0f);
    glVertex3f(2.4667f, 40.2239f, 0.0f);
    glVertex3f(2.5333f, 40.1493f, 0.0f);
    glVertex3f(2.5333f, 40.0f, 0.0f);
    glVertex3f(2.5333f, 39.9254f, 0.0f);
    glVertex3f(2.5333f, 39.8507f, 0.0f);
    glVertex3f(2.5333f, 39.7761f, 0.0f);
    glVertex3f(2.5333f, 39.7015f, 0.0f);
    glVertex3f(2.6f, 39.5522f, 0.0f);
    glVertex3f(2.6f, 39.4776f, 0.0f);
    glVertex3f(2.6667f, 39.3284f, 0.0f);
    glVertex3f(2.7333f, 39.2537f, 0.0f);
    glVertex3f(2.6667f, 39.3284f, 0.0f);
    glVertex3f(2.6f, 39.3284f, 0.0f);
    glVertex3f(2.5333f, 39.403f, 0.0f);
    glVertex3f(2.5333f, 39.4776f, 0.0f);
    glVertex3f(2.4667f, 39.4776f, 0.0f);
    glVertex3f(2.3333f, 39.5522f, 0.0f);
    glVertex3f(2.2f, 39.6269f, 0.0f);
    glVertex3f(2.1333f, 39.7015f, 0.0f);
    glVertex3f(2.0f, 39.7761f, 0.0f);
    glVertex3f(1.8667f, 39.7015f, 0.0f);
    glVertex3f(1.8f, 39.6269f, 0.0f);
    glVertex3f(1.7333f, 39.6269f, 0.0f);
    glVertex3f(1.7333f, 39.5522f, 0.0f);
    glVertex3f(1.6667f, 39.4776f, 0.0f);
    glVertex3f(1.6f, 39.4776f, 0.0f);
    glVertex3f(1.6f, 39.403f, 0.0f);
    glVertex3f(1.5333f, 39.3284f, 0.0f);
    glVertex3f(1.5333f, 39.2537f, 0.0f);
    glVertex3f(1.4667f, 39.2537f, 0.0f);
    glVertex3f(1.4667f, 39.1791f, 0.0f);
    glVertex3f(1.4667f, 39.1045f, 0.0f);
    glVertex3f(1.4667f, 38.9552f, 0.0f);
    glVertex3f(1.4f, 38.8806f, 0.0f);
    glVertex3f(1.4f, 38.806f, 0.0f);
    glVertex3f(1.4f, 38.7313f, 0.0f);
    glVertex3f(1.4f, 38.6567f, 0.0f);
    glVertex3f(1.4f, 38.5821f, 0.0f);
    glVertex3f(1.4f, 38.5075f, 0.0f);
    glVertex3f(1.4667f, 38.4328f, 0.0f);
    glVertex3f(1.5333f, 38.2836f, 0.0f);
    glVertex3f(1.5333f, 38.209f, 0.0f);
    glVertex3f(1.6f, 38.209f, 0.0f);
    glVertex3f(1.6667f, 38.0597f, 0.0f);
    glVertex3f(1.6667f, 37.9851f, 0.0f);
    glVertex3f(1.7333f, 37.9104f, 0.0f);
    glVertex3f(1.8667f, 37.8358f, 0.0f);
    glVertex3f(1.8667f, 37.7612f, 0.0f);
    glVertex3f(1.9333f, 37.6866f, 0.0f);
    glVertex3f(1.9333f, 37.6119f, 0.0f);
    glVertex3f(1.9333f, 37.5373f, 0.0f);
    glVertex3f(2.0f, 37.4627f, 0.0f);
    glVertex3f(2.0667f, 37.4627f, 0.0f);
    glVertex3f(2.1333f, 37.4627f, 0.0f);
    glVertex3f(2.2f, 37.4627f, 0.0f);
    glVertex3f(2.2667f, 37.4627f, 0.0f);
    glVertex3f(2.3333f, 37.4627f, 0.0f);
    glVertex3f(2.4f, 37.4627f, 0.0f);
    glVertex3f(2.4667f, 37.4627f, 0.0f);
    glVertex3f(2.5333f, 37.4627f, 0.0f);
    glVertex3f(2.6f, 37.4627f, 0.0f);
    glVertex3f(2.6667f, 37.4627f, 0.0f);
    glVertex3f(2.7333f, 37.4627f, 0.0f);
    glVertex3f(2.8667f, 37.3881f, 0.0f);
    glVertex3f(2.9333f, 37.3881f, 0.0f);
    glVertex3f(3.0f, 37.3881f, 0.0f);
    glVertex3f(3.0667f, 37.3134f, 0.0f);
    glVertex3f(3.1333f, 37.3134f, 0.0f);
    glVertex3f(3.2667f, 37.2388f, 0.0f);


    glEnd();

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬   CLOUD - 2 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.26, 0.45, 0.55); // cloud color and center point to draw all the triangle fan
    glVertex3f(28.1333f, 43.8806f, 0.0f);

    glVertex3f(22.1333f, 42.3881f, 0.0f);
    glVertex3f(22.3333f, 42.3881f, 0.0f);
    glVertex3f(22.6f, 42.3881f, 0.0f);
    glVertex3f(23.0667f, 42.3881f, 0.0f);
    glVertex3f(23.6f, 42.3881f, 0.0f);
    glVertex3f(24.2667f, 42.3881f, 0.0f);
    glVertex3f(25.0f, 42.3881f, 0.0f);
    glVertex3f(25.8667f, 42.3881f, 0.0f);
    glVertex3f(26.8667f, 42.3881f, 0.0f);
    glVertex3f(27.7333f, 42.3881f, 0.0f);
    glVertex3f(28.6f, 42.3881f, 0.0f);
    glVertex3f(29.4667f, 42.3881f, 0.0f);
    glVertex3f(30.2667f, 42.3881f, 0.0f);
    glVertex3f(31.0667f, 42.3881f, 0.0f);
    glVertex3f(31.7333f, 42.3881f, 0.0f);
    glVertex3f(32.2667f, 42.3881f, 0.0f);
    glVertex3f(32.6667f, 42.3881f, 0.0f);
    glVertex3f(33.0667f, 42.3881f, 0.0f);
    glVertex3f(33.3333f, 42.3881f, 0.0f);
    glVertex3f(33.5333f, 42.3881f, 0.0f);
    glVertex3f(33.7333f, 42.3881f, 0.0f);
    glVertex3f(33.8667f, 42.3881f, 0.0f);
    glVertex3f(33.9333f, 42.3881f, 0.0f);
    glVertex3f(34.0f, 42.3881f, 0.0f);
    glVertex3f(34.0667f, 42.3881f, 0.0f);
    glVertex3f(34.0667f, 42.4627f, 0.0f);
    glVertex3f(34.0667f, 42.5373f, 0.0f);
    glVertex3f(34.0f, 42.6866f, 0.0f);
    glVertex3f(34.0f, 42.7612f, 0.0f);
    glVertex3f(34.0f, 42.9104f, 0.0f);
    glVertex3f(34.0f, 42.9851f, 0.0f);
    glVertex3f(34.0f, 43.0597f, 0.0f);
    glVertex3f(34.0f, 43.1343f, 0.0f);
    glVertex3f(33.9333f, 43.209f, 0.0f);
    glVertex3f(33.8667f, 43.2836f, 0.0f);
    glVertex3f(33.8667f, 43.3582f, 0.0f);
    glVertex3f(33.8f, 43.4328f, 0.0f);
    glVertex3f(33.7333f, 43.5821f, 0.0f);
    glVertex3f(33.7333f, 43.6567f, 0.0f);
    glVertex3f(33.6667f, 43.7313f, 0.0f);
    glVertex3f(33.6667f, 43.806f, 0.0f);
    glVertex3f(33.6f, 43.8806f, 0.0f);
    glVertex3f(33.5333f, 43.8806f, 0.0f);
    glVertex3f(33.5333f, 43.9552f, 0.0f);
    glVertex3f(33.4667f, 44.0299f, 0.0f);
    glVertex3f(33.4f, 44.1045f, 0.0f);
    glVertex3f(33.4f, 44.1791f, 0.0f);
    glVertex3f(33.2667f, 44.1791f, 0.0f);
    glVertex3f(33.2f, 44.2537f, 0.0f);
    glVertex3f(33.1333f, 44.3284f, 0.0f);
    glVertex3f(33.0667f, 44.3284f, 0.0f);
    glVertex3f(33.0f, 44.3284f, 0.0f);
    glVertex3f(32.9333f, 44.3284f, 0.0f);
    glVertex3f(32.8667f, 44.403f, 0.0f);
    glVertex3f(32.8f, 44.403f, 0.0f);
    glVertex3f(32.7333f, 44.403f, 0.0f);
    glVertex3f(32.6667f, 44.403f, 0.0f);
    glVertex3f(32.6f, 44.403f, 0.0f);
    glVertex3f(32.4667f, 44.3284f, 0.0f);
    glVertex3f(32.2667f, 44.2537f, 0.0f);
    glVertex3f(32.2f, 44.2537f, 0.0f);
    glVertex3f(32.1333f, 44.1791f, 0.0f);
    glVertex3f(32.0667f, 44.1791f, 0.0f);
    glVertex3f(32.0f, 44.1045f, 0.0f);
    glVertex3f(31.9333f, 44.1045f, 0.0f);
    glVertex3f(31.9333f, 44.0299f, 0.0f);
    glVertex3f(31.8667f, 44.0299f, 0.0f);
    glVertex3f(31.8f, 43.8806f, 0.0f);
    glVertex3f(31.7333f, 43.806f, 0.0f);
    glVertex3f(31.6667f, 43.6567f, 0.0f);
    glVertex3f(31.6667f, 43.5821f, 0.0f);
    glVertex3f(31.6f, 43.5075f, 0.0f);
    glVertex3f(31.5333f, 43.5821f, 0.0f);
    glVertex3f(31.5333f, 43.6567f, 0.0f);
    glVertex3f(31.4667f, 43.7313f, 0.0f);
    glVertex3f(31.4667f, 43.806f, 0.0f);
    glVertex3f(31.4667f, 43.8806f, 0.0f);
    glVertex3f(31.4f, 43.9552f, 0.0f);
    glVertex3f(31.3333f, 44.1045f, 0.0f);
    glVertex3f(31.3333f, 44.1791f, 0.0f);
    glVertex3f(31.2667f, 44.3284f, 0.0f);
    glVertex3f(31.2f, 44.403f, 0.0f);
    glVertex3f(31.2f, 44.4776f, 0.0f);
    glVertex3f(31.1333f, 44.5522f, 0.0f);
    glVertex3f(31.1333f, 44.7015f, 0.0f);
    glVertex3f(31.0667f, 44.8507f, 0.0f);
    glVertex3f(31.0f, 44.8507f, 0.0f);
    glVertex3f(31.0f, 45.0f, 0.0f);
    glVertex3f(30.9333f, 45.0f, 0.0f);
    glVertex3f(30.8667f, 45.1493f, 0.0f);
    glVertex3f(30.8667f, 45.2239f, 0.0f);
    glVertex3f(30.8f, 45.3731f, 0.0f);
    glVertex3f(30.7333f, 45.4478f, 0.0f);
    glVertex3f(30.7333f, 45.5224f, 0.0f);
    glVertex3f(30.6667f, 45.597f, 0.0f);
    glVertex3f(30.6667f, 45.6716f, 0.0f);
    glVertex3f(30.6667f, 45.7463f, 0.0f);
    glVertex3f(30.6667f, 45.8209f, 0.0f);
    glVertex3f(30.6f, 45.8955f, 0.0f);
    glVertex3f(30.5333f, 45.8955f, 0.0f);
    glVertex3f(30.5333f, 45.9701f, 0.0f);
    glVertex3f(30.4667f, 46.0448f, 0.0f);
    glVertex3f(30.4667f, 46.194f, 0.0f);
    glVertex3f(30.4f, 46.194f, 0.0f);
    glVertex3f(30.3333f, 46.2687f, 0.0f);
    glVertex3f(30.3333f, 46.3433f, 0.0f);
    glVertex3f(30.2667f, 46.3433f, 0.0f);
    glVertex3f(30.2f, 46.4179f, 0.0f);
    glVertex3f(30.1333f, 46.4179f, 0.0f);
    glVertex3f(30.0667f, 46.4925f, 0.0f);
    glVertex3f(30.0f, 46.5672f, 0.0f);
    glVertex3f(29.9333f, 46.6418f, 0.0f);
    glVertex3f(29.9333f, 46.7164f, 0.0f);
    glVertex3f(29.8f, 46.7164f, 0.0f);
    glVertex3f(29.7333f, 46.791f, 0.0f);
    glVertex3f(29.6667f, 46.791f, 0.0f);
    glVertex3f(29.6667f, 46.8657f, 0.0f);
    glVertex3f(29.6f, 46.9403f, 0.0f);
    glVertex3f(29.4667f, 46.9403f, 0.0f);
    glVertex3f(29.4f, 46.9403f, 0.0f);
    glVertex3f(29.3333f, 47.0149f, 0.0f);
    glVertex3f(29.2667f, 47.0896f, 0.0f);
    glVertex3f(29.2f, 47.0896f, 0.0f);
    glVertex3f(29.1333f, 47.1642f, 0.0f);
    glVertex3f(29.0667f, 47.1642f, 0.0f);
    glVertex3f(29.0f, 47.1642f, 0.0f);
    glVertex3f(28.9333f, 47.1642f, 0.0f);
    glVertex3f(28.8667f, 47.1642f, 0.0f);
    glVertex3f(28.8f, 47.1642f, 0.0f);
    glVertex3f(28.6667f, 47.2388f, 0.0f);
    glVertex3f(28.5333f, 47.2388f, 0.0f);
    glVertex3f(28.4667f, 47.2388f, 0.0f);
    glVertex3f(28.2667f, 47.3134f, 0.0f);
    glVertex3f(28.1333f, 47.3881f, 0.0f);
    glVertex3f(28.0f, 47.3881f, 0.0f);
    glVertex3f(27.8667f, 47.3881f, 0.0f);
    glVertex3f(27.8f, 47.3881f, 0.0f);
    glVertex3f(27.6f, 47.4627f, 0.0f);
    glVertex3f(27.5333f, 47.4627f, 0.0f);
    glVertex3f(27.4667f, 47.4627f, 0.0f);
    glVertex3f(27.4f, 47.4627f, 0.0f);
    glVertex3f(27.2667f, 47.4627f, 0.0f);
    glVertex3f(27.2f, 47.4627f, 0.0f);
    glVertex3f(27.0667f, 47.3881f, 0.0f);
    glVertex3f(27.0f, 47.3881f, 0.0f);
    glVertex3f(26.8f, 47.3881f, 0.0f);
    glVertex3f(26.6667f, 47.3881f, 0.0f);
    glVertex3f(26.6f, 47.3881f, 0.0f);
    glVertex3f(26.4667f, 47.3134f, 0.0f);
    glVertex3f(26.4f, 47.3134f, 0.0f);
    glVertex3f(26.3333f, 47.3134f, 0.0f);
    glVertex3f(26.2f, 47.2388f, 0.0f);
    glVertex3f(26.1333f, 47.2388f, 0.0f);
    glVertex3f(26.0667f, 47.2388f, 0.0f);
    glVertex3f(26.0f, 47.1642f, 0.0f);
    glVertex3f(25.9333f, 47.1642f, 0.0f);
    glVertex3f(25.9333f, 47.0896f, 0.0f);
    glVertex3f(25.8f, 47.0896f, 0.0f);
    glVertex3f(25.7333f, 47.0149f, 0.0f);
    glVertex3f(25.6667f, 46.9403f, 0.0f);
    glVertex3f(25.6f, 46.9403f, 0.0f);
    glVertex3f(25.5333f, 46.8657f, 0.0f);
    glVertex3f(25.4667f, 46.8657f, 0.0f);
    glVertex3f(25.4f, 46.791f, 0.0f);
    glVertex3f(25.3333f, 46.7164f, 0.0f);
    glVertex3f(25.2667f, 46.7164f, 0.0f);
    glVertex3f(25.2667f, 46.6418f, 0.0f);
    glVertex3f(25.2f, 46.6418f, 0.0f);
    glVertex3f(25.1333f, 46.5672f, 0.0f);
    glVertex3f(25.0667f, 46.4925f, 0.0f);
    glVertex3f(25.0f, 46.4179f, 0.0f);
    glVertex3f(24.9333f, 46.4179f, 0.0f);
    glVertex3f(24.8667f, 46.3433f, 0.0f);
    glVertex3f(24.8f, 46.194f, 0.0f);
    glVertex3f(24.7333f, 46.194f, 0.0f);
    glVertex3f(24.7333f, 46.0448f, 0.0f);
    glVertex3f(24.6667f, 46.0448f, 0.0f);
    glVertex3f(24.6667f, 45.9701f, 0.0f);
    glVertex3f(24.6f, 45.9701f, 0.0f);
    glVertex3f(24.5333f, 45.8955f, 0.0f);
    glVertex3f(24.5333f, 45.8209f, 0.0f);
    glVertex3f(24.4667f, 45.7463f, 0.0f);
    glVertex3f(24.4667f, 45.6716f, 0.0f);
    glVertex3f(24.4f, 45.597f, 0.0f);
    glVertex3f(24.4f, 45.5224f, 0.0f);
    glVertex3f(24.3333f, 45.5224f, 0.0f);
    glVertex3f(24.2667f, 45.4478f, 0.0f);
    glVertex3f(24.2667f, 45.2985f, 0.0f);
    glVertex3f(24.2f, 45.2239f, 0.0f);
    glVertex3f(24.2f, 45.1493f, 0.0f);
    glVertex3f(24.1333f, 45.0746f, 0.0f);
    glVertex3f(24.1333f, 45.0f, 0.0f);
    glVertex3f(24.0667f, 44.9254f, 0.0f);
    glVertex3f(24.0667f, 44.8507f, 0.0f);
    glVertex3f(24.0667f, 44.7761f, 0.0f);
    glVertex3f(24.0667f, 44.7015f, 0.0f);
    glVertex3f(24.0667f, 44.6269f, 0.0f);
    glVertex3f(24.0667f, 44.5522f, 0.0f);
    glVertex3f(24.0667f, 44.4776f, 0.0f);
    glVertex3f(24.0667f, 44.403f, 0.0f);
    glVertex3f(24.0667f, 44.3284f, 0.0f);
    glVertex3f(24.0667f, 44.2537f, 0.0f);
    glVertex3f(24.0667f, 44.1791f, 0.0f);
    glVertex3f(24.0667f, 44.1045f, 0.0f);
    glVertex3f(24.0667f, 44.0299f, 0.0f);
    glVertex3f(24.0667f, 43.9552f, 0.0f);
    glVertex3f(24.0f, 43.9552f, 0.0f);
    glVertex3f(23.9333f, 44.0299f, 0.0f);
    glVertex3f(23.8f, 44.1045f, 0.0f);
    glVertex3f(23.6667f, 44.1791f, 0.0f);
    glVertex3f(23.5333f, 44.2537f, 0.0f);
    glVertex3f(23.4f, 44.3284f, 0.0f);
    glVertex3f(23.2667f, 44.3284f, 0.0f);
    glVertex3f(23.1333f, 44.403f, 0.0f);
    glVertex3f(23.0667f, 44.403f, 0.0f);
    glVertex3f(23.0f, 44.403f, 0.0f);
    glVertex3f(22.9333f, 44.403f, 0.0f);
    glVertex3f(22.8667f, 44.403f, 0.0f);
    glVertex3f(22.8f, 44.403f, 0.0f);
    glVertex3f(22.6667f, 44.403f, 0.0f);
    glVertex3f(22.6f, 44.3284f, 0.0f);
    glVertex3f(22.5333f, 44.2537f, 0.0f);
    glVertex3f(22.4667f, 44.2537f, 0.0f);
    glVertex3f(22.4f, 44.2537f, 0.0f);
    glVertex3f(22.3333f, 44.1791f, 0.0f);
    glVertex3f(22.2667f, 44.1791f, 0.0f);
    glVertex3f(22.2667f, 44.1045f, 0.0f);
    glVertex3f(22.2f, 44.0299f, 0.0f);
    glVertex3f(22.2f, 43.9552f, 0.0f);
    glVertex3f(22.1333f, 43.806f, 0.0f);
    glVertex3f(22.0667f, 43.7313f, 0.0f);
    glVertex3f(22.0667f, 43.6567f, 0.0f);
    glVertex3f(22.0f, 43.5821f, 0.0f);
    glVertex3f(22.0f, 43.5075f, 0.0f);
    glVertex3f(21.9333f, 43.4328f, 0.0f);
    glVertex3f(21.9333f, 43.3582f, 0.0f);
    glVertex3f(21.9333f, 43.2836f, 0.0f);
    glVertex3f(21.9333f, 43.209f, 0.0f);
    glVertex3f(21.9333f, 43.1343f, 0.0f);
    glVertex3f(21.9333f, 43.0597f, 0.0f);
    glVertex3f(21.9333f, 42.9851f, 0.0f);
    glVertex3f(21.9333f, 42.9104f, 0.0f);
    glVertex3f(21.9333f, 42.8358f, 0.0f);
    glVertex3f(21.9333f, 42.7612f, 0.0f);
    glVertex3f(21.9333f, 42.6866f, 0.0f);
    glVertex3f(22.0f, 42.6866f, 0.0f);
    glVertex3f(22.0667f, 42.6119f, 0.0f);
    glVertex3f(22.0667f, 42.5373f, 0.0f);
    glVertex3f(22.1333f, 42.5373f, 0.0f);
    glVertex3f(22.2f, 42.5373f, 0.0f);
    glVertex3f(22.2667f, 42.4627f, 0.0f);

    glEnd();

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬   CLOUD - 3 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.26, 0.45, 0.55);
    glVertex3f(42.6f, 39.2537f, 0.0f);

    glVertex3f(37.0667f, 38.1343f, 0.0f);
    glVertex3f(37.3333f, 38.1343f, 0.0f);
    glVertex3f(37.6667f, 38.1343f, 0.0f);
    glVertex3f(38.2f, 38.1343f, 0.0f);
    glVertex3f(38.6667f, 38.1343f, 0.0f);
    glVertex3f(39.2f, 38.1343f, 0.0f);
    glVertex3f(39.8667f, 38.1343f, 0.0f);
    glVertex3f(40.4f, 38.1343f, 0.0f);
    glVertex3f(40.9333f, 38.1343f, 0.0f);
    glVertex3f(41.3333f, 38.1343f, 0.0f);
    glVertex3f(41.8667f, 38.1343f, 0.0f);
    glVertex3f(42.3333f, 38.1343f, 0.0f);
    glVertex3f(42.6667f, 38.1343f, 0.0f);
    glVertex3f(43.0f, 38.1343f, 0.0f);
    glVertex3f(43.2667f, 38.1343f, 0.0f);
    glVertex3f(43.5333f, 38.1343f, 0.0f);
    glVertex3f(43.8f, 38.1343f, 0.0f);
    glVertex3f(44.1333f, 38.1343f, 0.0f);
    glVertex3f(44.6f, 38.1343f, 0.0f);
    glVertex3f(45.1333f, 38.1343f, 0.0f);
    glVertex3f(45.6667f, 38.1343f, 0.0f);
    glVertex3f(46.2f, 38.1343f, 0.0f);
    glVertex3f(46.7333f, 38.1343f, 0.0f);
    glVertex3f(47.2f, 38.1343f, 0.0f);
    glVertex3f(47.5333f, 38.1343f, 0.0f);
    glVertex3f(47.7333f, 38.1343f, 0.0f);
    glVertex3f(47.9333f, 38.1343f, 0.0f);
    glVertex3f(48.0f, 38.1343f, 0.0f);
    glVertex3f(48.0667f, 38.209f, 0.0f);
    glVertex3f(48.0667f, 38.2836f, 0.0f);
    glVertex3f(48.0667f, 38.3582f, 0.0f);
    glVertex3f(48.0667f, 38.4328f, 0.0f);
    glVertex3f(48.0667f, 38.5075f, 0.0f);
    glVertex3f(48.0667f, 38.5821f, 0.0f);
    glVertex3f(48.0667f, 38.6567f, 0.0f);
    glVertex3f(48.0667f, 38.7313f, 0.0f);
    glVertex3f(48.0667f, 38.806f, 0.0f);
    glVertex3f(48.0f, 38.8806f, 0.0f);
    glVertex3f(48.0f, 38.9552f, 0.0f);
    glVertex3f(48.0f, 39.0299f, 0.0f);
    glVertex3f(47.9333f, 39.1791f, 0.0f);
    glVertex3f(47.8667f, 39.1791f, 0.0f);
    glVertex3f(47.8667f, 39.2537f, 0.0f);
    glVertex3f(47.8f, 39.3284f, 0.0f);
    glVertex3f(47.8f, 39.403f, 0.0f);
    glVertex3f(47.7333f, 39.5522f, 0.0f);
    glVertex3f(47.6667f, 39.6269f, 0.0f);
    glVertex3f(47.6667f, 39.7015f, 0.0f);
    glVertex3f(47.6f, 39.7761f, 0.0f);
    glVertex3f(47.5333f, 39.8507f, 0.0f);
    glVertex3f(47.4667f, 40.0f, 0.0f);
    glVertex3f(47.4f, 40.0f, 0.0f);
    glVertex3f(47.4f, 40.0746f, 0.0f);
    glVertex3f(47.3333f, 40.0746f, 0.0f);
    glVertex3f(47.2f, 40.0746f, 0.0f);
    glVertex3f(47.2f, 40.1493f, 0.0f);
    glVertex3f(47.1333f, 40.2239f, 0.0f);
    glVertex3f(47.0f, 40.2239f, 0.0f);
    glVertex3f(47.0f, 40.2985f, 0.0f);
    glVertex3f(46.9333f, 40.2985f, 0.0f);
    glVertex3f(46.8667f, 40.2985f, 0.0f);
    glVertex3f(46.8f, 40.2985f, 0.0f);
    glVertex3f(46.6667f, 40.3731f, 0.0f);
    glVertex3f(46.6667f, 40.4478f, 0.0f);
    glVertex3f(46.5333f, 40.4478f, 0.0f);
    glVertex3f(46.4667f, 40.5224f, 0.0f);
    glVertex3f(46.4f, 40.5224f, 0.0f);
    glVertex3f(46.3333f, 40.5224f, 0.0f);
    glVertex3f(46.2667f, 40.5224f, 0.0f);
    glVertex3f(46.2f, 40.5224f, 0.0f);
    glVertex3f(46.1333f, 40.5224f, 0.0f);
    glVertex3f(46.0667f, 40.5224f, 0.0f);
    glVertex3f(46.0f, 40.5224f, 0.0f);
    glVertex3f(45.9333f, 40.5224f, 0.0f);
    glVertex3f(45.8667f, 40.4478f, 0.0f);
    glVertex3f(45.8f, 40.4478f, 0.0f);
    glVertex3f(45.7333f, 40.4478f, 0.0f);
    glVertex3f(45.6667f, 40.3731f, 0.0f);
    glVertex3f(45.6f, 40.2985f, 0.0f);
    glVertex3f(45.6f, 40.2239f, 0.0f);
    glVertex3f(45.5333f, 40.1493f, 0.0f);
    glVertex3f(45.4667f, 40.0f, 0.0f);
    glVertex3f(45.4667f, 40.0746f, 0.0f);
    glVertex3f(45.4667f, 40.1493f, 0.0f);
    glVertex3f(45.4667f, 40.2239f, 0.0f);
    glVertex3f(45.4667f, 40.2985f, 0.0f);
    glVertex3f(45.4f, 40.3731f, 0.0f);
    glVertex3f(45.4f, 40.4478f, 0.0f);
    glVertex3f(45.4f, 40.5224f, 0.0f);
    glVertex3f(45.3333f, 40.597f, 0.0f);
    glVertex3f(45.3333f, 40.6716f, 0.0f);
    glVertex3f(45.3333f, 40.7463f, 0.0f);
    glVertex3f(45.3333f, 40.8955f, 0.0f);
    glVertex3f(45.2667f, 40.9701f, 0.0f);
    glVertex3f(45.2f, 41.0448f, 0.0f);
    glVertex3f(45.2f, 41.1194f, 0.0f);
    glVertex3f(45.1333f, 41.1194f, 0.0f);
    glVertex3f(45.1333f, 41.194f, 0.0f);
    glVertex3f(45.0667f, 41.2687f, 0.0f);
    glVertex3f(45.0f, 41.3433f, 0.0f);
    glVertex3f(44.9333f, 41.4179f, 0.0f);
    glVertex3f(44.9333f, 41.4925f, 0.0f);
    glVertex3f(44.8667f, 41.4925f, 0.0f);
    glVertex3f(44.8f, 41.5672f, 0.0f);
    glVertex3f(44.7333f, 41.6418f, 0.0f);
    glVertex3f(44.6667f, 41.7164f, 0.0f);
    glVertex3f(44.6f, 41.791f, 0.0f);
    glVertex3f(44.4667f, 41.791f, 0.0f);
    glVertex3f(44.4f, 41.8657f, 0.0f);
    glVertex3f(44.3333f, 41.9403f, 0.0f);
    glVertex3f(44.2f, 41.9403f, 0.0f);
    glVertex3f(44.2f, 42.0149f, 0.0f);
    glVertex3f(44.0667f, 42.0896f, 0.0f);
    glVertex3f(43.9333f, 42.0896f, 0.0f);
    glVertex3f(43.8f, 42.1642f, 0.0f);
    glVertex3f(43.6667f, 42.2388f, 0.0f);
    glVertex3f(43.5333f, 42.2388f, 0.0f);
    glVertex3f(43.3333f, 42.3134f, 0.0f);
    glVertex3f(43.2667f, 42.3134f, 0.0f);
    glVertex3f(43.0667f, 42.3134f, 0.0f);
    glVertex3f(42.9333f, 42.3134f, 0.0f);
    glVertex3f(42.8f, 42.3134f, 0.0f);
    glVertex3f(42.6667f, 42.3134f, 0.0f);
    glVertex3f(42.6f, 42.3134f, 0.0f);
    glVertex3f(42.4667f, 42.3134f, 0.0f);
    glVertex3f(42.3333f, 42.3134f, 0.0f);
    glVertex3f(42.2667f, 42.3134f, 0.0f);
    glVertex3f(42.2f, 42.3134f, 0.0f);
    glVertex3f(42.0667f, 42.3134f, 0.0f);
    glVertex3f(42.0f, 42.3134f, 0.0f);
    glVertex3f(41.9333f, 42.3134f, 0.0f);
    glVertex3f(41.8667f, 42.3134f, 0.0f);
    glVertex3f(41.8f, 42.3134f, 0.0f);
    glVertex3f(41.6667f, 42.2388f, 0.0f);
    glVertex3f(41.6f, 42.2388f, 0.0f);
    glVertex3f(41.5333f, 42.2388f, 0.0f);
    glVertex3f(41.4667f, 42.1642f, 0.0f);
    glVertex3f(41.3333f, 42.0896f, 0.0f);
    glVertex3f(41.2667f, 42.0896f, 0.0f);
    glVertex3f(41.2667f, 42.0149f, 0.0f);
    glVertex3f(41.2f, 42.0149f, 0.0f);
    glVertex3f(41.1333f, 41.8657f, 0.0f);
    glVertex3f(41.1333f, 41.7164f, 0.0f);
    glVertex3f(41.0667f, 41.7164f, 0.0f);
    glVertex3f(41.0667f, 41.5672f, 0.0f);
    glVertex3f(41.0667f, 41.4925f, 0.0f);
    glVertex3f(41.0667f, 41.3433f, 0.0f);
    glVertex3f(41.0667f, 41.2687f, 0.0f);
    glVertex3f(41.0667f, 41.1194f, 0.0f);
    glVertex3f(41.0667f, 41.0448f, 0.0f);
    glVertex3f(41.0667f, 40.9701f, 0.0f);
    glVertex3f(41.0667f, 40.8955f, 0.0f);
    glVertex3f(41.0667f, 40.7463f, 0.0f);
    glVertex3f(41.0667f, 40.6716f, 0.0f);
    glVertex3f(41.0667f, 40.597f, 0.0f);
    glVertex3f(41.0667f, 40.5224f, 0.0f);
    glVertex3f(41.0667f, 40.4478f, 0.0f);
    glVertex3f(41.0667f, 40.3731f, 0.0f);
    glVertex3f(41.0f, 40.4478f, 0.0f);
    glVertex3f(40.9333f, 40.4478f, 0.0f);
    glVertex3f(40.9333f, 40.5224f, 0.0f);
    glVertex3f(40.8667f, 40.597f, 0.0f);
    glVertex3f(40.8f, 40.7463f, 0.0f);
    glVertex3f(40.7333f, 40.7463f, 0.0f);
    glVertex3f(40.6667f, 40.8209f, 0.0f);
    glVertex3f(40.5333f, 40.8955f, 0.0f);
    glVertex3f(40.4f, 40.9701f, 0.0f);
    glVertex3f(40.2667f, 41.0448f, 0.0f);
    glVertex3f(40.1333f, 41.1194f, 0.0f);
    glVertex3f(40.0f, 41.1194f, 0.0f);
    glVertex3f(39.9333f, 41.194f, 0.0f);
    glVertex3f(39.8667f, 41.2687f, 0.0f);
    glVertex3f(39.7333f, 41.2687f, 0.0f);
    glVertex3f(39.6667f, 41.3433f, 0.0f);
    glVertex3f(39.6f, 41.3433f, 0.0f);
    glVertex3f(39.6f, 41.4179f, 0.0f);
    glVertex3f(39.5333f, 41.4179f, 0.0f);
    glVertex3f(39.4667f, 41.4179f, 0.0f);
    glVertex3f(39.4f, 41.4179f, 0.0f);
    glVertex3f(39.3333f, 41.4179f, 0.0f);
    glVertex3f(39.2f, 41.3433f, 0.0f);
    glVertex3f(39.0667f, 41.3433f, 0.0f);
    glVertex3f(38.9333f, 41.2687f, 0.0f);
    glVertex3f(38.8667f, 41.194f, 0.0f);
    glVertex3f(38.8f, 41.1194f, 0.0f);
    glVertex3f(38.7333f, 41.1194f, 0.0f);
    glVertex3f(38.6667f, 41.0448f, 0.0f);
    glVertex3f(38.6667f, 40.9701f, 0.0f);
    glVertex3f(38.6f, 40.8955f, 0.0f);
    glVertex3f(38.6f, 40.8209f, 0.0f);
    glVertex3f(38.6f, 40.7463f, 0.0f);
    glVertex3f(38.5333f, 40.6716f, 0.0f);
    glVertex3f(38.4667f, 40.597f, 0.0f);
    glVertex3f(38.4667f, 40.5224f, 0.0f);
    glVertex3f(38.4667f, 40.4478f, 0.0f);
    glVertex3f(38.4667f, 40.3731f, 0.0f);
    glVertex3f(38.4667f, 40.2985f, 0.0f);
    glVertex3f(38.4667f, 40.2239f, 0.0f);
    glVertex3f(38.4667f, 40.1493f, 0.0f);
    glVertex3f(38.4667f, 40.0746f, 0.0f);
    glVertex3f(38.4667f, 40.0f, 0.0f);
    glVertex3f(38.4667f, 39.9254f, 0.0f);
    glVertex3f(38.4667f, 39.8507f, 0.0f);
    glVertex3f(38.4667f, 39.7761f, 0.0f);
    glVertex3f(38.4667f, 39.7015f, 0.0f);
    glVertex3f(38.4667f, 39.6269f, 0.0f);
    glVertex3f(38.4f, 39.5522f, 0.0f);
    glVertex3f(38.4f, 39.6269f, 0.0f);
    glVertex3f(38.2667f, 39.7015f, 0.0f);
    glVertex3f(38.2f, 39.7015f, 0.0f);
    glVertex3f(38.1333f, 39.7015f, 0.0f);
    glVertex3f(38.0667f, 39.7761f, 0.0f);
    glVertex3f(38.0f, 39.7761f, 0.0f);
    glVertex3f(37.9333f, 39.7015f, 0.0f);
    glVertex3f(37.8667f, 39.7015f, 0.0f);
    glVertex3f(37.8667f, 39.6269f, 0.0f);
    glVertex3f(37.8f, 39.6269f, 0.0f);
    glVertex3f(37.8f, 39.5522f, 0.0f);
    glVertex3f(37.6667f, 39.5522f, 0.0f);
    glVertex3f(37.6667f, 39.4776f, 0.0f);
    glVertex3f(37.6f, 39.403f, 0.0f);
    glVertex3f(37.5333f, 39.3284f, 0.0f);
    glVertex3f(37.4667f, 39.3284f, 0.0f);
    glVertex3f(37.4f, 39.2537f, 0.0f);
    glVertex3f(37.4f, 39.1791f, 0.0f);
    glVertex3f(37.3333f, 39.1045f, 0.0f);
    glVertex3f(37.3333f, 39.0299f, 0.0f);
    glVertex3f(37.2667f, 38.9552f, 0.0f);
    glVertex3f(37.2667f, 38.8806f, 0.0f);
    glVertex3f(37.2f, 38.806f, 0.0f);
    glVertex3f(37.2f, 38.7313f, 0.0f);
    glVertex3f(37.1333f, 38.6567f, 0.0f);
    glVertex3f(37.1333f, 38.5821f, 0.0f);
    glVertex3f(37.1333f, 38.5075f, 0.0f);
    glVertex3f(37.1333f, 38.4328f, 0.0f);
    glVertex3f(37.1333f, 38.3582f, 0.0f);
    glVertex3f(37.1333f, 38.2836f, 0.0f);
    glVertex3f(37.1333f, 38.209f, 0.0f);
    glVertex3f(37.0667f, 38.1343f, 0.0f);

    glEnd();

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬   CLOUD - 4 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.26, 0.45, 0.55); // cloud color and center point to draw all the triangle fan
    glVertex3f(39.3333f, 33.6567f, 0.0f);

    glVertex3f(36.4667f, 33.4328f, 0.0f);
    glVertex3f(36.6f, 33.4328f, 0.0f);
    glVertex3f(36.7333f, 33.4328f, 0.0f);
    glVertex3f(36.9333f, 33.4328f, 0.0f);
    glVertex3f(37.1333f, 33.4328f, 0.0f);
    glVertex3f(37.3333f, 33.4328f, 0.0f);
    glVertex3f(37.6f, 33.4328f, 0.0f);
    glVertex3f(37.9333f, 33.4328f, 0.0f);
    glVertex3f(38.1333f, 33.4328f, 0.0f);
    glVertex3f(38.3333f, 33.4328f, 0.0f);
    glVertex3f(38.5333f, 33.4328f, 0.0f);
    glVertex3f(38.7333f, 33.4328f, 0.0f);
    glVertex3f(38.9333f, 33.4328f, 0.0f);
    glVertex3f(39.0667f, 33.4328f, 0.0f);
    glVertex3f(39.2f, 33.4328f, 0.0f);
    glVertex3f(39.3333f, 33.4328f, 0.0f);
    glVertex3f(39.4667f, 33.4328f, 0.0f);
    glVertex3f(39.5333f, 33.4328f, 0.0f);
    glVertex3f(39.6667f, 33.4328f, 0.0f);
    glVertex3f(39.7333f, 33.4328f, 0.0f);
    glVertex3f(39.8667f, 33.4328f, 0.0f);
    glVertex3f(40.0f, 33.4328f, 0.0f);
    glVertex3f(40.1333f, 33.4328f, 0.0f);
    glVertex3f(40.2667f, 33.4328f, 0.0f);
    glVertex3f(40.4667f, 33.4328f, 0.0f);
    glVertex3f(40.6f, 33.4328f, 0.0f);
    glVertex3f(40.6667f, 33.4328f, 0.0f);
    glVertex3f(40.7333f, 33.4328f, 0.0f);
    glVertex3f(40.8667f, 33.4328f, 0.0f);
    glVertex3f(40.9333f, 33.4328f, 0.0f);
    glVertex3f(41.0f, 33.4328f, 0.0f);
    glVertex3f(41.0667f, 33.4328f, 0.0f);
    glVertex3f(41.2667f, 33.4328f, 0.0f);
    glVertex3f(41.3333f, 33.4328f, 0.0f);
    glVertex3f(41.4f, 33.4328f, 0.0f);
    glVertex3f(41.4667f, 33.4328f, 0.0f);
    glVertex3f(41.5333f, 33.4328f, 0.0f);
    glVertex3f(41.6f, 33.4328f, 0.0f);
    glVertex3f(41.6667f, 33.4328f, 0.0f);
    glVertex3f(41.7333f, 33.5075f, 0.0f);
    glVertex3f(41.8f, 33.5821f, 0.0f);
    glVertex3f(41.8f, 33.6567f, 0.0f);
    glVertex3f(41.8f, 33.7313f, 0.0f);
    glVertex3f(41.8f, 33.806f, 0.0f);
    glVertex3f(41.8f, 33.8806f, 0.0f);
    glVertex3f(41.8f, 33.9552f, 0.0f);
    glVertex3f(41.8f, 34.0299f, 0.0f);
    glVertex3f(41.7333f, 34.1791f, 0.0f);
    glVertex3f(41.6667f, 34.2537f, 0.0f);
    glVertex3f(41.6f, 34.3284f, 0.0f);
    glVertex3f(41.5333f, 34.403f, 0.0f);
    glVertex3f(41.4667f, 34.403f, 0.0f);
    glVertex3f(41.4f, 34.4776f, 0.0f);
    glVertex3f(41.3333f, 34.5522f, 0.0f);
    glVertex3f(41.2667f, 34.5522f, 0.0f);
    glVertex3f(41.2f, 34.5522f, 0.0f);
    glVertex3f(41.1333f, 34.5522f, 0.0f);
    glVertex3f(41.0667f, 34.5522f, 0.0f);
    glVertex3f(41.0f, 34.5522f, 0.0f);
    glVertex3f(40.9333f, 34.5522f, 0.0f);
    glVertex3f(40.8667f, 34.5522f, 0.0f);
    glVertex3f(40.8f, 34.5522f, 0.0f);
    glVertex3f(40.7333f, 34.4776f, 0.0f);
    glVertex3f(40.6667f, 34.403f, 0.0f);
    glVertex3f(40.6667f, 34.4776f, 0.0f);
    glVertex3f(40.6667f, 34.5522f, 0.0f);
    glVertex3f(40.6667f, 34.6269f, 0.0f);
    glVertex3f(40.6667f, 34.7015f, 0.0f);
    glVertex3f(40.6667f, 34.7761f, 0.0f);
    glVertex3f(40.6667f, 34.8507f, 0.0f);
    glVertex3f(40.6667f, 34.9254f, 0.0f);
    glVertex3f(40.6667f, 35.0f, 0.0f);
    glVertex3f(40.6667f, 35.1493f, 0.0f);
    glVertex3f(40.6f, 35.2239f, 0.0f);
    glVertex3f(40.5333f, 35.2239f, 0.0f);
    glVertex3f(40.5333f, 35.2985f, 0.0f);
    glVertex3f(40.5333f, 35.3731f, 0.0f);
    glVertex3f(40.5333f, 35.4478f, 0.0f);
    glVertex3f(40.5333f, 35.5224f, 0.0f);
    glVertex3f(40.4667f, 35.597f, 0.0f);
    glVertex3f(40.4667f, 35.6716f, 0.0f);
    glVertex3f(40.4f, 35.6716f, 0.0f);
    glVertex3f(40.3333f, 35.7463f, 0.0f);
    glVertex3f(40.3333f, 35.8209f, 0.0f);
    glVertex3f(40.2667f, 35.8209f, 0.0f);
    glVertex3f(40.1333f, 35.8209f, 0.0f);
    glVertex3f(40.0f, 35.8209f, 0.0f);
    glVertex3f(39.8667f, 35.8209f, 0.0f);
    glVertex3f(39.8f, 35.8209f, 0.0f);
    glVertex3f(39.7333f, 35.8955f, 0.0f);
    glVertex3f(39.6667f, 35.9701f, 0.0f);
    glVertex3f(39.6f, 35.9701f, 0.0f);
    glVertex3f(39.5333f, 35.9701f, 0.0f);
    glVertex3f(39.4667f, 35.9701f, 0.0f);
    glVertex3f(39.4667f, 35.8955f, 0.0f);
    glVertex3f(39.4f, 35.8209f, 0.0f);
    glVertex3f(39.3333f, 35.7463f, 0.0f);
    glVertex3f(39.2f, 35.6716f, 0.0f);
    glVertex3f(39.2f, 35.597f, 0.0f);
    glVertex3f(39.1333f, 35.5224f, 0.0f);
    glVertex3f(39.0667f, 35.4478f, 0.0f);
    glVertex3f(39.0667f, 35.3731f, 0.0f);
    glVertex3f(39.0667f, 35.2985f, 0.0f);
    glVertex3f(39.0667f, 35.2239f, 0.0f);
    glVertex3f(39.0667f, 35.1493f, 0.0f);
    glVertex3f(39.0667f, 35.0746f, 0.0f);
    glVertex3f(39.0667f, 35.0f, 0.0f);
    glVertex3f(39.0667f, 34.9254f, 0.0f);
    glVertex3f(39.0667f, 34.8507f, 0.0f);
    glVertex3f(39.0667f, 34.7761f, 0.0f);
    glVertex3f(39.0667f, 34.7015f, 0.0f);
    glVertex3f(39.0667f, 34.6269f, 0.0f);
    glVertex3f(39.0f, 34.7015f, 0.0f);
    glVertex3f(39.0f, 34.7761f, 0.0f);
    glVertex3f(38.8667f, 34.8507f, 0.0f);
    glVertex3f(38.8f, 34.8507f, 0.0f);
    glVertex3f(38.7333f, 35.0f, 0.0f);
    glVertex3f(38.6f, 35.0746f, 0.0f);
    glVertex3f(38.5333f, 35.1493f, 0.0f);
    glVertex3f(38.4f, 35.2239f, 0.0f);
    glVertex3f(38.2667f, 35.3731f, 0.0f);
    glVertex3f(38.2f, 35.3731f, 0.0f);
    glVertex3f(38.0667f, 35.4478f, 0.0f);
    glVertex3f(38.0667f, 35.5224f, 0.0f);
    glVertex3f(38.0f, 35.5224f, 0.0f);
    glVertex3f(37.8667f, 35.5224f, 0.0f);
    glVertex3f(37.7333f, 35.4478f, 0.0f);
    glVertex3f(37.6667f, 35.4478f, 0.0f);
    glVertex3f(37.6f, 35.3731f, 0.0f);
    glVertex3f(37.4667f, 35.3731f, 0.0f);
    glVertex3f(37.4f, 35.2985f, 0.0f);
    glVertex3f(37.3333f, 35.2239f, 0.0f);
    glVertex3f(37.2667f, 35.1493f, 0.0f);
    glVertex3f(37.2f, 35.0746f, 0.0f);
    glVertex3f(37.1333f, 35.0746f, 0.0f);
    glVertex3f(37.1333f, 35.0f, 0.0f);
    glVertex3f(37.1333f, 34.9254f, 0.0f);
    glVertex3f(37.1333f, 34.8507f, 0.0f);
    glVertex3f(37.1333f, 34.7761f, 0.0f);
    glVertex3f(37.1333f, 34.7015f, 0.0f);
    glVertex3f(37.1333f, 34.6269f, 0.0f);
    glVertex3f(37.1333f, 34.5522f, 0.0f);
    glVertex3f(37.1333f, 34.4776f, 0.0f);
    glVertex3f(37.0667f, 34.4776f, 0.0f);
    glVertex3f(37.0f, 34.4776f, 0.0f);
    glVertex3f(36.9333f, 34.4776f, 0.0f);
    glVertex3f(36.8667f, 34.4776f, 0.0f);
    glVertex3f(36.8f, 34.4776f, 0.0f);
    glVertex3f(36.7333f, 34.4776f, 0.0f);
    glVertex3f(36.6667f, 34.403f, 0.0f);
    glVertex3f(36.6f, 34.403f, 0.0f);
    glVertex3f(36.5333f, 34.403f, 0.0f);
    glVertex3f(36.5333f, 34.3284f, 0.0f);
    glVertex3f(36.4667f, 34.2537f, 0.0f);
    glVertex3f(36.4f, 34.2537f, 0.0f);
    glVertex3f(36.4f, 34.1791f, 0.0f);
    glVertex3f(36.3333f, 34.1791f, 0.0f);
    glVertex3f(36.3333f, 34.0299f, 0.0f);
    glVertex3f(36.2667f, 33.9552f, 0.0f);
    glVertex3f(36.2f, 33.8806f, 0.0f);
    glVertex3f(36.2f, 33.806f, 0.0f);
    glVertex3f(36.2667f, 33.7313f, 0.0f);
    glVertex3f(36.2667f, 33.6567f, 0.0f);
    glVertex3f(36.3333f, 33.5821f, 0.0f);
    glVertex3f(36.4f, 33.5821f, 0.0f);


    glEnd();



    //This is condition from where the cloud going to move left to right edge

    glPopMatrix();
    cx += .005;
    if (cx > 10)
        cx = -50;
    glutPostRedisplay();


}


// First Boat Auto movement code start here




void boat()
{

    glPushMatrix();
    glTranslatef(bx, 0, 0);




//first boat start


    //first boat start

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.612, 0.863, 0.973);
    glVertex3f(9.1333f, 5.8955f, 0.0f);
    glVertex3f(3.8667f, 5.6716f, 0.0f);
    glVertex3f(3.8f, 5.6716f, 0.0f);
    glVertex3f(3.7333f, 5.6716f, 0.0f);
    glVertex3f(3.6667f, 5.6716f, 0.0f);
    glVertex3f(3.6f, 5.6716f, 0.0f);
    glVertex3f(3.5333f, 5.6716f, 0.0f);
    glVertex3f(3.4667f, 5.6716f, 0.0f);
    glVertex3f(3.4f, 5.6716f, 0.0f);
    glVertex3f(3.3333f, 5.6716f, 0.0f);
    glVertex3f(3.2667f, 5.6716f, 0.0f);
    glVertex3f(3.2667f, 5.7463f, 0.0f);
    glVertex3f(3.2f, 5.7463f, 0.0f);
    glVertex3f(3.1333f, 5.7463f, 0.0f);
    glVertex3f(3.1333f, 5.8209f, 0.0f);
    glVertex3f(3.0667f, 5.8209f, 0.0f);
    glVertex3f(3.0667f, 5.8955f, 0.0f);
    glVertex3f(3.0f, 5.8955f, 0.0f);
    glVertex3f(3.0f, 5.9701f, 0.0f);
    glVertex3f(3.0667f, 5.9701f, 0.0f);
    glVertex3f(3.0667f, 6.0448f, 0.0f);
    glVertex3f(3.1333f, 6.0448f, 0.0f);
    glVertex3f(3.2f, 6.0448f, 0.0f);
    glVertex3f(3.2667f, 6.0448f, 0.0f);
    glVertex3f(3.3333f, 6.0448f, 0.0f);
    glVertex3f(3.4f, 6.0448f, 0.0f);
    glVertex3f(3.4667f, 6.0448f, 0.0f);
    glVertex3f(3.5333f, 6.0448f, 0.0f);
    glVertex3f(3.6f, 6.1194f, 0.0f);
    glVertex3f(3.6667f, 6.1194f, 0.0f);
    glVertex3f(3.6667f, 6.194f, 0.0f);
    glVertex3f(3.7333f, 6.194f, 0.0f);
    glVertex3f(3.8f, 6.194f, 0.0f);
    glVertex3f(3.8667f, 6.194f, 0.0f);
    glVertex3f(3.8667f, 6.2687f, 0.0f);
    glVertex3f(3.9333f, 6.2687f, 0.0f);
    glVertex3f(4.0f, 6.2687f, 0.0f);
    glVertex3f(4.0667f, 6.2687f, 0.0f);
    glVertex3f(4.0667f, 6.3433f, 0.0f);
    glVertex3f(4.1333f, 6.3433f, 0.0f);
    glVertex3f(4.2f, 6.3433f, 0.0f);
    glVertex3f(4.2667f, 6.4179f, 0.0f);
    glVertex3f(4.3333f, 6.4179f, 0.0f);
    glVertex3f(4.4f, 6.4179f, 0.0f);
    glVertex3f(4.4667f, 6.4179f, 0.0f);
    glVertex3f(4.4667f, 6.4925f, 0.0f);
    glVertex3f(4.5333f, 6.4925f, 0.0f);
    glVertex3f(4.6f, 6.4925f, 0.0f);
    glVertex3f(4.6667f, 6.4925f, 0.0f);
    glVertex3f(4.7333f, 6.4925f, 0.0f);
    glVertex3f(4.8f, 6.4925f, 0.0f);
    glVertex3f(4.8667f, 6.4925f, 0.0f);
    glVertex3f(4.9333f, 6.4925f, 0.0f);
    glVertex3f(5.0f, 6.5672f, 0.0f);
    glVertex3f(5.0667f, 6.5672f, 0.0f);
    glVertex3f(5.1333f, 6.5672f, 0.0f);
    glVertex3f(5.2f, 6.5672f, 0.0f);
    glVertex3f(5.2667f, 6.5672f, 0.0f);
    glVertex3f(5.3333f, 6.5672f, 0.0f);
    glVertex3f(5.4f, 6.5672f, 0.0f);
    glVertex3f(5.4667f, 6.5672f, 0.0f);
    glVertex3f(5.5333f, 6.5672f, 0.0f);
    glVertex3f(5.6f, 6.5672f, 0.0f);
    glVertex3f(5.6667f, 6.5672f, 0.0f);
    glVertex3f(5.7333f, 6.5672f, 0.0f);
    glVertex3f(5.7333f, 6.6418f, 0.0f);
    glVertex3f(5.8f, 6.6418f, 0.0f);
    glVertex3f(5.8667f, 6.6418f, 0.0f);
    glVertex3f(5.9333f, 6.6418f, 0.0f);
    glVertex3f(6.0f, 6.6418f, 0.0f);
    glVertex3f(6.0667f, 6.6418f, 0.0f);
    glVertex3f(6.1333f, 6.6418f, 0.0f);
    glVertex3f(6.2f, 6.6418f, 0.0f);
    glVertex3f(6.2667f, 6.6418f, 0.0f);
    glVertex3f(6.3333f, 6.6418f, 0.0f);
    glVertex3f(6.4f, 6.6418f, 0.0f);
    glVertex3f(6.4667f, 6.6418f, 0.0f);
    glVertex3f(6.5333f, 6.6418f, 0.0f);
    glVertex3f(6.5333f, 6.7164f, 0.0f);
    glVertex3f(6.6f, 6.7164f, 0.0f);
    glVertex3f(6.6667f, 6.7164f, 0.0f);
    glVertex3f(6.7333f, 6.7164f, 0.0f);
    glVertex3f(6.8f, 6.7164f, 0.0f);
    glVertex3f(6.8667f, 6.7164f, 0.0f);
    glVertex3f(6.9333f, 6.7164f, 0.0f);
    glVertex3f(7.0f, 6.7164f, 0.0f);
    glVertex3f(7.0667f, 6.7164f, 0.0f);
    glVertex3f(7.1333f, 6.7164f, 0.0f);
    glVertex3f(7.2f, 6.7164f, 0.0f);
    glVertex3f(7.2667f, 6.7164f, 0.0f);
    glVertex3f(7.3333f, 6.7164f, 0.0f);
    glVertex3f(7.4f, 6.7164f, 0.0f);
    glVertex3f(7.5333f, 6.7164f, 0.0f);
    glVertex3f(7.6f, 6.7164f, 0.0f);
    glVertex3f(7.6667f, 6.7164f, 0.0f);
    glVertex3f(7.7333f, 6.7164f, 0.0f);
    glVertex3f(7.8667f, 6.7164f, 0.0f);
    glVertex3f(7.9333f, 6.7164f, 0.0f);
    glVertex3f(8.0f, 6.7164f, 0.0f);
    glVertex3f(8.1333f, 6.7164f, 0.0f);
    glVertex3f(8.2f, 6.7164f, 0.0f);
    glVertex3f(8.2667f, 6.7164f, 0.0f);
    glVertex3f(8.3333f, 6.7164f, 0.0f);
    glVertex3f(8.4f, 6.7164f, 0.0f);
    glVertex3f(8.4667f, 6.7164f, 0.0f);
    glVertex3f(8.5333f, 6.7164f, 0.0f);
    glVertex3f(8.6f, 6.7164f, 0.0f);
    glVertex3f(8.6667f, 6.7164f, 0.0f);
    glVertex3f(8.7333f, 6.7164f, 0.0f);
    glVertex3f(8.8f, 6.7164f, 0.0f);
    glVertex3f(8.8667f, 6.7164f, 0.0f);
    glVertex3f(8.9333f, 6.7164f, 0.0f);
    glVertex3f(9.0f, 6.7164f, 0.0f);
    glVertex3f(9.0667f, 6.7164f, 0.0f);
    glVertex3f(9.1333f, 6.7164f, 0.0f);
    glVertex3f(9.2f, 6.7164f, 0.0f);
    glVertex3f(9.2667f, 6.7164f, 0.0f);
    glVertex3f(9.3333f, 6.791f, 0.0f);
    glVertex3f(9.4f, 6.791f, 0.0f);
    glVertex3f(9.4667f, 6.791f, 0.0f);
    glVertex3f(9.6f, 6.791f, 0.0f);
    glVertex3f(9.6667f, 6.791f, 0.0f);
    glVertex3f(9.7333f, 6.791f, 0.0f);
    glVertex3f(9.8f, 6.791f, 0.0f);
    glVertex3f(9.9333f, 6.791f, 0.0f);
    glVertex3f(10.0f, 6.791f, 0.0f);
    glVertex3f(10.0667f, 6.791f, 0.0f);
    glVertex3f(10.1333f, 6.791f, 0.0f);
    glVertex3f(10.2f, 6.791f, 0.0f);
    glVertex3f(10.2667f, 6.791f, 0.0f);
    glVertex3f(10.3333f, 6.791f, 0.0f);
    glVertex3f(10.4667f, 6.791f, 0.0f);
    glVertex3f(10.5333f, 6.791f, 0.0f);
    glVertex3f(10.6f, 6.791f, 0.0f);
    glVertex3f(10.6667f, 6.791f, 0.0f);
    glVertex3f(10.8f, 6.791f, 0.0f);
    glVertex3f(10.8667f, 6.791f, 0.0f);
    glVertex3f(10.9333f, 6.791f, 0.0f);
    glVertex3f(11.0667f, 6.791f, 0.0f);
    glVertex3f(11.1333f, 6.791f, 0.0f);
    glVertex3f(11.2f, 6.791f, 0.0f);
    glVertex3f(11.2667f, 6.791f, 0.0f);
    glVertex3f(11.3333f, 6.7164f, 0.0f);
    glVertex3f(11.4f, 6.7164f, 0.0f);
    glVertex3f(11.5333f, 6.7164f, 0.0f);
    glVertex3f(11.6f, 6.7164f, 0.0f);
    glVertex3f(11.6667f, 6.6418f, 0.0f);
    glVertex3f(11.7333f, 6.6418f, 0.0f);
    glVertex3f(11.8f, 6.6418f, 0.0f);
    glVertex3f(11.8667f, 6.6418f, 0.0f);
    glVertex3f(11.9333f, 6.6418f, 0.0f);
    glVertex3f(12.0f, 6.6418f, 0.0f);
    glVertex3f(12.0667f, 6.5672f, 0.0f);
    glVertex3f(12.1333f, 6.5672f, 0.0f);
    glVertex3f(12.2f, 6.5672f, 0.0f);
    glVertex3f(12.2667f, 6.5672f, 0.0f);
    glVertex3f(12.3333f, 6.5672f, 0.0f);
    glVertex3f(12.4f, 6.4925f, 0.0f);
    glVertex3f(12.4667f, 6.4925f, 0.0f);
    glVertex3f(12.5333f, 6.4925f, 0.0f);
    glVertex3f(12.6f, 6.4925f, 0.0f);
    glVertex3f(12.6f, 6.4179f, 0.0f);
    glVertex3f(12.6667f, 6.4179f, 0.0f);
    glVertex3f(12.7333f, 6.4179f, 0.0f);
    glVertex3f(12.8f, 6.4179f, 0.0f);
    glVertex3f(12.8667f, 6.4179f, 0.0f);
    glVertex3f(12.9333f, 6.4179f, 0.0f);
    glVertex3f(13.0f, 6.4179f, 0.0f);
    glVertex3f(13.0667f, 6.4179f, 0.0f);
    glVertex3f(13.1333f, 6.4179f, 0.0f);
    glVertex3f(13.2f, 6.4179f, 0.0f);
    glVertex3f(13.2667f, 6.4179f, 0.0f);
    glVertex3f(13.3333f, 6.4179f, 0.0f);
    glVertex3f(13.4f, 6.4179f, 0.0f);
    glVertex3f(13.4f, 6.3433f, 0.0f);
    glVertex3f(13.4667f, 6.3433f, 0.0f);
    glVertex3f(13.5333f, 6.3433f, 0.0f);
    glVertex3f(13.6f, 6.3433f, 0.0f);
    glVertex3f(13.6667f, 6.3433f, 0.0f);
    glVertex3f(13.6667f, 6.2687f, 0.0f);
    glVertex3f(13.7333f, 6.2687f, 0.0f);
    glVertex3f(13.8f, 6.194f, 0.0f);
    glVertex3f(13.8667f, 6.194f, 0.0f);
    glVertex3f(13.9333f, 6.194f, 0.0f);
    glVertex3f(13.9333f, 6.1194f, 0.0f);
    glVertex3f(14.0f, 6.1194f, 0.0f);
    glVertex3f(14.0667f, 6.1194f, 0.0f);
    glVertex3f(14.1333f, 6.0448f, 0.0f);
    glVertex3f(14.1333f, 5.9701f, 0.0f);
    glVertex3f(14.0667f, 5.9701f, 0.0f);
    glVertex3f(14.0f, 5.8955f, 0.0f);
    glVertex3f(13.9333f, 5.8955f, 0.0f);
    glVertex3f(13.8667f, 5.8955f, 0.0f);
    glVertex3f(13.8f, 5.8955f, 0.0f);
    glVertex3f(13.7333f, 5.8955f, 0.0f);
    glVertex3f(13.6667f, 5.8955f, 0.0f);
    glVertex3f(13.6f, 5.8955f, 0.0f);
    glVertex3f(13.5333f, 5.8955f, 0.0f);
    glVertex3f(13.4667f, 5.8955f, 0.0f);
    glVertex3f(13.4f, 5.8955f, 0.0f);
    glVertex3f(13.3333f, 5.8955f, 0.0f);
    glVertex3f(13.2667f, 5.8955f, 0.0f);
    glVertex3f(13.2f, 5.8955f, 0.0f);
    glVertex3f(13.1333f, 5.8955f, 0.0f);
    glVertex3f(13.0667f, 5.8955f, 0.0f);
    glVertex3f(13.0f, 5.8209f, 0.0f);
    glVertex3f(12.9333f, 5.8209f, 0.0f);
    glVertex3f(12.8667f, 5.8209f, 0.0f);
    glVertex3f(12.8f, 5.7463f, 0.0f);
    glVertex3f(12.7333f, 5.7463f, 0.0f);
    glVertex3f(12.6667f, 5.7463f, 0.0f);
    glVertex3f(12.6667f, 5.6716f, 0.0f);
    glVertex3f(12.6f, 5.6716f, 0.0f);
    glVertex3f(12.5333f, 5.6716f, 0.0f);
    glVertex3f(12.4667f, 5.6716f, 0.0f);
    glVertex3f(12.4f, 5.6716f, 0.0f);
    glVertex3f(12.4f, 5.597f, 0.0f);
    glVertex3f(12.3333f, 5.597f, 0.0f);
    glVertex3f(12.2667f, 5.597f, 0.0f);
    glVertex3f(12.2f, 5.597f, 0.0f);
    glVertex3f(12.1333f, 5.5224f, 0.0f);
    glVertex3f(12.0667f, 5.5224f, 0.0f);
    glVertex3f(12.0f, 5.5224f, 0.0f);
    glVertex3f(11.9333f, 5.5224f, 0.0f);
    glVertex3f(11.8667f, 5.5224f, 0.0f);
    glVertex3f(11.8f, 5.5224f, 0.0f);
    glVertex3f(11.8f, 5.4478f, 0.0f);
    glVertex3f(11.7333f, 5.4478f, 0.0f);
    glVertex3f(11.6667f, 5.4478f, 0.0f);
    glVertex3f(11.6f, 5.4478f, 0.0f);
    glVertex3f(11.6f, 5.3731f, 0.0f);
    glVertex3f(11.5333f, 5.3731f, 0.0f);
    glVertex3f(11.4667f, 5.3731f, 0.0f);
    glVertex3f(11.4f, 5.3731f, 0.0f);
    glVertex3f(11.3333f, 5.3731f, 0.0f);
    glVertex3f(11.2667f, 5.3731f, 0.0f);
    glVertex3f(11.2f, 5.3731f, 0.0f);
    glVertex3f(11.1333f, 5.3731f, 0.0f);
    glVertex3f(11.0667f, 5.2985f, 0.0f);
    glVertex3f(11.0f, 5.2985f, 0.0f);
    glVertex3f(10.9333f, 5.2985f, 0.0f);
    glVertex3f(10.8667f, 5.2985f, 0.0f);
    glVertex3f(10.8f, 5.2985f, 0.0f);
    glVertex3f(10.7333f, 5.2985f, 0.0f);
    glVertex3f(10.6667f, 5.2985f, 0.0f);
    glVertex3f(10.6f, 5.2985f, 0.0f);
    glVertex3f(10.5333f, 5.2985f, 0.0f);
    glVertex3f(10.4667f, 5.2985f, 0.0f);
    glVertex3f(10.4f, 5.2985f, 0.0f);
    glVertex3f(10.3333f, 5.2985f, 0.0f);
    glVertex3f(10.2667f, 5.2985f, 0.0f);
    glVertex3f(10.2f, 5.2985f, 0.0f);
    glVertex3f(10.1333f, 5.2985f, 0.0f);
    glVertex3f(10.0667f, 5.2985f, 0.0f);
    glVertex3f(10.0f, 5.2985f, 0.0f);
    glVertex3f(9.9333f, 5.2985f, 0.0f);
    glVertex3f(9.8667f, 5.2985f, 0.0f);
    glVertex3f(9.8f, 5.2985f, 0.0f);
    glVertex3f(9.7333f, 5.2985f, 0.0f);
    glVertex3f(9.6667f, 5.2985f, 0.0f);
    glVertex3f(9.6f, 5.2985f, 0.0f);
    glVertex3f(9.5333f, 5.2985f, 0.0f);
    glVertex3f(9.4667f, 5.2985f, 0.0f);
    glVertex3f(9.4f, 5.2985f, 0.0f);
    glVertex3f(9.3333f, 5.2985f, 0.0f);
    glVertex3f(9.2667f, 5.2985f, 0.0f);
    glVertex3f(9.2f, 5.2985f, 0.0f);
    glVertex3f(9.1333f, 5.2985f, 0.0f);
    glVertex3f(9.0667f, 5.2985f, 0.0f);
    glVertex3f(9.0f, 5.2985f, 0.0f);
    glVertex3f(8.9333f, 5.2985f, 0.0f);
    glVertex3f(8.8667f, 5.2985f, 0.0f);
    glVertex3f(8.8667f, 5.2239f, 0.0f);
    glVertex3f(8.8f, 5.2239f, 0.0f);
    glVertex3f(8.7333f, 5.2239f, 0.0f);
    glVertex3f(8.6667f, 5.2239f, 0.0f);
    glVertex3f(8.6f, 5.2239f, 0.0f);
    glVertex3f(8.5333f, 5.2239f, 0.0f);
    glVertex3f(8.4667f, 5.2239f, 0.0f);
    glVertex3f(8.4f, 5.2239f, 0.0f);
    glVertex3f(8.3333f, 5.2239f, 0.0f);
    glVertex3f(8.2667f, 5.2239f, 0.0f);
    glVertex3f(8.2f, 5.2239f, 0.0f);
    glVertex3f(8.1333f, 5.2239f, 0.0f);
    glVertex3f(8.0667f, 5.2239f, 0.0f);
    glVertex3f(8.0f, 5.2239f, 0.0f);
    glVertex3f(7.9333f, 5.2239f, 0.0f);
    glVertex3f(7.8667f, 5.2239f, 0.0f);
    glVertex3f(7.8f, 5.2239f, 0.0f);
    glVertex3f(7.7333f, 5.2239f, 0.0f);
    glVertex3f(7.6667f, 5.2239f, 0.0f);
    glVertex3f(7.6f, 5.2239f, 0.0f);
    glVertex3f(7.5333f, 5.2239f, 0.0f);
    glVertex3f(7.4667f, 5.2239f, 0.0f);
    glVertex3f(7.4f, 5.2239f, 0.0f);
    glVertex3f(7.3333f, 5.2239f, 0.0f);
    glVertex3f(7.2667f, 5.2239f, 0.0f);
    glVertex3f(7.2f, 5.2239f, 0.0f);
    glVertex3f(7.1333f, 5.2239f, 0.0f);
    glVertex3f(7.0667f, 5.2239f, 0.0f);
    glVertex3f(7.0f, 5.2239f, 0.0f);
    glVertex3f(6.9333f, 5.2239f, 0.0f);
    glVertex3f(6.8667f, 5.2239f, 0.0f);
    glVertex3f(6.8f, 5.2239f, 0.0f);
    glVertex3f(6.7333f, 5.2239f, 0.0f);
    glVertex3f(6.6667f, 5.2239f, 0.0f);
    glVertex3f(6.6f, 5.2239f, 0.0f);
    glVertex3f(6.5333f, 5.2239f, 0.0f);
    glVertex3f(6.4667f, 5.2239f, 0.0f);
    glVertex3f(6.4f, 5.2239f, 0.0f);
    glVertex3f(6.3333f, 5.2239f, 0.0f);
    glVertex3f(6.2667f, 5.2239f, 0.0f);
    glVertex3f(6.2f, 5.2239f, 0.0f);
    glVertex3f(6.1333f, 5.2239f, 0.0f);
    glVertex3f(6.0667f, 5.2239f, 0.0f);
    glVertex3f(6.0667f, 5.2985f, 0.0f);
    glVertex3f(6.0f, 5.2985f, 0.0f);
    glVertex3f(5.9333f, 5.2985f, 0.0f);
    glVertex3f(5.8667f, 5.2985f, 0.0f);
    glVertex3f(5.8f, 5.2985f, 0.0f);
    glVertex3f(5.7333f, 5.2985f, 0.0f);
    glVertex3f(5.6667f, 5.2985f, 0.0f);
    glVertex3f(5.6f, 5.2985f, 0.0f);
    glVertex3f(5.5333f, 5.2985f, 0.0f);
    glVertex3f(5.4667f, 5.2985f, 0.0f);
    glVertex3f(5.4f, 5.2985f, 0.0f);
    glVertex3f(5.3333f, 5.2985f, 0.0f);
    glVertex3f(5.2667f, 5.2985f, 0.0f);
    glVertex3f(5.2667f, 5.3731f, 0.0f);
    glVertex3f(5.2f, 5.3731f, 0.0f);
    glVertex3f(5.1333f, 5.3731f, 0.0f);
    glVertex3f(5.0667f, 5.3731f, 0.0f);
    glVertex3f(5.0f, 5.3731f, 0.0f);
    glVertex3f(4.9333f, 5.3731f, 0.0f);
    glVertex3f(4.8667f, 5.3731f, 0.0f);
    glVertex3f(4.8f, 5.3731f, 0.0f);
    glVertex3f(4.7333f, 5.3731f, 0.0f);
    glVertex3f(4.6667f, 5.3731f, 0.0f);
    glVertex3f(4.6667f, 5.4478f, 0.0f);
    glVertex3f(4.6f, 5.4478f, 0.0f);
    glVertex3f(4.5333f, 5.4478f, 0.0f);
    glVertex3f(4.4667f, 5.4478f, 0.0f);
    glVertex3f(4.4f, 5.4478f, 0.0f);
    glVertex3f(4.3333f, 5.4478f, 0.0f);
    glVertex3f(4.2667f, 5.4478f, 0.0f);
    glVertex3f(4.2f, 5.4478f, 0.0f);
    glVertex3f(4.1333f, 5.4478f, 0.0f);
    glVertex3f(4.0667f, 5.4478f, 0.0f);
    glVertex3f(4.0667f, 5.5224f, 0.0f);
    glVertex3f(4.0f, 5.5224f, 0.0f);
    glVertex3f(3.9333f, 5.5224f, 0.0f);
    glVertex3f(3.8667f, 5.5224f, 0.0f);
    glVertex3f(3.8f, 5.5224f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.478, 0.043);
    glVertex3f(3.1333f, 8.2836f, 0.0f);
    glVertex3f(4.1333f, 5.9701f, 0.0f);
    glVertex3f(12.9333f, 6.194f, 0.0f);
    glVertex3f(15.4f, 9.0299f, 0.0f);

    glColor3f(0.416, 0.776, 0.208);
    glVertex3f(2.8f, 8.1343f, 0.0f);
    glVertex3f(16.0f, 9.1791f, 0.0f);
    glVertex3f(15.5333f, 8.2836f, 0.0f);
    glVertex3f(3.2f, 7.6866f, 0.0f);


    glColor3f(0.459, 0.004, 0.141);
    glVertex3f(3.7333f, 7.0149f, 0.0f);
    glVertex3f(14.1333f, 7.5373f, 0.0f);
    glVertex3f(13.8f, 7.1642f, 0.0f);
    glVertex3f(3.8f, 6.791f, 0.0f);

    glVertex3f(3.9333f, 6.4925f, 0.0f);
    glVertex3f(13.5333f, 6.8657f, 0.0f);
    glVertex3f(13.4f, 6.6418f, 0.0f);
    glVertex3f(4.1333f, 6.194f, 0.0f);


    glColor3f(0.886, 0.431, 0.145);
    glVertex3f(3.4f, 7.6866f, 0.0f);
    glVertex3f(11.1333f, 8.1343f, 0.0f);
    glVertex3f(6.5333f, 7.3134f, 0.0f);
    glVertex3f(3.6667f, 7.0896f, 0.0f);

    glColor3f(1.0, 0.804, 0.0);
    glVertex3f(4.5333f, 8.4328f, 0.0f);
    glVertex3f(4.6f, 11.4179f, 0.0f);
    glVertex3f(6.8f, 11.2687f, 0.0f);
    glVertex3f(7.4f, 8.5075f, 0.0f);

    glColor3f(0.969, 0.192, 0.196);
    glVertex3f(4.5333f, 11.7164f, 0.0f);
    glVertex3f(7.2f, 11.6418f, 0.0f);
    glVertex3f(7.2f, 11.194f, 0.0f);
    glVertex3f(4.6f, 11.2687f, 0.0f);


    glColor3f(1.0, 1.0, 0.992);
    glVertex3f(4.8f, 10.2985f, 0.0f);
    glVertex3f(4.8f, 10.9701f, 0.0f);
    glVertex3f(5.2667f, 10.9701f, 0.0f);
    glVertex3f(5.3333f, 10.2239f, 0.0f);

    glVertex3f(5.5333f, 11.0448f, 0.0f);
    glVertex3f(6.0f, 10.9701f, 0.0f);
    glVertex3f(6.0f, 10.3731f, 0.0f);
    glVertex3f(5.4667f, 10.2985f, 0.0f);

    glVertex3f(6.2f, 10.9701f, 0.0f);
    glVertex3f(6.6667f, 10.9701f, 0.0f);
    glVertex3f(6.8667f, 10.2239f, 0.0f);
    glVertex3f(6.2667f, 10.2239f, 0.0f);

    glColor3f(0.0, 0.686, 0.933);
    glVertex3f(7.4667f, 8.5821f, 0.0f);
    glVertex3f(7.2f, 9.7761f, 0.0f);
    glVertex3f(9.6667f, 10.0f, 0.0f);
    glVertex3f(10.4f, 8.806f, 0.0f);


    glColor3f(1.0, 0.996, 1.0);
    glVertex3f(7.4667f, 9.7015f, 0.0f);
    glVertex3f(7.8667f, 9.7015f, 0.0f);
    glVertex3f(7.8667f, 9.2537f, 0.0f);
    glVertex3f(7.5333f, 9.1791f, 0.0f);

    glVertex3f(8.1333f, 9.7015f, 0.0f);
    glVertex3f(8.4f, 9.7761f, 0.0f);
    glVertex3f(8.4667f, 9.2537f, 0.0f);
    glVertex3f(8.1333f, 9.2537f, 0.0f);

    glVertex3f(8.6667f, 9.7015f, 0.0f);
    glVertex3f(9.0667f, 9.7015f, 0.0f);
    glVertex3f(9.0f, 9.2537f, 0.0f);
    glVertex3f(8.7333f, 9.2537f, 0.0f);

    glVertex3f(9.2667f, 9.6269f, 0.0f);
    glVertex3f(9.5333f, 9.7015f, 0.0f);
    glVertex3f(9.6667f, 9.403f, 0.0f);
    glVertex3f(9.3333f, 9.2537f, 0.0f);


    glColor3f(0.463, 0.0, 0.133);
    glVertex3f(13.1333f, 9.1045f, 0.0f);
    glVertex3f(13.1333f, 13.7313f, 0.0f);
    glVertex3f(13.2f, 13.7313f, 0.0f);
    glVertex3f(13.4f, 9.0299f, 0.0f);


    glColor3f(0.992, 0.475, 0.047);
    glVertex3f(11.3333f, 8.9552f, 0.0f);
    glVertex3f(13.2f, 12.9104f, 0.0f);
    glVertex3f(13.2f, 12.3881f, 0.0f);
    glVertex3f(11.8f, 8.9552f, 0.0f);


    glVertex3f(13.2f, 12.5373f, 0.0f);
    glVertex3f(13.1333f, 12.9104f, 0.0f);
    glVertex3f(15.0f, 9.1791f, 0.0f);
    glVertex3f(14.6667f, 9.1791f, 0.0f);


    glColor3f(1.0, 0.055, 0.118);
    glVertex3f(13.2f, 13.7313f, 0.0f);
    glVertex3f(13.4667f, 13.9552f, 0.0f);
    glVertex3f(14.7333f, 13.5821f, 0.0f);
    glVertex3f(13.2667f, 13.0597f, 0.0f);


    glColor3f(1.0, 1.0, 0.796);
    glVertex3f(4.6f, 9.8507f, 0.0f);
    glVertex3f(7.1333f, 9.9254f, 0.0f);
    glVertex3f(7.3333f, 9.0299f, 0.0f);
    glVertex3f(4.6f, 8.806f, 0.0f);
    glEnd();




    //first boat end




    glPopMatrix();
    bx += .01;
    if (bx > 45)
        bx = -30;
    glutPostRedisplay();

}





void boat2()
{

    // 2nd BOAT Draw

    glLoadIdentity();
    glTranslatef(xPos, yPos, 0.0f);



    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.608, 0.859, 0.996);



    glVertex3f(34.9333f, 3.5075f, 0.0f);
    glVertex3f(34.8667f, 3.5075f, 0.0f);
    glVertex3f(34.8667f, 3.4328f, 0.0f);
    glVertex3f(34.8f, 3.4328f, 0.0f);
    glVertex3f(34.6667f, 3.3582f, 0.0f);
    glVertex3f(34.6f, 3.3582f, 0.0f);
    glVertex3f(34.4667f, 3.2836f, 0.0f);
    glVertex3f(34.4f, 3.209f, 0.0f);
    glVertex3f(34.3333f, 3.209f, 0.0f);
    glVertex3f(34.2667f, 3.209f, 0.0f);
    glVertex3f(34.2667f, 3.1343f, 0.0f);
    glVertex3f(34.2667f, 3.0597f, 0.0f);
    glVertex3f(34.2667f, 2.9851f, 0.0f);
    glVertex3f(34.4f, 2.9104f, 0.0f);
    glVertex3f(34.4f, 2.8358f, 0.0f);
    glVertex3f(34.4667f, 2.8358f, 0.0f);
    glVertex3f(34.5333f, 2.7612f, 0.0f);
    glVertex3f(34.6f, 2.7612f, 0.0f);
    glVertex3f(34.6667f, 2.7612f, 0.0f);
    glVertex3f(34.7333f, 2.7612f, 0.0f);
    glVertex3f(34.8f, 2.7612f, 0.0f);
    glVertex3f(34.8667f, 2.7612f, 0.0f);
    glVertex3f(34.9333f, 2.6866f, 0.0f);
    glVertex3f(35.0f, 2.6866f, 0.0f);
    glVertex3f(35.0667f, 2.6866f, 0.0f);
    glVertex3f(35.1333f, 2.6866f, 0.0f);
    glVertex3f(35.2f, 2.6866f, 0.0f);
    glVertex3f(35.2667f, 2.6119f, 0.0f);
    glVertex3f(35.3333f, 2.6119f, 0.0f);
    glVertex3f(35.4f, 2.6119f, 0.0f);
    glVertex3f(35.4667f, 2.6119f, 0.0f);
    glVertex3f(35.5333f, 2.6119f, 0.0f);
    glVertex3f(35.6f, 2.6119f, 0.0f);
    glVertex3f(35.6667f, 2.6119f, 0.0f);
    glVertex3f(35.7333f, 2.6119f, 0.0f);
    glVertex3f(35.8f, 2.6119f, 0.0f);
    glVertex3f(35.8667f, 2.6119f, 0.0f);
    glVertex3f(35.9333f, 2.6119f, 0.0f);
    glVertex3f(36.0f, 2.6119f, 0.0f);
    glVertex3f(36.0667f, 2.6119f, 0.0f);
    glVertex3f(36.1333f, 2.6119f, 0.0f);
    glVertex3f(36.2f, 2.6119f, 0.0f);
    glVertex3f(36.2667f, 2.6119f, 0.0f);
    glVertex3f(36.3333f, 2.6119f, 0.0f);
    glVertex3f(36.4f, 2.6119f, 0.0f);
    glVertex3f(36.4667f, 2.6119f, 0.0f);
    glVertex3f(36.5333f, 2.6119f, 0.0f);
    glVertex3f(36.6f, 2.6119f, 0.0f);
    glVertex3f(36.7333f, 2.6119f, 0.0f);
    glVertex3f(36.8f, 2.6119f, 0.0f);
    glVertex3f(36.9333f, 2.6119f, 0.0f);
    glVertex3f(37.0f, 2.6119f, 0.0f);
    glVertex3f(37.0667f, 2.6119f, 0.0f);
    glVertex3f(37.1333f, 2.6119f, 0.0f);
    glVertex3f(37.2f, 2.6119f, 0.0f);
    glVertex3f(37.2667f, 2.6119f, 0.0f);
    glVertex3f(37.3333f, 2.6119f, 0.0f);
    glVertex3f(37.4f, 2.6119f, 0.0f);
    glVertex3f(37.4667f, 2.6119f, 0.0f);
    glVertex3f(37.5333f, 2.6119f, 0.0f);
    glVertex3f(37.6f, 2.6119f, 0.0f);
    glVertex3f(37.6667f, 2.6119f, 0.0f);
    glVertex3f(37.7333f, 2.6119f, 0.0f);
    glVertex3f(37.8f, 2.6119f, 0.0f);
    glVertex3f(37.8667f, 2.6119f, 0.0f);
    glVertex3f(37.9333f, 2.6119f, 0.0f);
    glVertex3f(38.0f, 2.6119f, 0.0f);
    glVertex3f(38.0667f, 2.6119f, 0.0f);
    glVertex3f(38.1333f, 2.6119f, 0.0f);
    glVertex3f(38.2f, 2.6119f, 0.0f);
    glVertex3f(38.2667f, 2.6119f, 0.0f);
    glVertex3f(38.3333f, 2.6119f, 0.0f);
    glVertex3f(38.4f, 2.6119f, 0.0f);
    glVertex3f(38.4667f, 2.6119f, 0.0f);
    glVertex3f(38.5333f, 2.6119f, 0.0f);
    glVertex3f(38.6667f, 2.6119f, 0.0f);
    glVertex3f(38.7333f, 2.6119f, 0.0f);
    glVertex3f(38.8f, 2.6119f, 0.0f);
    glVertex3f(38.8667f, 2.6119f, 0.0f);
    glVertex3f(38.9333f, 2.6119f, 0.0f);
    glVertex3f(39.0f, 2.6119f, 0.0f);
    glVertex3f(39.0667f, 2.6119f, 0.0f);
    glVertex3f(39.1333f, 2.6119f, 0.0f);
    glVertex3f(39.2f, 2.6119f, 0.0f);
    glVertex3f(39.2667f, 2.6119f, 0.0f);
    glVertex3f(39.4667f, 2.6119f, 0.0f);
    glVertex3f(39.5333f, 2.6119f, 0.0f);
    glVertex3f(39.6f, 2.6119f, 0.0f);
    glVertex3f(39.6667f, 2.6119f, 0.0f);
    glVertex3f(39.7333f, 2.6119f, 0.0f);
    glVertex3f(39.8f, 2.6119f, 0.0f);
    glVertex3f(39.8667f, 2.6119f, 0.0f);
    glVertex3f(39.9333f, 2.6119f, 0.0f);
    glVertex3f(40.0f, 2.6119f, 0.0f);
    glVertex3f(40.0667f, 2.6119f, 0.0f);
    glVertex3f(40.1333f, 2.6119f, 0.0f);
    glVertex3f(40.2f, 2.6119f, 0.0f);
    glVertex3f(40.2667f, 2.6119f, 0.0f);
    glVertex3f(40.3333f, 2.6119f, 0.0f);
    glVertex3f(40.4f, 2.6119f, 0.0f);
    glVertex3f(40.4667f, 2.6119f, 0.0f);
    glVertex3f(40.5333f, 2.6119f, 0.0f);
    glVertex3f(40.6f, 2.6119f, 0.0f);
    glVertex3f(40.6667f, 2.6119f, 0.0f);
    glVertex3f(40.7333f, 2.6119f, 0.0f);
    glVertex3f(40.8f, 2.6119f, 0.0f);
    glVertex3f(40.8667f, 2.6119f, 0.0f);
    glVertex3f(40.9333f, 2.6119f, 0.0f);
    glVertex3f(41.0f, 2.6119f, 0.0f);
    glVertex3f(41.0667f, 2.6119f, 0.0f);
    glVertex3f(41.1333f, 2.6119f, 0.0f);
    glVertex3f(41.2f, 2.6119f, 0.0f);
    glVertex3f(41.2667f, 2.6866f, 0.0f);
    glVertex3f(41.3333f, 2.6866f, 0.0f);
    glVertex3f(41.3333f, 2.7612f, 0.0f);
    glVertex3f(41.4f, 2.7612f, 0.0f);
    glVertex3f(41.4667f, 2.8358f, 0.0f);
    glVertex3f(41.5333f, 2.8358f, 0.0f);
    glVertex3f(41.5333f, 2.9104f, 0.0f);
    glVertex3f(41.5333f, 2.9851f, 0.0f);
    glVertex3f(41.5333f, 3.0597f, 0.0f);
    glVertex3f(41.4667f, 3.1343f, 0.0f);
    glVertex3f(41.4f, 3.1343f, 0.0f);
    glVertex3f(41.3333f, 3.1343f, 0.0f);
    glVertex3f(41.2667f, 3.1343f, 0.0f);
    glVertex3f(41.2f, 3.1343f, 0.0f);
    glVertex3f(41.1333f, 3.1343f, 0.0f);
    glVertex3f(41.0667f, 3.1343f, 0.0f);
    glVertex3f(41.0f, 3.1343f, 0.0f);
    glVertex3f(40.9333f, 3.1343f, 0.0f);
    glVertex3f(40.8667f, 3.1343f, 0.0f);
    glVertex3f(40.8f, 3.1343f, 0.0f);
    glVertex3f(40.7333f, 3.1343f, 0.0f);
    glVertex3f(40.6667f, 3.209f, 0.0f);
    glVertex3f(40.6f, 3.209f, 0.0f);
    glVertex3f(40.5333f, 3.209f, 0.0f);
    glVertex3f(40.4667f, 3.209f, 0.0f);
    glVertex3f(40.4f, 3.209f, 0.0f);
    glVertex3f(40.3333f, 3.209f, 0.0f);
    glVertex3f(40.2667f, 3.2836f, 0.0f);
    glVertex3f(40.2f, 3.2836f, 0.0f);
    glVertex3f(40.0667f, 3.2836f, 0.0f);
    glVertex3f(40.0f, 3.2836f, 0.0f);
    glVertex3f(39.9333f, 3.2836f, 0.0f);
    glVertex3f(39.8667f, 3.2836f, 0.0f);
    glVertex3f(39.7333f, 3.2836f, 0.0f);
    glVertex3f(39.6667f, 3.2836f, 0.0f);
    glVertex3f(39.6f, 3.2836f, 0.0f);
    glVertex3f(39.5333f, 3.2836f, 0.0f);
    glVertex3f(39.4f, 3.2836f, 0.0f);
    glVertex3f(39.2667f, 3.2836f, 0.0f);
    glVertex3f(39.0667f, 3.2836f, 0.0f);
    glVertex3f(38.8667f, 3.2836f, 0.0f);
    glVertex3f(38.6667f, 3.2836f, 0.0f);
    glVertex3f(38.4f, 3.2836f, 0.0f);
    glVertex3f(38.3333f, 3.2836f, 0.0f);
    glVertex3f(38.2f, 3.3582f, 0.0f);
    glVertex3f(38.1333f, 3.3582f, 0.0f);
    glVertex3f(38.0667f, 3.3582f, 0.0f);
    glVertex3f(38.0f, 3.3582f, 0.0f);
    glVertex3f(37.8667f, 3.4328f, 0.0f);
    glVertex3f(37.7333f, 3.4328f, 0.0f);
    glVertex3f(37.6667f, 3.5075f, 0.0f);
    glVertex3f(37.6f, 3.5075f, 0.0f);
    glVertex3f(37.4667f, 3.5821f, 0.0f);
    glVertex3f(37.4f, 3.5821f, 0.0f);
    glVertex3f(37.3333f, 3.5821f, 0.0f);
    glVertex3f(37.2667f, 3.5821f, 0.0f);
    glVertex3f(37.2f, 3.5821f, 0.0f);
    glVertex3f(37.1333f, 3.5821f, 0.0f);
    glVertex3f(36.9333f, 3.6567f, 0.0f);
    glVertex3f(36.7333f, 3.7313f, 0.0f);
    glVertex3f(36.6f, 3.806f, 0.0f);
    glVertex3f(36.4667f, 3.806f, 0.0f);
    glVertex3f(36.4f, 3.806f, 0.0f);
    glVertex3f(36.3333f, 3.806f, 0.0f);
    glVertex3f(36.2667f, 3.806f, 0.0f);
    glVertex3f(36.2f, 3.806f, 0.0f);
    glVertex3f(36.1333f, 3.806f, 0.0f);
    glVertex3f(36.0667f, 3.8806f, 0.0f);
    glVertex3f(36.0f, 3.8806f, 0.0f);
    glVertex3f(35.9333f, 3.8806f, 0.0f);
    glVertex3f(35.8667f, 3.8806f, 0.0f);
    glVertex3f(35.8f, 3.8806f, 0.0f);
    glVertex3f(35.7333f, 3.8806f, 0.0f);
    glVertex3f(35.6667f, 3.806f, 0.0f);
    glVertex3f(35.6f, 3.806f, 0.0f);
    glVertex3f(35.5333f, 3.806f, 0.0f);
    glVertex3f(35.4667f, 3.806f, 0.0f);
    glVertex3f(35.4f, 3.806f, 0.0f);
    glVertex3f(35.2667f, 3.7313f, 0.0f);
    glVertex3f(35.2f, 3.7313f, 0.0f);
    glVertex3f(35.0667f, 3.7313f, 0.0f);
    glVertex3f(35.0667f, 3.6567f, 0.0f);
    glVertex3f(35.0f, 3.5821f, 0.0f);
    glVertex3f(34.9333f, 3.5075f, 0.0f);
    glVertex3f(34.8667f, 3.5075f, 0.0f);
    glVertex3f(34.8f, 3.4328f, 0.0f);
    glVertex3f(34.8f, 3.3582f, 0.0f);
    glVertex3f(34.7333f, 3.3582f, 0.0f);


    glEnd();





    glBegin(GL_QUADS);
    glColor3f(0.514, 0.573, 0.404);
    glVertex3f(38.8f, 3.8806f, 0.0f);
    glVertex3f(39.6667f, 5.9701f, 0.0f);
    glVertex3f(40.8667f, 5.9701f, 0.0f);
    glVertex3f(40.8f, 3.806f, 0.0f);

    glColor3f(0.71, 0.737, 0.537);
    glVertex3f(38.7333f, 3.9552f, 0.0f);
    glVertex3f(39.6667f, 5.9701f, 0.0f);
    glVertex3f(40.0667f, 6.0448f, 0.0f);
    glVertex3f(39.4667f, 3.806f, 0.0f);

    glColor3f(0.184, 0.235, 0.267);
    glVertex3f(39.6667f, 6.2687f, 0.0f);
    glVertex3f(40.8667f, 6.194f, 0.0f);
    glVertex3f(40.9333f, 5.9701f, 0.0f);
    glVertex3f(39.6f, 5.9701f, 0.0f);


    glVertex3f(39.1333f, 4.403f, 0.0f);
    glVertex3f(39.6667f, 5.6716f, 0.0f);
    glVertex3f(40.2f, 5.6716f, 0.0f);
    glVertex3f(40.2667f, 4.403f, 0.0f);

    glVertex3f(35.3333f, 4.3284f, 0.0f);
    glVertex3f(35.3333f, 9.0299f, 0.0f);
    glVertex3f(35.6667f, 8.8806f, 0.0f);
    glVertex3f(35.6667f, 4.1791f, 0.0f);

    glVertex3f(34.9333f, 8.5821f, 0.0f);
    glVertex3f(36.2f, 8.6567f, 0.0f);
    glVertex3f(36.0667f, 8.3582f, 0.0f);
    glVertex3f(34.9333f, 8.3582f, 0.0f);

    glColor3f(1.0, 0.306, 0.086);
    glVertex3f(35.1333f, 9.3284f, 0.0f);
    glVertex3f(35.9333f, 9.3284f, 0.0f);
    glVertex3f(35.9333f, 8.806f, 0.0f);
    glVertex3f(35.0667f, 8.806f, 0.0f);

    glColor3f(0.204, 0.247, 0.263);
    glVertex3f(36.3333f, 4.1791f, 0.0f);
    glVertex3f(36.3333f, 5.4478f, 0.0f);
    glVertex3f(36.4667f, 5.3731f, 0.0f);
    glVertex3f(36.5333f, 4.1045f, 0.0f);

    glVertex3f(36.2667f, 5.5224f, 0.0f);
    glVertex3f(37.3333f, 5.2985f, 0.0f);
    glVertex3f(37.0667f, 5.0746f, 0.0f);
    glVertex3f(36.3333f, 5.2239f, 0.0f);

    glVertex3f(36.6f, 4.1045f, 0.0f);
    glVertex3f(37.1333f, 5.2985f, 0.0f);
    glVertex3f(37.2667f, 5.1493f, 0.0f);
    glVertex3f(36.8667f, 4.1045f, 0.0f);

    glVertex3f(36.9333f, 5.2985f, 0.0f);
    glVertex3f(37.1333f, 5.3731f, 0.0f);
    glVertex3f(37.9333f, 3.8806f, 0.0f);
    glVertex3f(37.6f, 3.806f, 0.0f);


    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.514, 0.345, 0.271);
    glVertex3f(33.7333f, 5.1493f, 0.0f);
    glVertex3f(34.8667f, 3.209f, 0.0f);
    glVertex3f(41.1333f, 3.209f, 0.0f);
    glVertex3f(41.3333f, 3.8806f, 0.0f);
    glVertex3f(37.0f, 3.9552f, 0.0f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.541, 0.569, 0.396);
    glVertex3f(34.4f, 3.9552f, 0.0f);
    glVertex3f(41.0667f, 3.5075f, 0.0f);
    glVertex3f(41.1333f, 3.2836f, 0.0f);
    glVertex3f(34.7333f, 3.3582f, 0.0f);


    glEnd();


    //second boat end

}






// All the objects drawn here
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Write your code here

    if(isCityVisible)
        drawCity();
    else
        drawVillage();


    rain();

    glutSwapBuffers();
}



void drawCity()
{

    glLoadIdentity();
    glBegin(GL_QUADS);     // beach sand
    glColor3f(0.953, 0.722, 0.486);
    glVertex3f(0.0f, 13.6567f, 0.0f);
    glVertex3f(50.0f, 13.5821f, 0.0f);
    glVertex3f(50.0f, 12.6119f, 0.0f);
    glVertex3f(0.0f, 12.4627f, 0.0f);

    glColor3f(0.318, 0.976, 1.0);   // small water shade
    glVertex3f(0.0f, 12.4627f, 0.0f);
    glVertex3f(50.0f, 12.6119f, 0.0f);
    glVertex3f(50.0f, 11.8657f, 0.0f);
    glVertex3f(0.0f, 11.8657f, 0.0f);

    glColor3f(0.29, 0.792, 0.898); // water eith gradient color
    glVertex3f(0.0f, 11.8657f, 0.0f);
    glVertex3f(50.0f, 11.8657f, 0.0f);
    glColor3f(0.224, 0.588, 0.902);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glColor3f(1.0, 1.0, 0.91);  // whiteish background
    glVertex3f(0.0f, 13.6567f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glVertex3f(50.0f, 50.0f, 0.0f);
    glVertex3f(50.0f, 13.5821f, 0.0f);

    glColor3f(1.0, 1.0, 0.796); //1st SUN Ray
    glVertex3f(0.0f, 25.5224f, 0.0f);
    glVertex3f(0.0f, 33.0597f, 0.0f);
    glVertex3f(28.2f, 38.6567f, 0.0f);
    glVertex3f(28.8667f, 37.0896f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON); //2nd SUN Ray
    glColor3f(1.0, 1.0, 0.796);
    glVertex3f(0.0f, 45.6716f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glVertex3f(5.5333f, 50.0f, 0.0f);
    glVertex3f(28.6f, 40.4478f, 0.0f);
    glVertex3f(28.4f, 39.5522f, 0.0f);

    glEnd();

    glBegin(GL_QUADS); // 3rd SUN Ray
    glColor3f(1.0, 1.0, 0.796);
    glVertex3f(19.5333f, 50.0f, 0.0f);
    glVertex3f(24.2667f, 50.0f, 0.0f);
    glVertex3f(29.7333f, 41.6418f, 0.0f);
    glVertex3f(29.0667f, 40.9701f, 0.0f);

    // 4th SUN Ray
    glVertex3f(30.8f, 42.0896f, 0.0f);
    glVertex3f(28.4667f, 50.0f, 0.0f);
    glVertex3f(31.6f, 50.0, 0.0f);
    glVertex3f(31.7333f, 42.1642f, 0.0f);

    // 5th SUN Ray
    glVertex3f(32.6667f, 41.9403f, 0.0f);
    glVertex3f(36.3333f, 50.0f, 0.0f);
    glVertex3f(39.2667f, 50.0f, 0.0f);
    glVertex3f(33.4f, 41.1194f, 0.0f);

    // 6th SUN Ray
    glVertex3f(34.1333f, 40.2239f, 0.0f);
    glVertex3f(50.0f, 48.3582f, 0.0f);
    glVertex3f(50.0f, 44.7015f, 0.0f);
    glVertex3f(34.3333f, 39.403f, 0.0f);

    // 7th SUN Ray
    glVertex3f(34.6f, 38.5821f, 0.0f);
    glVertex3f(50.0f, 31.7164f, 0.0f);
    glVertex3f(50.0f, 26.3433f, 0.0f);
    glVertex3f(34.1333f, 37.0149f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON); //8th SUN Ray
    glColor3f(1.0, 1.0, 0.796);
    glVertex3f(33.8667f, 36.3433f, 0.0f);
    glVertex3f(50.0f, 16.9403f, 0.0f);
    glVertex3f(50.0f, 13.5821f, 0.0f);
    glVertex3f(44.3333f, 13.806f, 0.0f);
    glVertex3f(33.0667f, 35.8209f, 0.0f);

    glEnd();

    glBegin(GL_QUADS); // 9th SUN Ray
    glColor3f(1.0, 1.0, 0.796);
    glVertex3f(32.6667f, 35.3731f, 0.0f);
    glVertex3f(34.5333f, 25.1493f, 0.0f);
    glVertex3f(31.1333f, 24.4776f, 0.0f);
    glVertex3f(31.2f, 35.2985f, 0.0f);

    // 10th SUN Ray
    glVertex3f(26.5333f, 25.1493f, 0.0f);
    glVertex3f(30.1333f, 35.5224f, 0.0f);
    glVertex3f(29.4667f, 36.1194f, 0.0f);
    glVertex3f(23.2f, 24.9254f, 0.0f);

    glEnd();


    // ¬¬¬¬¬¬¬¬¬¬¬¬¬   SUN   ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    // SUN
    glColor3f(0.996, 0.765, 0.012); // set color to yellow
    drawCircle(31.2667, 38.7313f, 3.0); // draw a circle with radius 3.0
    glFlush();


// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Black - White Building 1st ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_QUADS);  // 1st building left side shade
    glColor3f(0.882, 0.882, 0.882);
    glVertex3f(4.5333f, 30.5224f, 0.0f);
    glVertex3f(5.7333f, 30.597f, 0.0f);
    glVertex3f(5.6667f, 13.6313f, 0.0f);
    glVertex3f(4.4667f, 13.6313f, 0.0f);

    glColor3f(0.933, 0.933, 0.933); // 1st building body shade
    glVertex3f(5.7333f, 30.597f, 0.0f);
    glVertex3f(11.0f, 30.5224f, 0.0f);
    glVertex3f(11.0f, 13.6313f, 0.0f);
    glVertex3f(5.6333f, 13.7113f, 0.0f);

    glEnd();

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬    set color to 1st apartment row wise    ¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    // 1st row
    glColor3f(0.988, 0.988, 0.988); // set color to apartment row wise
    drawCircle2(7, 29.17f, 0.4); // draw a circle with radius 0.4

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 29.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(9.0, 29.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 29.17f, 0.4);

    //2nd row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7, 28.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(8.0, 28.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 28.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 28.17f, 0.4);

    //3rd row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7.0, 27.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 27.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(9.0, 27.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(10.0, 27.17f, 0.4);

    //4th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(7.0, 26.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 26.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 26.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 26.17f, 0.4);

    //5th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(7.0, 25.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(8.0, 25.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 25.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(10.0, 25.17f, 0.4);

    //6th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7, 24.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 24.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(9.0, 24.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 24.17f, 0.4);

    //7th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(7.0, 23.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 23.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 23.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 23.17f, 0.4);

    //8th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7.0, 22.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 22.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(9.0, 22.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(10.0, 22.17f, 0.4);

    //9th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(7.0, 21.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(8.0, 21.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 21.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(10.0, 21.17f, 0.4);

    //10th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7, 20.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(8.0, 20.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 20.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 20.17f, 0.4);

    //11th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7, 19.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 19.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(9.0, 19.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 19.17f, 0.4);

    //12th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(7, 18.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 18.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 18.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 18.17f, 0.4);

    //13th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7, 17.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 17.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(9.0, 17.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 17.17f, 0.4);

    //14th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(7, 16.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 16.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 16.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 16.17f, 0.4);

    //15th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(7, 15.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(8.0, 15.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 15.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(10.0, 15.17f, 0.4);

    //16th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(7, 14.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(8.0, 14.17f, 0.4);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(9.0, 14.17f, 0.4);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(10.0, 14.17f, 0.4);


// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Black - White Building 2nd ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS); // 2nd building base

    glColor3f(0.867, 0.886, 0.871);
    glVertex3f(15.0667f, 13.6313f, 0.0f);
    glVertex3f(15.0667f, 14.4776f, 0.0f);
    glVertex3f(21.3333f, 14.4776f, 0.0f);
    glVertex3f(21.2667f, 13.6313f, 0.0f);

    glColor3f(0.961, 0.961, 0.961);   // big body phase - 1
    glVertex3f(15.4f, 14.403f, 0.0f);
    glVertex3f(15.4f, 33.2836f, 0.0f);
    glVertex3f(21.0f, 33.2836f, 0.0f);
    glVertex3f(20.8667f, 14.403f, 0.0f);

    glColor3f(0.961, 0.961, 0.961);   // big body phase - 2
    glVertex3f(15.8667f, 33.2836f, 0.0f);
    glVertex3f(15.8667f, 37.7612f, 0.0f);
    glVertex3f(20.4667f, 37.7612f, 0.0f);
    glVertex3f(20.4667f, 33.2836f, 0.0f);

    glColor3f(0.961, 0.961, 0.961);   // big body phase - 3
    glVertex3f(16.0f, 37.8358f, 0.0f);
    glVertex3f(16.0f, 41.0448f, 0.0f);
    glVertex3f(20.4f, 41.0448f, 0.0f);
    glVertex3f(20.4f, 37.8358f, 0.0f);

    glColor3f(0.961, 0.961, 0.961);   // big body phase - 4
    glVertex3f(16.4667f, 41.0448f, 0.0f);
    glVertex3f(16.4667f, 42.6119f, 0.0f);
    glVertex3f(19.9333f, 42.6119f, 0.0f);
    glVertex3f(19.9333f, 41.0448f, 0.0f);

    glColor3f(0.961, 0.961, 0.961);   // big body phase - 5
    glVertex3f(17.0f, 41.9851f, 0.0f);
    glVertex3f(17.0f, 44.1045f, 0.0f);
    glVertex3f(19.4f, 44.0299f, 0.0f);
    glVertex3f(19.4f, 42.6866f, 0.0f);

    glEnd();

    glBegin(GL_LINES);

    //middle white lines
    glColor3f(0.998, 0.998, 0.998);
    glVertex3f(16.4667f, 41.82835f, 0.0f);
    glVertex3f(19.9333f, 41.82835f, 0.0f);

    glColor3f(0.998, 0.998, 0.998);
    glVertex3f(16.0f, 39.8269f, 0.0f);
    glVertex3f(20.4f, 39.8269f, 0.0f);

    glVertex3f(16.0f, 39.0299f, 0.0f);
    glVertex3f(20.4f, 39.0299f, 0.0f);

    glVertex3f(15.8667f, 36.1194f, 0.0f);
    glVertex3f(20.4667f, 36.1194f, 0.0f);

    glVertex3f(15.8667f, 35.1194f, 0.0f);
    glVertex3f(20.4667f, 35.1194f, 0.0f);

    // base side bold lineing
    glColor3f(0.88, 0.84, 0.84);

    glVertex3f(15.4f, 33.2836f, 0.0f);
    glVertex3f(21.0f, 33.2836f, 0.0f);

    glVertex3f(15.8667f, 37.9104f, 0.0f);
    glVertex3f(20.4667f, 37.9104f, 0.0f);

    glVertex3f(16.0f, 41.0448f, 0.0f);
    glVertex3f(20.4f, 41.0448f, 0.0f);

    glVertex3f(16.4667f, 42.6119f, 0.0f);
    glVertex3f(19.9333f, 42.6119f, 0.0f);

    glVertex3f(16.4667f, 41.0448f, 0.0f);
    glVertex3f(16.4667f, 42.6119f, 0.0f);

    glVertex3f(19.9333f, 42.6119f, 0.0f);
    glVertex3f(19.9333f, 41.0448f, 0.0f);

    glVertex3f(16.0f, 37.8358f, 0.0f);
    glVertex3f(16.0f, 41.0448f, 0.0f);

    glVertex3f(20.4f, 41.0448f, 0.0f);
    glVertex3f(20.4f, 37.9104f, 0.0f);

    glVertex3f(15.8667f, 33.2836f, 0.0f);
    glVertex3f(15.8667f, 37.8812f, 0.0f);

    glVertex3f(20.4667f, 37.9104f, 0.0f);
    glVertex3f(20.4667f, 33.2828f, 0.0f);

    glVertex3f(21.0f, 33.2836f, 0.0f);
    glVertex3f(20.99f, 14.2537f, 0.0f);
    glEnd();

    glBegin(GL_LINES);

    // middle bold line rectangle

    glColor3f(0.88, 0.84, 0.84);
    glVertex3f(17.0f, 14.3284f, 0.0f);
    glVertex3f(17.0f, 44.1045f, 0.0f);

    glVertex3f(17.0f, 44.1045f, 0.0f);
    glVertex3f(19.4f, 44.0299f, 0.0f);

    glVertex3f(19.4f, 44.0299f, 0.0f);
    glVertex3f(19.4f, 14.403f, 0.0f);

    glVertex3f(19.4f, 14.403f, 0.0f);
    glVertex3f(17.0f, 14.403f, 0.0f);

    glEnd();

// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Black - White Building 3rd ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);

    glColor3f(0.882, 0.882, 0.882); // side shadow
    glVertex3f(41.8667f, 13.5567f, 0.0f);
    glVertex3f(41.8667f, 26.6418f, 0.0f);
    glVertex3f(42.6667f, 26.6418f, 0.0f);
    glVertex3f(42.6667f, 13.5567f, 0.0f);

    glColor3f(0.925, 0.925, 0.925); // body
    glVertex3f(42.6667f, 26.6418f, 0.0f);
    glVertex3f(46.8667f, 26.6418f, 0.0f);
    glVertex3f(46.8667f, 13.5567f, 0.0f);
    glVertex3f(42.6667f, 13.5567f, 0.0f);

    glEnd();


    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬    set color to 3rd apartment row wise    ¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    // 1st row
    glColor3f(0.988, 0.988, 0.988); // set color to apartment row wise
    drawCircle2(43.4667, 25.4478f, 0.3); // draw a circle with radius 0.4

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 25.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(45.4667, 25.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(46.4667, 25.4478f, 0.3);

    //2nd row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(43.4667, 24.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 24.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(45.4667, 24.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(46.4667, 24.4478f, 0.3);

    //3rd row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(43.4667, 23.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 23.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(45.4667, 23.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(46.4667, 23.4478f, 0.3);

    //4th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(43.4667, 22.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 22.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(45.4667, 22.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(46.4667, 22.4478f, 0.3);

    //5th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(43.4667, 21.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 21.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(45.4667, 21.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(46.4667, 21.4478f, 0.3);

    //6th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(43.4667, 20.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(44.4667, 20.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(45.4667, 20.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(46.4667, 20.4478f, 0.3);

    //7th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(43.4667, 19.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 19.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(45.4667, 19.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(46.4667, 19.4478f, 0.3);

    // 8th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(43.4667, 18.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 18.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(45.4667, 18.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(46.4667, 18.4478f, 0.3);

    // 9th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(43.4667, 17.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 17.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(45.4667, 17.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(46.4667, 17.4478f, 0.3);

    //10th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(43.4667, 16.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(44.4667, 16.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(45.4667, 16.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(46.4667, 16.4478f, 0.3);

    //11th row
    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(43.4667, 15.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 15.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(45.4667, 15.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(46.4667, 15.4478f, 0.3);

    //12th row
    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(43.4667, 14.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(44.4667, 14.4478f, 0.3);

    glColor3f(0.882, 0.890, 0.882);
    drawCircle2(45.4667, 14.4478f, 0.3);

    glColor3f(0.988, 0.988, 0.988);
    drawCircle2(46.4667, 14.4478f, 0.3);


    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Background Colored Building - 1  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);

    glColor3f(0.78, 0.322, 0.251); // building left side shadow
    glVertex3f(12.5333f, 13.606f, 0.0f);
    glVertex3f(12.5333f, 33.4328f, 0.0f);
    glVertex3f(14.6667f, 33.4328f, 0.0f);
    glVertex3f(14.6667f, 13.606f, 0.0f);


    glColor3f(0.133, 0.243, 0.259); // left side long apartment
    glVertex3f(13.0f, 14.7015f, 0.0f);
    glVertex3f(13.0f, 32.6866f, 0.0f);
    glVertex3f(13.5f, 32.6866f, 0.0f);
    glVertex3f(13.5f, 14.7015f, 0.0f);

    glVertex3f(13.8f, 14.7015f, 0.0f);
    glVertex3f(13.8f, 32.6866f, 0.0f);
    glVertex3f(14.3f, 32.6866f, 0.0f);
    glVertex3f(14.3f, 14.7015f, 0.0f);

    glColor3f(0.984, 0.451, 0.396);  // building right side shadow
    glVertex3f(14.6667f, 13.606f, 0.0f);
    glVertex3f(14.6667f, 33.4075f, 0.0f);
    glVertex3f(19.6f, 33.4075f, 0.0f);
    glVertex3f(19.6f, 13.606f, 0.0f);

    glColor3f(0.133, 0.243, 0.259); // right side long apartment
    glVertex3f(15.3333f, 14.7015f, 0.0f);
    glVertex3f(15.3333f, 32.6866f, 0.0f);
    glVertex3f(15.9333f, 32.6866f, 0.0f);
    glVertex3f(15.9333f, 14.7015f, 0.0f);

    glVertex3f(16.1333f, 14.7015f, 0.0f);
    glVertex3f(16.1333f, 32.6866f, 0.0f);
    glVertex3f(16.7333f, 32.6866f, 0.0f);
    glVertex3f(16.7333f, 14.7015f, 0.0f);

    glVertex3f(16.9333f, 14.7015f, 0.0f);
    glVertex3f(16.9333f, 32.6866f, 0.0f);
    glVertex3f(17.5333f, 32.6866f, 0.0f);
    glVertex3f(17.5333f, 14.7015f, 0.0f);

    glVertex3f(17.7333f, 14.7015f, 0.0f);
    glVertex3f(17.7333f, 32.6866f, 0.0f);
    glVertex3f(18.3333f, 32.6866f, 0.0f);
    glVertex3f(18.3333f, 14.7015f, 0.0f);

    glVertex3f(18.5333f, 14.7015f, 0.0f);
    glVertex3f(18.5333f, 32.6866f, 0.0f);
    glVertex3f(19.1333f, 32.6866f, 0.0f);
    glVertex3f(19.1333f, 14.7015f, 0.0f);


// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Background Colored Building - 2  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glColor3f(0.804, 0.31, 0.251); // building left side shadow
    glVertex3f(21.1333f, 13.5806f, 0.0f);
    glVertex3f(21.1333f, 41.0448f, 0.0f);
    glVertex3f(22.8f, 41.0448f, 0.0f);
    glVertex3f(22.8f, 13.5806f, 0.0f);

    glColor3f(1.0, 0.451, 0.361); // building right side shadow
    glVertex3f(22.8f, 13.5806f, 0.0f);
    glVertex3f(22.8f, 41.0448f, 0.0f);
    glVertex3f(28.0f, 41.0448f, 0.0f);
    glVertex3f(28.0f, 13.5806f, 0.0f);

    glColor3f(0.133, 0.243, 0.259); // left side small apartments
    glVertex3f(21.4f, 39.8507f, 0.0f); // 1st row
    glVertex3f(21.4f, 40.5224f, 0.0f);
    glVertex3f(21.8f, 40.5224f, 0.0f);
    glVertex3f(21.8f, 39.8507f, 0.0f);

    glVertex3f(22.2f, 39.8507f, 0.0f);
    glVertex3f(22.2f, 40.5224f, 0.0f);
    glVertex3f(22.6f, 40.5224f, 0.0f);
    glVertex3f(22.6f, 39.8507f, 0.0f);

    glVertex3f(21.4f, 38.4507f, 0.0f); // 2nd row
    glVertex3f(21.4f, 39.1224f, 0.0f);
    glVertex3f(21.8f, 39.1224f, 0.0f);
    glVertex3f(21.8f, 38.4507f, 0.0f);

    glVertex3f(22.2f, 38.4507f, 0.0f);
    glVertex3f(22.2f, 39.1224f, 0.0f);
    glVertex3f(22.6f, 39.1224f, 0.0f);
    glVertex3f(22.6f, 38.4507f, 0.0f);

    glVertex3f(21.4f, 37.0507f, 0.0f); // 3rd row
    glVertex3f(21.4f, 37.7224f, 0.0f);
    glVertex3f(21.8f, 37.7224f, 0.0f);
    glVertex3f(21.8f, 37.0507f, 0.0f);

    glVertex3f(22.2f, 37.0507f, 0.0f);
    glVertex3f(22.2f, 37.7224f, 0.0f);
    glVertex3f(22.6f, 37.7224f, 0.0f);
    glVertex3f(22.6f, 37.0507f, 0.0f);

    glVertex3f(21.4f, 35.6507f, 0.0f); // 4th row
    glVertex3f(21.4f, 36.3224f, 0.0f);
    glVertex3f(21.8f, 36.3224f, 0.0f);
    glVertex3f(21.8f, 35.6507f, 0.0f);

    glVertex3f(22.2f, 35.6507f, 0.0f);
    glVertex3f(22.2f, 36.3224f, 0.0f);
    glVertex3f(22.6f, 36.3224f, 0.0f);
    glVertex3f(22.6f, 35.6507f, 0.0f);

    glVertex3f(21.4f, 34.2507f, 0.0f); // 5th row
    glVertex3f(21.4f, 34.9224f, 0.0f);
    glVertex3f(21.8f, 34.9224f, 0.0f);
    glVertex3f(21.8f, 34.2507f, 0.0f);

    glVertex3f(22.2f, 34.2507f, 0.0f);
    glVertex3f(22.2f, 34.9224f, 0.0f);
    glVertex3f(22.6f, 34.9224f, 0.0f);
    glVertex3f(22.6f, 34.2507f, 0.0f);

    glVertex3f(21.4f, 32.8507f, 0.0f); // 6th row
    glVertex3f(21.4f, 33.5224f, 0.0f);
    glVertex3f(21.8f, 33.5224f, 0.0f);
    glVertex3f(21.8f, 32.8507f, 0.0f);

    glVertex3f(22.2f, 32.8507f, 0.0f);
    glVertex3f(22.2f, 33.5224f, 0.0f);
    glVertex3f(22.6f, 33.5224f, 0.0f);
    glVertex3f(22.6f, 32.8507f, 0.0f);

    glVertex3f(21.4f, 31.4507f, 0.0f); // 7th row
    glVertex3f(21.4f, 32.1224f, 0.0f);
    glVertex3f(21.8f, 32.1224f, 0.0f);
    glVertex3f(21.8f, 31.4507f, 0.0f);

    glVertex3f(22.2f, 31.4507f, 0.0f);
    glVertex3f(22.2f, 32.1224f, 0.0f);
    glVertex3f(22.6f, 32.1224f, 0.0f);
    glVertex3f(22.6f, 31.4507f, 0.0f);

    glVertex3f(21.4f, 30.0507f, 0.0f); // 8th row
    glVertex3f(21.4f, 30.7224f, 0.0f);
    glVertex3f(21.8f, 30.7224f, 0.0f);
    glVertex3f(21.8f, 30.0507f, 0.0f);

    glVertex3f(22.2f, 30.0507f, 0.0f);
    glVertex3f(22.2f, 30.7224f, 0.0f);
    glVertex3f(22.6f, 30.7224f, 0.0f);
    glVertex3f(22.6f, 30.0507f, 0.0f);

    glVertex3f(21.4f, 28.6507f, 0.0f); // 9th row
    glVertex3f(21.4f, 29.3224f, 0.0f);
    glVertex3f(21.8f, 29.3224f, 0.0f);
    glVertex3f(21.8f, 28.6507f, 0.0f);

    glVertex3f(22.2f, 28.6507f, 0.0f);
    glVertex3f(22.2f, 29.3224f, 0.0f);
    glVertex3f(22.6f, 29.3224f, 0.0f);
    glVertex3f(22.6f, 28.6507f, 0.0f);

    glColor3f(0.482, 0.541, 0.561); // building right side small apartments
    glVertex3f(23.2f, 39.7015f, 0.0f); // column wise 1st column
    glVertex3f(23.2f, 40.5224f, 0.0f);
    glVertex3f(25.8f, 40.5224f, 0.0f);
    glVertex3f(25.8f, 39.7015f, 0.0f);

    glVertex3f(23.2f, 38.3015f, 0.0f);
    glVertex3f(23.2f, 39.1224f, 0.0f);
    glVertex3f(25.8f, 39.1224f, 0.0f);
    glVertex3f(25.8f, 38.3015f, 0.0f);

    glVertex3f(23.2f, 36.9015f, 0.0f);
    glVertex3f(23.2f, 37.7224f, 0.0f);
    glVertex3f(25.8f, 37.7224f, 0.0f);
    glVertex3f(25.8f, 36.9015f, 0.0f);

    glVertex3f(23.2f, 35.5015f, 0.0f);
    glVertex3f(23.2f, 36.3224f, 0.0f);
    glVertex3f(25.8f, 36.3224f, 0.0f);
    glVertex3f(25.8f, 35.5015f, 0.0f);

    glVertex3f(23.2f, 34.1015f, 0.0f);
    glVertex3f(23.2f, 34.9224f, 0.0f);
    glVertex3f(25.8f, 34.9224f, 0.0f);
    glVertex3f(25.8f, 34.1015f, 0.0f);

    glColor3f(0.212, 0.365, 0.384);
    glVertex3f(23.2f, 32.7015f, 0.0f);
    glVertex3f(23.2f, 33.5224f, 0.0f);
    glVertex3f(25.8f, 33.5224f, 0.0f);
    glVertex3f(25.8f, 32.7015f, 0.0f);

    glVertex3f(23.2f, 31.3015f, 0.0f);
    glVertex3f(23.2f, 32.1224f, 0.0f);
    glVertex3f(25.8f, 32.1224f, 0.0f);
    glVertex3f(25.8f, 31.3015f, 0.0f);

    glVertex3f(23.2f, 29.9015f, 0.0f);
    glVertex3f(23.2f, 30.7224f, 0.0f);
    glVertex3f(25.8f, 30.7224f, 0.0f);
    glVertex3f(25.8f, 29.9015f, 0.0f);

    glVertex3f(23.2f, 28.5015f, 0.0f);
    glVertex3f(23.2f, 29.3224f, 0.0f);
    glVertex3f(25.8f, 29.3224f, 0.0f);
    glVertex3f(25.8f, 28.5015f, 0.0f);

    glVertex3f(23.2f, 27.1015f, 0.0f);
    glVertex3f(23.2f, 27.9224f, 0.0f);
    glVertex3f(25.8f, 27.9224f, 0.0f);
    glVertex3f(25.8f, 27.1015f, 0.0f);

    glVertex3f(23.2f, 25.7015f, 0.0f);
    glVertex3f(23.2f, 26.5224f, 0.0f);
    glVertex3f(25.8f, 26.5224f, 0.0f);
    glVertex3f(25.8f, 25.7015f, 0.0f);

    glVertex3f(23.2f, 24.3015f, 0.0f);
    glVertex3f(23.2f, 25.1224f, 0.0f);
    glVertex3f(25.8f, 25.1224f, 0.0f);
    glVertex3f(25.8f, 24.3015f, 0.0f);

    glVertex3f(23.2f, 22.9015f, 0.0f);
    glVertex3f(23.2f, 23.7224f, 0.0f);
    glVertex3f(25.8f, 23.7224f, 0.0f);
    glVertex3f(25.8f, 22.9015f, 0.0f);

    glVertex3f(23.2f, 21.5015f, 0.0f);
    glVertex3f(23.2f, 22.3224f, 0.0f);
    glVertex3f(25.8f, 22.3224f, 0.0f);
    glVertex3f(25.8f, 21.5015f, 0.0f);

    glVertex3f(23.2f, 20.1015f, 0.0f);
    glVertex3f(23.2f, 20.9224f, 0.0f);
    glVertex3f(25.8f, 20.9224f, 0.0f);
    glVertex3f(25.8f, 20.1015f, 0.0f);

    glColor3f(0.49, 0.541, 0.604); // column 2nd
    glVertex3f(26.3333f, 39.7015f, 0.0f);
    glVertex3f(26.3333f, 40.5224f, 0.0f);
    glVertex3f(27.6667f, 40.5224f, 0.0f);
    glVertex3f(27.6667f, 39.7015f, 0.0f);

    glVertex3f(26.3333f, 38.3015f, 0.0f);
    glVertex3f(26.3333f, 39.1224f, 0.0f);
    glVertex3f(27.6667f, 39.1224f, 0.0f);
    glVertex3f(27.6667f, 38.3015f, 0.0f);

    glVertex3f(26.3333f, 36.9015f, 0.0f);
    glVertex3f(26.3333f, 37.7224f, 0.0f);
    glVertex3f(27.6667f, 37.7224f, 0.0f);
    glVertex3f(27.6667f, 36.9015f, 0.0f);

    glColor3f(0.212, 0.365, 0.384);
    glVertex3f(26.3333f, 35.5015f, 0.0f);
    glVertex3f(26.3333f, 36.3224f, 0.0f);
    glVertex3f(27.6667f, 36.3224f, 0.0f);
    glVertex3f(27.6667f, 35.5015f, 0.0f);

    glVertex3f(26.3333f, 34.1015f, 0.0f);
    glVertex3f(26.3333f, 34.9224f, 0.0f);
    glVertex3f(27.6667f, 34.9224f, 0.0f);
    glVertex3f(27.6667f, 34.1015f, 0.0f);

    glVertex3f(26.3333f, 32.7015f, 0.0f);
    glVertex3f(26.3333f, 33.5224f, 0.0f);
    glVertex3f(27.6667f, 33.5224f, 0.0f);
    glVertex3f(27.6667f, 32.7015f, 0.0f);

    glVertex3f(26.3333f, 31.3015f, 0.0f);
    glVertex3f(26.3333f, 32.1224f, 0.0f);
    glVertex3f(27.6667f, 32.1224f, 0.0f);
    glVertex3f(27.6667f, 31.3015f, 0.0f);

    glVertex3f(26.3333f, 29.9015f, 0.0f);
    glVertex3f(26.3333f, 30.7224f, 0.0f);
    glVertex3f(27.6667f, 30.7224f, 0.0f);
    glVertex3f(27.6667f, 29.9015f, 0.0f);

    glVertex3f(26.3333f, 28.5015f, 0.0f);
    glVertex3f(26.3333f, 29.3224f, 0.0f);
    glVertex3f(27.6667f, 29.3224f, 0.0f);
    glVertex3f(27.6667f, 28.5015f, 0.0f);

    glVertex3f(26.3333f, 27.1015f, 0.0f);
    glVertex3f(26.3333f, 27.9224f, 0.0f);
    glVertex3f(27.6667f, 27.9224f, 0.0f);
    glVertex3f(27.6667f, 27.1015f, 0.0f);

    glVertex3f(26.3333f, 25.7015f, 0.0f);
    glVertex3f(26.3333f, 26.5224f, 0.0f);
    glVertex3f(27.6667f, 26.5224f, 0.0f);
    glVertex3f(27.6667f, 25.7015f, 0.0f);

    glVertex3f(26.3333f, 24.3015f, 0.0f);
    glVertex3f(26.3333f, 25.1224f, 0.0f);
    glVertex3f(27.6667f, 25.1224f, 0.0f);
    glVertex3f(27.6667f, 24.3015f, 0.0f);

    glVertex3f(26.3333f, 22.9015f, 0.0f);
    glVertex3f(26.3333f, 23.7224f, 0.0f);
    glVertex3f(27.6667f, 23.7224f, 0.0f);
    glVertex3f(27.6667f, 22.9015f, 0.0f);

    glVertex3f(26.3333f, 21.5015f, 0.0f);
    glVertex3f(26.3333f, 22.3224f, 0.0f);
    glVertex3f(27.6667f, 22.3224f, 0.0f);
    glVertex3f(27.6667f, 21.5015f, 0.0f);

    glVertex3f(26.3333f, 20.1015f, 0.0f);
    glVertex3f(26.3333f, 20.9224f, 0.0f);
    glVertex3f(27.6667f, 20.9224f, 0.0f);
    glVertex3f(27.6667f, 20.1015f, 0.0f);

    glEnd();

// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Background Colored Building - 3  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
    glBegin(GL_POLYGON);

    glColor3f(0.059, 0.11, 0.141); // building - 3 background polygon color
    glVertex3f(28.4f, 24.3284f, 0.0f);
    glVertex3f(28.4f, 35.2239f, 0.0f);
    glVertex3f(29.0f, 35.2239f, 0.0f);
    glVertex3f(29.0f, 36.2687f, 0.0f);
    glVertex3f(33.1333f, 36.2687f, 0.0f);
    glVertex3f(33.1333f, 35.2985f, 0.0f);
    glVertex3f(33.5333f, 35.2985f, 0.0f);
    glVertex3f(33.5333f, 22.0896f, 0.0f);
    glVertex3f(28.8667f, 22.0896f, 0.0f);
    glVertex3f(28.8667f, 24.1791f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.463, 0.553, 0.584); // celing color
    glVertex3f(29.6f, 35.2985f, 0.0f);
    glVertex3f(29.6f, 35.9701f, 0.0f);
    glVertex3f(32.8f, 35.9701f, 0.0f);
    glVertex3f(32.8f, 35.2985f, 0.0f);

    glVertex3f(29.1333f, 22.1642f, 0.0f);
    glVertex3f(29.1333f, 34.9254f, 0.0f);
    glVertex3f(33.2667f, 34.9254f, 0.0f);
    glVertex3f(33.2667f, 22.1642f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON); // body polygon paint

    glColor3f(0.212, 0.345, 0.384);

    glVertex3f(29.1333f, 22.1642f, 0.0f);
    glVertex3f(29.0667f, 28.806f, 0.0f);
    glVertex3f(30.0667f, 28.806f, 0.0f);
    glVertex3f(30.0667f, 30.3731f, 0.0f);
    glVertex3f(31.1333f, 30.3731f, 0.0f);
    glVertex3f(31.3333f, 27.6866f, 0.0f);
    glVertex3f(32.6667f, 27.6866f, 0.0f);
    glVertex3f(32.6f, 32.9851f, 0.0f);
    glVertex3f(33.3333f, 33.0597f, 0.0f);
    glVertex3f(33.3333f, 22.3134f, 0.0f);

    glEnd();

    glBegin(GL_LINES); // body polygon lines

    glColor3f(0.063, 0.114, 0.137);
    glVertex3f(30.1333f, 35.9701f, 0.0f);
    glVertex3f(30.1333f, 22.1642f, 0.0f);

    glVertex3f(31.1333f, 35.9701f, 0.0f);
    glVertex3f(31.1333f, 22.1642f, 0.0f);

    glVertex3f(32.1333f, 35.9701f, 0.0f);
    glVertex3f(32.1333f, 22.1642f, 0.0f);

    glVertex3f(33.1333f, 35.9701f, 0.0f);
    glVertex3f(33.1333f, 22.1642f, 0.0f);

    glVertex3f(29.0667f, 33.6567f, 0.0f);
    glVertex3f(33.2667f, 33.6567f, 0.0f);

    glVertex3f(29.0667f, 32.6567f, 0.0f);
    glVertex3f(33.2667f, 32.6567f, 0.0f);

    glVertex3f(29.0667f, 31.6567f, 0.0f);
    glVertex3f(33.2667f, 31.6567f, 0.0f);

    glVertex3f(29.0667f, 30.6567f, 0.0f);
    glVertex3f(33.2667f, 30.6567f, 0.0f);

    glVertex3f(29.0667f, 29.6567f, 0.0f);
    glVertex3f(33.2667f, 29.6567f, 0.0f);

    glVertex3f(29.0667f, 28.6567f, 0.0f);
    glVertex3f(33.2667f, 28.6567f, 0.0f);

    glVertex3f(29.0667f, 27.6567f, 0.0f);
    glVertex3f(33.2667f, 27.6567f, 0.0f);

    glVertex3f(29.0667f, 26.6567f, 0.0f);
    glVertex3f(33.2667f, 26.6567f, 0.0f);

    glVertex3f(29.0667f, 25.6567f, 0.0f);
    glVertex3f(33.2667f, 25.6567f, 0.0f);

    glVertex3f(29.0667f, 24.6567f, 0.0f);
    glVertex3f(33.2667f, 24.6567f, 0.0f);

    glVertex3f(29.0667f, 23.6567f, 0.0f);
    glVertex3f(33.2667f, 23.6567f, 0.0f);

    glVertex3f(29.0667f, 22.6567f, 0.0f);
    glVertex3f(33.2667f, 22.6567f, 0.0f);

    glEnd();

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Background Colored Building - 4  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
    glBegin(GL_QUADS);

    glColor3f(0.129, 0.243, 0.275); // building left shadow
    glVertex3f(35.0f, 17.3134f, 0.0f);
    glVertex3f(35.0f, 29.403f, 0.0f);
    glVertex3f(36.8f, 30.4478f, 0.0f);
    glVertex3f(36.8f, 17.3134f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // building right shadow
    glVertex3f(36.8f, 17.3134f, 0.0f);
    glVertex3f(36.8f, 30.4478f, 0.0f);
    glVertex3f(41.2f, 32.9104f, 0.0f);
    glVertex3f(41.2f, 17.3134f, 0.0f);

    glColor3f(0.051, 0.122, 0.137); // building left small apartments
    glVertex3f(35.3333f, 28.209f, 0.0f); // 1st row
    glVertex3f(35.3333f, 29.2537f, 0.0f);
    glVertex3f(35.7333f, 29.2537f, 0.0f);
    glVertex3f(35.7333f, 28.209f, 0.0f);

    glVertex3f(36.0f, 28.209f, 0.0f);
    glVertex3f(36.0f, 29.2537f, 0.0f);
    glVertex3f(36.4333f, 29.2537f, 0.0f);
    glVertex3f(36.4333f, 28.209f, 0.0f);

    glVertex3f(35.3333f, 26.809f, 0.0f); // 2nd row
    glVertex3f(35.3333f, 27.8537f, 0.0f);
    glVertex3f(35.7333f, 27.8537f, 0.0f);
    glVertex3f(35.7333f, 26.809f, 0.0f);

    glVertex3f(36.0f, 26.809f, 0.0f);
    glVertex3f(36.0f, 27.8537f, 0.0f);
    glVertex3f(36.4333f, 27.8537f, 0.0f);
    glVertex3f(36.4333f, 26.809f, 0.0f);

    glVertex3f(35.3333f, 25.409f, 0.0f); // 3rd row
    glVertex3f(35.3333f, 26.4537f, 0.0f);
    glVertex3f(35.7333f, 26.4537f, 0.0f);
    glVertex3f(35.7333f, 25.409f, 0.0f);

    glVertex3f(36.0f, 25.409f, 0.0f);
    glVertex3f(36.0f, 26.4537f, 0.0f);
    glVertex3f(36.4333f, 26.4537f, 0.0f);
    glVertex3f(36.4333f, 25.409f, 0.0f);

    glVertex3f(35.3333f, 24.009f, 0.0f); // 4th row
    glVertex3f(35.3333f, 25.0537f, 0.0f);
    glVertex3f(35.7333f, 25.0537f, 0.0f);
    glVertex3f(35.7333f, 24.009f, 0.0f);

    glVertex3f(36.0f, 24.009f, 0.0f);
    glVertex3f(36.0f, 25.0537f, 0.0f);
    glVertex3f(36.4333f, 25.0537f, 0.0f);
    glVertex3f(36.4333f, 24.009f, 0.0f);

    glVertex3f(35.3333f, 22.609f, 0.0f); // 5th row
    glVertex3f(35.3333f, 23.6537f, 0.0f);
    glVertex3f(35.7333f, 23.6537f, 0.0f);
    glVertex3f(35.7333f, 22.609f, 0.0f);

    glVertex3f(36.0f, 22.609f, 0.0f);
    glVertex3f(36.0f, 23.6537f, 0.0f);
    glVertex3f(36.4333f, 23.6537f, 0.0f);
    glVertex3f(36.4333f, 22.609f, 0.0f);

    glVertex3f(35.3333f, 21.209f, 0.0f); // 6th row
    glVertex3f(35.3333f, 22.2537f, 0.0f);
    glVertex3f(35.7333f, 22.2537f, 0.0f);
    glVertex3f(35.7333f, 21.209f, 0.0f);

    glVertex3f(36.0f, 21.209f, 0.0f);
    glVertex3f(36.0f, 22.2537f, 0.0f);
    glVertex3f(36.4333f, 22.2537f, 0.0f);
    glVertex3f(36.4333f, 21.209f, 0.0f);

    glVertex3f(35.3333f, 19.809f, 0.0f); // 7th row
    glVertex3f(35.3333f, 20.8537f, 0.0f);
    glVertex3f(35.7333f, 20.8537f, 0.0f);
    glVertex3f(35.7333f, 19.809f, 0.0f);

    glVertex3f(36.0f, 19.809f, 0.0f);
    glVertex3f(36.0f, 20.8537f, 0.0f);
    glVertex3f(36.4333f, 20.8537f, 0.0f);
    glVertex3f(36.4333f, 19.809f, 0.0f);

    glVertex3f(35.3333f, 18.409f, 0.0f); // 8th row
    glVertex3f(35.3333f, 19.4537f, 0.0f);
    glVertex3f(35.7333f, 19.4537f, 0.0f);
    glVertex3f(35.7333f, 18.409f, 0.0f);

    glVertex3f(36.0f, 18.409f, 0.0f);
    glVertex3f(36.0f, 19.4537f, 0.0f);
    glVertex3f(36.4333f, 19.4537f, 0.0f);
    glVertex3f(36.4333f, 18.409f, 0.0f);

    glColor3f(0.973, 0.937, 0.949);  // building body small apartments
    glVertex3f(37.4f, 28.5075f, 0.0f); // 1st row
    glVertex3f(37.4f, 29.5522f, 0.0f);
    glVertex3f(38.1333f, 29.5522f, 0.0f);
    glVertex3f(38.1333f, 28.5075f, 0.0f);

    glVertex3f(38.5f, 28.5075f, 0.0f);
    glVertex3f(38.5f, 29.5522f, 0.0f);
    glVertex3f(39.2333f, 29.5522f, 0.0f);
    glVertex3f(39.2333f, 28.5075f, 0.0f);

    glVertex3f(39.6f, 28.5075f, 0.0f);
    glVertex3f(39.6f, 29.5522f, 0.0f);
    glVertex3f(40.3333f, 29.5522f, 0.0f);
    glVertex3f(40.3333f, 28.5075f, 0.0f);

    glVertex3f(37.4f, 27.1075f, 0.0f); // 2nd row
    glVertex3f(37.4f, 28.1522f, 0.0f);
    glVertex3f(38.1333f, 28.1522f, 0.0f);
    glVertex3f(38.1333f, 27.1075f, 0.0f);

    glVertex3f(38.5f, 27.1075f, 0.0f);
    glVertex3f(38.5f, 28.1522f, 0.0f);
    glVertex3f(39.2333f, 28.1522f, 0.0f);
    glVertex3f(39.2333f, 27.1075f, 0.0f);

    glVertex3f(39.6f, 27.1075f, 0.0f);
    glVertex3f(39.6f, 28.1522f, 0.0f);
    glVertex3f(40.3333f, 28.1522f, 0.0f);
    glVertex3f(40.3333f, 27.1075f, 0.0f);

    glVertex3f(37.4f, 25.7075f, 0.0f); // 3rd row
    glVertex3f(37.4f, 26.7522f, 0.0f);
    glVertex3f(38.1333f, 26.7522f, 0.0f);
    glVertex3f(38.1333f, 25.7075f, 0.0f);

    glVertex3f(38.5f, 25.7075f, 0.0f);
    glVertex3f(38.5f, 26.7522f, 0.0f);
    glVertex3f(39.2333f, 26.7522f, 0.0f);
    glVertex3f(39.2333f, 25.7075f, 0.0f);

    glVertex3f(39.6f, 25.7075f, 0.0f);
    glVertex3f(39.6f, 26.7522f, 0.0f);
    glVertex3f(40.3333f, 26.7522f, 0.0f);
    glVertex3f(40.3333f, 25.7075f, 0.0f);

    glVertex3f(37.4f, 24.3075f, 0.0f); // 4th row
    glVertex3f(37.4f, 25.3522f, 0.0f);
    glVertex3f(38.1333f, 25.3522f, 0.0f);
    glVertex3f(38.1333f, 24.3075f, 0.0f);

    glVertex3f(38.5f, 24.3075f, 0.0f);
    glVertex3f(38.5f, 25.3522f, 0.0f);
    glVertex3f(39.2333f, 25.3522f, 0.0f);
    glVertex3f(39.2333f, 24.3075f, 0.0f);

    glVertex3f(39.6f, 24.3075f, 0.0f);
    glVertex3f(39.6f, 25.3522f, 0.0f);
    glVertex3f(40.3333f, 25.3522f, 0.0f);
    glVertex3f(40.3333f, 24.3075f, 0.0f);

    glVertex3f(37.4f, 22.9075f, 0.0f); // 5th row
    glVertex3f(37.4f, 23.9522f, 0.0f);
    glVertex3f(38.1333f, 23.9522f, 0.0f);
    glVertex3f(38.1333f, 22.9075f, 0.0f);

    glVertex3f(38.5f, 22.9075f, 0.0f);
    glVertex3f(38.5f, 23.9522f, 0.0f);
    glVertex3f(39.2333f, 23.9522f, 0.0f);
    glVertex3f(39.2333f, 22.9075f, 0.0f);

    glVertex3f(39.6f, 22.9075f, 0.0f);
    glVertex3f(39.6f, 23.9522f, 0.0f);
    glVertex3f(40.3333f, 23.9522f, 0.0f);
    glVertex3f(40.3333f, 22.9075f, 0.0f);

    glVertex3f(37.4f, 21.5075f, 0.0f); // 6th row
    glVertex3f(37.4f, 22.5522f, 0.0f);
    glVertex3f(38.1333f, 22.5522f, 0.0f);
    glVertex3f(38.1333f, 21.5075f, 0.0f);

    glVertex3f(38.5f, 21.5075f, 0.0f);
    glVertex3f(38.5f, 22.5522f, 0.0f);
    glVertex3f(39.2333f, 22.5522f, 0.0f);
    glVertex3f(39.2333f, 21.5075f, 0.0f);

    glVertex3f(39.6f, 21.5075f, 0.0f);
    glVertex3f(39.6f, 22.5522f, 0.0f);
    glVertex3f(40.3333f, 22.5522f, 0.0f);
    glVertex3f(40.3333f, 21.5075f, 0.0f);

    glVertex3f(37.4f, 20.1075f, 0.0f); // 7th row
    glVertex3f(37.4f, 21.1522f, 0.0f);
    glVertex3f(38.1333f, 21.1522f, 0.0f);
    glVertex3f(38.1333f, 20.1075f, 0.0f);

    glVertex3f(38.5f, 20.1075f, 0.0f);
    glVertex3f(38.5f, 21.1522f, 0.0f);
    glVertex3f(39.2333f, 21.1522f, 0.0f);
    glVertex3f(39.2333f, 20.1075f, 0.0f);

    glVertex3f(39.6f, 20.1075f, 0.0f);
    glVertex3f(39.6f, 21.1522f, 0.0f);
    glVertex3f(40.3333f, 21.1522f, 0.0f);
    glVertex3f(40.3333f, 20.1075f, 0.0f);

    glVertex3f(37.4667f, 17.2642f, 0.0f); // 8th row
    glVertex3f(37.4667f, 18.9552f, 0.0f);
    glVertex3f(38.1333f, 18.9552f, 0.0f);
    glVertex3f(38.1333f, 17.2642f, 0.0f);

    glVertex3f(38.5667f, 17.2642f, 0.0f);
    glVertex3f(38.5667f, 18.9552f, 0.0f);
    glVertex3f(39.2333f, 18.9552f, 0.0f);
    glVertex3f(39.2333f, 17.2642f, 0.0f);

    glVertex3f(39.6667f, 17.2642f, 0.0f);
    glVertex3f(39.6667f, 18.9552f, 0.0f);
    glVertex3f(40.3333f, 18.9552f, 0.0f);
    glVertex3f(40.3333f, 17.2642f, 0.0f);

    glEnd();


    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Background Colored Building - 4  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
    glBegin(GL_QUADS);

    glColor3f(0.604, 0.588, 0.592); // building left side shadow
    glVertex3f(20.0f, 13.5552f, 0.0f);
    glVertex3f(20.0f, 29.7015f, 0.0f);
    glVertex3f(21.9f, 29.7015f, 0.0f);
    glVertex3f(21.9f, 13.5552f, 0.0f);

    glColor3f(0.851, 0.871, 0.847); // building right side shadow
    glVertex3f(21.9f, 13.5552f, 0.0f);
    glVertex3f(21.9f, 29.7015f, 0.0f);
    glVertex3f(25.2667f, 29.7015f, 0.0f);
    glVertex3f(25.2667f, 13.5552f, 0.0f);

    glColor3f(0.384, 0.424, 0.431); // left side small apartments
    glVertex3f(20.2f, 28.5075f, 0.0f); //1st row
    glVertex3f(20.2f, 29.1791f, 0.0f);
    glVertex3f(20.6f, 29.1791f, 0.0f);
    glVertex3f(20.6f, 28.5075f, 0.0f);

    glVertex3f(21.2f, 28.5075f, 0.0f);
    glVertex3f(21.2f, 29.1791f, 0.0f);
    glVertex3f(21.6f, 29.1791f, 0.0f);
    glVertex3f(21.6f, 28.5075f, 0.0f);

    glVertex3f(20.2f, 27.5075f, 0.0f); //2nd row
    glVertex3f(20.2f, 28.1791f, 0.0f);
    glVertex3f(20.6f, 28.1791f, 0.0f);
    glVertex3f(20.6f, 27.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(21.2f, 27.5075f, 0.0f);
    glVertex3f(21.2f, 28.1791f, 0.0f);
    glVertex3f(21.6f, 28.1791f, 0.0f);
    glVertex3f(21.6f, 27.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(20.2f, 26.5075f, 0.0f); //3rd row
    glVertex3f(20.2f, 27.1791f, 0.0f);
    glVertex3f(20.6f, 27.1791f, 0.0f);
    glVertex3f(20.6f, 26.5075f, 0.0f);

    glColor3f(0.384, 0.424, 0.431);
    glVertex3f(21.2f, 26.5075f, 0.0f);
    glVertex3f(21.2f, 27.1791f, 0.0f);
    glVertex3f(21.6f, 27.1791f, 0.0f);
    glVertex3f(21.6f, 26.5075f, 0.0f);

    glVertex3f(20.2f, 25.5075f, 0.0f); //4th row
    glVertex3f(20.2f, 26.1791f, 0.0f);
    glVertex3f(20.6f, 26.1791f, 0.0f);
    glVertex3f(20.6f, 25.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(21.2f, 25.5075f, 0.0f);
    glVertex3f(21.2f, 26.1791f, 0.0f);
    glVertex3f(21.6f, 26.1791f, 0.0f);
    glVertex3f(21.6f, 25.5075f, 0.0f);

    glVertex3f(20.2f, 24.5075f, 0.0f); //5th row
    glVertex3f(20.2f, 25.1791f, 0.0f);
    glVertex3f(20.6f, 25.1791f, 0.0f);
    glVertex3f(20.6f, 24.5075f, 0.0f);

    glVertex3f(21.2f, 24.5075f, 0.0f);
    glVertex3f(21.2f, 25.1791f, 0.0f);
    glVertex3f(21.6f, 25.1791f, 0.0f);
    glVertex3f(21.6f, 24.5075f, 0.0f);

    glVertex3f(20.2f, 22.5075f, 0.0f); //6th row
    glVertex3f(20.2f, 23.1791f, 0.0f);
    glVertex3f(20.6f, 23.1791f, 0.0f);
    glVertex3f(20.6f, 22.5075f, 0.0f);

    glVertex3f(21.2f, 22.5075f, 0.0f);
    glVertex3f(21.2f, 23.1791f, 0.0f);
    glVertex3f(21.6f, 23.1791f, 0.0f);
    glVertex3f(21.6f, 22.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(20.2f, 21.5075f, 0.0f); //7th row
    glVertex3f(20.2f, 22.1791f, 0.0f);
    glVertex3f(20.6f, 22.1791f, 0.0f);
    glVertex3f(20.6f, 21.5075f, 0.0f);

    glVertex3f(21.2f, 21.5075f, 0.0f);
    glVertex3f(21.2f, 22.1791f, 0.0f);
    glVertex3f(21.6f, 22.1791f, 0.0f);
    glVertex3f(21.6f, 21.5075f, 0.0f);

    glVertex3f(20.2f, 20.5075f, 0.0f); //8th row
    glVertex3f(20.2f, 21.1791f, 0.0f);
    glVertex3f(20.6f, 21.1791f, 0.0f);
    glVertex3f(20.6f, 20.5075f, 0.0f);

    glVertex3f(21.2f, 20.5075f, 0.0f);
    glVertex3f(21.2f, 21.1791f, 0.0f);
    glVertex3f(21.6f, 21.1791f, 0.0f);
    glVertex3f(21.6f, 20.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(20.2f, 19.5075f, 0.0f); //9th row
    glVertex3f(20.2f, 20.1791f, 0.0f);
    glVertex3f(20.6f, 20.1791f, 0.0f);
    glVertex3f(20.6f, 19.5075f, 0.0f);

    glVertex3f(21.2f, 19.5075f, 0.0f);
    glVertex3f(21.2f, 20.1791f, 0.0f);
    glVertex3f(21.6f, 20.1791f, 0.0f);
    glVertex3f(21.6f, 19.5075f, 0.0f);

    glColor3f(0.384, 0.424, 0.431); // right side small apartments
    glVertex3f(22.1333f, 28.5075f, 0.0f); //1st row
    glVertex3f(22.1333f, 29.3284f, 0.0f);
    glVertex3f(22.5333f, 29.3284f, 0.0f);
    glVertex3f(22.5333f, 28.5075f, 0.0f);

    glVertex3f(23.1333f, 28.5075f, 0.0f);
    glVertex3f(23.1333f, 29.3284f, 0.0f);
    glVertex3f(23.5333f, 29.3284f, 0.0f);
    glVertex3f(23.5333f, 28.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(24.1333f, 28.5075f, 0.0f);
    glVertex3f(24.1333f, 29.3284f, 0.0f);
    glVertex3f(24.5333f, 29.3284f, 0.0f);
    glVertex3f(24.5333f, 28.5075f, 0.0f);

    glColor3f(0.384, 0.424, 0.431);
    glVertex3f(22.1333f, 27.5075f, 0.0f); //2nd row
    glVertex3f(22.1333f, 28.3284f, 0.0f);
    glVertex3f(22.5333f, 28.3284f, 0.0f);
    glVertex3f(22.5333f, 27.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(23.1333f, 27.5075f, 0.0f);
    glVertex3f(23.1333f, 28.3284f, 0.0f);
    glVertex3f(23.5333f, 28.3284f, 0.0f);
    glVertex3f(23.5333f, 27.5075f, 0.0f);

    glVertex3f(24.1333f, 27.5075f, 0.0f);
    glVertex3f(24.1333f, 28.3284f, 0.0f);
    glVertex3f(24.5333f, 28.3284f, 0.0f);
    glVertex3f(24.5333f, 27.5075f, 0.0f);

    glColor3f(0.384, 0.424, 0.431);
    glVertex3f(22.1333f, 26.5075f, 0.0f); //3rd row
    glVertex3f(22.1333f, 27.3284f, 0.0f);
    glVertex3f(22.5333f, 27.3284f, 0.0f);
    glVertex3f(22.5333f, 26.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(23.1333f, 26.5075f, 0.0f);
    glVertex3f(23.1333f, 27.3284f, 0.0f);
    glVertex3f(23.5333f, 27.3284f, 0.0f);
    glVertex3f(23.5333f, 26.5075f, 0.0f);

    glColor3f(0.384, 0.424, 0.431);
    glVertex3f(24.1333f, 26.5075f, 0.0f);
    glVertex3f(24.1333f, 27.3284f, 0.0f);
    glVertex3f(24.5333f, 27.3284f, 0.0f);
    glVertex3f(24.5333f, 26.5075f, 0.0f);

    glVertex3f(22.1333f, 25.5075f, 0.0f); //4th row
    glVertex3f(22.1333f, 26.3284f, 0.0f);
    glVertex3f(22.5333f, 26.3284f, 0.0f);
    glVertex3f(22.5333f, 25.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(23.1333f, 25.5075f, 0.0f);
    glVertex3f(23.1333f, 26.3284f, 0.0f);
    glVertex3f(23.5333f, 26.3284f, 0.0f);
    glVertex3f(23.5333f, 25.5075f, 0.0f);

    glColor3f(0.384, 0.424, 0.431);
    glVertex3f(24.1333f, 25.5075f, 0.0f);
    glVertex3f(24.1333f, 26.3284f, 0.0f);
    glVertex3f(24.5333f, 26.3284f, 0.0f);
    glVertex3f(24.5333f, 25.5075f, 0.0f);

    glVertex3f(22.1333f, 24.5075f, 0.0f); //5th row
    glVertex3f(22.1333f, 25.3284f, 0.0f);
    glVertex3f(22.5333f, 25.3284f, 0.0f);
    glVertex3f(22.5333f, 24.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(23.1333f, 24.5075f, 0.0f);
    glVertex3f(23.1333f, 25.3284f, 0.0f);
    glVertex3f(23.5333f, 25.3284f, 0.0f);
    glVertex3f(23.5333f, 24.5075f, 0.0f);

    glVertex3f(24.1333f, 24.5075f, 0.0f);
    glVertex3f(24.1333f, 25.3284f, 0.0f);
    glVertex3f(24.5333f, 25.3284f, 0.0f);
    glVertex3f(24.5333f, 24.5075f, 0.0f);

    glColor3f(0.176, 0.231, 0.267);
    glVertex3f(22.1333f, 22.5075f, 0.0f); //6th row
    glVertex3f(22.1333f, 23.3284f, 0.0f);
    glVertex3f(22.5333f, 23.3284f, 0.0f);
    glVertex3f(22.5333f, 22.5075f, 0.0f);

    glVertex3f(23.1333f, 22.5075f, 0.0f);
    glVertex3f(23.1333f, 23.3284f, 0.0f);
    glVertex3f(23.5333f, 23.3284f, 0.0f);
    glVertex3f(23.5333f, 22.5075f, 0.0f);

    glVertex3f(24.1333f, 22.5075f, 0.0f);
    glVertex3f(24.1333f, 23.3284f, 0.0f);
    glVertex3f(24.5333f, 23.3284f, 0.0f);
    glVertex3f(24.5333f, 22.5075f, 0.0f);

    glVertex3f(22.1333f, 21.5075f, 0.0f); //7th row
    glVertex3f(22.1333f, 22.3284f, 0.0f);
    glVertex3f(22.5333f, 22.3284f, 0.0f);
    glVertex3f(22.5333f, 21.5075f, 0.0f);

    glVertex3f(23.1333f, 21.5075f, 0.0f);
    glVertex3f(23.1333f, 22.3284f, 0.0f);
    glVertex3f(23.5333f, 22.3284f, 0.0f);
    glVertex3f(23.5333f, 21.5075f, 0.0f);

    glVertex3f(24.1333f, 21.5075f, 0.0f);
    glVertex3f(24.1333f, 22.3284f, 0.0f);
    glVertex3f(24.5333f, 22.3284f, 0.0f);
    glVertex3f(24.5333f, 21.5075f, 0.0f);

    glVertex3f(22.1333f, 20.5075f, 0.0f); //8th row
    glVertex3f(22.1333f, 21.3284f, 0.0f);
    glVertex3f(22.5333f, 21.3284f, 0.0f);
    glVertex3f(22.5333f, 20.5075f, 0.0f);

    glVertex3f(23.1333f, 20.5075f, 0.0f);
    glVertex3f(23.1333f, 21.3284f, 0.0f);
    glVertex3f(23.5333f, 21.3284f, 0.0f);
    glVertex3f(23.5333f, 20.5075f, 0.0f);

    glVertex3f(24.1333f, 20.5075f, 0.0f);
    glVertex3f(24.1333f, 21.3284f, 0.0f);
    glVertex3f(24.5333f, 21.3284f, 0.0f);
    glVertex3f(24.5333f, 20.5075f, 0.0f);

    glVertex3f(22.1333f, 19.5075f, 0.0f); //9th row
    glVertex3f(22.1333f, 20.3284f, 0.0f);
    glVertex3f(22.5333f, 20.3284f, 0.0f);
    glVertex3f(22.5333f, 19.5075f, 0.0f);

    glVertex3f(23.1333f, 19.5075f, 0.0f);
    glVertex3f(23.1333f, 20.3284f, 0.0f);
    glVertex3f(23.5333f, 20.3284f, 0.0f);
    glVertex3f(23.5333f, 19.5075f, 0.0f);

    glVertex3f(24.1333f, 19.5075f, 0.0f);
    glVertex3f(24.1333f, 20.3284f, 0.0f);
    glVertex3f(24.5333f, 20.3284f, 0.0f);
    glVertex3f(24.5333f, 19.5075f, 0.0f);

    glVertex3f(22.1333f, 18.5075f, 0.0f); //10th row
    glVertex3f(22.1333f, 19.3284f, 0.0f);
    glVertex3f(22.5333f, 19.3284f, 0.0f);
    glVertex3f(22.5333f, 18.5075f, 0.0f);

    glVertex3f(23.1333f, 18.5075f, 0.0f);
    glVertex3f(23.1333f, 19.3284f, 0.0f);
    glVertex3f(23.5333f, 19.3284f, 0.0f);
    glVertex3f(23.5333f, 18.5075f, 0.0f);

    glVertex3f(24.1333f, 18.5075f, 0.0f);
    glVertex3f(24.1333f, 19.3284f, 0.0f);
    glVertex3f(24.5333f, 19.3284f, 0.0f);
    glVertex3f(24.5333f, 18.5075f, 0.0f);

    glVertex3f(22.1333f, 17.5075f, 0.0f); //11th row
    glVertex3f(22.1333f, 18.3284f, 0.0f);
    glVertex3f(22.5333f, 18.3284f, 0.0f);
    glVertex3f(22.5333f, 17.5075f, 0.0f);

    glVertex3f(22.1333f, 16.5075f, 0.0f); //12th row
    glVertex3f(22.1333f, 17.3284f, 0.0f);
    glVertex3f(22.5333f, 17.3284f, 0.0f);
    glVertex3f(22.5333f, 16.5075f, 0.0f);

    glVertex3f(22.1333f, 15.5075f, 0.0f); //13th row
    glVertex3f(22.1333f, 16.3284f, 0.0f);
    glVertex3f(22.5333f, 16.3284f, 0.0f);
    glVertex3f(22.5333f, 15.5075f, 0.0f);

    glVertex3f(22.1333f, 14.5075f, 0.0f); //14th row
    glVertex3f(22.1333f, 15.3284f, 0.0f);
    glVertex3f(22.5333f, 15.3284f, 0.0f);
    glVertex3f(22.5333f, 14.5075f, 0.0f);

    glVertex3f(22.1333f, 13.5075f, 0.0f); //15th row
    glVertex3f(22.1333f, 14.3284f, 0.0f);
    glVertex3f(22.5333f, 14.3284f, 0.0f);
    glVertex3f(22.5333f, 13.5075f, 0.0f);

    glEnd();

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Colored Building 1st ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);

    glColor3f(0.769, 0.525, 0.427);  //left side shadow
    glVertex3f(9.8667f, 13.606f, 0.0f);
    glVertex3f(9.8667f, 24.6269f, 0.0f);
    glVertex3f(11.2667f, 24.6269f, 0.0f);
    glVertex3f(11.2667f, 13.606f, 0.0f);

    glColor3f(0.157, 0.259, 0.263); // left side big window
    glVertex3f(10.3333f, 14.3284f, 0.0f);
    glVertex3f(10.8667f, 14.3284f, 0.0f);
    glVertex3f(10.8667f, 15.2239f, 0.0f);
    glVertex3f(10.3333f, 15.2239f, 0.0f);

    glColor3f(0.106, 0.11, 0.055); // left side small window
    glVertex3f(10.2667f, 21.9403f, 0.0f);
    glVertex3f(10.4667f, 21.9403f, 0.0f);
    glVertex3f(10.4667f, 22.8358f, 0.0f);
    glVertex3f(10.2667f, 22.8358f, 0.0f);

    glVertex3f(10.2667f, 20.5403f, 0.0f);
    glVertex3f(10.4667f, 20.5403f, 0.0f);
    glVertex3f(10.4667f, 21.4358f, 0.0f);
    glVertex3f(10.2667f, 21.4358f, 0.0f);

    glVertex3f(10.2667f, 19.0403f, 0.0f);
    glVertex3f(10.4667f, 19.0403f, 0.0f);
    glVertex3f(10.4667f, 20.0358f, 0.0f);
    glVertex3f(10.2667f, 20.0358f, 0.0f);

    glVertex3f(10.2667f, 18.9403f, 0.0f);
    glVertex3f(10.4667f, 18.9403f, 0.0f);
    glVertex3f(10.4667f, 19.9358f, 0.0f);
    glVertex3f(10.2667f, 19.9358f, 0.0f);

    glVertex3f(10.2667f, 17.1403f, 0.0f);
    glVertex3f(10.4667f, 17.1403f, 0.0f);
    glVertex3f(10.4667f, 18.1358f, 0.0f);
    glVertex3f(10.2667f, 18.1358f, 0.0f);

    glVertex3f(10.2667f, 16.0403f, 0.0f);
    glVertex3f(10.4667f, 16.0403f, 0.0f);
    glVertex3f(10.4667f, 17.0358f, 0.0f);
    glVertex3f(10.2667f, 17.0358f, 0.0f);

    glColor3f(1.0, 0.741, 0.604); // 1st building body
    glVertex3f(11.2667f, 24.6269f, 0.0f);
    glVertex3f(17.3333f, 24.6269f, 0.0f);
    glVertex3f(17.3333f, 13.606f, 0.0f);
    glVertex3f(11.2667f, 13.606f, 0.0f);

    glColor3f(1.0, 0.58, 0.42); // 1st building body paint
    glVertex3f(11.5333f, 15.8955f, 0.0f);
    glVertex3f(11.5333f, 24.6015f, 0.0f);
    glVertex3f(16.6667f, 24.6015f, 0.0f);
    glVertex3f(16.6667f, 15.8955f, 0.0f);

    glColor3f(1.0, 0.741, 0.604); // 1st building mid-body paint
    glVertex3f(13.2667f, 16.8955f, 0.0f);
    glVertex3f(13.2667f, 23.4328f, 0.0f);
    glVertex3f(14.9333f, 23.4328f, 0.0f);
    glVertex3f(14.9333f, 16.8955f, 0.0f);

    glColor3f(0.216, 0.349, 0.384); // 1st row wise apartments
    glVertex3f(12.0f, 22.9104f, 0.0f);
    glVertex3f(13.0f, 22.9104f, 0.0f);
    glVertex3f(13.0f, 21.9403f, 0.0f);
    glVertex3f(12.0f, 21.9403f, 0.0f);

    glVertex3f(13.5f, 22.9104f, 0.0f);
    glVertex3f(14.5f, 22.9104f, 0.0f);
    glVertex3f(14.5f, 21.9403f, 0.0f);
    glVertex3f(13.5f, 21.9403f, 0.0f);

    glVertex3f(15.0f, 22.9104f, 0.0f);
    glVertex3f(16.0f, 22.9104f, 0.0f);
    glVertex3f(16.0f, 21.9403f, 0.0f);
    glVertex3f(15.0f, 21.9403f, 0.0f);

    glColor3f(0.216, 0.349, 0.384); //2nd row wise apartments
    glVertex3f(12.0f, 20.0746f, 0.0f);
    glVertex3f(12.0f, 20.8955f, 0.0f);
    glVertex3f(13.0f, 20.8955f, 0.0f);
    glVertex3f(13.0f, 20.0746f, 0.0f);

    glVertex3f(13.5f, 20.0746f, 0.0f);
    glVertex3f(13.5f, 20.8955f, 0.0f);
    glVertex3f(14.5f, 20.8955f, 0.0f);
    glVertex3f(14.5f, 20.0746f, 0.0f);

    glVertex3f(15.0f, 20.0746f, 0.0f);
    glVertex3f(15.0f, 20.8955f, 0.0f);
    glVertex3f(16.0f, 20.8955f, 0.0f);
    glVertex3f(16.0f, 20.0746f, 0.0f);

    glColor3f(0.216, 0.349, 0.384); //3rd row wise apartments
    glVertex3f(12.0f, 18.209f, 0.0f);
    glVertex3f(12.0f, 19.1791f, 0.0f);
    glVertex3f(13.0f, 19.1791f, 0.0f);
    glVertex3f(13.0f, 18.209f, 0.0f);

    glVertex3f(13.5f, 18.209f, 0.0f);
    glVertex3f(13.5f, 19.1791f, 0.0f);
    glVertex3f(14.5f, 19.1791f, 0.0f);
    glVertex3f(14.5f, 18.209f, 0.0f);

    glVertex3f(15.0f, 18.209f, 0.0f);
    glVertex3f(15.0f, 19.1791f, 0.0f);
    glVertex3f(16.0f, 19.1791f, 0.0f);
    glVertex3f(16.0f, 18.209f, 0.0f);

    glColor3f(0.216, 0.349, 0.384); //4th row wise apartments

    glVertex3f(12.0f, 16.3433f, 0.0f);
    glVertex3f(12.0f, 17.3134f, 0.0f);
    glVertex3f(13.0f, 17.3134f, 0.0f);
    glVertex3f(13.0f, 16.3433f, 0.0f);

    glVertex3f(13.5f, 16.3433f, 0.0f);
    glVertex3f(13.5f, 17.3134f, 0.0f);
    glVertex3f(14.5f, 17.3134f, 0.0f);
    glVertex3f(14.5f, 16.3433f, 0.0f);

    glVertex3f(15.0f, 16.3433f, 0.0f);
    glVertex3f(15.0f, 17.3134f, 0.0f);
    glVertex3f(16.0f, 17.3134f, 0.0f);
    glVertex3f(16.0f, 16.3433f, 0.0f);

    glColor3f(0.094, 0.184, 0.208); // 1st building big door
    glVertex3f(13.5333f, 13.5552f, 0.0f);
    glVertex3f(13.5333f, 15.2985f, 0.0f);
    glVertex3f(14.5333f, 15.2985f, 0.0f);
    glVertex3f(14.5333f, 13.5552f, 0.0f);

    glColor3f(0.239, 0.369, 0.427);  // door left side window
    glVertex3f(12.0f, 14.2537f, 0.0f);
    glVertex3f(12.0f, 15.2239f, 0.0f);
    glVertex3f(12.6f, 15.2239f, 0.0f);
    glVertex3f(12.6f, 14.2537f, 0.0f);

    glColor3f(0.239, 0.369, 0.427); // door right side window
    glVertex3f(15.2f, 14.3284f, 0.0f);
    glVertex3f(15.2f, 15.2239f, 0.0f);
    glVertex3f(15.8f, 15.2239f, 0.0f);
    glVertex3f(15.8f, 14.3284f, 0.0f);

    glVertex3f(16.1f, 14.3284f, 0.0f);
    glVertex3f(16.1f, 15.2239f, 0.0f);
    glVertex3f(16.8f, 15.2239f, 0.0f);
    glVertex3f(16.8f, 14.3284f, 0.0f);

    glEnd();

    glBegin(GL_LINES); // 1st building ceiling lines

    glColor3f(0.984, 0.749, 0.608);
    glVertex3f(9.8f, 24.1045f, 0.0f);
    glVertex3f(17.4f, 24.1791f, 0.0f);

    glVertex3f(9.8667f, 23.7313f, 0.0f);
    glVertex3f(17.3333f, 23.806f, 0.0f);

    glColor3f(0.957, 0.62, 0.435);
    glVertex3f(9.8f, 15.6716f, 0.0f);
    glVertex3f(17.3333f, 15.6716f, 0.0f);

    glEnd();

    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Colored Building 5th ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);


    glColor3f(0.824, 0.306, 0.255); // building left side shadow
    glVertex3f(17.6f, 13.6313f, 0.0f);
    glVertex3f(17.6f, 23.0597f, 0.0f);
    glVertex3f(19.2f, 23.0597f, 0.0f);
    glVertex3f(19.2f, 13.6313f, 0.0f);

    glColor3f(1.0, 0.439, 0.38); // building right side shadow
    glVertex3f(19.2f, 13.6313f, 0.0f);
    glVertex3f(19.2f, 23.1f, 0.0f);
    glVertex3f(22.2f, 23.1f, 0.0f);
    glVertex3f(22.2f, 13.6313f, 0.0f);

    glColor3f(0.227, 0.345, 0.384); // left side small apartments
    glVertex3f(17.8f, 21.3433f, 0.0f); //1st row
    glVertex3f(17.8f, 22.3881f, 0.0f);
    glVertex3f(18.2f, 22.3881f, 0.0f);
    glVertex3f(18.2f, 21.3433f, 0.0f);

    glColor3f(0.227, 0.345, 0.384);
    glVertex3f(18.4f, 21.3433f, 0.0f);
    glVertex3f(18.4f, 22.3881f, 0.0f);
    glVertex3f(18.8f, 22.3881f, 0.0f);
    glVertex3f(18.8f, 21.3433f, 0.0f);

    glColor3f(0.227, 0.345, 0.384); // 2nd row
    glVertex3f(17.8f, 19.8433f, 0.0f);
    glVertex3f(17.8f, 20.8881f, 0.0f);
    glVertex3f(18.2f, 20.8881f, 0.0f);
    glVertex3f(18.2f, 19.8433f, 0.0f);

    glVertex3f(18.4f, 19.8433f, 0.0f);
    glVertex3f(18.4f, 20.8881f, 0.0f);
    glVertex3f(18.8f, 20.8881f, 0.0f);
    glVertex3f(18.8f, 19.8433f, 0.0f);

    glColor3f(0.227, 0.345, 0.384); // 3rd row
    glVertex3f(17.8f, 18.4433f, 0.0f);
    glVertex3f(17.8f, 19.4881f, 0.0f);
    glVertex3f(18.2f, 19.4881f, 0.0f);
    glVertex3f(18.2f, 18.4433f, 0.0f);

    glVertex3f(18.4f, 18.4433f, 0.0f);
    glVertex3f(18.4f, 19.4881f, 0.0f);
    glVertex3f(18.8f, 19.4881f, 0.0f);
    glVertex3f(18.8f, 18.4433f, 0.0f);

    glColor3f(0.227, 0.345, 0.384); // 4th row
    glVertex3f(17.8f, 17.0433f, 0.0f);
    glVertex3f(17.8f, 18.0881f, 0.0f);
    glVertex3f(18.2f, 18.0881f, 0.0f);
    glVertex3f(18.2f, 17.0433f, 0.0f);

    glVertex3f(18.4f, 17.0433f, 0.0f);
    glVertex3f(18.4f, 18.0881f, 0.0f);
    glVertex3f(18.8f, 18.0881f, 0.0f);
    glVertex3f(18.8f, 17.0433f, 0.0f);

    glColor3f(0.227, 0.345, 0.384); // 5th row
    glVertex3f(17.8f, 15.6433f, 0.0f);
    glVertex3f(17.8f, 16.6881f, 0.0f);
    glVertex3f(18.2f, 16.6881f, 0.0f);
    glVertex3f(18.2f, 15.6433f, 0.0f);

    glVertex3f(18.4f, 15.6433f, 0.0f);
    glVertex3f(18.4f, 16.6881f, 0.0f);
    glVertex3f(18.8f, 16.6881f, 0.0f);
    glVertex3f(18.8f, 15.6433f, 0.0f);

    glVertex3f(17.8f, 13.606f, 0.0f); // 6th
    glVertex3f(17.8f, 15.3731f, 0.0f);
    glVertex3f(18.8f, 15.3731f, 0.0f);
    glVertex3f(18.8f, 13.606f, 0.0f);

    glVertex3f(19.6f, 21.2687f, 0.0f); // building right side apartments
    glVertex3f(19.6f, 22.3881f, 0.0f); // 1st row
    glVertex3f(20.2f, 22.3881f, 0.0f);
    glVertex3f(20.2f, 21.2687f, 0.0f);

    glVertex3f(21.0f, 21.2687f, 0.0f);
    glVertex3f(21.0f, 22.3881f, 0.0f);
    glVertex3f(21.6f, 22.3881f, 0.0f);
    glVertex3f(21.6f, 21.2687f, 0.0f);

    glVertex3f(19.6f, 19.8687f, 0.0f); // 2nd row
    glVertex3f(19.6f, 20.9881f, 0.0f);
    glVertex3f(20.2f, 20.9881f, 0.0f);
    glVertex3f(20.2f, 19.8687f, 0.0f);

    glVertex3f(21.0f, 19.8687f, 0.0f);
    glVertex3f(21.0f, 20.9881f, 0.0f);
    glVertex3f(21.6f, 20.9881f, 0.0f);
    glVertex3f(21.6f, 19.8687f, 0.0f);

    glVertex3f(19.6f, 18.4687f, 0.0f); // 3rd row
    glVertex3f(19.6f, 19.5881f, 0.0f);
    glVertex3f(20.2f, 19.5881f, 0.0f);
    glVertex3f(20.2f, 18.4687f, 0.0f);

    glVertex3f(21.0f, 18.4687f, 0.0f);
    glVertex3f(21.0f, 19.5881f, 0.0f);
    glVertex3f(21.6f, 19.5881f, 0.0f);
    glVertex3f(21.6f, 18.4687f, 0.0f);

    glVertex3f(19.6f, 17.0687f, 0.0f); // 4th row
    glVertex3f(19.6f, 18.1881f, 0.0f);
    glVertex3f(20.2f, 18.1881f, 0.0f);
    glVertex3f(20.2f, 17.0687f, 0.0f);

    glVertex3f(21.0f, 17.0687f, 0.0f);
    glVertex3f(21.0f, 18.1881f, 0.0f);
    glVertex3f(21.6f, 18.1881f, 0.0f);
    glVertex3f(21.6f, 17.0687f, 0.0f);

    glVertex3f(19.6f, 15.6687f, 0.0f); // 5th row
    glVertex3f(19.6f, 16.7881f, 0.0f);
    glVertex3f(20.2f, 16.7881f, 0.0f);
    glVertex3f(20.2f, 15.6687f, 0.0f);

    glVertex3f(21.0f, 15.6687f, 0.0f);
    glVertex3f(21.0f, 16.7881f, 0.0f);
    glVertex3f(21.6f, 16.7881f, 0.0f);
    glVertex3f(21.6f, 15.6687f, 0.0f);

    glVertex3f(19.6f, 13.606f, 0.0f); // 6th row
    glVertex3f(19.6f, 15.3731f, 0.0f);
    glVertex3f(20.2f, 15.3731f, 0.0f);
    glVertex3f(20.2f, 13.606f, 0.0f);

    glVertex3f(21.0f, 13.606f, 0.0f);
    glVertex3f(21.0f, 15.373f, 0.0f);
    glVertex3f(21.6f, 15.3731f, 0.0f);
    glVertex3f(21.6f, 13.606f, 0.0f);

    glEnd();

// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Colored Building 2nd ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);

    glColor3f(0.757, 0.424, 0.345);  // 2nd building left side shadow
    glVertex3f(22.5333f, 13.5806f, 0.0f);
    glVertex3f(22.5333f, 21.9403f, 0.0f);
    glVertex3f(23.8667f, 21.9403f, 0.0f);
    glVertex3f(23.8667f, 13.5806f, 0.0f);

    glColor3f(0.106, 0.18, 0.204); // 2nd building left side small apartments
    glVertex3f(22.9f, 19.6269f, 0.0f);
    glVertex3f(22.9f, 20.597f, 0.0f);
    glVertex3f(23.2f, 20.597f, 0.0f);
    glVertex3f(23.2f, 19.6269f, 0.0f);

    glVertex3f(22.9f, 18.209f, 0.0f);
    glVertex3f(22.9f, 19.1791f, 0.0f);
    glVertex3f(23.2f, 19.1791f, 0.0f);
    glVertex3f(23.2f, 18.209f, 0.0f);

    glVertex3f(22.9f, 16.79f, 0.0f);
    glVertex3f(22.9f, 17.6861f, 0.0f);
    glVertex3f(23.2f, 17.6861f, 0.0f);
    glVertex3f(23.2f, 16.79f, 0.0f);

    glVertex3f(22.9f, 15.3731f, 0.0f);
    glVertex3f(22.9f, 16.2687f, 0.0f);
    glVertex3f(23.2f, 16.2687f, 0.0f);
    glVertex3f(23.2f, 15.3731f, 0.0f);

    glVertex3f(22.9f, 14.1791f, 0.0f);
    glVertex3f(22.9f, 15.0f, 0.0f);
    glVertex3f(23.2f, 15.0f, 0.0f);
    glVertex3f(23.2f, 14.1791f, 0.0f);

    glColor3f(1.0, 0.604, 0.416); // 2nd building body paint
    glVertex3f(23.8f, 13.606f, 0.0f);
    glVertex3f(23.8f, 21.9403f, 0.0f);
    glVertex3f(27.6f, 21.9403f, 0.0f);
    glVertex3f(27.6f, 13.606f, 0.0f);

    glColor3f(1.0, 0.741, 0.604); // ceiling
    glVertex3f(22.6f, 22.0149f, 0.0f);
    glVertex3f(27.6f, 22.0149f, 0.0f);
    glVertex3f(27.6f, 21.6418f, 0.0f);
    glVertex3f(22.6f, 21.6418f, 0.0f);

    glColor3f(0.216, 0.349, 0.384); // 1st row small apartments
    glVertex3f(24.7333f, 19.7015f, 0.0f);
    glVertex3f(24.7333f, 20.5224f, 0.0f);
    glVertex3f(25.3333f, 20.5224f, 0.0f);
    glVertex3f(25.2667f, 19.7015f, 0.0f);

    glVertex3f(25.9333f, 19.7015f, 0.0f);
    glVertex3f(25.9333f, 20.5224f, 0.0f);
    glVertex3f(26.6333f, 20.5224f, 0.0f);
    glVertex3f(26.5667f, 19.7015f, 0.0f);

    glVertex3f(24.7333f, 18.2836f, 0.0f); // 2nd row small apartments
    glVertex3f(24.7333f, 19.2537f, 0.0f);
    glVertex3f(25.3333f, 19.2537f, 0.0f);
    glVertex3f(25.2667f, 18.2836f, 0.0f);

    glVertex3f(25.9333f, 18.2836f, 0.0f);
    glVertex3f(25.9333f, 19.2537f, 0.0f);
    glVertex3f(26.6333f, 19.2537f, 0.0f);
    glVertex3f(26.5667f, 18.2836f, 0.0f);

    glVertex3f(24.7333f, 17.0896f, 0.0f); // 3rd row small apartments
    glVertex3f(24.7333f, 17.9358f, 0.0f);
    glVertex3f(25.3333f, 17.9358f, 0.0f);
    glVertex3f(25.2667f, 17.0896f, 0.0f);

    glVertex3f(25.9333f, 16.9403f, 0.0f);
    glVertex3f(25.9333f, 17.8358f, 0.0f);
    glVertex3f(26.6333f, 17.8358f, 0.0f);
    glVertex3f(26.5667f, 16.9403f, 0.0f);

    glVertex3f(24.7333f, 15.6716f, 0.0f); // 4th row small apartments
    glVertex3f(24.7333f, 16.5672f, 0.0f);
    glVertex3f(25.3333f, 16.5672f, 0.0f);
    glVertex3f(25.2667f, 15.6716f, 0.0f);

    glVertex3f(25.9333f, 15.6716f, 0.0f);
    glVertex3f(25.9333f, 16.4179f, 0.0f);
    glVertex3f(26.6333f, 16.4179f, 0.0f);
    glVertex3f(26.5667f, 15.6716f, 0.0f);

    glVertex3f(24.7333f, 14.2537f, 0.0f); // 5th row small apartments
    glVertex3f(24.7333f, 15.0f, 0.0f);
    glVertex3f(25.3333f, 15.0f, 0.0f);
    glVertex3f(25.2667f, 14.2537f, 0.0f);

    glVertex3f(26.1333f, 13.7313f, 0.0f);
    glVertex3f(26.1333f, 15.2239f, 0.0f);
    glVertex3f(26.9333f, 15.2239f, 0.0f);
    glVertex3f(26.9333f, 13.7313f, 0.0f);

    glEnd();

    glBegin(GL_LINES); // mid body line

    glColor3f(1.0, 0.741, 0.604);
    glVertex3f(22.6667f, 21.1194f, 0.0f);
    glVertex3f(27.5333f, 21.194f, 0.0f);

    glEnd();

// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Colored Building 3rd ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);

    glColor3f(0.788, 0.325, 0.224);  // building left shadow
    glVertex3f(27.6f, 13.5552f, 0.0f);
    glVertex3f(27.6f, 25.597f, 0.0f);
    glVertex3f(29.0f, 25.597f, 0.0f);
    glVertex3f(29.0f, 13.5552f, 0.0f);

    glColor3f(1.0, 0.459, 0.353); // building Right Shadow
    glVertex3f(29.0f, 13.6313f, 0.0f);
    glVertex3f(29.0f, 25.597f, 0.0f);
    glVertex3f(35.2f, 25.597f, 0.0f);
    glVertex3f(35.2f, 13.6313f, 0.0f);

    glColor3f(0.992, 0.757, 0.612); // ceiling
    glVertex3f(27.6f, 25.0f, 0.0f);
    glVertex3f(27.6f, 25.597f, 0.0f);
    glVertex3f(35.2f, 25.597f, 0.0f);
    glVertex3f(35.2667f, 25.0f, 0.0f);

    glColor3f(0.757, 0.502, 0.424); // water tank
    glVertex3f(29.6f, 25.5224f, 0.0f);
    glVertex3f(29.6f, 26.5672f, 0.0f);
    glVertex3f(31.2f, 26.5672f, 0.0f);
    glVertex3f(31.2f, 25.5224f, 0.0f);

    glColor3f(0.757, 0.502, 0.424); // building mid lines
    glVertex3f(27.5667f, 22.8358f, 0.0f);
    glVertex3f(27.5667f, 23.3582f, 0.0f);
    glVertex3f(35.1667f, 23.3582f, 0.0f);
    glVertex3f(35.1333f, 22.8358f, 0.0f);

    glColor3f(0.757, 0.502, 0.424);
    glVertex3f(27.6f, 20.5716f, 0.0f);
    glVertex3f(27.6f, 21.1194f, 0.0f);
    glVertex3f(35.2433f, 21.1194f, 0.0f);
    glVertex3f(35.2433f, 20.5716f, 0.0f);

    glColor3f(0.757, 0.502, 0.424);
    glVertex3f(27.5333f, 18.5075f, 0.0f);
    glVertex3f(27.5333f, 19.0299f, 0.0f);
    glVertex3f(35.1667f, 19.0299f, 0.0f);
    glVertex3f(35.1667f, 18.5075f, 0.0f);

    glColor3f(0.757, 0.502, 0.424);
    glVertex3f(27.6f, 16.194f, 0.0f);
    glVertex3f(27.6f, 16.5672f, 0.0f);
    glVertex3f(35.2f, 16.5672f, 0.0f);
    glVertex3f(35.2f, 16.194f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // building left side small apartment
    glVertex3f(27.9333f, 23.6567f, 0.0f);
    glVertex3f(27.9333f, 24.7761f, 0.0f);
    glVertex3f(28.2667f, 24.7761f, 0.0f);
    glVertex3f(28.2667f, 23.6567f, 0.0f);

    glVertex3f(27.9333f, 21.3567f, 0.0f);
    glVertex3f(27.9333f, 22.4761f, 0.0f);
    glVertex3f(28.2667f, 22.4761f, 0.0f);
    glVertex3f(28.2667f, 21.3567f, 0.0f);

    glVertex3f(27.9333f, 19.1567f, 0.0f);
    glVertex3f(27.9333f, 20.2761f, 0.0f);
    glVertex3f(28.2667f, 20.2761f, 0.0f);
    glVertex3f(28.2667f, 19.1567f, 0.0f);

    glVertex3f(27.9333f, 17.0567f, 0.0f);
    glVertex3f(27.9333f, 18.0761f, 0.0f);
    glVertex3f(28.2667f, 18.0761f, 0.0f);
    glVertex3f(28.2667f, 17.0567f, 0.0f);

    glVertex3f(27.9333f, 14.6567f, 0.0f);
    glVertex3f(27.9333f, 15.6761f, 0.0f);
    glVertex3f(28.2667f, 15.6761f, 0.0f);
    glVertex3f(28.2667f, 14.6567f, 0.0f);

    glColor3f(0.22, 0.353, 0.392);// building right side small apartments
    glVertex3f(29.4f, 23.806f, 0.0f); // 1st row
    glVertex3f(29.4f, 24.6269f, 0.0f);
    glVertex3f(29.9f, 24.6269f, 0.0f);
    glVertex3f(29.9f, 23.806f, 0.0f);

    glVertex3f(30.4f, 23.806f, 0.0f);
    glVertex3f(30.4f, 24.6269f, 0.0f);
    glVertex3f(30.9f, 24.6269f, 0.0f);
    glVertex3f(30.9f, 23.806f, 0.0f);

    glVertex3f(31.4f, 23.806f, 0.0f);
    glVertex3f(31.4f, 24.6269f, 0.0f);
    glVertex3f(31.9f, 24.6269f, 0.0f);
    glVertex3f(31.9f, 23.806f, 0.0f);

    glVertex3f(32.4f, 23.806f, 0.0f);
    glVertex3f(32.4f, 24.6269f, 0.0f);
    glVertex3f(32.9f, 24.6269f, 0.0f);
    glVertex3f(32.9f, 23.806f, 0.0f);

    glVertex3f(33.4f, 23.806f, 0.0f);
    glVertex3f(33.4f, 24.6269f, 0.0f);
    glVertex3f(33.9f, 24.6269f, 0.0f);
    glVertex3f(33.9f, 23.806f, 0.0f);

    glVertex3f(34.4f, 23.806f, 0.0f);
    glVertex3f(34.4f, 24.6269f, 0.0f);
    glVertex3f(34.9f, 24.6269f, 0.0f);
    glVertex3f(34.9f, 23.806f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // 2nd row
    glVertex3f(29.4f, 21.5672f, 0.0f);
    glVertex3f(29.4f, 22.3881f, 0.0f);
    glVertex3f(30.0f, 22.3881f, 0.0f);
    glVertex3f(30.0f, 21.5672f, 0.0f);

    glVertex3f(30.4f, 21.5672f, 0.0f);
    glVertex3f(30.4f, 22.3881f, 0.0f);
    glVertex3f(31.0f, 22.3881f, 0.0f);
    glVertex3f(31.0f, 21.5672f, 0.0f);

    glVertex3f(31.4f, 21.5672f, 0.0f);
    glVertex3f(31.4f, 22.3881f, 0.0f);
    glVertex3f(32.0f, 22.3881f, 0.0f);
    glVertex3f(32.0f, 21.5672f, 0.0f);

    glVertex3f(32.4f, 21.5672f, 0.0f);
    glVertex3f(32.4f, 22.3881f, 0.0f);
    glVertex3f(33.0f, 22.3881f, 0.0f);
    glVertex3f(33.0f, 21.5672f, 0.0f);

    glVertex3f(33.4f, 21.5672f, 0.0f);
    glVertex3f(33.4f, 22.3881f, 0.0f);
    glVertex3f(34.0f, 22.3881f, 0.0f);
    glVertex3f(34.0f, 21.5672f, 0.0f);

    glVertex3f(34.4f, 21.5672f, 0.0f);
    glVertex3f(34.4f, 22.3881f, 0.0f);
    glVertex3f(35.0f, 22.3881f, 0.0f);
    glVertex3f(35.0f, 21.5672f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // 3rd row
    glVertex3f(29.4f, 19.3284f, 0.0f);
    glVertex3f(29.4f, 20.2985f, 0.0f);
    glVertex3f(30.0f, 20.2985f, 0.0f);
    glVertex3f(30.0f, 19.3284f, 0.0f);

    glVertex3f(30.4f, 19.3284f, 0.0f);
    glVertex3f(30.4f, 20.2985f, 0.0f);
    glVertex3f(31.0f, 20.2985f, 0.0f);
    glVertex3f(31.0f, 19.3284f, 0.0f);

    glVertex3f(31.4f, 19.3284f, 0.0f);
    glVertex3f(31.4f, 20.2985f, 0.0f);
    glVertex3f(32.0f, 20.2985f, 0.0f);
    glVertex3f(32.0f, 19.3284f, 0.0f);

    glVertex3f(32.4f, 19.3284f, 0.0f);
    glVertex3f(32.4f, 20.2985f, 0.0f);
    glVertex3f(33.0f, 20.2985f, 0.0f);
    glVertex3f(33.0f, 19.3284f, 0.0f);

    glVertex3f(33.4f, 19.3284f, 0.0f);
    glVertex3f(33.4f, 20.2985f, 0.0f);
    glVertex3f(34.0f, 20.2985f, 0.0f);
    glVertex3f(34.0f, 19.3284f, 0.0f);

    glVertex3f(34.4f, 19.3284f, 0.0f);
    glVertex3f(34.4f, 20.2985f, 0.0f);
    glVertex3f(35.0f, 20.2985f, 0.0f);
    glVertex3f(35.0f, 19.3284f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // 4th row
    glVertex3f(29.4f, 17.1642f, 0.0f);
    glVertex3f(29.4f, 17.9851f, 0.0f);
    glVertex3f(30.0f, 17.9851f, 0.0f);
    glVertex3f(30.0f, 17.1642f, 0.0f);

    glVertex3f(30.4f, 17.1642f, 0.0f);
    glVertex3f(30.4f, 17.9851f, 0.0f);
    glVertex3f(31.0f, 17.9851f, 0.0f);
    glVertex3f(31.0f, 17.1642f, 0.0f);

    glVertex3f(31.4f, 17.1642f, 0.0f);
    glVertex3f(31.4f, 17.9851f, 0.0f);
    glVertex3f(32.0f, 17.9851f, 0.0f);
    glVertex3f(32.0f, 17.1642f, 0.0f);

    glVertex3f(32.4f, 17.1642f, 0.0f);
    glVertex3f(32.4f, 17.9851f, 0.0f);
    glVertex3f(33.0f, 17.9851f, 0.0f);
    glVertex3f(33.0f, 17.1642f, 0.0f);

    glVertex3f(33.4f, 17.1642f, 0.0f);
    glVertex3f(33.4f, 17.9851f, 0.0f);
    glVertex3f(34.0f, 17.9851f, 0.0f);
    glVertex3f(34.0f, 17.1642f, 0.0f);

    glVertex3f(34.4f, 17.1642f, 0.0f);
    glVertex3f(34.4f, 17.9851f, 0.0f);
    glVertex3f(35.0f, 17.9851f, 0.0f);
    glVertex3f(35.0f, 17.1642f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // 5th row
    glVertex3f(29.4f, 13.5806f, 0.0f);
    glVertex3f(29.4f, 15.4478f, 0.0f);
    glVertex3f(31.0f, 15.4478f, 0.0f);
    glVertex3f(31.0f, 13.5806f, 0.0f);

    glVertex3f(31.6667f, 13.6313f, 0.0f);
    glVertex3f(31.6667f, 15.5224f, 0.0f);
    glVertex3f(32.5333f, 15.5224f, 0.0f);
    glVertex3f(32.5333f, 13.6313f, 0.0f);

    glVertex3f(34.0f, 13.6552f, 0.0f);
    glVertex3f(34.0f, 15.4478f, 0.0f);
    glVertex3f(35.0f, 15.4478f, 0.0f);
    glVertex3f(35.0f, 13.6552f, 0.0f);

    glColor3f(0.816, 0.306, 0.255);
    glVertex3f(33.0f, 13.6806f, 0.0f);
    glVertex3f(33.0f, 15.3731f, 0.0f);
    glVertex3f(33.6667f, 15.3731f, 0.0f);
    glVertex3f(33.6667f, 13.6806f, 0.0f);

    glEnd();

// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Colored Building 4th ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);


    glColor3f(0.788, 0.314, 0.239);  // building left part
    glVertex3f(35.2f, 13.606f, 0.0f);
    glVertex3f(35.2f, 17.8358f, 0.0f);
    glVertex3f(37.0f, 17.8358f, 0.0f);
    glVertex3f(37.0f, 13.606f, 0.0f);

    glColor3f(1.0, 0.439, 0.376); // building right body
    glVertex3f(37.0f, 13.606f, 0.0f);
    glVertex3f(37.0f, 17.8358f, 0.0f);
    glVertex3f(41.9333f, 17.8358f, 0.0f);
    glVertex3f(41.9333f, 13.606f, 0.0f);

    glColor3f(0.894, 0.878, 0.875); // building down part
    glVertex3f(35.2f, 13.606f, 0.0f);
    glVertex3f(35.2f, 14.7015f, 0.0f);
    glVertex3f(41.9333f, 14.7015f, 0.0f);
    glVertex3f(41.9333f, 13.606f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // building left part apartment
    glVertex3f(35.6667f, 14.6522f, 0.0f);
    glVertex3f(35.6667f, 16.8657f, 0.0f);
    glVertex3f(36.6f, 16.8657f, 0.0f);
    glVertex3f(36.6f, 14.6522f, 0.0f);

    glVertex3f(37.4f, 16.4448f, 0.0f); // building right part small apartments
    glVertex3f(37.4f, 16.9164f, 0.0f); // 1st row
    glVertex3f(38.0f, 16.9164f, 0.0f);
    glVertex3f(38.0f, 16.4448f, 0.0f);

    glVertex3f(38.8f, 16.4448f, 0.0f);
    glVertex3f(38.8f, 16.9164f, 0.0f);
    glVertex3f(39.4f, 16.9164f, 0.0f);
    glVertex3f(39.4f, 16.4448f, 0.0f);

    glVertex3f(40.2f, 16.4448f, 0.0f);
    glVertex3f(40.2f, 16.9164f, 0.0f);
    glVertex3f(41.0f, 16.9164f, 0.0f);
    glVertex3f(41.0f, 16.4448f, 0.0f);

    glVertex3f(37.4f, 13.7313f, 0.0f); // 2nd row
    glVertex3f(37.4f, 15.5224f, 0.0f);
    glVertex3f(38.2f, 15.5224f, 0.0f);
    glVertex3f(38.2f, 13.7313f, 0.0f);

    glVertex3f(38.5333f, 15.0f, 0.0f);
    glVertex3f(38.5333f, 15.6716f, 0.0f);
    glVertex3f(39.0f, 15.6716f, 0.0f);
    glVertex3f(39.0f, 15.0f, 0.0f);

    glVertex3f(39.5333f, 15.0f, 0.0f);
    glVertex3f(39.5333f, 15.6716f, 0.0f);
    glVertex3f(40.5f, 15.6716f, 0.0f);
    glVertex3f(40.5f, 15.0f, 0.0f);

    glEnd();



// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Colored Building 4th ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_QUADS);


    glColor3f(0.788, 0.314, 0.239);  // building left part
    glVertex3f(35.2f, 13.606f, 0.0f);
    glVertex3f(35.2f, 17.8358f, 0.0f);
    glVertex3f(37.0f, 17.8358f, 0.0f);
    glVertex3f(37.0f, 13.606f, 0.0f);

    glColor3f(1.0, 0.439, 0.376); // building right body
    glVertex3f(37.0f, 13.606f, 0.0f);
    glVertex3f(37.0f, 17.8358f, 0.0f);
    glVertex3f(41.9333f, 17.8358f, 0.0f);
    glVertex3f(41.9333f, 13.606f, 0.0f);

    glColor3f(0.894, 0.878, 0.875); // building down part
    glVertex3f(35.2f, 13.606f, 0.0f);
    glVertex3f(35.2f, 14.7015f, 0.0f);
    glVertex3f(41.9333f, 14.7015f, 0.0f);
    glVertex3f(41.9333f, 13.606f, 0.0f);

    glColor3f(0.22, 0.353, 0.392); // building left part apartment
    glVertex3f(35.6667f, 14.6522f, 0.0f);
    glVertex3f(35.6667f, 16.8657f, 0.0f);
    glVertex3f(36.6f, 16.8657f, 0.0f);
    glVertex3f(36.6f, 14.6522f, 0.0f);

    glVertex3f(37.4f, 16.4448f, 0.0f); // building right part small apartments
    glVertex3f(37.4f, 16.9164f, 0.0f); // 1st row
    glVertex3f(38.0f, 16.9164f, 0.0f);
    glVertex3f(38.0f, 16.4448f, 0.0f);

    glVertex3f(38.8f, 16.4448f, 0.0f);
    glVertex3f(38.8f, 16.9164f, 0.0f);
    glVertex3f(39.4f, 16.9164f, 0.0f);
    glVertex3f(39.4f, 16.4448f, 0.0f);

    glVertex3f(40.2f, 16.4448f, 0.0f);
    glVertex3f(40.2f, 16.9164f, 0.0f);
    glVertex3f(41.0f, 16.9164f, 0.0f);
    glVertex3f(41.0f, 16.4448f, 0.0f);

    glVertex3f(37.4f, 13.7313f, 0.0f); // 2nd row
    glVertex3f(37.4f, 15.5224f, 0.0f);
    glVertex3f(38.2f, 15.5224f, 0.0f);
    glVertex3f(38.2f, 13.7313f, 0.0f);

    glVertex3f(38.5333f, 15.0f, 0.0f);
    glVertex3f(38.5333f, 15.6716f, 0.0f);
    glVertex3f(39.0f, 15.6716f, 0.0f);
    glVertex3f(39.0f, 15.0f, 0.0f);

    glVertex3f(39.5333f, 15.0f, 0.0f);
    glVertex3f(39.5333f, 15.6716f, 0.0f);
    glVertex3f(40.5f, 15.6716f, 0.0f);
    glVertex3f(40.5f, 15.0f, 0.0f);

    glEnd();



    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREES ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬









    // ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE   1          ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.227, 0.31, 0.149);
    glVertex3f(2.4f, 15.1493f, 0.0f);


    glVertex3f(1.2667f, 14.1791f, 0.0f);
    glVertex3f(1.2667f, 14.1045f, 0.0f);
    glVertex3f(1.2f, 13.9552f, 0.0f);
    glVertex3f(1.1333f, 13.8806f, 0.0f);
    glVertex3f(1.1333f, 13.806f, 0.0f);
    glVertex3f(1.0667f, 13.806f, 0.0f);
    glVertex3f(1.0f, 13.806f, 0.0f);
    glVertex3f(0.9333f, 13.806f, 0.0f);
    glVertex3f(0.8667f, 13.806f, 0.0f);
    glVertex3f(0.8f, 13.806f, 0.0f);
    glVertex3f(0.7333f, 13.8806f, 0.0f);
    glVertex3f(0.6667f, 13.8806f, 0.0f);
    glVertex3f(0.6f, 13.8806f, 0.0f);
    glVertex3f(0.5333f, 13.8806f, 0.0f);
    glVertex3f(0.4667f, 13.9552f, 0.0f);
    glVertex3f(0.4f, 13.9552f, 0.0f);
    glVertex3f(0.4f, 14.0299f, 0.0f);
    glVertex3f(0.3333f, 14.1045f, 0.0f);
    glVertex3f(0.2667f, 14.1791f, 0.0f);
    glVertex3f(0.2667f, 14.2537f, 0.0f);
    glVertex3f(0.2667f, 14.3284f, 0.0f);
    glVertex3f(0.2f, 14.403f, 0.0f);
    glVertex3f(0.2f, 14.4776f, 0.0f);
    glVertex3f(0.2f, 14.5522f, 0.0f);
    glVertex3f(0.2f, 14.6269f, 0.0f);
    glVertex3f(0.2f, 14.7015f, 0.0f);
    glVertex3f(0.2f, 14.7761f, 0.0f);
    glVertex3f(0.2f, 14.8507f, 0.0f);
    glVertex3f(0.2f, 14.9254f, 0.0f);
    glVertex3f(0.2667f, 14.9254f, 0.0f);
    glVertex3f(0.3333f, 14.9254f, 0.0f);
    glVertex3f(0.4f, 15.0f, 0.0f);
    glVertex3f(0.4667f, 15.0746f, 0.0f);
    glVertex3f(0.5333f, 15.0746f, 0.0f);
    glVertex3f(0.6f, 15.1493f, 0.0f);
    glVertex3f(0.6667f, 15.1493f, 0.0f);
    glVertex3f(0.7333f, 15.1493f, 0.0f);
    glVertex3f(0.6667f, 15.1493f, 0.0f);
    glVertex3f(0.6f, 15.1493f, 0.0f);
    glVertex3f(0.5333f, 15.1493f, 0.0f);
    glVertex3f(0.4667f, 15.1493f, 0.0f);
    glVertex3f(0.4f, 15.1493f, 0.0f);
    glVertex3f(0.3333f, 15.1493f, 0.0f);
    glVertex3f(0.2667f, 15.2239f, 0.0f);
    glVertex3f(0.2667f, 15.2985f, 0.0f);
    glVertex3f(0.2f, 15.3731f, 0.0f);
    glVertex3f(0.2f, 15.4478f, 0.0f);
    glVertex3f(0.2f, 15.5224f, 0.0f);
    glVertex3f(0.2f, 15.597f, 0.0f);
    glVertex3f(0.2f, 15.6716f, 0.0f);
    glVertex3f(0.2f, 15.7463f, 0.0f);
    glVertex3f(0.2f, 15.8209f, 0.0f);
    glVertex3f(0.2f, 15.8955f, 0.0f);
    glVertex3f(0.2f, 15.9701f, 0.0f);
    glVertex3f(0.2f, 16.0448f, 0.0f);
    glVertex3f(0.2f, 16.1194f, 0.0f);
    glVertex3f(0.2667f, 16.194f, 0.0f);
    glVertex3f(0.3333f, 16.194f, 0.0f);
    glVertex3f(0.4f, 16.2687f, 0.0f);
    glVertex3f(0.4667f, 16.2687f, 0.0f);
    glVertex3f(0.5333f, 16.2687f, 0.0f);
    glVertex3f(0.6667f, 16.3433f, 0.0f);
    glVertex3f(0.7333f, 16.3433f, 0.0f);
    glVertex3f(0.8f, 16.3433f, 0.0f);
    glVertex3f(0.8667f, 16.3433f, 0.0f);
    glVertex3f(0.9333f, 16.3433f, 0.0f);
    glVertex3f(0.9333f, 16.4179f, 0.0f);
    glVertex3f(0.8667f, 16.4925f, 0.0f);
    glVertex3f(0.8667f, 16.5672f, 0.0f);
    glVertex3f(0.8f, 16.6418f, 0.0f);
    glVertex3f(0.8f, 16.791f, 0.0f);
    glVertex3f(0.8f, 16.8657f, 0.0f);
    glVertex3f(0.7333f, 16.9403f, 0.0f);
    glVertex3f(0.8f, 17.0149f, 0.0f);
    glVertex3f(0.8667f, 17.0896f, 0.0f);
    glVertex3f(0.9333f, 17.0896f, 0.0f);
    glVertex3f(1.0f, 17.0896f, 0.0f);
    glVertex3f(1.0667f, 17.0896f, 0.0f);
    glVertex3f(1.1333f, 17.1642f, 0.0f);
    glVertex3f(1.2f, 17.1642f, 0.0f);
    glVertex3f(1.2667f, 17.1642f, 0.0f);
    glVertex3f(1.3333f, 17.1642f, 0.0f);
    glVertex3f(1.4f, 17.1642f, 0.0f);
    glVertex3f(1.4667f, 17.1642f, 0.0f);
    glVertex3f(1.5333f, 17.1642f, 0.0f);
    glVertex3f(1.5333f, 17.0896f, 0.0f);
    glVertex3f(1.6f, 17.0149f, 0.0f);
    glVertex3f(1.6f, 16.9403f, 0.0f);
    glVertex3f(1.6f, 16.8657f, 0.0f);
    glVertex3f(1.6667f, 16.8657f, 0.0f);
    glVertex3f(1.6667f, 16.791f, 0.0f);
    glVertex3f(1.6667f, 16.7164f, 0.0f);
    glVertex3f(1.6667f, 16.6418f, 0.0f);
    glVertex3f(1.6667f, 16.5672f, 0.0f);
    glVertex3f(1.6667f, 16.4925f, 0.0f);
    glVertex3f(1.7333f, 16.5672f, 0.0f);
    glVertex3f(1.7333f, 16.6418f, 0.0f);
    glVertex3f(1.7333f, 16.7164f, 0.0f);
    glVertex3f(1.8f, 16.8657f, 0.0f);
    glVertex3f(1.8f, 16.9403f, 0.0f);
    glVertex3f(1.8f, 17.0896f, 0.0f);
    glVertex3f(1.8667f, 17.1642f, 0.0f);
    glVertex3f(1.8667f, 17.2388f, 0.0f);
    glVertex3f(1.9333f, 17.2388f, 0.0f);
    glVertex3f(2.0667f, 17.3134f, 0.0f);
    glVertex3f(2.1333f, 17.3134f, 0.0f);
    glVertex3f(2.2f, 17.3134f, 0.0f);
    glVertex3f(2.2667f, 17.3881f, 0.0f);
    glVertex3f(2.2667f, 17.4627f, 0.0f);
    glVertex3f(2.2f, 17.4627f, 0.0f);
    glVertex3f(2.1333f, 17.5373f, 0.0f);
    glVertex3f(2.0f, 17.5373f, 0.0f);
    glVertex3f(2.0f, 17.6119f, 0.0f);
    glVertex3f(2.0f, 17.6866f, 0.0f);
    glVertex3f(2.0f, 17.7612f, 0.0f);
    glVertex3f(2.0f, 17.8358f, 0.0f);
    glVertex3f(2.0f, 17.9104f, 0.0f);
    glVertex3f(2.0f, 17.9851f, 0.0f);
    glVertex3f(2.0667f, 17.9851f, 0.0f);
    glVertex3f(2.1333f, 17.9851f, 0.0f);
    glVertex3f(2.1333f, 18.0597f, 0.0f);
    glVertex3f(2.2f, 18.0597f, 0.0f);
    glVertex3f(2.2667f, 18.0597f, 0.0f);
    glVertex3f(2.3333f, 18.0597f, 0.0f);
    glVertex3f(2.4f, 18.0597f, 0.0f);
    glVertex3f(2.4667f, 18.0597f, 0.0f);
    glVertex3f(2.5333f, 18.0597f, 0.0f);
    glVertex3f(2.6667f, 18.0597f, 0.0f);
    glVertex3f(2.6667f, 17.9851f, 0.0f);
    glVertex3f(2.7333f, 17.9851f, 0.0f);
    glVertex3f(2.7333f, 17.8358f, 0.0f);
    glVertex3f(2.8f, 17.7612f, 0.0f);
    glVertex3f(2.8667f, 17.6866f, 0.0f);
    glVertex3f(2.8667f, 17.6119f, 0.0f);
    glVertex3f(2.8667f, 17.5373f, 0.0f);
    glVertex3f(2.8667f, 17.4627f, 0.0f);
    glVertex3f(2.8667f, 17.3881f, 0.0f);
    glVertex3f(2.8667f, 17.3134f, 0.0f);
    glVertex3f(2.8667f, 17.1642f, 0.0f);
    glVertex3f(2.8667f, 17.0896f, 0.0f);
    glVertex3f(2.8f, 17.0896f, 0.0f);
    glVertex3f(2.7333f, 17.0149f, 0.0f);
    glVertex3f(2.8f, 16.9403f, 0.0f);
    glVertex3f(2.8667f, 16.9403f, 0.0f);
    glVertex3f(2.8667f, 16.8657f, 0.0f);
    glVertex3f(2.9333f, 16.8657f, 0.0f);
    glVertex3f(3.0f, 16.8657f, 0.0f);
    glVertex3f(3.0667f, 16.791f, 0.0f);
    glVertex3f(3.1333f, 16.7164f, 0.0f);
    glVertex3f(3.1333f, 16.6418f, 0.0f);
    glVertex3f(3.1333f, 16.5672f, 0.0f);
    glVertex3f(3.1333f, 16.4925f, 0.0f);
    glVertex3f(3.1333f, 16.4179f, 0.0f);
    glVertex3f(3.1333f, 16.3433f, 0.0f);
    glVertex3f(3.1333f, 16.2687f, 0.0f);
    glVertex3f(3.1333f, 16.194f, 0.0f);
    glVertex3f(3.0667f, 16.194f, 0.0f);
    glVertex3f(3.0f, 16.194f, 0.0f);
    glVertex3f(2.9333f, 16.194f, 0.0f);
    glVertex3f(2.8667f, 16.1194f, 0.0f);
    glVertex3f(2.9333f, 16.0448f, 0.0f);
    glVertex3f(3.0f, 16.0448f, 0.0f);
    glVertex3f(3.1333f, 16.0448f, 0.0f);
    glVertex3f(3.2f, 15.9701f, 0.0f);
    glVertex3f(3.2667f, 15.8955f, 0.0f);
    glVertex3f(3.3333f, 15.8209f, 0.0f);
    glVertex3f(3.3333f, 15.7463f, 0.0f);
    glVertex3f(3.3333f, 15.6716f, 0.0f);
    glVertex3f(3.3333f, 15.597f, 0.0f);
    glVertex3f(3.3333f, 15.5224f, 0.0f);
    glVertex3f(3.3333f, 15.4478f, 0.0f);
    glVertex3f(3.3333f, 15.3731f, 0.0f);
    glVertex3f(3.2667f, 15.2985f, 0.0f);
    glVertex3f(3.2f, 15.1493f, 0.0f);
    glVertex3f(3.1333f, 15.1493f, 0.0f);
    glVertex3f(3.0667f, 15.1493f, 0.0f);
    glVertex3f(3.0f, 15.0746f, 0.0f);
    glVertex3f(2.9333f, 15.0746f, 0.0f);
    glVertex3f(2.8667f, 15.0f, 0.0f);
    glVertex3f(2.8f, 15.0f, 0.0f);
    glVertex3f(2.8667f, 15.0f, 0.0f);
    glVertex3f(2.8667f, 14.9254f, 0.0f);
    glVertex3f(2.9333f, 14.9254f, 0.0f);
    glVertex3f(3.0f, 14.8507f, 0.0f);
    glVertex3f(3.0f, 14.7761f, 0.0f);
    glVertex3f(3.0f, 14.7015f, 0.0f);
    glVertex3f(3.0667f, 14.7015f, 0.0f);
    glVertex3f(3.0667f, 14.6269f, 0.0f);
    glVertex3f(3.0667f, 14.5522f, 0.0f);
    glVertex3f(3.0667f, 14.4776f, 0.0f);
    glVertex3f(3.0667f, 14.403f, 0.0f);
    glVertex3f(3.1333f, 14.3284f, 0.0f);
    glVertex3f(3.1333f, 14.2537f, 0.0f);
    glVertex3f(3.0667f, 14.1791f, 0.0f);
    glVertex3f(3.0f, 14.1791f, 0.0f);
    glVertex3f(2.9333f, 14.1791f, 0.0f);
    glVertex3f(2.8667f, 14.1791f, 0.0f);
    glVertex3f(2.8f, 14.1791f, 0.0f);
    glVertex3f(2.7333f, 14.1791f, 0.0f);
    glVertex3f(2.6667f, 14.1791f, 0.0f);
    glVertex3f(2.6f, 14.1791f, 0.0f);
    glVertex3f(2.5333f, 14.1791f, 0.0f);
    glVertex3f(2.4667f, 14.1791f, 0.0f);
    glVertex3f(2.4f, 14.1791f, 0.0f);
    glVertex3f(2.3333f, 14.1791f, 0.0f);
    glVertex3f(2.2667f, 14.2537f, 0.0f);
    glVertex3f(2.2667f, 14.3284f, 0.0f);
    glVertex3f(2.2f, 14.3284f, 0.0f);
    glVertex3f(2.2f, 14.2537f, 0.0f);
    glVertex3f(2.2f, 14.1791f, 0.0f);
    glVertex3f(2.2f, 14.1045f, 0.0f);
    glVertex3f(2.1333f, 14.1045f, 0.0f);
    glVertex3f(2.0667f, 14.0299f, 0.0f);
    glVertex3f(2.0f, 14.0299f, 0.0f);
    glVertex3f(1.9333f, 14.0299f, 0.0f);
    glVertex3f(1.8667f, 14.0299f, 0.0f);
    glVertex3f(1.8f, 14.0299f, 0.0f);
    glVertex3f(1.7333f, 13.9552f, 0.0f);
    glVertex3f(1.6667f, 13.9552f, 0.0f);
    glVertex3f(1.6f, 13.9552f, 0.0f);
    glVertex3f(1.5333f, 13.9552f, 0.0f);
    glVertex3f(1.4667f, 13.9552f, 0.0f);
    glVertex3f(1.4f, 13.9552f, 0.0f);
    glVertex3f(1.3333f, 13.9552f, 0.0f);
    glVertex3f(1.2667f, 13.9552f, 0.0f);
    glVertex3f(1.2f, 13.9552f, 0.0f);
    glVertex3f(1.1333f, 13.9552f, 0.0f);
    glVertex3f(1.0667f, 13.9552f, 0.0f);
    glVertex3f(1.0f, 13.9552f, 0.0f);
    glVertex3f(0.9333f, 13.9552f, 0.0f);
    glVertex3f(0.8667f, 13.9552f, 0.0f);
    glVertex3f(0.8f, 13.9552f, 0.0f);

    glEnd();


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE    2¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.239, 0.302, 0.149);
    glVertex3f(5.0667f, 15.0746f, 0.0f);


    glVertex3f(3.0f, 16.3433f, 0.0f);
    glVertex3f(3.0f, 16.4179f, 0.0f);
    glVertex3f(3.0f, 16.4925f, 0.0f);
    glVertex3f(3.0667f, 16.6418f, 0.0f);
    glVertex3f(3.1333f, 16.7164f, 0.0f);
    glVertex3f(3.1333f, 16.791f, 0.0f);
    glVertex3f(3.1333f, 16.8657f, 0.0f);
    glVertex3f(3.2f, 16.9403f, 0.0f);
    glVertex3f(3.2667f, 16.9403f, 0.0f);
    glVertex3f(3.3333f, 16.9403f, 0.0f);
    glVertex3f(3.4f, 16.9403f, 0.0f);
    glVertex3f(3.4667f, 17.0149f, 0.0f);
    glVertex3f(3.5333f, 17.0149f, 0.0f);
    glVertex3f(3.6f, 17.0149f, 0.0f);
    glVertex3f(3.6667f, 17.0149f, 0.0f);
    glVertex3f(3.7333f, 17.0896f, 0.0f);
    glVertex3f(3.8f, 17.0896f, 0.0f);
    glVertex3f(3.8667f, 17.0896f, 0.0f);
    glVertex3f(3.9333f, 17.0896f, 0.0f);
    glVertex3f(4.0f, 17.0896f, 0.0f);
    glVertex3f(4.0667f, 17.0896f, 0.0f);
    glVertex3f(4.1333f, 17.0149f, 0.0f);
    glVertex3f(4.0667f, 16.9403f, 0.0f);
    glVertex3f(4.0f, 16.8657f, 0.0f);
    glVertex3f(4.0f, 16.791f, 0.0f);
    glVertex3f(3.9333f, 16.791f, 0.0f);
    glVertex3f(3.9333f, 16.7164f, 0.0f);
    glVertex3f(3.8667f, 16.7164f, 0.0f);
    glVertex3f(3.9333f, 16.7164f, 0.0f);
    glVertex3f(4.0f, 16.7164f, 0.0f);
    glVertex3f(4.0667f, 16.7164f, 0.0f);
    glVertex3f(4.1333f, 16.7164f, 0.0f);
    glVertex3f(4.2f, 16.6418f, 0.0f);
    glVertex3f(4.2667f, 16.6418f, 0.0f);
    glVertex3f(4.3333f, 16.5672f, 0.0f);
    glVertex3f(4.4f, 16.4925f, 0.0f);
    glVertex3f(4.4667f, 16.4179f, 0.0f);
    glVertex3f(4.4667f, 16.3433f, 0.0f);
    glVertex3f(4.4667f, 16.2687f, 0.0f);
    glVertex3f(4.4667f, 16.194f, 0.0f);
    glVertex3f(4.4f, 16.194f, 0.0f);
    glVertex3f(4.3333f, 16.0448f, 0.0f);
    glVertex3f(4.2667f, 16.0448f, 0.0f);
    glVertex3f(4.2f, 15.9701f, 0.0f);
    glVertex3f(4.2667f, 15.9701f, 0.0f);
    glVertex3f(4.3333f, 15.9701f, 0.0f);
    glVertex3f(4.4f, 15.9701f, 0.0f);
    glVertex3f(4.4667f, 15.9701f, 0.0f);
    glVertex3f(4.4667f, 16.0448f, 0.0f);
    glVertex3f(4.4667f, 16.1194f, 0.0f);
    glVertex3f(4.4667f, 16.194f, 0.0f);
    glVertex3f(4.4667f, 16.2687f, 0.0f);
    glVertex3f(4.4667f, 16.3433f, 0.0f);
    glVertex3f(4.4667f, 16.4179f, 0.0f);
    glVertex3f(4.4667f, 16.4925f, 0.0f);
    glVertex3f(4.4667f, 16.5672f, 0.0f);
    glVertex3f(4.4667f, 16.6418f, 0.0f);
    glVertex3f(4.5333f, 16.7164f, 0.0f);
    glVertex3f(4.6f, 16.7164f, 0.0f);
    glVertex3f(4.6667f, 16.7164f, 0.0f);
    glVertex3f(4.8f, 16.791f, 0.0f);
    glVertex3f(4.8667f, 16.791f, 0.0f);
    glVertex3f(4.8667f, 16.8657f, 0.0f);
    glVertex3f(4.9333f, 16.8657f, 0.0f);
    glVertex3f(4.9333f, 16.9403f, 0.0f);
    glVertex3f(4.9333f, 17.0149f, 0.0f);
    glVertex3f(4.9333f, 17.0896f, 0.0f);
    glVertex3f(4.9333f, 17.1642f, 0.0f);
    glVertex3f(4.9333f, 17.2388f, 0.0f);
    glVertex3f(4.9333f, 17.3881f, 0.0f);
    glVertex3f(4.9333f, 17.4627f, 0.0f);
    glVertex3f(4.9333f, 17.5373f, 0.0f);
    glVertex3f(4.9333f, 17.6119f, 0.0f);
    glVertex3f(4.9333f, 17.6866f, 0.0f);
    glVertex3f(4.9333f, 17.7612f, 0.0f);
    glVertex3f(4.9333f, 17.8358f, 0.0f);
    glVertex3f(5.0f, 17.9104f, 0.0f);
    glVertex3f(5.0667f, 17.9851f, 0.0f);
    glVertex3f(5.0667f, 18.0597f, 0.0f);
    glVertex3f(5.0667f, 18.1343f, 0.0f);
    glVertex3f(5.1333f, 18.1343f, 0.0f);
    glVertex3f(5.2f, 18.1343f, 0.0f);
    glVertex3f(5.2667f, 18.1343f, 0.0f);
    glVertex3f(5.2667f, 18.0597f, 0.0f);
    glVertex3f(5.3333f, 17.9851f, 0.0f);
    glVertex3f(5.4f, 17.9851f, 0.0f);
    glVertex3f(5.4f, 17.9104f, 0.0f);
    glVertex3f(5.4f, 17.8358f, 0.0f);
    glVertex3f(5.4f, 17.7612f, 0.0f);
    glVertex3f(5.4f, 17.6866f, 0.0f);
    glVertex3f(5.4f, 17.6119f, 0.0f);
    glVertex3f(5.4f, 17.4627f, 0.0f);
    glVertex3f(5.4f, 17.3881f, 0.0f);
    glVertex3f(5.3333f, 17.3881f, 0.0f);
    glVertex3f(5.3333f, 17.3134f, 0.0f);
    glVertex3f(5.2667f, 17.3134f, 0.0f);
    glVertex3f(5.2667f, 17.1642f, 0.0f);
    glVertex3f(5.2f, 17.1642f, 0.0f);
    glVertex3f(5.2667f, 17.0896f, 0.0f);
    glVertex3f(5.3333f, 17.0896f, 0.0f);
    glVertex3f(5.4f, 17.0896f, 0.0f);
    glVertex3f(5.5333f, 17.0896f, 0.0f);
    glVertex3f(5.5333f, 17.0149f, 0.0f);
    glVertex3f(5.6f, 17.0149f, 0.0f);
    glVertex3f(5.6667f, 16.9403f, 0.0f);
    glVertex3f(5.6f, 16.8657f, 0.0f);
    glVertex3f(5.5333f, 16.791f, 0.0f);
    glVertex3f(5.5333f, 16.7164f, 0.0f);
    glVertex3f(5.4667f, 16.7164f, 0.0f);
    glVertex3f(5.4667f, 16.6418f, 0.0f);
    glVertex3f(5.4f, 16.4925f, 0.0f);
    glVertex3f(5.4f, 16.4179f, 0.0f);
    glVertex3f(5.3333f, 16.3433f, 0.0f);
    glVertex3f(5.4f, 16.2687f, 0.0f);
    glVertex3f(5.4667f, 16.2687f, 0.0f);
    glVertex3f(5.5333f, 16.2687f, 0.0f);
    glVertex3f(5.5333f, 16.194f, 0.0f);
    glVertex3f(5.5333f, 16.1194f, 0.0f);
    glVertex3f(5.6f, 16.0448f, 0.0f);
    glVertex3f(5.6f, 15.9701f, 0.0f);
    glVertex3f(5.6f, 15.8955f, 0.0f);
    glVertex3f(5.6f, 15.8209f, 0.0f);
    glVertex3f(5.6f, 15.7463f, 0.0f);
    glVertex3f(5.6f, 15.6716f, 0.0f);
    glVertex3f(5.5333f, 15.6716f, 0.0f);
    glVertex3f(5.4667f, 15.6716f, 0.0f);
    glVertex3f(5.4f, 15.6716f, 0.0f);
    glVertex3f(5.4667f, 15.6716f, 0.0f);
    glVertex3f(5.5333f, 15.6716f, 0.0f);
    glVertex3f(5.6f, 15.6716f, 0.0f);
    glVertex3f(5.6667f, 15.597f, 0.0f);
    glVertex3f(5.7333f, 15.597f, 0.0f);
    glVertex3f(5.8f, 15.597f, 0.0f);
    glVertex3f(5.8667f, 15.5224f, 0.0f);
    glVertex3f(5.9333f, 15.5224f, 0.0f);
    glVertex3f(6.0f, 15.5224f, 0.0f);
    glVertex3f(6.0667f, 15.4478f, 0.0f);
    glVertex3f(6.0667f, 15.3731f, 0.0f);
    glVertex3f(6.0667f, 15.2985f, 0.0f);
    glVertex3f(6.0667f, 15.2239f, 0.0f);
    glVertex3f(6.0667f, 15.1493f, 0.0f);
    glVertex3f(6.0667f, 15.0746f, 0.0f);
    glVertex3f(6.0667f, 15.0f, 0.0f);
    glVertex3f(6.0667f, 14.9254f, 0.0f);
    glVertex3f(6.0667f, 14.8507f, 0.0f);
    glVertex3f(6.0f, 14.7015f, 0.0f);
    glVertex3f(6.0f, 14.6269f, 0.0f);
    glVertex3f(5.9333f, 14.5522f, 0.0f);
    glVertex3f(5.8667f, 14.5522f, 0.0f);
    glVertex3f(5.8f, 14.4776f, 0.0f);
    glVertex3f(5.7333f, 14.4776f, 0.0f);
    glVertex3f(5.6667f, 14.4776f, 0.0f);
    glVertex3f(5.6f, 14.4776f, 0.0f);
    glVertex3f(5.5333f, 14.4776f, 0.0f);
    glVertex3f(5.4667f, 14.4776f, 0.0f);
    glVertex3f(5.5333f, 14.4776f, 0.0f);
    glVertex3f(5.5333f, 14.403f, 0.0f);
    glVertex3f(5.5333f, 14.3284f, 0.0f);
    glVertex3f(5.5333f, 14.2537f, 0.0f);
    glVertex3f(5.5333f, 14.1791f, 0.0f);
    glVertex3f(5.4667f, 14.1045f, 0.0f);
    glVertex3f(5.4f, 14.1045f, 0.0f);
    glVertex3f(5.3333f, 14.1045f, 0.0f);
    glVertex3f(5.2667f, 14.1045f, 0.0f);
    glVertex3f(5.2f, 14.1045f, 0.0f);
    glVertex3f(5.1333f, 14.1045f, 0.0f);
    glVertex3f(5.0667f, 14.1045f, 0.0f);
    glVertex3f(5.0f, 14.1045f, 0.0f);
    glVertex3f(5.0f, 14.1791f, 0.0f);
    glVertex3f(4.9333f, 14.1791f, 0.0f);
    glVertex3f(4.8667f, 14.1791f, 0.0f);
    glVertex3f(4.8f, 14.1791f, 0.0f);
    glVertex3f(4.7333f, 14.2537f, 0.0f);
    glVertex3f(4.6667f, 14.2537f, 0.0f);
    glVertex3f(4.6f, 14.2537f, 0.0f);
    glVertex3f(4.5333f, 14.2537f, 0.0f);
    glVertex3f(4.4667f, 14.3284f, 0.0f);
    glVertex3f(4.5333f, 14.3284f, 0.0f);
    glVertex3f(4.5333f, 14.2537f, 0.0f);
    glVertex3f(4.6f, 14.2537f, 0.0f);
    glVertex3f(4.6f, 14.1791f, 0.0f);
    glVertex3f(4.6f, 14.1045f, 0.0f);
    glVertex3f(4.6667f, 14.0299f, 0.0f);
    glVertex3f(4.6667f, 13.9552f, 0.0f);
    glVertex3f(4.6f, 13.9552f, 0.0f);
    glVertex3f(4.5333f, 13.9552f, 0.0f);
    glVertex3f(4.4667f, 13.9552f, 0.0f);
    glVertex3f(4.4f, 13.9552f, 0.0f);
    glVertex3f(4.3333f, 13.9552f, 0.0f);
    glVertex3f(4.2667f, 13.9552f, 0.0f);
    glVertex3f(4.2f, 13.9552f, 0.0f);
    glVertex3f(4.1333f, 13.9552f, 0.0f);
    glVertex3f(4.0667f, 13.9552f, 0.0f);
    glVertex3f(4.0f, 13.9552f, 0.0f);
    glVertex3f(3.9333f, 13.9552f, 0.0f);
    glVertex3f(3.8667f, 14.0299f, 0.0f);
    glVertex3f(3.8f, 14.0299f, 0.0f);
    glVertex3f(3.7333f, 14.0299f, 0.0f);
    glVertex3f(3.6667f, 14.1045f, 0.0f);
    glVertex3f(3.6f, 14.2537f, 0.0f);
    glVertex3f(3.6f, 14.3284f, 0.0f);
    glVertex3f(3.5333f, 14.403f, 0.0f);
    glVertex3f(3.4667f, 14.403f, 0.0f);
    glVertex3f(3.4f, 14.403f, 0.0f);
    glVertex3f(3.3333f, 14.403f, 0.0f);
    glVertex3f(3.2667f, 14.403f, 0.0f);
    glVertex3f(3.2f, 14.403f, 0.0f);
    glVertex3f(3.1333f, 14.403f, 0.0f);
    glVertex3f(3.0667f, 14.403f, 0.0f);
    glVertex3f(3.0f, 14.403f, 0.0f);
    glVertex3f(2.9333f, 14.403f, 0.0f);
    glVertex3f(2.8667f, 14.403f, 0.0f);
    glVertex3f(2.8f, 14.403f, 0.0f);
    glVertex3f(2.7333f, 14.4776f, 0.0f);
    glVertex3f(2.6667f, 14.4776f, 0.0f);
    glVertex3f(2.6667f, 14.5522f, 0.0f);
    glVertex3f(2.6f, 14.5522f, 0.0f);
    glVertex3f(2.6f, 14.6269f, 0.0f);
    glVertex3f(2.5333f, 14.6269f, 0.0f);
    glVertex3f(2.4667f, 14.7015f, 0.0f);
    glVertex3f(2.4667f, 14.7761f, 0.0f);
    glVertex3f(2.4667f, 14.8507f, 0.0f);
    glVertex3f(2.4f, 14.8507f, 0.0f);
    glVertex3f(2.4f, 15.0f, 0.0f);
    glVertex3f(2.4f, 15.0746f, 0.0f);
    glVertex3f(2.3333f, 15.1493f, 0.0f);
    glVertex3f(2.2667f, 15.1493f, 0.0f);
    glVertex3f(2.2f, 15.1493f, 0.0f);
    glVertex3f(2.1333f, 15.1493f, 0.0f);
    glVertex3f(2.0667f, 15.2985f, 0.0f);
    glVertex3f(2.0f, 15.2985f, 0.0f);
    glVertex3f(2.0f, 15.3731f, 0.0f);
    glVertex3f(2.0f, 15.4478f, 0.0f);
    glVertex3f(2.0f, 15.5224f, 0.0f);
    glVertex3f(2.0f, 15.597f, 0.0f);
    glVertex3f(2.0f, 15.6716f, 0.0f);
    glVertex3f(2.0667f, 15.7463f, 0.0f);
    glVertex3f(2.1333f, 15.8209f, 0.0f);
    glVertex3f(2.1333f, 15.8955f, 0.0f);
    glVertex3f(2.2f, 15.8955f, 0.0f);
    glVertex3f(2.2667f, 15.8955f, 0.0f);
    glVertex3f(2.3333f, 15.8955f, 0.0f);
    glVertex3f(2.4f, 15.8955f, 0.0f);
    glVertex3f(2.4667f, 15.8955f, 0.0f);
    glVertex3f(2.5333f, 15.8955f, 0.0f);
    glVertex3f(2.6f, 15.9701f, 0.0f);
    glVertex3f(2.6667f, 15.9701f, 0.0f);
    glVertex3f(2.7333f, 15.9701f, 0.0f);
    glVertex3f(2.8f, 15.9701f, 0.0f);
    glVertex3f(2.8667f, 16.0448f, 0.0f);
    glVertex3f(2.8667f, 16.1194f, 0.0f);
    glVertex3f(2.8667f, 16.194f, 0.0f);
    glVertex3f(2.8667f, 16.2687f, 0.0f);
    glVertex3f(2.9333f, 16.3433f, 0.0f);
    glVertex3f(3.0f, 16.3433f, 0.0f);
    glVertex3f(3.0667f, 16.4179f, 0.0f);
    glVertex3f(3.1333f, 16.4179f, 0.0f);
    glVertex3f(3.2f, 16.4925f, 0.0f);


    glEnd();


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE    3¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.227, 0.31, 0.141);
    glVertex3f(6.5333f, 15.2239f, 0.0f);


    glVertex3f(5.2f, 15.6716f, 0.0f);
    glVertex3f(5.2f, 15.7463f, 0.0f);
    glVertex3f(5.2f, 15.8209f, 0.0f);
    glVertex3f(5.2f, 15.8955f, 0.0f);
    glVertex3f(5.2667f, 15.9701f, 0.0f);
    glVertex3f(5.2667f, 16.1194f, 0.0f);
    glVertex3f(5.3333f, 16.194f, 0.0f);
    glVertex3f(5.4f, 16.194f, 0.0f);
    glVertex3f(5.4667f, 16.194f, 0.0f);
    glVertex3f(5.5333f, 16.194f, 0.0f);
    glVertex3f(5.5333f, 16.2687f, 0.0f);
    glVertex3f(5.6f, 16.2687f, 0.0f);
    glVertex3f(5.6667f, 16.2687f, 0.0f);
    glVertex3f(5.7333f, 16.2687f, 0.0f);
    glVertex3f(5.8f, 16.2687f, 0.0f);
    glVertex3f(5.7333f, 16.3433f, 0.0f);
    glVertex3f(5.6667f, 16.4179f, 0.0f);
    glVertex3f(5.6f, 16.4179f, 0.0f);
    glVertex3f(5.6f, 16.4925f, 0.0f);
    glVertex3f(5.6f, 16.5672f, 0.0f);
    glVertex3f(5.6f, 16.6418f, 0.0f);
    glVertex3f(5.6f, 16.7164f, 0.0f);
    glVertex3f(5.6f, 16.791f, 0.0f);
    glVertex3f(5.6f, 16.8657f, 0.0f);
    glVertex3f(5.6f, 16.9403f, 0.0f);
    glVertex3f(5.6f, 17.0149f, 0.0f);
    glVertex3f(5.6f, 17.0896f, 0.0f);
    glVertex3f(5.6667f, 17.0896f, 0.0f);
    glVertex3f(5.7333f, 17.1642f, 0.0f);
    glVertex3f(5.8f, 17.1642f, 0.0f);
    glVertex3f(5.8667f, 17.1642f, 0.0f);
    glVertex3f(5.9333f, 17.1642f, 0.0f);
    glVertex3f(6.0f, 17.1642f, 0.0f);
    glVertex3f(6.0667f, 17.1642f, 0.0f);
    glVertex3f(6.1333f, 17.1642f, 0.0f);
    glVertex3f(6.2f, 17.1642f, 0.0f);
    glVertex3f(6.2667f, 17.1642f, 0.0f);
    glVertex3f(6.3333f, 17.1642f, 0.0f);
    glVertex3f(6.4f, 17.1642f, 0.0f);
    glVertex3f(6.4667f, 17.1642f, 0.0f);
    glVertex3f(6.5333f, 17.1642f, 0.0f);
    glVertex3f(6.6f, 17.1642f, 0.0f);
    glVertex3f(6.6667f, 17.0896f, 0.0f);
    glVertex3f(6.6667f, 17.0149f, 0.0f);
    glVertex3f(6.7333f, 16.9403f, 0.0f);
    glVertex3f(6.7333f, 16.8657f, 0.0f);
    glVertex3f(6.7333f, 16.791f, 0.0f);
    glVertex3f(6.7333f, 16.7164f, 0.0f);
    glVertex3f(6.7333f, 16.6418f, 0.0f);
    glVertex3f(6.7333f, 16.5672f, 0.0f);
    glVertex3f(6.7333f, 16.4925f, 0.0f);
    glVertex3f(6.8f, 16.5672f, 0.0f);
    glVertex3f(6.8667f, 16.5672f, 0.0f);
    glVertex3f(6.9333f, 16.5672f, 0.0f);
    glVertex3f(7.0f, 16.5672f, 0.0f);
    glVertex3f(7.0667f, 16.5672f, 0.0f);
    glVertex3f(7.1333f, 16.5672f, 0.0f);
    glVertex3f(7.2f, 16.5672f, 0.0f);
    glVertex3f(7.2667f, 16.5672f, 0.0f);
    glVertex3f(7.3333f, 16.5672f, 0.0f);
    glVertex3f(7.4f, 16.5672f, 0.0f);
    glVertex3f(7.4667f, 16.5672f, 0.0f);
    glVertex3f(7.5333f, 16.5672f, 0.0f);
    glVertex3f(7.6f, 16.4925f, 0.0f);
    glVertex3f(7.6f, 16.4179f, 0.0f);
    glVertex3f(7.6f, 16.3433f, 0.0f);
    glVertex3f(7.6f, 16.2687f, 0.0f);
    glVertex3f(7.6f, 16.194f, 0.0f);
    glVertex3f(7.6f, 16.1194f, 0.0f);
    glVertex3f(7.6f, 16.0448f, 0.0f);
    glVertex3f(7.6f, 15.9701f, 0.0f);
    glVertex3f(7.6f, 15.8955f, 0.0f);
    glVertex3f(7.6f, 15.8209f, 0.0f);
    glVertex3f(7.4667f, 15.7463f, 0.0f);
    glVertex3f(7.5333f, 15.7463f, 0.0f);
    glVertex3f(7.6f, 15.7463f, 0.0f);
    glVertex3f(7.6667f, 15.7463f, 0.0f);
    glVertex3f(7.7333f, 15.6716f, 0.0f);
    glVertex3f(7.8f, 15.597f, 0.0f);
    glVertex3f(7.8667f, 15.597f, 0.0f);
    glVertex3f(7.9333f, 15.597f, 0.0f);
    glVertex3f(7.9333f, 15.5224f, 0.0f);
    glVertex3f(7.9333f, 15.4478f, 0.0f);
    glVertex3f(7.9333f, 15.3731f, 0.0f);
    glVertex3f(7.9333f, 15.2985f, 0.0f);
    glVertex3f(7.9333f, 15.2239f, 0.0f);
    glVertex3f(7.9333f, 15.1493f, 0.0f);
    glVertex3f(7.9333f, 15.0746f, 0.0f);
    glVertex3f(7.8667f, 15.0f, 0.0f);
    glVertex3f(7.8f, 14.9254f, 0.0f);
    glVertex3f(7.8f, 14.8507f, 0.0f);
    glVertex3f(7.7333f, 14.8507f, 0.0f);
    glVertex3f(7.6667f, 14.8507f, 0.0f);
    glVertex3f(7.6f, 14.8507f, 0.0f);
    glVertex3f(7.5333f, 14.8507f, 0.0f);
    glVertex3f(7.4667f, 14.8507f, 0.0f);
    glVertex3f(7.5333f, 14.8507f, 0.0f);
    glVertex3f(7.6f, 14.7761f, 0.0f);
    glVertex3f(7.6f, 14.7015f, 0.0f);
    glVertex3f(7.6667f, 14.6269f, 0.0f);
    glVertex3f(7.7333f, 14.5522f, 0.0f);
    glVertex3f(7.7333f, 14.4776f, 0.0f);
    glVertex3f(7.7333f, 14.403f, 0.0f);
    glVertex3f(7.7333f, 14.3284f, 0.0f);
    glVertex3f(7.7333f, 14.2537f, 0.0f);
    glVertex3f(7.7333f, 14.1791f, 0.0f);
    glVertex3f(7.7333f, 14.1045f, 0.0f);
    glVertex3f(7.6667f, 14.1045f, 0.0f);
    glVertex3f(7.6f, 14.1045f, 0.0f);
    glVertex3f(7.5333f, 14.1045f, 0.0f);
    glVertex3f(7.4667f, 14.1045f, 0.0f);
    glVertex3f(7.4f, 14.1045f, 0.0f);
    glVertex3f(7.3333f, 14.1045f, 0.0f);
    glVertex3f(7.2667f, 14.1045f, 0.0f);
    glVertex3f(7.2f, 14.1045f, 0.0f);
    glVertex3f(7.1333f, 14.1045f, 0.0f);
    glVertex3f(7.0667f, 14.1045f, 0.0f);
    glVertex3f(7.0f, 14.1045f, 0.0f);
    glVertex3f(6.9333f, 14.1045f, 0.0f);
    glVertex3f(6.8667f, 14.1045f, 0.0f);
    glVertex3f(6.8f, 14.1045f, 0.0f);
    glVertex3f(6.7333f, 14.1791f, 0.0f);
    glVertex3f(6.7333f, 14.2537f, 0.0f);
    glVertex3f(6.6667f, 14.403f, 0.0f);
    glVertex3f(6.6f, 14.3284f, 0.0f);
    glVertex3f(6.6f, 14.2537f, 0.0f);
    glVertex3f(6.5333f, 14.2537f, 0.0f);
    glVertex3f(6.5333f, 14.1791f, 0.0f);
    glVertex3f(6.4667f, 14.1045f, 0.0f);
    glVertex3f(6.4f, 14.0299f, 0.0f);
    glVertex3f(6.3333f, 14.0299f, 0.0f);
    glVertex3f(6.2667f, 14.0299f, 0.0f);
    glVertex3f(6.2f, 14.0299f, 0.0f);
    glVertex3f(6.1333f, 14.0299f, 0.0f);
    glVertex3f(6.0667f, 14.0299f, 0.0f);
    glVertex3f(6.0f, 14.0299f, 0.0f);
    glVertex3f(5.9333f, 14.0299f, 0.0f);
    glVertex3f(5.8667f, 14.1045f, 0.0f);
    glVertex3f(5.8f, 14.1045f, 0.0f);
    glVertex3f(5.7333f, 14.1045f, 0.0f);
    glVertex3f(5.6667f, 14.1045f, 0.0f);
    glVertex3f(5.6667f, 14.1791f, 0.0f);
    glVertex3f(5.6f, 14.1791f, 0.0f);
    glVertex3f(5.5333f, 14.1791f, 0.0f);
    glVertex3f(5.4f, 14.2537f, 0.0f);
    glVertex3f(5.4f, 14.3284f, 0.0f);
    glVertex3f(5.4f, 14.403f, 0.0f);
    glVertex3f(5.4f, 14.4776f, 0.0f);
    glVertex3f(5.4f, 14.5522f, 0.0f);
    glVertex3f(5.5333f, 14.5522f, 0.0f);
    glVertex3f(5.6f, 14.5522f, 0.0f);
    glVertex3f(5.6667f, 14.5522f, 0.0f);
    glVertex3f(5.7333f, 14.6269f, 0.0f);
    glVertex3f(5.6667f, 14.6269f, 0.0f);
    glVertex3f(5.6f, 14.6269f, 0.0f);
    glVertex3f(5.5333f, 14.6269f, 0.0f);
    glVertex3f(5.4667f, 14.6269f, 0.0f);
    glVertex3f(5.4f, 14.6269f, 0.0f);
    glVertex3f(5.3333f, 14.6269f, 0.0f);
    glVertex3f(5.2667f, 14.7015f, 0.0f);
    glVertex3f(5.2f, 14.7015f, 0.0f);
    glVertex3f(5.0667f, 14.7015f, 0.0f);
    glVertex3f(5.0667f, 14.7761f, 0.0f);
    glVertex3f(5.0f, 14.7761f, 0.0f);
    glVertex3f(4.9333f, 14.7761f, 0.0f);
    glVertex3f(4.8667f, 14.8507f, 0.0f);
    glVertex3f(4.8667f, 14.9254f, 0.0f);
    glVertex3f(4.8667f, 15.0f, 0.0f);
    glVertex3f(4.8667f, 15.0746f, 0.0f);
    glVertex3f(4.8667f, 15.1493f, 0.0f);
    glVertex3f(4.8667f, 15.2239f, 0.0f);
    glVertex3f(4.8667f, 15.2985f, 0.0f);
    glVertex3f(4.8667f, 15.3731f, 0.0f);
    glVertex3f(4.9333f, 15.5224f, 0.0f);
    glVertex3f(4.9333f, 15.597f, 0.0f);
    glVertex3f(5.0f, 15.6716f, 0.0f);
    glVertex3f(5.0f, 15.7463f, 0.0f);
    glVertex3f(5.0667f, 15.7463f, 0.0f);
    glVertex3f(5.1333f, 15.7463f, 0.0f);
    glVertex3f(5.2f, 15.7463f, 0.0f);
    glVertex3f(5.2667f, 15.8209f, 0.0f);
    glVertex3f(5.3333f, 15.8209f, 0.0f);
    glVertex3f(5.4f, 15.8209f, 0.0f);
    glVertex3f(5.4667f, 15.8209f, 0.0f);
    glVertex3f(5.5333f, 15.8209f, 0.0f);



    glEnd();

//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE    3¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.227, 0.306, 0.161);
    glVertex3f(8.6667f, 15.2985f, 0.0f);


    glVertex3f(7.8667f, 15.1493f, 0.0f);
    glVertex3f(8.0f, 15.1493f, 0.0f);
    glVertex3f(8.0f, 15.2239f, 0.0f);
    glVertex3f(8.0667f, 15.2985f, 0.0f);
    glVertex3f(8.1333f, 15.2985f, 0.0f);
    glVertex3f(8.1333f, 15.3731f, 0.0f);
    glVertex3f(8.2f, 15.3731f, 0.0f);
    glVertex3f(8.2667f, 15.4478f, 0.0f);
    glVertex3f(8.2667f, 15.5224f, 0.0f);
    glVertex3f(8.2f, 15.5224f, 0.0f);
    glVertex3f(8.1333f, 15.597f, 0.0f);
    glVertex3f(8.1333f, 15.6716f, 0.0f);
    glVertex3f(8.0667f, 15.6716f, 0.0f);
    glVertex3f(8.0667f, 15.7463f, 0.0f);
    glVertex3f(8.0f, 15.7463f, 0.0f);
    glVertex3f(8.0f, 15.8209f, 0.0f);
    glVertex3f(7.9333f, 15.8209f, 0.0f);
    glVertex3f(7.8667f, 15.8955f, 0.0f);
    glVertex3f(7.8667f, 15.9701f, 0.0f);
    glVertex3f(7.8667f, 16.0448f, 0.0f);
    glVertex3f(7.8667f, 16.1194f, 0.0f);
    glVertex3f(7.8667f, 16.194f, 0.0f);
    glVertex3f(7.8667f, 16.2687f, 0.0f);
    glVertex3f(7.8667f, 16.3433f, 0.0f);
    glVertex3f(7.8667f, 16.4179f, 0.0f);
    glVertex3f(7.8667f, 16.4925f, 0.0f);
    glVertex3f(8.0f, 16.4925f, 0.0f);
    glVertex3f(8.0f, 16.5672f, 0.0f);
    glVertex3f(8.0667f, 16.5672f, 0.0f);
    glVertex3f(8.0667f, 16.6418f, 0.0f);
    glVertex3f(8.1333f, 16.6418f, 0.0f);
    glVertex3f(8.1333f, 16.7164f, 0.0f);
    glVertex3f(8.1333f, 16.791f, 0.0f);
    glVertex3f(8.1333f, 16.8657f, 0.0f);
    glVertex3f(8.1333f, 16.9403f, 0.0f);
    glVertex3f(8.1333f, 17.0149f, 0.0f);
    glVertex3f(8.1333f, 17.0896f, 0.0f);
    glVertex3f(8.1333f, 17.1642f, 0.0f);
    glVertex3f(8.2f, 17.3134f, 0.0f);
    glVertex3f(8.2667f, 17.3134f, 0.0f);
    glVertex3f(8.3333f, 17.3881f, 0.0f);
    glVertex3f(8.4f, 17.3881f, 0.0f);
    glVertex3f(8.4f, 17.4627f, 0.0f);
    glVertex3f(8.4f, 17.5373f, 0.0f);
    glVertex3f(8.4f, 17.6119f, 0.0f);
    glVertex3f(8.4667f, 17.6119f, 0.0f);
    glVertex3f(8.4667f, 17.5373f, 0.0f);
    glVertex3f(8.4667f, 17.4627f, 0.0f);
    glVertex3f(8.4667f, 17.3881f, 0.0f);
    glVertex3f(8.4667f, 17.3134f, 0.0f);
    glVertex3f(8.4f, 17.2388f, 0.0f);
    glVertex3f(8.4f, 17.1642f, 0.0f);
    glVertex3f(8.4f, 17.0896f, 0.0f);
    glVertex3f(8.4f, 17.0149f, 0.0f);
    glVertex3f(8.4f, 16.9403f, 0.0f);
    glVertex3f(8.4f, 16.8657f, 0.0f);
    glVertex3f(8.4667f, 16.8657f, 0.0f);
    glVertex3f(8.4667f, 16.791f, 0.0f);
    glVertex3f(8.5333f, 16.791f, 0.0f);
    glVertex3f(8.6f, 16.791f, 0.0f);
    glVertex3f(8.6667f, 16.791f, 0.0f);
    glVertex3f(8.7333f, 16.791f, 0.0f);
    glVertex3f(8.8f, 16.791f, 0.0f);
    glVertex3f(8.8667f, 16.7164f, 0.0f);
    glVertex3f(8.8667f, 16.6418f, 0.0f);
    glVertex3f(8.8667f, 16.5672f, 0.0f);
    glVertex3f(8.8667f, 16.4925f, 0.0f);
    glVertex3f(8.8667f, 16.4179f, 0.0f);
    glVertex3f(8.8667f, 16.3433f, 0.0f);
    glVertex3f(8.8667f, 16.2687f, 0.0f);
    glVertex3f(8.9333f, 16.2687f, 0.0f);
    glVertex3f(8.9333f, 16.194f, 0.0f);
    glVertex3f(9.0f, 16.1194f, 0.0f);
    glVertex3f(9.0f, 16.0448f, 0.0f);
    glVertex3f(9.0f, 15.9701f, 0.0f);
    glVertex3f(8.9333f, 15.9701f, 0.0f);
    glVertex3f(8.8667f, 15.8955f, 0.0f);
    glVertex3f(8.8667f, 15.8209f, 0.0f);
    glVertex3f(8.8667f, 15.7463f, 0.0f);
    glVertex3f(8.8667f, 15.6716f, 0.0f);
    glVertex3f(8.9333f, 15.6716f, 0.0f);
    glVertex3f(8.9333f, 15.5224f, 0.0f);
    glVertex3f(9.0f, 15.5224f, 0.0f);
    glVertex3f(9.0667f, 15.5224f, 0.0f);
    glVertex3f(9.1333f, 15.5224f, 0.0f);
    glVertex3f(9.2f, 15.5224f, 0.0f);
    glVertex3f(9.2f, 15.4478f, 0.0f);
    glVertex3f(9.2667f, 15.4478f, 0.0f);
    glVertex3f(9.3333f, 15.4478f, 0.0f);
    glVertex3f(9.3333f, 15.3731f, 0.0f);
    glVertex3f(9.3333f, 15.2985f, 0.0f);
    glVertex3f(9.2667f, 15.2239f, 0.0f);
    glVertex3f(9.2667f, 15.1493f, 0.0f);
    glVertex3f(9.2667f, 15.0746f, 0.0f);
    glVertex3f(9.2f, 15.0746f, 0.0f);
    glVertex3f(9.1333f, 15.0746f, 0.0f);
    glVertex3f(9.0f, 15.0f, 0.0f);
    glVertex3f(9.0667f, 14.9254f, 0.0f);
    glVertex3f(9.1333f, 14.8507f, 0.0f);
    glVertex3f(9.1333f, 14.7761f, 0.0f);
    glVertex3f(9.1333f, 14.7015f, 0.0f);
    glVertex3f(9.2f, 14.7015f, 0.0f);
    glVertex3f(9.2f, 14.6269f, 0.0f);
    glVertex3f(9.2f, 14.5522f, 0.0f);
    glVertex3f(9.1333f, 14.5522f, 0.0f);
    glVertex3f(9.0667f, 14.5522f, 0.0f);
    glVertex3f(9.0f, 14.4776f, 0.0f);
    glVertex3f(8.9333f, 14.4776f, 0.0f);
    glVertex3f(8.8667f, 14.4776f, 0.0f);
    glVertex3f(8.8f, 14.4776f, 0.0f);
    glVertex3f(8.7333f, 14.4776f, 0.0f);
    glVertex3f(8.6667f, 14.4776f, 0.0f);
    glVertex3f(8.6f, 14.4776f, 0.0f);
    glVertex3f(8.5333f, 14.4776f, 0.0f);
    glVertex3f(8.4667f, 14.4776f, 0.0f);
    glVertex3f(8.4f, 14.4776f, 0.0f);
    glVertex3f(8.3333f, 14.4776f, 0.0f);
    glVertex3f(8.2667f, 14.4776f, 0.0f);
    glVertex3f(8.2f, 14.4776f, 0.0f);
    glVertex3f(8.1333f, 14.4776f, 0.0f);
    glVertex3f(8.0667f, 14.4776f, 0.0f);
    glVertex3f(8.0f, 14.4776f, 0.0f);
    glVertex3f(7.9333f, 14.4776f, 0.0f);
    glVertex3f(7.8667f, 14.4776f, 0.0f);
    glVertex3f(7.8f, 14.4776f, 0.0f);
    glVertex3f(7.7333f, 14.4776f, 0.0f);
    glVertex3f(7.6667f, 14.4776f, 0.0f);
    glVertex3f(7.6f, 14.4776f, 0.0f);
    glVertex3f(7.5333f, 14.4776f, 0.0f);
    glVertex3f(7.4f, 14.5522f, 0.0f);
    glVertex3f(7.3333f, 14.5522f, 0.0f);
    glVertex3f(7.3333f, 14.6269f, 0.0f);
    glVertex3f(7.2667f, 14.6269f, 0.0f);
    glVertex3f(7.2f, 14.7015f, 0.0f);
    glVertex3f(7.1333f, 14.7761f, 0.0f);
    glVertex3f(7.1333f, 14.8507f, 0.0f);
    glVertex3f(7.0f, 14.9254f, 0.0f);
    glVertex3f(6.9333f, 14.9254f, 0.0f);
    glVertex3f(6.9333f, 15.0f, 0.0f);
    glVertex3f(6.8667f, 15.0746f, 0.0f);
    glVertex3f(6.9333f, 15.0746f, 0.0f);
    glVertex3f(7.0f, 15.1493f, 0.0f);
    glVertex3f(7.0667f, 15.1493f, 0.0f);
    glVertex3f(7.1333f, 15.1493f, 0.0f);
    glVertex3f(7.2f, 15.1493f, 0.0f);
    glVertex3f(7.2667f, 15.1493f, 0.0f);
    glVertex3f(7.3333f, 15.1493f, 0.0f);
    glVertex3f(7.4f, 15.1493f, 0.0f);
    glVertex3f(7.4667f, 15.1493f, 0.0f);
    glVertex3f(7.5333f, 15.1493f, 0.0f);
    glVertex3f(7.6f, 15.1493f, 0.0f);
    glVertex3f(7.6667f, 15.1493f, 0.0f);
    glVertex3f(7.7333f, 15.1493f, 0.0f);
    glVertex3f(7.8f, 15.1493f, 0.0f);
    glVertex3f(7.8667f, 15.1493f, 0.0f);
    glVertex3f(7.9333f, 15.1493f, 0.0f);
    glVertex3f(7.9333f, 15.2239f, 0.0f);
    glVertex3f(7.9333f, 15.2985f, 0.0f);
    glVertex3f(7.9333f, 15.3731f, 0.0f);
    glVertex3f(7.9333f, 15.4478f, 0.0f);
    glVertex3f(7.9333f, 15.5224f, 0.0f);
    glVertex3f(7.8667f, 15.597f, 0.0f);
    glVertex3f(7.8667f, 15.6716f, 0.0f);
    glVertex3f(7.8667f, 15.7463f, 0.0f);
    glVertex3f(7.8667f, 15.8209f, 0.0f);
    glVertex3f(7.9333f, 15.8209f, 0.0f);
    glVertex3f(8.0f, 15.8209f, 0.0f);
    glVertex3f(8.0667f, 15.8209f, 0.0f);
    glVertex3f(8.1333f, 15.8209f, 0.0f);


    glEnd();


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE    4¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.231, 0.314, 0.145);
    glVertex3f(10.2f, 15.597f, 0.0f);


    glVertex3f(9.0667f, 15.2985f, 0.0f);
    glVertex3f(9.0667f, 15.3731f, 0.0f);
    glVertex3f(9.1333f, 15.3731f, 0.0f);
    glVertex3f(9.1333f, 15.4478f, 0.0f);
    glVertex3f(9.1333f, 15.5224f, 0.0f);
    glVertex3f(9.1333f, 15.597f, 0.0f);
    glVertex3f(9.1333f, 15.6716f, 0.0f);
    glVertex3f(9.2f, 15.7463f, 0.0f);
    glVertex3f(9.2f, 15.8209f, 0.0f);
    glVertex3f(9.2667f, 15.9701f, 0.0f);
    glVertex3f(9.3333f, 16.1194f, 0.0f);
    glVertex3f(9.4f, 16.194f, 0.0f);
    glVertex3f(9.4f, 16.2687f, 0.0f);
    glVertex3f(9.4667f, 16.3433f, 0.0f);
    glVertex3f(9.5333f, 16.3433f, 0.0f);
    glVertex3f(9.6f, 16.3433f, 0.0f);
    glVertex3f(9.6667f, 16.3433f, 0.0f);
    glVertex3f(9.7333f, 16.4179f, 0.0f);
    glVertex3f(9.6667f, 16.4925f, 0.0f);
    glVertex3f(9.6f, 16.6418f, 0.0f);
    glVertex3f(9.5333f, 16.7164f, 0.0f);
    glVertex3f(9.5333f, 16.791f, 0.0f);
    glVertex3f(9.4667f, 16.9403f, 0.0f);
    glVertex3f(9.4667f, 17.0149f, 0.0f);
    glVertex3f(9.4667f, 17.0896f, 0.0f);
    glVertex3f(9.4667f, 17.1642f, 0.0f);
    glVertex3f(9.4667f, 17.2388f, 0.0f);
    glVertex3f(9.4667f, 17.4627f, 0.0f);
    glVertex3f(9.5333f, 17.5373f, 0.0f);
    glVertex3f(9.6f, 17.5373f, 0.0f);
    glVertex3f(9.6667f, 17.6119f, 0.0f);
    glVertex3f(9.7333f, 17.6119f, 0.0f);
    glVertex3f(9.8f, 17.6119f, 0.0f);
    glVertex3f(9.8667f, 17.6119f, 0.0f);
    glVertex3f(9.9333f, 17.6119f, 0.0f);
    glVertex3f(10.0f, 17.6119f, 0.0f);
    glVertex3f(10.0667f, 17.6119f, 0.0f);
    glVertex3f(10.1333f, 17.6866f, 0.0f);
    glVertex3f(10.2f, 17.6866f, 0.0f);
    glVertex3f(10.2667f, 17.6866f, 0.0f);
    glVertex3f(10.2667f, 17.6119f, 0.0f);
    glVertex3f(10.3333f, 17.6119f, 0.0f);
    glVertex3f(10.4f, 17.5373f, 0.0f);
    glVertex3f(10.4f, 17.4627f, 0.0f);
    glVertex3f(10.4f, 17.3881f, 0.0f);
    glVertex3f(10.4f, 17.3134f, 0.0f);
    glVertex3f(10.4667f, 17.3134f, 0.0f);
    glVertex3f(10.5333f, 17.3134f, 0.0f);
    glVertex3f(10.6f, 17.3134f, 0.0f);
    glVertex3f(10.6667f, 17.3134f, 0.0f);
    glVertex3f(10.7333f, 17.3134f, 0.0f);
    glVertex3f(10.8f, 17.3134f, 0.0f);
    glVertex3f(10.8667f, 17.2388f, 0.0f);
    glVertex3f(10.9333f, 17.2388f, 0.0f);
    glVertex3f(10.9333f, 17.1642f, 0.0f);
    glVertex3f(10.9333f, 17.0896f, 0.0f);
    glVertex3f(10.9333f, 17.0149f, 0.0f);
    glVertex3f(10.9333f, 16.9403f, 0.0f);
    glVertex3f(11.0f, 16.9403f, 0.0f);
    glVertex3f(11.0f, 16.8657f, 0.0f);
    glVertex3f(11.0f, 16.791f, 0.0f);
    glVertex3f(11.0f, 16.7164f, 0.0f);
    glVertex3f(10.9333f, 16.6418f, 0.0f);
    glVertex3f(10.8667f, 16.6418f, 0.0f);
    glVertex3f(10.8f, 16.5672f, 0.0f);
    glVertex3f(10.7333f, 16.5672f, 0.0f);
    glVertex3f(10.6667f, 16.4925f, 0.0f);
    glVertex3f(10.6f, 16.4925f, 0.0f);
    glVertex3f(10.5333f, 16.4925f, 0.0f);
    glVertex3f(10.6f, 16.4925f, 0.0f);
    glVertex3f(10.7333f, 16.4179f, 0.0f);
    glVertex3f(10.8f, 16.3433f, 0.0f);
    glVertex3f(10.8667f, 16.3433f, 0.0f);
    glVertex3f(10.9333f, 16.3433f, 0.0f);
    glVertex3f(11.0f, 16.2687f, 0.0f);
    glVertex3f(11.0667f, 16.194f, 0.0f);
    glVertex3f(11.0667f, 16.1194f, 0.0f);
    glVertex3f(11.0667f, 16.0448f, 0.0f);
    glVertex3f(11.1333f, 15.9701f, 0.0f);
    glVertex3f(11.1333f, 15.8955f, 0.0f);
    glVertex3f(11.1333f, 15.8209f, 0.0f);
    glVertex3f(11.1333f, 15.7463f, 0.0f);
    glVertex3f(11.1333f, 15.6716f, 0.0f);
    glVertex3f(11.1333f, 15.597f, 0.0f);
    glVertex3f(11.1333f, 15.5224f, 0.0f);
    glVertex3f(11.1333f, 15.4478f, 0.0f);
    glVertex3f(11.0667f, 15.3731f, 0.0f);
    glVertex3f(11.0f, 15.2985f, 0.0f);
    glVertex3f(10.9333f, 15.2985f, 0.0f);
    glVertex3f(10.8667f, 15.2985f, 0.0f);
    glVertex3f(10.8f, 15.2985f, 0.0f);
    glVertex3f(10.8667f, 15.2985f, 0.0f);
    glVertex3f(10.9333f, 15.2985f, 0.0f);
    glVertex3f(10.9333f, 15.2239f, 0.0f);
    glVertex3f(11.0f, 15.2239f, 0.0f);
    glVertex3f(11.0667f, 15.2239f, 0.0f);
    glVertex3f(11.0667f, 15.0746f, 0.0f);
    glVertex3f(11.0667f, 15.0f, 0.0f);
    glVertex3f(11.1333f, 15.0f, 0.0f);
    glVertex3f(11.1333f, 14.9254f, 0.0f);
    glVertex3f(11.1333f, 14.8507f, 0.0f);
    glVertex3f(11.1333f, 14.7761f, 0.0f);
    glVertex3f(11.1333f, 14.7015f, 0.0f);
    glVertex3f(11.1333f, 14.6269f, 0.0f);
    glVertex3f(11.0667f, 14.5522f, 0.0f);
    glVertex3f(11.0f, 14.5522f, 0.0f);
    glVertex3f(10.9333f, 14.5522f, 0.0f);
    glVertex3f(10.8667f, 14.5522f, 0.0f);
    glVertex3f(10.8f, 14.5522f, 0.0f);
    glVertex3f(10.8f, 14.4776f, 0.0f);
    glVertex3f(10.7333f, 14.4776f, 0.0f);
    glVertex3f(10.6667f, 14.4776f, 0.0f);
    glVertex3f(10.6f, 14.4776f, 0.0f);
    glVertex3f(10.5333f, 14.403f, 0.0f);
    glVertex3f(10.4667f, 14.3284f, 0.0f);
    glVertex3f(10.4f, 14.2537f, 0.0f);
    glVertex3f(10.3333f, 14.1045f, 0.0f);
    glVertex3f(10.2667f, 14.1045f, 0.0f);
    glVertex3f(10.2f, 14.1045f, 0.0f);
    glVertex3f(10.1333f, 14.1045f, 0.0f);
    glVertex3f(10.0667f, 14.1045f, 0.0f);
    glVertex3f(9.9333f, 14.1045f, 0.0f);
    glVertex3f(9.8667f, 14.1045f, 0.0f);
    glVertex3f(9.8f, 14.1045f, 0.0f);
    glVertex3f(9.7333f, 14.1045f, 0.0f);
    glVertex3f(9.6667f, 14.1045f, 0.0f);
    glVertex3f(9.6f, 14.1045f, 0.0f);
    glVertex3f(9.4667f, 14.1045f, 0.0f);
    glVertex3f(9.4667f, 14.1791f, 0.0f);
    glVertex3f(9.4f, 14.1791f, 0.0f);
    glVertex3f(9.3333f, 14.1791f, 0.0f);
    glVertex3f(9.2667f, 14.1791f, 0.0f);
    glVertex3f(9.2667f, 14.2537f, 0.0f);
    glVertex3f(9.2f, 14.2537f, 0.0f);
    glVertex3f(9.1333f, 14.2537f, 0.0f);
    glVertex3f(9.0667f, 14.2537f, 0.0f);
    glVertex3f(9.0f, 14.3284f, 0.0f);
    glVertex3f(8.9333f, 14.3284f, 0.0f);
    glVertex3f(8.8667f, 14.403f, 0.0f);
    glVertex3f(8.8f, 14.403f, 0.0f);
    glVertex3f(8.8f, 14.4776f, 0.0f);
    glVertex3f(8.7333f, 14.6269f, 0.0f);
    glVertex3f(8.6667f, 14.7015f, 0.0f);
    glVertex3f(8.6f, 14.7015f, 0.0f);
    glVertex3f(8.6f, 14.7761f, 0.0f);
    glVertex3f(8.6f, 14.8507f, 0.0f);
    glVertex3f(8.6f, 14.9254f, 0.0f);
    glVertex3f(8.5333f, 14.9254f, 0.0f);
    glVertex3f(8.5333f, 15.0f, 0.0f);
    glVertex3f(8.5333f, 15.0746f, 0.0f);
    glVertex3f(8.5333f, 15.1493f, 0.0f);
    glVertex3f(8.5333f, 15.2239f, 0.0f);
    glVertex3f(8.6f, 15.2985f, 0.0f);
    glVertex3f(8.6667f, 15.3731f, 0.0f);
    glVertex3f(8.7333f, 15.3731f, 0.0f);
    glVertex3f(8.8667f, 15.4478f, 0.0f);
    glVertex3f(8.9333f, 15.5224f, 0.0f);
    glVertex3f(9.0f, 15.597f, 0.0f);
    glVertex3f(9.0f, 15.6716f, 0.0f);
    glVertex3f(9.0f, 15.7463f, 0.0f);
    glVertex3f(9.1333f, 15.7463f, 0.0f);
    glVertex3f(9.1333f, 15.8955f, 0.0f);
    glVertex3f(9.2f, 15.9701f, 0.0f);


    glEnd();


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE    5¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.235, 0.31, 0.133);
    glVertex3f(11.4f, 15.4478f, 0.0f);


    glVertex3f(11.0f, 15.9701f, 0.0f);
    glVertex3f(11.0667f, 16.1194f, 0.0f);
    glVertex3f(11.0667f, 16.194f, 0.0f);
    glVertex3f(11.1333f, 16.2687f, 0.0f);
    glVertex3f(11.1333f, 16.3433f, 0.0f);
    glVertex3f(11.2f, 16.4925f, 0.0f);
    glVertex3f(11.2667f, 16.4925f, 0.0f);
    glVertex3f(11.2667f, 16.5672f, 0.0f);
    glVertex3f(11.2667f, 16.6418f, 0.0f);
    glVertex3f(11.3333f, 16.7164f, 0.0f);
    glVertex3f(11.2667f, 16.8657f, 0.0f);
    glVertex3f(11.2f, 17.0149f, 0.0f);
    glVertex3f(11.2f, 17.0896f, 0.0f);
    glVertex3f(11.1333f, 17.2388f, 0.0f);
    glVertex3f(11.0667f, 17.2388f, 0.0f);
    glVertex3f(11.0667f, 17.3134f, 0.0f);
    glVertex3f(11.0667f, 17.3881f, 0.0f);
    glVertex3f(11.0667f, 17.4627f, 0.0f);
    glVertex3f(11.0667f, 17.5373f, 0.0f);
    glVertex3f(11.0667f, 17.6119f, 0.0f);
    glVertex3f(11.0667f, 17.6866f, 0.0f);
    glVertex3f(11.0667f, 17.7612f, 0.0f);
    glVertex3f(11.0667f, 17.8358f, 0.0f);
    glVertex3f(11.0667f, 17.9104f, 0.0f);
    glVertex3f(11.1333f, 17.9104f, 0.0f);
    glVertex3f(11.1333f, 17.9851f, 0.0f);
    glVertex3f(11.2f, 18.0597f, 0.0f);
    glVertex3f(11.2f, 18.1343f, 0.0f);
    glVertex3f(11.2f, 18.209f, 0.0f);
    glVertex3f(11.2667f, 18.209f, 0.0f);
    glVertex3f(11.2667f, 18.2836f, 0.0f);
    glVertex3f(11.2667f, 18.3582f, 0.0f);
    glVertex3f(11.3333f, 18.4328f, 0.0f);
    glVertex3f(11.3333f, 18.5075f, 0.0f);
    glVertex3f(11.3333f, 18.5821f, 0.0f);
    glVertex3f(11.3333f, 18.5075f, 0.0f);
    glVertex3f(11.3333f, 18.4328f, 0.0f);
    glVertex3f(11.3333f, 18.3582f, 0.0f);
    glVertex3f(11.3333f, 18.2836f, 0.0f);
    glVertex3f(11.4f, 18.209f, 0.0f);
    glVertex3f(11.4f, 18.1343f, 0.0f);
    glVertex3f(11.4f, 18.0597f, 0.0f);
    glVertex3f(11.4f, 17.9851f, 0.0f);
    glVertex3f(11.4667f, 17.9851f, 0.0f);
    glVertex3f(11.5333f, 17.9104f, 0.0f);
    glVertex3f(11.5333f, 17.8358f, 0.0f);
    glVertex3f(11.6f, 17.7612f, 0.0f);
    glVertex3f(11.6f, 17.6866f, 0.0f);
    glVertex3f(11.6f, 17.6119f, 0.0f);
    glVertex3f(11.6f, 17.5373f, 0.0f);
    glVertex3f(11.6667f, 17.3881f, 0.0f);
    glVertex3f(11.6667f, 17.3134f, 0.0f);
    glVertex3f(11.6667f, 17.1642f, 0.0f);
    glVertex3f(11.7333f, 17.0896f, 0.0f);
    glVertex3f(11.8f, 16.9403f, 0.0f);
    glVertex3f(11.8667f, 16.8657f, 0.0f);
    glVertex3f(11.8667f, 16.791f, 0.0f);
    glVertex3f(11.8667f, 16.7164f, 0.0f);
    glVertex3f(11.8667f, 16.6418f, 0.0f);
    glVertex3f(11.8f, 16.6418f, 0.0f);
    glVertex3f(11.8f, 16.5672f, 0.0f);
    glVertex3f(11.8f, 16.4925f, 0.0f);
    glVertex3f(11.8f, 16.4179f, 0.0f);
    glVertex3f(11.8f, 16.3433f, 0.0f);
    glVertex3f(11.8f, 16.2687f, 0.0f);
    glVertex3f(11.8f, 16.194f, 0.0f);
    glVertex3f(11.8667f, 16.1194f, 0.0f);
    glVertex3f(11.9333f, 16.0448f, 0.0f);
    glVertex3f(12.0f, 16.0448f, 0.0f);
    glVertex3f(12.0667f, 16.0448f, 0.0f);
    glVertex3f(12.1333f, 16.0448f, 0.0f);
    glVertex3f(12.2f, 16.0448f, 0.0f);
    glVertex3f(12.2f, 15.9701f, 0.0f);
    glVertex3f(12.2f, 15.8955f, 0.0f);
    glVertex3f(12.2f, 15.8209f, 0.0f);
    glVertex3f(12.1333f, 15.7463f, 0.0f);
    glVertex3f(12.1333f, 15.6716f, 0.0f);
    glVertex3f(12.0667f, 15.6716f, 0.0f);
    glVertex3f(12.0f, 15.6716f, 0.0f);
    glVertex3f(12.0f, 15.597f, 0.0f);
    glVertex3f(11.9333f, 15.597f, 0.0f);
    glVertex3f(11.8667f, 15.597f, 0.0f);
    glVertex3f(11.8667f, 15.5224f, 0.0f);
    glVertex3f(11.8667f, 15.4478f, 0.0f);
    glVertex3f(11.8667f, 15.3731f, 0.0f);
    glVertex3f(11.8667f, 15.2985f, 0.0f);
    glVertex3f(11.9333f, 15.1493f, 0.0f);
    glVertex3f(12.0f, 15.1493f, 0.0f);
    glVertex3f(12.0f, 15.0746f, 0.0f);
    glVertex3f(12.0667f, 15.0746f, 0.0f);
    glVertex3f(12.1333f, 15.0f, 0.0f);
    glVertex3f(12.2f, 15.0f, 0.0f);
    glVertex3f(12.2667f, 15.0f, 0.0f);
    glVertex3f(12.3333f, 14.9254f, 0.0f);
    glVertex3f(12.3333f, 14.8507f, 0.0f);
    glVertex3f(12.3333f, 14.7761f, 0.0f);
    glVertex3f(12.2667f, 14.7761f, 0.0f);
    glVertex3f(12.2f, 14.7761f, 0.0f);
    glVertex3f(12.2f, 14.7015f, 0.0f);
    glVertex3f(12.1333f, 14.7015f, 0.0f);
    glVertex3f(12.0667f, 14.7015f, 0.0f);
    glVertex3f(12.0f, 14.7015f, 0.0f);
    glVertex3f(11.9333f, 14.7015f, 0.0f);
    glVertex3f(11.8667f, 14.7015f, 0.0f);
    glVertex3f(11.8f, 14.7015f, 0.0f);
    glVertex3f(11.7333f, 14.7015f, 0.0f);
    glVertex3f(11.6f, 14.6269f, 0.0f);
    glVertex3f(11.6f, 14.5522f, 0.0f);
    glVertex3f(11.5333f, 14.5522f, 0.0f);
    glVertex3f(11.4667f, 14.5522f, 0.0f);
    glVertex3f(11.4f, 14.5522f, 0.0f);
    glVertex3f(11.3333f, 14.5522f, 0.0f);
    glVertex3f(11.2667f, 14.5522f, 0.0f);
    glVertex3f(11.2f, 14.5522f, 0.0f);
    glVertex3f(11.1333f, 14.5522f, 0.0f);
    glVertex3f(11.0f, 14.4776f, 0.0f);
    glVertex3f(10.9333f, 14.4776f, 0.0f);
    glVertex3f(10.8667f, 14.4776f, 0.0f);
    glVertex3f(10.8f, 14.4776f, 0.0f);
    glVertex3f(10.7333f, 14.4776f, 0.0f);
    glVertex3f(10.6667f, 14.4776f, 0.0f);
    glVertex3f(10.6f, 14.4776f, 0.0f);
    glVertex3f(10.5333f, 14.4776f, 0.0f);
    glVertex3f(10.4667f, 14.4776f, 0.0f);
    glVertex3f(10.4f, 14.4776f, 0.0f);
    glVertex3f(10.3333f, 14.4776f, 0.0f);
    glVertex3f(10.2667f, 14.4776f, 0.0f);
    glVertex3f(10.2f, 14.4776f, 0.0f);
    glVertex3f(10.1333f, 14.4776f, 0.0f);
    glVertex3f(10.0667f, 14.4776f, 0.0f);
    glVertex3f(10.0f, 14.4776f, 0.0f);
    glVertex3f(9.9333f, 14.4776f, 0.0f);
    glVertex3f(9.8667f, 14.5522f, 0.0f);
    glVertex3f(9.8f, 14.5522f, 0.0f);
    glVertex3f(9.8f, 14.6269f, 0.0f);
    glVertex3f(9.7333f, 14.6269f, 0.0f);
    glVertex3f(9.6667f, 14.7015f, 0.0f);
    glVertex3f(9.6f, 14.7761f, 0.0f);
    glVertex3f(9.6f, 14.8507f, 0.0f);
    glVertex3f(9.5333f, 14.9254f, 0.0f);
    glVertex3f(9.6f, 14.9254f, 0.0f);
    glVertex3f(9.6f, 15.0f, 0.0f);
    glVertex3f(9.6667f, 15.0f, 0.0f);
    glVertex3f(9.7333f, 15.0f, 0.0f);
    glVertex3f(9.8f, 15.0746f, 0.0f);
    glVertex3f(9.8667f, 15.0746f, 0.0f);
    glVertex3f(9.9333f, 15.0746f, 0.0f);
    glVertex3f(9.9333f, 15.1493f, 0.0f);
    glVertex3f(10.0f, 15.2985f, 0.0f);
    glVertex3f(10.0f, 15.3731f, 0.0f);
    glVertex3f(10.0f, 15.4478f, 0.0f);
    glVertex3f(10.0667f, 15.597f, 0.0f);
    glVertex3f(10.1333f, 15.597f, 0.0f);
    glVertex3f(10.1333f, 15.6716f, 0.0f);
    glVertex3f(10.1333f, 15.7463f, 0.0f);
    glVertex3f(10.1333f, 15.8209f, 0.0f);
    glVertex3f(10.1333f, 15.8955f, 0.0f);
    glVertex3f(10.2f, 15.9701f, 0.0f);
    glVertex3f(10.2f, 16.1194f, 0.0f);
    glVertex3f(10.2667f, 16.2687f, 0.0f);
    glVertex3f(10.3333f, 16.2687f, 0.0f);
    glVertex3f(10.3333f, 16.3433f, 0.0f);
    glVertex3f(10.4f, 16.3433f, 0.0f);
    glVertex3f(10.4667f, 16.3433f, 0.0f);
    glVertex3f(10.6f, 16.4179f, 0.0f);
    glVertex3f(10.6667f, 16.4179f, 0.0f);
    glVertex3f(10.7333f, 16.4925f, 0.0f);
    glVertex3f(10.8f, 16.4925f, 0.0f);
    glVertex3f(10.8f, 16.5672f, 0.0f);
    glVertex3f(10.8667f, 16.6418f, 0.0f);
    glVertex3f(10.9333f, 16.6418f, 0.0f);
    glVertex3f(10.9333f, 16.7164f, 0.0f);
    glVertex3f(11.0f, 16.791f, 0.0f);
    glVertex3f(11.0667f, 16.791f, 0.0f);
    glVertex3f(11.0667f, 16.8657f, 0.0f);


    glEnd();


// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE Kandooooooooo ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

    glBegin(GL_LINES);


    glColor3f(0.235, 0.31, 0.133);


    glVertex3f(1.1333f, 14.5522f, 0.0f);
    glVertex3f(1.0f, 12.9851f, 0.0f);

    glVertex3f(2.3333f, 14.7761f, 0.0f);
    glVertex3f(2.3333f, 13.209f, 0.0f);

    glVertex3f(3.6667f, 14.7761f, 0.0f);
    glVertex3f(3.6667f, 13.1343f, 0.0f);

    glVertex3f(5.4f, 14.7015f, 0.0f);
    glVertex3f(5.1333f, 12.9104f, 0.0f);

    glVertex3f(6.6f, 14.7015f, 0.0f);
    glVertex3f(6.5333f, 13.209f, 0.0f);

    glVertex3f(8.4667f, 14.7761f, 0.0f);
    glVertex3f(8.4667f, 13.3582f, 0.0f);

    glVertex3f(10.0f, 14.7015f, 0.0f);
    glVertex3f(10.1333f, 13.1343f, 0.0f);

    glVertex3f(11.3333f, 14.5522f, 0.0f);
    glVertex3f(11.3333f, 13.0597f, 0.0f);

// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Right side Kandoooooooooo ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glVertex3f(44.1333f, 14.6269f, 0.0f);
    glVertex3f(43.9333f, 12.9851f, 0.0f);

    glVertex3f(45.9333f, 14.6269f, 0.0f);
    glVertex3f(46.1333f, 12.9851f, 0.0f);

    glVertex3f(47.5333f, 14.6269f, 0.0f);
    glVertex3f(47.6667f, 13.2836f, 0.0f);

    glVertex3f(48.9333f, 14.5522f, 0.0f);
    glVertex3f(48.8667f, 13.1343f, 0.0f);

    glEnd();



// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE Right Side - 1 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.227, 0.31, 0.141);
    glVertex3f(44.2667f, 15.0f, 0.0f);

    glVertex3f(44.0667f, 13.806f, 0.0f);
    glVertex3f(44.0f, 13.806f, 0.0f);
    glVertex3f(43.9333f, 13.806f, 0.0f);
    glVertex3f(43.8667f, 13.806f, 0.0f);
    glVertex3f(43.7333f, 13.7313f, 0.0f);
    glVertex3f(43.6667f, 13.7313f, 0.0f);
    glVertex3f(43.6f, 13.7313f, 0.0f);
    glVertex3f(43.5333f, 13.7313f, 0.0f);
    glVertex3f(43.4667f, 13.7313f, 0.0f);
    glVertex3f(43.4f, 13.7313f, 0.0f);
    glVertex3f(43.3333f, 13.7313f, 0.0f);
    glVertex3f(43.2667f, 13.7313f, 0.0f);
    glVertex3f(43.2f, 13.806f, 0.0f);
    glVertex3f(43.1333f, 13.806f, 0.0f);
    glVertex3f(43.1333f, 13.8806f, 0.0f);
    glVertex3f(43.1333f, 13.9552f, 0.0f);
    glVertex3f(43.0667f, 14.0299f, 0.0f);
    glVertex3f(43.0f, 14.0299f, 0.0f);
    glVertex3f(43.0f, 14.1045f, 0.0f);
    glVertex3f(43.0f, 14.1791f, 0.0f);
    glVertex3f(43.0f, 14.2537f, 0.0f);
    glVertex3f(43.0f, 14.3284f, 0.0f);
    glVertex3f(43.0f, 14.403f, 0.0f);
    glVertex3f(42.9333f, 14.4776f, 0.0f);
    glVertex3f(42.8667f, 14.6269f, 0.0f);
    glVertex3f(42.8667f, 14.7015f, 0.0f);
    glVertex3f(42.8f, 14.7761f, 0.0f);
    glVertex3f(42.8f, 14.8507f, 0.0f);
    glVertex3f(42.8f, 14.9254f, 0.0f);
    glVertex3f(42.8f, 15.0f, 0.0f);
    glVertex3f(42.8f, 15.0746f, 0.0f);
    glVertex3f(42.8f, 15.1493f, 0.0f);
    glVertex3f(42.8f, 15.2239f, 0.0f);
    glVertex3f(42.8667f, 15.2985f, 0.0f);
    glVertex3f(42.9333f, 15.2985f, 0.0f);
    glVertex3f(43.0f, 15.2985f, 0.0f);
    glVertex3f(43.0667f, 15.2985f, 0.0f);
    glVertex3f(43.1333f, 15.3731f, 0.0f);
    glVertex3f(43.2f, 15.3731f, 0.0f);
    glVertex3f(43.2667f, 15.4478f, 0.0f);
    glVertex3f(43.4f, 15.4478f, 0.0f);
    glVertex3f(43.4f, 15.5224f, 0.0f);
    glVertex3f(43.4667f, 15.5224f, 0.0f);
    glVertex3f(43.5333f, 15.5224f, 0.0f);
    glVertex3f(43.6f, 15.5224f, 0.0f);
    glVertex3f(43.4667f, 15.597f, 0.0f);
    glVertex3f(43.4f, 15.6716f, 0.0f);
    glVertex3f(43.3333f, 15.6716f, 0.0f);
    glVertex3f(43.2667f, 15.7463f, 0.0f);
    glVertex3f(43.2f, 15.8209f, 0.0f);
    glVertex3f(43.2f, 15.8955f, 0.0f);
    glVertex3f(43.2f, 15.9701f, 0.0f);
    glVertex3f(43.2f, 16.0448f, 0.0f);
    glVertex3f(43.2f, 16.1194f, 0.0f);
    glVertex3f(43.2f, 16.194f, 0.0f);
    glVertex3f(43.2f, 16.2687f, 0.0f);
    glVertex3f(43.2f, 16.3433f, 0.0f);
    glVertex3f(43.2f, 16.4179f, 0.0f);
    glVertex3f(43.2667f, 16.4925f, 0.0f);
    glVertex3f(43.2667f, 16.6418f, 0.0f);
    glVertex3f(43.3333f, 16.7164f, 0.0f);
    glVertex3f(43.4f, 16.791f, 0.0f);
    glVertex3f(43.4f, 16.8657f, 0.0f);
    glVertex3f(43.4667f, 16.9403f, 0.0f);
    glVertex3f(43.4667f, 17.0149f, 0.0f);
    glVertex3f(43.5333f, 17.0896f, 0.0f);
    glVertex3f(43.5333f, 17.1642f, 0.0f);
    glVertex3f(43.6f, 17.1642f, 0.0f);
    glVertex3f(43.6667f, 17.1642f, 0.0f);
    glVertex3f(43.7333f, 17.2388f, 0.0f);
    glVertex3f(43.8f, 17.2388f, 0.0f);
    glVertex3f(43.8667f, 17.2388f, 0.0f);
    glVertex3f(43.9333f, 17.2388f, 0.0f);
    glVertex3f(44.0f, 17.2388f, 0.0f);
    glVertex3f(44.0f, 17.3134f, 0.0f);
    glVertex3f(44.0667f, 17.3134f, 0.0f);
    glVertex3f(44.1333f, 17.3134f, 0.0f);
    glVertex3f(44.2f, 17.3134f, 0.0f);
    glVertex3f(44.2667f, 17.3134f, 0.0f);
    glVertex3f(44.3333f, 17.2388f, 0.0f);
    glVertex3f(44.4f, 17.2388f, 0.0f);
    glVertex3f(44.4f, 17.0896f, 0.0f);
    glVertex3f(44.4f, 17.0149f, 0.0f);
    glVertex3f(44.4f, 16.9403f, 0.0f);
    glVertex3f(44.4667f, 16.8657f, 0.0f);
    glVertex3f(44.4667f, 16.791f, 0.0f);
    glVertex3f(44.4667f, 16.7164f, 0.0f);
    glVertex3f(44.4667f, 16.6418f, 0.0f);
    glVertex3f(44.4667f, 16.5672f, 0.0f);
    glVertex3f(44.4667f, 16.4925f, 0.0f);
    glVertex3f(44.4f, 16.4179f, 0.0f);
    glVertex3f(44.4f, 16.3433f, 0.0f);
    glVertex3f(44.4f, 16.2687f, 0.0f);
    glVertex3f(44.4667f, 16.2687f, 0.0f);
    glVertex3f(44.5333f, 16.2687f, 0.0f);
    glVertex3f(44.6f, 16.2687f, 0.0f);
    glVertex3f(44.6667f, 16.2687f, 0.0f);
    glVertex3f(44.7333f, 16.2687f, 0.0f);
    glVertex3f(44.8f, 16.2687f, 0.0f);
    glVertex3f(44.8667f, 16.2687f, 0.0f);
    glVertex3f(44.9333f, 16.2687f, 0.0f);
    glVertex3f(45.0f, 16.194f, 0.0f);
    glVertex3f(45.0667f, 16.194f, 0.0f);
    glVertex3f(45.0667f, 16.1194f, 0.0f);
    glVertex3f(45.1333f, 16.1194f, 0.0f);
    glVertex3f(45.1333f, 16.0448f, 0.0f);
    glVertex3f(45.1333f, 15.9701f, 0.0f);
    glVertex3f(45.1333f, 15.8955f, 0.0f);
    glVertex3f(45.1333f, 15.8209f, 0.0f);
    glVertex3f(45.1333f, 15.7463f, 0.0f);
    glVertex3f(45.1333f, 15.6716f, 0.0f);
    glVertex3f(45.1333f, 15.597f, 0.0f);
    glVertex3f(45.0667f, 15.5224f, 0.0f);
    glVertex3f(45.0667f, 15.4478f, 0.0f);
    glVertex3f(45.0f, 15.4478f, 0.0f);
    glVertex3f(45.0f, 15.3731f, 0.0f);
    glVertex3f(45.0f, 15.2985f, 0.0f);
    glVertex3f(44.9333f, 15.2985f, 0.0f);
    glVertex3f(44.8667f, 15.2985f, 0.0f);
    glVertex3f(44.8f, 15.2239f, 0.0f);
    glVertex3f(44.7333f, 15.2239f, 0.0f);
    glVertex3f(44.6667f, 15.2239f, 0.0f);
    glVertex3f(44.7333f, 15.2239f, 0.0f);
    glVertex3f(44.8f, 15.1493f, 0.0f);
    glVertex3f(44.8667f, 15.1493f, 0.0f);
    glVertex3f(44.9333f, 15.1493f, 0.0f);
    glVertex3f(45.0f, 15.0746f, 0.0f);
    glVertex3f(45.0667f, 15.0746f, 0.0f);
    glVertex3f(45.1333f, 15.0746f, 0.0f);
    glVertex3f(45.2f, 15.0f, 0.0f);
    glVertex3f(45.2f, 14.9254f, 0.0f);
    glVertex3f(45.2f, 14.8507f, 0.0f);
    glVertex3f(45.2f, 14.7761f, 0.0f);
    glVertex3f(45.2f, 14.7015f, 0.0f);
    glVertex3f(45.2f, 14.6269f, 0.0f);
    glVertex3f(45.2f, 14.5522f, 0.0f);
    glVertex3f(45.2f, 14.4776f, 0.0f);
    glVertex3f(45.1333f, 14.4776f, 0.0f);
    glVertex3f(45.0667f, 14.4776f, 0.0f);
    glVertex3f(45.0f, 14.4776f, 0.0f);
    glVertex3f(44.9333f, 14.4776f, 0.0f);
    glVertex3f(44.8667f, 14.403f, 0.0f);
    glVertex3f(44.8f, 14.403f, 0.0f);
    glVertex3f(44.7333f, 14.403f, 0.0f);
    glVertex3f(44.7333f, 14.3284f, 0.0f);
    glVertex3f(44.6667f, 14.3284f, 0.0f);
    glVertex3f(44.6f, 14.3284f, 0.0f);
    glVertex3f(44.5333f, 14.3284f, 0.0f);
    glVertex3f(44.5333f, 14.2537f, 0.0f);
    glVertex3f(44.6f, 14.2537f, 0.0f);
    glVertex3f(44.6667f, 14.2537f, 0.0f);
    glVertex3f(44.7333f, 14.1791f, 0.0f);
    glVertex3f(44.7333f, 14.1045f, 0.0f);
    glVertex3f(44.8f, 14.0299f, 0.0f);
    glVertex3f(44.8f, 13.9552f, 0.0f);
    glVertex3f(44.8f, 13.8806f, 0.0f);
    glVertex3f(44.8f, 13.806f, 0.0f);
    glVertex3f(44.7333f, 13.7313f, 0.0f);
    glVertex3f(44.6667f, 13.6567f, 0.0f);
    glVertex3f(44.6f, 13.5821f, 0.0f);
    glVertex3f(44.5333f, 13.5821f, 0.0f);
    glVertex3f(44.4667f, 13.5821f, 0.0f);
    glVertex3f(44.4f, 13.5821f, 0.0f);
    glVertex3f(44.3333f, 13.6567f, 0.0f);
    glVertex3f(44.2667f, 13.7313f, 0.0f);
    glVertex3f(44.2667f, 13.806f, 0.0f);
    glVertex3f(44.2f, 13.806f, 0.0f);
    glVertex3f(44.1333f, 13.806f, 0.0f);
    glVertex3f(44.0667f, 13.806f, 0.0f);
    glVertex3f(44.0f, 13.806f, 0.0f);

    glEnd();


// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE Right Side - 2 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.224, 0.314, 0.149);
    glVertex3f(46.0667f, 15.2985f, 0.0f);


    glVertex3f(45.1333f, 15.2985f, 0.0f);
    glVertex3f(45.2f, 15.3731f, 0.0f);
    glVertex3f(45.2667f, 15.3731f, 0.0f);
    glVertex3f(45.3333f, 15.3731f, 0.0f);
    glVertex3f(45.3333f, 15.4478f, 0.0f);
    glVertex3f(45.4f, 15.5224f, 0.0f);
    glVertex3f(45.4f, 15.597f, 0.0f);
    glVertex3f(45.4f, 15.6716f, 0.0f);
    glVertex3f(45.4f, 15.7463f, 0.0f);
    glVertex3f(45.3333f, 15.8955f, 0.0f);
    glVertex3f(45.2667f, 15.9701f, 0.0f);
    glVertex3f(45.2667f, 16.0448f, 0.0f);
    glVertex3f(45.2667f, 16.1194f, 0.0f);
    glVertex3f(45.2667f, 16.194f, 0.0f);
    glVertex3f(45.2667f, 16.2687f, 0.0f);
    glVertex3f(45.3333f, 16.3433f, 0.0f);
    glVertex3f(45.4f, 16.4179f, 0.0f);
    glVertex3f(45.4667f, 16.4179f, 0.0f);
    glVertex3f(45.5333f, 16.4925f, 0.0f);
    glVertex3f(45.6f, 16.4925f, 0.0f);
    glVertex3f(45.6f, 16.5672f, 0.0f);
    glVertex3f(45.6f, 16.6418f, 0.0f);
    glVertex3f(45.6f, 16.7164f, 0.0f);
    glVertex3f(45.6f, 16.791f, 0.0f);
    glVertex3f(45.6f, 16.8657f, 0.0f);
    glVertex3f(45.6f, 16.9403f, 0.0f);
    glVertex3f(45.6f, 17.0149f, 0.0f);
    glVertex3f(45.6f, 17.0896f, 0.0f);
    glVertex3f(45.5333f, 17.0896f, 0.0f);
    glVertex3f(45.4667f, 17.1642f, 0.0f);
    glVertex3f(45.4667f, 17.2388f, 0.0f);
    glVertex3f(45.4667f, 17.3134f, 0.0f);
    glVertex3f(45.4667f, 17.3881f, 0.0f);
    glVertex3f(45.4667f, 17.4627f, 0.0f);
    glVertex3f(45.5333f, 17.5373f, 0.0f);
    glVertex3f(45.5333f, 17.6119f, 0.0f);
    glVertex3f(45.6f, 17.6866f, 0.0f);
    glVertex3f(45.6667f, 17.6866f, 0.0f);
    glVertex3f(45.7333f, 17.7612f, 0.0f);
    glVertex3f(45.8f, 17.7612f, 0.0f);
    glVertex3f(45.8667f, 17.7612f, 0.0f);
    glVertex3f(45.8667f, 17.8358f, 0.0f);
    glVertex3f(45.9333f, 17.8358f, 0.0f);
    glVertex3f(46.0f, 17.8358f, 0.0f);
    glVertex3f(46.0667f, 17.7612f, 0.0f);
    glVertex3f(46.0667f, 17.6866f, 0.0f);
    glVertex3f(46.0667f, 17.6119f, 0.0f);
    glVertex3f(46.0f, 17.6119f, 0.0f);
    glVertex3f(46.0f, 17.5373f, 0.0f);
    glVertex3f(46.0f, 17.4627f, 0.0f);
    glVertex3f(45.9333f, 17.3881f, 0.0f);
    glVertex3f(45.9333f, 17.3134f, 0.0f);
    glVertex3f(45.9333f, 17.2388f, 0.0f);
    glVertex3f(45.9333f, 17.1642f, 0.0f);
    glVertex3f(45.8667f, 17.0896f, 0.0f);
    glVertex3f(45.8667f, 17.0149f, 0.0f);
    glVertex3f(45.8667f, 16.9403f, 0.0f);
    glVertex3f(45.9333f, 16.8657f, 0.0f);
    glVertex3f(45.9333f, 16.791f, 0.0f);
    glVertex3f(46.0f, 16.791f, 0.0f);
    glVertex3f(46.0667f, 16.791f, 0.0f);
    glVertex3f(46.1333f, 16.791f, 0.0f);
    glVertex3f(46.2f, 16.791f, 0.0f);
    glVertex3f(46.2667f, 16.791f, 0.0f);
    glVertex3f(46.3333f, 16.7164f, 0.0f);
    glVertex3f(46.3333f, 16.6418f, 0.0f);
    glVertex3f(46.3333f, 16.5672f, 0.0f);
    glVertex3f(46.3333f, 16.4925f, 0.0f);
    glVertex3f(46.3333f, 16.4179f, 0.0f);
    glVertex3f(46.3333f, 16.3433f, 0.0f);
    glVertex3f(46.3333f, 16.2687f, 0.0f);
    glVertex3f(46.3333f, 16.194f, 0.0f);
    glVertex3f(46.3333f, 16.1194f, 0.0f);
    glVertex3f(46.3333f, 16.0448f, 0.0f);
    glVertex3f(46.3333f, 15.9701f, 0.0f);
    glVertex3f(46.3333f, 15.8955f, 0.0f);
    glVertex3f(46.3333f, 15.8209f, 0.0f);
    glVertex3f(46.3333f, 15.7463f, 0.0f);
    glVertex3f(46.4f, 15.7463f, 0.0f);
    glVertex3f(46.4f, 15.6716f, 0.0f);
    glVertex3f(46.4667f, 15.6716f, 0.0f);
    glVertex3f(46.4667f, 15.597f, 0.0f);
    glVertex3f(46.5333f, 15.597f, 0.0f);
    glVertex3f(46.6f, 15.5224f, 0.0f);
    glVertex3f(46.6667f, 15.5224f, 0.0f);
    glVertex3f(46.6667f, 15.4478f, 0.0f);
    glVertex3f(46.6f, 15.3731f, 0.0f);
    glVertex3f(46.5333f, 15.2985f, 0.0f);
    glVertex3f(46.4667f, 15.2985f, 0.0f);
    glVertex3f(46.4f, 15.2239f, 0.0f);
    glVertex3f(46.3333f, 15.2239f, 0.0f);
    glVertex3f(46.3333f, 15.1493f, 0.0f);
    glVertex3f(46.4f, 15.0746f, 0.0f);
    glVertex3f(46.4667f, 15.0746f, 0.0f);
    glVertex3f(46.5333f, 15.0746f, 0.0f);
    glVertex3f(46.5333f, 15.0f, 0.0f);
    glVertex3f(46.6f, 15.0f, 0.0f);
    glVertex3f(46.6f, 14.9254f, 0.0f);
    glVertex3f(46.6f, 14.8507f, 0.0f);
    glVertex3f(46.6f, 14.7761f, 0.0f);
    glVertex3f(46.6f, 14.7015f, 0.0f);
    glVertex3f(46.6f, 14.6269f, 0.0f);
    glVertex3f(46.6f, 14.5522f, 0.0f);
    glVertex3f(46.6f, 14.4776f, 0.0f);
    glVertex3f(46.5333f, 14.4776f, 0.0f);
    glVertex3f(46.5333f, 14.403f, 0.0f);
    glVertex3f(46.4667f, 14.403f, 0.0f);
    glVertex3f(46.3333f, 14.403f, 0.0f);
    glVertex3f(46.2667f, 14.403f, 0.0f);
    glVertex3f(46.2f, 14.403f, 0.0f);
    glVertex3f(46.0667f, 14.3284f, 0.0f);
    glVertex3f(46.0f, 14.2537f, 0.0f);
    glVertex3f(45.9333f, 14.2537f, 0.0f);
    glVertex3f(45.8667f, 14.2537f, 0.0f);
    glVertex3f(45.8f, 14.3284f, 0.0f);
    glVertex3f(45.8f, 14.403f, 0.0f);
    glVertex3f(45.8f, 14.4776f, 0.0f);
    glVertex3f(45.8f, 14.5522f, 0.0f);
    glVertex3f(45.7333f, 14.5522f, 0.0f);
    glVertex3f(45.6667f, 14.5522f, 0.0f);
    glVertex3f(45.6f, 14.4776f, 0.0f);
    glVertex3f(45.5333f, 14.4776f, 0.0f);
    glVertex3f(45.4667f, 14.403f, 0.0f);
    glVertex3f(45.4f, 14.403f, 0.0f);
    glVertex3f(45.3333f, 14.403f, 0.0f);
    glVertex3f(45.2667f, 14.403f, 0.0f);
    glVertex3f(45.2f, 14.403f, 0.0f);
    glVertex3f(45.2f, 14.3284f, 0.0f);
    glVertex3f(45.1333f, 14.3284f, 0.0f);
    glVertex3f(45.0667f, 14.3284f, 0.0f);
    glVertex3f(45.0f, 14.3284f, 0.0f);
    glVertex3f(44.9333f, 14.3284f, 0.0f);
    glVertex3f(44.8667f, 14.3284f, 0.0f);
    glVertex3f(44.8f, 14.3284f, 0.0f);
    glVertex3f(44.7333f, 14.403f, 0.0f);
    glVertex3f(44.7333f, 14.4776f, 0.0f);
    glVertex3f(44.6667f, 14.5522f, 0.0f);
    glVertex3f(44.6667f, 14.6269f, 0.0f);
    glVertex3f(44.6667f, 14.7015f, 0.0f);
    glVertex3f(44.6f, 14.7015f, 0.0f);
    glVertex3f(44.5333f, 14.7761f, 0.0f);
    glVertex3f(44.4667f, 14.7761f, 0.0f);
    glVertex3f(44.4f, 14.7761f, 0.0f);
    glVertex3f(44.3333f, 14.7761f, 0.0f);
    glVertex3f(44.2667f, 14.7761f, 0.0f);
    glVertex3f(44.2667f, 14.8507f, 0.0f);
    glVertex3f(44.2667f, 14.9254f, 0.0f);
    glVertex3f(44.2667f, 15.0f, 0.0f);
    glVertex3f(44.2667f, 15.0746f, 0.0f);
    glVertex3f(44.3333f, 15.1493f, 0.0f);
    glVertex3f(44.3333f, 15.2239f, 0.0f);
    glVertex3f(44.4f, 15.3731f, 0.0f);
    glVertex3f(44.4667f, 15.4478f, 0.0f);
    glVertex3f(44.5333f, 15.4478f, 0.0f);
    glVertex3f(44.6f, 15.4478f, 0.0f);
    glVertex3f(44.6667f, 15.4478f, 0.0f);
    glVertex3f(44.7333f, 15.4478f, 0.0f);
    glVertex3f(44.8f, 15.4478f, 0.0f);
    glVertex3f(44.8667f, 15.4478f, 0.0f);
    glVertex3f(44.9333f, 15.4478f, 0.0f);
    glVertex3f(45.0f, 15.5224f, 0.0f);
    glVertex3f(45.0f, 15.597f, 0.0f);
    glVertex3f(45.0667f, 15.597f, 0.0f);
    glVertex3f(45.1333f, 15.597f, 0.0f);
    glVertex3f(45.1333f, 15.6716f, 0.0f);
    glVertex3f(45.1333f, 15.7463f, 0.0f);
    glVertex3f(45.1333f, 15.8209f, 0.0f);
    glVertex3f(45.1333f, 15.8955f, 0.0f);


    glEnd();


// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE Right Side - 4 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.227, 0.31, 0.141);
    glVertex3f(47.6f, 15.0746f, 0.0f);


    glVertex3f(46.4667f, 15.3731f, 0.0f);
    glVertex3f(46.4667f, 15.4478f, 0.0f);
    glVertex3f(46.4667f, 15.5224f, 0.0f);
    glVertex3f(46.4667f, 15.597f, 0.0f);
    glVertex3f(46.4667f, 15.6716f, 0.0f);
    glVertex3f(46.4667f, 15.7463f, 0.0f);
    glVertex3f(46.5333f, 15.8209f, 0.0f);
    glVertex3f(46.5333f, 15.8955f, 0.0f);
    glVertex3f(46.5333f, 15.9701f, 0.0f);
    glVertex3f(46.5333f, 16.0448f, 0.0f);
    glVertex3f(46.5333f, 16.1194f, 0.0f);
    glVertex3f(46.5333f, 16.194f, 0.0f);
    glVertex3f(46.5333f, 16.2687f, 0.0f);
    glVertex3f(46.6f, 16.2687f, 0.0f);
    glVertex3f(46.6667f, 16.2687f, 0.0f);
    glVertex3f(46.7333f, 16.2687f, 0.0f);
    glVertex3f(46.8f, 16.3433f, 0.0f);
    glVertex3f(46.8667f, 16.3433f, 0.0f);
    glVertex3f(46.9333f, 16.3433f, 0.0f);
    glVertex3f(47.0f, 16.3433f, 0.0f);
    glVertex3f(46.9333f, 16.4925f, 0.0f);
    glVertex3f(46.8667f, 16.5672f, 0.0f);
    glVertex3f(46.8667f, 16.6418f, 0.0f);
    glVertex3f(46.8667f, 16.7164f, 0.0f);
    glVertex3f(46.8f, 16.791f, 0.0f);
    glVertex3f(46.8f, 16.8657f, 0.0f);
    glVertex3f(46.8f, 16.9403f, 0.0f);
    glVertex3f(46.8f, 17.0149f, 0.0f);
    glVertex3f(46.8f, 17.0896f, 0.0f);
    glVertex3f(46.8f, 17.1642f, 0.0f);
    glVertex3f(46.8667f, 17.3134f, 0.0f);
    glVertex3f(46.9333f, 17.3881f, 0.0f);
    glVertex3f(47.0f, 17.3881f, 0.0f);
    glVertex3f(47.0667f, 17.3881f, 0.0f);
    glVertex3f(47.1333f, 17.3881f, 0.0f);
    glVertex3f(47.2f, 17.3881f, 0.0f);
    glVertex3f(47.2667f, 17.3881f, 0.0f);
    glVertex3f(47.3333f, 17.3881f, 0.0f);
    glVertex3f(47.4f, 17.3881f, 0.0f);
    glVertex3f(47.4667f, 17.3881f, 0.0f);
    glVertex3f(47.5333f, 17.3881f, 0.0f);
    glVertex3f(47.6f, 17.3881f, 0.0f);
    glVertex3f(47.6667f, 17.3881f, 0.0f);
    glVertex3f(47.7333f, 17.3134f, 0.0f);
    glVertex3f(47.8f, 17.2388f, 0.0f);
    glVertex3f(47.8667f, 17.1642f, 0.0f);
    glVertex3f(47.8667f, 17.0896f, 0.0f);
    glVertex3f(47.9333f, 17.0896f, 0.0f);
    glVertex3f(47.9333f, 17.0149f, 0.0f);
    glVertex3f(47.9333f, 16.9403f, 0.0f);
    glVertex3f(47.9333f, 16.8657f, 0.0f);
    glVertex3f(48.0f, 16.791f, 0.0f);
    glVertex3f(48.0667f, 16.791f, 0.0f);
    glVertex3f(48.1333f, 16.791f, 0.0f);
    glVertex3f(48.2f, 16.791f, 0.0f);
    glVertex3f(48.2667f, 16.7164f, 0.0f);
    glVertex3f(48.2667f, 16.6418f, 0.0f);
    glVertex3f(48.3333f, 16.6418f, 0.0f);
    glVertex3f(48.3333f, 16.5672f, 0.0f);
    glVertex3f(48.3333f, 16.4925f, 0.0f);
    glVertex3f(48.4f, 16.4925f, 0.0f);
    glVertex3f(48.4f, 16.4179f, 0.0f);
    glVertex3f(48.4f, 16.3433f, 0.0f);
    glVertex3f(48.4f, 16.2687f, 0.0f);
    glVertex3f(48.4f, 16.194f, 0.0f);
    glVertex3f(48.4f, 16.1194f, 0.0f);
    glVertex3f(48.4f, 16.0448f, 0.0f);
    glVertex3f(48.4f, 15.9701f, 0.0f);
    glVertex3f(48.4f, 15.8955f, 0.0f);
    glVertex3f(48.4f, 15.8209f, 0.0f);
    glVertex3f(48.2667f, 15.7463f, 0.0f);
    glVertex3f(48.2f, 15.7463f, 0.0f);
    glVertex3f(48.2667f, 15.7463f, 0.0f);
    glVertex3f(48.2667f, 15.6716f, 0.0f);
    glVertex3f(48.3333f, 15.6716f, 0.0f);
    glVertex3f(48.4f, 15.6716f, 0.0f);
    glVertex3f(48.4667f, 15.597f, 0.0f);
    glVertex3f(48.5333f, 15.597f, 0.0f);
    glVertex3f(48.6f, 15.5224f, 0.0f);
    glVertex3f(48.6f, 15.4478f, 0.0f);
    glVertex3f(48.6f, 15.3731f, 0.0f);
    glVertex3f(48.6f, 15.2985f, 0.0f);
    glVertex3f(48.6f, 15.2239f, 0.0f);
    glVertex3f(48.6f, 15.1493f, 0.0f);
    glVertex3f(48.6f, 15.0746f, 0.0f);
    glVertex3f(48.6f, 15.0f, 0.0f);
    glVertex3f(48.5333f, 15.0f, 0.0f);
    glVertex3f(48.4667f, 14.9254f, 0.0f);
    glVertex3f(48.4f, 14.9254f, 0.0f);
    glVertex3f(48.3333f, 14.9254f, 0.0f);
    glVertex3f(48.2f, 14.8507f, 0.0f);
    glVertex3f(48.1333f, 14.8507f, 0.0f);
    glVertex3f(48.0667f, 14.8507f, 0.0f);
    glVertex3f(48.1333f, 14.8507f, 0.0f);
    glVertex3f(48.2f, 14.8507f, 0.0f);
    glVertex3f(48.2667f, 14.7761f, 0.0f);
    glVertex3f(48.3333f, 14.7761f, 0.0f);
    glVertex3f(48.4f, 14.7015f, 0.0f);
    glVertex3f(48.4f, 14.6269f, 0.0f);
    glVertex3f(48.4f, 14.5522f, 0.0f);
    glVertex3f(48.4667f, 14.403f, 0.0f);
    glVertex3f(48.4f, 14.3284f, 0.0f);
    glVertex3f(48.3333f, 14.3284f, 0.0f);
    glVertex3f(48.2667f, 14.2537f, 0.0f);
    glVertex3f(48.2f, 14.2537f, 0.0f);
    glVertex3f(48.1333f, 14.2537f, 0.0f);
    glVertex3f(48.0667f, 14.2537f, 0.0f);
    glVertex3f(48.0f, 14.1791f, 0.0f);
    glVertex3f(47.9333f, 14.1791f, 0.0f);
    glVertex3f(47.8667f, 14.1791f, 0.0f);
    glVertex3f(47.8f, 14.1791f, 0.0f);
    glVertex3f(47.7333f, 14.1791f, 0.0f);
    glVertex3f(47.6667f, 14.1791f, 0.0f);
    glVertex3f(47.6f, 14.1791f, 0.0f);
    glVertex3f(47.5333f, 14.1791f, 0.0f);
    glVertex3f(47.4667f, 14.1791f, 0.0f);
    glVertex3f(47.4667f, 14.1045f, 0.0f);
    glVertex3f(47.4667f, 14.0299f, 0.0f);
    glVertex3f(47.4f, 13.9552f, 0.0f);
    glVertex3f(47.3333f, 13.9552f, 0.0f);
    glVertex3f(47.2667f, 13.9552f, 0.0f);
    glVertex3f(47.2f, 13.9552f, 0.0f);
    glVertex3f(47.1333f, 13.9552f, 0.0f);
    glVertex3f(47.0667f, 13.9552f, 0.0f);
    glVertex3f(47.0f, 13.9552f, 0.0f);
    glVertex3f(46.9333f, 13.9552f, 0.0f);
    glVertex3f(46.8667f, 13.9552f, 0.0f);
    glVertex3f(46.8f, 14.0299f, 0.0f);
    glVertex3f(46.8f, 14.1045f, 0.0f);
    glVertex3f(46.7333f, 14.1045f, 0.0f);
    glVertex3f(46.6667f, 14.1045f, 0.0f);
    glVertex3f(46.6f, 14.1045f, 0.0f);
    glVertex3f(46.5333f, 14.1045f, 0.0f);
    glVertex3f(46.4667f, 14.1045f, 0.0f);
    glVertex3f(46.4f, 14.1791f, 0.0f);
    glVertex3f(46.2667f, 14.2537f, 0.0f);
    glVertex3f(46.2667f, 14.3284f, 0.0f);
    glVertex3f(46.2f, 14.3284f, 0.0f);
    glVertex3f(46.2f, 14.403f, 0.0f);
    glVertex3f(46.1333f, 14.403f, 0.0f);
    glVertex3f(46.0667f, 14.4776f, 0.0f);
    glVertex3f(46.0f, 14.5522f, 0.0f);
    glVertex3f(46.0f, 14.6269f, 0.0f);
    glVertex3f(46.0f, 14.7015f, 0.0f);
    glVertex3f(46.0f, 14.7761f, 0.0f);
    glVertex3f(46.0f, 14.8507f, 0.0f);
    glVertex3f(46.0f, 14.9254f, 0.0f);
    glVertex3f(46.0f, 15.0f, 0.0f);
    glVertex3f(46.0f, 15.0746f, 0.0f);
    glVertex3f(46.0667f, 15.0746f, 0.0f);
    glVertex3f(46.1333f, 15.1493f, 0.0f);
    glVertex3f(46.2f, 15.1493f, 0.0f);
    glVertex3f(46.2667f, 15.1493f, 0.0f);
    glVertex3f(46.3333f, 15.2239f, 0.0f);
    glVertex3f(46.2667f, 15.2239f, 0.0f);
    glVertex3f(46.2f, 15.2239f, 0.0f);
    glVertex3f(46.0667f, 15.2985f, 0.0f);
    glVertex3f(46.0f, 15.3731f, 0.0f);
    glVertex3f(46.0f, 15.4478f, 0.0f);
    glVertex3f(46.0f, 15.5224f, 0.0f);
    glVertex3f(46.0f, 15.597f, 0.0f);
    glVertex3f(46.0f, 15.6716f, 0.0f);
    glVertex3f(46.0667f, 15.7463f, 0.0f);
    glVertex3f(46.1333f, 15.7463f, 0.0f);
    glVertex3f(46.2f, 15.7463f, 0.0f);
    glVertex3f(46.2667f, 15.7463f, 0.0f);
    glVertex3f(46.3333f, 15.8209f, 0.0f);
    glVertex3f(46.4f, 15.8209f, 0.0f);
    glVertex3f(46.4667f, 15.8955f, 0.0f);
    glVertex3f(46.5333f, 15.9701f, 0.0f);
    glVertex3f(46.5333f, 16.0448f, 0.0f);
    glVertex3f(46.5333f, 16.1194f, 0.0f);
    glVertex3f(46.6f, 16.1194f, 0.0f);
    glVertex3f(46.6667f, 16.194f, 0.0f);
    glVertex3f(46.7333f, 16.194f, 0.0f);
    glVertex3f(46.8f, 16.194f, 0.0f);

    glEnd();


// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬TREE Right Side - 5 ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.224, 0.314, 0.141);
    glVertex3f(49.0f, 15.5224f, 0.0f);

    glVertex3f(47.9333f, 15.6716f, 0.0f);
    glVertex3f(47.9333f, 15.7463f, 0.0f);
    glVertex3f(47.9333f, 15.8209f, 0.0f);
    glVertex3f(47.9333f, 15.9701f, 0.0f);
    glVertex3f(47.9333f, 16.0448f, 0.0f);
    glVertex3f(47.9333f, 16.1194f, 0.0f);
    glVertex3f(47.9333f, 16.194f, 0.0f);
    glVertex3f(47.9333f, 16.2687f, 0.0f);
    glVertex3f(47.9333f, 16.3433f, 0.0f);
    glVertex3f(47.9333f, 16.4179f, 0.0f);
    glVertex3f(48.0f, 16.4925f, 0.0f);
    glVertex3f(48.0667f, 16.4925f, 0.0f);
    glVertex3f(48.1333f, 16.4925f, 0.0f);
    glVertex3f(48.1333f, 16.5672f, 0.0f);
    glVertex3f(48.2f, 16.5672f, 0.0f);
    glVertex3f(48.2667f, 16.5672f, 0.0f);
    glVertex3f(48.3333f, 16.5672f, 0.0f);
    glVertex3f(48.4f, 16.6418f, 0.0f);
    glVertex3f(48.4f, 16.7164f, 0.0f);
    glVertex3f(48.3333f, 16.791f, 0.0f);
    glVertex3f(48.2667f, 16.791f, 0.0f);
    glVertex3f(48.2667f, 16.8657f, 0.0f);
    glVertex3f(48.2f, 16.9403f, 0.0f);
    glVertex3f(48.2667f, 17.0149f, 0.0f);
    glVertex3f(48.4f, 17.0896f, 0.0f);
    glVertex3f(48.4f, 17.1642f, 0.0f);
    glVertex3f(48.4667f, 17.3134f, 0.0f);
    glVertex3f(48.4667f, 17.3881f, 0.0f);
    glVertex3f(48.4667f, 17.4627f, 0.0f);
    glVertex3f(48.4667f, 17.5373f, 0.0f);
    glVertex3f(48.4667f, 17.6119f, 0.0f);
    glVertex3f(48.4667f, 17.6866f, 0.0f);
    glVertex3f(48.4f, 17.8358f, 0.0f);
    glVertex3f(48.4f, 17.9851f, 0.0f);
    glVertex3f(48.4f, 18.0597f, 0.0f);
    glVertex3f(48.4f, 18.1343f, 0.0f);
    glVertex3f(48.4f, 18.209f, 0.0f);
    glVertex3f(48.4f, 18.2836f, 0.0f);
    glVertex3f(48.5333f, 18.2836f, 0.0f);
    glVertex3f(48.5333f, 18.3582f, 0.0f);
    glVertex3f(48.6f, 18.3582f, 0.0f);
    glVertex3f(48.6667f, 18.3582f, 0.0f);
    glVertex3f(48.7333f, 18.3582f, 0.0f);
    glVertex3f(48.8f, 18.3582f, 0.0f);
    glVertex3f(48.8667f, 18.3582f, 0.0f);
    glVertex3f(48.9333f, 18.3582f, 0.0f);
    glVertex3f(48.9333f, 18.2836f, 0.0f);
    glVertex3f(48.9333f, 18.209f, 0.0f);
    glVertex3f(48.9333f, 18.1343f, 0.0f);
    glVertex3f(48.8667f, 18.0597f, 0.0f);
    glVertex3f(48.8667f, 17.9851f, 0.0f);
    glVertex3f(48.8667f, 17.9104f, 0.0f);
    glVertex3f(48.9333f, 17.8358f, 0.0f);
    glVertex3f(48.9333f, 17.7612f, 0.0f);
    glVertex3f(49.0f, 17.6866f, 0.0f);
    glVertex3f(49.0f, 17.6119f, 0.0f);
    glVertex3f(49.0667f, 17.6119f, 0.0f);
    glVertex3f(49.0667f, 17.5373f, 0.0f);
    glVertex3f(49.0667f, 17.4627f, 0.0f);
    glVertex3f(49.0667f, 17.3881f, 0.0f);
    glVertex3f(49.0667f, 17.3134f, 0.0f);
    glVertex3f(49.1333f, 17.1642f, 0.0f);
    glVertex3f(49.2667f, 17.1642f, 0.0f);
    glVertex3f(49.2667f, 17.0896f, 0.0f);
    glVertex3f(49.3333f, 17.0149f, 0.0f);
    glVertex3f(49.4f, 17.0149f, 0.0f);
    glVertex3f(49.4667f, 17.0149f, 0.0f);
    glVertex3f(49.4667f, 16.9403f, 0.0f);
    glVertex3f(49.4667f, 16.8657f, 0.0f);
    glVertex3f(49.4f, 16.791f, 0.0f);
    glVertex3f(49.3333f, 16.7164f, 0.0f);
    glVertex3f(49.2667f, 16.7164f, 0.0f);
    glVertex3f(49.2f, 16.7164f, 0.0f);
    glVertex3f(49.2f, 16.6418f, 0.0f);
    glVertex3f(49.2f, 16.5672f, 0.0f);
    glVertex3f(49.2f, 16.4925f, 0.0f);
    glVertex3f(49.2f, 16.4179f, 0.0f);
    glVertex3f(49.2f, 16.3433f, 0.0f);
    glVertex3f(49.2f, 16.2687f, 0.0f);
    glVertex3f(49.2f, 16.194f, 0.0f);
    glVertex3f(49.2f, 16.1194f, 0.0f);
    glVertex3f(49.2f, 16.0448f, 0.0f);
    glVertex3f(49.2f, 15.9701f, 0.0f);
    glVertex3f(49.2f, 15.8955f, 0.0f);
    glVertex3f(49.2667f, 15.8209f, 0.0f);
    glVertex3f(49.3333f, 15.7463f, 0.0f);
    glVertex3f(49.3333f, 15.6716f, 0.0f);
    glVertex3f(49.3333f, 15.597f, 0.0f);
    glVertex3f(49.4f, 15.5224f, 0.0f);
    glVertex3f(49.4f, 15.4478f, 0.0f);
    glVertex3f(49.4667f, 15.4478f, 0.0f);
    glVertex3f(49.5333f, 15.3731f, 0.0f);
    glVertex3f(49.6f, 15.3731f, 0.0f);
    glVertex3f(49.6f, 15.2985f, 0.0f);
    glVertex3f(49.6f, 15.2239f, 0.0f);
    glVertex3f(49.6f, 15.1493f, 0.0f);
    glVertex3f(49.5333f, 15.1493f, 0.0f);
    glVertex3f(49.4667f, 15.0746f, 0.0f);
    glVertex3f(49.4667f, 15.0f, 0.0f);
    glVertex3f(49.4667f, 14.9254f, 0.0f);
    glVertex3f(49.4667f, 14.8507f, 0.0f);
    glVertex3f(49.5333f, 14.8507f, 0.0f);
    glVertex3f(49.6f, 14.8507f, 0.0f);
    glVertex3f(49.6667f, 14.8507f, 0.0f);
    glVertex3f(49.7333f, 14.8507f, 0.0f);
    glVertex3f(49.8f, 14.8507f, 0.0f);
    glVertex3f(49.8667f, 14.8507f, 0.0f);
    glVertex3f(49.9333f, 14.8507f, 0.0f);
    glVertex3f(50.0f, 14.8507f, 0.0f);
    glVertex3f(50.0f, 14.7761f, 0.0f);
    glVertex3f(49.9333f, 14.7761f, 0.0f);
    glVertex3f(49.8f, 14.7761f, 0.0f);
    glVertex3f(49.8f, 14.7015f, 0.0f);
    glVertex3f(49.7333f, 14.7015f, 0.0f);
    glVertex3f(49.6667f, 14.6269f, 0.0f);
    glVertex3f(49.6f, 14.6269f, 0.0f);
    glVertex3f(49.5333f, 14.6269f, 0.0f);
    glVertex3f(49.4667f, 14.6269f, 0.0f);
    glVertex3f(49.4f, 14.6269f, 0.0f);
    glVertex3f(49.3333f, 14.6269f, 0.0f);
    glVertex3f(49.2667f, 14.6269f, 0.0f);
    glVertex3f(49.2f, 14.6269f, 0.0f);
    glVertex3f(49.1333f, 14.5522f, 0.0f);
    glVertex3f(49.0667f, 14.5522f, 0.0f);
    glVertex3f(49.0f, 14.5522f, 0.0f);
    glVertex3f(48.9333f, 14.5522f, 0.0f);
    glVertex3f(48.8667f, 14.5522f, 0.0f);
    glVertex3f(48.8f, 14.4776f, 0.0f);
    glVertex3f(48.7333f, 14.4776f, 0.0f);
    glVertex3f(48.6f, 14.403f, 0.0f);
    glVertex3f(48.5333f, 14.403f, 0.0f);
    glVertex3f(48.4667f, 14.403f, 0.0f);
    glVertex3f(48.4f, 14.403f, 0.0f);
    glVertex3f(48.3333f, 14.403f, 0.0f);
    glVertex3f(48.2667f, 14.403f, 0.0f);
    glVertex3f(48.2f, 14.403f, 0.0f);
    glVertex3f(48.1333f, 14.403f, 0.0f);
    glVertex3f(48.0667f, 14.403f, 0.0f);
    glVertex3f(48.0f, 14.403f, 0.0f);
    glVertex3f(47.9333f, 14.403f, 0.0f);
    glVertex3f(47.8667f, 14.4776f, 0.0f);
    glVertex3f(47.8667f, 14.5522f, 0.0f);
    glVertex3f(47.8667f, 14.6269f, 0.0f);
    glVertex3f(47.8667f, 14.7015f, 0.0f);
    glVertex3f(47.8667f, 14.7761f, 0.0f);
    glVertex3f(47.8667f, 14.8507f, 0.0f);
    glVertex3f(47.8667f, 14.9254f, 0.0f);
    glVertex3f(47.9333f, 15.0f, 0.0f);
    glVertex3f(47.9333f, 15.1493f, 0.0f);
    glVertex3f(48.0f, 15.1493f, 0.0f);
    glVertex3f(48.0f, 15.2239f, 0.0f);
    glVertex3f(48.0f, 15.2985f, 0.0f);
    glVertex3f(48.0f, 15.3731f, 0.0f);
    glVertex3f(48.0f, 15.4478f, 0.0f);
    glVertex3f(48.0f, 15.5224f, 0.0f);
    glVertex3f(48.0f, 15.597f, 0.0f);
    glVertex3f(48.0f, 15.6716f, 0.0f);
    glVertex3f(48.0f, 15.7463f, 0.0f);
    glVertex3f(48.0f, 15.8209f, 0.0f);
    glVertex3f(48.0f, 15.8955f, 0.0f);
    glVertex3f(48.0f, 15.9701f, 0.0f);
    glVertex3f(48.0f, 16.0448f, 0.0f);
    glVertex3f(48.0f, 16.1194f, 0.0f);
    glVertex3f(48.0f, 16.194f, 0.0f);
    glVertex3f(48.0f, 16.2687f, 0.0f);
    glVertex3f(48.0f, 16.3433f, 0.0f);

    glEnd();



//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Tree Big Left Side 1  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.239, 0.553, 0.322);
    glVertex3f(0.6667f, 14.8507f, 0.0f);

    glVertex3f(0.8667f, 13.8806f, 0.0f);
    glVertex3f(0.9333f, 13.8806f, 0.0f);
    glVertex3f(1.0f, 13.8806f, 0.0f);
    glVertex3f(1.0667f, 13.8806f, 0.0f);
    glVertex3f(1.1333f, 13.9552f, 0.0f);
    glVertex3f(1.2f, 13.9552f, 0.0f);
    glVertex3f(1.2667f, 13.9552f, 0.0f);
    glVertex3f(1.3333f, 13.9552f, 0.0f);
    glVertex3f(1.4f, 14.0299f, 0.0f);
    glVertex3f(1.4667f, 14.0299f, 0.0f);
    glVertex3f(1.5333f, 14.0299f, 0.0f);
    glVertex3f(1.6f, 14.0299f, 0.0f);
    glVertex3f(1.6667f, 14.1045f, 0.0f);
    glVertex3f(1.7333f, 14.1791f, 0.0f);
    glVertex3f(1.8f, 14.1791f, 0.0f);
    glVertex3f(1.8f, 14.2537f, 0.0f);
    glVertex3f(1.8667f, 14.2537f, 0.0f);
    glVertex3f(1.9333f, 14.3284f, 0.0f);
    glVertex3f(2.0f, 14.3284f, 0.0f);
    glVertex3f(2.0667f, 14.403f, 0.0f);
    glVertex3f(2.0f, 14.403f, 0.0f);
    glVertex3f(1.9333f, 14.403f, 0.0f);
    glVertex3f(1.8667f, 14.4776f, 0.0f);
    glVertex3f(1.8f, 14.4776f, 0.0f);
    glVertex3f(1.7333f, 14.5522f, 0.0f);
    glVertex3f(1.6667f, 14.5522f, 0.0f);
    glVertex3f(1.7333f, 14.6269f, 0.0f);
    glVertex3f(1.8f, 14.7015f, 0.0f);
    glVertex3f(1.7333f, 14.7761f, 0.0f);
    glVertex3f(1.6667f, 14.7761f, 0.0f);
    glVertex3f(1.6f, 14.7761f, 0.0f);
    glVertex3f(1.6f, 14.8507f, 0.0f);
    glVertex3f(1.6f, 14.9254f, 0.0f);
    glVertex3f(1.6667f, 14.9254f, 0.0f);
    glVertex3f(1.6667f, 15.0f, 0.0f);
    glVertex3f(1.6667f, 15.0746f, 0.0f);
    glVertex3f(1.6667f, 15.1493f, 0.0f);
    glVertex3f(1.6f, 15.2239f, 0.0f);
    glVertex3f(1.5333f, 15.2239f, 0.0f);
    glVertex3f(1.4667f, 15.2239f, 0.0f);
    glVertex3f(1.4f, 15.2239f, 0.0f);
    glVertex3f(1.3333f, 15.2239f, 0.0f);
    glVertex3f(1.2667f, 15.2239f, 0.0f);
    glVertex3f(1.2667f, 15.2985f, 0.0f);
    glVertex3f(1.2667f, 15.3731f, 0.0f);
    glVertex3f(1.3333f, 15.5224f, 0.0f);
    glVertex3f(1.4f, 15.5224f, 0.0f);
    glVertex3f(1.4667f, 15.6716f, 0.0f);
    glVertex3f(1.4667f, 15.7463f, 0.0f);
    glVertex3f(1.4667f, 15.8209f, 0.0f);
    glVertex3f(1.4f, 15.8955f, 0.0f);
    glVertex3f(1.3333f, 15.8955f, 0.0f);
    glVertex3f(1.3333f, 15.9701f, 0.0f);
    glVertex3f(1.3333f, 16.0448f, 0.0f);
    glVertex3f(1.3333f, 16.1194f, 0.0f);
    glVertex3f(1.3333f, 16.194f, 0.0f);
    glVertex3f(1.2667f, 16.2687f, 0.0f);
    glVertex3f(1.2f, 16.2687f, 0.0f);
    glVertex3f(1.1333f, 16.2687f, 0.0f);
    glVertex3f(1.0667f, 16.2687f, 0.0f);
    glVertex3f(1.0f, 16.3433f, 0.0f);
    glVertex3f(1.0f, 16.4179f, 0.0f);
    glVertex3f(1.0667f, 16.5672f, 0.0f);
    glVertex3f(1.1333f, 16.6418f, 0.0f);
    glVertex3f(1.1333f, 16.7164f, 0.0f);
    glVertex3f(1.0667f, 16.791f, 0.0f);
    glVertex3f(1.0f, 16.791f, 0.0f);
    glVertex3f(0.9333f, 16.8657f, 0.0f);
    glVertex3f(0.8667f, 16.8657f, 0.0f);
    glVertex3f(0.8667f, 16.9403f, 0.0f);
    glVertex3f(0.9333f, 17.0149f, 0.0f);
    glVertex3f(0.9333f, 17.0896f, 0.0f);
    glVertex3f(1.0f, 17.0896f, 0.0f);
    glVertex3f(1.0f, 17.2388f, 0.0f);
    glVertex3f(1.0667f, 17.2388f, 0.0f);
    glVertex3f(1.0667f, 17.3134f, 0.0f);
    glVertex3f(1.0667f, 17.3881f, 0.0f);
    glVertex3f(1.0f, 17.4627f, 0.0f);
    glVertex3f(1.0f, 17.5373f, 0.0f);
    glVertex3f(0.9333f, 17.5373f, 0.0f);
    glVertex3f(0.9333f, 17.6119f, 0.0f);
    glVertex3f(0.8667f, 17.6119f, 0.0f);
    glVertex3f(0.8f, 17.6119f, 0.0f);
    glVertex3f(0.7333f, 17.6119f, 0.0f);
    glVertex3f(0.6667f, 17.6866f, 0.0f);
    glVertex3f(0.6f, 17.6119f, 0.0f);
    glVertex3f(0.5333f, 17.5373f, 0.0f);
    glVertex3f(0.5333f, 17.4627f, 0.0f);
    glVertex3f(0.4667f, 17.3881f, 0.0f);
    glVertex3f(0.4f, 17.2388f, 0.0f);
    glVertex3f(0.3333f, 17.1642f, 0.0f);
    glVertex3f(0.3333f, 17.0896f, 0.0f);
    glVertex3f(0.3333f, 17.0149f, 0.0f);
    glVertex3f(0.4f, 16.9403f, 0.0f);
    glVertex3f(0.4667f, 16.9403f, 0.0f);
    glVertex3f(0.5333f, 16.8657f, 0.0f);
    glVertex3f(0.5333f, 16.791f, 0.0f);
    glVertex3f(0.6f, 16.791f, 0.0f);
    glVertex3f(0.6f, 16.7164f, 0.0f);
    glVertex3f(0.6f, 16.6418f, 0.0f);
    glVertex3f(0.5333f, 16.6418f, 0.0f);
    glVertex3f(0.4667f, 16.6418f, 0.0f);
    glVertex3f(0.4f, 16.6418f, 0.0f);
    glVertex3f(0.3333f, 16.5672f, 0.0f);
    glVertex3f(0.2667f, 16.4925f, 0.0f);
    glVertex3f(0.2f, 16.4925f, 0.0f);
    glVertex3f(0.1333f, 16.4179f, 0.0f);
    glVertex3f(0.0667f, 16.4179f, 0.0f);
    glVertex3f(0.0667f, 16.3433f, 0.0f);
    glVertex3f(0.0667f, 16.2687f, 0.0f);
    glVertex3f(0.0667f, 16.194f, 0.0f);
    glVertex3f(0.0f, 16.194f, 0.0f);
    glVertex3f(-0.0667f, 16.194f, 0.0f);
    glVertex3f(-0.1333f, 16.194f, 0.0f);
    glVertex3f(-0.1333f, 16.1194f, 0.0f);
    glVertex3f(-0.2f, 16.1194f, 0.0f);
    glVertex3f(-0.2667f, 16.0448f, 0.0f);
    glVertex3f(-0.3333f, 15.9701f, 0.0f);
    glVertex3f(-0.3333f, 15.8955f, 0.0f);
    glVertex3f(-0.3333f, 15.8209f, 0.0f);
    glVertex3f(-0.3333f, 15.6716f, 0.0f);
    glVertex3f(-0.3333f, 15.597f, 0.0f);
    glVertex3f(-0.3333f, 15.5224f, 0.0f);
    glVertex3f(-0.3333f, 15.4478f, 0.0f);
    glVertex3f(-0.3333f, 15.3731f, 0.0f);
    glVertex3f(-0.3333f, 15.2985f, 0.0f);
    glVertex3f(-0.3333f, 15.2239f, 0.0f);
    glVertex3f(-0.3333f, 15.1493f, 0.0f);
    glVertex3f(-0.4f, 15.0746f, 0.0f);
    glVertex3f(-0.4667f, 15.0f, 0.0f);
    glVertex3f(-0.5333f, 14.9254f, 0.0f);
    glVertex3f(-0.6f, 14.8507f, 0.0f);
    glVertex3f(-0.6667f, 14.8507f, 0.0f);
    glVertex3f(-0.6667f, 14.7761f, 0.0f);
    glVertex3f(-0.6667f, 14.7015f, 0.0f);
    glVertex3f(-0.7333f, 14.7015f, 0.0f);
    glVertex3f(-0.7333f, 14.6269f, 0.0f);
    glVertex3f(-0.8f, 14.6269f, 0.0f);
    glVertex3f(-0.8667f, 14.6269f, 0.0f);
    glVertex3f(-0.8667f, 14.5522f, 0.0f);
    glVertex3f(-0.8f, 14.4776f, 0.0f);
    glVertex3f(-0.7333f, 14.403f, 0.0f);
    glVertex3f(-0.6667f, 14.403f, 0.0f);
    glVertex3f(-0.5333f, 14.403f, 0.0f);
    glVertex3f(-0.4667f, 14.3284f, 0.0f);
    glVertex3f(-0.5333f, 14.2537f, 0.0f);
    glVertex3f(-0.6667f, 14.2537f, 0.0f);
    glVertex3f(-0.7333f, 14.1791f, 0.0f);
    glVertex3f(-0.8f, 14.1791f, 0.0f);
    glVertex3f(-0.7333f, 14.1791f, 0.0f);
    glVertex3f(-0.6667f, 14.1791f, 0.0f);
    glVertex3f(-0.6f, 14.1791f, 0.0f);
    glVertex3f(-0.4667f, 14.1791f, 0.0f);
    glVertex3f(-0.4f, 14.1791f, 0.0f);
    glVertex3f(-0.3333f, 14.1791f, 0.0f);
    glVertex3f(-0.2667f, 14.1045f, 0.0f);
    glVertex3f(-0.3333f, 14.0299f, 0.0f);
    glVertex3f(-0.4f, 14.0299f, 0.0f);
    glVertex3f(-0.4667f, 14.0299f, 0.0f);
    glVertex3f(-0.5333f, 14.0299f, 0.0f);
    glVertex3f(-0.6f, 13.9552f, 0.0f);
    glVertex3f(-0.6f, 13.8806f, 0.0f);
    glVertex3f(-0.6f, 13.806f, 0.0f);
    glVertex3f(-0.5333f, 13.7313f, 0.0f);
    glVertex3f(-0.4667f, 13.7313f, 0.0f);
    glVertex3f(-0.4f, 13.7313f, 0.0f);
    glVertex3f(-0.3333f, 13.7313f, 0.0f);
    glVertex3f(-0.2667f, 13.7313f, 0.0f);
    glVertex3f(-0.2f, 13.7313f, 0.0f);
    glVertex3f(-0.1333f, 13.7313f, 0.0f);
    glVertex3f(-0.0667f, 13.7313f, 0.0f);
    glVertex3f(0.0f, 13.7313f, 0.0f);
    glVertex3f(0.0667f, 13.7313f, 0.0f);
    glVertex3f(0.1333f, 13.7313f, 0.0f);
    glVertex3f(0.2f, 13.7313f, 0.0f);
    glVertex3f(0.2667f, 13.7313f, 0.0f);
    glVertex3f(0.3333f, 13.7313f, 0.0f);
    glVertex3f(0.4f, 13.7313f, 0.0f);
    glVertex3f(0.4667f, 13.7313f, 0.0f);
    glVertex3f(0.5333f, 13.7313f, 0.0f);
    glVertex3f(0.6f, 13.7313f, 0.0f);
    glVertex3f(0.6f, 13.806f, 0.0f);
    glVertex3f(0.6667f, 13.806f, 0.0f);
    glVertex3f(0.7333f, 13.806f, 0.0f);
    glVertex3f(0.8f, 13.806f, 0.0f);
    glVertex3f(0.8667f, 13.806f, 0.0f);
    glVertex3f(0.9333f, 13.806f, 0.0f);
    glVertex3f(1.0f, 13.8806f, 0.0f);
    glVertex3f(1.0667f, 13.8806f, 0.0f);
    glVertex3f(1.0667f, 13.9552f, 0.0f);
    glVertex3f(1.1333f, 14.0299f, 0.0f);
    glVertex3f(1.2f, 14.0299f, 0.0f);
    glVertex3f(1.2667f, 14.0299f, 0.0f);
    glVertex3f(1.3333f, 14.0299f, 0.0f);
    glVertex3f(1.4667f, 14.1045f, 0.0f);


    glEnd();



    //¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ Big Tree Left side ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glColor3f(0.51, 0.647, 0.325);  // 1
    drawCircle2(4.4667, 14.6716f, 1.0);

    glColor3f(0.51, 0.647, 0.325);
    drawCircle2(4.4667f, 15.9403f, 0.8f);

    glColor3f(0.51, 0.647, 0.325);
    drawCircle2(4.4667f, 16.9403f, 0.5f);

    glColor3f(0.392, 0.506, 0.247);  // 2
    drawCircle2(2.6667f, 14.4776f, 1.0f);

    glColor3f(0.392, 0.506, 0.247);
    drawCircle2(2.6667f, 15.597f, 0.7f);

    glColor3f(0.392, 0.506, 0.247);
    drawCircle2(2.6667f, 16.597f, 0.5f);



    glBegin(GL_LINES);  // big  tree left side Kando

    glColor3f(0.122, 0.235, 0.267);


    glVertex3f(4.5333f, 14.5672f, 0.0f);
    glVertex3f(4.6f, 12.9104f, 0.0f);

    glVertex3f(2.6667f, 14.4776f, 0.0f);
    glVertex3f(2.6667f, 12.876f, 0.0f);

    glVertex3f(9.3333f, 15.0746f, 0.0f);
    glVertex3f(9.4f, 12.9851f, 0.0f);

    glVertex3f(7.0f, 15.9701f, 0.0f);
    glVertex3f(6.9333f, 12.9851f, 0.0f);


    glEnd();



//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Tree Big Left Side 4  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.51, 0.647, 0.325);
    glVertex3f(9.2667f, 15.1493f, 0.0f);


    glVertex3f(9.3333f, 14.2537f, 0.0f);
    glVertex3f(9.2667f, 14.1791f, 0.0f);
    glVertex3f(9.2f, 14.1045f, 0.0f);
    glVertex3f(9.1333f, 14.1045f, 0.0f);
    glVertex3f(9.0667f, 14.1045f, 0.0f);
    glVertex3f(9.0f, 14.1045f, 0.0f);
    glVertex3f(8.9333f, 14.1045f, 0.0f);
    glVertex3f(8.8667f, 14.0299f, 0.0f);
    glVertex3f(8.8f, 14.0299f, 0.0f);
    glVertex3f(8.7333f, 14.0299f, 0.0f);
    glVertex3f(8.6f, 13.9552f, 0.0f);
    glVertex3f(8.5333f, 13.9552f, 0.0f);
    glVertex3f(8.4667f, 13.9552f, 0.0f);
    glVertex3f(8.4f, 13.8806f, 0.0f);
    glVertex3f(8.3333f, 13.8806f, 0.0f);
    glVertex3f(8.2667f, 13.8806f, 0.0f);
    glVertex3f(8.2f, 13.8806f, 0.0f);
    glVertex3f(8.1333f, 13.8806f, 0.0f);
    glVertex3f(8.0667f, 13.8806f, 0.0f);
    glVertex3f(8.0f, 13.9552f, 0.0f);
    glVertex3f(7.9333f, 13.9552f, 0.0f);
    glVertex3f(7.8667f, 14.0299f, 0.0f);
    glVertex3f(7.8667f, 14.1045f, 0.0f);
    glVertex3f(7.8f, 14.1791f, 0.0f);
    glVertex3f(7.8f, 14.2537f, 0.0f);
    glVertex3f(7.8f, 14.3284f, 0.0f);
    glVertex3f(7.8f, 14.403f, 0.0f);
    glVertex3f(7.8f, 14.4776f, 0.0f);
    glVertex3f(7.8f, 14.5522f, 0.0f);
    glVertex3f(7.7333f, 14.5522f, 0.0f);
    glVertex3f(7.7333f, 14.6269f, 0.0f);
    glVertex3f(7.7333f, 14.7015f, 0.0f);
    glVertex3f(7.7333f, 14.7761f, 0.0f);
    glVertex3f(7.7333f, 14.8507f, 0.0f);
    glVertex3f(7.8f, 14.9254f, 0.0f);
    glVertex3f(7.8667f, 14.9254f, 0.0f);
    glVertex3f(7.9333f, 14.9254f, 0.0f);
    glVertex3f(8.0f, 14.9254f, 0.0f);
    glVertex3f(8.0667f, 14.9254f, 0.0f);
    glVertex3f(8.0667f, 15.0f, 0.0f);
    glVertex3f(8.1333f, 15.0f, 0.0f);
    glVertex3f(8.2f, 15.0f, 0.0f);
    glVertex3f(8.2667f, 15.0f, 0.0f);
    glVertex3f(8.2f, 15.0746f, 0.0f);
    glVertex3f(8.1333f, 15.0746f, 0.0f);
    glVertex3f(8.0f, 15.1493f, 0.0f);
    glVertex3f(7.9333f, 15.1493f, 0.0f);
    glVertex3f(7.8667f, 15.1493f, 0.0f);
    glVertex3f(7.8f, 15.1493f, 0.0f);
    glVertex3f(7.8f, 15.2239f, 0.0f);
    glVertex3f(7.7333f, 15.2239f, 0.0f);
    glVertex3f(7.7333f, 15.2985f, 0.0f);
    glVertex3f(7.7333f, 15.3731f, 0.0f);
    glVertex3f(7.7333f, 15.4478f, 0.0f);
    glVertex3f(7.7333f, 15.5224f, 0.0f);
    glVertex3f(7.7333f, 15.597f, 0.0f);
    glVertex3f(7.7333f, 15.6716f, 0.0f);
    glVertex3f(7.7333f, 15.7463f, 0.0f);
    glVertex3f(7.7333f, 15.8209f, 0.0f);
    glVertex3f(7.7333f, 15.9701f, 0.0f);
    glVertex3f(7.7333f, 16.0448f, 0.0f);
    glVertex3f(7.7333f, 16.1194f, 0.0f);
    glVertex3f(7.7333f, 16.194f, 0.0f);
    glVertex3f(7.7333f, 16.2687f, 0.0f);
    glVertex3f(7.7333f, 16.3433f, 0.0f);
    glVertex3f(7.8f, 16.4179f, 0.0f);
    glVertex3f(7.8667f, 16.4179f, 0.0f);
    glVertex3f(7.9333f, 16.4179f, 0.0f);
    glVertex3f(8.0f, 16.4925f, 0.0f);
    glVertex3f(8.0667f, 16.4925f, 0.0f);
    glVertex3f(8.1333f, 16.4925f, 0.0f);
    glVertex3f(8.2f, 16.4925f, 0.0f);
    glVertex3f(8.2667f, 16.4925f, 0.0f);
    glVertex3f(8.3333f, 16.4925f, 0.0f);
    glVertex3f(8.4f, 16.4925f, 0.0f);
    glVertex3f(8.4667f, 16.4925f, 0.0f);
    glVertex3f(8.5333f, 16.4925f, 0.0f);
    glVertex3f(8.6f, 16.4925f, 0.0f);
    glVertex3f(8.6f, 16.5672f, 0.0f);
    glVertex3f(8.6f, 16.6418f, 0.0f);
    glVertex3f(8.5333f, 16.7164f, 0.0f);
    glVertex3f(8.5333f, 16.791f, 0.0f);
    glVertex3f(8.5333f, 16.8657f, 0.0f);
    glVertex3f(8.5333f, 16.9403f, 0.0f);
    glVertex3f(8.4667f, 16.9403f, 0.0f);
    glVertex3f(8.4667f, 17.0149f, 0.0f);
    glVertex3f(8.4667f, 17.0896f, 0.0f);
    glVertex3f(8.4f, 17.2388f, 0.0f);
    glVertex3f(8.4f, 17.3134f, 0.0f);
    glVertex3f(8.4f, 17.3881f, 0.0f);
    glVertex3f(8.4f, 17.4627f, 0.0f);
    glVertex3f(8.4f, 17.5373f, 0.0f);
    glVertex3f(8.4f, 17.6119f, 0.0f);
    glVertex3f(8.4f, 17.6866f, 0.0f);
    glVertex3f(8.4f, 17.7612f, 0.0f);
    glVertex3f(8.4f, 17.8358f, 0.0f);
    glVertex3f(8.4667f, 17.9104f, 0.0f);
    glVertex3f(8.5333f, 17.9851f, 0.0f);
    glVertex3f(8.6f, 17.9851f, 0.0f);
    glVertex3f(8.6667f, 17.9851f, 0.0f);
    glVertex3f(8.8f, 18.0597f, 0.0f);
    glVertex3f(8.8667f, 18.0597f, 0.0f);
    glVertex3f(8.9333f, 18.0597f, 0.0f);
    glVertex3f(9.0f, 18.0597f, 0.0f);
    glVertex3f(9.0667f, 18.0597f, 0.0f);
    glVertex3f(9.1333f, 18.0597f, 0.0f);
    glVertex3f(9.2f, 18.1343f, 0.0f);
    glVertex3f(9.2667f, 18.1343f, 0.0f);
    glVertex3f(9.3333f, 18.1343f, 0.0f);
    glVertex3f(9.4f, 18.1343f, 0.0f);
    glVertex3f(9.4667f, 18.1343f, 0.0f);
    glVertex3f(9.5333f, 18.1343f, 0.0f);
    glVertex3f(9.6f, 18.1343f, 0.0f);
    glVertex3f(9.6667f, 18.0597f, 0.0f);
    glVertex3f(9.7333f, 18.0597f, 0.0f);
    glVertex3f(9.8667f, 17.9851f, 0.0f);
    glVertex3f(9.8667f, 17.9104f, 0.0f);
    glVertex3f(9.9333f, 17.7612f, 0.0f);
    glVertex3f(9.9333f, 17.6866f, 0.0f);
    glVertex3f(10.0f, 17.4627f, 0.0f);
    glVertex3f(10.0f, 17.3881f, 0.0f);
    glVertex3f(10.0f, 17.2388f, 0.0f);
    glVertex3f(10.0f, 17.1642f, 0.0f);
    glVertex3f(10.0f, 17.0896f, 0.0f);
    glVertex3f(10.0f, 17.0149f, 0.0f);
    glVertex3f(10.0f, 16.9403f, 0.0f);
    glVertex3f(10.0f, 16.8657f, 0.0f);
    glVertex3f(10.0f, 16.791f, 0.0f);
    glVertex3f(10.0f, 16.7164f, 0.0f);
    glVertex3f(9.9333f, 16.7164f, 0.0f);
    glVertex3f(9.8f, 16.7164f, 0.0f);
    glVertex3f(9.7333f, 16.7164f, 0.0f);
    glVertex3f(9.6f, 16.6418f, 0.0f);
    glVertex3f(9.5333f, 16.6418f, 0.0f);
    glVertex3f(9.4f, 16.6418f, 0.0f);
    glVertex3f(9.4f, 16.5672f, 0.0f);
    glVertex3f(9.3333f, 16.5672f, 0.0f);
    glVertex3f(9.4f, 16.5672f, 0.0f);
    glVertex3f(9.4667f, 16.5672f, 0.0f);
    glVertex3f(9.5333f, 16.5672f, 0.0f);
    glVertex3f(9.6f, 16.5672f, 0.0f);
    glVertex3f(9.6667f, 16.4925f, 0.0f);
    glVertex3f(9.7333f, 16.4925f, 0.0f);
    glVertex3f(9.8f, 16.4925f, 0.0f);
    glVertex3f(9.8667f, 16.4925f, 0.0f);
    glVertex3f(9.9333f, 16.4925f, 0.0f);
    glVertex3f(10.0f, 16.4925f, 0.0f);
    glVertex3f(10.0667f, 16.4179f, 0.0f);
    glVertex3f(10.1333f, 16.4179f, 0.0f);
    glVertex3f(10.2f, 16.3433f, 0.0f);
    glVertex3f(10.2667f, 16.2687f, 0.0f);
    glVertex3f(10.3333f, 16.194f, 0.0f);
    glVertex3f(10.4f, 16.194f, 0.0f);
    glVertex3f(10.4f, 16.1194f, 0.0f);
    glVertex3f(10.4667f, 16.0448f, 0.0f);
    glVertex3f(10.4667f, 15.9701f, 0.0f);
    glVertex3f(10.4667f, 15.8955f, 0.0f);
    glVertex3f(10.4667f, 15.8209f, 0.0f);
    glVertex3f(10.4667f, 15.7463f, 0.0f);
    glVertex3f(10.5333f, 15.6716f, 0.0f);
    glVertex3f(10.5333f, 15.597f, 0.0f);
    glVertex3f(10.5333f, 15.5224f, 0.0f);
    glVertex3f(10.5333f, 15.4478f, 0.0f);
    glVertex3f(10.4667f, 15.4478f, 0.0f);
    glVertex3f(10.4f, 15.4478f, 0.0f);
    glVertex3f(10.3333f, 15.4478f, 0.0f);
    glVertex3f(10.2667f, 15.3731f, 0.0f);
    glVertex3f(10.2f, 15.3731f, 0.0f);
    glVertex3f(10.1333f, 15.3731f, 0.0f);
    glVertex3f(10.0667f, 15.3731f, 0.0f);
    glVertex3f(10.0f, 15.3731f, 0.0f);
    glVertex3f(10.0667f, 15.3731f, 0.0f);
    glVertex3f(10.1333f, 15.3731f, 0.0f);
    glVertex3f(10.2f, 15.3731f, 0.0f);
    glVertex3f(10.2667f, 15.3731f, 0.0f);
    glVertex3f(10.3333f, 15.3731f, 0.0f);
    glVertex3f(10.4f, 15.3731f, 0.0f);
    glVertex3f(10.4667f, 15.3731f, 0.0f);
    glVertex3f(10.5333f, 15.3731f, 0.0f);
    glVertex3f(10.6f, 15.2985f, 0.0f);
    glVertex3f(10.6667f, 15.2985f, 0.0f);
    glVertex3f(10.7333f, 15.2985f, 0.0f);
    glVertex3f(10.8f, 15.2985f, 0.0f);
    glVertex3f(10.8667f, 15.2239f, 0.0f);
    glVertex3f(10.9333f, 15.2239f, 0.0f);
    glVertex3f(11.0667f, 15.1493f, 0.0f);
    glVertex3f(11.0667f, 15.0746f, 0.0f);
    glVertex3f(11.0667f, 15.0f, 0.0f);
    glVertex3f(11.0667f, 14.9254f, 0.0f);
    glVertex3f(11.0667f, 14.8507f, 0.0f);
    glVertex3f(11.0667f, 14.7761f, 0.0f);
    glVertex3f(11.0667f, 14.7015f, 0.0f);
    glVertex3f(11.0667f, 14.5522f, 0.0f);
    glVertex3f(11.0f, 14.5522f, 0.0f);
    glVertex3f(10.9333f, 14.4776f, 0.0f);
    glVertex3f(10.9333f, 14.403f, 0.0f);
    glVertex3f(10.8667f, 14.3284f, 0.0f);
    glVertex3f(10.8f, 14.2537f, 0.0f);
    glVertex3f(10.7333f, 14.2537f, 0.0f);
    glVertex3f(10.7333f, 14.1791f, 0.0f);
    glVertex3f(10.7333f, 14.1045f, 0.0f);
    glVertex3f(10.6667f, 14.1045f, 0.0f);
    glVertex3f(10.6f, 14.1045f, 0.0f);
    glVertex3f(10.6f, 14.0299f, 0.0f);
    glVertex3f(10.5333f, 14.0299f, 0.0f);
    glVertex3f(10.4667f, 14.0299f, 0.0f);
    glVertex3f(10.4f, 14.0299f, 0.0f);
    glVertex3f(10.3333f, 14.0299f, 0.0f);
    glVertex3f(10.2667f, 14.0299f, 0.0f);
    glVertex3f(10.2f, 14.0299f, 0.0f);
    glVertex3f(10.1333f, 14.0299f, 0.0f);
    glVertex3f(10.0667f, 14.0299f, 0.0f);
    glVertex3f(10.0f, 14.0299f, 0.0f);
    glVertex3f(9.9333f, 14.0299f, 0.0f);
    glVertex3f(9.8667f, 14.0299f, 0.0f);
    glVertex3f(9.8f, 14.0299f, 0.0f);
    glVertex3f(9.7333f, 14.0299f, 0.0f);
    glVertex3f(9.6667f, 14.0299f, 0.0f);
    glVertex3f(9.6f, 14.0299f, 0.0f);
    glVertex3f(9.5333f, 14.0299f, 0.0f);
    glVertex3f(9.4667f, 14.0299f, 0.0f);
    glVertex3f(9.4f, 14.0299f, 0.0f);
    glVertex3f(9.4f, 14.1045f, 0.0f);
    glVertex3f(9.3333f, 14.1045f, 0.0f);
    glVertex3f(9.3333f, 14.1791f, 0.0f);
    glVertex3f(9.2667f, 14.1791f, 0.0f);


    glEnd();


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Tree Big Left Side 4  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.388, 0.502, 0.243);
    glVertex3f(6.9333f, 16.4179f, 0.0f);


    glVertex3f(6.3333f, 15.4478f, 0.0f);
    glVertex3f(6.2667f, 15.5224f, 0.0f);
    glVertex3f(6.2f, 15.597f, 0.0f);
    glVertex3f(6.1333f, 15.597f, 0.0f);
    glVertex3f(6.0f, 15.6716f, 0.0f);
    glVertex3f(5.9333f, 15.6716f, 0.0f);
    glVertex3f(5.8667f, 15.7463f, 0.0f);
    glVertex3f(5.8f, 15.7463f, 0.0f);
    glVertex3f(5.7333f, 15.8209f, 0.0f);
    glVertex3f(5.6667f, 15.8209f, 0.0f);
    glVertex3f(5.6f, 15.9701f, 0.0f);
    glVertex3f(5.5333f, 15.9701f, 0.0f);
    glVertex3f(5.4667f, 16.1194f, 0.0f);
    glVertex3f(5.4667f, 16.194f, 0.0f);
    glVertex3f(5.4667f, 16.2687f, 0.0f);
    glVertex3f(5.4667f, 16.3433f, 0.0f);
    glVertex3f(5.4667f, 16.4179f, 0.0f);
    glVertex3f(5.4667f, 16.4925f, 0.0f);
    glVertex3f(5.5333f, 16.6418f, 0.0f);
    glVertex3f(5.5333f, 16.7164f, 0.0f);
    glVertex3f(5.5333f, 16.8657f, 0.0f);
    glVertex3f(5.6f, 16.9403f, 0.0f);
    glVertex3f(5.6f, 17.0149f, 0.0f);
    glVertex3f(5.6f, 17.0896f, 0.0f);
    glVertex3f(5.6667f, 17.0896f, 0.0f);
    glVertex3f(5.7333f, 17.0896f, 0.0f);
    glVertex3f(5.8f, 17.1642f, 0.0f);
    glVertex3f(5.8667f, 17.1642f, 0.0f);
    glVertex3f(6.0f, 17.1642f, 0.0f);
    glVertex3f(6.0667f, 17.1642f, 0.0f);
    glVertex3f(6.1333f, 17.1642f, 0.0f);
    glVertex3f(6.2f, 17.1642f, 0.0f);
    glVertex3f(6.1333f, 17.1642f, 0.0f);
    glVertex3f(6.1333f, 17.2388f, 0.0f);
    glVertex3f(6.0667f, 17.3881f, 0.0f);
    glVertex3f(6.0667f, 17.4627f, 0.0f);
    glVertex3f(6.0667f, 17.5373f, 0.0f);
    glVertex3f(6.0667f, 17.6866f, 0.0f);
    glVertex3f(6.0667f, 17.7612f, 0.0f);
    glVertex3f(6.0667f, 17.8358f, 0.0f);
    glVertex3f(6.0667f, 17.9104f, 0.0f);
    glVertex3f(6.1333f, 17.9851f, 0.0f);
    glVertex3f(6.2f, 17.9851f, 0.0f);
    glVertex3f(6.2667f, 17.9851f, 0.0f);
    glVertex3f(6.3333f, 17.9851f, 0.0f);
    glVertex3f(6.4667f, 18.0597f, 0.0f);
    glVertex3f(6.5333f, 18.0597f, 0.0f);
    glVertex3f(6.6f, 18.0597f, 0.0f);
    glVertex3f(6.6667f, 18.0597f, 0.0f);
    glVertex3f(6.7333f, 18.0597f, 0.0f);
    glVertex3f(6.8f, 18.1343f, 0.0f);
    glVertex3f(6.7333f, 18.209f, 0.0f);
    glVertex3f(6.7333f, 18.2836f, 0.0f);
    glVertex3f(6.7333f, 18.3582f, 0.0f);
    glVertex3f(6.7333f, 18.4328f, 0.0f);
    glVertex3f(6.7333f, 18.5075f, 0.0f);
    glVertex3f(6.7333f, 18.5821f, 0.0f);
    glVertex3f(6.7333f, 18.6567f, 0.0f);
    glVertex3f(6.7333f, 18.7313f, 0.0f);
    glVertex3f(6.7333f, 18.806f, 0.0f);
    glVertex3f(6.7333f, 18.8806f, 0.0f);
    glVertex3f(6.8f, 18.9552f, 0.0f);
    glVertex3f(6.8f, 19.0299f, 0.0f);
    glVertex3f(6.8f, 19.1045f, 0.0f);
    glVertex3f(6.8667f, 19.1791f, 0.0f);
    glVertex3f(6.8667f, 19.2537f, 0.0f);
    glVertex3f(6.9333f, 19.2537f, 0.0f);
    glVertex3f(7.0f, 19.3284f, 0.0f);
    glVertex3f(7.0667f, 19.3284f, 0.0f);
    glVertex3f(7.1333f, 19.3284f, 0.0f);
    glVertex3f(7.2f, 19.3284f, 0.0f);
    glVertex3f(7.2667f, 19.3284f, 0.0f);
    glVertex3f(7.3333f, 19.3284f, 0.0f);
    glVertex3f(7.3333f, 19.403f, 0.0f);
    glVertex3f(7.4f, 19.403f, 0.0f);
    glVertex3f(7.4667f, 19.403f, 0.0f);
    glVertex3f(7.5333f, 19.403f, 0.0f);
    glVertex3f(7.6f, 19.4776f, 0.0f);
    glVertex3f(7.5333f, 19.403f, 0.0f);
    glVertex3f(7.4667f, 19.403f, 0.0f);
    glVertex3f(7.4f, 19.403f, 0.0f);
    glVertex3f(7.2667f, 19.3284f, 0.0f);
    glVertex3f(7.2667f, 19.2537f, 0.0f);
    glVertex3f(7.2f, 19.2537f, 0.0f);
    glVertex3f(7.2f, 19.1791f, 0.0f);
    glVertex3f(7.0667f, 19.1791f, 0.0f);
    glVertex3f(7.1333f, 19.1045f, 0.0f);
    glVertex3f(7.2f, 19.0299f, 0.0f);
    glVertex3f(7.2667f, 18.9552f, 0.0f);
    glVertex3f(7.3333f, 18.9552f, 0.0f);
    glVertex3f(7.4f, 18.8806f, 0.0f);
    glVertex3f(7.4f, 18.806f, 0.0f);
    glVertex3f(7.5333f, 18.806f, 0.0f);
    glVertex3f(7.5333f, 18.7313f, 0.0f);
    glVertex3f(7.6f, 18.7313f, 0.0f);
    glVertex3f(7.6f, 18.6567f, 0.0f);
    glVertex3f(7.6f, 18.5821f, 0.0f);
    glVertex3f(7.5333f, 18.5075f, 0.0f);
    glVertex3f(7.5333f, 18.4328f, 0.0f);
    glVertex3f(7.5333f, 18.3582f, 0.0f);
    glVertex3f(7.5333f, 18.2836f, 0.0f);
    glVertex3f(7.5333f, 18.209f, 0.0f);
    glVertex3f(7.4667f, 18.0597f, 0.0f);
    glVertex3f(7.4667f, 17.9851f, 0.0f);
    glVertex3f(7.4f, 17.9104f, 0.0f);
    glVertex3f(7.2667f, 17.9104f, 0.0f);
    glVertex3f(7.1333f, 17.8358f, 0.0f);
    glVertex3f(7.0667f, 17.8358f, 0.0f);
    glVertex3f(7.2f, 17.8358f, 0.0f);
    glVertex3f(7.2667f, 17.7612f, 0.0f);
    glVertex3f(7.2667f, 17.6866f, 0.0f);
    glVertex3f(7.3333f, 17.6866f, 0.0f);
    glVertex3f(7.4f, 17.6119f, 0.0f);
    glVertex3f(7.4667f, 17.6119f, 0.0f);
    glVertex3f(7.5333f, 17.5373f, 0.0f);
    glVertex3f(7.5333f, 17.4627f, 0.0f);
    glVertex3f(7.5333f, 17.3881f, 0.0f);
    glVertex3f(7.5333f, 17.3134f, 0.0f);
    glVertex3f(7.4667f, 17.2388f, 0.0f);
    glVertex3f(7.4667f, 17.1642f, 0.0f);
    glVertex3f(7.4667f, 17.0896f, 0.0f);
    glVertex3f(7.4667f, 17.0149f, 0.0f);
    glVertex3f(7.4667f, 16.9403f, 0.0f);
    glVertex3f(7.4667f, 16.8657f, 0.0f);
    glVertex3f(7.4667f, 16.791f, 0.0f);
    glVertex3f(7.5333f, 16.7164f, 0.0f);
    glVertex3f(7.6f, 16.7164f, 0.0f);
    glVertex3f(7.6667f, 16.7164f, 0.0f);
    glVertex3f(7.7333f, 16.6418f, 0.0f);
    glVertex3f(7.8667f, 16.5672f, 0.0f);
    glVertex3f(7.8667f, 16.4925f, 0.0f);
    glVertex3f(7.8667f, 16.4179f, 0.0f);
    glVertex3f(7.8667f, 16.3433f, 0.0f);
    glVertex3f(7.8667f, 16.2687f, 0.0f);
    glVertex3f(7.8667f, 16.194f, 0.0f);
    glVertex3f(7.8667f, 16.1194f, 0.0f);
    glVertex3f(7.8f, 16.0448f, 0.0f);
    glVertex3f(7.8f, 15.9701f, 0.0f);
    glVertex3f(7.7333f, 15.9701f, 0.0f);
    glVertex3f(7.7333f, 15.8955f, 0.0f);
    glVertex3f(7.6667f, 15.8955f, 0.0f);
    glVertex3f(7.6f, 15.8955f, 0.0f);
    glVertex3f(7.5333f, 15.8955f, 0.0f);
    glVertex3f(7.4667f, 15.8955f, 0.0f);
    glVertex3f(7.4f, 15.8955f, 0.0f);
    glVertex3f(7.4667f, 15.8955f, 0.0f);
    glVertex3f(7.5333f, 15.8209f, 0.0f);
    glVertex3f(7.6f, 15.8209f, 0.0f);
    glVertex3f(7.6667f, 15.8209f, 0.0f);
    glVertex3f(7.6667f, 15.7463f, 0.0f);
    glVertex3f(7.7333f, 15.7463f, 0.0f);
    glVertex3f(7.7333f, 15.6716f, 0.0f);
    glVertex3f(7.8f, 15.6716f, 0.0f);
    glVertex3f(7.8667f, 15.597f, 0.0f);
    glVertex3f(7.8667f, 15.5224f, 0.0f);
    glVertex3f(7.8667f, 15.4478f, 0.0f);
    glVertex3f(7.9333f, 15.3731f, 0.0f);
    glVertex3f(7.9333f, 15.2985f, 0.0f);
    glVertex3f(7.9333f, 15.2239f, 0.0f);
    glVertex3f(7.9333f, 15.1493f, 0.0f);
    glVertex3f(7.9333f, 15.0746f, 0.0f);
    glVertex3f(7.9333f, 15.0f, 0.0f);
    glVertex3f(7.9333f, 14.9254f, 0.0f);
    glVertex3f(7.8667f, 14.8507f, 0.0f);
    glVertex3f(7.8f, 14.8507f, 0.0f);
    glVertex3f(7.6667f, 14.8507f, 0.0f);
    glVertex3f(7.6f, 14.8507f, 0.0f);
    glVertex3f(7.5333f, 14.8507f, 0.0f);
    glVertex3f(7.4667f, 14.8507f, 0.0f);
    glVertex3f(7.4f, 14.8507f, 0.0f);
    glVertex3f(7.3333f, 14.8507f, 0.0f);
    glVertex3f(7.2667f, 14.8507f, 0.0f);
    glVertex3f(7.2f, 14.8507f, 0.0f);
    glVertex3f(7.0667f, 14.9254f, 0.0f);
    glVertex3f(7.0f, 14.9254f, 0.0f);
    glVertex3f(6.9333f, 14.9254f, 0.0f);
    glVertex3f(6.8667f, 14.9254f, 0.0f);
    glVertex3f(6.8f, 14.9254f, 0.0f);
    glVertex3f(6.7333f, 14.9254f, 0.0f);
    glVertex3f(6.6667f, 14.9254f, 0.0f);
    glVertex3f(6.6f, 14.9254f, 0.0f);
    glVertex3f(6.5333f, 14.9254f, 0.0f);
    glVertex3f(6.4667f, 14.9254f, 0.0f);
    glVertex3f(6.4f, 14.9254f, 0.0f);
    glVertex3f(6.3333f, 14.9254f, 0.0f);
    glVertex3f(6.2667f, 14.9254f, 0.0f);
    glVertex3f(6.2f, 15.0f, 0.0f);
    glVertex3f(6.1333f, 15.0746f, 0.0f);
    glVertex3f(6.1333f, 15.1493f, 0.0f);
    glVertex3f(6.1333f, 15.2239f, 0.0f);
    glVertex3f(6.1333f, 15.2985f, 0.0f);
    glVertex3f(6.2f, 15.3731f, 0.0f);
    glVertex3f(6.2667f, 15.3731f, 0.0f);
    glVertex3f(6.2667f, 15.4478f, 0.0f);
    glVertex3f(6.3333f, 15.4478f, 0.0f);
    glVertex3f(6.4f, 15.4478f, 0.0f);
    glVertex3f(6.4667f, 15.4478f, 0.0f);


    glEnd();


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Tree Big Right Side 1  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.196, 0.482, 0.267);
    glVertex3f(43.2f, 15.4478f, 0.0f);


    glVertex3f(42.7333f, 14.4776f, 0.0f);
    glVertex3f(42.6667f, 14.4776f, 0.0f);
    glVertex3f(42.6f, 14.4776f, 0.0f);
    glVertex3f(42.5333f, 14.4776f, 0.0f);
    glVertex3f(42.4667f, 14.4776f, 0.0f);
    glVertex3f(42.4f, 14.4776f, 0.0f);
    glVertex3f(42.3333f, 14.4776f, 0.0f);
    glVertex3f(42.2667f, 14.4776f, 0.0f);
    glVertex3f(42.2f, 14.4776f, 0.0f);
    glVertex3f(42.1333f, 14.4776f, 0.0f);
    glVertex3f(42.0667f, 14.4776f, 0.0f);
    glVertex3f(42.0f, 14.4776f, 0.0f);
    glVertex3f(41.9333f, 14.4776f, 0.0f);
    glVertex3f(41.8667f, 14.4776f, 0.0f);
    glVertex3f(41.7333f, 14.5522f, 0.0f);
    glVertex3f(41.7333f, 14.6269f, 0.0f);
    glVertex3f(41.7333f, 14.7015f, 0.0f);
    glVertex3f(41.7333f, 14.8507f, 0.0f);
    glVertex3f(41.7333f, 14.9254f, 0.0f);
    glVertex3f(41.7333f, 15.0f, 0.0f);
    glVertex3f(41.7333f, 15.0746f, 0.0f);
    glVertex3f(41.8f, 15.1493f, 0.0f);
    glVertex3f(41.9333f, 15.1493f, 0.0f);
    glVertex3f(42.0f, 15.2239f, 0.0f);
    glVertex3f(42.0667f, 15.2239f, 0.0f);
    glVertex3f(42.1333f, 15.2239f, 0.0f);
    glVertex3f(42.2f, 15.2239f, 0.0f);
    glVertex3f(42.1333f, 15.2985f, 0.0f);
    glVertex3f(42.1333f, 15.3731f, 0.0f);
    glVertex3f(42.1333f, 15.5224f, 0.0f);
    glVertex3f(42.1333f, 15.597f, 0.0f);
    glVertex3f(42.1333f, 15.6716f, 0.0f);
    glVertex3f(42.1333f, 15.7463f, 0.0f);
    glVertex3f(42.2f, 15.8209f, 0.0f);
    glVertex3f(42.3333f, 15.8209f, 0.0f);
    glVertex3f(42.3333f, 15.8955f, 0.0f);
    glVertex3f(42.2f, 15.9701f, 0.0f);
    glVertex3f(42.1333f, 15.9701f, 0.0f);
    glVertex3f(42.1333f, 16.0448f, 0.0f);
    glVertex3f(42.0667f, 16.0448f, 0.0f);
    glVertex3f(42.0f, 16.0448f, 0.0f);
    glVertex3f(41.9333f, 16.1194f, 0.0f);
    glVertex3f(41.9333f, 16.194f, 0.0f);
    glVertex3f(42.0f, 16.2687f, 0.0f);
    glVertex3f(42.0667f, 16.2687f, 0.0f);
    glVertex3f(42.1333f, 16.2687f, 0.0f);
    glVertex3f(42.2f, 16.2687f, 0.0f);
    glVertex3f(42.2667f, 16.2687f, 0.0f);
    glVertex3f(42.2667f, 16.3433f, 0.0f);
    glVertex3f(42.3333f, 16.3433f, 0.0f);
    glVertex3f(42.4f, 16.3433f, 0.0f);
    glVertex3f(42.4667f, 16.3433f, 0.0f);
    glVertex3f(42.4667f, 16.4179f, 0.0f);
    glVertex3f(42.4667f, 16.4925f, 0.0f);
    glVertex3f(42.4667f, 16.5672f, 0.0f);
    glVertex3f(42.3333f, 16.6418f, 0.0f);
    glVertex3f(42.3333f, 16.7164f, 0.0f);
    glVertex3f(42.2667f, 16.791f, 0.0f);
    glVertex3f(42.3333f, 16.791f, 0.0f);
    glVertex3f(42.4f, 16.791f, 0.0f);
    glVertex3f(42.4667f, 16.8657f, 0.0f);
    glVertex3f(42.4667f, 16.9403f, 0.0f);
    glVertex3f(42.4667f, 17.0149f, 0.0f);
    glVertex3f(42.5333f, 17.0149f, 0.0f);
    glVertex3f(42.5333f, 17.0896f, 0.0f);
    glVertex3f(42.6f, 17.0896f, 0.0f);
    glVertex3f(42.6f, 17.1642f, 0.0f);
    glVertex3f(42.6f, 17.2388f, 0.0f);
    glVertex3f(42.5333f, 17.3134f, 0.0f);
    glVertex3f(42.4667f, 17.4627f, 0.0f);
    glVertex3f(42.4667f, 17.5373f, 0.0f);
    glVertex3f(42.4667f, 17.6119f, 0.0f);
    glVertex3f(42.4f, 17.6866f, 0.0f);
    glVertex3f(42.4f, 17.7612f, 0.0f);
    glVertex3f(42.4f, 17.8358f, 0.0f);
    glVertex3f(42.4f, 17.9104f, 0.0f);
    glVertex3f(42.4667f, 17.9104f, 0.0f);
    glVertex3f(42.5333f, 17.9104f, 0.0f);
    glVertex3f(42.6f, 17.9104f, 0.0f);
    glVertex3f(42.6667f, 17.9104f, 0.0f);
    glVertex3f(42.7333f, 17.9104f, 0.0f);
    glVertex3f(42.8f, 17.9104f, 0.0f);
    glVertex3f(42.8667f, 17.9104f, 0.0f);
    glVertex3f(42.9333f, 17.9104f, 0.0f);
    glVertex3f(43.0f, 17.9851f, 0.0f);
    glVertex3f(43.0f, 18.0597f, 0.0f);
    glVertex3f(43.0f, 18.1343f, 0.0f);
    glVertex3f(43.0f, 18.209f, 0.0f);
    glVertex3f(43.0f, 18.2836f, 0.0f);
    glVertex3f(43.0f, 18.3582f, 0.0f);
    glVertex3f(43.0f, 18.4328f, 0.0f);
    glVertex3f(43.0667f, 18.5075f, 0.0f);
    glVertex3f(43.1333f, 18.4328f, 0.0f);
    glVertex3f(43.1333f, 18.3582f, 0.0f);
    glVertex3f(43.1333f, 18.2836f, 0.0f);
    glVertex3f(43.2f, 18.209f, 0.0f);
    glVertex3f(43.2f, 18.1343f, 0.0f);
    glVertex3f(43.2f, 18.0597f, 0.0f);
    glVertex3f(43.2f, 17.9851f, 0.0f);
    glVertex3f(43.2f, 17.9104f, 0.0f);
    glVertex3f(43.2f, 17.8358f, 0.0f);
    glVertex3f(43.2f, 17.7612f, 0.0f);
    glVertex3f(43.2f, 17.6866f, 0.0f);
    glVertex3f(43.2f, 17.6119f, 0.0f);
    glVertex3f(43.2f, 17.5373f, 0.0f);
    glVertex3f(43.2667f, 17.4627f, 0.0f);
    glVertex3f(43.3333f, 17.4627f, 0.0f);
    glVertex3f(43.3333f, 17.3881f, 0.0f);
    glVertex3f(43.4f, 17.3134f, 0.0f);
    glVertex3f(43.4f, 17.1642f, 0.0f);
    glVertex3f(43.4f, 17.0896f, 0.0f);
    glVertex3f(43.3333f, 17.0896f, 0.0f);
    glVertex3f(43.2667f, 17.0896f, 0.0f);
    glVertex3f(43.2667f, 17.0149f, 0.0f);
    glVertex3f(43.1333f, 16.9403f, 0.0f);
    glVertex3f(43.1333f, 16.8657f, 0.0f);
    glVertex3f(43.2f, 16.8657f, 0.0f);
    glVertex3f(43.2667f, 16.791f, 0.0f);
    glVertex3f(43.4f, 16.7164f, 0.0f);
    glVertex3f(43.4f, 16.6418f, 0.0f);
    glVertex3f(43.4667f, 16.5672f, 0.0f);
    glVertex3f(43.4667f, 16.4925f, 0.0f);
    glVertex3f(43.5333f, 16.4179f, 0.0f);
    glVertex3f(43.5333f, 16.3433f, 0.0f);
    glVertex3f(43.4667f, 16.2687f, 0.0f);
    glVertex3f(43.4667f, 16.194f, 0.0f);
    glVertex3f(43.4667f, 16.0448f, 0.0f);
    glVertex3f(43.4667f, 15.9701f, 0.0f);
    glVertex3f(43.5333f, 15.8209f, 0.0f);
    glVertex3f(43.6f, 15.7463f, 0.0f);
    glVertex3f(43.6f, 15.6716f, 0.0f);
    glVertex3f(43.6667f, 15.6716f, 0.0f);
    glVertex3f(43.7333f, 15.6716f, 0.0f);
    glVertex3f(43.8f, 15.6716f, 0.0f);
    glVertex3f(43.8f, 15.597f, 0.0f);
    glVertex3f(43.8f, 15.4478f, 0.0f);
    glVertex3f(43.8f, 15.3731f, 0.0f);
    glVertex3f(43.8f, 15.2985f, 0.0f);
    glVertex3f(43.8f, 15.1493f, 0.0f);
    glVertex3f(43.8667f, 15.0746f, 0.0f);
    glVertex3f(44.0f, 15.0f, 0.0f);
    glVertex3f(44.0667f, 14.9254f, 0.0f);
    glVertex3f(44.2f, 14.8507f, 0.0f);
    glVertex3f(44.2667f, 14.8507f, 0.0f);
    glVertex3f(44.3333f, 14.8507f, 0.0f);
    glVertex3f(44.4f, 14.7761f, 0.0f);
    glVertex3f(44.4667f, 14.7761f, 0.0f);
    glVertex3f(44.5333f, 14.7761f, 0.0f);
    glVertex3f(44.5333f, 14.7015f, 0.0f);
    glVertex3f(44.5333f, 14.6269f, 0.0f);
    glVertex3f(44.5333f, 14.5522f, 0.0f);
    glVertex3f(44.4667f, 14.5522f, 0.0f);
    glVertex3f(44.4667f, 14.4776f, 0.0f);
    glVertex3f(44.4f, 14.403f, 0.0f);
    glVertex3f(44.3333f, 14.403f, 0.0f);
    glVertex3f(44.2667f, 14.403f, 0.0f);
    glVertex3f(44.2f, 14.403f, 0.0f);
    glVertex3f(44.1333f, 14.403f, 0.0f);
    glVertex3f(44.0667f, 14.403f, 0.0f);
    glVertex3f(44.0f, 14.403f, 0.0f);
    glVertex3f(43.9333f, 14.403f, 0.0f);
    glVertex3f(43.8667f, 14.403f, 0.0f);
    glVertex3f(43.8f, 14.403f, 0.0f);
    glVertex3f(43.7333f, 14.403f, 0.0f);
    glVertex3f(43.6667f, 14.403f, 0.0f);
    glVertex3f(43.6f, 14.403f, 0.0f);
    glVertex3f(43.5333f, 14.403f, 0.0f);
    glVertex3f(43.4667f, 14.403f, 0.0f);
    glVertex3f(43.4f, 14.403f, 0.0f);
    glVertex3f(43.3333f, 14.403f, 0.0f);
    glVertex3f(43.2667f, 14.403f, 0.0f);
    glVertex3f(43.2f, 14.4776f, 0.0f);
    glVertex3f(43.1333f, 14.5522f, 0.0f);
    glVertex3f(43.0667f, 14.5522f, 0.0f);
    glVertex3f(43.0f, 14.5522f, 0.0f);
    glVertex3f(42.9333f, 14.5522f, 0.0f);
    glVertex3f(42.8667f, 14.5522f, 0.0f);
    glVertex3f(42.8f, 14.5522f, 0.0f);
    glVertex3f(42.7333f, 14.5522f, 0.0f);
    glVertex3f(42.6667f, 14.5522f, 0.0f);
    glVertex3f(42.6f, 14.5522f, 0.0f);
    glVertex3f(42.5333f, 14.5522f, 0.0f);
    glVertex3f(42.4667f, 14.5522f, 0.0f);
    glVertex3f(42.4f, 14.5522f, 0.0f);
    glVertex3f(42.3333f, 14.5522f, 0.0f);
    glVertex3f(42.3333f, 14.6269f, 0.0f);


    glEnd();


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Tree Big Right Side 2  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glColor3f(0.498, 0.635, 0.376);
    drawCircle(45.6f, 15.1493f,1.0);

    glColor3f(0.498, 0.635, 0.376);
    drawCircle(45.6f, 16.1493f, 0.7);

    glColor3f(0.498, 0.635, 0.376);
    drawCircle(45.6f, 16.9f, 0.5);


//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Tree Big Right Side 3  ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬


    glBegin(GL_TRIANGLE_FAN);


    glColor3f(0.196, 0.482, 0.267);
    glVertex3f(48.8f, 15.4478f, 0.0f);


    glVertex3f(48.7333f, 13.8806f, 0.0f);
    glVertex3f(48.6667f, 13.8806f, 0.0f);
    glVertex3f(48.6f, 13.8806f, 0.0f);
    glVertex3f(48.5333f, 13.806f, 0.0f);
    glVertex3f(48.4667f, 13.806f, 0.0f);
    glVertex3f(48.4f, 13.806f, 0.0f);
    glVertex3f(48.3333f, 13.806f, 0.0f);
    glVertex3f(48.2f, 13.806f, 0.0f);
    glVertex3f(48.1333f, 13.806f, 0.0f);
    glVertex3f(48.0667f, 13.806f, 0.0f);
    glVertex3f(48.0f, 13.7313f, 0.0f);
    glVertex3f(48.0f, 13.6567f, 0.0f);
    glVertex3f(47.9333f, 13.6567f, 0.0f);
    glVertex3f(47.8667f, 13.6567f, 0.0f);
    glVertex3f(47.8f, 13.6567f, 0.0f);
    glVertex3f(47.7333f, 13.6567f, 0.0f);
    glVertex3f(47.6667f, 13.6567f, 0.0f);
    glVertex3f(47.6f, 13.6567f, 0.0f);
    glVertex3f(47.5333f, 13.6567f, 0.0f);
    glVertex3f(47.4667f, 13.6567f, 0.0f);
    glVertex3f(47.4f, 13.6567f, 0.0f);
    glVertex3f(47.3333f, 13.7313f, 0.0f);
    glVertex3f(47.2667f, 13.806f, 0.0f);
    glVertex3f(47.2f, 13.8806f, 0.0f);
    glVertex3f(47.2f, 13.9552f, 0.0f);
    glVertex3f(47.2f, 14.0299f, 0.0f);
    glVertex3f(47.2f, 14.1045f, 0.0f);
    glVertex3f(47.2f, 14.1791f, 0.0f);
    glVertex3f(47.2f, 14.2537f, 0.0f);
    glVertex3f(47.2f, 14.3284f, 0.0f);
    glVertex3f(47.2f, 14.403f, 0.0f);
    glVertex3f(47.2f, 14.4776f, 0.0f);
    glVertex3f(47.2f, 14.5522f, 0.0f);
    glVertex3f(47.2f, 14.6269f, 0.0f);
    glVertex3f(47.2f, 14.7015f, 0.0f);
    glVertex3f(47.2f, 14.7761f, 0.0f);
    glVertex3f(47.2f, 14.8507f, 0.0f);
    glVertex3f(47.2f, 14.9254f, 0.0f);
    glVertex3f(47.2f, 15.0f, 0.0f);
    glVertex3f(47.2f, 15.1493f, 0.0f);
    glVertex3f(47.2f, 15.2239f, 0.0f);
    glVertex3f(47.2f, 15.2985f, 0.0f);
    glVertex3f(47.2f, 15.3731f, 0.0f);
    glVertex3f(47.2667f, 15.3731f, 0.0f);
    glVertex3f(47.2667f, 15.4478f, 0.0f);
    glVertex3f(47.3333f, 15.4478f, 0.0f);
    glVertex3f(47.4f, 15.4478f, 0.0f);
    glVertex3f(47.4667f, 15.4478f, 0.0f);
    glVertex3f(47.4f, 15.4478f, 0.0f);
    glVertex3f(47.3333f, 15.4478f, 0.0f);
    glVertex3f(47.2667f, 15.4478f, 0.0f);
    glVertex3f(47.1333f, 15.5224f, 0.0f);
    glVertex3f(47.0667f, 15.5224f, 0.0f);
    glVertex3f(47.0f, 15.597f, 0.0f);
    glVertex3f(47.0f, 15.6716f, 0.0f);
    glVertex3f(46.9333f, 15.7463f, 0.0f);
    glVertex3f(46.9333f, 15.8209f, 0.0f);
    glVertex3f(46.9333f, 15.8955f, 0.0f);
    glVertex3f(46.9333f, 15.9701f, 0.0f);
    glVertex3f(46.9333f, 16.0448f, 0.0f);
    glVertex3f(46.9333f, 16.1194f, 0.0f);
    glVertex3f(46.9333f, 16.194f, 0.0f);
    glVertex3f(46.9333f, 16.2687f, 0.0f);
    glVertex3f(46.9333f, 16.3433f, 0.0f);
    glVertex3f(46.9333f, 16.4179f, 0.0f);
    glVertex3f(46.9333f, 16.4925f, 0.0f);
    glVertex3f(46.9333f, 16.5672f, 0.0f);
    glVertex3f(47.0f, 16.6418f, 0.0f);
    glVertex3f(47.0f, 16.7164f, 0.0f);
    glVertex3f(47.0667f, 16.791f, 0.0f);
    glVertex3f(47.1333f, 16.791f, 0.0f);
    glVertex3f(47.2f, 16.791f, 0.0f);
    glVertex3f(47.2667f, 16.791f, 0.0f);
    glVertex3f(47.3333f, 16.8657f, 0.0f);
    glVertex3f(47.4f, 16.8657f, 0.0f);
    glVertex3f(47.4667f, 16.8657f, 0.0f);
    glVertex3f(47.5333f, 16.8657f, 0.0f);
    glVertex3f(47.6f, 16.9403f, 0.0f);
    glVertex3f(47.6667f, 16.9403f, 0.0f);
    glVertex3f(47.7333f, 16.9403f, 0.0f);
    glVertex3f(47.8f, 16.9403f, 0.0f);
    glVertex3f(47.8667f, 17.0149f, 0.0f);
    glVertex3f(47.9333f, 17.0149f, 0.0f);
    glVertex3f(48.0f, 17.0149f, 0.0f);
    glVertex3f(47.9333f, 17.0896f, 0.0f);
    glVertex3f(47.9333f, 17.1642f, 0.0f);
    glVertex3f(47.9333f, 17.2388f, 0.0f);
    glVertex3f(47.9333f, 17.3134f, 0.0f);
    glVertex3f(47.9333f, 17.3881f, 0.0f);
    glVertex3f(47.9333f, 17.4627f, 0.0f);
    glVertex3f(47.9333f, 17.5373f, 0.0f);
    glVertex3f(47.9333f, 17.6119f, 0.0f);
    glVertex3f(47.9333f, 17.6866f, 0.0f);
    glVertex3f(47.9333f, 17.7612f, 0.0f);
    glVertex3f(48.0f, 17.9104f, 0.0f);
    glVertex3f(48.0667f, 17.9104f, 0.0f);
    glVertex3f(48.2f, 17.9851f, 0.0f);
    glVertex3f(48.2667f, 17.9851f, 0.0f);
    glVertex3f(48.3333f, 17.9851f, 0.0f);
    glVertex3f(48.4f, 17.9851f, 0.0f);
    glVertex3f(48.4667f, 17.9851f, 0.0f);
    glVertex3f(48.5333f, 17.9851f, 0.0f);
    glVertex3f(48.6f, 17.9851f, 0.0f);
    glVertex3f(48.6667f, 17.9851f, 0.0f);
    glVertex3f(48.7333f, 17.9851f, 0.0f);
    glVertex3f(48.8f, 17.9851f, 0.0f);
    glVertex3f(48.8667f, 17.9104f, 0.0f);
    glVertex3f(48.9333f, 17.9104f, 0.0f);
    glVertex3f(48.9333f, 17.8358f, 0.0f);
    glVertex3f(49.0f, 17.8358f, 0.0f);
    glVertex3f(49.0f, 17.7612f, 0.0f);
    glVertex3f(49.1333f, 17.6866f, 0.0f);
    glVertex3f(49.1333f, 17.6119f, 0.0f);
    glVertex3f(49.2f, 17.5373f, 0.0f);
    glVertex3f(49.2f, 17.4627f, 0.0f);
    glVertex3f(49.2667f, 17.3881f, 0.0f);
    glVertex3f(49.2667f, 17.3134f, 0.0f);
    glVertex3f(49.2667f, 17.2388f, 0.0f);
    glVertex3f(49.2667f, 17.1642f, 0.0f);
    glVertex3f(49.2667f, 17.0896f, 0.0f);
    glVertex3f(49.3333f, 17.0149f, 0.0f);
    glVertex3f(49.3333f, 16.9403f, 0.0f);
    glVertex3f(49.3333f, 16.8657f, 0.0f);
    glVertex3f(49.3333f, 16.791f, 0.0f);
    glVertex3f(49.3333f, 16.7164f, 0.0f);
    glVertex3f(49.3333f, 16.6418f, 0.0f);
    glVertex3f(49.3333f, 16.5672f, 0.0f);
    glVertex3f(49.3333f, 16.4925f, 0.0f);
    glVertex3f(49.3333f, 16.4179f, 0.0f);
    glVertex3f(49.3333f, 16.3433f, 0.0f);
    glVertex3f(49.3333f, 16.2687f, 0.0f);
    glVertex3f(49.4f, 16.2687f, 0.0f);
    glVertex3f(49.4667f, 16.2687f, 0.0f);
    glVertex3f(49.5333f, 16.2687f, 0.0f);
    glVertex3f(49.6f, 16.2687f, 0.0f);
    glVertex3f(49.6667f, 16.2687f, 0.0f);
    glVertex3f(49.7333f, 16.2687f, 0.0f);
    glVertex3f(49.7333f, 16.194f, 0.0f);
    glVertex3f(49.8f, 16.194f, 0.0f);
    glVertex3f(49.8667f, 16.1194f, 0.0f);
    glVertex3f(49.8667f, 16.0448f, 0.0f);
    glVertex3f(49.9333f, 16.0448f, 0.0f);
    glVertex3f(49.9333f, 15.9701f, 0.0f);
    glVertex3f(50.0f, 15.9701f, 0.0f);
    glVertex3f(50.0f, 15.8955f, 0.0f);
    glVertex3f(50.0667f, 15.8955f, 0.0f);
    glVertex3f(50.0667f, 15.8209f, 0.0f);
    glVertex3f(50.0667f, 15.7463f, 0.0f);
    glVertex3f(50.0667f, 15.6716f, 0.0f);
    glVertex3f(50.1333f, 15.5224f, 0.0f);
    glVertex3f(50.1333f, 15.4478f, 0.0f);
    glVertex3f(50.1333f, 15.3731f, 0.0f);
    glVertex3f(50.2f, 15.2239f, 0.0f);
    glVertex3f(50.2f, 15.1493f, 0.0f);
    glVertex3f(50.2f, 15.0746f, 0.0f);
    glVertex3f(50.1333f, 15.0f, 0.0f);
    glVertex3f(50.0667f, 14.9254f, 0.0f);
    glVertex3f(50.0f, 14.9254f, 0.0f);
    glVertex3f(49.9333f, 14.9254f, 0.0f);
    glVertex3f(49.8667f, 14.9254f, 0.0f);
    glVertex3f(49.8f, 14.8507f, 0.0f);
    glVertex3f(49.8667f, 14.7761f, 0.0f);
    glVertex3f(49.9333f, 14.7761f, 0.0f);
    glVertex3f(50.0f, 14.7761f, 0.0f);
    glVertex3f(50.0667f, 14.7015f, 0.0f);
    glVertex3f(50.1333f, 14.7015f, 0.0f);
    glVertex3f(50.2f, 14.6269f, 0.0f);
    glVertex3f(50.2667f, 14.6269f, 0.0f);
    glVertex3f(50.3333f, 14.5522f, 0.0f);
    glVertex3f(50.3333f, 14.4776f, 0.0f);
    glVertex3f(50.4f, 14.4776f, 0.0f);
    glVertex3f(50.4f, 14.403f, 0.0f);
    glVertex3f(50.4667f, 14.3284f, 0.0f);
    glVertex3f(50.5333f, 14.1791f, 0.0f);
    glVertex3f(50.5333f, 14.1045f, 0.0f);
    glVertex3f(50.5333f, 14.0299f, 0.0f);
    glVertex3f(50.6f, 13.8806f, 0.0f);
    glVertex3f(50.6f, 13.806f, 0.0f);
    glVertex3f(50.6f, 13.7313f, 0.0f);
    glVertex3f(50.6f, 13.6567f, 0.0f);
    glVertex3f(50.5333f, 13.6567f, 0.0f);
    glVertex3f(50.5333f, 13.5821f, 0.0f);
    glVertex3f(50.4f, 13.5075f, 0.0f);
    glVertex3f(50.3333f, 13.5075f, 0.0f);
    glVertex3f(50.2667f, 13.4328f, 0.0f);
    glVertex3f(50.2f, 13.4328f, 0.0f);
    glVertex3f(50.1333f, 13.4328f, 0.0f);
    glVertex3f(50.0667f, 13.4328f, 0.0f);
    glVertex3f(50.0f, 13.4328f, 0.0f);
    glVertex3f(49.9333f, 13.4328f, 0.0f);
    glVertex3f(49.8667f, 13.4328f, 0.0f);
    glVertex3f(49.8f, 13.4328f, 0.0f);
    glVertex3f(49.7333f, 13.4328f, 0.0f);
    glVertex3f(49.6667f, 13.4328f, 0.0f);
    glVertex3f(49.6f, 13.4328f, 0.0f);
    glVertex3f(49.5333f, 13.4328f, 0.0f);
    glVertex3f(49.4667f, 13.4328f, 0.0f);
    glVertex3f(49.4f, 13.4328f, 0.0f);
    glVertex3f(49.3333f, 13.4328f, 0.0f);
    glVertex3f(49.2667f, 13.4328f, 0.0f);
    glVertex3f(49.2f, 13.4328f, 0.0f);
    glVertex3f(49.1333f, 13.4328f, 0.0f);
    glVertex3f(49.0667f, 13.5075f, 0.0f);
    glVertex3f(49.0f, 13.5075f, 0.0f);
    glVertex3f(48.9333f, 13.5821f, 0.0f);
    glVertex3f(48.8667f, 13.6567f, 0.0f);
    glVertex3f(48.8f, 13.6567f, 0.0f);
    glVertex3f(48.8f, 13.7313f, 0.0f);
    glVertex3f(48.8f, 13.806f, 0.0f);
    glVertex3f(48.8f, 13.8806f, 0.0f);
    glVertex3f(48.8f, 13.9552f, 0.0f);
    glVertex3f(48.8f, 14.0299f, 0.0f);
    glVertex3f(48.8f, 14.1045f, 0.0f);
    glVertex3f(48.8f, 14.1791f, 0.0f);



    glEnd();

//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Tree Right Side Kandoo¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
    glBegin(GL_LINES);

    glColor3f(0.302, 0.227, 0.243);

    glVertex3f(42.8667f, 15.2239f, 0.0f);
    glVertex3f(43.0f, 13.2836f, 0.0f);

    glVertex3f(45.4667f, 15.2985f, 0.0f);
    glVertex3f(45.6f, 13.209f, 0.0f);

    glVertex3f(48.4667f, 14.6269f, 0.0f);
    glVertex3f(48.7333f, 12.5373f, 0.0f);




    glEnd();




    clouds(); // clouds draw and movement


    boat(); // 1st boat draw and movement

    boat2(); // 2nd boat draw and movement



}






//¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬VILLAGE¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬







void drawVillage()
{
    glLoadIdentity();
    glBegin(GL_QUADS); // background sky color
    glColor3f(0.655, 0.875, 1.0);
    glVertex3f(0.1333f, 16.791f, 0.0f);
    glVertex3f(49.8667f, 16.9403f, 0.0f);
    glVertex3f(49.8667f, 49.9254f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd();






    // SUN
    glColor3f(0.996, 0.765, 0.012); // set color to yellow
    drawCircle(22.5333, 31.9403f, 3.0); // draw a circle with radius 3.0
    glFlush();


    glBegin(GL_TRIANGLE_FAN);    // Background Pahar 1st

    glColor3f(0.22, 0.353, 0.392);
    glVertex3f(23.8f, 19.1791f, 0.0f);

    glVertex3f(0.2667f, 19.6269f, 0.0f);
    glVertex3f(0.3333f, 19.7761f, 0.0f);
    glVertex3f(0.3333f, 19.8507f, 0.0f);
    glVertex3f(0.4f, 19.9254f, 0.0f);
    glVertex3f(0.4667f, 20.0f, 0.0f);
    glVertex3f(0.4667f, 20.0746f, 0.0f);
    glVertex3f(0.5333f, 20.2239f, 0.0f);
    glVertex3f(0.6f, 20.2985f, 0.0f);
    glVertex3f(0.6f, 20.3731f, 0.0f);
    glVertex3f(0.6f, 20.4478f, 0.0f);
    glVertex3f(0.6667f, 20.5224f, 0.0f);
    glVertex3f(0.6667f, 20.597f, 0.0f);
    glVertex3f(0.7333f, 20.597f, 0.0f);
    glVertex3f(0.7333f, 20.6716f, 0.0f);
    glVertex3f(0.8f, 20.7463f, 0.0f);
    glVertex3f(0.8f, 20.8209f, 0.0f);
    glVertex3f(0.8667f, 20.8209f, 0.0f);
    glVertex3f(0.8667f, 20.8955f, 0.0f);
    glVertex3f(0.9333f, 20.9701f, 0.0f);
    glVertex3f(0.9333f, 21.0448f, 0.0f);
    glVertex3f(1.0f, 21.1194f, 0.0f);
    glVertex3f(1.0f, 21.194f, 0.0f);
    glVertex3f(1.0667f, 21.2687f, 0.0f);
    glVertex3f(1.1333f, 21.3433f, 0.0f);
    glVertex3f(1.2f, 21.4179f, 0.0f);
    glVertex3f(1.2f, 21.4925f, 0.0f);
    glVertex3f(1.2667f, 21.4925f, 0.0f);
    glVertex3f(1.2667f, 21.5672f, 0.0f);
    glVertex3f(1.3333f, 21.6418f, 0.0f);
    glVertex3f(1.4f, 21.791f, 0.0f);
    glVertex3f(1.4667f, 21.8657f, 0.0f);
    glVertex3f(1.4667f, 21.9403f, 0.0f);
    glVertex3f(1.5333f, 21.9403f, 0.0f);
    glVertex3f(1.5333f, 22.0149f, 0.0f);
    glVertex3f(1.5333f, 22.0896f, 0.0f);
    glVertex3f(1.6f, 22.1642f, 0.0f);
    glVertex3f(1.6667f, 22.2388f, 0.0f);
    glVertex3f(1.6667f, 22.3134f, 0.0f);
    glVertex3f(1.7333f, 22.3881f, 0.0f);
    glVertex3f(1.7333f, 22.4627f, 0.0f);
    glVertex3f(1.8f, 22.5373f, 0.0f);
    glVertex3f(1.8667f, 22.6119f, 0.0f);
    glVertex3f(1.9333f, 22.6866f, 0.0f);
    glVertex3f(1.9333f, 22.7612f, 0.0f);
    glVertex3f(2.0f, 22.8358f, 0.0f);
    glVertex3f(2.0667f, 22.8358f, 0.0f);
    glVertex3f(2.0667f, 22.9104f, 0.0f);
    glVertex3f(2.1333f, 23.0597f, 0.0f);
    glVertex3f(2.2f, 23.1343f, 0.0f);
    glVertex3f(2.2f, 23.209f, 0.0f);
    glVertex3f(2.2f, 23.2836f, 0.0f);
    glVertex3f(2.2667f, 23.3582f, 0.0f);
    glVertex3f(2.3333f, 23.5075f, 0.0f);
    glVertex3f(2.4f, 23.5821f, 0.0f);
    glVertex3f(2.4f, 23.6567f, 0.0f);
    glVertex3f(2.4667f, 23.7313f, 0.0f);
    glVertex3f(2.4667f, 23.806f, 0.0f);
    glVertex3f(2.5333f, 23.9552f, 0.0f);
    glVertex3f(2.6f, 24.1791f, 0.0f);
    glVertex3f(2.6f, 24.2537f, 0.0f);
    glVertex3f(2.6667f, 24.3284f, 0.0f);
    glVertex3f(2.7333f, 24.403f, 0.0f);
    glVertex3f(2.7333f, 24.4776f, 0.0f);
    glVertex3f(2.8f, 24.5522f, 0.0f);
    glVertex3f(2.8f, 24.6269f, 0.0f);
    glVertex3f(2.8667f, 24.7015f, 0.0f);
    glVertex3f(2.9333f, 24.7761f, 0.0f);
    glVertex3f(3.0f, 24.8507f, 0.0f);
    glVertex3f(3.0f, 25.0f, 0.0f);
    glVertex3f(3.0667f, 25.0746f, 0.0f);
    glVertex3f(3.1333f, 25.1493f, 0.0f);
    glVertex3f(3.1333f, 25.2239f, 0.0f);
    glVertex3f(3.2f, 25.3731f, 0.0f);
    glVertex3f(3.2667f, 25.4478f, 0.0f);
    glVertex3f(3.3333f, 25.597f, 0.0f);
    glVertex3f(3.4f, 25.6716f, 0.0f);
    glVertex3f(3.4f, 25.7463f, 0.0f);
    glVertex3f(3.4667f, 25.8209f, 0.0f);
    glVertex3f(3.5333f, 25.8209f, 0.0f);
    glVertex3f(3.5333f, 25.9701f, 0.0f);
    glVertex3f(3.6f, 26.0448f, 0.0f);
    glVertex3f(3.6667f, 26.194f, 0.0f);
    glVertex3f(3.7333f, 26.2687f, 0.0f);
    glVertex3f(3.7333f, 26.3433f, 0.0f);
    glVertex3f(3.8f, 26.4179f, 0.0f);
    glVertex3f(3.8667f, 26.5672f, 0.0f);
    glVertex3f(3.9333f, 26.6418f, 0.0f);
    glVertex3f(4.0f, 26.7164f, 0.0f);
    glVertex3f(4.0f, 26.791f, 0.0f);
    glVertex3f(4.0667f, 26.8657f, 0.0f);
    glVertex3f(4.1333f, 26.8657f, 0.0f);
    glVertex3f(4.1333f, 27.0149f, 0.0f);
    glVertex3f(4.2f, 27.0149f, 0.0f);
    glVertex3f(4.2f, 27.0896f, 0.0f);
    glVertex3f(4.2667f, 27.0896f, 0.0f);
    glVertex3f(4.3333f, 27.1642f, 0.0f);
    glVertex3f(4.4f, 27.3134f, 0.0f);
    glVertex3f(4.4f, 27.3881f, 0.0f);
    glVertex3f(4.5333f, 27.4627f, 0.0f);
    glVertex3f(4.6f, 27.5373f, 0.0f);
    glVertex3f(4.6667f, 27.6119f, 0.0f);
    glVertex3f(4.7333f, 27.6866f, 0.0f);
    glVertex3f(4.8f, 27.7612f, 0.0f);
    glVertex3f(4.8f, 27.9104f, 0.0f);
    glVertex3f(4.8667f, 27.9104f, 0.0f);
    glVertex3f(4.8667f, 27.9851f, 0.0f);
    glVertex3f(4.9333f, 27.9851f, 0.0f);
    glVertex3f(5.0f, 28.0597f, 0.0f);
    glVertex3f(5.0667f, 28.1343f, 0.0f);
    glVertex3f(5.0667f, 28.209f, 0.0f);
    glVertex3f(5.1333f, 28.2836f, 0.0f);
    glVertex3f(5.2f, 28.2836f, 0.0f);
    glVertex3f(5.2f, 28.4328f, 0.0f);
    glVertex3f(5.3333f, 28.4328f, 0.0f);
    glVertex3f(5.3333f, 28.5821f, 0.0f);
    glVertex3f(5.4f, 28.5821f, 0.0f);
    glVertex3f(5.4f, 28.7313f, 0.0f);
    glVertex3f(5.4667f, 28.7313f, 0.0f);
    glVertex3f(5.5333f, 28.806f, 0.0f);
    glVertex3f(5.6f, 28.8806f, 0.0f);
    glVertex3f(5.6667f, 28.8806f, 0.0f);
    glVertex3f(5.6667f, 28.9552f, 0.0f);
    glVertex3f(5.7333f, 29.0299f, 0.0f);
    glVertex3f(5.8f, 29.0299f, 0.0f);
    glVertex3f(5.8f, 29.1045f, 0.0f);
    glVertex3f(5.8667f, 29.1045f, 0.0f);
    glVertex3f(5.9333f, 29.2537f, 0.0f);
    glVertex3f(6.0f, 29.2537f, 0.0f);
    glVertex3f(6.0f, 29.3284f, 0.0f);
    glVertex3f(6.1333f, 29.3284f, 0.0f);
    glVertex3f(6.1333f, 29.403f, 0.0f);
    glVertex3f(6.2f, 29.4776f, 0.0f);
    glVertex3f(6.2667f, 29.4776f, 0.0f);
    glVertex3f(6.4f, 29.5522f, 0.0f);
    glVertex3f(6.4667f, 29.5522f, 0.0f);
    glVertex3f(6.5333f, 29.5522f, 0.0f);
    glVertex3f(6.6f, 29.6269f, 0.0f);
    glVertex3f(6.6f, 29.7015f, 0.0f);
    glVertex3f(6.6667f, 29.7015f, 0.0f);
    glVertex3f(6.8f, 29.7761f, 0.0f);
    glVertex3f(6.8667f, 29.7761f, 0.0f);
    glVertex3f(6.8667f, 29.8507f, 0.0f);
    glVertex3f(6.9333f, 29.9254f, 0.0f);
    glVertex3f(7.0f, 29.9254f, 0.0f);
    glVertex3f(7.0667f, 29.9254f, 0.0f);
    glVertex3f(7.1333f, 29.9254f, 0.0f);
    glVertex3f(7.2f, 30.0f, 0.0f);
    glVertex3f(7.2667f, 30.0f, 0.0f);
    glVertex3f(7.3333f, 30.0f, 0.0f);
    glVertex3f(7.4f, 30.0f, 0.0f);
    glVertex3f(7.4667f, 30.0f, 0.0f);
    glVertex3f(7.5333f, 30.0f, 0.0f);
    glVertex3f(7.6f, 30.0f, 0.0f);
    glVertex3f(7.6667f, 30.0f, 0.0f);
    glVertex3f(7.7333f, 30.0f, 0.0f);
    glVertex3f(7.8f, 30.0f, 0.0f);
    glVertex3f(7.8667f, 30.0f, 0.0f);
    glVertex3f(7.9333f, 30.0f, 0.0f);
    glVertex3f(8.0f, 30.0f, 0.0f);
    glVertex3f(8.0667f, 30.0f, 0.0f);
    glVertex3f(8.0667f, 29.9254f, 0.0f);
    glVertex3f(8.1333f, 29.9254f, 0.0f);
    glVertex3f(8.2f, 29.8507f, 0.0f);
    glVertex3f(8.2667f, 29.8507f, 0.0f);
    glVertex3f(8.2667f, 29.7761f, 0.0f);
    glVertex3f(8.3333f, 29.7761f, 0.0f);
    glVertex3f(8.4f, 29.7761f, 0.0f);
    glVertex3f(8.4667f, 29.7761f, 0.0f);
    glVertex3f(8.4667f, 29.7015f, 0.0f);
    glVertex3f(8.5333f, 29.7015f, 0.0f);
    glVertex3f(8.5333f, 29.6269f, 0.0f);
    glVertex3f(8.6f, 29.6269f, 0.0f);
    glVertex3f(8.7333f, 29.5522f, 0.0f);
    glVertex3f(8.8f, 29.4776f, 0.0f);
    glVertex3f(8.8667f, 29.403f, 0.0f);
    glVertex3f(8.9333f, 29.403f, 0.0f);
    glVertex3f(8.9333f, 29.3284f, 0.0f);
    glVertex3f(9.0f, 29.3284f, 0.0f);
    glVertex3f(9.0667f, 29.1791f, 0.0f);
    glVertex3f(9.1333f, 29.1045f, 0.0f);
    glVertex3f(9.2f, 29.0299f, 0.0f);
    glVertex3f(9.2f, 28.9552f, 0.0f);
    glVertex3f(9.2667f, 28.9552f, 0.0f);
    glVertex3f(9.2667f, 28.8806f, 0.0f);
    glVertex3f(9.3333f, 28.7313f, 0.0f);
    glVertex3f(9.4f, 28.7313f, 0.0f);
    glVertex3f(9.4f, 28.6567f, 0.0f);
    glVertex3f(9.4667f, 28.6567f, 0.0f);
    glVertex3f(9.4667f, 28.5821f, 0.0f);
    glVertex3f(9.5333f, 28.5821f, 0.0f);
    glVertex3f(9.5333f, 28.5075f, 0.0f);
    glVertex3f(9.6f, 28.4328f, 0.0f);
    glVertex3f(9.6667f, 28.3582f, 0.0f);
    glVertex3f(9.7333f, 28.2836f, 0.0f);
    glVertex3f(9.7333f, 28.209f, 0.0f);
    glVertex3f(9.8f, 28.209f, 0.0f);
    glVertex3f(9.8f, 28.1343f, 0.0f);
    glVertex3f(9.8f, 28.0597f, 0.0f);
    glVertex3f(9.8667f, 28.0597f, 0.0f);
    glVertex3f(9.8667f, 27.9851f, 0.0f);
    glVertex3f(9.9333f, 27.9104f, 0.0f);
    glVertex3f(9.9333f, 27.8358f, 0.0f);
    glVertex3f(10.0f, 27.8358f, 0.0f);
    glVertex3f(10.0f, 27.6866f, 0.0f);
    glVertex3f(10.0667f, 27.6119f, 0.0f);
    glVertex3f(10.1333f, 27.5373f, 0.0f);
    glVertex3f(10.2f, 27.4627f, 0.0f);
    glVertex3f(10.2f, 27.3881f, 0.0f);
    glVertex3f(10.2667f, 27.3134f, 0.0f);
    glVertex3f(10.3333f, 27.2388f, 0.0f);
    glVertex3f(10.4f, 27.1642f, 0.0f);
    glVertex3f(10.4f, 27.0896f, 0.0f);
    glVertex3f(10.4f, 27.0149f, 0.0f);
    glVertex3f(10.4667f, 27.0149f, 0.0f);
    glVertex3f(10.4667f, 26.9403f, 0.0f);
    glVertex3f(10.6f, 26.9403f, 0.0f);
    glVertex3f(10.6f, 26.8657f, 0.0f);
    glVertex3f(10.6667f, 26.791f, 0.0f);
    glVertex3f(10.7333f, 26.7164f, 0.0f);
    glVertex3f(10.8f, 26.7164f, 0.0f);
    glVertex3f(10.8667f, 26.7164f, 0.0f);
    glVertex3f(10.9333f, 26.6418f, 0.0f);
    glVertex3f(11.0f, 26.6418f, 0.0f);
    glVertex3f(11.0f, 26.5672f, 0.0f);
    glVertex3f(11.0667f, 26.4925f, 0.0f);
    glVertex3f(11.1333f, 26.4179f, 0.0f);
    glVertex3f(11.2f, 26.4179f, 0.0f);
    glVertex3f(11.2667f, 26.3433f, 0.0f);
    glVertex3f(11.3333f, 26.3433f, 0.0f);
    glVertex3f(11.4f, 26.4179f, 0.0f);
    glVertex3f(11.4667f, 26.4925f, 0.0f);
    glVertex3f(11.5333f, 26.4925f, 0.0f);
    glVertex3f(11.5333f, 26.5672f, 0.0f);
    glVertex3f(11.6f, 26.5672f, 0.0f);
    glVertex3f(11.6f, 26.6418f, 0.0f);
    glVertex3f(11.6667f, 26.7164f, 0.0f);
    glVertex3f(11.7333f, 26.7164f, 0.0f);
    glVertex3f(11.8f, 26.791f, 0.0f);
    glVertex3f(11.8667f, 26.8657f, 0.0f);
    glVertex3f(11.8667f, 26.9403f, 0.0f);
    glVertex3f(11.9333f, 26.9403f, 0.0f);
    glVertex3f(12.0f, 27.0149f, 0.0f);
    glVertex3f(12.0667f, 27.0896f, 0.0f);
    glVertex3f(12.1333f, 27.1642f, 0.0f);
    glVertex3f(12.2f, 27.2388f, 0.0f);
    glVertex3f(12.2667f, 27.3134f, 0.0f);
    glVertex3f(12.3333f, 27.3881f, 0.0f);
    glVertex3f(12.3333f, 27.4627f, 0.0f);
    glVertex3f(12.4f, 27.4627f, 0.0f);
    glVertex3f(12.4f, 27.5373f, 0.0f);
    glVertex3f(12.4667f, 27.6119f, 0.0f);
    glVertex3f(12.4667f, 27.6866f, 0.0f);
    glVertex3f(12.5333f, 27.6866f, 0.0f);
    glVertex3f(12.5333f, 27.7612f, 0.0f);
    glVertex3f(12.6f, 27.7612f, 0.0f);
    glVertex3f(12.6667f, 27.8358f, 0.0f);
    glVertex3f(12.6667f, 27.9104f, 0.0f);
    glVertex3f(12.7333f, 27.9851f, 0.0f);
    glVertex3f(12.8f, 28.0597f, 0.0f);
    glVertex3f(12.8667f, 28.1343f, 0.0f);
    glVertex3f(12.8667f, 28.209f, 0.0f);
    glVertex3f(12.9333f, 28.209f, 0.0f);
    glVertex3f(12.9333f, 28.2836f, 0.0f);
    glVertex3f(13.0f, 28.2836f, 0.0f);
    glVertex3f(13.0f, 28.4328f, 0.0f);
    glVertex3f(13.1333f, 28.4328f, 0.0f);
    glVertex3f(13.1333f, 28.5075f, 0.0f);
    glVertex3f(13.2f, 28.5821f, 0.0f);
    glVertex3f(13.2667f, 28.6567f, 0.0f);
    glVertex3f(13.3333f, 28.7313f, 0.0f);
    glVertex3f(13.4f, 28.8806f, 0.0f);
    glVertex3f(13.5333f, 28.9552f, 0.0f);
    glVertex3f(13.5333f, 29.0299f, 0.0f);
    glVertex3f(13.6f, 29.1045f, 0.0f);
    glVertex3f(13.6667f, 29.1791f, 0.0f);
    glVertex3f(13.6667f, 29.2537f, 0.0f);
    glVertex3f(13.7333f, 29.3284f, 0.0f);
    glVertex3f(13.8f, 29.4776f, 0.0f);
    glVertex3f(13.8667f, 29.4776f, 0.0f);
    glVertex3f(13.8667f, 29.5522f, 0.0f);
    glVertex3f(13.9333f, 29.5522f, 0.0f);
    glVertex3f(13.9333f, 29.6269f, 0.0f);
    glVertex3f(14.0f, 29.7015f, 0.0f);
    glVertex3f(14.0f, 29.7761f, 0.0f);
    glVertex3f(14.0667f, 29.7761f, 0.0f);
    glVertex3f(14.1333f, 29.8507f, 0.0f);
    glVertex3f(14.2f, 29.9254f, 0.0f);
    glVertex3f(14.2667f, 30.0746f, 0.0f);
    glVertex3f(14.3333f, 30.1493f, 0.0f);
    glVertex3f(14.4f, 30.1493f, 0.0f);
    glVertex3f(14.5333f, 30.2239f, 0.0f);
    glVertex3f(14.6f, 30.2985f, 0.0f);
    glVertex3f(14.6667f, 30.3731f, 0.0f);
    glVertex3f(14.7333f, 30.4478f, 0.0f);
    glVertex3f(14.8f, 30.4478f, 0.0f);
    glVertex3f(14.8f, 30.597f, 0.0f);
    glVertex3f(14.8667f, 30.597f, 0.0f);
    glVertex3f(14.9333f, 30.6716f, 0.0f);
    glVertex3f(15.0f, 30.6716f, 0.0f);
    glVertex3f(15.0f, 30.7463f, 0.0f);
    glVertex3f(15.0f, 30.8209f, 0.0f);
    glVertex3f(15.0667f, 30.8955f, 0.0f);
    glVertex3f(15.1333f, 30.8955f, 0.0f);
    glVertex3f(15.2f, 30.9701f, 0.0f);
    glVertex3f(15.2f, 31.0448f, 0.0f);
    glVertex3f(15.2667f, 31.1194f, 0.0f);
    glVertex3f(15.3333f, 31.1194f, 0.0f);
    glVertex3f(15.4f, 31.194f, 0.0f);
    glVertex3f(15.4f, 31.2687f, 0.0f);
    glVertex3f(15.4667f, 31.2687f, 0.0f);
    glVertex3f(15.4667f, 31.3433f, 0.0f);
    glVertex3f(15.6f, 31.3433f, 0.0f);
    glVertex3f(15.6f, 31.4179f, 0.0f);
    glVertex3f(15.6667f, 31.4179f, 0.0f);
    glVertex3f(15.6667f, 31.4925f, 0.0f);
    glVertex3f(15.7333f, 31.5672f, 0.0f);
    glVertex3f(15.8f, 31.5672f, 0.0f);
    glVertex3f(15.8667f, 31.6418f, 0.0f);
    glVertex3f(15.9333f, 31.7164f, 0.0f);
    glVertex3f(16.0f, 31.791f, 0.0f);
    glVertex3f(16.0667f, 31.791f, 0.0f);
    glVertex3f(16.1333f, 31.8657f, 0.0f);
    glVertex3f(16.2f, 31.9403f, 0.0f);
    glVertex3f(16.2f, 32.0149f, 0.0f);
    glVertex3f(16.2667f, 32.0149f, 0.0f);
    glVertex3f(16.3333f, 32.0149f, 0.0f);
    glVertex3f(16.4f, 32.0896f, 0.0f);
    glVertex3f(16.4667f, 32.0896f, 0.0f);
    glVertex3f(16.5333f, 32.0896f, 0.0f);
    glVertex3f(16.6667f, 32.0896f, 0.0f);
    glVertex3f(16.7333f, 32.0896f, 0.0f);
    glVertex3f(16.8f, 32.0896f, 0.0f);
    glVertex3f(16.8667f, 32.0896f, 0.0f);
    glVertex3f(17.0667f, 32.0896f, 0.0f);
    glVertex3f(17.2f, 32.0896f, 0.0f);
    glVertex3f(17.3333f, 32.0896f, 0.0f);
    glVertex3f(17.4f, 32.0896f, 0.0f);
    glVertex3f(17.4667f, 32.0896f, 0.0f);
    glVertex3f(17.5333f, 32.0896f, 0.0f);
    glVertex3f(17.6f, 32.0896f, 0.0f);
    glVertex3f(17.6667f, 32.0896f, 0.0f);
    glVertex3f(17.7333f, 32.0896f, 0.0f);
    glVertex3f(17.8f, 32.0149f, 0.0f);
    glVertex3f(17.8667f, 32.0149f, 0.0f);
    glVertex3f(17.8667f, 31.9403f, 0.0f);
    glVertex3f(18.0f, 31.8657f, 0.0f);
    glVertex3f(18.0667f, 31.791f, 0.0f);
    glVertex3f(18.2f, 31.791f, 0.0f);
    glVertex3f(18.2f, 31.7164f, 0.0f);
    glVertex3f(18.2667f, 31.6418f, 0.0f);
    glVertex3f(18.3333f, 31.5672f, 0.0f);
    glVertex3f(18.4f, 31.5672f, 0.0f);
    glVertex3f(18.4f, 31.4925f, 0.0f);
    glVertex3f(18.4667f, 31.4925f, 0.0f);
    glVertex3f(18.4667f, 31.4179f, 0.0f);
    glVertex3f(18.5333f, 31.4179f, 0.0f);
    glVertex3f(18.5333f, 31.3433f, 0.0f);
    glVertex3f(18.6f, 31.3433f, 0.0f);
    glVertex3f(18.6667f, 31.3433f, 0.0f);
    glVertex3f(18.7333f, 31.2687f, 0.0f);
    glVertex3f(18.8f, 31.194f, 0.0f);
    glVertex3f(18.8667f, 31.194f, 0.0f);
    glVertex3f(18.9333f, 31.194f, 0.0f);
    glVertex3f(19.0f, 31.1194f, 0.0f);
    glVertex3f(19.0f, 31.0448f, 0.0f);
    glVertex3f(19.0667f, 31.0448f, 0.0f);
    glVertex3f(19.1333f, 30.9701f, 0.0f);
    glVertex3f(19.2667f, 30.9701f, 0.0f);
    glVertex3f(19.3333f, 30.8955f, 0.0f);
    glVertex3f(19.4f, 30.8209f, 0.0f);
    glVertex3f(19.4667f, 30.7463f, 0.0f);
    glVertex3f(19.4667f, 30.6716f, 0.0f);
    glVertex3f(19.5333f, 30.6716f, 0.0f);
    glVertex3f(19.5333f, 30.597f, 0.0f);
    glVertex3f(19.6f, 30.597f, 0.0f);
    glVertex3f(19.6f, 30.5224f, 0.0f);
    glVertex3f(19.6667f, 30.4478f, 0.0f);
    glVertex3f(19.6667f, 30.3731f, 0.0f);
    glVertex3f(19.7333f, 30.3731f, 0.0f);
    glVertex3f(19.7333f, 30.2985f, 0.0f);
    glVertex3f(19.8f, 30.2985f, 0.0f);
    glVertex3f(19.8667f, 30.1493f, 0.0f);
    glVertex3f(20.0f, 30.1493f, 0.0f);
    glVertex3f(20.0f, 30.0746f, 0.0f);
    glVertex3f(20.0667f, 30.0f, 0.0f);
    glVertex3f(20.1333f, 30.0f, 0.0f);
    glVertex3f(20.2f, 29.9254f, 0.0f);
    glVertex3f(20.2667f, 29.9254f, 0.0f);
    glVertex3f(20.3333f, 29.8507f, 0.0f);
    glVertex3f(20.4f, 29.7761f, 0.0f);
    glVertex3f(20.4f, 29.7015f, 0.0f);
    glVertex3f(20.4667f, 29.6269f, 0.0f);
    glVertex3f(20.5333f, 29.6269f, 0.0f);
    glVertex3f(20.6f, 29.5522f, 0.0f);
    glVertex3f(20.6667f, 29.4776f, 0.0f);
    glVertex3f(20.6667f, 29.403f, 0.0f);
    glVertex3f(20.7333f, 29.3284f, 0.0f);
    glVertex3f(20.8f, 29.3284f, 0.0f);
    glVertex3f(20.8667f, 29.3284f, 0.0f);
    glVertex3f(20.8667f, 29.2537f, 0.0f);
    glVertex3f(20.9333f, 29.1791f, 0.0f);
    glVertex3f(21.0f, 29.1791f, 0.0f);
    glVertex3f(21.0f, 29.1045f, 0.0f);
    glVertex3f(21.0667f, 28.9552f, 0.0f);
    glVertex3f(21.1333f, 28.9552f, 0.0f);
    glVertex3f(21.2f, 28.806f, 0.0f);
    glVertex3f(21.2667f, 28.806f, 0.0f);
    glVertex3f(21.2667f, 28.7313f, 0.0f);
    glVertex3f(21.3333f, 28.6567f, 0.0f);
    glVertex3f(21.4f, 28.6567f, 0.0f);
    glVertex3f(21.4f, 28.5821f, 0.0f);
    glVertex3f(21.4667f, 28.5075f, 0.0f);
    glVertex3f(21.5333f, 28.4328f, 0.0f);
    glVertex3f(21.6f, 28.3582f, 0.0f);
    glVertex3f(21.6667f, 28.2836f, 0.0f);
    glVertex3f(21.7333f, 28.2836f, 0.0f);
    glVertex3f(21.7333f, 28.209f, 0.0f);
    glVertex3f(21.8f, 28.1343f, 0.0f);
    glVertex3f(21.8667f, 28.0597f, 0.0f);
    glVertex3f(21.9333f, 28.0597f, 0.0f);
    glVertex3f(21.9333f, 27.9851f, 0.0f);
    glVertex3f(22.0f, 27.9851f, 0.0f);
    glVertex3f(22.0f, 27.9104f, 0.0f);
    glVertex3f(22.0667f, 27.9104f, 0.0f);
    glVertex3f(22.0667f, 27.8358f, 0.0f);
    glVertex3f(22.1333f, 27.8358f, 0.0f);
    glVertex3f(22.2f, 27.7612f, 0.0f);
    glVertex3f(22.2667f, 27.6866f, 0.0f);
    glVertex3f(22.3333f, 27.6119f, 0.0f);
    glVertex3f(22.3333f, 27.5373f, 0.0f);
    glVertex3f(22.4f, 27.4627f, 0.0f);
    glVertex3f(22.4667f, 27.3881f, 0.0f);
    glVertex3f(22.4667f, 27.3134f, 0.0f);
    glVertex3f(22.4667f, 27.2388f, 0.0f);
    glVertex3f(22.5333f, 27.1642f, 0.0f);
    glVertex3f(22.6f, 27.2388f, 0.0f);
    glVertex3f(22.6667f, 27.3134f, 0.0f);
    glVertex3f(22.6667f, 27.3881f, 0.0f);
    glVertex3f(22.7333f, 27.5373f, 0.0f);
    glVertex3f(22.8f, 27.6119f, 0.0f);
    glVertex3f(22.8f, 27.6866f, 0.0f);
    glVertex3f(22.8667f, 27.7612f, 0.0f);
    glVertex3f(22.8667f, 27.8358f, 0.0f);
    glVertex3f(22.9333f, 27.9104f, 0.0f);
    glVertex3f(22.9333f, 27.9851f, 0.0f);
    glVertex3f(23.0f, 27.9851f, 0.0f);
    glVertex3f(23.0f, 28.1343f, 0.0f);
    glVertex3f(23.0667f, 28.209f, 0.0f);
    glVertex3f(23.1333f, 28.209f, 0.0f);
    glVertex3f(23.1333f, 28.2836f, 0.0f);
    glVertex3f(23.2f, 28.3582f, 0.0f);
    glVertex3f(23.2667f, 28.4328f, 0.0f);
    glVertex3f(23.3333f, 28.4328f, 0.0f);
    glVertex3f(23.4f, 28.5075f, 0.0f);
    glVertex3f(23.4f, 28.5821f, 0.0f);
    glVertex3f(23.4667f, 28.5821f, 0.0f);
    glVertex3f(23.5333f, 28.6567f, 0.0f);
    glVertex3f(23.6667f, 28.6567f, 0.0f);
    glVertex3f(23.6667f, 28.7313f, 0.0f);
    glVertex3f(23.7333f, 28.806f, 0.0f);
    glVertex3f(23.8f, 28.8806f, 0.0f);
    glVertex3f(23.9333f, 28.8806f, 0.0f);
    glVertex3f(24.0f, 28.9552f, 0.0f);
    glVertex3f(24.0667f, 29.0299f, 0.0f);
    glVertex3f(24.2f, 29.1045f, 0.0f);
    glVertex3f(24.2667f, 29.1045f, 0.0f);
    glVertex3f(24.3333f, 29.1791f, 0.0f);
    glVertex3f(24.4f, 29.2537f, 0.0f);
    glVertex3f(24.4667f, 29.3284f, 0.0f);
    glVertex3f(24.5333f, 29.403f, 0.0f);
    glVertex3f(24.6f, 29.4776f, 0.0f);
    glVertex3f(24.6667f, 29.5522f, 0.0f);
    glVertex3f(24.8f, 29.5522f, 0.0f);
    glVertex3f(24.8667f, 29.6269f, 0.0f);
    glVertex3f(24.9333f, 29.7015f, 0.0f);
    glVertex3f(25.0f, 29.7015f, 0.0f);
    glVertex3f(25.0f, 29.7761f, 0.0f);
    glVertex3f(25.1333f, 29.7761f, 0.0f);
    glVertex3f(25.2f, 29.8507f, 0.0f);
    glVertex3f(25.2667f, 29.9254f, 0.0f);
    glVertex3f(25.3333f, 30.0f, 0.0f);
    glVertex3f(25.4f, 30.0f, 0.0f);
    glVertex3f(25.4667f, 30.0746f, 0.0f);
    glVertex3f(25.4667f, 30.1493f, 0.0f);
    glVertex3f(25.5333f, 30.1493f, 0.0f);
    glVertex3f(25.5333f, 30.2239f, 0.0f);
    glVertex3f(25.6f, 30.2239f, 0.0f);
    glVertex3f(25.7333f, 30.2985f, 0.0f);
    glVertex3f(25.7333f, 30.3731f, 0.0f);
    glVertex3f(25.8f, 30.3731f, 0.0f);
    glVertex3f(25.8667f, 30.4478f, 0.0f);
    glVertex3f(25.9333f, 30.4478f, 0.0f);
    glVertex3f(25.9333f, 30.5224f, 0.0f);
    glVertex3f(26.0f, 30.597f, 0.0f);
    glVertex3f(26.0667f, 30.6716f, 0.0f);
    glVertex3f(26.1333f, 30.6716f, 0.0f);
    glVertex3f(26.1333f, 30.7463f, 0.0f);
    glVertex3f(26.2f, 30.8209f, 0.0f);
    glVertex3f(26.2667f, 30.8209f, 0.0f);
    glVertex3f(26.3333f, 30.8955f, 0.0f);
    glVertex3f(26.4f, 30.8955f, 0.0f);
    glVertex3f(26.4667f, 30.9701f, 0.0f);
    glVertex3f(26.5333f, 31.0448f, 0.0f);
    glVertex3f(26.6f, 31.1194f, 0.0f);
    glVertex3f(26.6667f, 31.194f, 0.0f);
    glVertex3f(26.7333f, 31.2687f, 0.0f);
    glVertex3f(26.8f, 31.3433f, 0.0f);
    glVertex3f(26.8667f, 31.4179f, 0.0f);
    glVertex3f(26.9333f, 31.4925f, 0.0f);
    glVertex3f(27.0f, 31.5672f, 0.0f);
    glVertex3f(27.0667f, 31.5672f, 0.0f);
    glVertex3f(27.1333f, 31.6418f, 0.0f);
    glVertex3f(27.1333f, 31.7164f, 0.0f);
    glVertex3f(27.2f, 31.7164f, 0.0f);
    glVertex3f(27.2667f, 31.791f, 0.0f);
    glVertex3f(27.3333f, 31.791f, 0.0f);
    glVertex3f(27.3333f, 31.9403f, 0.0f);
    glVertex3f(27.4f, 32.0149f, 0.0f);
    glVertex3f(27.4667f, 32.0149f, 0.0f);
    glVertex3f(27.5333f, 32.0896f, 0.0f);
    glVertex3f(27.5333f, 32.1642f, 0.0f);
    glVertex3f(27.6f, 32.2388f, 0.0f);
    glVertex3f(27.6667f, 32.2388f, 0.0f);
    glVertex3f(27.6667f, 32.3134f, 0.0f);
    glVertex3f(27.7333f, 32.3134f, 0.0f);
    glVertex3f(27.7333f, 32.4627f, 0.0f);
    glVertex3f(27.8f, 32.4627f, 0.0f);
    glVertex3f(27.8667f, 32.5373f, 0.0f);
    glVertex3f(27.9333f, 32.5373f, 0.0f);
    glVertex3f(27.9333f, 32.6119f, 0.0f);
    glVertex3f(28.0f, 32.6119f, 0.0f);
    glVertex3f(28.0667f, 32.6866f, 0.0f);
    glVertex3f(28.1333f, 32.7612f, 0.0f);
    glVertex3f(28.2f, 32.8358f, 0.0f);
    glVertex3f(28.2667f, 32.8358f, 0.0f);
    glVertex3f(28.3333f, 32.9104f, 0.0f);
    glVertex3f(28.3333f, 32.9851f, 0.0f);
    glVertex3f(28.4f, 32.9851f, 0.0f);
    glVertex3f(28.4f, 33.0597f, 0.0f);
    glVertex3f(28.4667f, 33.0597f, 0.0f);
    glVertex3f(28.5333f, 33.1343f, 0.0f);
    glVertex3f(28.6f, 33.1343f, 0.0f);
    glVertex3f(28.6f, 33.209f, 0.0f);
    glVertex3f(28.6667f, 33.2836f, 0.0f);
    glVertex3f(28.7333f, 33.2836f, 0.0f);
    glVertex3f(28.8f, 33.3582f, 0.0f);
    glVertex3f(28.8667f, 33.3582f, 0.0f);
    glVertex3f(28.8667f, 33.4328f, 0.0f);
    glVertex3f(28.9333f, 33.4328f, 0.0f);
    glVertex3f(29.0f, 33.5075f, 0.0f);
    glVertex3f(29.0667f, 33.5821f, 0.0f);
    glVertex3f(29.1333f, 33.6567f, 0.0f);
    glVertex3f(29.2f, 33.6567f, 0.0f);
    glVertex3f(29.2667f, 33.7313f, 0.0f);
    glVertex3f(29.3333f, 33.806f, 0.0f);
    glVertex3f(29.4f, 33.806f, 0.0f);
    glVertex3f(29.4667f, 33.806f, 0.0f);
    glVertex3f(29.5333f, 33.8806f, 0.0f);
    glVertex3f(29.6f, 33.8806f, 0.0f);
    glVertex3f(29.6667f, 33.9552f, 0.0f);
    glVertex3f(29.7333f, 33.9552f, 0.0f);
    glVertex3f(29.7333f, 34.0299f, 0.0f);
    glVertex3f(29.8f, 34.1045f, 0.0f);
    glVertex3f(29.8667f, 34.1045f, 0.0f);
    glVertex3f(29.9333f, 34.1045f, 0.0f);
    glVertex3f(30.0f, 34.1791f, 0.0f);
    glVertex3f(30.0667f, 34.1791f, 0.0f);
    glVertex3f(30.1333f, 34.1791f, 0.0f);
    glVertex3f(30.2f, 34.1791f, 0.0f);
    glVertex3f(30.2667f, 34.1791f, 0.0f);
    glVertex3f(30.3333f, 34.1791f, 0.0f);
    glVertex3f(30.4f, 34.1791f, 0.0f);
    glVertex3f(30.4667f, 34.1045f, 0.0f);
    glVertex3f(30.5333f, 34.1045f, 0.0f);
    glVertex3f(30.6f, 34.1045f, 0.0f);
    glVertex3f(30.7333f, 34.0299f, 0.0f);
    glVertex3f(30.8f, 34.0299f, 0.0f);
    glVertex3f(30.8667f, 34.0299f, 0.0f);
    glVertex3f(30.9333f, 34.0299f, 0.0f);
    glVertex3f(31.0f, 34.0299f, 0.0f);
    glVertex3f(31.0f, 33.9552f, 0.0f);
    glVertex3f(31.0667f, 33.8806f, 0.0f);
    glVertex3f(31.1333f, 33.8806f, 0.0f);
    glVertex3f(31.2f, 33.8806f, 0.0f);
    glVertex3f(31.2667f, 33.806f, 0.0f);
    glVertex3f(31.3333f, 33.806f, 0.0f);
    glVertex3f(31.4f, 33.806f, 0.0f);
    glVertex3f(31.4667f, 33.806f, 0.0f);
    glVertex3f(31.5333f, 33.7313f, 0.0f);
    glVertex3f(31.5333f, 33.6567f, 0.0f);
    glVertex3f(31.6f, 33.6567f, 0.0f);
    glVertex3f(31.6f, 33.5821f, 0.0f);
    glVertex3f(31.7333f, 33.5821f, 0.0f);
    glVertex3f(31.8f, 33.5821f, 0.0f);
    glVertex3f(31.8667f, 33.5821f, 0.0f);
    glVertex3f(31.9333f, 33.5075f, 0.0f);
    glVertex3f(31.9333f, 33.4328f, 0.0f);
    glVertex3f(32.0f, 33.4328f, 0.0f);
    glVertex3f(32.0667f, 33.4328f, 0.0f);
    glVertex3f(32.1333f, 33.3582f, 0.0f);
    glVertex3f(32.2f, 33.3582f, 0.0f);
    glVertex3f(32.2667f, 33.2836f, 0.0f);
    glVertex3f(32.3333f, 33.209f, 0.0f);
    glVertex3f(32.4f, 33.1343f, 0.0f);
    glVertex3f(32.4667f, 33.0597f, 0.0f);
    glVertex3f(32.5333f, 33.0597f, 0.0f);
    glVertex3f(32.6f, 32.9851f, 0.0f);
    glVertex3f(32.6667f, 32.9104f, 0.0f);
    glVertex3f(32.8f, 32.8358f, 0.0f);
    glVertex3f(32.8f, 32.7612f, 0.0f);
    glVertex3f(32.8667f, 32.7612f, 0.0f);
    glVertex3f(32.9333f, 32.7612f, 0.0f);
    glVertex3f(33.0f, 32.6866f, 0.0f);
    glVertex3f(33.0667f, 32.6866f, 0.0f);
    glVertex3f(33.0667f, 32.6119f, 0.0f);
    glVertex3f(33.1333f, 32.5373f, 0.0f);
    glVertex3f(33.2f, 32.5373f, 0.0f);
    glVertex3f(33.2f, 32.4627f, 0.0f);
    glVertex3f(33.2f, 32.3881f, 0.0f);
    glVertex3f(33.2667f, 32.3134f, 0.0f);
    glVertex3f(33.2667f, 32.2388f, 0.0f);
    glVertex3f(33.4f, 32.2388f, 0.0f);
    glVertex3f(33.4f, 32.1642f, 0.0f);
    glVertex3f(33.4667f, 32.0896f, 0.0f);
    glVertex3f(33.5333f, 32.0896f, 0.0f);
    glVertex3f(33.6f, 32.0149f, 0.0f);
    glVertex3f(33.6667f, 32.0149f, 0.0f);
    glVertex3f(33.8f, 31.9403f, 0.0f);
    glVertex3f(33.8f, 31.8657f, 0.0f);
    glVertex3f(33.8667f, 31.791f, 0.0f);
    glVertex3f(33.9333f, 31.791f, 0.0f);
    glVertex3f(34.0f, 31.7164f, 0.0f);
    glVertex3f(34.0f, 31.6418f, 0.0f);
    glVertex3f(34.0667f, 31.6418f, 0.0f);
    glVertex3f(34.0667f, 31.5672f, 0.0f);
    glVertex3f(34.1333f, 31.5672f, 0.0f);
    glVertex3f(34.1333f, 31.4925f, 0.0f);
    glVertex3f(34.2f, 31.4925f, 0.0f);
    glVertex3f(34.2667f, 31.4179f, 0.0f);
    glVertex3f(34.2667f, 31.3433f, 0.0f);
    glVertex3f(34.3333f, 31.3433f, 0.0f);
    glVertex3f(34.3333f, 31.2687f, 0.0f);
    glVertex3f(34.4f, 31.194f, 0.0f);
    glVertex3f(34.4667f, 31.1194f, 0.0f);
    glVertex3f(34.5333f, 31.0448f, 0.0f);
    glVertex3f(34.5333f, 30.9701f, 0.0f);
    glVertex3f(34.6f, 30.9701f, 0.0f);
    glVertex3f(34.6f, 30.8955f, 0.0f);
    glVertex3f(34.6f, 30.8209f, 0.0f);
    glVertex3f(34.6667f, 30.7463f, 0.0f);
    glVertex3f(34.7333f, 30.7463f, 0.0f);
    glVertex3f(34.7333f, 30.6716f, 0.0f);
    glVertex3f(34.7333f, 30.597f, 0.0f);
    glVertex3f(34.8f, 30.5224f, 0.0f);
    glVertex3f(34.8f, 30.4478f, 0.0f);
    glVertex3f(34.8667f, 30.3731f, 0.0f);
    glVertex3f(34.9333f, 30.2985f, 0.0f);
    glVertex3f(35.0f, 30.2239f, 0.0f);
    glVertex3f(35.0f, 30.1493f, 0.0f);
    glVertex3f(35.0667f, 30.0f, 0.0f);
    glVertex3f(35.1333f, 30.0f, 0.0f);
    glVertex3f(35.1333f, 29.9254f, 0.0f);
    glVertex3f(35.2f, 29.9254f, 0.0f);
    glVertex3f(35.2f, 29.8507f, 0.0f);
    glVertex3f(35.2f, 29.7761f, 0.0f);
    glVertex3f(35.2667f, 29.7015f, 0.0f);
    glVertex3f(35.2667f, 29.6269f, 0.0f);
    glVertex3f(35.3333f, 29.6269f, 0.0f);
    glVertex3f(35.4f, 29.5522f, 0.0f);
    glVertex3f(35.4f, 29.4776f, 0.0f);
    glVertex3f(35.4667f, 29.403f, 0.0f);
    glVertex3f(35.4667f, 29.3284f, 0.0f);
    glVertex3f(35.6f, 29.2537f, 0.0f);
    glVertex3f(35.6f, 29.1791f, 0.0f);
    glVertex3f(35.6667f, 29.1791f, 0.0f);
    glVertex3f(35.6667f, 29.1045f, 0.0f);
    glVertex3f(35.7333f, 29.0299f, 0.0f);
    glVertex3f(35.8f, 29.0299f, 0.0f);
    glVertex3f(35.8f, 28.9552f, 0.0f);
    glVertex3f(35.8667f, 28.8806f, 0.0f);
    glVertex3f(35.9333f, 28.7313f, 0.0f);
    glVertex3f(36.0f, 28.7313f, 0.0f);
    glVertex3f(36.0f, 28.6567f, 0.0f);
    glVertex3f(36.0f, 28.5821f, 0.0f);
    glVertex3f(36.0667f, 28.4328f, 0.0f);
    glVertex3f(36.1333f, 28.3582f, 0.0f);
    glVertex3f(36.2f, 28.3582f, 0.0f);
    glVertex3f(36.2f, 28.2836f, 0.0f);
    glVertex3f(36.2667f, 28.209f, 0.0f);
    glVertex3f(36.3333f, 28.1343f, 0.0f);
    glVertex3f(36.3333f, 28.0597f, 0.0f);
    glVertex3f(36.4f, 28.0597f, 0.0f);
    glVertex3f(36.4667f, 27.9851f, 0.0f);
    glVertex3f(36.5333f, 27.9851f, 0.0f);
    glVertex3f(36.5333f, 27.9104f, 0.0f);
    glVertex3f(36.6f, 27.9104f, 0.0f);
    glVertex3f(36.6f, 27.8358f, 0.0f);
    glVertex3f(36.7333f, 27.7612f, 0.0f);
    glVertex3f(36.8f, 27.6866f, 0.0f);
    glVertex3f(36.8667f, 27.6119f, 0.0f);
    glVertex3f(36.8667f, 27.5373f, 0.0f);
    glVertex3f(37.0f, 27.5373f, 0.0f);
    glVertex3f(37.0f, 27.4627f, 0.0f);
    glVertex3f(37.0667f, 27.4627f, 0.0f);
    glVertex3f(37.0667f, 27.3881f, 0.0f);
    glVertex3f(37.1333f, 27.3881f, 0.0f);
    glVertex3f(37.2f, 27.3881f, 0.0f);
    glVertex3f(37.2667f, 27.3134f, 0.0f);
    glVertex3f(37.2667f, 27.2388f, 0.0f);
    glVertex3f(37.3333f, 27.1642f, 0.0f);
    glVertex3f(37.4f, 27.1642f, 0.0f);
    glVertex3f(37.4667f, 27.0896f, 0.0f);
    glVertex3f(37.5333f, 27.0149f, 0.0f);
    glVertex3f(37.6f, 27.0149f, 0.0f);
    glVertex3f(37.6f, 26.9403f, 0.0f);
    glVertex3f(37.6667f, 26.9403f, 0.0f);
    glVertex3f(37.7333f, 26.8657f, 0.0f);
    glVertex3f(37.8f, 26.791f, 0.0f);
    glVertex3f(37.8f, 26.7164f, 0.0f);
    glVertex3f(37.8667f, 26.7164f, 0.0f);
    glVertex3f(37.8667f, 26.6418f, 0.0f);
    glVertex3f(37.9333f, 26.5672f, 0.0f);
    glVertex3f(38.0f, 26.5672f, 0.0f);
    glVertex3f(38.0667f, 26.4925f, 0.0f);
    glVertex3f(38.1333f, 26.4179f, 0.0f);
    glVertex3f(38.2f, 26.3433f, 0.0f);
    glVertex3f(38.2667f, 26.3433f, 0.0f);
    glVertex3f(38.3333f, 26.2687f, 0.0f);
    glVertex3f(38.4667f, 26.2687f, 0.0f);
    glVertex3f(38.5333f, 26.2687f, 0.0f);
    glVertex3f(38.6f, 26.3433f, 0.0f);
    glVertex3f(38.6667f, 26.3433f, 0.0f);
    glVertex3f(38.7333f, 26.4179f, 0.0f);
    glVertex3f(38.7333f, 26.4925f, 0.0f);
    glVertex3f(38.8f, 26.6418f, 0.0f);
    glVertex3f(38.8667f, 26.6418f, 0.0f);
    glVertex3f(38.9333f, 26.7164f, 0.0f);
    glVertex3f(39.0f, 26.791f, 0.0f);
    glVertex3f(39.0f, 26.9403f, 0.0f);
    glVertex3f(39.0667f, 27.0149f, 0.0f);
    glVertex3f(39.1333f, 27.0149f, 0.0f);
    glVertex3f(39.1333f, 27.0896f, 0.0f);
    glVertex3f(39.1333f, 27.1642f, 0.0f);
    glVertex3f(39.2f, 27.3134f, 0.0f);
    glVertex3f(39.2667f, 27.3881f, 0.0f);
    glVertex3f(39.3333f, 27.3881f, 0.0f);
    glVertex3f(39.3333f, 27.4627f, 0.0f);
    glVertex3f(39.3333f, 27.5373f, 0.0f);
    glVertex3f(39.4f, 27.6119f, 0.0f);
    glVertex3f(39.4667f, 27.6866f, 0.0f);
    glVertex3f(39.4667f, 27.7612f, 0.0f);
    glVertex3f(39.5333f, 27.8358f, 0.0f);
    glVertex3f(39.6f, 27.8358f, 0.0f);
    glVertex3f(39.6f, 27.9104f, 0.0f);
    glVertex3f(39.6667f, 27.9104f, 0.0f);
    glVertex3f(39.6667f, 27.9851f, 0.0f);
    glVertex3f(39.8f, 28.0597f, 0.0f);
    glVertex3f(39.8667f, 28.0597f, 0.0f);
    glVertex3f(39.8667f, 28.1343f, 0.0f);
    glVertex3f(39.9333f, 28.1343f, 0.0f);
    glVertex3f(39.9333f, 28.209f, 0.0f);
    glVertex3f(40.0f, 28.209f, 0.0f);
    glVertex3f(40.0667f, 28.2836f, 0.0f);
    glVertex3f(40.2f, 28.3582f, 0.0f);
    glVertex3f(40.2f, 28.4328f, 0.0f);
    glVertex3f(40.2667f, 28.5075f, 0.0f);
    glVertex3f(40.3333f, 28.5075f, 0.0f);
    glVertex3f(40.4f, 28.5821f, 0.0f);
    glVertex3f(40.4667f, 28.5821f, 0.0f);
    glVertex3f(40.5333f, 28.6567f, 0.0f);
    glVertex3f(40.6f, 28.7313f, 0.0f);
    glVertex3f(40.7333f, 28.7313f, 0.0f);
    glVertex3f(40.8f, 28.806f, 0.0f);
    glVertex3f(40.8667f, 28.8806f, 0.0f);
    glVertex3f(40.9333f, 28.9552f, 0.0f);
    glVertex3f(41.0667f, 28.9552f, 0.0f);
    glVertex3f(41.1333f, 29.0299f, 0.0f);
    glVertex3f(41.2f, 29.1045f, 0.0f);
    glVertex3f(41.2667f, 29.1045f, 0.0f);
    glVertex3f(41.3333f, 29.1791f, 0.0f);
    glVertex3f(41.4f, 29.1791f, 0.0f);
    glVertex3f(41.4f, 29.2537f, 0.0f);
    glVertex3f(41.4667f, 29.3284f, 0.0f);
    glVertex3f(41.5333f, 29.3284f, 0.0f);
    glVertex3f(41.6f, 29.403f, 0.0f);
    glVertex3f(41.6667f, 29.403f, 0.0f);
    glVertex3f(41.8f, 29.4776f, 0.0f);
    glVertex3f(41.8f, 29.5522f, 0.0f);
    glVertex3f(41.8667f, 29.5522f, 0.0f);
    glVertex3f(41.9333f, 29.6269f, 0.0f);
    glVertex3f(42.0f, 29.6269f, 0.0f);
    glVertex3f(42.0667f, 29.6269f, 0.0f);
    glVertex3f(42.1333f, 29.6269f, 0.0f);
    glVertex3f(42.2f, 29.7015f, 0.0f);
    glVertex3f(42.2f, 29.7761f, 0.0f);
    glVertex3f(42.2667f, 29.7761f, 0.0f);
    glVertex3f(42.3333f, 29.7761f, 0.0f);
    glVertex3f(42.4f, 29.8507f, 0.0f);
    glVertex3f(42.4667f, 29.8507f, 0.0f);
    glVertex3f(42.5333f, 29.8507f, 0.0f);
    glVertex3f(42.6f, 29.8507f, 0.0f);
    glVertex3f(42.7333f, 29.7761f, 0.0f);
    glVertex3f(42.8f, 29.7761f, 0.0f);
    glVertex3f(42.8667f, 29.7761f, 0.0f);
    glVertex3f(43.0f, 29.7015f, 0.0f);
    glVertex3f(43.1333f, 29.6269f, 0.0f);
    glVertex3f(43.2f, 29.6269f, 0.0f);
    glVertex3f(43.2667f, 29.5522f, 0.0f);
    glVertex3f(43.3333f, 29.5522f, 0.0f);
    glVertex3f(43.4f, 29.4776f, 0.0f);
    glVertex3f(43.4667f, 29.4776f, 0.0f);
    glVertex3f(43.6f, 29.403f, 0.0f);
    glVertex3f(43.6667f, 29.3284f, 0.0f);
    glVertex3f(43.7333f, 29.3284f, 0.0f);
    glVertex3f(43.7333f, 29.2537f, 0.0f);
    glVertex3f(43.8667f, 29.2537f, 0.0f);
    glVertex3f(43.9333f, 29.2537f, 0.0f);
    glVertex3f(43.9333f, 29.1791f, 0.0f);
    glVertex3f(44.0f, 29.1791f, 0.0f);
    glVertex3f(44.0f, 29.1045f, 0.0f);
    glVertex3f(44.0667f, 29.0299f, 0.0f);
    glVertex3f(44.1333f, 28.9552f, 0.0f);
    glVertex3f(44.2f, 28.9552f, 0.0f);
    glVertex3f(44.2667f, 28.8806f, 0.0f);
    glVertex3f(44.3333f, 28.806f, 0.0f);
    glVertex3f(44.4f, 28.7313f, 0.0f);
    glVertex3f(44.4f, 28.6567f, 0.0f);
    glVertex3f(44.4667f, 28.5821f, 0.0f);
    glVertex3f(44.5333f, 28.5821f, 0.0f);
    glVertex3f(44.5333f, 28.5075f, 0.0f);
    glVertex3f(44.6f, 28.5075f, 0.0f);
    glVertex3f(44.6f, 28.3582f, 0.0f);
    glVertex3f(44.6667f, 28.3582f, 0.0f);
    glVertex3f(44.6667f, 28.2836f, 0.0f);
    glVertex3f(44.7333f, 28.2836f, 0.0f);
    glVertex3f(44.7333f, 28.209f, 0.0f);
    glVertex3f(44.8f, 28.209f, 0.0f);
    glVertex3f(44.8f, 28.1343f, 0.0f);
    glVertex3f(44.8667f, 28.0597f, 0.0f);
    glVertex3f(44.9333f, 27.9851f, 0.0f);
    glVertex3f(44.9333f, 27.8358f, 0.0f);
    glVertex3f(45.0f, 27.8358f, 0.0f);
    glVertex3f(45.0667f, 27.7612f, 0.0f);
    glVertex3f(45.1333f, 27.6866f, 0.0f);
    glVertex3f(45.2f, 27.5373f, 0.0f);
    glVertex3f(45.2667f, 27.4627f, 0.0f);
    glVertex3f(45.2667f, 27.3881f, 0.0f);
    glVertex3f(45.3333f, 27.3134f, 0.0f);
    glVertex3f(45.4f, 27.2388f, 0.0f);
    glVertex3f(45.4f, 27.1642f, 0.0f);
    glVertex3f(45.4667f, 27.0896f, 0.0f);
    glVertex3f(45.5333f, 27.0149f, 0.0f);
    glVertex3f(45.6f, 26.9403f, 0.0f);
    glVertex3f(45.6f, 26.8657f, 0.0f);
    glVertex3f(45.6667f, 26.791f, 0.0f);
    glVertex3f(45.7333f, 26.791f, 0.0f);
    glVertex3f(45.7333f, 26.7164f, 0.0f);
    glVertex3f(45.8f, 26.6418f, 0.0f);
    glVertex3f(45.8f, 26.5672f, 0.0f);
    glVertex3f(45.8667f, 26.5672f, 0.0f);
    glVertex3f(45.9333f, 26.4925f, 0.0f);
    glVertex3f(46.0f, 26.4925f, 0.0f);
    glVertex3f(46.0f, 26.4179f, 0.0f);
    glVertex3f(46.0667f, 26.3433f, 0.0f);
    glVertex3f(46.1333f, 26.2687f, 0.0f);
    glVertex3f(46.2f, 26.2687f, 0.0f);
    glVertex3f(46.2667f, 26.194f, 0.0f);
    glVertex3f(46.3333f, 26.1194f, 0.0f);
    glVertex3f(46.4f, 26.1194f, 0.0f);
    glVertex3f(46.4f, 26.0448f, 0.0f);
    glVertex3f(46.4667f, 26.0448f, 0.0f);
    glVertex3f(46.4667f, 25.9701f, 0.0f);
    glVertex3f(46.5333f, 25.9701f, 0.0f);
    glVertex3f(46.6f, 25.8209f, 0.0f);
    glVertex3f(46.6f, 25.7463f, 0.0f);
    glVertex3f(46.6667f, 25.6716f, 0.0f);
    glVertex3f(46.7333f, 25.597f, 0.0f);
    glVertex3f(46.8f, 25.597f, 0.0f);
    glVertex3f(46.8f, 25.5224f, 0.0f);
    glVertex3f(46.8667f, 25.5224f, 0.0f);
    glVertex3f(46.8667f, 25.3731f, 0.0f);
    glVertex3f(46.9333f, 25.3731f, 0.0f);
    glVertex3f(46.9333f, 25.2985f, 0.0f);
    glVertex3f(47.0f, 25.2985f, 0.0f);
    glVertex3f(47.0667f, 25.2239f, 0.0f);
    glVertex3f(47.0667f, 25.1493f, 0.0f);
    glVertex3f(47.1333f, 25.0746f, 0.0f);
    glVertex3f(47.2f, 24.9254f, 0.0f);
    glVertex3f(47.2667f, 24.8507f, 0.0f);
    glVertex3f(47.2667f, 24.7761f, 0.0f);
    glVertex3f(47.3333f, 24.7761f, 0.0f);
    glVertex3f(47.3333f, 24.7015f, 0.0f);
    glVertex3f(47.4f, 24.5522f, 0.0f);
    glVertex3f(47.4667f, 24.4776f, 0.0f);
    glVertex3f(47.4667f, 24.403f, 0.0f);
    glVertex3f(47.5333f, 24.403f, 0.0f);
    glVertex3f(47.5333f, 24.3284f, 0.0f);
    glVertex3f(47.6f, 24.3284f, 0.0f);
    glVertex3f(47.6667f, 24.2537f, 0.0f);
    glVertex3f(47.6667f, 24.1791f, 0.0f);
    glVertex3f(47.7333f, 24.1791f, 0.0f);
    glVertex3f(47.7333f, 24.1045f, 0.0f);
    glVertex3f(47.8f, 24.0299f, 0.0f);
    glVertex3f(47.8667f, 23.9552f, 0.0f);
    glVertex3f(47.8667f, 23.8806f, 0.0f);
    glVertex3f(47.9333f, 23.8806f, 0.0f);
    glVertex3f(47.9333f, 23.806f, 0.0f);
    glVertex3f(47.9333f, 23.7313f, 0.0f);
    glVertex3f(48.0f, 23.6567f, 0.0f);
    glVertex3f(48.0f, 23.5821f, 0.0f);
    glVertex3f(48.0667f, 23.5821f, 0.0f);
    glVertex3f(48.1333f, 23.5075f, 0.0f);
    glVertex3f(48.1333f, 23.3582f, 0.0f);
    glVertex3f(48.2f, 23.2836f, 0.0f);
    glVertex3f(48.2667f, 23.209f, 0.0f);
    glVertex3f(48.3333f, 23.1343f, 0.0f);
    glVertex3f(48.3333f, 23.0597f, 0.0f);
    glVertex3f(48.4f, 22.9104f, 0.0f);
    glVertex3f(48.4667f, 22.9104f, 0.0f);
    glVertex3f(48.4667f, 22.8358f, 0.0f);
    glVertex3f(48.5333f, 22.8358f, 0.0f);
    glVertex3f(48.5333f, 22.7612f, 0.0f);
    glVertex3f(48.5333f, 22.6866f, 0.0f);
    glVertex3f(48.6f, 22.6119f, 0.0f);
    glVertex3f(48.6667f, 22.5373f, 0.0f);
    glVertex3f(48.7333f, 22.5373f, 0.0f);
    glVertex3f(48.7333f, 22.4627f, 0.0f);
    glVertex3f(48.7333f, 22.3881f, 0.0f);
    glVertex3f(48.8f, 22.3881f, 0.0f);
    glVertex3f(48.8667f, 22.3134f, 0.0f);
    glVertex3f(48.9333f, 22.2388f, 0.0f);
    glVertex3f(48.9333f, 22.1642f, 0.0f);
    glVertex3f(49.0f, 22.0896f, 0.0f);
    glVertex3f(49.0667f, 22.0896f, 0.0f);
    glVertex3f(49.1333f, 21.9403f, 0.0f);
    glVertex3f(49.2f, 21.8657f, 0.0f);
    glVertex3f(49.2667f, 21.791f, 0.0f);
    glVertex3f(49.3333f, 21.7164f, 0.0f);
    glVertex3f(49.3333f, 21.6418f, 0.0f);
    glVertex3f(49.4f, 21.6418f, 0.0f);
    glVertex3f(49.4667f, 21.5672f, 0.0f);
    glVertex3f(49.5333f, 21.4925f, 0.0f);
    glVertex3f(49.5333f, 21.4179f, 0.0f);
    glVertex3f(49.6667f, 21.4179f, 0.0f);
    glVertex3f(49.6667f, 21.3433f, 0.0f);
    glVertex3f(49.7333f, 21.2687f, 0.0f);
    glVertex3f(49.7333f, 21.194f, 0.0f);
    glVertex3f(49.8f, 21.194f, 0.0f);
    glVertex3f(49.8f, 21.1194f, 0.0f);
    glVertex3f(49.8667f, 21.0448f, 0.0f);
    glVertex3f(49.9333f, 20.9701f, 0.0f);
    glVertex3f(50.0f, 20.8209f, 0.0f);
    glVertex3f(50.0667f, 20.7463f, 0.0f);
    glVertex3f(50.1333f, 20.7463f, 0.0f);
    glVertex3f(50.1333f, 20.6716f, 0.0f);
    glVertex3f(50.2f, 20.597f, 0.0f);
    glVertex3f(50.2f, 20.5224f, 0.0f);
    glVertex3f(50.2667f, 20.5224f, 0.0f);
    glVertex3f(50.2667f, 20.4478f, 0.0f);
    glVertex3f(50.3333f, 20.3731f, 0.0f);
    glVertex3f(50.4f, 20.2985f, 0.0f);
    glVertex3f(50.4667f, 20.2239f, 0.0f);
    glVertex3f(50.4667f, 20.1493f, 0.0f);
    glVertex3f(50.5333f, 20.0746f, 0.0f);
    glVertex3f(50.6f, 20.0f, 0.0f);
    glVertex3f(50.6667f, 19.9254f, 0.0f);
    glVertex3f(50.7333f, 19.7761f, 0.0f);
    glVertex3f(50.8f, 19.7015f, 0.0f);
    glVertex3f(50.8f, 19.6269f, 0.0f);
    glVertex3f(50.8667f, 19.6269f, 0.0f);
    glVertex3f(50.8667f, 19.5522f, 0.0f);
    glVertex3f(50.8667f, 19.4776f, 0.0f);
    glVertex3f(50.8667f, 19.403f, 0.0f);
    glVertex3f(50.9333f, 19.403f, 0.0f);
    glVertex3f(50.9333f, 19.3284f, 0.0f);
    glVertex3f(51.0f, 19.2537f, 0.0f);
    glVertex3f(51.0f, 19.1791f, 0.0f);
    glVertex3f(51.0667f, 19.1045f, 0.0f);
    glVertex3f(51.0667f, 18.9552f, 0.0f);
    glVertex3f(51.0667f, 18.806f, 0.0f);
    glVertex3f(51.1333f, 18.806f, 0.0f);
    glVertex3f(51.1333f, 18.7313f, 0.0f);
    glVertex3f(51.2f, 18.5821f, 0.0f);
    glVertex3f(51.2f, 18.5075f, 0.0f);
    glVertex3f(51.2667f, 18.3582f, 0.0f);
    glVertex3f(51.3333f, 18.2836f, 0.0f);
    glVertex3f(51.3333f, 18.209f, 0.0f);
    glVertex3f(51.3333f, 18.1343f, 0.0f);
    glVertex3f(51.3333f, 18.0597f, 0.0f);
    glVertex3f(51.4f, 17.9851f, 0.0f);
    glVertex3f(51.4667f, 17.9104f, 0.0f);
    glVertex3f(51.5333f, 17.7612f, 0.0f);
    glVertex3f(51.5333f, 17.6866f, 0.0f);
    glVertex3f(51.6f, 17.6119f, 0.0f);
    glVertex3f(51.6667f, 17.5373f, 0.0f);
    glVertex3f(51.7333f, 17.3881f, 0.0f);
    glVertex3f(51.7333f, 17.3134f, 0.0f);
    glVertex3f(51.8f, 17.1642f, 0.0f);
    glVertex3f(51.8667f, 17.0896f, 0.0f);
    glVertex3f(51.9333f, 16.8657f, 0.0f);
    glVertex3f(51.9333f, 16.791f, 0.0f);
    glVertex3f(52.0f, 16.7164f, 0.0f);
    glVertex3f(52.0667f, 16.6418f, 0.0f);
    glVertex3f(52.0667f, 16.4925f, 0.0f);
    glVertex3f(52.1333f, 16.4179f, 0.0f);
    glVertex3f(52.1333f, 16.3433f, 0.0f);
    glVertex3f(52.2f, 16.2687f, 0.0f);
    glVertex3f(52.2f, 16.194f, 0.0f);
    glVertex3f(52.2f, 16.1194f, 0.0f);
    glVertex3f(52.2f, 16.0448f, 0.0f);
    glVertex3f(52.2f, 15.9701f, 0.0f);
    glVertex3f(52.2f, 15.8955f, 0.0f);
    glVertex3f(52.1333f, 15.8955f, 0.0f);
    glVertex3f(52.0667f, 15.8209f, 0.0f);
    glVertex3f(52.0f, 15.8209f, 0.0f);
    glVertex3f(51.8667f, 15.7463f, 0.0f);
    glVertex3f(51.8f, 15.7463f, 0.0f);
    glVertex3f(51.7333f, 15.7463f, 0.0f);
    glVertex3f(51.6f, 15.7463f, 0.0f);
    glVertex3f(51.5333f, 15.7463f, 0.0f);
    glVertex3f(51.4667f, 15.7463f, 0.0f);
    glVertex3f(51.4f, 15.6716f, 0.0f);
    glVertex3f(51.3333f, 15.6716f, 0.0f);
    glVertex3f(51.2667f, 15.6716f, 0.0f);
    glVertex3f(51.2f, 15.597f, 0.0f);
    glVertex3f(51.1333f, 15.597f, 0.0f);
    glVertex3f(51.0667f, 15.597f, 0.0f);
    glVertex3f(50.9333f, 15.5224f, 0.0f);
    glVertex3f(50.8667f, 15.5224f, 0.0f);
    glVertex3f(50.8f, 15.5224f, 0.0f);
    glVertex3f(50.6667f, 15.4478f, 0.0f);
    glVertex3f(50.5333f, 15.4478f, 0.0f);
    glVertex3f(50.4f, 15.4478f, 0.0f);
    glVertex3f(50.3333f, 15.4478f, 0.0f);
    glVertex3f(50.2667f, 15.4478f, 0.0f);
    glVertex3f(50.2f, 15.3731f, 0.0f);
    glVertex3f(50.0667f, 15.2985f, 0.0f);
    glVertex3f(50.0f, 15.2985f, 0.0f);
    glVertex3f(49.8f, 15.2985f, 0.0f);
    glVertex3f(49.7333f, 15.2985f, 0.0f);
    glVertex3f(49.6f, 15.2239f, 0.0f);
    glVertex3f(49.5333f, 15.2239f, 0.0f);
    glVertex3f(49.4f, 15.2239f, 0.0f);
    glVertex3f(49.1333f, 15.1493f, 0.0f);
    glVertex3f(49.0667f, 15.1493f, 0.0f);
    glVertex3f(48.8667f, 15.0746f, 0.0f);
    glVertex3f(48.7333f, 15.0746f, 0.0f);
    glVertex3f(48.6667f, 15.0f, 0.0f);
    glVertex3f(48.5333f, 15.0f, 0.0f);
    glVertex3f(48.4667f, 15.0f, 0.0f);
    glVertex3f(48.4f, 14.9254f, 0.0f);
    glVertex3f(48.2667f, 14.9254f, 0.0f);
    glVertex3f(48.2f, 14.9254f, 0.0f);
    glVertex3f(48.0667f, 14.9254f, 0.0f);
    glVertex3f(48.0f, 14.9254f, 0.0f);
    glVertex3f(47.8667f, 14.9254f, 0.0f);
    glVertex3f(47.7333f, 14.8507f, 0.0f);
    glVertex3f(47.6f, 14.7761f, 0.0f);
    glVertex3f(47.5333f, 14.7761f, 0.0f);
    glVertex3f(47.4667f, 14.7761f, 0.0f);
    glVertex3f(47.2667f, 14.7761f, 0.0f);
    glVertex3f(47.0667f, 14.7761f, 0.0f);
    glVertex3f(46.8667f, 14.7761f, 0.0f);
    glVertex3f(46.6667f, 14.7761f, 0.0f);
    glVertex3f(46.4667f, 14.7761f, 0.0f);
    glVertex3f(46.2667f, 14.7761f, 0.0f);
    glVertex3f(46.0667f, 14.7761f, 0.0f);
    glVertex3f(45.8667f, 14.7761f, 0.0f);
    glVertex3f(45.7333f, 14.7761f, 0.0f);
    glVertex3f(45.5333f, 14.7761f, 0.0f);
    glVertex3f(45.3333f, 14.7761f, 0.0f);
    glVertex3f(45.2f, 14.7761f, 0.0f);
    glVertex3f(45.0f, 14.7761f, 0.0f);
    glVertex3f(44.8667f, 14.7761f, 0.0f);
    glVertex3f(44.6667f, 14.7761f, 0.0f);
    glVertex3f(44.4667f, 14.7761f, 0.0f);
    glVertex3f(44.2667f, 14.7761f, 0.0f);
    glVertex3f(44.0f, 14.7761f, 0.0f);
    glVertex3f(43.7333f, 14.7761f, 0.0f);
    glVertex3f(43.5333f, 14.7761f, 0.0f);
    glVertex3f(43.3333f, 14.7761f, 0.0f);
    glVertex3f(43.1333f, 14.7761f, 0.0f);
    glVertex3f(43.0667f, 14.7761f, 0.0f);
    glVertex3f(42.9333f, 14.7761f, 0.0f);
    glVertex3f(42.8f, 14.7761f, 0.0f);
    glVertex3f(42.7333f, 14.7761f, 0.0f);
    glVertex3f(42.6667f, 14.7761f, 0.0f);
    glVertex3f(42.5333f, 14.7761f, 0.0f);
    glVertex3f(42.3333f, 14.7761f, 0.0f);
    glVertex3f(42.2f, 14.7761f, 0.0f);
    glVertex3f(42.0f, 14.7761f, 0.0f);
    glVertex3f(41.7333f, 14.7761f, 0.0f);
    glVertex3f(41.4667f, 14.7761f, 0.0f);
    glVertex3f(41.2f, 14.7761f, 0.0f);
    glVertex3f(41.0f, 14.7761f, 0.0f);
    glVertex3f(40.8f, 14.7761f, 0.0f);
    glVertex3f(40.6f, 14.7761f, 0.0f);
    glVertex3f(40.4f, 14.7761f, 0.0f);
    glVertex3f(40.2f, 14.7761f, 0.0f);
    glVertex3f(40.0f, 14.7761f, 0.0f);
    glVertex3f(39.8667f, 14.7761f, 0.0f);
    glVertex3f(39.6667f, 14.7761f, 0.0f);
    glVertex3f(39.4667f, 14.7761f, 0.0f);
    glVertex3f(39.2667f, 14.7761f, 0.0f);
    glVertex3f(39.0667f, 14.7761f, 0.0f);
    glVertex3f(38.8f, 14.7761f, 0.0f);
    glVertex3f(38.6f, 14.7761f, 0.0f);
    glVertex3f(38.4f, 14.7761f, 0.0f);
    glVertex3f(38.2667f, 14.7761f, 0.0f);
    glVertex3f(38.0667f, 14.7761f, 0.0f);
    glVertex3f(37.8667f, 14.7761f, 0.0f);
    glVertex3f(37.6667f, 14.7761f, 0.0f);
    glVertex3f(37.4667f, 14.7761f, 0.0f);
    glVertex3f(37.2667f, 14.7761f, 0.0f);
    glVertex3f(37.0667f, 14.7761f, 0.0f);
    glVertex3f(36.8667f, 14.7761f, 0.0f);
    glVertex3f(36.6667f, 14.7761f, 0.0f);
    glVertex3f(36.4f, 14.7761f, 0.0f);
    glVertex3f(36.0667f, 14.7761f, 0.0f);
    glVertex3f(35.6667f, 14.7761f, 0.0f);
    glVertex3f(35.3333f, 14.7761f, 0.0f);
    glVertex3f(34.8667f, 14.7761f, 0.0f);
    glVertex3f(34.4f, 14.7761f, 0.0f);
    glVertex3f(34.0f, 14.7761f, 0.0f);
    glVertex3f(33.6f, 14.7761f, 0.0f);
    glVertex3f(33.3333f, 14.7761f, 0.0f);
    glVertex3f(33.1333f, 14.7761f, 0.0f);
    glVertex3f(32.9333f, 14.7761f, 0.0f);
    glVertex3f(32.8f, 14.7761f, 0.0f);
    glVertex3f(32.6667f, 14.7761f, 0.0f);
    glVertex3f(32.4667f, 14.7761f, 0.0f);
    glVertex3f(32.3333f, 14.7761f, 0.0f);
    glVertex3f(32.2f, 14.7761f, 0.0f);
    glVertex3f(32.0f, 14.7761f, 0.0f);
    glVertex3f(31.8f, 14.7761f, 0.0f);
    glVertex3f(31.6f, 14.7761f, 0.0f);
    glVertex3f(31.4f, 14.7761f, 0.0f);
    glVertex3f(31.2f, 14.7761f, 0.0f);
    glVertex3f(31.0667f, 14.7761f, 0.0f);
    glVertex3f(30.8667f, 14.7761f, 0.0f);
    glVertex3f(30.7333f, 14.7761f, 0.0f);
    glVertex3f(30.6f, 14.7761f, 0.0f);
    glVertex3f(30.4f, 14.7761f, 0.0f);
    glVertex3f(30.2f, 14.7761f, 0.0f);
    glVertex3f(30.0f, 14.7761f, 0.0f);
    glVertex3f(29.8f, 14.7761f, 0.0f);
    glVertex3f(29.5333f, 14.7761f, 0.0f);
    glVertex3f(29.2667f, 14.7761f, 0.0f);
    glVertex3f(29.0667f, 14.7761f, 0.0f);
    glVertex3f(28.8667f, 14.7761f, 0.0f);
    glVertex3f(28.6667f, 14.7761f, 0.0f);
    glVertex3f(28.4667f, 14.7761f, 0.0f);
    glVertex3f(28.3333f, 14.7761f, 0.0f);
    glVertex3f(28.2f, 14.7761f, 0.0f);
    glVertex3f(28.0667f, 14.7761f, 0.0f);
    glVertex3f(28.0f, 14.7761f, 0.0f);
    glVertex3f(27.8667f, 14.7015f, 0.0f);
    glVertex3f(27.8f, 14.7015f, 0.0f);
    glVertex3f(27.6667f, 14.7015f, 0.0f);
    glVertex3f(27.5333f, 14.7015f, 0.0f);
    glVertex3f(27.2667f, 14.6269f, 0.0f);
    glVertex3f(27.0667f, 14.5522f, 0.0f);
    glVertex3f(26.8667f, 14.4776f, 0.0f);
    glVertex3f(26.7333f, 14.4776f, 0.0f);
    glVertex3f(26.5333f, 14.4776f, 0.0f);
    glVertex3f(26.4f, 14.4776f, 0.0f);
    glVertex3f(26.2667f, 14.4776f, 0.0f);
    glVertex3f(26.1333f, 14.4776f, 0.0f);
    glVertex3f(26.0667f, 14.4776f, 0.0f);
    glVertex3f(26.0f, 14.4776f, 0.0f);
    glVertex3f(25.9333f, 14.4776f, 0.0f);
    glVertex3f(25.8f, 14.4776f, 0.0f);
    glVertex3f(25.7333f, 14.4776f, 0.0f);
    glVertex3f(25.5333f, 14.4776f, 0.0f);
    glVertex3f(25.3333f, 14.4776f, 0.0f);
    glVertex3f(25.1333f, 14.4776f, 0.0f);
    glVertex3f(24.9333f, 14.4776f, 0.0f);
    glVertex3f(24.7333f, 14.4776f, 0.0f);
    glVertex3f(24.4667f, 14.4776f, 0.0f);
    glVertex3f(24.2f, 14.4776f, 0.0f);
    glVertex3f(24.0f, 14.4776f, 0.0f);
    glVertex3f(23.8f, 14.4776f, 0.0f);
    glVertex3f(23.6f, 14.4776f, 0.0f);
    glVertex3f(23.3333f, 14.4776f, 0.0f);
    glVertex3f(23.1333f, 14.4776f, 0.0f);
    glVertex3f(22.8667f, 14.4776f, 0.0f);
    glVertex3f(22.6667f, 14.4776f, 0.0f);
    glVertex3f(22.4f, 14.4776f, 0.0f);
    glVertex3f(22.2f, 14.4776f, 0.0f);
    glVertex3f(22.0f, 14.4776f, 0.0f);
    glVertex3f(21.8f, 14.4776f, 0.0f);
    glVertex3f(21.6f, 14.4776f, 0.0f);
    glVertex3f(21.4667f, 14.4776f, 0.0f);
    glVertex3f(21.2667f, 14.4776f, 0.0f);
    glVertex3f(21.0667f, 14.4776f, 0.0f);
    glVertex3f(20.9333f, 14.4776f, 0.0f);
    glVertex3f(20.8f, 14.4776f, 0.0f);
    glVertex3f(20.6f, 14.4776f, 0.0f);
    glVertex3f(20.4f, 14.4776f, 0.0f);
    glVertex3f(20.1333f, 14.4776f, 0.0f);
    glVertex3f(19.8f, 14.4776f, 0.0f);
    glVertex3f(19.4f, 14.4776f, 0.0f);
    glVertex3f(19.0667f, 14.4776f, 0.0f);
    glVertex3f(18.7333f, 14.4776f, 0.0f);
    glVertex3f(18.3333f, 14.4776f, 0.0f);
    glVertex3f(18.0667f, 14.4776f, 0.0f);
    glVertex3f(17.6667f, 14.403f, 0.0f);
    glVertex3f(17.4667f, 14.403f, 0.0f);
    glVertex3f(17.2667f, 14.403f, 0.0f);
    glVertex3f(17.0f, 14.403f, 0.0f);
    glVertex3f(16.8667f, 14.403f, 0.0f);
    glVertex3f(16.6f, 14.403f, 0.0f);
    glVertex3f(16.3333f, 14.403f, 0.0f);
    glVertex3f(16.0667f, 14.403f, 0.0f);
    glVertex3f(15.6667f, 14.403f, 0.0f);
    glVertex3f(15.3333f, 14.403f, 0.0f);
    glVertex3f(15.0f, 14.403f, 0.0f);
    glVertex3f(14.7333f, 14.403f, 0.0f);
    glVertex3f(14.4f, 14.403f, 0.0f);
    glVertex3f(14.1333f, 14.403f, 0.0f);
    glVertex3f(13.8667f, 14.403f, 0.0f);
    glVertex3f(13.6f, 14.403f, 0.0f);
    glVertex3f(13.2667f, 14.403f, 0.0f);
    glVertex3f(12.8667f, 14.403f, 0.0f);
    glVertex3f(12.6f, 14.403f, 0.0f);
    glVertex3f(12.2667f, 14.403f, 0.0f);
    glVertex3f(11.8667f, 14.403f, 0.0f);
    glVertex3f(11.5333f, 14.403f, 0.0f);
    glVertex3f(11.1333f, 14.403f, 0.0f);
    glVertex3f(10.8667f, 14.403f, 0.0f);
    glVertex3f(10.6f, 14.403f, 0.0f);
    glVertex3f(10.3333f, 14.403f, 0.0f);
    glVertex3f(10.1333f, 14.403f, 0.0f);
    glVertex3f(9.9333f, 14.403f, 0.0f);
    glVertex3f(9.8f, 14.403f, 0.0f);
    glVertex3f(9.6f, 14.403f, 0.0f);
    glVertex3f(9.4667f, 14.403f, 0.0f);
    glVertex3f(9.3333f, 14.403f, 0.0f);
    glVertex3f(9.2f, 14.403f, 0.0f);
    glVertex3f(9.1333f, 14.403f, 0.0f);
    glVertex3f(9.0667f, 14.403f, 0.0f);
    glVertex3f(8.9333f, 14.403f, 0.0f);
    glVertex3f(8.8667f, 14.403f, 0.0f);
    glVertex3f(8.8f, 14.403f, 0.0f);
    glVertex3f(8.6667f, 14.403f, 0.0f);
    glVertex3f(8.5333f, 14.403f, 0.0f);
    glVertex3f(8.4f, 14.403f, 0.0f);
    glVertex3f(8.3333f, 14.403f, 0.0f);
    glVertex3f(8.2f, 14.403f, 0.0f);
    glVertex3f(8.0667f, 14.403f, 0.0f);
    glVertex3f(7.9333f, 14.403f, 0.0f);
    glVertex3f(7.8f, 14.403f, 0.0f);
    glVertex3f(7.6667f, 14.403f, 0.0f);
    glVertex3f(7.6f, 14.403f, 0.0f);
    glVertex3f(7.4667f, 14.403f, 0.0f);
    glVertex3f(7.4f, 14.403f, 0.0f);
    glVertex3f(7.2667f, 14.403f, 0.0f);
    glVertex3f(7.2f, 14.403f, 0.0f);
    glVertex3f(7.1333f, 14.403f, 0.0f);
    glVertex3f(7.0f, 14.403f, 0.0f);
    glVertex3f(6.9333f, 14.403f, 0.0f);
    glVertex3f(6.8667f, 14.403f, 0.0f);
    glVertex3f(6.8f, 14.403f, 0.0f);
    glVertex3f(6.7333f, 14.403f, 0.0f);
    glVertex3f(6.6667f, 14.403f, 0.0f);
    glVertex3f(6.6f, 14.403f, 0.0f);
    glVertex3f(6.5333f, 14.403f, 0.0f);
    glVertex3f(6.4667f, 14.403f, 0.0f);
    glVertex3f(6.3333f, 14.403f, 0.0f);
    glVertex3f(6.2667f, 14.403f, 0.0f);
    glVertex3f(6.1333f, 14.403f, 0.0f);
    glVertex3f(6.0f, 14.403f, 0.0f);
    glVertex3f(5.8f, 14.403f, 0.0f);
    glVertex3f(5.6f, 14.403f, 0.0f);
    glVertex3f(5.4667f, 14.403f, 0.0f);
    glVertex3f(5.3333f, 14.403f, 0.0f);
    glVertex3f(5.2f, 14.403f, 0.0f);
    glVertex3f(5.0f, 14.403f, 0.0f);
    glVertex3f(4.9333f, 14.403f, 0.0f);
    glVertex3f(4.8667f, 14.403f, 0.0f);
    glVertex3f(4.8f, 14.403f, 0.0f);
    glVertex3f(4.7333f, 14.403f, 0.0f);
    glVertex3f(4.6f, 14.403f, 0.0f);
    glVertex3f(4.5333f, 14.403f, 0.0f);
    glVertex3f(4.4667f, 14.403f, 0.0f);
    glVertex3f(4.3333f, 14.403f, 0.0f);
    glVertex3f(4.2f, 14.403f, 0.0f);
    glVertex3f(4.0667f, 14.4776f, 0.0f);
    glVertex3f(4.0f, 14.4776f, 0.0f);
    glVertex3f(3.9333f, 14.4776f, 0.0f);
    glVertex3f(3.8f, 14.5522f, 0.0f);
    glVertex3f(3.7333f, 14.5522f, 0.0f);
    glVertex3f(3.6667f, 14.5522f, 0.0f);
    glVertex3f(3.6f, 14.5522f, 0.0f);
    glVertex3f(3.5333f, 14.5522f, 0.0f);
    glVertex3f(3.4667f, 14.5522f, 0.0f);
    glVertex3f(3.3333f, 14.5522f, 0.0f);
    glVertex3f(3.2f, 14.5522f, 0.0f);
    glVertex3f(3.0f, 14.7015f, 0.0f);
    glVertex3f(2.9333f, 14.7015f, 0.0f);
    glVertex3f(2.8f, 14.7015f, 0.0f);
    glVertex3f(2.7333f, 14.7015f, 0.0f);
    glVertex3f(2.6667f, 14.7015f, 0.0f);
    glVertex3f(2.6f, 14.7015f, 0.0f);
    glVertex3f(2.5333f, 14.7015f, 0.0f);
    glVertex3f(2.4667f, 14.7761f, 0.0f);
    glVertex3f(2.4f, 14.7761f, 0.0f);
    glVertex3f(2.3333f, 14.7761f, 0.0f);
    glVertex3f(2.2667f, 14.7761f, 0.0f);
    glVertex3f(2.1333f, 14.8507f, 0.0f);
    glVertex3f(2.0667f, 14.8507f, 0.0f);
    glVertex3f(2.0f, 14.8507f, 0.0f);
    glVertex3f(1.9333f, 14.8507f, 0.0f);
    glVertex3f(1.8667f, 14.9254f, 0.0f);
    glVertex3f(1.8f, 14.9254f, 0.0f);
    glVertex3f(1.7333f, 15.0f, 0.0f);
    glVertex3f(1.6f, 15.0f, 0.0f);
    glVertex3f(1.5333f, 15.0f, 0.0f);
    glVertex3f(1.4667f, 15.0f, 0.0f);
    glVertex3f(1.4f, 15.0f, 0.0f);
    glVertex3f(1.3333f, 15.0f, 0.0f);
    glVertex3f(1.2667f, 15.0746f, 0.0f);
    glVertex3f(1.2f, 15.0746f, 0.0f);
    glVertex3f(1.1333f, 15.0746f, 0.0f);
    glVertex3f(1.0f, 15.0746f, 0.0f);
    glVertex3f(0.9333f, 15.0746f, 0.0f);
    glVertex3f(0.8667f, 15.0746f, 0.0f);
    glVertex3f(0.8f, 15.0746f, 0.0f);
    glVertex3f(0.7333f, 15.0746f, 0.0f);
    glVertex3f(0.6667f, 15.0746f, 0.0f);
    glVertex3f(0.6f, 15.0746f, 0.0f);
    glVertex3f(0.5333f, 15.0746f, 0.0f);
    glVertex3f(0.4f, 15.0746f, 0.0f);
    glVertex3f(0.3333f, 15.0746f, 0.0f);
    glVertex3f(0.2667f, 15.0746f, 0.0f);
    glVertex3f(0.2f, 15.0746f, 0.0f);
    glVertex3f(0.0667f, 15.0746f, 0.0f);
    glVertex3f(0.0f, 15.0746f, 0.0f);
    glVertex3f(-0.0667f, 15.0746f, 0.0f);
    glVertex3f(-0.1333f, 15.0746f, 0.0f);
    glVertex3f(-0.2f, 15.1493f, 0.0f);
    glVertex3f(-0.2667f, 15.1493f, 0.0f);
    glVertex3f(-0.3333f, 15.1493f, 0.0f);
    glVertex3f(-0.4f, 15.1493f, 0.0f);
    glVertex3f(-0.5333f, 15.2239f, 0.0f);
    glVertex3f(-0.6f, 15.2985f, 0.0f);
    glVertex3f(-0.6667f, 15.2985f, 0.0f);
    glVertex3f(-0.7333f, 15.3731f, 0.0f);
    glVertex3f(-0.7333f, 15.4478f, 0.0f);
    glVertex3f(-0.8f, 15.4478f, 0.0f);
    glVertex3f(-0.8f, 15.5224f, 0.0f);
    glVertex3f(-0.8667f, 15.5224f, 0.0f);
    glVertex3f(-0.8667f, 15.597f, 0.0f);
    glVertex3f(-0.9333f, 15.6716f, 0.0f);
    glVertex3f(-1.0f, 15.8209f, 0.0f);
    glVertex3f(-1.0f, 15.9701f, 0.0f);
    glVertex3f(-1.0667f, 16.0448f, 0.0f);
    glVertex3f(-1.0667f, 16.1194f, 0.0f);
    glVertex3f(-1.0667f, 16.194f, 0.0f);
    glVertex3f(-1.0667f, 16.2687f, 0.0f);
    glVertex3f(-1.0667f, 16.3433f, 0.0f);
    glVertex3f(-1.0667f, 16.4179f, 0.0f);
    glVertex3f(-1.0667f, 16.4925f, 0.0f);
    glVertex3f(-1.0667f, 16.5672f, 0.0f);
    glVertex3f(-1.0f, 16.6418f, 0.0f);
    glVertex3f(-1.0f, 16.7164f, 0.0f);
    glVertex3f(-1.0f, 16.791f, 0.0f);
    glVertex3f(-1.0f, 16.8657f, 0.0f);
    glVertex3f(-0.9333f, 16.9403f, 0.0f);
    glVertex3f(-0.9333f, 17.0149f, 0.0f);
    glVertex3f(-0.8667f, 17.0896f, 0.0f);
    glVertex3f(-0.8f, 17.1642f, 0.0f);
    glVertex3f(-0.8f, 17.3134f, 0.0f);
    glVertex3f(-0.7333f, 17.3134f, 0.0f);
    glVertex3f(-0.7333f, 17.3881f, 0.0f);
    glVertex3f(-0.6667f, 17.4627f, 0.0f);
    glVertex3f(-0.6f, 17.5373f, 0.0f);
    glVertex3f(-0.6f, 17.6119f, 0.0f);
    glVertex3f(-0.5333f, 17.7612f, 0.0f);
    glVertex3f(-0.4667f, 17.8358f, 0.0f);
    glVertex3f(-0.4667f, 17.9104f, 0.0f);
    glVertex3f(-0.4667f, 17.9851f, 0.0f);
    glVertex3f(-0.4667f, 18.0597f, 0.0f);
    glVertex3f(-0.4667f, 18.1343f, 0.0f);
    glVertex3f(-0.4f, 18.209f, 0.0f);
    glVertex3f(-0.4f, 18.2836f, 0.0f);
    glVertex3f(-0.3333f, 18.3582f, 0.0f);
    glVertex3f(-0.3333f, 18.4328f, 0.0f);
    glVertex3f(-0.2667f, 18.5075f, 0.0f);
    glVertex3f(-0.2667f, 18.5821f, 0.0f);
    glVertex3f(-0.2f, 18.6567f, 0.0f);
    glVertex3f(-0.2f, 18.7313f, 0.0f);
    glVertex3f(-0.1333f, 18.806f, 0.0f);
    glVertex3f(-0.1333f, 18.8806f, 0.0f);
    glVertex3f(-0.0667f, 18.8806f, 0.0f);
    glVertex3f(0.0f, 18.9552f, 0.0f);
    glVertex3f(0.0f, 19.0299f, 0.0f);
    glVertex3f(0.0667f, 19.1045f, 0.0f);
    glVertex3f(0.1333f, 19.1791f, 0.0f);
    glVertex3f(0.2f, 19.2537f, 0.0f);
    glVertex3f(0.2667f, 19.3284f, 0.0f);
    glVertex3f(0.2667f, 19.403f, 0.0f);
    glVertex3f(0.3333f, 19.4776f, 0.0f);
    glVertex3f(0.3333f, 19.5522f, 0.0f);
    glVertex3f(0.3333f, 19.6269f, 0.0f);
    glVertex3f(0.4f, 19.7015f, 0.0f);
    glVertex3f(0.4667f, 19.7015f, 0.0f);
    glVertex3f(0.4667f, 19.7761f, 0.0f);
    glVertex3f(0.5333f, 19.8507f, 0.0f);
    glVertex3f(0.5333f, 19.9254f, 0.0f);
    glVertex3f(0.6f, 19.9254f, 0.0f);
    glVertex3f(0.6667f, 20.0746f, 0.0f);
    glVertex3f(0.7333f, 20.1493f, 0.0f);
    glVertex3f(0.7333f, 20.2239f, 0.0f);
    glVertex3f(0.8f, 20.2985f, 0.0f);
    glVertex3f(0.8f, 20.3731f, 0.0f);
    glVertex3f(0.8667f, 20.4478f, 0.0f);
    glVertex3f(0.9333f, 20.5224f, 0.0f);
    glVertex3f(0.9333f, 20.597f, 0.0f);
    glVertex3f(0.9333f, 20.6716f, 0.0f);
    glVertex3f(0.9333f, 20.7463f, 0.0f);
    glVertex3f(0.9333f, 20.8209f, 0.0f);
    glVertex3f(1.0f, 20.8209f, 0.0f);
    glVertex3f(1.0f, 20.8955f, 0.0f);
    glVertex3f(1.0f, 20.9701f, 0.0f);
    glVertex3f(1.0f, 21.0448f, 0.0f);
    glVertex3f(1.0f, 21.1194f, 0.0f);
    glVertex3f(1.0f, 21.2687f, 0.0f);
    glVertex3f(1.0667f, 21.2687f, 0.0f);
    glVertex3f(1.0667f, 21.3433f, 0.0f);
    glVertex3f(1.0667f, 21.4179f, 0.0f);
    glVertex3f(1.1333f, 21.4179f, 0.0f);

    glEnd();





    glBegin(GL_TRIANGLE_FAN);   // Background Pahar green 1st

    glColor3f(0.475, 0.58, 0.122);
    glVertex3f(27.8f, 18.4328f, 0.0f);

    glVertex3f(20.3333f, 17.7612f, 0.0f);
    glVertex3f(20.3333f, 17.8358f, 0.0f);
    glVertex3f(20.4f, 17.8358f, 0.0f);
    glVertex3f(20.4667f, 17.8358f, 0.0f);
    glVertex3f(20.6f, 17.9104f, 0.0f);
    glVertex3f(20.6667f, 18.0597f, 0.0f);
    glVertex3f(20.7333f, 18.1343f, 0.0f);
    glVertex3f(20.7333f, 18.209f, 0.0f);
    glVertex3f(20.8f, 18.209f, 0.0f);
    glVertex3f(20.8f, 18.2836f, 0.0f);
    glVertex3f(20.8667f, 18.3582f, 0.0f);
    glVertex3f(20.9333f, 18.3582f, 0.0f);
    glVertex3f(20.9333f, 18.4328f, 0.0f);
    glVertex3f(20.9333f, 18.5075f, 0.0f);
    glVertex3f(21.0f, 18.5821f, 0.0f);
    glVertex3f(21.0667f, 18.7313f, 0.0f);
    glVertex3f(21.1333f, 18.806f, 0.0f);
    glVertex3f(21.1333f, 18.8806f, 0.0f);
    glVertex3f(21.2f, 18.9552f, 0.0f);
    glVertex3f(21.2667f, 19.0299f, 0.0f);
    glVertex3f(21.3333f, 19.1045f, 0.0f);
    glVertex3f(21.3333f, 19.1791f, 0.0f);
    glVertex3f(21.4f, 19.1791f, 0.0f);
    glVertex3f(21.4667f, 19.2537f, 0.0f);
    glVertex3f(21.5333f, 19.2537f, 0.0f);
    glVertex3f(21.6f, 19.2537f, 0.0f);
    glVertex3f(21.6f, 19.3284f, 0.0f);
    glVertex3f(21.6667f, 19.403f, 0.0f);
    glVertex3f(21.7333f, 19.403f, 0.0f);
    glVertex3f(21.7333f, 19.4776f, 0.0f);
    glVertex3f(21.8f, 19.4776f, 0.0f);
    glVertex3f(21.8f, 19.5522f, 0.0f);
    glVertex3f(21.8667f, 19.5522f, 0.0f);
    glVertex3f(21.8667f, 19.6269f, 0.0f);
    glVertex3f(21.9333f, 19.6269f, 0.0f);
    glVertex3f(22.0f, 19.7015f, 0.0f);
    glVertex3f(22.0667f, 19.7015f, 0.0f);
    glVertex3f(22.0667f, 19.7761f, 0.0f);
    glVertex3f(22.1333f, 19.8507f, 0.0f);
    glVertex3f(22.2f, 19.9254f, 0.0f);
    glVertex3f(22.2667f, 19.9254f, 0.0f);
    glVertex3f(22.3333f, 20.0f, 0.0f);
    glVertex3f(22.4f, 20.0f, 0.0f);
    glVertex3f(22.4f, 20.0746f, 0.0f);
    glVertex3f(22.4667f, 20.1493f, 0.0f);
    glVertex3f(22.6f, 20.1493f, 0.0f);
    glVertex3f(22.6f, 20.2239f, 0.0f);
    glVertex3f(22.6667f, 20.2239f, 0.0f);
    glVertex3f(22.7333f, 20.2985f, 0.0f);
    glVertex3f(22.8f, 20.3731f, 0.0f);
    glVertex3f(22.8f, 20.4478f, 0.0f);
    glVertex3f(22.8667f, 20.4478f, 0.0f);
    glVertex3f(22.8667f, 20.5224f, 0.0f);
    glVertex3f(22.9333f, 20.5224f, 0.0f);
    glVertex3f(23.0f, 20.597f, 0.0f);
    glVertex3f(23.0667f, 20.6716f, 0.0f);
    glVertex3f(23.1333f, 20.8209f, 0.0f);
    glVertex3f(23.2f, 20.8955f, 0.0f);
    glVertex3f(23.2667f, 21.0448f, 0.0f);
    glVertex3f(23.3333f, 21.1194f, 0.0f);
    glVertex3f(23.3333f, 21.194f, 0.0f);
    glVertex3f(23.4f, 21.3433f, 0.0f);
    glVertex3f(23.4667f, 21.4179f, 0.0f);
    glVertex3f(23.5333f, 21.4925f, 0.0f);
    glVertex3f(23.5333f, 21.5672f, 0.0f);
    glVertex3f(23.5333f, 21.6418f, 0.0f);
    glVertex3f(23.6f, 21.7164f, 0.0f);
    glVertex3f(23.6667f, 21.791f, 0.0f);
    glVertex3f(23.6667f, 21.8657f, 0.0f);
    glVertex3f(23.7333f, 21.8657f, 0.0f);
    glVertex3f(23.7333f, 21.9403f, 0.0f);
    glVertex3f(23.8f, 22.0149f, 0.0f);
    glVertex3f(23.8667f, 22.0896f, 0.0f);
    glVertex3f(23.8667f, 22.1642f, 0.0f);
    glVertex3f(23.9333f, 22.2388f, 0.0f);
    glVertex3f(23.9333f, 22.3134f, 0.0f);
    glVertex3f(24.0f, 22.3134f, 0.0f);
    glVertex3f(24.0f, 22.3881f, 0.0f);
    glVertex3f(24.0f, 22.4627f, 0.0f);
    glVertex3f(24.0667f, 22.5373f, 0.0f);
    glVertex3f(24.0667f, 22.6119f, 0.0f);
    glVertex3f(24.1333f, 22.6866f, 0.0f);
    glVertex3f(24.2f, 22.7612f, 0.0f);
    glVertex3f(24.2667f, 22.8358f, 0.0f);
    glVertex3f(24.3333f, 22.9104f, 0.0f);
    glVertex3f(24.4f, 22.9851f, 0.0f);
    glVertex3f(24.4667f, 23.0597f, 0.0f);
    glVertex3f(24.5333f, 23.0597f, 0.0f);
    glVertex3f(24.5333f, 23.1343f, 0.0f);
    glVertex3f(24.6f, 23.1343f, 0.0f);
    glVertex3f(24.6667f, 23.209f, 0.0f);
    glVertex3f(24.6667f, 23.2836f, 0.0f);
    glVertex3f(24.7333f, 23.2836f, 0.0f);
    glVertex3f(24.8f, 23.2836f, 0.0f);
    glVertex3f(24.8667f, 23.4328f, 0.0f);
    glVertex3f(24.9333f, 23.5075f, 0.0f);
    glVertex3f(25.0f, 23.5821f, 0.0f);
    glVertex3f(25.0667f, 23.6567f, 0.0f);
    glVertex3f(25.0667f, 23.7313f, 0.0f);
    glVertex3f(25.1333f, 23.806f, 0.0f);
    glVertex3f(25.2f, 23.8806f, 0.0f);
    glVertex3f(25.2f, 23.9552f, 0.0f);
    glVertex3f(25.2667f, 23.9552f, 0.0f);
    glVertex3f(25.3333f, 24.0299f, 0.0f);
    glVertex3f(25.4f, 24.1045f, 0.0f);
    glVertex3f(25.4667f, 24.1791f, 0.0f);
    glVertex3f(25.4667f, 24.2537f, 0.0f);
    glVertex3f(25.5333f, 24.2537f, 0.0f);
    glVertex3f(25.6f, 24.3284f, 0.0f);
    glVertex3f(25.6667f, 24.3284f, 0.0f);
    glVertex3f(25.7333f, 24.403f, 0.0f);
    glVertex3f(25.8f, 24.4776f, 0.0f);
    glVertex3f(25.9333f, 24.5522f, 0.0f);
    glVertex3f(26.0f, 24.5522f, 0.0f);
    glVertex3f(26.0667f, 24.6269f, 0.0f);
    glVertex3f(26.1333f, 24.7015f, 0.0f);
    glVertex3f(26.2f, 24.7015f, 0.0f);
    glVertex3f(26.3333f, 24.7761f, 0.0f);
    glVertex3f(26.4f, 24.7761f, 0.0f);
    glVertex3f(26.4667f, 24.7761f, 0.0f);
    glVertex3f(26.5333f, 24.7761f, 0.0f);
    glVertex3f(26.6667f, 24.8507f, 0.0f);
    glVertex3f(26.8f, 24.9254f, 0.0f);
    glVertex3f(26.8667f, 24.9254f, 0.0f);
    glVertex3f(26.9333f, 24.9254f, 0.0f);
    glVertex3f(27.0f, 24.9254f, 0.0f);
    glVertex3f(27.0667f, 24.9254f, 0.0f);
    glVertex3f(27.1333f, 25.0f, 0.0f);
    glVertex3f(27.2f, 25.0f, 0.0f);
    glVertex3f(27.2667f, 25.0f, 0.0f);
    glVertex3f(27.4f, 25.0f, 0.0f);
    glVertex3f(27.5333f, 25.0746f, 0.0f);
    glVertex3f(27.6f, 25.0746f, 0.0f);
    glVertex3f(27.6667f, 25.0746f, 0.0f);
    glVertex3f(27.7333f, 25.0746f, 0.0f);
    glVertex3f(27.8f, 25.0746f, 0.0f);
    glVertex3f(27.9333f, 25.0746f, 0.0f);
    glVertex3f(28.0667f, 25.0746f, 0.0f);
    glVertex3f(28.2f, 25.0746f, 0.0f);
    glVertex3f(28.3333f, 25.0746f, 0.0f);
    glVertex3f(28.4667f, 25.0746f, 0.0f);
    glVertex3f(28.6667f, 25.0746f, 0.0f);
    glVertex3f(28.7333f, 25.0746f, 0.0f);
    glVertex3f(28.8f, 25.0746f, 0.0f);
    glVertex3f(28.8667f, 25.0746f, 0.0f);
    glVertex3f(28.9333f, 25.0746f, 0.0f);
    glVertex3f(29.0f, 25.0f, 0.0f);
    glVertex3f(29.0667f, 24.9254f, 0.0f);
    glVertex3f(29.1333f, 24.9254f, 0.0f);
    glVertex3f(29.2f, 24.8507f, 0.0f);
    glVertex3f(29.3333f, 24.7761f, 0.0f);
    glVertex3f(29.4667f, 24.7015f, 0.0f);
    glVertex3f(29.5333f, 24.7015f, 0.0f);
    glVertex3f(29.6f, 24.6269f, 0.0f);
    glVertex3f(29.6f, 24.5522f, 0.0f);
    glVertex3f(29.7333f, 24.4776f, 0.0f);
    glVertex3f(29.8f, 24.4776f, 0.0f);
    glVertex3f(29.8667f, 24.403f, 0.0f);
    glVertex3f(29.9333f, 24.3284f, 0.0f);
    glVertex3f(30.0f, 24.3284f, 0.0f);
    glVertex3f(30.0f, 24.2537f, 0.0f);
    glVertex3f(30.0667f, 24.2537f, 0.0f);
    glVertex3f(30.1333f, 24.1791f, 0.0f);
    glVertex3f(30.2f, 24.1045f, 0.0f);
    glVertex3f(30.2f, 24.0299f, 0.0f);
    glVertex3f(30.2667f, 23.9552f, 0.0f);
    glVertex3f(30.3333f, 23.9552f, 0.0f);
    glVertex3f(30.3333f, 23.8806f, 0.0f);
    glVertex3f(30.4f, 23.806f, 0.0f);
    glVertex3f(30.4f, 23.7313f, 0.0f);
    glVertex3f(30.4667f, 23.7313f, 0.0f);
    glVertex3f(30.4667f, 23.6567f, 0.0f);
    glVertex3f(30.4667f, 23.5821f, 0.0f);
    glVertex3f(30.5333f, 23.5821f, 0.0f);
    glVertex3f(30.6f, 23.5075f, 0.0f);
    glVertex3f(30.6667f, 23.4328f, 0.0f);
    glVertex3f(30.6667f, 23.3582f, 0.0f);
    glVertex3f(30.7333f, 23.2836f, 0.0f);
    glVertex3f(30.8667f, 23.209f, 0.0f);
    glVertex3f(30.8667f, 23.0597f, 0.0f);
    glVertex3f(30.9333f, 23.0597f, 0.0f);
    glVertex3f(30.9333f, 22.9851f, 0.0f);
    glVertex3f(31.0f, 22.9851f, 0.0f);
    glVertex3f(31.0667f, 22.9104f, 0.0f);
    glVertex3f(31.1333f, 22.8358f, 0.0f);
    glVertex3f(31.1333f, 22.7612f, 0.0f);
    glVertex3f(31.2f, 22.7612f, 0.0f);
    glVertex3f(31.2f, 22.6866f, 0.0f);
    glVertex3f(31.2667f, 22.6866f, 0.0f);
    glVertex3f(31.3333f, 22.5373f, 0.0f);
    glVertex3f(31.4f, 22.4627f, 0.0f);
    glVertex3f(31.4667f, 22.3134f, 0.0f);
    glVertex3f(31.5333f, 22.3134f, 0.0f);
    glVertex3f(31.5333f, 22.2388f, 0.0f);
    glVertex3f(31.6f, 22.2388f, 0.0f);
    glVertex3f(31.6f, 22.1642f, 0.0f);
    glVertex3f(31.6667f, 22.1642f, 0.0f);
    glVertex3f(31.6667f, 22.0896f, 0.0f);
    glVertex3f(31.7333f, 22.0149f, 0.0f);
    glVertex3f(31.8f, 22.0149f, 0.0f);
    glVertex3f(31.9333f, 21.9403f, 0.0f);
    glVertex3f(32.0f, 21.8657f, 0.0f);
    glVertex3f(32.0f, 21.791f, 0.0f);
    glVertex3f(32.1333f, 21.791f, 0.0f);
    glVertex3f(32.1333f, 21.7164f, 0.0f);
    glVertex3f(32.2f, 21.7164f, 0.0f);
    glVertex3f(32.2f, 21.6418f, 0.0f);
    glVertex3f(32.2667f, 21.6418f, 0.0f);
    glVertex3f(32.3333f, 21.5672f, 0.0f);
    glVertex3f(32.4f, 21.4925f, 0.0f);
    glVertex3f(32.4667f, 21.4179f, 0.0f);
    glVertex3f(32.5333f, 21.3433f, 0.0f);
    glVertex3f(32.5333f, 21.2687f, 0.0f);
    glVertex3f(32.6f, 21.194f, 0.0f);
    glVertex3f(32.6667f, 21.1194f, 0.0f);
    glVertex3f(32.6667f, 21.0448f, 0.0f);
    glVertex3f(32.7333f, 21.0448f, 0.0f);
    glVertex3f(32.8f, 20.9701f, 0.0f);
    glVertex3f(32.8667f, 20.8209f, 0.0f);
    glVertex3f(32.9333f, 20.8209f, 0.0f);
    glVertex3f(33.0f, 20.6716f, 0.0f);
    glVertex3f(33.0667f, 20.597f, 0.0f);
    glVertex3f(33.1333f, 20.5224f, 0.0f);
    glVertex3f(33.1333f, 20.4478f, 0.0f);
    glVertex3f(33.2f, 20.4478f, 0.0f);
    glVertex3f(33.2667f, 20.3731f, 0.0f);
    glVertex3f(33.3333f, 20.3731f, 0.0f);
    glVertex3f(33.4f, 20.2985f, 0.0f);
    glVertex3f(33.4667f, 20.2239f, 0.0f);
    glVertex3f(33.5333f, 20.1493f, 0.0f);
    glVertex3f(33.6f, 20.0746f, 0.0f);
    glVertex3f(33.6667f, 20.0f, 0.0f);
    glVertex3f(33.6667f, 19.9254f, 0.0f);
    glVertex3f(33.7333f, 19.9254f, 0.0f);
    glVertex3f(33.7333f, 19.8507f, 0.0f);
    glVertex3f(33.8f, 19.8507f, 0.0f);
    glVertex3f(33.8667f, 19.7761f, 0.0f);
    glVertex3f(33.9333f, 19.7761f, 0.0f);
    glVertex3f(33.9333f, 19.6269f, 0.0f);
    glVertex3f(34.0f, 19.6269f, 0.0f);
    glVertex3f(34.0667f, 19.5522f, 0.0f);
    glVertex3f(34.0667f, 19.4776f, 0.0f);
    glVertex3f(34.1333f, 19.403f, 0.0f);
    glVertex3f(34.2f, 19.3284f, 0.0f);
    glVertex3f(34.2667f, 19.2537f, 0.0f);
    glVertex3f(34.3333f, 19.1791f, 0.0f);
    glVertex3f(34.3333f, 19.1045f, 0.0f);
    glVertex3f(34.4f, 19.1045f, 0.0f);
    glVertex3f(34.4f, 18.9552f, 0.0f);
    glVertex3f(34.4667f, 18.8806f, 0.0f);
    glVertex3f(34.5333f, 18.806f, 0.0f);
    glVertex3f(34.5333f, 18.7313f, 0.0f);
    glVertex3f(34.6667f, 18.6567f, 0.0f);
    glVertex3f(34.6667f, 18.5821f, 0.0f);
    glVertex3f(34.7333f, 18.5821f, 0.0f);
    glVertex3f(34.7333f, 18.5075f, 0.0f);
    glVertex3f(34.7333f, 18.4328f, 0.0f);
    glVertex3f(34.8f, 18.3582f, 0.0f);
    glVertex3f(34.8f, 18.2836f, 0.0f);
    glVertex3f(34.8667f, 18.2836f, 0.0f);
    glVertex3f(34.9333f, 18.209f, 0.0f);
    glVertex3f(34.9333f, 18.1343f, 0.0f);
    glVertex3f(35.0667f, 17.9851f, 0.0f);
    glVertex3f(35.1333f, 17.9104f, 0.0f);
    glVertex3f(35.2f, 17.7612f, 0.0f);
    glVertex3f(35.2f, 17.6119f, 0.0f);
    glVertex3f(35.2667f, 17.5373f, 0.0f);
    glVertex3f(35.2667f, 17.4627f, 0.0f);
    glVertex3f(35.3333f, 17.3881f, 0.0f);
    glVertex3f(35.4f, 17.3134f, 0.0f);
    glVertex3f(35.4f, 17.1642f, 0.0f);
    glVertex3f(35.4667f, 17.1642f, 0.0f);
    glVertex3f(35.4667f, 17.0896f, 0.0f);
    glVertex3f(35.5333f, 17.0149f, 0.0f);
    glVertex3f(35.6f, 16.9403f, 0.0f);
    glVertex3f(35.6f, 16.8657f, 0.0f);
    glVertex3f(35.6667f, 16.791f, 0.0f);
    glVertex3f(35.6667f, 16.7164f, 0.0f);
    glVertex3f(35.7333f, 16.7164f, 0.0f);
    glVertex3f(35.7333f, 16.6418f, 0.0f);
    glVertex3f(35.7333f, 16.5672f, 0.0f);
    glVertex3f(35.7333f, 16.4925f, 0.0f);
    glVertex3f(35.7333f, 16.4179f, 0.0f);
    glVertex3f(35.7333f, 16.2687f, 0.0f);
    glVertex3f(35.7333f, 16.194f, 0.0f);
    glVertex3f(35.7333f, 16.1194f, 0.0f);
    glVertex3f(35.7333f, 16.0448f, 0.0f);
    glVertex3f(35.7333f, 15.9701f, 0.0f);
    glVertex3f(35.7333f, 15.8955f, 0.0f);
    glVertex3f(35.6667f, 15.7463f, 0.0f);
    glVertex3f(35.6667f, 15.6716f, 0.0f);
    glVertex3f(35.6f, 15.6716f, 0.0f);
    glVertex3f(35.6f, 15.597f, 0.0f);
    glVertex3f(35.5333f, 15.5224f, 0.0f);
    glVertex3f(35.5333f, 15.4478f, 0.0f);
    glVertex3f(35.4667f, 15.4478f, 0.0f);
    glVertex3f(35.4f, 15.3731f, 0.0f);
    glVertex3f(35.3333f, 15.2985f, 0.0f);
    glVertex3f(35.3333f, 15.2239f, 0.0f);
    glVertex3f(35.2f, 15.2239f, 0.0f);
    glVertex3f(35.1333f, 15.1493f, 0.0f);
    glVertex3f(35.0667f, 15.1493f, 0.0f);
    glVertex3f(34.9333f, 15.0746f, 0.0f);
    glVertex3f(34.8667f, 15.0746f, 0.0f);
    glVertex3f(34.7333f, 15.0f, 0.0f);
    glVertex3f(34.6f, 14.9254f, 0.0f);
    glVertex3f(34.5333f, 14.9254f, 0.0f);
    glVertex3f(34.4667f, 14.9254f, 0.0f);
    glVertex3f(34.2667f, 14.9254f, 0.0f);
    glVertex3f(34.2f, 14.9254f, 0.0f);
    glVertex3f(34.1333f, 14.9254f, 0.0f);
    glVertex3f(34.0667f, 14.9254f, 0.0f);
    glVertex3f(34.0f, 14.9254f, 0.0f);
    glVertex3f(33.8667f, 14.9254f, 0.0f);
    glVertex3f(33.6667f, 14.9254f, 0.0f);
    glVertex3f(33.4f, 14.9254f, 0.0f);
    glVertex3f(33.0667f, 14.9254f, 0.0f);
    glVertex3f(32.7333f, 14.8507f, 0.0f);
    glVertex3f(32.4667f, 14.7761f, 0.0f);
    glVertex3f(32.2667f, 14.7761f, 0.0f);
    glVertex3f(32.0f, 14.7761f, 0.0f);
    glVertex3f(31.8f, 14.7761f, 0.0f);
    glVertex3f(31.6f, 14.7761f, 0.0f);
    glVertex3f(31.4f, 14.7761f, 0.0f);
    glVertex3f(31.2f, 14.7761f, 0.0f);
    glVertex3f(31.0f, 14.7761f, 0.0f);
    glVertex3f(30.8f, 14.7015f, 0.0f);
    glVertex3f(30.6667f, 14.7015f, 0.0f);
    glVertex3f(30.4f, 14.6269f, 0.0f);
    glVertex3f(30.2667f, 14.6269f, 0.0f);
    glVertex3f(30.0f, 14.5522f, 0.0f);
    glVertex3f(29.9333f, 14.5522f, 0.0f);
    glVertex3f(29.7333f, 14.5522f, 0.0f);
    glVertex3f(29.4f, 14.5522f, 0.0f);
    glVertex3f(29.1333f, 14.4776f, 0.0f);
    glVertex3f(28.9333f, 14.4776f, 0.0f);
    glVertex3f(28.6667f, 14.4776f, 0.0f);
    glVertex3f(28.4f, 14.4776f, 0.0f);
    glVertex3f(28.1333f, 14.4776f, 0.0f);
    glVertex3f(27.9333f, 14.4776f, 0.0f);
    glVertex3f(27.7333f, 14.4776f, 0.0f);
    glVertex3f(27.6f, 14.4776f, 0.0f);
    glVertex3f(27.4f, 14.4776f, 0.0f);
    glVertex3f(27.2667f, 14.4776f, 0.0f);
    glVertex3f(27.1333f, 14.4776f, 0.0f);
    glVertex3f(26.9333f, 14.4776f, 0.0f);
    glVertex3f(26.7333f, 14.4776f, 0.0f);
    glVertex3f(26.5333f, 14.4776f, 0.0f);
    glVertex3f(26.4f, 14.4776f, 0.0f);
    glVertex3f(26.2f, 14.4776f, 0.0f);
    glVertex3f(26.0667f, 14.4776f, 0.0f);
    glVertex3f(25.8667f, 14.4776f, 0.0f);
    glVertex3f(25.7333f, 14.4776f, 0.0f);
    glVertex3f(25.6f, 14.4776f, 0.0f);
    glVertex3f(25.4f, 14.4776f, 0.0f);
    glVertex3f(25.2f, 14.4776f, 0.0f);
    glVertex3f(25.0f, 14.4776f, 0.0f);
    glVertex3f(24.8667f, 14.4776f, 0.0f);
    glVertex3f(24.6667f, 14.4776f, 0.0f);
    glVertex3f(24.5333f, 14.4776f, 0.0f);
    glVertex3f(24.4f, 14.4776f, 0.0f);
    glVertex3f(24.2f, 14.4776f, 0.0f);
    glVertex3f(24.0667f, 14.4776f, 0.0f);
    glVertex3f(23.9333f, 14.4776f, 0.0f);
    glVertex3f(23.8f, 14.4776f, 0.0f);
    glVertex3f(23.6f, 14.4776f, 0.0f);
    glVertex3f(23.5333f, 14.4776f, 0.0f);
    glVertex3f(23.4f, 14.4776f, 0.0f);
    glVertex3f(23.2667f, 14.5522f, 0.0f);
    glVertex3f(23.2f, 14.5522f, 0.0f);
    glVertex3f(23.1333f, 14.5522f, 0.0f);
    glVertex3f(23.0667f, 14.5522f, 0.0f);
    glVertex3f(23.0f, 14.6269f, 0.0f);
    glVertex3f(22.9333f, 14.6269f, 0.0f);
    glVertex3f(22.8f, 14.7015f, 0.0f);
    glVertex3f(22.7333f, 14.7761f, 0.0f);
    glVertex3f(22.6f, 14.8507f, 0.0f);
    glVertex3f(22.4667f, 14.9254f, 0.0f);
    glVertex3f(22.2667f, 15.0746f, 0.0f);
    glVertex3f(22.2f, 15.1493f, 0.0f);
    glVertex3f(22.0667f, 15.2239f, 0.0f);
    glVertex3f(21.8667f, 15.2239f, 0.0f);
    glVertex3f(21.6667f, 15.2985f, 0.0f);
    glVertex3f(21.5333f, 15.3731f, 0.0f);
    glVertex3f(21.4f, 15.4478f, 0.0f);
    glVertex3f(21.3333f, 15.5224f, 0.0f);
    glVertex3f(21.2667f, 15.5224f, 0.0f);
    glVertex3f(21.1333f, 15.5224f, 0.0f);
    glVertex3f(21.0667f, 15.597f, 0.0f);
    glVertex3f(20.9333f, 15.597f, 0.0f);
    glVertex3f(20.8667f, 15.6716f, 0.0f);
    glVertex3f(20.8f, 15.6716f, 0.0f);
    glVertex3f(20.8f, 15.7463f, 0.0f);
    glVertex3f(20.7333f, 15.7463f, 0.0f);
    glVertex3f(20.6667f, 15.8209f, 0.0f);
    glVertex3f(20.6f, 15.8955f, 0.0f);
    glVertex3f(20.5333f, 15.9701f, 0.0f);
    glVertex3f(20.4667f, 15.9701f, 0.0f);
    glVertex3f(20.4667f, 16.0448f, 0.0f);
    glVertex3f(20.4f, 16.1194f, 0.0f);
    glVertex3f(20.4f, 16.194f, 0.0f);
    glVertex3f(20.3333f, 16.194f, 0.0f);
    glVertex3f(20.3333f, 16.2687f, 0.0f);
    glVertex3f(20.3333f, 16.3433f, 0.0f);
    glVertex3f(20.2667f, 16.4179f, 0.0f);
    glVertex3f(20.2667f, 16.4925f, 0.0f);
    glVertex3f(20.2667f, 16.5672f, 0.0f);
    glVertex3f(20.2667f, 16.6418f, 0.0f);
    glVertex3f(20.2667f, 16.7164f, 0.0f);
    glVertex3f(20.2667f, 16.791f, 0.0f);
    glVertex3f(20.2667f, 16.8657f, 0.0f);
    glVertex3f(20.2667f, 16.9403f, 0.0f);
    glVertex3f(20.2667f, 17.0149f, 0.0f);
    glVertex3f(20.2667f, 17.0896f, 0.0f);
    glVertex3f(20.2667f, 17.1642f, 0.0f);
    glVertex3f(20.2667f, 17.2388f, 0.0f);
    glVertex3f(20.3333f, 17.3134f, 0.0f);
    glVertex3f(20.3333f, 17.3881f, 0.0f);
    glVertex3f(20.3333f, 17.4627f, 0.0f);
    glVertex3f(20.3333f, 17.5373f, 0.0f);
    glVertex3f(20.4f, 17.5373f, 0.0f);
    glVertex3f(20.4667f, 17.5373f, 0.0f);
    glVertex3f(20.5333f, 17.5373f, 0.0f);
    glVertex3f(20.6f, 17.5373f, 0.0f);
    glVertex3f(20.6667f, 17.6119f, 0.0f);
    glVertex3f(20.7333f, 17.6119f, 0.0f);
    glVertex3f(20.7333f, 17.6866f, 0.0f);
    glVertex3f(20.8f, 17.6866f, 0.0f);
    glVertex3f(20.8f, 17.7612f, 0.0f);
    glVertex3f(20.8f, 17.8358f, 0.0f);
    glVertex3f(20.8f, 17.9104f, 0.0f);
    glVertex3f(20.8f, 17.9851f, 0.0f);
    glVertex3f(20.8f, 18.0597f, 0.0f);
    glVertex3f(20.8f, 18.1343f, 0.0f);
    glVertex3f(20.8f, 18.209f, 0.0f);
    glVertex3f(20.8f, 18.2836f, 0.0f);
    glVertex3f(20.8f, 18.3582f, 0.0f);

    glEnd();




    glBegin(GL_TRIANGLE_FAN);  //background green pahar left side

    glColor3f(0.396, 0.494, 0.098);
    glVertex3f(11.3333f, 19.0299f, 0.0f);


    glVertex3f(0.2f, 16.8657f, 0.0f);
    glVertex3f(0.2667f, 17.0149f, 0.0f);
    glVertex3f(0.3333f, 17.0896f, 0.0f);
    glVertex3f(0.4f, 17.1642f, 0.0f);
    glVertex3f(0.4f, 17.2388f, 0.0f);
    glVertex3f(0.4667f, 17.2388f, 0.0f);
    glVertex3f(0.5333f, 17.3134f, 0.0f);
    glVertex3f(0.6f, 17.3134f, 0.0f);
    glVertex3f(0.6667f, 17.3881f, 0.0f);
    glVertex3f(0.7333f, 17.4627f, 0.0f);
    glVertex3f(0.7333f, 17.6119f, 0.0f);
    glVertex3f(0.7333f, 17.6866f, 0.0f);
    glVertex3f(0.8f, 17.7612f, 0.0f);
    glVertex3f(0.8667f, 17.8358f, 0.0f);
    glVertex3f(0.8667f, 17.9104f, 0.0f);
    glVertex3f(0.9333f, 17.9851f, 0.0f);
    glVertex3f(0.9333f, 18.0597f, 0.0f);
    glVertex3f(1.0f, 18.0597f, 0.0f);
    glVertex3f(1.0667f, 18.209f, 0.0f);
    glVertex3f(1.1333f, 18.2836f, 0.0f);
    glVertex3f(1.1333f, 18.3582f, 0.0f);
    glVertex3f(1.2f, 18.4328f, 0.0f);
    glVertex3f(1.2f, 18.5075f, 0.0f);
    glVertex3f(1.2667f, 18.5821f, 0.0f);
    glVertex3f(1.2667f, 18.6567f, 0.0f);
    glVertex3f(1.3333f, 18.6567f, 0.0f);
    glVertex3f(1.3333f, 18.7313f, 0.0f);
    glVertex3f(1.4f, 18.806f, 0.0f);
    glVertex3f(1.4f, 18.8806f, 0.0f);
    glVertex3f(1.4667f, 18.8806f, 0.0f);
    glVertex3f(1.5333f, 18.9552f, 0.0f);
    glVertex3f(1.5333f, 19.0299f, 0.0f);
    glVertex3f(1.6f, 19.0299f, 0.0f);
    glVertex3f(1.6f, 19.1045f, 0.0f);
    glVertex3f(1.6667f, 19.1791f, 0.0f);
    glVertex3f(1.7333f, 19.2537f, 0.0f);
    glVertex3f(1.8f, 19.2537f, 0.0f);
    glVertex3f(1.8667f, 19.3284f, 0.0f);
    glVertex3f(1.9333f, 19.403f, 0.0f);
    glVertex3f(2.0f, 19.5522f, 0.0f);
    glVertex3f(2.0667f, 19.6269f, 0.0f);
    glVertex3f(2.1333f, 19.7015f, 0.0f);
    glVertex3f(2.2f, 19.7015f, 0.0f);
    glVertex3f(2.2667f, 19.7761f, 0.0f);
    glVertex3f(2.3333f, 19.8507f, 0.0f);
    glVertex3f(2.4f, 19.8507f, 0.0f);
    glVertex3f(2.5333f, 19.9254f, 0.0f);
    glVertex3f(2.6f, 20.0f, 0.0f);
    glVertex3f(2.7333f, 20.0746f, 0.0f);
    glVertex3f(2.8f, 20.1493f, 0.0f);
    glVertex3f(2.8f, 20.2239f, 0.0f);
    glVertex3f(2.8667f, 20.2985f, 0.0f);
    glVertex3f(3.0f, 20.3731f, 0.0f);
    glVertex3f(3.0667f, 20.4478f, 0.0f);
    glVertex3f(3.2f, 20.5224f, 0.0f);
    glVertex3f(3.2f, 20.597f, 0.0f);
    glVertex3f(3.2667f, 20.6716f, 0.0f);
    glVertex3f(3.3333f, 20.7463f, 0.0f);
    glVertex3f(3.4f, 20.8209f, 0.0f);
    glVertex3f(3.4667f, 20.8209f, 0.0f);
    glVertex3f(3.4667f, 20.8955f, 0.0f);
    glVertex3f(3.5333f, 20.8955f, 0.0f);
    glVertex3f(3.6f, 20.9701f, 0.0f);
    glVertex3f(3.6667f, 21.0448f, 0.0f);
    glVertex3f(3.7333f, 21.1194f, 0.0f);
    glVertex3f(3.8f, 21.194f, 0.0f);
    glVertex3f(3.8667f, 21.194f, 0.0f);
    glVertex3f(3.8667f, 21.2687f, 0.0f);
    glVertex3f(3.9333f, 21.3433f, 0.0f);
    glVertex3f(3.9333f, 21.4179f, 0.0f);
    glVertex3f(4.0f, 21.4179f, 0.0f);
    glVertex3f(4.0667f, 21.4925f, 0.0f);
    glVertex3f(4.0667f, 21.5672f, 0.0f);
    glVertex3f(4.1333f, 21.5672f, 0.0f);
    glVertex3f(4.1333f, 21.6418f, 0.0f);
    glVertex3f(4.2f, 21.791f, 0.0f);
    glVertex3f(4.2667f, 21.791f, 0.0f);
    glVertex3f(4.2667f, 21.8657f, 0.0f);
    glVertex3f(4.3333f, 21.9403f, 0.0f);
    glVertex3f(4.3333f, 22.0149f, 0.0f);
    glVertex3f(4.4f, 22.0149f, 0.0f);
    glVertex3f(4.4f, 22.0896f, 0.0f);
    glVertex3f(4.5333f, 22.0896f, 0.0f);
    glVertex3f(4.5333f, 22.1642f, 0.0f);
    glVertex3f(4.6f, 22.2388f, 0.0f);
    glVertex3f(4.6667f, 22.2388f, 0.0f);
    glVertex3f(4.7333f, 22.3134f, 0.0f);
    glVertex3f(4.8f, 22.4627f, 0.0f);
    glVertex3f(4.9333f, 22.5373f, 0.0f);
    glVertex3f(4.9333f, 22.6119f, 0.0f);
    glVertex3f(5.0f, 22.7612f, 0.0f);
    glVertex3f(5.0667f, 22.7612f, 0.0f);
    glVertex3f(5.1333f, 22.8358f, 0.0f);
    glVertex3f(5.1333f, 22.9104f, 0.0f);
    glVertex3f(5.2f, 22.9851f, 0.0f);
    glVertex3f(5.2667f, 23.0597f, 0.0f);
    glVertex3f(5.2667f, 23.1343f, 0.0f);
    glVertex3f(5.3333f, 23.1343f, 0.0f);
    glVertex3f(5.3333f, 23.2836f, 0.0f);
    glVertex3f(5.4f, 23.2836f, 0.0f);
    glVertex3f(5.4667f, 23.3582f, 0.0f);
    glVertex3f(5.5333f, 23.5075f, 0.0f);
    glVertex3f(5.5333f, 23.5821f, 0.0f);
    glVertex3f(5.6f, 23.6567f, 0.0f);
    glVertex3f(5.6667f, 23.7313f, 0.0f);
    glVertex3f(5.7333f, 23.7313f, 0.0f);
    glVertex3f(5.8f, 23.806f, 0.0f);
    glVertex3f(5.8f, 23.8806f, 0.0f);
    glVertex3f(5.8667f, 24.0299f, 0.0f);
    glVertex3f(5.9333f, 24.1045f, 0.0f);
    glVertex3f(6.0f, 24.1045f, 0.0f);
    glVertex3f(6.0f, 24.1791f, 0.0f);
    glVertex3f(6.0667f, 24.2537f, 0.0f);
    glVertex3f(6.0667f, 24.403f, 0.0f);
    glVertex3f(6.1333f, 24.4776f, 0.0f);
    glVertex3f(6.2f, 24.4776f, 0.0f);
    glVertex3f(6.2667f, 24.5522f, 0.0f);
    glVertex3f(6.3333f, 24.6269f, 0.0f);
    glVertex3f(6.3333f, 24.7015f, 0.0f);
    glVertex3f(6.4f, 24.7761f, 0.0f);
    glVertex3f(6.4f, 24.8507f, 0.0f);
    glVertex3f(6.5333f, 24.9254f, 0.0f);
    glVertex3f(6.5333f, 25.0f, 0.0f);
    glVertex3f(6.6f, 25.0f, 0.0f);
    glVertex3f(6.6f, 25.1493f, 0.0f);
    glVertex3f(6.6667f, 25.2239f, 0.0f);
    glVertex3f(6.7333f, 25.2239f, 0.0f);
    glVertex3f(6.8f, 25.2985f, 0.0f);
    glVertex3f(6.8667f, 25.3731f, 0.0f);
    glVertex3f(6.9333f, 25.4478f, 0.0f);
    glVertex3f(7.0f, 25.4478f, 0.0f);
    glVertex3f(7.0667f, 25.5224f, 0.0f);
    glVertex3f(7.2f, 25.5224f, 0.0f);
    glVertex3f(7.2f, 25.597f, 0.0f);
    glVertex3f(7.2667f, 25.597f, 0.0f);
    glVertex3f(7.3333f, 25.6716f, 0.0f);
    glVertex3f(7.4f, 25.6716f, 0.0f);
    glVertex3f(7.4f, 25.7463f, 0.0f);
    glVertex3f(7.4667f, 25.7463f, 0.0f);
    glVertex3f(7.5333f, 25.8209f, 0.0f);
    glVertex3f(7.6f, 25.8209f, 0.0f);
    glVertex3f(7.6f, 25.8955f, 0.0f);
    glVertex3f(7.6667f, 25.9701f, 0.0f);
    glVertex3f(7.8f, 25.9701f, 0.0f);
    glVertex3f(7.8f, 26.1194f, 0.0f);
    glVertex3f(7.8667f, 26.1194f, 0.0f);
    glVertex3f(7.9333f, 26.1194f, 0.0f);
    glVertex3f(8.0f, 26.194f, 0.0f);
    glVertex3f(8.0667f, 26.2687f, 0.0f);
    glVertex3f(8.1333f, 26.2687f, 0.0f);
    glVertex3f(8.2f, 26.3433f, 0.0f);
    glVertex3f(8.2667f, 26.3433f, 0.0f);
    glVertex3f(8.3333f, 26.4179f, 0.0f);
    glVertex3f(8.4f, 26.4179f, 0.0f);
    glVertex3f(8.4667f, 26.4925f, 0.0f);
    glVertex3f(8.4667f, 26.5672f, 0.0f);
    glVertex3f(8.5333f, 26.5672f, 0.0f);
    glVertex3f(8.6f, 26.5672f, 0.0f);
    glVertex3f(8.6f, 26.6418f, 0.0f);
    glVertex3f(8.6667f, 26.6418f, 0.0f);
    glVertex3f(8.7333f, 26.6418f, 0.0f);
    glVertex3f(8.8f, 26.791f, 0.0f);
    glVertex3f(8.8667f, 26.791f, 0.0f);
    glVertex3f(8.9333f, 26.8657f, 0.0f);
    glVertex3f(9.0f, 26.9403f, 0.0f);
    glVertex3f(9.0667f, 27.0149f, 0.0f);
    glVertex3f(9.1333f, 27.0896f, 0.0f);
    glVertex3f(9.2f, 27.1642f, 0.0f);
    glVertex3f(9.2667f, 27.1642f, 0.0f);
    glVertex3f(9.2667f, 27.2388f, 0.0f);
    glVertex3f(9.3333f, 27.2388f, 0.0f);
    glVertex3f(9.4f, 27.3134f, 0.0f);
    glVertex3f(9.4667f, 27.3881f, 0.0f);
    glVertex3f(9.5333f, 27.4627f, 0.0f);
    glVertex3f(9.6f, 27.4627f, 0.0f);
    glVertex3f(9.6667f, 27.4627f, 0.0f);
    glVertex3f(9.7333f, 27.4627f, 0.0f);
    glVertex3f(9.8f, 27.5373f, 0.0f);
    glVertex3f(9.8667f, 27.5373f, 0.0f);
    glVertex3f(9.9333f, 27.6119f, 0.0f);
    glVertex3f(10.0f, 27.6119f, 0.0f);
    glVertex3f(10.0667f, 27.6119f, 0.0f);
    glVertex3f(10.1333f, 27.6119f, 0.0f);
    glVertex3f(10.2f, 27.6866f, 0.0f);
    glVertex3f(10.2667f, 27.6866f, 0.0f);
    glVertex3f(10.3333f, 27.6866f, 0.0f);
    glVertex3f(10.4f, 27.6866f, 0.0f);
    glVertex3f(10.4667f, 27.6866f, 0.0f);
    glVertex3f(10.5333f, 27.6866f, 0.0f);
    glVertex3f(10.6f, 27.6866f, 0.0f);
    glVertex3f(10.6667f, 27.6866f, 0.0f);
    glVertex3f(10.7333f, 27.6866f, 0.0f);
    glVertex3f(10.8f, 27.6866f, 0.0f);
    glVertex3f(10.8667f, 27.6866f, 0.0f);
    glVertex3f(10.9333f, 27.6866f, 0.0f);
    glVertex3f(11.0667f, 27.6866f, 0.0f);
    glVertex3f(11.1333f, 27.6866f, 0.0f);
    glVertex3f(11.2f, 27.7612f, 0.0f);
    glVertex3f(11.2667f, 27.7612f, 0.0f);
    glVertex3f(11.3333f, 27.7612f, 0.0f);
    glVertex3f(11.4f, 27.7612f, 0.0f);
    glVertex3f(11.4667f, 27.7612f, 0.0f);
    glVertex3f(11.5333f, 27.7612f, 0.0f);
    glVertex3f(11.6f, 27.7612f, 0.0f);
    glVertex3f(11.6667f, 27.7612f, 0.0f);
    glVertex3f(11.8f, 27.7612f, 0.0f);
    glVertex3f(11.8667f, 27.7612f, 0.0f);
    glVertex3f(11.9333f, 27.7612f, 0.0f);
    glVertex3f(12.0f, 27.7612f, 0.0f);
    glVertex3f(12.2f, 27.7612f, 0.0f);
    glVertex3f(12.3333f, 27.6866f, 0.0f);
    glVertex3f(12.4667f, 27.6119f, 0.0f);
    glVertex3f(12.5333f, 27.5373f, 0.0f);
    glVertex3f(12.6f, 27.5373f, 0.0f);
    glVertex3f(12.6667f, 27.4627f, 0.0f);
    glVertex3f(12.7333f, 27.3881f, 0.0f);
    glVertex3f(12.8f, 27.3881f, 0.0f);
    glVertex3f(12.8667f, 27.3134f, 0.0f);
    glVertex3f(13.0f, 27.2388f, 0.0f);
    glVertex3f(13.0667f, 27.1642f, 0.0f);
    glVertex3f(13.2667f, 27.0896f, 0.0f);
    glVertex3f(13.3333f, 27.0896f, 0.0f);
    glVertex3f(13.4f, 27.0149f, 0.0f);
    glVertex3f(13.4f, 26.9403f, 0.0f);
    glVertex3f(13.4667f, 26.9403f, 0.0f);
    glVertex3f(13.5333f, 26.9403f, 0.0f);
    glVertex3f(13.5333f, 26.8657f, 0.0f);
    glVertex3f(13.6f, 26.8657f, 0.0f);
    glVertex3f(13.6667f, 26.791f, 0.0f);
    glVertex3f(13.6667f, 26.7164f, 0.0f);
    glVertex3f(13.8f, 26.6418f, 0.0f);
    glVertex3f(13.8667f, 26.6418f, 0.0f);
    glVertex3f(13.8667f, 26.5672f, 0.0f);
    glVertex3f(13.9333f, 26.4925f, 0.0f);
    glVertex3f(14.0f, 26.4925f, 0.0f);
    glVertex3f(14.0667f, 26.4179f, 0.0f);
    glVertex3f(14.1333f, 26.4179f, 0.0f);
    glVertex3f(14.2f, 26.3433f, 0.0f);
    glVertex3f(14.2667f, 26.2687f, 0.0f);
    glVertex3f(14.2667f, 26.194f, 0.0f);
    glVertex3f(14.3333f, 26.194f, 0.0f);
    glVertex3f(14.4f, 26.194f, 0.0f);
    glVertex3f(14.4667f, 26.1194f, 0.0f);
    glVertex3f(14.5333f, 26.0448f, 0.0f);
    glVertex3f(14.5333f, 25.9701f, 0.0f);
    glVertex3f(14.6667f, 25.9701f, 0.0f);
    glVertex3f(14.6667f, 25.8955f, 0.0f);
    glVertex3f(14.7333f, 25.8955f, 0.0f);
    glVertex3f(14.7333f, 25.8209f, 0.0f);
    glVertex3f(14.8667f, 25.8209f, 0.0f);
    glVertex3f(15.0f, 25.7463f, 0.0f);
    glVertex3f(15.0667f, 25.6716f, 0.0f);
    glVertex3f(15.1333f, 25.597f, 0.0f);
    glVertex3f(15.2f, 25.597f, 0.0f);
    glVertex3f(15.2667f, 25.5224f, 0.0f);
    glVertex3f(15.4f, 25.5224f, 0.0f);
    glVertex3f(15.4f, 25.4478f, 0.0f);
    glVertex3f(15.4667f, 25.3731f, 0.0f);
    glVertex3f(15.6f, 25.2985f, 0.0f);
    glVertex3f(15.6667f, 25.2985f, 0.0f);
    glVertex3f(15.7333f, 25.2985f, 0.0f);
    glVertex3f(15.8667f, 25.2239f, 0.0f);
    glVertex3f(15.8667f, 25.1493f, 0.0f);
    glVertex3f(15.9333f, 25.1493f, 0.0f);
    glVertex3f(16.0f, 25.0746f, 0.0f);
    glVertex3f(16.0667f, 25.0f, 0.0f);
    glVertex3f(16.0667f, 24.9254f, 0.0f);
    glVertex3f(16.1333f, 24.9254f, 0.0f);
    glVertex3f(16.1333f, 24.8507f, 0.0f);
    glVertex3f(16.2f, 24.7015f, 0.0f);
    glVertex3f(16.2667f, 24.6269f, 0.0f);
    glVertex3f(16.3333f, 24.6269f, 0.0f);
    glVertex3f(16.3333f, 24.5522f, 0.0f);
    glVertex3f(16.4f, 24.4776f, 0.0f);
    glVertex3f(16.4f, 24.403f, 0.0f);
    glVertex3f(16.5333f, 24.403f, 0.0f);
    glVertex3f(16.6f, 24.3284f, 0.0f);
    glVertex3f(16.6f, 24.2537f, 0.0f);
    glVertex3f(16.6667f, 24.2537f, 0.0f);
    glVertex3f(16.7333f, 24.1791f, 0.0f);
    glVertex3f(16.8f, 24.1791f, 0.0f);
    glVertex3f(16.8667f, 24.0299f, 0.0f);
    glVertex3f(16.9333f, 23.9552f, 0.0f);
    glVertex3f(17.0f, 23.8806f, 0.0f);
    glVertex3f(17.0667f, 23.806f, 0.0f);
    glVertex3f(17.1333f, 23.806f, 0.0f);
    glVertex3f(17.2f, 23.7313f, 0.0f);
    glVertex3f(17.2667f, 23.6567f, 0.0f);
    glVertex3f(17.4f, 23.6567f, 0.0f);
    glVertex3f(17.4f, 23.5075f, 0.0f);
    glVertex3f(17.5333f, 23.5075f, 0.0f);
    glVertex3f(17.5333f, 23.4328f, 0.0f);
    glVertex3f(17.6f, 23.3582f, 0.0f);
    glVertex3f(17.6f, 23.2836f, 0.0f);
    glVertex3f(17.6667f, 23.209f, 0.0f);
    glVertex3f(17.7333f, 23.1343f, 0.0f);
    glVertex3f(17.8f, 23.0597f, 0.0f);
    glVertex3f(17.8667f, 22.9851f, 0.0f);
    glVertex3f(17.9333f, 22.8358f, 0.0f);
    glVertex3f(18.0f, 22.8358f, 0.0f);
    glVertex3f(18.0667f, 22.7612f, 0.0f);
    glVertex3f(18.1333f, 22.7612f, 0.0f);
    glVertex3f(18.2f, 22.6866f, 0.0f);
    glVertex3f(18.2f, 22.6119f, 0.0f);
    glVertex3f(18.2667f, 22.6119f, 0.0f);
    glVertex3f(18.3333f, 22.5373f, 0.0f);
    glVertex3f(18.4f, 22.5373f, 0.0f);
    glVertex3f(18.4f, 22.3881f, 0.0f);
    glVertex3f(18.4667f, 22.3881f, 0.0f);
    glVertex3f(18.5333f, 22.3134f, 0.0f);
    glVertex3f(18.6f, 22.3134f, 0.0f);
    glVertex3f(18.6f, 22.2388f, 0.0f);
    glVertex3f(18.6667f, 22.2388f, 0.0f);
    glVertex3f(18.6667f, 22.1642f, 0.0f);
    glVertex3f(18.7333f, 22.0896f, 0.0f);
    glVertex3f(18.8f, 22.0149f, 0.0f);
    glVertex3f(18.8667f, 22.0149f, 0.0f);
    glVertex3f(18.8667f, 21.9403f, 0.0f);
    glVertex3f(18.9333f, 21.9403f, 0.0f);
    glVertex3f(19.0f, 21.8657f, 0.0f);
    glVertex3f(19.0667f, 21.791f, 0.0f);
    glVertex3f(19.1333f, 21.7164f, 0.0f);
    glVertex3f(19.1333f, 21.6418f, 0.0f);
    glVertex3f(19.2f, 21.5672f, 0.0f);
    glVertex3f(19.2667f, 21.4925f, 0.0f);
    glVertex3f(19.3333f, 21.4179f, 0.0f);
    glVertex3f(19.4f, 21.4179f, 0.0f);
    glVertex3f(19.4667f, 21.4179f, 0.0f);
    glVertex3f(19.4667f, 21.3433f, 0.0f);
    glVertex3f(19.5333f, 21.3433f, 0.0f);
    glVertex3f(19.5333f, 21.2687f, 0.0f);
    glVertex3f(19.6f, 21.2687f, 0.0f);
    glVertex3f(19.7333f, 21.194f, 0.0f);
    glVertex3f(19.8f, 21.1194f, 0.0f);
    glVertex3f(19.8667f, 21.1194f, 0.0f);
    glVertex3f(19.8667f, 21.0448f, 0.0f);
    glVertex3f(19.9333f, 21.0448f, 0.0f);
    glVertex3f(20.0f, 20.9701f, 0.0f);
    glVertex3f(20.0667f, 20.8955f, 0.0f);
    glVertex3f(20.1333f, 20.8209f, 0.0f);
    glVertex3f(20.2f, 20.8209f, 0.0f);
    glVertex3f(20.2667f, 20.7463f, 0.0f);
    glVertex3f(20.4f, 20.6716f, 0.0f);
    glVertex3f(20.4667f, 20.6716f, 0.0f);
    glVertex3f(20.6f, 20.597f, 0.0f);
    glVertex3f(20.7333f, 20.5224f, 0.0f);
    glVertex3f(20.8667f, 20.5224f, 0.0f);
    glVertex3f(20.8667f, 20.4478f, 0.0f);
    glVertex3f(20.9333f, 20.4478f, 0.0f);
    glVertex3f(21.0f, 20.3731f, 0.0f);
    glVertex3f(21.0667f, 20.3731f, 0.0f);
    glVertex3f(21.1333f, 20.2985f, 0.0f);
    glVertex3f(21.2f, 20.2985f, 0.0f);
    glVertex3f(21.2667f, 20.2239f, 0.0f);
    glVertex3f(21.3333f, 20.1493f, 0.0f);
    glVertex3f(21.4f, 20.1493f, 0.0f);
    glVertex3f(21.5333f, 20.0746f, 0.0f);
    glVertex3f(21.6f, 20.0f, 0.0f);
    glVertex3f(21.6667f, 20.0f, 0.0f);
    glVertex3f(21.7333f, 19.9254f, 0.0f);
    glVertex3f(21.8f, 19.8507f, 0.0f);
    glVertex3f(21.8f, 19.7761f, 0.0f);
    glVertex3f(21.8667f, 19.7761f, 0.0f);
    glVertex3f(21.9333f, 19.7015f, 0.0f);
    glVertex3f(22.0f, 19.6269f, 0.0f);
    glVertex3f(22.0667f, 19.6269f, 0.0f);
    glVertex3f(22.0667f, 19.4776f, 0.0f);
    glVertex3f(22.1333f, 19.4776f, 0.0f);
    glVertex3f(22.2f, 19.403f, 0.0f);
    glVertex3f(22.2667f, 19.403f, 0.0f);
    glVertex3f(22.2667f, 19.3284f, 0.0f);
    glVertex3f(22.3333f, 19.2537f, 0.0f);
    glVertex3f(22.4f, 19.1791f, 0.0f);
    glVertex3f(22.4667f, 19.0299f, 0.0f);
    glVertex3f(22.5333f, 18.9552f, 0.0f);
    glVertex3f(22.5333f, 18.8806f, 0.0f);
    glVertex3f(22.6f, 18.806f, 0.0f);
    glVertex3f(22.6667f, 18.806f, 0.0f);
    glVertex3f(22.6667f, 18.7313f, 0.0f);
    glVertex3f(22.7333f, 18.6567f, 0.0f);
    glVertex3f(22.8f, 18.5821f, 0.0f);
    glVertex3f(22.8667f, 18.5821f, 0.0f);
    glVertex3f(22.8667f, 18.5075f, 0.0f);
    glVertex3f(22.9333f, 18.4328f, 0.0f);
    glVertex3f(23.0f, 18.4328f, 0.0f);
    glVertex3f(23.0667f, 18.3582f, 0.0f);
    glVertex3f(23.1333f, 18.3582f, 0.0f);
    glVertex3f(23.1333f, 18.2836f, 0.0f);
    glVertex3f(23.2f, 18.2836f, 0.0f);
    glVertex3f(23.2667f, 18.209f, 0.0f);
    glVertex3f(23.3333f, 18.209f, 0.0f);
    glVertex3f(23.3333f, 18.1343f, 0.0f);
    glVertex3f(23.4f, 18.1343f, 0.0f);
    glVertex3f(23.4667f, 18.1343f, 0.0f);
    glVertex3f(23.5333f, 18.0597f, 0.0f);
    glVertex3f(23.6f, 18.0597f, 0.0f);
    glVertex3f(23.6667f, 17.9851f, 0.0f);
    glVertex3f(23.6667f, 17.9104f, 0.0f);
    glVertex3f(23.7333f, 17.9104f, 0.0f);
    glVertex3f(23.8f, 17.9104f, 0.0f);
    glVertex3f(23.9333f, 17.8358f, 0.0f);
    glVertex3f(24.0f, 17.7612f, 0.0f);
    glVertex3f(24.0667f, 17.6866f, 0.0f);
    glVertex3f(24.1333f, 17.6866f, 0.0f);
    glVertex3f(24.1333f, 17.6119f, 0.0f);
    glVertex3f(24.2f, 17.6119f, 0.0f);
    glVertex3f(24.2667f, 17.5373f, 0.0f);
    glVertex3f(24.3333f, 17.4627f, 0.0f);
    glVertex3f(24.4f, 17.4627f, 0.0f);
    glVertex3f(24.4f, 17.3881f, 0.0f);
    glVertex3f(24.5333f, 17.3881f, 0.0f);
    glVertex3f(24.6f, 17.3134f, 0.0f);
    glVertex3f(24.6667f, 17.2388f, 0.0f);
    glVertex3f(24.7333f, 17.2388f, 0.0f);
    glVertex3f(24.8f, 17.1642f, 0.0f);
    glVertex3f(24.8667f, 17.1642f, 0.0f);
    glVertex3f(24.9333f, 17.0896f, 0.0f);
    glVertex3f(25.0f, 17.0896f, 0.0f);
    glVertex3f(25.0f, 17.0149f, 0.0f);
    glVertex3f(25.0667f, 16.9403f, 0.0f);
    glVertex3f(25.2f, 16.9403f, 0.0f);
    glVertex3f(25.2f, 16.8657f, 0.0f);
    glVertex3f(25.3333f, 16.8657f, 0.0f);
    glVertex3f(25.4f, 16.791f, 0.0f);
    glVertex3f(25.4667f, 16.791f, 0.0f);
    glVertex3f(25.5333f, 16.7164f, 0.0f);
    glVertex3f(25.6f, 16.7164f, 0.0f);
    glVertex3f(25.6f, 16.6418f, 0.0f);
    glVertex3f(25.6667f, 16.6418f, 0.0f);
    glVertex3f(25.7333f, 16.5672f, 0.0f);
    glVertex3f(25.8f, 16.4925f, 0.0f);
    glVertex3f(25.8667f, 16.4179f, 0.0f);
    glVertex3f(25.9333f, 16.4179f, 0.0f);
    glVertex3f(25.9333f, 16.3433f, 0.0f);
    glVertex3f(26.0f, 16.3433f, 0.0f);
    glVertex3f(26.0667f, 16.2687f, 0.0f);
    glVertex3f(26.1333f, 16.194f, 0.0f);
    glVertex3f(26.2f, 16.1194f, 0.0f);
    glVertex3f(26.2667f, 16.1194f, 0.0f);
    glVertex3f(26.3333f, 16.0448f, 0.0f);
    glVertex3f(26.4f, 15.9701f, 0.0f);
    glVertex3f(26.3333f, 15.9701f, 0.0f);
    glVertex3f(26.2667f, 15.9701f, 0.0f);
    glVertex3f(26.2f, 15.9701f, 0.0f);
    glVertex3f(26.1333f, 15.8955f, 0.0f);
    glVertex3f(26.0667f, 15.8955f, 0.0f);
    glVertex3f(26.0f, 15.8955f, 0.0f);
    glVertex3f(25.9333f, 15.8955f, 0.0f);
    glVertex3f(25.8667f, 15.8209f, 0.0f);
    glVertex3f(25.8f, 15.8209f, 0.0f);
    glVertex3f(25.7333f, 15.8209f, 0.0f);
    glVertex3f(25.6667f, 15.8209f, 0.0f);
    glVertex3f(25.6f, 15.8209f, 0.0f);
    glVertex3f(25.6f, 15.7463f, 0.0f);
    glVertex3f(25.5333f, 15.7463f, 0.0f);
    glVertex3f(25.4667f, 15.7463f, 0.0f);
    glVertex3f(25.3333f, 15.7463f, 0.0f);
    glVertex3f(25.2667f, 15.7463f, 0.0f);
    glVertex3f(25.2f, 15.7463f, 0.0f);
    glVertex3f(25.0667f, 15.6716f, 0.0f);
    glVertex3f(25.0f, 15.6716f, 0.0f);
    glVertex3f(24.9333f, 15.6716f, 0.0f);
    glVertex3f(24.8667f, 15.6716f, 0.0f);
    glVertex3f(24.8f, 15.6716f, 0.0f);
    glVertex3f(24.7333f, 15.597f, 0.0f);
    glVertex3f(24.6667f, 15.597f, 0.0f);
    glVertex3f(24.6f, 15.597f, 0.0f);
    glVertex3f(24.5333f, 15.597f, 0.0f);
    glVertex3f(24.3333f, 15.597f, 0.0f);
    glVertex3f(24.1333f, 15.597f, 0.0f);
    glVertex3f(23.9333f, 15.597f, 0.0f);
    glVertex3f(23.7333f, 15.597f, 0.0f);
    glVertex3f(23.5333f, 15.597f, 0.0f);
    glVertex3f(23.3333f, 15.597f, 0.0f);
    glVertex3f(23.0667f, 15.597f, 0.0f);
    glVertex3f(22.8f, 15.597f, 0.0f);
    glVertex3f(22.4667f, 15.597f, 0.0f);
    glVertex3f(22.2f, 15.597f, 0.0f);
    glVertex3f(22.0f, 15.597f, 0.0f);
    glVertex3f(21.7333f, 15.597f, 0.0f);
    glVertex3f(21.5333f, 15.597f, 0.0f);
    glVertex3f(21.3333f, 15.597f, 0.0f);
    glVertex3f(21.2f, 15.597f, 0.0f);
    glVertex3f(21.0f, 15.597f, 0.0f);
    glVertex3f(20.8667f, 15.597f, 0.0f);
    glVertex3f(20.6667f, 15.597f, 0.0f);
    glVertex3f(20.4667f, 15.597f, 0.0f);
    glVertex3f(20.2667f, 15.597f, 0.0f);
    glVertex3f(20.0667f, 15.597f, 0.0f);
    glVertex3f(19.8667f, 15.597f, 0.0f);
    glVertex3f(19.7333f, 15.597f, 0.0f);
    glVertex3f(19.5333f, 15.597f, 0.0f);
    glVertex3f(19.3333f, 15.597f, 0.0f);
    glVertex3f(19.1333f, 15.597f, 0.0f);
    glVertex3f(18.8667f, 15.597f, 0.0f);
    glVertex3f(18.6667f, 15.597f, 0.0f);
    glVertex3f(18.4667f, 15.597f, 0.0f);
    glVertex3f(18.3333f, 15.597f, 0.0f);
    glVertex3f(18.2667f, 15.597f, 0.0f);
    glVertex3f(18.2f, 15.597f, 0.0f);
    glVertex3f(18.0667f, 15.597f, 0.0f);
    glVertex3f(18.0f, 15.597f, 0.0f);
    glVertex3f(17.9333f, 15.597f, 0.0f);
    glVertex3f(17.8667f, 15.597f, 0.0f);
    glVertex3f(17.7333f, 15.597f, 0.0f);
    glVertex3f(17.6f, 15.597f, 0.0f);
    glVertex3f(17.4667f, 15.597f, 0.0f);
    glVertex3f(17.3333f, 15.597f, 0.0f);
    glVertex3f(17.1333f, 15.597f, 0.0f);
    glVertex3f(16.9333f, 15.597f, 0.0f);
    glVertex3f(16.6667f, 15.5224f, 0.0f);
    glVertex3f(16.3333f, 15.4478f, 0.0f);
    glVertex3f(16.2f, 15.4478f, 0.0f);
    glVertex3f(15.9333f, 15.4478f, 0.0f);
    glVertex3f(15.6f, 15.4478f, 0.0f);
    glVertex3f(15.2667f, 15.4478f, 0.0f);
    glVertex3f(14.8667f, 15.4478f, 0.0f);
    glVertex3f(14.5333f, 15.4478f, 0.0f);
    glVertex3f(14.2667f, 15.4478f, 0.0f);
    glVertex3f(13.9333f, 15.4478f, 0.0f);
    glVertex3f(13.7333f, 15.4478f, 0.0f);
    glVertex3f(13.5333f, 15.4478f, 0.0f);
    glVertex3f(13.4667f, 15.4478f, 0.0f);
    glVertex3f(13.4f, 15.4478f, 0.0f);
    glVertex3f(13.3333f, 15.4478f, 0.0f);
    glVertex3f(13.2f, 15.4478f, 0.0f);
    glVertex3f(13.1333f, 15.4478f, 0.0f);
    glVertex3f(13.0667f, 15.4478f, 0.0f);
    glVertex3f(12.9333f, 15.4478f, 0.0f);
    glVertex3f(12.8f, 15.4478f, 0.0f);
    glVertex3f(12.6f, 15.4478f, 0.0f);
    glVertex3f(12.4f, 15.4478f, 0.0f);
    glVertex3f(12.2f, 15.4478f, 0.0f);
    glVertex3f(11.9333f, 15.4478f, 0.0f);
    glVertex3f(11.6667f, 15.4478f, 0.0f);
    glVertex3f(11.4f, 15.4478f, 0.0f);
    glVertex3f(11.1333f, 15.4478f, 0.0f);
    glVertex3f(10.8667f, 15.4478f, 0.0f);
    glVertex3f(10.6f, 15.4478f, 0.0f);
    glVertex3f(10.4f, 15.4478f, 0.0f);
    glVertex3f(10.2f, 15.4478f, 0.0f);
    glVertex3f(10.0f, 15.4478f, 0.0f);
    glVertex3f(9.8667f, 15.4478f, 0.0f);
    glVertex3f(9.7333f, 15.4478f, 0.0f);
    glVertex3f(9.6667f, 15.4478f, 0.0f);
    glVertex3f(9.6f, 15.4478f, 0.0f);
    glVertex3f(9.5333f, 15.4478f, 0.0f);
    glVertex3f(9.4f, 15.4478f, 0.0f);
    glVertex3f(9.2667f, 15.4478f, 0.0f);
    glVertex3f(9.1333f, 15.4478f, 0.0f);
    glVertex3f(9.0f, 15.4478f, 0.0f);
    glVertex3f(8.8667f, 15.4478f, 0.0f);
    glVertex3f(8.7333f, 15.4478f, 0.0f);
    glVertex3f(8.6f, 15.4478f, 0.0f);
    glVertex3f(8.4667f, 15.4478f, 0.0f);
    glVertex3f(8.4f, 15.4478f, 0.0f);
    glVertex3f(8.3333f, 15.4478f, 0.0f);
    glVertex3f(8.2667f, 15.4478f, 0.0f);
    glVertex3f(8.1333f, 15.4478f, 0.0f);
    glVertex3f(8.0f, 15.4478f, 0.0f);
    glVertex3f(7.7333f, 15.4478f, 0.0f);
    glVertex3f(7.4667f, 15.4478f, 0.0f);
    glVertex3f(7.1333f, 15.4478f, 0.0f);
    glVertex3f(6.7333f, 15.4478f, 0.0f);
    glVertex3f(6.4667f, 15.4478f, 0.0f);
    glVertex3f(6.2667f, 15.4478f, 0.0f);
    glVertex3f(6.0667f, 15.4478f, 0.0f);
    glVertex3f(5.8667f, 15.4478f, 0.0f);
    glVertex3f(5.8f, 15.4478f, 0.0f);
    glVertex3f(5.7333f, 15.4478f, 0.0f);
    glVertex3f(5.6667f, 15.4478f, 0.0f);
    glVertex3f(5.6f, 15.4478f, 0.0f);
    glVertex3f(5.5333f, 15.4478f, 0.0f);
    glVertex3f(5.4f, 15.4478f, 0.0f);
    glVertex3f(5.2f, 15.4478f, 0.0f);
    glVertex3f(5.0667f, 15.4478f, 0.0f);
    glVertex3f(4.9333f, 15.4478f, 0.0f);
    glVertex3f(4.8667f, 15.4478f, 0.0f);
    glVertex3f(4.8f, 15.4478f, 0.0f);
    glVertex3f(4.7333f, 15.4478f, 0.0f);
    glVertex3f(4.6667f, 15.4478f, 0.0f);
    glVertex3f(4.6f, 15.4478f, 0.0f);
    glVertex3f(4.5333f, 15.3731f, 0.0f);
    glVertex3f(4.4667f, 15.3731f, 0.0f);
    glVertex3f(4.4f, 15.3731f, 0.0f);
    glVertex3f(4.3333f, 15.2985f, 0.0f);
    glVertex3f(4.2667f, 15.2985f, 0.0f);
    glVertex3f(4.2f, 15.2985f, 0.0f);
    glVertex3f(4.1333f, 15.2985f, 0.0f);
    glVertex3f(4.0667f, 15.2985f, 0.0f);
    glVertex3f(4.0f, 15.2985f, 0.0f);
    glVertex3f(3.9333f, 15.2985f, 0.0f);
    glVertex3f(3.8667f, 15.2985f, 0.0f);
    glVertex3f(3.8f, 15.2985f, 0.0f);
    glVertex3f(3.7333f, 15.2985f, 0.0f);
    glVertex3f(3.6667f, 15.2985f, 0.0f);
    glVertex3f(3.5333f, 15.3731f, 0.0f);
    glVertex3f(3.3333f, 15.4478f, 0.0f);
    glVertex3f(3.2667f, 15.4478f, 0.0f);
    glVertex3f(3.0667f, 15.5224f, 0.0f);
    glVertex3f(2.9333f, 15.5224f, 0.0f);
    glVertex3f(2.8667f, 15.5224f, 0.0f);
    glVertex3f(2.6f, 15.597f, 0.0f);
    glVertex3f(2.5333f, 15.597f, 0.0f);
    glVertex3f(2.2667f, 15.6716f, 0.0f);
    glVertex3f(2.1333f, 15.7463f, 0.0f);
    glVertex3f(2.0f, 15.8209f, 0.0f);
    glVertex3f(1.9333f, 15.8209f, 0.0f);
    glVertex3f(1.8667f, 15.8209f, 0.0f);
    glVertex3f(1.8f, 15.8209f, 0.0f);
    glVertex3f(1.7333f, 15.8209f, 0.0f);
    glVertex3f(1.6667f, 15.8209f, 0.0f);
    glVertex3f(1.6f, 15.8209f, 0.0f);
    glVertex3f(1.5333f, 15.8209f, 0.0f);
    glVertex3f(1.4667f, 15.8209f, 0.0f);
    glVertex3f(1.4f, 15.8209f, 0.0f);
    glVertex3f(1.3333f, 15.8209f, 0.0f);
    glVertex3f(1.2667f, 15.8209f, 0.0f);
    glVertex3f(1.1333f, 15.8209f, 0.0f);
    glVertex3f(0.9333f, 15.8209f, 0.0f);
    glVertex3f(0.8667f, 15.8209f, 0.0f);
    glVertex3f(0.7333f, 15.8209f, 0.0f);
    glVertex3f(0.6f, 15.8209f, 0.0f);
    glVertex3f(0.4667f, 15.8209f, 0.0f);
    glVertex3f(0.4f, 15.8209f, 0.0f);
    glVertex3f(0.3333f, 15.8209f, 0.0f);
    glVertex3f(0.2667f, 15.8209f, 0.0f);
    glVertex3f(0.2f, 15.8209f, 0.0f);
    glVertex3f(0.1333f, 15.8209f, 0.0f);
    glVertex3f(0.0667f, 15.8209f, 0.0f);
    glVertex3f(0.0f, 15.8209f, 0.0f);
    glVertex3f(-0.0667f, 15.8209f, 0.0f);
    glVertex3f(-0.1333f, 15.8209f, 0.0f);
    glVertex3f(-0.2667f, 15.8209f, 0.0f);
    glVertex3f(-0.3333f, 15.8209f, 0.0f);
    glVertex3f(-0.4f, 15.8209f, 0.0f);
    glVertex3f(-0.3333f, 15.8209f, 0.0f);
    glVertex3f(-0.2667f, 15.8955f, 0.0f);
    glVertex3f(-0.2f, 15.8955f, 0.0f);
    glVertex3f(-0.1333f, 15.8955f, 0.0f);
    glVertex3f(-0.0667f, 15.9701f, 0.0f);
    glVertex3f(-0.0667f, 16.0448f, 0.0f);
    glVertex3f(0.0f, 16.1194f, 0.0f);
    glVertex3f(0.0667f, 16.1194f, 0.0f);
    glVertex3f(0.0667f, 16.194f, 0.0f);
    glVertex3f(0.0667f, 16.2687f, 0.0f);
    glVertex3f(0.0667f, 16.4179f, 0.0f);
    glVertex3f(0.1333f, 16.4925f, 0.0f);
    glVertex3f(0.1333f, 16.5672f, 0.0f);
    glVertex3f(0.1333f, 16.6418f, 0.0f);
    glVertex3f(0.1333f, 16.7164f, 0.0f);
    glVertex3f(0.2f, 16.791f, 0.0f);
    glVertex3f(0.2667f, 16.791f, 0.0f);
    glVertex3f(0.2667f, 16.9403f, 0.0f);
    glVertex3f(0.3333f, 17.0149f, 0.0f);
    glVertex3f(0.3333f, 17.0896f, 0.0f);
    glVertex3f(0.3333f, 17.1642f, 0.0f);
    glVertex3f(0.4f, 17.2388f, 0.0f);
    glVertex3f(0.4667f, 17.2388f, 0.0f);
    glVertex3f(0.5333f, 17.3134f, 0.0f);


    glEnd();



    glBegin(GL_TRIANGLE_FAN);   // background green pahar right

    glColor3f(0.396, 0.494, 0.098);
    glVertex3f(40.4667f, 16.791f, 0.0f);



    glVertex3f(27.6667f, 15.6716f, 0.0f);
    glVertex3f(27.7333f, 15.6716f, 0.0f);
    glVertex3f(27.7333f, 15.7463f, 0.0f);
    glVertex3f(27.8f, 15.7463f, 0.0f);
    glVertex3f(27.8f, 15.8209f, 0.0f);
    glVertex3f(27.9333f, 15.8955f, 0.0f);
    glVertex3f(27.9333f, 15.9701f, 0.0f);
    glVertex3f(28.0667f, 16.0448f, 0.0f);
    glVertex3f(28.1333f, 16.1194f, 0.0f);
    glVertex3f(28.2f, 16.194f, 0.0f);
    glVertex3f(28.2f, 16.2687f, 0.0f);
    glVertex3f(28.3333f, 16.3433f, 0.0f);
    glVertex3f(28.4f, 16.3433f, 0.0f);
    glVertex3f(28.4667f, 16.4179f, 0.0f);
    glVertex3f(28.4667f, 16.4925f, 0.0f);
    glVertex3f(28.6f, 16.6418f, 0.0f);
    glVertex3f(28.6667f, 16.7164f, 0.0f);
    glVertex3f(28.6667f, 16.791f, 0.0f);
    glVertex3f(28.7333f, 16.8657f, 0.0f);
    glVertex3f(28.8f, 16.8657f, 0.0f);
    glVertex3f(28.8667f, 16.9403f, 0.0f);
    glVertex3f(28.9333f, 17.0149f, 0.0f);
    glVertex3f(29.0667f, 17.0896f, 0.0f);
    glVertex3f(29.2f, 17.2388f, 0.0f);
    glVertex3f(29.4667f, 17.3881f, 0.0f);
    glVertex3f(29.6f, 17.4627f, 0.0f);
    glVertex3f(29.7333f, 17.5373f, 0.0f);
    glVertex3f(29.8667f, 17.5373f, 0.0f);
    glVertex3f(30.0f, 17.6119f, 0.0f);
    glVertex3f(30.0667f, 17.6119f, 0.0f);
    glVertex3f(30.2f, 17.6866f, 0.0f);
    glVertex3f(30.2667f, 17.7612f, 0.0f);
    glVertex3f(30.4f, 17.8358f, 0.0f);
    glVertex3f(30.4667f, 17.9104f, 0.0f);
    glVertex3f(30.6f, 17.9104f, 0.0f);
    glVertex3f(30.7333f, 17.9851f, 0.0f);
    glVertex3f(30.8667f, 18.0597f, 0.0f);
    glVertex3f(30.9333f, 18.0597f, 0.0f);
    glVertex3f(31.0f, 18.1343f, 0.0f);
    glVertex3f(31.0667f, 18.1343f, 0.0f);
    glVertex3f(31.1333f, 18.209f, 0.0f);
    glVertex3f(31.2f, 18.209f, 0.0f);
    glVertex3f(31.2f, 18.2836f, 0.0f);
    glVertex3f(31.2667f, 18.2836f, 0.0f);
    glVertex3f(31.3333f, 18.3582f, 0.0f);
    glVertex3f(31.4f, 18.4328f, 0.0f);
    glVertex3f(31.4667f, 18.5075f, 0.0f);
    glVertex3f(31.6f, 18.5821f, 0.0f);
    glVertex3f(31.6667f, 18.5821f, 0.0f);
    glVertex3f(31.7333f, 18.7313f, 0.0f);
    glVertex3f(31.8667f, 18.806f, 0.0f);
    glVertex3f(32.0f, 18.8806f, 0.0f);
    glVertex3f(32.0667f, 18.8806f, 0.0f);
    glVertex3f(32.0667f, 18.9552f, 0.0f);
    glVertex3f(32.1333f, 19.0299f, 0.0f);
    glVertex3f(32.2f, 19.1045f, 0.0f);
    glVertex3f(32.4667f, 19.2537f, 0.0f);
    glVertex3f(32.4667f, 19.3284f, 0.0f);
    glVertex3f(32.5333f, 19.3284f, 0.0f);
    glVertex3f(32.6f, 19.403f, 0.0f);
    glVertex3f(32.6667f, 19.4776f, 0.0f);
    glVertex3f(32.7333f, 19.5522f, 0.0f);
    glVertex3f(32.8f, 19.6269f, 0.0f);
    glVertex3f(32.8667f, 19.6269f, 0.0f);
    glVertex3f(32.9333f, 19.7015f, 0.0f);
    glVertex3f(32.9333f, 19.7761f, 0.0f);
    glVertex3f(33.0f, 19.7761f, 0.0f);
    glVertex3f(33.0667f, 19.8507f, 0.0f);
    glVertex3f(33.1333f, 19.8507f, 0.0f);
    glVertex3f(33.1333f, 19.9254f, 0.0f);
    glVertex3f(33.1333f, 20.0f, 0.0f);
    glVertex3f(33.2f, 20.0f, 0.0f);
    glVertex3f(33.2f, 20.0746f, 0.0f);
    glVertex3f(33.2667f, 20.0746f, 0.0f);
    glVertex3f(33.2667f, 20.1493f, 0.0f);
    glVertex3f(33.3333f, 20.2239f, 0.0f);
    glVertex3f(33.4f, 20.2985f, 0.0f);
    glVertex3f(33.4f, 20.3731f, 0.0f);
    glVertex3f(33.4667f, 20.3731f, 0.0f);
    glVertex3f(33.4667f, 20.4478f, 0.0f);
    glVertex3f(33.6f, 20.5224f, 0.0f);
    glVertex3f(33.6f, 20.597f, 0.0f);
    glVertex3f(33.6667f, 20.597f, 0.0f);
    glVertex3f(33.6667f, 20.6716f, 0.0f);
    glVertex3f(33.8f, 20.7463f, 0.0f);
    glVertex3f(33.8667f, 20.8209f, 0.0f);
    glVertex3f(33.9333f, 20.8955f, 0.0f);
    glVertex3f(34.0f, 21.0448f, 0.0f);
    glVertex3f(34.0667f, 21.0448f, 0.0f);
    glVertex3f(34.0667f, 21.1194f, 0.0f);
    glVertex3f(34.1333f, 21.194f, 0.0f);
    glVertex3f(34.2f, 21.194f, 0.0f);
    glVertex3f(34.2f, 21.2687f, 0.0f);
    glVertex3f(34.2667f, 21.2687f, 0.0f);
    glVertex3f(34.3333f, 21.3433f, 0.0f);
    glVertex3f(34.4f, 21.3433f, 0.0f);
    glVertex3f(34.4f, 21.4179f, 0.0f);
    glVertex3f(34.4667f, 21.4925f, 0.0f);
    glVertex3f(34.5333f, 21.5672f, 0.0f);
    glVertex3f(34.6f, 21.6418f, 0.0f);
    glVertex3f(34.6667f, 21.6418f, 0.0f);
    glVertex3f(34.6667f, 21.7164f, 0.0f);
    glVertex3f(34.7333f, 21.7164f, 0.0f);
    glVertex3f(34.8f, 21.791f, 0.0f);
    glVertex3f(34.8667f, 21.791f, 0.0f);
    glVertex3f(34.8667f, 21.8657f, 0.0f);
    glVertex3f(34.9333f, 21.8657f, 0.0f);
    glVertex3f(34.9333f, 21.9403f, 0.0f);
    glVertex3f(35.0f, 22.0149f, 0.0f);
    glVertex3f(35.0667f, 22.0149f, 0.0f);
    glVertex3f(35.1333f, 22.0896f, 0.0f);
    glVertex3f(35.1333f, 22.1642f, 0.0f);
    glVertex3f(35.2f, 22.2388f, 0.0f);
    glVertex3f(35.2667f, 22.2388f, 0.0f);
    glVertex3f(35.3333f, 22.3134f, 0.0f);
    glVertex3f(35.3333f, 22.3881f, 0.0f);
    glVertex3f(35.4f, 22.3881f, 0.0f);
    glVertex3f(35.4667f, 22.4627f, 0.0f);
    glVertex3f(35.5333f, 22.4627f, 0.0f);
    glVertex3f(35.5333f, 22.5373f, 0.0f);
    glVertex3f(35.6667f, 22.6119f, 0.0f);
    glVertex3f(35.7333f, 22.6866f, 0.0f);
    glVertex3f(35.8f, 22.6866f, 0.0f);
    glVertex3f(35.8667f, 22.7612f, 0.0f);
    glVertex3f(35.8667f, 22.8358f, 0.0f);
    glVertex3f(35.9333f, 22.8358f, 0.0f);
    glVertex3f(36.0f, 22.9104f, 0.0f);
    glVertex3f(36.0667f, 22.9104f, 0.0f);
    glVertex3f(36.0667f, 22.9851f, 0.0f);
    glVertex3f(36.2f, 23.0597f, 0.0f);
    glVertex3f(36.2667f, 23.0597f, 0.0f);
    glVertex3f(36.3333f, 23.209f, 0.0f);
    glVertex3f(36.4667f, 23.209f, 0.0f);
    glVertex3f(36.5333f, 23.2836f, 0.0f);
    glVertex3f(36.6667f, 23.3582f, 0.0f);
    glVertex3f(36.6667f, 23.4328f, 0.0f);
    glVertex3f(36.7333f, 23.5075f, 0.0f);
    glVertex3f(36.8667f, 23.5821f, 0.0f);
    glVertex3f(36.9333f, 23.6567f, 0.0f);
    glVertex3f(36.9333f, 23.7313f, 0.0f);
    glVertex3f(37.0f, 23.7313f, 0.0f);
    glVertex3f(37.0667f, 23.806f, 0.0f);
    glVertex3f(37.1333f, 23.806f, 0.0f);
    glVertex3f(37.2667f, 23.8806f, 0.0f);
    glVertex3f(37.3333f, 23.9552f, 0.0f);
    glVertex3f(37.3333f, 24.0299f, 0.0f);
    glVertex3f(37.4f, 24.0299f, 0.0f);
    glVertex3f(37.4f, 24.1045f, 0.0f);
    glVertex3f(37.4667f, 24.1045f, 0.0f);
    glVertex3f(37.5333f, 24.1791f, 0.0f);
    glVertex3f(37.5333f, 24.2537f, 0.0f);
    glVertex3f(37.6f, 24.3284f, 0.0f);
    glVertex3f(37.6f, 24.403f, 0.0f);
    glVertex3f(37.6667f, 24.4776f, 0.0f);
    glVertex3f(37.7333f, 24.4776f, 0.0f);
    glVertex3f(37.7333f, 24.5522f, 0.0f);
    glVertex3f(37.8f, 24.6269f, 0.0f);
    glVertex3f(37.9333f, 24.7015f, 0.0f);
    glVertex3f(37.9333f, 24.7761f, 0.0f);
    glVertex3f(38.0f, 24.8507f, 0.0f);
    glVertex3f(38.0f, 24.9254f, 0.0f);
    glVertex3f(38.1333f, 24.9254f, 0.0f);
    glVertex3f(38.1333f, 25.0f, 0.0f);
    glVertex3f(38.2f, 25.0746f, 0.0f);
    glVertex3f(38.2667f, 25.1493f, 0.0f);
    glVertex3f(38.3333f, 25.1493f, 0.0f);
    glVertex3f(38.4f, 25.2239f, 0.0f);
    glVertex3f(38.4667f, 25.2239f, 0.0f);
    glVertex3f(38.4667f, 25.2985f, 0.0f);
    glVertex3f(38.5333f, 25.3731f, 0.0f);
    glVertex3f(38.6f, 25.3731f, 0.0f);
    glVertex3f(38.6667f, 25.3731f, 0.0f);
    glVertex3f(38.6667f, 25.4478f, 0.0f);
    glVertex3f(38.7333f, 25.4478f, 0.0f);
    glVertex3f(38.7333f, 25.5224f, 0.0f);
    glVertex3f(38.8667f, 25.597f, 0.0f);
    glVertex3f(38.9333f, 25.597f, 0.0f);
    glVertex3f(38.9333f, 25.6716f, 0.0f);
    glVertex3f(39.0667f, 25.6716f, 0.0f);
    glVertex3f(39.1333f, 25.7463f, 0.0f);
    glVertex3f(39.2f, 25.8209f, 0.0f);
    glVertex3f(39.2667f, 25.8209f, 0.0f);
    glVertex3f(39.3333f, 25.8955f, 0.0f);
    glVertex3f(39.4f, 25.9701f, 0.0f);
    glVertex3f(39.4667f, 25.9701f, 0.0f);
    glVertex3f(39.5333f, 25.9701f, 0.0f);
    glVertex3f(39.6f, 25.9701f, 0.0f);
    glVertex3f(39.6667f, 25.9701f, 0.0f);
    glVertex3f(39.7333f, 25.9701f, 0.0f);
    glVertex3f(39.8f, 25.9701f, 0.0f);
    glVertex3f(39.8f, 26.0448f, 0.0f);
    glVertex3f(39.8667f, 26.0448f, 0.0f);
    glVertex3f(39.9333f, 26.0448f, 0.0f);
    glVertex3f(40.0f, 26.0448f, 0.0f);
    glVertex3f(40.0667f, 26.0448f, 0.0f);
    glVertex3f(40.1333f, 26.0448f, 0.0f);
    glVertex3f(40.2f, 26.1194f, 0.0f);
    glVertex3f(40.2667f, 26.194f, 0.0f);
    glVertex3f(40.3333f, 26.194f, 0.0f);
    glVertex3f(40.4f, 26.194f, 0.0f);
    glVertex3f(40.4667f, 26.194f, 0.0f);
    glVertex3f(40.5333f, 26.194f, 0.0f);
    glVertex3f(40.6f, 26.194f, 0.0f);
    glVertex3f(40.7333f, 26.2687f, 0.0f);
    glVertex3f(40.8f, 26.2687f, 0.0f);
    glVertex3f(40.8667f, 26.2687f, 0.0f);
    glVertex3f(40.9333f, 26.2687f, 0.0f);
    glVertex3f(41.0f, 26.2687f, 0.0f);
    glVertex3f(41.0667f, 26.2687f, 0.0f);
    glVertex3f(41.2f, 26.2687f, 0.0f);
    glVertex3f(41.2667f, 26.2687f, 0.0f);
    glVertex3f(41.3333f, 26.194f, 0.0f);
    glVertex3f(41.4f, 26.194f, 0.0f);
    glVertex3f(41.4667f, 26.194f, 0.0f);
    glVertex3f(41.5333f, 26.194f, 0.0f);
    glVertex3f(41.6f, 26.194f, 0.0f);
    glVertex3f(41.6667f, 26.1194f, 0.0f);
    glVertex3f(41.7333f, 26.1194f, 0.0f);
    glVertex3f(41.8f, 26.1194f, 0.0f);
    glVertex3f(41.8667f, 26.1194f, 0.0f);
    glVertex3f(41.9333f, 26.1194f, 0.0f);
    glVertex3f(42.0f, 26.1194f, 0.0f);
    glVertex3f(42.0f, 26.0448f, 0.0f);
    glVertex3f(42.1333f, 26.0448f, 0.0f);
    glVertex3f(42.1333f, 25.9701f, 0.0f);
    glVertex3f(42.2f, 25.8955f, 0.0f);
    glVertex3f(42.2667f, 25.8955f, 0.0f);
    glVertex3f(42.3333f, 25.8209f, 0.0f);
    glVertex3f(42.4667f, 25.8209f, 0.0f);
    glVertex3f(42.5333f, 25.7463f, 0.0f);
    glVertex3f(42.5333f, 25.6716f, 0.0f);
    glVertex3f(42.6f, 25.6716f, 0.0f);
    glVertex3f(42.6667f, 25.597f, 0.0f);
    glVertex3f(42.8f, 25.5224f, 0.0f);
    glVertex3f(42.8f, 25.4478f, 0.0f);
    glVertex3f(42.8667f, 25.4478f, 0.0f);
    glVertex3f(42.9333f, 25.3731f, 0.0f);
    glVertex3f(43.0f, 25.2985f, 0.0f);
    glVertex3f(43.0f, 25.2239f, 0.0f);
    glVertex3f(43.0667f, 25.2239f, 0.0f);
    glVertex3f(43.1333f, 25.1493f, 0.0f);
    glVertex3f(43.2f, 25.0746f, 0.0f);
    glVertex3f(43.2667f, 25.0f, 0.0f);
    glVertex3f(43.3333f, 25.0f, 0.0f);
    glVertex3f(43.3333f, 24.9254f, 0.0f);
    glVertex3f(43.4667f, 24.8507f, 0.0f);
    glVertex3f(43.5333f, 24.8507f, 0.0f);
    glVertex3f(43.5333f, 24.7761f, 0.0f);
    glVertex3f(43.6f, 24.7761f, 0.0f);
    glVertex3f(43.6667f, 24.7015f, 0.0f);
    glVertex3f(43.7333f, 24.7015f, 0.0f);
    glVertex3f(43.7333f, 24.6269f, 0.0f);
    glVertex3f(43.8f, 24.5522f, 0.0f);
    glVertex3f(43.8667f, 24.5522f, 0.0f);
    glVertex3f(43.8667f, 24.4776f, 0.0f);
    glVertex3f(43.9333f, 24.403f, 0.0f);
    glVertex3f(43.9333f, 24.3284f, 0.0f);
    glVertex3f(44.0667f, 24.1791f, 0.0f);
    glVertex3f(44.1333f, 24.1791f, 0.0f);
    glVertex3f(44.2f, 24.1045f, 0.0f);
    glVertex3f(44.3333f, 24.0299f, 0.0f);
    glVertex3f(44.4f, 23.8806f, 0.0f);
    glVertex3f(44.5333f, 23.806f, 0.0f);
    glVertex3f(44.6f, 23.7313f, 0.0f);
    glVertex3f(44.6667f, 23.6567f, 0.0f);
    glVertex3f(44.7333f, 23.6567f, 0.0f);
    glVertex3f(44.8f, 23.5821f, 0.0f);
    glVertex3f(44.8f, 23.5075f, 0.0f);
    glVertex3f(44.8667f, 23.4328f, 0.0f);
    glVertex3f(44.9333f, 23.3582f, 0.0f);
    glVertex3f(45.0f, 23.2836f, 0.0f);
    glVertex3f(45.0667f, 23.2836f, 0.0f);
    glVertex3f(45.0667f, 23.1343f, 0.0f);
    glVertex3f(45.2f, 23.1343f, 0.0f);
    glVertex3f(45.2667f, 23.0597f, 0.0f);
    glVertex3f(45.3333f, 22.9851f, 0.0f);
    glVertex3f(45.3333f, 22.9104f, 0.0f);
    glVertex3f(45.4f, 22.9104f, 0.0f);
    glVertex3f(45.4f, 22.8358f, 0.0f);
    glVertex3f(45.4667f, 22.7612f, 0.0f);
    glVertex3f(45.4667f, 22.6866f, 0.0f);
    glVertex3f(45.5333f, 22.6866f, 0.0f);
    glVertex3f(45.6f, 22.5373f, 0.0f);
    glVertex3f(45.6667f, 22.4627f, 0.0f);
    glVertex3f(45.7333f, 22.3881f, 0.0f);
    glVertex3f(45.8f, 22.3134f, 0.0f);
    glVertex3f(45.8667f, 22.2388f, 0.0f);
    glVertex3f(45.9333f, 22.1642f, 0.0f);
    glVertex3f(46.0f, 22.0896f, 0.0f);
    glVertex3f(46.0667f, 22.0149f, 0.0f);
    glVertex3f(46.0667f, 21.9403f, 0.0f);
    glVertex3f(46.0667f, 21.8657f, 0.0f);
    glVertex3f(46.1333f, 21.791f, 0.0f);
    glVertex3f(46.2f, 21.791f, 0.0f);
    glVertex3f(46.2f, 21.6418f, 0.0f);
    glVertex3f(46.2667f, 21.6418f, 0.0f);
    glVertex3f(46.2667f, 21.5672f, 0.0f);
    glVertex3f(46.3333f, 21.4179f, 0.0f);
    glVertex3f(46.4f, 21.4179f, 0.0f);
    glVertex3f(46.4f, 21.3433f, 0.0f);
    glVertex3f(46.4667f, 21.2687f, 0.0f);
    glVertex3f(46.4667f, 21.194f, 0.0f);
    glVertex3f(46.4667f, 21.1194f, 0.0f);
    glVertex3f(46.5333f, 21.1194f, 0.0f);
    glVertex3f(46.5333f, 21.0448f, 0.0f);
    glVertex3f(46.6f, 20.9701f, 0.0f);
    glVertex3f(46.6667f, 20.8955f, 0.0f);
    glVertex3f(46.7333f, 20.8209f, 0.0f);
    glVertex3f(46.8f, 20.7463f, 0.0f);
    glVertex3f(46.8667f, 20.6716f, 0.0f);
    glVertex3f(46.9333f, 20.597f, 0.0f);
    glVertex3f(47.0f, 20.5224f, 0.0f);
    glVertex3f(47.0f, 20.4478f, 0.0f);
    glVertex3f(47.0667f, 20.3731f, 0.0f);
    glVertex3f(47.1333f, 20.2985f, 0.0f);
    glVertex3f(47.2f, 20.2239f, 0.0f);
    glVertex3f(47.2667f, 20.1493f, 0.0f);
    glVertex3f(47.2667f, 20.0746f, 0.0f);
    glVertex3f(47.3333f, 20.0f, 0.0f);
    glVertex3f(47.4f, 19.9254f, 0.0f);
    glVertex3f(47.4667f, 19.8507f, 0.0f);
    glVertex3f(47.4667f, 19.7761f, 0.0f);
    glVertex3f(47.5333f, 19.7015f, 0.0f);
    glVertex3f(47.6f, 19.7015f, 0.0f);
    glVertex3f(47.6f, 19.6269f, 0.0f);
    glVertex3f(47.6667f, 19.5522f, 0.0f);
    glVertex3f(47.6667f, 19.4776f, 0.0f);
    glVertex3f(47.7333f, 19.4776f, 0.0f);
    glVertex3f(47.8f, 19.403f, 0.0f);
    glVertex3f(47.8667f, 19.2537f, 0.0f);
    glVertex3f(47.8667f, 19.1791f, 0.0f);
    glVertex3f(47.9333f, 19.1045f, 0.0f);
    glVertex3f(48.0f, 19.0299f, 0.0f);
    glVertex3f(48.0667f, 18.9552f, 0.0f);
    glVertex3f(48.0667f, 18.8806f, 0.0f);
    glVertex3f(48.1333f, 18.806f, 0.0f);
    glVertex3f(48.1333f, 18.7313f, 0.0f);
    glVertex3f(48.2f, 18.7313f, 0.0f);
    glVertex3f(48.2667f, 18.6567f, 0.0f);
    glVertex3f(48.2667f, 18.5821f, 0.0f);
    glVertex3f(48.3333f, 18.5075f, 0.0f);
    glVertex3f(48.3333f, 18.4328f, 0.0f);
    glVertex3f(48.4f, 18.4328f, 0.0f);
    glVertex3f(48.4f, 18.3582f, 0.0f);
    glVertex3f(48.4667f, 18.3582f, 0.0f);
    glVertex3f(48.5333f, 18.2836f, 0.0f);
    glVertex3f(48.5333f, 18.209f, 0.0f);
    glVertex3f(48.6f, 18.209f, 0.0f);
    glVertex3f(48.6f, 18.1343f, 0.0f);
    glVertex3f(48.6667f, 18.1343f, 0.0f);
    glVertex3f(48.6667f, 18.0597f, 0.0f);
    glVertex3f(48.8f, 17.9851f, 0.0f);
    glVertex3f(48.8f, 17.9104f, 0.0f);
    glVertex3f(48.8667f, 17.9104f, 0.0f);
    glVertex3f(48.9333f, 17.8358f, 0.0f);
    glVertex3f(49.0f, 17.7612f, 0.0f);
    glVertex3f(49.0f, 17.6866f, 0.0f);
    glVertex3f(49.0667f, 17.6119f, 0.0f);
    glVertex3f(49.1333f, 17.5373f, 0.0f);
    glVertex3f(49.2f, 17.5373f, 0.0f);
    glVertex3f(49.2f, 17.4627f, 0.0f);
    glVertex3f(49.2667f, 17.4627f, 0.0f);
    glVertex3f(49.2667f, 17.3881f, 0.0f);
    glVertex3f(49.3333f, 17.3881f, 0.0f);
    glVertex3f(49.4f, 17.3134f, 0.0f);
    glVertex3f(49.4667f, 17.3134f, 0.0f);
    glVertex3f(49.5333f, 17.2388f, 0.0f);
    glVertex3f(49.6f, 17.1642f, 0.0f);
    glVertex3f(49.6f, 17.0896f, 0.0f);
    glVertex3f(49.6667f, 17.0149f, 0.0f);
    glVertex3f(49.7333f, 16.9403f, 0.0f);
    glVertex3f(49.8f, 16.8657f, 0.0f);
    glVertex3f(49.8667f, 16.8657f, 0.0f);
    glVertex3f(49.8667f, 16.791f, 0.0f);
    glVertex3f(49.9333f, 16.7164f, 0.0f);
    glVertex3f(50.0f, 16.6418f, 0.0f);
    glVertex3f(50.0667f, 16.4925f, 0.0f);
    glVertex3f(50.0667f, 16.4179f, 0.0f);
    glVertex3f(50.2f, 16.3433f, 0.0f);
    glVertex3f(50.2667f, 16.194f, 0.0f);
    glVertex3f(50.3333f, 16.1194f, 0.0f);
    glVertex3f(50.3333f, 16.0448f, 0.0f);
    glVertex3f(50.4f, 16.0448f, 0.0f);
    glVertex3f(50.4f, 15.9701f, 0.0f);
    glVertex3f(50.4667f, 15.8955f, 0.0f);
    glVertex3f(50.5333f, 15.8209f, 0.0f);
    glVertex3f(50.6f, 15.7463f, 0.0f);
    glVertex3f(50.6667f, 15.6716f, 0.0f);
    glVertex3f(50.6667f, 15.597f, 0.0f);
    glVertex3f(50.7333f, 15.597f, 0.0f);
    glVertex3f(50.7333f, 15.5224f, 0.0f);
    glVertex3f(50.8f, 15.4478f, 0.0f);
    glVertex3f(50.8667f, 15.3731f, 0.0f);
    glVertex3f(50.8667f, 15.2985f, 0.0f);
    glVertex3f(50.9333f, 15.2239f, 0.0f);
    glVertex3f(51.0f, 15.1493f, 0.0f);
    glVertex3f(51.0667f, 15.0746f, 0.0f);
    glVertex3f(51.0667f, 15.0f, 0.0f);
    glVertex3f(51.1333f, 15.0f, 0.0f);
    glVertex3f(51.1333f, 14.8507f, 0.0f);
    glVertex3f(51.2f, 14.8507f, 0.0f);
    glVertex3f(51.2667f, 14.7761f, 0.0f);
    glVertex3f(51.4f, 14.7015f, 0.0f);
    glVertex3f(51.4f, 14.6269f, 0.0f);
    glVertex3f(51.3333f, 14.5522f, 0.0f);
    glVertex3f(51.2667f, 14.5522f, 0.0f);
    glVertex3f(51.2f, 14.5522f, 0.0f);
    glVertex3f(51.1333f, 14.4776f, 0.0f);
    glVertex3f(51.0f, 14.403f, 0.0f);
    glVertex3f(50.9333f, 14.403f, 0.0f);
    glVertex3f(50.8f, 14.3284f, 0.0f);
    glVertex3f(50.6667f, 14.2537f, 0.0f);
    glVertex3f(50.5333f, 14.2537f, 0.0f);
    glVertex3f(50.4667f, 14.2537f, 0.0f);
    glVertex3f(50.2667f, 14.1791f, 0.0f);
    glVertex3f(50.1333f, 14.1791f, 0.0f);
    glVertex3f(49.8f, 14.1045f, 0.0f);
    glVertex3f(49.7333f, 14.1045f, 0.0f);
    glVertex3f(49.5333f, 14.0299f, 0.0f);
    glVertex3f(49.4667f, 14.0299f, 0.0f);
    glVertex3f(49.2667f, 13.9552f, 0.0f);
    glVertex3f(49.0667f, 13.9552f, 0.0f);
    glVertex3f(48.8667f, 13.9552f, 0.0f);
    glVertex3f(48.6f, 13.8806f, 0.0f);
    glVertex3f(48.4f, 13.8806f, 0.0f);
    glVertex3f(48.1333f, 13.8806f, 0.0f);
    glVertex3f(47.8667f, 13.8806f, 0.0f);
    glVertex3f(47.6f, 13.8806f, 0.0f);
    glVertex3f(47.3333f, 13.8806f, 0.0f);
    glVertex3f(47.1333f, 13.8806f, 0.0f);
    glVertex3f(46.9333f, 13.8806f, 0.0f);
    glVertex3f(46.7333f, 13.8806f, 0.0f);
    glVertex3f(46.5333f, 13.8806f, 0.0f);
    glVertex3f(46.2667f, 13.8806f, 0.0f);
    glVertex3f(46.0f, 13.8806f, 0.0f);
    glVertex3f(45.7333f, 13.8806f, 0.0f);
    glVertex3f(45.4667f, 13.8806f, 0.0f);
    glVertex3f(45.2f, 13.8806f, 0.0f);
    glVertex3f(44.8667f, 13.8806f, 0.0f);
    glVertex3f(44.6f, 13.8806f, 0.0f);
    glVertex3f(44.3333f, 13.8806f, 0.0f);
    glVertex3f(44.1333f, 13.8806f, 0.0f);
    glVertex3f(44.0f, 13.8806f, 0.0f);
    glVertex3f(43.8f, 13.8806f, 0.0f);
    glVertex3f(43.6667f, 13.8806f, 0.0f);
    glVertex3f(43.5333f, 13.8806f, 0.0f);
    glVertex3f(43.4f, 13.8806f, 0.0f);
    glVertex3f(43.2f, 13.8806f, 0.0f);
    glVertex3f(43.0667f, 13.8806f, 0.0f);
    glVertex3f(42.8667f, 13.8806f, 0.0f);
    glVertex3f(42.6667f, 13.8806f, 0.0f);
    glVertex3f(42.4667f, 13.8806f, 0.0f);
    glVertex3f(42.2667f, 13.8806f, 0.0f);
    glVertex3f(42.0667f, 13.8806f, 0.0f);
    glVertex3f(41.8667f, 13.8806f, 0.0f);
    glVertex3f(41.6667f, 13.8806f, 0.0f);
    glVertex3f(41.4667f, 13.8806f, 0.0f);
    glVertex3f(41.2667f, 13.8806f, 0.0f);
    glVertex3f(41.0667f, 13.8806f, 0.0f);
    glVertex3f(40.8667f, 13.8806f, 0.0f);
    glVertex3f(40.6667f, 13.8806f, 0.0f);
    glVertex3f(40.5333f, 13.8806f, 0.0f);
    glVertex3f(40.3333f, 13.8806f, 0.0f);
    glVertex3f(40.1333f, 13.8806f, 0.0f);
    glVertex3f(39.9333f, 13.8806f, 0.0f);
    glVertex3f(39.6f, 13.9552f, 0.0f);
    glVertex3f(39.5333f, 13.9552f, 0.0f);
    glVertex3f(39.2667f, 13.9552f, 0.0f);
    glVertex3f(39.1333f, 13.9552f, 0.0f);
    glVertex3f(38.9333f, 14.0299f, 0.0f);
    glVertex3f(38.8667f, 14.0299f, 0.0f);
    glVertex3f(38.5333f, 14.1045f, 0.0f);
    glVertex3f(38.4f, 14.1791f, 0.0f);
    glVertex3f(38.2667f, 14.1791f, 0.0f);
    glVertex3f(38.0667f, 14.1791f, 0.0f);
    glVertex3f(37.8667f, 14.1791f, 0.0f);
    glVertex3f(37.6f, 14.2537f, 0.0f);
    glVertex3f(37.4667f, 14.2537f, 0.0f);
    glVertex3f(37.2f, 14.2537f, 0.0f);
    glVertex3f(37.0667f, 14.2537f, 0.0f);
    glVertex3f(36.7333f, 14.2537f, 0.0f);
    glVertex3f(36.4f, 14.2537f, 0.0f);
    glVertex3f(36.0667f, 14.2537f, 0.0f);
    glVertex3f(35.8f, 14.2537f, 0.0f);
    glVertex3f(35.4f, 14.2537f, 0.0f);
    glVertex3f(35.1333f, 14.2537f, 0.0f);
    glVertex3f(34.8667f, 14.2537f, 0.0f);
    glVertex3f(34.5333f, 14.2537f, 0.0f);
    glVertex3f(34.2667f, 14.2537f, 0.0f);
    glVertex3f(33.8667f, 14.3284f, 0.0f);
    glVertex3f(33.6667f, 14.3284f, 0.0f);
    glVertex3f(33.4667f, 14.3284f, 0.0f);
    glVertex3f(33.3333f, 14.3284f, 0.0f);
    glVertex3f(33.2f, 14.3284f, 0.0f);
    glVertex3f(33.1333f, 14.3284f, 0.0f);
    glVertex3f(33.0f, 14.3284f, 0.0f);
    glVertex3f(32.8667f, 14.3284f, 0.0f);
    glVertex3f(32.7333f, 14.3284f, 0.0f);
    glVertex3f(32.6667f, 14.3284f, 0.0f);
    glVertex3f(32.5333f, 14.3284f, 0.0f);
    glVertex3f(32.3333f, 14.3284f, 0.0f);
    glVertex3f(32.1333f, 14.3284f, 0.0f);
    glVertex3f(31.9333f, 14.3284f, 0.0f);
    glVertex3f(31.7333f, 14.3284f, 0.0f);
    glVertex3f(31.6f, 14.3284f, 0.0f);
    glVertex3f(31.4667f, 14.3284f, 0.0f);
    glVertex3f(31.3333f, 14.3284f, 0.0f);
    glVertex3f(31.2f, 14.3284f, 0.0f);
    glVertex3f(31.0667f, 14.3284f, 0.0f);
    glVertex3f(30.9333f, 14.3284f, 0.0f);
    glVertex3f(30.8f, 14.3284f, 0.0f);
    glVertex3f(30.7333f, 14.3284f, 0.0f);
    glVertex3f(30.6667f, 14.3284f, 0.0f);
    glVertex3f(30.6f, 14.3284f, 0.0f);
    glVertex3f(30.5333f, 14.3284f, 0.0f);
    glVertex3f(30.4f, 14.403f, 0.0f);
    glVertex3f(30.2667f, 14.4776f, 0.0f);
    glVertex3f(30.1333f, 14.5522f, 0.0f);
    glVertex3f(29.9333f, 14.5522f, 0.0f);
    glVertex3f(29.8667f, 14.5522f, 0.0f);
    glVertex3f(29.6667f, 14.6269f, 0.0f);
    glVertex3f(29.6f, 14.6269f, 0.0f);
    glVertex3f(29.5333f, 14.6269f, 0.0f);
    glVertex3f(29.4f, 14.6269f, 0.0f);
    glVertex3f(29.3333f, 14.6269f, 0.0f);
    glVertex3f(29.2667f, 14.6269f, 0.0f);
    glVertex3f(29.2f, 14.6269f, 0.0f);
    glVertex3f(29.1333f, 14.6269f, 0.0f);
    glVertex3f(29.0667f, 14.7015f, 0.0f);
    glVertex3f(29.0f, 14.7015f, 0.0f);
    glVertex3f(28.9333f, 14.7761f, 0.0f);
    glVertex3f(28.8f, 14.7761f, 0.0f);
    glVertex3f(28.7333f, 14.7761f, 0.0f);
    glVertex3f(28.6667f, 14.8507f, 0.0f);
    glVertex3f(28.6f, 14.8507f, 0.0f);
    glVertex3f(28.5333f, 14.8507f, 0.0f);
    glVertex3f(28.4667f, 14.8507f, 0.0f);
    glVertex3f(28.4f, 14.9254f, 0.0f);
    glVertex3f(28.3333f, 14.9254f, 0.0f);
    glVertex3f(28.2667f, 14.9254f, 0.0f);
    glVertex3f(28.2667f, 15.0f, 0.0f);
    glVertex3f(28.2f, 15.0f, 0.0f);
    glVertex3f(28.0667f, 15.0746f, 0.0f);
    glVertex3f(28.0f, 15.0746f, 0.0f);
    glVertex3f(27.9333f, 15.1493f, 0.0f);
    glVertex3f(27.8667f, 15.1493f, 0.0f);
    glVertex3f(27.8667f, 15.2239f, 0.0f);
    glVertex3f(27.8f, 15.2985f, 0.0f);
    glVertex3f(27.8f, 15.3731f, 0.0f);
    glVertex3f(27.8f, 15.4478f, 0.0f);
    glVertex3f(27.8f, 15.5224f, 0.0f);
    glVertex3f(27.8f, 15.597f, 0.0f);
    glVertex3f(27.8667f, 15.6716f, 0.0f);
    glVertex3f(27.9333f, 15.8209f, 0.0f);
    glVertex3f(27.9333f, 15.9701f, 0.0f);
    glVertex3f(28.0f, 15.9701f, 0.0f);
    glVertex3f(28.0667f, 15.9701f, 0.0f);
    glVertex3f(28.1333f, 15.9701f, 0.0f);
    glVertex3f(28.2f, 15.9701f, 0.0f);
    glVertex3f(28.2667f, 15.9701f, 0.0f);
    glVertex3f(28.3333f, 15.9701f, 0.0f);
    glVertex3f(28.4f, 16.0448f, 0.0f);

    glEnd();


// From here the clouds will be draw and move automatically
    clouds();


    // S



    glBegin(GL_QUADS);
    glColor3f(0.824, 0.875, 0.42);

    glVertex3f(0.0667f, 0.1493f, 0.0f);
    glVertex3f(49.9333f, 0.1493f, 0.0f);
    glVertex3f(49.9333f, 3.2836f, 0.0f);
    glVertex3f(0.0667f, 3.2836f, 0.0f);
    glEnd();

    //RASTER-LINE
    glBegin(GL_QUADS);
    glColor3f(0.749, 0.208, 0.208);

    glVertex3f(0.0f, 3.2836f, 0.0f);
    glVertex3f(49.8f, 3.2836f, 0.0f);
    glVertex3f(49.8f, 3.5821f, 0.0f);
    glVertex3f(0.0f, 3.5821f, 0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.478, 0.482, 0.49);

    glVertex3f(0.0667f, 3.5821f, 0.0f);
    glVertex3f(49.8667f, 3.5821f, 0.0f);
    glVertex3f(49.8667f, 10.2493f, 0.0f);
    glVertex3f(0.0667f, 10.2493f, 0.0f);
    glEnd();

    //RASTER-LINE
    glBegin(GL_QUADS);
    glColor3f(0.749, 0.208, 0.208);

    glVertex3f(0.2667f, 10.2239f, 0.0f);
    glVertex3f(49.8f, 10.2239f, 0.0f);
    glVertex3f(49.8f, 10.7463f, 0.0f);
    glVertex3f(0.2667f, 10.7463f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.694, 0.694, 0.694);

    glVertex3f(0.2f, 10.597f, 0.0f);
    glVertex3f(49.9333f, 10.597f, 0.0f);
    glVertex3f(49.9333f, 11.5672f, 0.0f);
    glVertex3f(0.2f, 11.5672f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.412, 0.514, 0.173);

    glVertex3f(0.0667f, 11.6418f, 0.0f);
    glVertex3f(49.8667f, 11.6418f, 0.0f);
    glVertex3f(49.8667f, 13.9552f, 0.0f);
    glVertex3f(0.0667f, 13.806f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.886, 0.89, 0.42);

    glVertex3f(0.0667f, 13.806f, 0.0f);
    glVertex3f(49.9333f, 13.806f, 0.0f);
    glVertex3f(49.8f, 17.0149f, 0.0f);
    glVertex3f(0.0667f, 16.8657f, 0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(0.6667f, 6.7164f, 0.0f);
    glVertex3f(2.3333f, 6.7164f, 0.0f);
    glVertex3f(2.6f, 7.1642f, 0.0f);
    glVertex3f(1.1333f, 7.2388f, 0.0f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(5.9333f, 6.7164f, 0.0f);
    glVertex3f(7.5333f, 6.7164f, 0.0f);
    glVertex3f(7.8667f, 7.2388f, 0.0f);
    glVertex3f(6.2f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(11.4667f, 6.7164f, 0.0f);
    glVertex3f(13.1333f, 6.7164f, 0.0f);
    glVertex3f(13.3333f, 7.1642f, 0.0f);
    glVertex3f(11.7333f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(17.00f, 6.7164f, 0.0f);
    glVertex3f(18.7333f, 6.7164f, 0.0f);
    glVertex3f(18.8667f, 7.1642f, 0.0f);
    glVertex3f(17.2f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(22.5333f, 6.7164f, 0.0f);
    glVertex3f(24.3333f, 6.7164f, 0.0f);
    glVertex3f(24.2667f, 7.2388f, 0.0f);
    glVertex3f(22.5333f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(27.5333f, 6.7164f, 0.0f);
    glVertex3f(29.3333f, 6.7164f, 0.0f);
    glVertex3f(29.2667f, 7.2388f, 0.0f);
    glVertex3f(27.5333f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(32.5333f, 6.7164f, 0.0f);
    glVertex3f(34.3333f, 6.7164f, 0.0f);
    glVertex3f(34.2667f, 7.2388f, 0.0f);
    glVertex3f(32.5333f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(36.5333f, 6.7164f, 0.0f);
    glVertex3f(38.3333f, 6.7164f, 0.0f);
    glVertex3f(38.2667f, 7.2388f, 0.0f);
    glVertex3f(36.5333f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(42.2f, 6.7164f, 0.0f);
    glVertex3f(43.8f, 6.7164f, 0.0f);
    glVertex3f(43.3333f, 7.2388f, 0.0f);
    glVertex3f(41.8f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.875, 0.875, 0.875);
    glVertex3f(47.4f, 6.7164f, 0.0f);
    glVertex3f(48.8667f, 6.7164f, 0.0f);
    glVertex3f(48.5333f, 7.2388f, 0.0f);
    glVertex3f(47.0f, 7.2388f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.576, 0.337, 0.161);

    glVertex3f(36.7333f, 13.6552f, 0.0f);
    glVertex3f(37.4f, 13.6552f, 0.0f);
    glVertex3f(37.4f, 17.5373f, 0.0f);
    glVertex3f(36.7333f, 17.5373f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.659, 0.702, 0.192);
    glVertex3f(33.4667f, 17.5373f, 0.0f);
    glVertex3f(41.1333f, 17.5373f, 0.0f);
    glVertex3f(39.0f, 24.0299f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.576, 0.337, 0.161);
    glVertex3f(47.6667f, 13.7313f, 0.0f);
    glVertex3f(48.0667f, 13.7313f, 0.0f);
    glVertex3f(48.0667f, 16.9403f, 0.0f);
    glVertex3f(47.6667f, 16.9403f, 0.0f);
    glEnd();


//TREE

    glBegin(GL_TRIANGLES);
    glColor3f(0.659, 0.702, 0.192);
    glVertex3f(46.2f, 16.9403f, 0.0f);
    glVertex3f(49.8f, 16.9403f, 0.0f);
    glVertex3f(48.4667f, 23.0597f, 0.0f);
    glEnd();

    //house
    glBegin(GL_QUADS);
    glColor3f(0.706, 0.835, 0.855);

    glVertex3f(2.0667f, 12.5373f, 0.0f);
    glVertex3f(10.2667f, 12.5373f, 0.0f);
    glVertex3f(10.3333f, 12.9104f, 0.0f);
    glVertex3f(2.1333f, 12.9104f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.675, 0.682);
    glVertex3f(2.1333f, 12.9104f, 0.0f);
    glVertex3f(10.2667f, 12.9104f, 0.0f);
    glVertex3f(10.2667f, 15.8209f, 0.0f);
    glVertex3f(2.1333f, 15.8209f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.6f, 12.9104f, 0.0f);
    glVertex3f(5.0f, 12.9104f, 0.0f);
    glVertex3f(5.0f, 15.3731f, 0.0f);
    glVertex3f(2.6f, 15.3731f, 0.0f);
    glEnd();

    //DORJA
    glBegin(GL_QUADS);
    glColor3f(0.592, 0.369, 0.192);

    glVertex3f(6.1333f, 12.5373f, 0.0f);
    glVertex3f(7.5333f, 12.5373f, 0.0f);
    glVertex3f(7.533f, 15.1493f, 0.0f);
    glVertex3f(6.1333f, 15.1493f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.49, 0.212, 0.267);

    glVertex3f(1.4f, 15.8209f, 0.0f);
    glVertex3f(10.8f, 15.8209f, 0.0f);
    glVertex3f(10.2f, 17.7612f, 0.0f);
    glVertex3f(1.9333f, 17.7612f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.706, 0.835, 0.855);

    glVertex3f(5.1333f, 16.7164f, 0.0f);
    glVertex3f(9.9333, 16.7164f, 0.0f);
    glVertex3f(9.9333f, 17.0149f, 0.0f);
    glVertex3f(5.1333f, 17.0149f, 0.0f);
    glEnd();

    //2tala
    glBegin(GL_QUADS);
    glColor3f(0.392, 0.671, 0.678);

    glVertex3f(5.1333f, 16.9403f, 0.0f);
    glVertex3f(9.9333f, 16.9403f, 0.0f);
    glVertex3f(9.9333f, 20.0746f, 0.0f);
    glVertex3f(5.1333f, 20.0746f, 0.0f);
    glEnd();

    //sad
    glBegin(GL_QUADS);
    glColor3f(0.49, 0.212, 0.267);

    glVertex3f(4.4f, 20.0f, 0.0f);
    glVertex3f(10.6667f, 20.0f, 0.0f);
    glVertex3f(10.0667f, 22.5373f, 0.0f);
    glVertex3f(5.0f, 22.5373f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.412, 0.176, 0.224);

    glVertex3f(5.8667f, 21.4925f, 0.0f);
    glVertex3f(9.0667f, 21.4925f, 0.0f);
    glVertex3f(7.5333f, 23.806f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4, 0.675, 0.675);
    glVertex3f(6.2667f, 21.5672f, 0.0f);
    glVertex3f(8.6f, 21.5672f, 0.0f);
    glVertex3f(7.5222f, 23.2836f, 0.0f);
    glEnd();


    //janala
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.875);

    glVertex3f(5.4f, 17.6866f, 0.0f);
    glVertex3f(7.2f, 17.6866f, 0.0f);
    glVertex3f(7.2f, 19.7015f, 0.0f);
    glVertex3f(5.4f, 19.7015f, 0.0f);
    glEnd();

    //janala
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.875);
    glVertex3f(7.8f, 17.6866f, 0.0f);
    glVertex3f(9.6f, 17.6866f, 0.0f);
    glVertex3f(9.6f, 19.7015f, 0.0f);
    glVertex3f(7.8f, 19.7015f, 0.0f);
    glEnd();

    //janala
    glBegin(GL_LINES);
    glColor3f(0.996, 1.0, 0.992);

    glVertex3f(6.4f, 17.6866f, 0.0f);
    glVertex3f(6.4f, 19.7015f, 0.0f);
    glEnd();

    //janala
    glBegin(GL_LINES);
    glColor3f(0.996, 1.0, 0.992);
    glVertex3f(5.4f, 18.6567f, 0.0f);
    glVertex3f(7.2f, 18.6567f, 0.0f);
    glEnd();


    //janala
    glBegin(GL_LINES);
    glColor3f(0.996, 1.0, 0.992);

    glVertex3f(7.8f, 18.5821f, 0.0f);
    glVertex3f(9.5333f, 18.5821f, 0.0f);
    glVertex3f(8.7333f, 19.7015f, 0.0f);
    glVertex3f(8.7333f, 17.6866f, 0.0f);
    glEnd();

    //janala
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.875);
    glVertex3f(8.0f, 13.2836f, 0.0f);
    glVertex3f(9.8667f, 13.2836f, 0.0f);
    glVertex3f(9.8667f, 15.4478f, 0.0f);
    glVertex3f(8.0f, 15.4478f, 0.0f);
    glEnd();

    //janala
    glBegin(GL_LINES);
    glColor3f(0.996, 1.0, 0.992);

    glVertex3f(8.0f, 14.2537f, 0.0f);
    glVertex3f(9.8667f, 14.2537f, 0.0f);
    glVertex3f(8.9333f, 13.3582f, 0.0f);
    glVertex3f(8.9333f, 15.4478f, 0.0f);
    glEnd();

    //1ST TRI SAD
    glBegin(GL_TRIANGLES);
    glColor3f(0.412, 0.176, 0.224);

    glVertex3f(2.4667f, 16.791f, 0.0f);
    glVertex3f(4.8667f, 16.791f, 0.0f);
    glVertex3f(3.6f, 18.5821f, 0.0f);
    glEnd();

    //1ST TRI SAD
    glBegin(GL_TRIANGLES);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(2.8f, 16.791f, 0.0f);
    glVertex3f(4.5333f, 16.791f, 0.0f);
    glVertex3f(3.6f, 18.2836f, 0.0f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.996, 1.0, 0.992);
    glVertex3f(3.7f, 16.791f, 0.0f);
    glVertex3f(3.7f, 18.2836f, 0.0f);
    glEnd();

    //3RD HOUSE
    glBegin(GL_QUADS);
    glColor3f(0.82, 0.698, 0.518);

    glVertex3f(28.6667f, 12.6119f, 0.0f);
    glVertex3f(35.8667f, 12.6119f, 0.0f);
    glVertex3f(35.8667f, 12.9851f, 0.0f);
    glVertex3f(28.6667f, 12.9851f, 0.0f);

    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.894, 0.788, 0.604);

    glVertex3f(35.8667, 12.9851f, 0.0f);
    glVertex3f(35.8667f, 16.194f, 0.0f);
    glVertex3f(32.9333f, 19.403f, 0.0f);
    glVertex3f(30.3333f, 16.1194f, 0.0f);
    glVertex3f(30.3333f, 12.9851f, 0.0f);
    glEnd();

    //JANALA
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.784, 0.859);

    glVertex3f(32.6667f, 13.5821f, 0.0f);
    glVertex3f(32.6667f, 15.2985f, 0.0f);
    glVertex3f(31.2667f, 15.2985f, 0.0f);
    glVertex3f(31.2667f, 13.5821f, 0.0f);
    glEnd();

    //JANALA
    glBegin(GL_LINES);
    glColor3f(0.996, 1.0, 0.992);
    glVertex3f(32.0667f, 13.7777f, 0.0f);
    glVertex3f(32.0667f, 15.2985f, 0.0f);
    glVertex3f(31.3333f, 14.403f, 0.0f);
    glVertex3f(32.8667f, 14.4776f, 0.0f);
    glEnd();

    //SAD
    glBegin(GL_QUADS);
    glColor3f(0.494, 0.216, 0.271);


    glVertex3f(35.8f, 16.2687f, 0.0f);
    glVertex3f(36.6667f, 16.7164f, 0.0f);
    glVertex3f(32.9333f, 20.7463f, 0.0f);
    glVertex3f(32.9333f, 19.2537f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.494, 0.216, 0.271);

    glVertex3f(32.9333f, 20.7463f, 0.0f);
    glVertex3f(30.0f, 17.5373f, 0.0f);
    glVertex3f(30.3333f, 16.1194f, 0.0f);
    glVertex3f(32.9333f, 19.2537f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.914, 0.745);

    glVertex3f(28.6667f, 12.9851f, 0.0f);
    glVertex3f(31.6f, 12.9851f, 0.0f);
    glVertex3f(31.6f, 15.2985f, 0.0f);
    glVertex3f(30.1333f, 16.7164f, 0.0f);
    glVertex3f(28.6667f, 15.2985f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.42, 0.184, 0.224);
    glVertex3f(31.6f, 15.2985f, 0.0f);

    glVertex3f(32.2667f, 16.1194f, 0.0f);
    glVertex3f(30.1333f, 18.0597f, 0.0f);
    glVertex3f(30.1333f, 16.7164f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(30.2f, 18.2836f, 0.0f);
    glVertex3f(28.1333f, 15.8209f, 0.0f);
    glVertex3f(28.6667f, 15.2985f, 0.0f);
    glVertex3f(30.1333f, 16.7164f, 0.0f);

    glEnd();

    //DORJA
    glBegin(GL_QUADS);
    glColor3f(0.612, 0.388, 0.212);

    glVertex3f(29.6f, 12.6119f, 0.0f);
    glVertex3f(30.7333f, 12.6119f, 0.0f);
    glVertex3f(30.7333f, 14.6269f, 0.0f);
    glVertex3f(29.6f, 14.6269f, 0.0f);
    glEnd();

    //JANALA
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.784, 0.859);

    glVertex3f(34.8667f, 13.5821f, 0.0f);
    glVertex3f(34.8667f, 15.3731f, 0.0f);
    glVertex3f(33.0667f, 15.3731f, 0.0f);
    glVertex3f(33.0667f, 13.5821f, 0.0f);
    glEnd();

    //JANALA
    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(33.2f, 14.4776f, 0.0f);
    glVertex3f(34.7333f, 14.4776f, 0.0f);
    glVertex3f(34.0f, 13.6567f, 0.0f);
    glVertex3f(34.0f, 15.3731f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.522, 0.78, 0.867);
    glVertex3f(33.5333f, 17.0149f, 0.0f);
    glVertex3f(32.8f, 18.4328f, 0.0f);
    glVertex3f(32.0667f, 17.0149f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(32.7777f, 17.0149f, 0.0f);
    glVertex3f(32.7777f, 18.4328f, 0.0f);

    glEnd();


//2nd house
    glBegin(GL_QUADS);
    glColor3f(0.976, 0.831, 0.373);

    glVertex3f(13.0f, 12.6119f, 0.0f);
    glVertex3f(23.7333f, 12.6119f, 0.0f);
    glVertex3f(23.7333f, 15.9701f, 0.0f);
    glVertex3f(13.0f, 15.9701f, 0.0f);
    glEnd();

    //FULLsad
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.271, 0.231);

    glVertex3f(12.4f, 15.9701f, 0.0f);
    glVertex3f(24.4f, 15.9701f, 0.0f);
    glVertex3f(23.8f, 18.4328f, 0.0f);
    glVertex3f(13.0f, 18.4328f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.914, 0.745);

    glVertex3f(17.0667f, 12.6119f, 0.0f);
    glVertex3f(19.8667f, 12.6119f, 0.0f);
    glVertex3f(19.8667f, 15.2239f, 0.0f);
    glVertex3f(18.4667f, 16.7164f, 0.0f);
    glVertex3f(17.0667f, 15.2239f, 0.0f);
    glEnd();

    //DOROJA
    glBegin(GL_QUADS);
    glColor3f(0.588, 0.365, 0.188);

    glVertex3f(17.9333f, 12.6119f, 0.0f);
    glVertex3f(18.9333f, 12.6119f, 0.0f);
    glVertex3f(18.9333f, 14.6269f, 0.0f);
    glVertex3f(17.9333f, 14.6269f, 0.0f);

    glEnd();

    //TRI-SAD
    glBegin(GL_QUADS);
    glColor3f(0.447, 0.243, 0.192);

    glVertex3f(19.8667f, 15.2239f, 0.0f);
    glVertex3f(20.4667f, 15.8955f, 0.0f);
    glVertex3f(18.4f, 18.0597f, 0.0f);
    glVertex3f(18.4667f, 16.7164f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.447, 0.243, 0.192);
    glVertex3f(18.4667f, 16.7164f, 0.0f);
    glVertex3f(18.4f, 18.0597f, 0.0f);
    glVertex3f(16.3333f, 15.8955f, 0.0f);
    glVertex3f(17.0667f, 15.2239f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(18.0f, 15.4478f, 0.0f);
    glVertex3f(18.8f, 15.4478f, 0.0f);
    glVertex3f(18.8f, 16.1194f, 0.0f);
    glVertex3f(18.0f, 16.1194f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.976, 0.831, 0.38);

    glVertex3f(16.3333f, 17.6119f, 0.0f);
    glVertex3f(20.5333f, 17.6119f, 0.0f);
    glVertex3f(20.5333f, 19.8507f, 0.0f);
    glVertex3f(18.4667f, 21.9403f, 0.0f);
    glVertex3f(16.3333f, 19.8507f, 0.0f);
    glEnd();

    //OPOERER-SAD
    glBegin(GL_QUADS);
    glColor3f(0.49, 0.212, 0.267);

    glVertex3f(20.5333f, 19.8507f, 0.0f);
    glVertex3f(21.0f, 20.4478f, 0.0f);
    glVertex3f(18.4667f, 23.2836f, 0.0f);
    glVertex3f(18.4667f, 21.9403f, 0.0f);
    glEnd();

    //OPOERER-SAD

    glBegin(GL_QUADS);
    glColor3f(0.49, 0.212, 0.267);

    glVertex3f(18.4667f, 23.2836f, 0.0f);
    glVertex3f(15.8f, 20.4478f, 0.0f);
    glVertex3f(16.3333f, 19.8507f, 0.0f);
    glVertex3f(18.4667f, 21.9403f, 0.0f);
    glEnd();

    //JANALA
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(16.8667f, 18.209f, 0.0f);
    glVertex3f(18.2667f, 18.209f, 0.0f);
    glVertex3f(18.2667f, 19.7015f, 0.0f);
    glVertex3f(16.8667f, 19.7015f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(16.8667f, 19.0299f, 0.0f);
    glVertex3f(18.2667f, 19.0229f, 0.0f);
    glVertex3f(17.6f, 18.209f, 0.0f);
    glVertex3f(17.5333f, 19.7761f, 0.0f);

    glEnd();



    //JANALA
    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(18.6667f, 18.2836f, 0.0f);
    glVertex3f(20.0667f, 18.2836f, 0.0f);
    glVertex3f(20.0667f, 19.7015f, 0.0f);
    glVertex3f(18.6667f, 19.7015f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(18.6667f, 19.0299f, 0.0f);
    glVertex3f(20.0667f, 19.0299f, 0.0f);
    glVertex3f(19.4f, 18.2836f, 0.0f);
    glVertex3f(19.4f, 19.7015f, 0.0f);
    glEnd();

    //LEFT
    glBegin(GL_TRIANGLES);
    glColor3f(0.529, 0.267, 0.231);

    glVertex3f(13.2f, 17.6119f, 0.0f);
    glVertex3f(16.1333f, 17.4627f, 0.0f);
    glVertex3f(14.7333f, 19.7761f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.98, 0.839, 0.369);

    glVertex3f(13.6f, 17.6119f, 0.0f);
    glVertex3f(15.7000f, 17.6119f, 0.0f);
    glVertex3f(14.7333f, 19.2537f, 0.0f);
    glEnd();

    //RIGHT
    glBegin(GL_TRIANGLES);
    glColor3f(0.529, 0.267, 0.231);
    glVertex3f(20.6667f, 17.4627f, 0.0f);
    glVertex3f(23.5333f, 17.4627f, 0.0f);
    glVertex3f(22.0667f, 19.7015f, 0.0f);
    glEnd();

    //RIGHT
    glBegin(GL_TRIANGLES);
    glColor3f(0.98, 0.839, 0.369);

    glVertex3f(21.0f, 17.6119f, 0.0f);
    glVertex3f(23.0f, 17.6119f, 0.0f);
    glVertex3f(22.1f, 19.1791f, 0.0f);

    glEnd();

    //SHAMNEER-2TA LEFT DORJAR MOTO JANALA

    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(13.7333f, 12.6119f, 0.0f);
    glVertex3f(14.7333f, 12.6119f, 0.0f);
    glVertex3f(14.7333f, 14.9254f, 0.0f);
    glVertex3f(13.7333f, 14.9254f, 0.0f);

    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(15.4f, 12.6119f, 0.0f);
    glVertex3f(16.4f, 12.6119f, 0.0f);
    glVertex3f(16.4f, 14.9254f, 0.0f);
    glVertex3f(15.4f, 14.9254f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);
    glVertex3f(14.2667f, 12.6119f, 0.0f);
    glVertex3f(14.2667f, 14.9254f, 0.0f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);
    glVertex3f(15.9333f, 12.6119f, 0.0f);
    glVertex3f(15.9333f, 14.9254f, 0.0f);

    glEnd();

    //SHAMNEER-2TA RIGHT DORJAR MOTO JANALA

    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(20.5333f, 12.6119f, 0.0f);
    glVertex3f(21.4667f, 12.6119f, 0.0f);
    glVertex3f(21.4667f, 14.9254f, 0.0f);
    glVertex3f(20.4667f, 14.9254f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.522, 0.78, 0.867);

    glVertex3f(22.2f, 12.6119f, 0.0f);
    glVertex3f(23.1333f, 12.6119f, 0.0f);
    glVertex3f(23.1333f, 14.9254f, 0.0f);
    glVertex3f(22.2f, 14.9254f, 0.0f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(21.0f, 12.6119f, 0.0f);
    glVertex3f(21.0f, 14.9254f, 0.0f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(22.6667f, 12.6119f, 0.0f);
    glVertex3f(22.6667f, 14.9254f, 0.0f);

    glEnd();

    //4th house
    glBegin(GL_QUADS);
    glColor3f(0.843, 0.753, 0.631);

    glVertex3f(42.1333f, 12.6119f, 0.0f);
    glVertex3f(47.5333f, 12.6119f, 0.0f);
    glVertex3f(47.5333f, 15.8955f, 0.0f);
    glVertex3f(42.1333f, 15.8955f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.706, 0.639, 0.537);

    glVertex3f(42.1333f, 15.8955f, 0.0f);
    glVertex3f(47.5333f, 15.8955f, 0.0f);
    glVertex3f(47.5333f, 17.0149f, 0.0f);
    glVertex3f(42.1333f, 17.0149f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);

    glVertex3f(42.0667f, 16.4925f, 0.0f);
    glVertex3f(47.6f, 16.4925f, 0.0f);
    glVertex3f(47.6f, 16.8657f, 0.0f);
    glVertex3f(42.0667f, 16.8657f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.882, 0.808, 0.682);

    glVertex3f(42.1333f, 17.0149f, 0.0f);
    glVertex3f(47.5333f, 17.0149f, 0.0f);
    glVertex3f(47.5333f, 19.4776f, 0.0f);
    glVertex3f(42.1333f, 19.4776f, 0.0f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.412, 0.176, 0.224);

    glVertex3f(41.2667f, 19.4776f, 0.0f);
    glVertex3f(48.3333f, 19.4776f, 0.0f);
    glVertex3f(47.8667f, 21.4925f, 0.0f);
    glVertex3f(41.7333f, 21.4925f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.412, 0.176, 0.224);

    glVertex3f(43.2f, 20.2239f, 0.0f);
    glVertex3f(46.6667f, 20.2239f, 0.0f);
    glVertex3f(45.0f, 22.6866f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.875, 0.812, 0.682);

    glVertex3f(43.6f, 20.2239f, 0.0f);
    glVertex3f(46.2667f, 20.2239f, 0.0f);
    glVertex3f(45.0f, 22.1642f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.929, 0.906, 0.812);

    glVertex3f(42.1333f, 12.6866f, 0.0f);
    glVertex3f(45.0667f, 12.6866f, 0.0f);
    glVertex3f(45.0667f, 14.6269f, 0.0f);
    glVertex3f(43.6f, 15.7463f, 0.0f);
    glVertex3f(42.1333f, 14.6269f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.424, 0.188, 0.227);

    glVertex3f(45.0667f, 14.6269f, 0.0f);
    glVertex3f(45.4667f, 15.2985f, 0.0f);
    glVertex3f(43.6f, 16.9403f, 0.0f);
    glVertex3f(43.6f, 15.7463f, 0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.424, 0.188, 0.227);

    glVertex3f(43.6f, 15.7463f, 0.0f);
    glVertex3f(43.6f, 16.9403f, 0.0f);
    glVertex3f(41.6f, 15.2985f, 0.0f);
    glVertex3f(42.1333f, 14.6269f, 0.0f);
    glEnd();

    //JANALA

    glBegin(GL_QUADS);
    glColor3f(0.518, 0.776, 0.863);

    glVertex3f(45.4f, 13.4328f, 0.0f);
    glVertex3f(47.2f, 13.5075f, 0.0f);
    glVertex3f(47.2f, 15.2239f, 0.0f);
    glVertex3f(45.4f, 15.2239f, 0.0f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(45.4f, 14.3284f, 0.0f);
    glVertex3f(47.2f, 14.3284f, 0.0f);
    glVertex3f(46.4f, 13.5075f, 0.0f);
    glVertex3f(46.4f, 15.1493f, 0.0f);


    glEnd();

    //LEFT JANALA
    glBegin(GL_QUADS);
    glColor3f(0.518, 0.776, 0.863);

    glVertex3f(42.8667f, 17.3881f, 0.0f);
    glVertex3f(44.3333f, 17.3881f, 0.0f);
    glVertex3f(44.3333f, 18.8806f, 0.0f);
    glVertex3f(42.8667f, 18.8806f, 0.0f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(42.8667f, 18.1343f, 0.0f);
    glVertex3f(44.3333f, 18.1343f, 0.0f);
    glVertex3f(43.6f, 17.3881f, 0.0f);
    glVertex3f(43.6f, 18.8806f, 0.0f);

    glEnd();

    //RIGHT JANALA
    glBegin(GL_QUADS);
    glColor3f(0.518, 0.776, 0.863);

    glVertex3f(45.5333f, 17.3881f, 0.0f);
    glVertex3f(47.1333f, 17.3881f, 0.0f);
    glVertex3f(47.1333f, 18.9552f, 0.0f);
    glVertex3f(45.5333f, 18.9552f, 0.0f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.996, 0.996, 0.988);

    glVertex3f(45.5333f, 18.209f, 0.0f);
    glVertex3f(47.1333f, 18.209f, 0.0f);
    glVertex3f(46.4f, 17.5373f, 0.0f);
    glVertex3f(46.3333f, 18.9552f, 0.0f);

    glEnd();

    //DOROJA

    glBegin(GL_QUADS);
    glColor3f(0.612, 0.388, 0.212);

    glVertex3f(43.2f, 12.6119f, 0.0f);
    glVertex3f(43.9333f, 12.6119f, 0.0f);
    glVertex3f(43.9333f, 14.1791f, 0.0f);
    glVertex3f(43.2f, 14.1791f, 0.0f);

    glEnd();





// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬A¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬




    car();   //1st car will be drawn and move automatically

    //car2(); // 2nd car drawn and move


    rocket(); // rocket draw and move



}


// 2nd boat Movement


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        if(xPos<-60)
        {
            xPos += 80.0f;
        }
        else
        {
            xPos -= 2;
        }
        break;
    case 'd':
        if(xPos>=50)
        {
            xPos -= 100.0f;
        }
        else
        {
            xPos += 2;
        }
        break;
    case 'v':
        isCityVisible = false;
        break;
    case 'c':
        isCityVisible = true;
        break;
    default:
        break;
    }


    if (key == 'R' || key == 'r') {
        isRainActive = true;
    } else if (key == 'S' || key == 's') {
        isRainActive = false;
    }



    glutPostRedisplay();
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("HOBBIT_FINAL");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f, 50.0f, 0.0f, 50.0f);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(Draw);
    glutKeyboardFunc(keyboard);


    init();
    glutIdleFunc(Draw);


    glutMainLoop();
    return 0;
}

