#pragma once

#include "glfw.h"


#include <iostream>


class Util
{
public:
	static void CheckError()
	{
		GLenum err;
		if ((err = glGetError()) != GL_NO_ERROR) {
				std::cout << "GL ERROR DETECTED!!!" << " " << err << std::endl;
			}
	}

};