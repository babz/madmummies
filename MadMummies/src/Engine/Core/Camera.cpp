#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Activate()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(	40.0,	// field of view in degree
					1.0,	// aspect ratio
					1.0,	// Z near
					10.0f);	// Z far
	
	glViewport(0, 0, 1920, 1080);
	glClearColor(0.14f, 1.0f, 0.43f, 0.0f);
}

void Camera::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
}