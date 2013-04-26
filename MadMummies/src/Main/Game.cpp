#include "Game.h"

#include "Engine/Util/Util.h"

#include "glfw.h"


Game::Game(void) : m_light(0), m_camera(0), m_cube(0)
{
}


Game::~Game(void)
{
}

void Game::Init()
{
	/*
	m_light = new Light;
	m_camera = new Camera;
	m_cube = new Cube;
	*/

	int    width, height;  // Window dimensions

	glfwGetWindowSize( &width, &height );
	height = height < 1 ? 1 : height;
	glViewport( 0, 0, width, height );

	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Set up projection matrix
	glMatrixMode( GL_PROJECTION );    
	glLoadIdentity();                 
	gluPerspective(                   
		65.0,                         
		(double)width/(double)height, 
		1.0,                          
		100.0                         
	);

	glMatrixMode( GL_MODELVIEW );     
	glLoadIdentity();                 
	gluLookAt(                        // Set camera position and orientation
		0.0, 0.0, 10.0,               // Camera position (x,y,z)
		0.0, 0.0, 0.0,                // View point (x,y,z)
		0.0, 1.0, 0.0                 // Up-vector (x,y,z)
	);
}

void Game::Update(double deltaT)
{
}

void Game::Render()
{
	/*
	m_camera->Activate();
	Util::CheckError();
	m_camera->Render();
	Util::CheckError();

	m_light->Activate();
	Util::CheckError();
	m_camera->Render();
	Util::CheckError();

	m_cube->Activate();
	Util::CheckError();
	m_cube->Render();
	Util::CheckError();

	*/


	double t = glfwGetTime();

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();                 

	gluLookAt
	(								  // Set camera position and orientation
		0.0, 0.0, 10.0,               // Camera position (x,y,z)
		0.0, 0.0, 0.0,                // View point (x,y,z)
		0.0, 1.0, 0.0                 // Up-vector (x,y,z)
	);

	glTranslatef( 0, 0, -5 );
	glRotatef( 60.0f * (float)t, 0.0f, 1.0f, 0.0f );

	glBegin( GL_TRIANGLES );          
		glColor3f( 1.0f, 0.0f, 0.0f );    
		glVertex3f( -5.0f, -4.0f, 0.0f ); 
		glColor3f( 0.0f, 1.0f, 0.0f );    
		glVertex3f(  5.0f, -4.0f, 0.0f ); 
		glColor3f( 0.0f, 0.0f, 1.0f );    
		glVertex3f(  0.0f,  4.5f, 0.0f ); 
	glEnd();                          

	glFlush();
}

void Game::Cleanup()
{
}