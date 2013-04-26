/*
 * Copyright 2013
 * Barbara Schwankl
 * Martin Scheuchenegger
 */


#include "glfw.h"

#pragma comment ( lib, "opengl32.lib" )
#pragma comment ( lib, "glu32.lib" )
#pragma comment ( lib, "GLFW.lib" )


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <tchar.h>

#include "Game.h"
#include "Engine/Util/Util.h"


void OpenWindow(int width, int height)
{
	int i = 0;
	std::cout << "OpenWindow\n";

	// (1) init glfw
	if (!glfwInit())
	{
		std::cout << "Failed to init glfw" << std::endl;
		system("PAUSE");
		exit(-1);
	}


	// Open window
	if(!glfwOpenWindow(
		640, 480,          // Width and height of window
		8, 8, 8,           // Number of red, green, and blue bits for color buffer
		8,                 // Number of bits for alpha buffer
		24,                // Number of bits for depth buffer (Z-buffer)
		0,                 // Number of bits for stencil buffer
		GLFW_WINDOW        // We want a desktop window (could be GLFW_FULLSCREEN)
	))
	{
		glfwTerminate();
		std::cout << "Failed to open window" << std::endl;
		system("PAUSE");
		exit(-1);
	} 

	/*
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize glew" << std::endl;
		system("PAUSE");
		exit(-1);
	}
	*/

	// Set window title
	glfwSetWindowTitle("Mad Mummies");

	// Enable sticky keys
	glfwEnable( GLFW_STICKY_KEYS );

}

void MainLoop()
{
	double deltaT;
	double time = glfwGetTime();
	double lastTime = time;
 
	bool running = true;
	

	Game* game = new Game;
	game->Init();

	while (running)
	{
		double time = glfwGetTime();
		deltaT = time - lastTime;
		lastTime = time;
 
		running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
 
		game->Update(deltaT);
		game->Render();

		glfwSwapBuffers();
 
		Util::CheckError();
	}
 
	game->Cleanup();
	glfwTerminate();
}



int main(int argc, char **argv)
{
	OpenWindow(500, 500);
	MainLoop();
	return 0;
}

