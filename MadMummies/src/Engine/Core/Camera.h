#pragma once

#include "Node.h"


class Camera : public Node
{
public:
	Camera(void);
	~Camera(void);

	virtual void Activate();
	virtual void Render();

};

