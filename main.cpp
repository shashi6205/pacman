//main function
#include <windows.h>
#include <glut.h>
#include <math.h>
#include <stdio.h>
#include "Camera.h"
#include "Board.h"
#include "Pac.h"
#include "Ghost.h"

#define M_PI 3.14159265358979323846264338327950288419716939937510
//delays in game
int start_timer;

//void *currentfont;
int flag=0;
int score=0;
char tmp_str[40];//used for sprintf

void init(void);

//number of ghosts on the board
int num_ghosts = 4;

//window info
float ratio;
int h,w;

//camera object
Camera *camera;

//viewing positions
int view;
//stops key repeats
int v_timer;

//playing board
Board *board;

//mr. pacman
Pac *pacman;

//ghosts
Ghost *ghost[4];


bool gameover = false;	// used to tell if the game has ended

//functions for printing
void renderBitmapString(float x, float y, void *font, char *string)
{
  char *str;
  glRasterPos2f(x,y);

  for (str=string; *str != '\0'; str++)
  {
    glutBitmapCharacter(font, *str);
  }
}


void Write(char *string)
{
   	 while(*string)
               glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}

void print(char *string)
{
               while(*string)
        	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}
//end of function 
void fo(char *strr)
{
	char *c;
	for(c=strr;*c!='\0';c++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,*c);
}

void setOrthographicProjection() 
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_MODELVIEW);
}
void resetPerspectiveProjection() 
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void screen1()
{
	char a1[]="PACMAN GAME";
    char a2[]="Department of Computer Science and Engineering";
	char a3[]="RAJENDRA PRASAD";
	char a4[]="Project by";
	char a5[]="SHASHI KUMAR";
	char a6[]="(1RE13CS146)";
	char a7[]="Under the Guidance of";
	char a8[]="Mr.NAVEEN CHANDRA GOWDA";
	char a9[]="Asst. Professor";
	char a10[]="REVA ITM,Yelahanka,Bangalore";
	char a11[]="Press ENTER to continue";
	char a12[]="Mrs.SHOBHA BIRADAR";
	char a13[]="COMPUTER GRAPHICS MINI-PROJECT";
	char a14[]="(1RE14CS420)";
	int i;		
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,0,800,10);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,35,800,45);
	glColor3f(250.0/256.0,200.0/255.0,1.0);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,0,7,700);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(25,0,32,700);
	glColor3f(0.2,0.8,0.2);
	glRectf(10,15,22,30);
	//glRectf(10,517,22,532);
	//glRectf(10,544,22,559);
	glRectf(10,571,22,586);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(768,0,775,700);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(792,0,810,700);
	glColor3f(250.0/256.0,200.0/255.0,1.0);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,590,800,710);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,563,800,570);
	glColor3f(0.2,0.8,0.2);
	glRectf(779,15,789,33);
	//glRectf(779,50,789,65);
	//glRectf(779,75,789,90);
	glRectf(779,571,789,586);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(350.0,470.0);
	for(i=0;i<sizeof(a1);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  ,a1[i]);


	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(355.0,420.0);
	for(i=0;i<sizeof(a4);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a4[i]);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(100.0,350.0);
	for(i=0;i<sizeof(a5);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a5[i]);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(100.0,330.0);
	for(i=0;i<sizeof(a6);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a6[i]);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(330.0,280.0);
	for(i=0;i<sizeof(a7);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a7[i]);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(100.0,230.0);
	for(i=0;i<sizeof(a8);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a8[i]);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(100.0,210.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a9[i]);
	
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(250.0,500.0);
	for(i=0;i<sizeof(a13);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a13[i]);
    
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(560.0,230.0);
	for(i=0;i<sizeof(a12);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a12[i]);

	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(560.0,210.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a9[i]);
	
	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(300.0,80.0);
	for(i=0;i<sizeof(a11);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a11[i]);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(220.0,150.0);
	for(i=0;i<sizeof(a2);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a2[i]);

	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(270.0,120.0);
	for(i=0;i<sizeof(a10);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a10[i]);

		glColor3f(0.0,0.0,0.0);
	glRasterPos2f(560.0,350.0);
	for(i=0;i<sizeof(a3);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a3[i]);

		glColor3f(0.0,0.0,0.0);
	glRasterPos2f(560.0,330.0);
	for(i=0;i<sizeof(a14);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,a14[i]);


	glPopMatrix();
	resetPerspectiveProjection();
	
	glutSwapBuffers();
	glFlush();
}

// draw the scene
void RenderScene()
{
	glClearColor(0.6,0.5,0.6,0.0);
	
	//camera update
	camera->Set_position(pacman->x, pacman->y, pacman->angle, view);

	//pipe transport
	if ((int)pacman->x == 27 && (int) pacman->y == 14 && pacman->angle == 0)
	{
		pacman->x = 0;
		pacman->animate = true;
	}else
	if ((int)(pacman->x + 0.9) == 0 && (int) pacman->y == 14 && pacman->angle == 180)
	{
		pacman->x = 27;
		pacman->animate = true;
	}


	//do animation/movement checks for pacman
	if (pacman->animate)
		pacman->Move();	
	if(!(board->IsOpen((int)(pacman->x + cos(M_PI/180*pacman->angle)),
			(int)(pacman->y + sin(M_PI/180*pacman->angle)))) &&
			pacman->x - (int)pacman->x < 0.1 && pacman->y - (int)pacman->y < 0.1)
		pacman->animate = false;


	//do pebble eating
	if (board->tp_array[(int)(pacman->y+0.5)][(int)(pacman->x+0.5)]	== 1)
	{
		board->tp_array[(int)(pacman->y+0.5)][(int)(pacman->x+0.5)]	= 0;
		board->pebbles_left--;
		score+=1;
		
	} else if(board->tp_array[(int)(pacman->y+0.5)][(int)(pacman->x+0.5)] == 3)
	{
		board->tp_array[(int)(pacman->y+0.5)][(int)(pacman->x+0.5)]	= 0;
		board->pebbles_left--;
		score+=5;
		for (int i = 0; i < 4; i++)
		{
			if (!ghost[i]->eaten)
				ghost[i]->Vulnerable();
		}
	}
	
	//board is cleared of pebbles
	if (board->pebbles_left == 0)
	{
		init();
		board->tp_restore();
	}



	board->Draw();
	if (!gameover)
		pacman->Draw();


	for (int a = 0; a < num_ghosts; a++)
	{

		//GHOST DRAWING/MOVING
		if (!gameover && start_timer == 0)
			ghost[a]->Update();

		if (!ghost[a]->in_jail &&
			ghost[a]->x - (int)ghost[a]->x < 0.1 && ghost[a]->y - (int)ghost[a]->y < 0.1)
		{

			bool open_move[4];
			//find available moves
			for (int ang = 0; ang < 4; ang++)
			{
				open_move[ang] = board->IsOpen((int)(ghost[a]->x + cos(M_PI/180*ang*90)),
					(int)(ghost[a]->y + sin(M_PI/180*ang*90)));
			}

            //TRACK PACMANS MOVEMENT
			if (!ghost[a]->eaten)
			{
				if(ghost[a]->x - (int)ghost[a]->x < 0.1 && ghost[a]->y - (int)ghost[a]->y < 0.1)
					ghost[a]->Chase(pacman->x, pacman->y, open_move);
			} else {
				if(ghost[a]->x - (int)ghost[a]->x < 0.1 && ghost[a]->y - (int)ghost[a]->y < 0.1)
					ghost[a]->Chase(13, 11, open_move);
			}
		}
		if (ghost[a]->in_jail && !(board->IsOpen((int)(ghost[a]->x + cos(M_PI/180*ghost[a]->angle)),
			(int)(ghost[a]->y + sin(M_PI/180*ghost[a]->angle)))) && ghost[a]->jail_timer > 0 &&
			ghost[a]->x - (int)ghost[a]->x < 0.1 && ghost[a]->y - (int)ghost[a]->y < 0.1)
		{
			ghost[a]->angle = (double)(((int)ghost[a]->angle + 180)%360);
		}

		if (!gameover && start_timer == 0)
			ghost[a]->Move();

		ghost[a]->Draw();
		
		if(!(ghost[a]->eaten))
		{
			bool collide = ghost[a]->Catch(pacman->x, pacman->y);
			if (collide && !(ghost[a]->edible))  //pacman is eaten
			{
				pacman->lives--;
				if (pacman->lives == 0)
					gameover = true;
				else
					init();
				//break loop
				a = 4;
			}else
			if (collide && ((ghost[a]->edible)))	//ate a ghost send it to jail
			{
				//reset info
				ghost[a]->edible = false;
				ghost[a]->eaten = true;
				ghost[a]->speed = 0.1;
			}
		}

	}
	//printing on display
	if(gameover==true)
	{
		glColor3f(0, 0, 0);
		glRasterPos2f(-15,18);
		sprintf(tmp_str, "LIVES=0");
		Write(tmp_str);
		glColor3f(0, 0, 0);
		glRasterPos2f(-4,-17);
		sprintf(tmp_str, "GAME OVER");
		print(tmp_str);
		glColor3f(0,0,0);
		renderBitmapString(-3,-18,GLUT_BITMAP_HELVETICA_18 ,"(Press ESC)");
	
	}

    

    glColor3f(0, 0, 0);
    glRasterPos2f(8, 18);
	sprintf(tmp_str, "SCORE: %d", score);
    Write(tmp_str);

	glColor3f(0, 0, 0);
    glRasterPos2f(-5, 18);
	sprintf(tmp_str, "PACMAN");
    print(tmp_str);

	glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
  switch(key)
 {
 case 13: glutDisplayFunc(RenderScene); //Ascii of 'enter' key is 13
			break;
 }
}


void TimerFunction(int value)
{
	//switch views from 3D to classic
	if(GetAsyncKeyState(0x56) && v_timer == 0)
	{
		view = (view+1)%2;
		v_timer = 10;
	}
	if (v_timer > 0)
		v_timer--;	

	//short pause when starting game
	if (start_timer > 0)
		start_timer--;

	//make sure game is in play
	if (!gameover && start_timer == 0)
	{
		// Get keyboard input
		//move right
		if(GetAsyncKeyState(VK_RIGHT)&& !GetAsyncKeyState(VK_LEFT)
			&& (int) pacman->y - pacman->y > -0.1 && pacman->angle != 0)
		{
			if (board->IsOpen(pacman->x+1, pacman->y))
			{
				pacman->animate = true;
				pacman->angle = 0;
			} 
		}else
		//move left
		if(GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) 
			&& (int) pacman->y - pacman->y > -0.1 && pacman->angle != 180)
		{
			if (board->IsOpen(pacman->x-1, pacman->y))
			{
				pacman->animate = true;
				pacman->angle = 180;
			}	
		}
		//move up
		if(GetAsyncKeyState(VK_UP)&& !GetAsyncKeyState(VK_DOWN) 
			&& (int) pacman->x - pacman->x > -0.1 && pacman->angle != 270)
		{
			if (board->IsOpen(pacman->x, pacman->y - 1))
			{
				pacman->animate = true;
				pacman->angle = 270;
			}
		}else
		//move down
		if(GetAsyncKeyState(VK_DOWN)&& !GetAsyncKeyState(VK_UP)
			&& (int) pacman->x - pacman->x > -0.1 && pacman->angle != 90)
		{
			if (board->IsOpen(pacman->x, pacman->y + 1))
			{
				pacman->animate = true;
				pacman->angle = 90;
			}
		}
	}

	//start a new game
	if (GetAsyncKeyState(VK_RETURN) && gameover)
	{
		pacman->lives = 3;
		init();
		board->tp_restore();
		gameover = false;
	}
	//quit
	if(GetAsyncKeyState(VK_ESCAPE))
	{
		exit(0);
	}

	glutPostRedisplay();

	glutTimerFunc(15, TimerFunction, 1);
}


void ChangeSize(GLsizei w, GLsizei h)
{
	if(h == 0)
		h = 1;	

	ratio = 1.0f * w / (h);
	glViewport(0,0,w,h);
	camera = new Camera(ratio);

}



//SET UP THE GAME
void init(void)
{

	start_timer = 140;
	pacman->Reinit();

	//ghost initial starting positions
	int start_x[4] = {11,12,15,16};
	float ghost_colors[4][3] = {{255,0,0},{120,240,120},{255,200,200},{255,125,0}};

	for (int i = 0; i < num_ghosts; i++)
	{
		ghost[i]->Reinit();
		ghost[i]->x = start_x[i];
		ghost[i]->y = 14;
		ghost[i]->eaten = false;
		ghost[i]->jail_timer = i*33 + 66;
		ghost[i]->max_speed = 0.1 - 0.01*(float)i;
		ghost[i]->speed = ghost[i]->max_speed;
		//colorize ghosts
		for (int j = 0; j < 3; j++)
			ghost[i]->color[j] = ghost_colors[i][j]/255.0f;
	}
}



int main(int argc, char * argv[])
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	
	//windowed mode
	glutInitWindowSize(600, 400);
	glutCreateWindow("Pacman 3D");

	//fullscreen mode
	/*glutGameModeString( "800x600:16@60" );
	glutEnterGameMode();*/

	//make mouse disappear
	glutSetCursor(GLUT_CURSOR_NONE);
	glutKeyboardFunc(myKeyboardFunc);
	glutDisplayFunc(screen1);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(15, TimerFunction, 1);
	
	//draw the level...
	glClearColor(.3, .3, .3, 1.0f);

	//set up board
	board = new Board();
	int start_x[4] = {11,12,15,16};
	pacman = new Pac(13.5,23);

	//put ghosts in starting positions
	for (int i = 0; i < num_ghosts; i++)
	{
		ghost[i] = new Ghost(start_x[i],14);
	}

	init();

	//initial view is the "3D" view
	view = 0;
	v_timer = 0;

	glutMainLoop();

	return 0;
}