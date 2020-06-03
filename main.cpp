#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
int inctree = 0;
double a = 0,b=0,a2=-90;
int i,j,spaceCount=0;
int tortoiselegs[]= {-2,6,22,30};
int ssTortoisey =220;
int ssTortoisex =50;
int ssHarex = 800;
int ssHarey = 150;
int tCount;
void display();
void display2();
void display3();
void movement();
void delay(float);
void roadAndTrees();
void roadAndTrees2();
void hareScene();
void tortoiseraces();
void Tortoise();

void init() {
	glClearColor(0.1,0.8,0.1,1.0);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0,1000,0,500);
}

void display_string(int x, int y, char *string, int font)
{
    int len,i;
	glColor3f(255,255,0);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	if(font==3)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]);
	if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}

void NormalKey(GLubyte key, GLint x, GLint y)
{	int m;
    switch ( key )    {
     case 27 : printf("Escape pressed. exit.\n");
	               exit(0);
                   break;

	 case ' ': delay(0.3);
				spaceCount++;
				if(spaceCount==1){
				   tCount = 0;
				   display2();
			   }
			   if(spaceCount==2){
				   display();
			   }
			   if(spaceCount==3){
				   display3();
			   }

                   break;
	 case 'f':
	 case 'F': glutFullScreen();
		 spaceCount = 0; tCount = 0; break;
	 case 's':
	 case 'S':
		 if(spaceCount==1) {
		 tCount++;
		 switch(tCount) {
		 case 1: display_string(550,340,"I am the fastest animal in the whole wide world.",3); break;
		 case 2: display_string(60,330,"All Lies!!!",3);
				 display_string(60,310,"Stop Boasting, If you are not careful,",3);
				 display_string(60,290,"then you will meet your end.",3); break;
		 case 3: display_string(550,280,"I will prove to you all that I am the fastest",3);
				 display_string(550,260,"animal in the whole World.",3); break;
		 case 4: display_string(60,240,"OK! I'll race you then...",3); break;
		 case 5: display_string(550,210,"* Laughs Heavily *",3); break;
		 case 6: display_string(60,180,"You just Wait and See...",3); break;
		 case 7: display_string(420,100,"READY...STEADY...GO...",2);
		 case 8: display_string(350,60,"PRESS SPACE BAR TO PROCEED TO THE RACE",2); break;
		 }
		 glFlush(); }break;
	 case 'o':
	 case 'O':
				for(m=0;m<25;m++) {
					movement();
					delay(0.05);
				}
				hareScene();
				delay(1);
				delay(1);
				display_string(330,320,"He is somewhere far away so",3);
				display_string(330,300,"I can sleep for a while",3);
				glFlush();
				delay(1);
				delay(1);
				hareScene();
				delay(1);
				glColor3f(1.0,1.0,1.0);
				glPointSize(4);
				glBegin(GL_POINTS);
				glVertex2i(278,273);
				glEnd();
				glFlush();
				delay(1);
				display_string(310,310,"Z",2);
				display_string(300,290,"Z",2);
				glFlush();
				delay(1);
				display_string(260,180,"(Tortoise continues to run slowly and steadily.)",3);
				glFlush();
				delay(1);
				delay(1);
				for(m=0;m<28;m++) {
					tortoiseraces();
					delay(0.05);
					glutSwapBuffers();
				}

				delay(1);
				display_string(750,230,"I WIN!!!",2);
				glFlush();
				delay(1);
				display_string(300,200,"The Hare was over confident!",3);
				display_string(300,180,"This has lead to his failure!",3);
				glFlush();
				break;
	}
}
void tortoiseraces() {
	hareScene();
	glColor3f(1.0,1.0,1.0);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(278,273);
	glEnd();
	display_string(310,310,"Z",2);
	display_string(300,290,"Z",2);
	glFlush();
	glPushMatrix();
	glTranslated(a2,0,0);
	Tortoise();
	//Hare();
	glPopMatrix();
	a2+=30;
	glFlush();

}
void roadAndTrees2() {
	//Road
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(0,150);
	glVertex2i(1000,150);
	glVertex2i(1000,350);
	glVertex2i(0,350);
	glEnd();

	//Top Trees
	for(i=0;i<14;i++){
	glColor3f(1.0,0.4,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(30 + inctree,400);
	glVertex2i(40 + inctree,400);
	glVertex2i(40 + inctree,420);
	glVertex2i(30 + inctree,420);
	glEnd();
	inctree = inctree + 70;
	}
	inctree = 0;

	for(i=0;i<14;i++){
	glColor3f(0.0,0.4,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(20 + inctree,420);
	glVertex2f(55 + inctree,420);
	glVertex2f(35 + inctree,470);
	glEnd();
	inctree = inctree + 70;

	}
	inctree = 0;

	//Bottom Trees
	for(i=0;i<14;i++){
	glColor3f(1.0,0.4,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(30 + inctree,30);
	glVertex2i(40 + inctree,30);
	glVertex2i(40 + inctree,50);
	glVertex2i(30 + inctree,50);
	glEnd();
	inctree = inctree + 70;
	}
	inctree = 0;

	for(i=0;i<14;i++){
	glColor3f(0.0,0.4,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(20 + inctree,50);
	glVertex2f(55 + inctree,50);
	glVertex2f(35 + inctree,100);
	glEnd();
	inctree = inctree + 70;

	}
	inctree = 0;
}

void roadAndTrees() {
	//Road
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(0,150);
	glVertex2i(1000,150);
	glVertex2i(1000,350);
	glVertex2i(0,350);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(100,150);
	glVertex2i(100,350);
	glEnd();
	//Top Trees
	for(i=0;i<14;i++){
	glColor3f(1.0,0.4,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(30 + inctree,400);
	glVertex2i(40 + inctree,400);
	glVertex2i(40 + inctree,420);
	glVertex2i(30 + inctree,420);
	glEnd();
	inctree = inctree + 70;
	}
	inctree = 0;

	for(i=0;i<14;i++){
	glColor3f(0.0,0.4,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(20 + inctree,420);
	glVertex2f(55 + inctree,420);
	glVertex2f(35 + inctree,470);
	glEnd();
	inctree = inctree + 70;

	}
	inctree = 0;

	//Bottom Trees
	for(i=0;i<14;i++){
	glColor3f(1.0,0.4,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(30 + inctree,30);
	glVertex2i(40 + inctree,30);
	glVertex2i(40 + inctree,50);
	glVertex2i(30 + inctree,50);
	glEnd();
	inctree = inctree + 70;
	}
	inctree = 0;

	for(i=0;i<14;i++){
	glColor3f(0.0,0.4,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(20 + inctree,50);
	glVertex2f(55 + inctree,50);
	glVertex2f(35 + inctree,100);
	glEnd();
	inctree = inctree + 70;

	}
	inctree = 0;
}
void Tortoise() {

	float x,y;
	float t;
	//Tortoise
	glColor3f(0.0,0.5,0.0);
	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=50+22*cos(t);
		y=180+22*sin(t);
		glVertex2f(50,180);
		glVertex2f(x,y);
	}
	glEnd();

	glColor3f(1.0,0.5,0.0); //This covers the bottom half of the circle.
	glBegin(GL_POLYGON);
	glVertex2i(28,180);
	glVertex2i(72,180);
	glVertex2i(72,158);
	glVertex2i(28,158);
	glEnd();

	//Tortoise Face
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=82+7*cos(t);
		y=184+7*sin(t);
		glVertex2f(72,182);
		glVertex2f(x,y);
	}
	glEnd();

	//Tortoise Legs
	for(i=0;i<4;i++) {
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2i(32 + tortoiselegs[i],170);
	glVertex2i(38 + tortoiselegs[i],170);
	glVertex2i(37 + tortoiselegs[i],180);
	glVertex2i(33 + tortoiselegs[i],180);
	glEnd();
	}
}
void Tortoise2() {

	float x,y;
	float t;
	//Tortoise
	glColor3f(0.0,0.5,0.0);
	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=(50 + ssTortoisex)+22*cos(t);
		y=(180 + ssTortoisey)+22*sin(t);
		glVertex2f(50 + ssTortoisex,180 + ssTortoisey);
		glVertex2f(x,y);
	}
	glEnd();

	glColor3f(0,0,0.0); //This covers the bottom half of the circle.
	glBegin(GL_POLYGON);
	glVertex2i(28 + ssTortoisex,180 + ssTortoisey);
	glVertex2i(72 + ssTortoisex,180 + ssTortoisey);
	glVertex2i(72 + ssTortoisex,158 + ssTortoisey);
	glVertex2i(28 + ssTortoisex,158 + ssTortoisey);
	glEnd();

	//Tortoise Face
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=(82 + ssTortoisex)+7*cos(t);
		y=(184 + ssTortoisey)+7*sin(t);
		glVertex2f(72 + ssTortoisex,182 + ssTortoisey);
		glVertex2f(x,y);
	}
	glEnd();

	//Tortoise Legs
	for(i=0;i<4;i++) {
	glColor3f(0.5,0,1);
	glBegin(GL_POLYGON);
	glVertex2i(32 + tortoiselegs[i] + ssTortoisex,170 + ssTortoisey);
	glVertex2i(38 + tortoiselegs[i] + ssTortoisex,170 + ssTortoisey);
	glVertex2i(37 + tortoiselegs[i] + ssTortoisex,180 + ssTortoisey);
	glVertex2i(33 + tortoiselegs[i] + ssTortoisex,180 + ssTortoisey);
	glEnd();
	}
}
void Hare() {

	float x,y;
	float t;

	//Rabbit
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2i(50,210+40);
	glVertex2i(60,210+40);
	glVertex2i(70,220+40);
	glVertex2i(70,230+40);
	glVertex2i(60,240+40);
	glVertex2i(50,240+40);
	glVertex2i(40,230+40);
	glVertex2i(40,220+40);
	glEnd();

	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=78+9*cos(t);
		y=273+9*sin(t);
		glVertex2f(70,260);
		glVertex2f(x,y);
	}
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(78,273);
	glEnd();

	//Rabbit Ears
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=74+4*cos(t);
		y=295+4*sin(t);
		glVertex2f(70,270);
		glVertex2f(x,y);
	}
	glEnd();
}
void Hare2() {

	float x,y;
	float t;

	//Rabbit Body
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2i(50 + ssHarex,210+40 + ssHarey);
	glVertex2i(60 + ssHarex,210+40 + ssHarey);
	glVertex2i(70 + ssHarex,220+40 + ssHarey);
	glVertex2i(70 + ssHarex,230+40 + ssHarey);
	glVertex2i(60 + ssHarex,240+40 + ssHarey);
	glVertex2i(50 + ssHarex,240+40 + ssHarey);
	glVertex2i(40 + ssHarex,230+40 + ssHarey);
	glVertex2i(40 + ssHarex,220+40 + ssHarey);
	glEnd();

	//Rabbit Face
	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=(78 + ssHarex)+9*cos(t);
		y=(273 + ssHarey)+9*sin(t);
		glVertex2f(70 + ssHarex,260 + ssHarey);
		glVertex2f(x,y);
	}
	glEnd();

	//Rabbit Eye
	glColor3f(0.0,0.0,0.0);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(78 + ssHarex,273 + ssHarey);
	glEnd();

	//Rabbit Ears
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(t=0;t<=360;t++) {
		x=(74 + ssHarex)+4*cos(t);
		y=(295 + ssHarey)+4*sin(t);
		glVertex2f(70 + ssHarex,270 + ssHarey);
		glVertex2f(x,y);
	}
	glEnd();
}

void delay(float secs)
{
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}
void display() {
	//This is the Race Scene
	glClearColor(0.1,0.8,0.1,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//init();
	roadAndTrees();
	//glPushMatrix();
	//glTranslated(a,0,0);
	Tortoise();
	Hare();
	//glPopMatrix();
	//a+=10;
	glFlush();
}

void movement() {
	//This is the Race Scene
	glClearColor(0.1,0.8,0.1,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//init();
	roadAndTrees();
	glPushMatrix();
	glTranslated(a,0,0);
	//Tortoise();
	Hare();
	glPopMatrix();

	glPushMatrix();
	glTranslated(b,0,0);
	Tortoise();
	//Hare();
	glPopMatrix();
	b+=15;
	a+=50;
	glFlush();
}

void hareScene() {
	glClearColor(0.1,0.8,0.1,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//init();
	roadAndTrees2();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(700,150);
	glVertex2i(700,350);
	glEnd();
	glPushMatrix();
	glTranslated(200,0,0);
	//Tortoise();
	Hare();
	glPopMatrix();
	//a+=10;
	glFlush();
}


void display1() {
	//This is the First Screen
	glClearColor(1,0,0,0.8);
	glClear(GL_COLOR_BUFFER_BIT);
   // glLineWidth(3);
	glBegin(GL_LINE_LOOP);
        glVertex2f(200,480);
        glVertex2f(800,480);
        glVertex2f(800,370);
        glVertex2f(200,370);
    glEnd();
	display_string(300,440,"BMS INSTITUTE OF TECHNOLOGY AND MANAGEMENT",2);
	display_string(370,400,"DEPARTMENT OF COMPUTER SCIENCE",2);
	//display_string(300,360,"A mini project on Computer Graphics",1);
	display_string(350,310,"THE HARE AND TORTOISE STORY",1);
	display_string(40,100,"AUTHORS",2);
	display_string(40,80,"*******************",3);
	display_string(40,60,"NITHIN BHARADWAJ B P",3);
	display_string(40,40,"PRAJWAL KAUSHAL",3);
   	display_string(750,180,"LEGEND",2);
    display_string(750,160,"-----------------------",3);
	display_string(750,140,"ESCAPE -> EXIT",3);
	display_string(750,120,"SPACE  -> TO ENTER",3);
	display_string(750,100,"O -> RACE",3);
	display_string(750,80,"F -> FULLSCREEN",3);
	display_string(750,60,"S -> TO MAKE THEM CONVERSE",3); // Press S to make them converse in the second screen.

	display_string(470,250,"Let's GO !!!",2);
	glutSwapBuffers();
	glFlush();
}

void display2() {
	//This is the Second Screen (Conversation)
	glClearColor(0,0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	Hare2();
	Tortoise2();
	glFlush();
}

void display3() {
	//Last Screen (Moral of the Story)
	glClearColor(0,0,0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
        glVertex2f(220,400);
        glVertex2f(850,400);
        glVertex2f(850,150);
        glVertex2f(220,150);
    glEnd();
	display_string(400,350,"MORAL OF THE STORY",1);
	display_string(300,300,"------------------------------------------------------",3);
	display_string(320,250,"SLOW AND STEADY WINS THE RACE!!!",1);
	display_string(300,200,"------------------------------------------------------",3);
	glFlush();
}

int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,500);
	glutCreateWindow("HARE AND TORTOISE");
	glutPositionWindow(50,50);
	init();
	glutDisplayFunc(display1);
	glutKeyboardFunc(NormalKey);
	glutMainLoop();
	return 0;
}
