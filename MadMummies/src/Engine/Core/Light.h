#pragma once

#include "Node.h"


class Light : public Node
{
public:
	Light(void);
	~Light(void);

	virtual void Activate();

private:
	GLfloat m_lightDiffuse[4];
	GLfloat m_lightPosition[4];
};