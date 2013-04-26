#pragma once

#include "glfw.h"


class Node
{
public:
	Node(void);
	virtual ~Node(void);

	virtual void Activate() {};
	virtual void Render() {};
};

