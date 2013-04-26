#pragma once

#include "Node.h"


class Cube : public Node
{
public:
	Cube(void);
	~Cube(void);

	virtual void Activate();
	virtual void Render();

private:
	GLfloat* m_normals;
	GLint* m_faces;
	GLfloat* m_vertices;	
};

