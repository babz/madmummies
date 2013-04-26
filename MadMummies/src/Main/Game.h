#pragma once

#include "glfw.h"

#include "Engine/Core/Camera.h"
#include "Engine/Core/Light.h"
#include "Engine/Core/Cube.h"

class Game
{
public:
	Game(void);
	~Game(void);

	void Init();
	void Update(double deltaT);
	void Render();
	void Cleanup();

private:
	Light* m_light;
	Camera* m_camera;
	Cube* m_cube;
};

