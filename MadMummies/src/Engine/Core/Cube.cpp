#include "Cube.h"


Cube::Cube() : m_normals(0), m_faces(0), m_vertices(0)
{
	m_normals = new GLfloat[18]; // 6 * 3
	m_normals[0] = -1.0; m_normals[1] = 0.0; m_normals[2] = 0.0;
	m_normals[3] = 0.0; m_normals[4] = 1.0; m_normals[5] = 0.0;
	m_normals[6] = 1.0; m_normals[7] = 0.0; m_normals[8] = 0.0;
	m_normals[9] = 0.0; m_normals[10] = -1.0; m_normals[11] = 0.0;
	m_normals[12] = 0.0; m_normals[13] = 0.0; m_normals[14] = 1.0;
	m_normals[15] = 0.0; m_normals[16] = 0.0; m_normals[17] = -1.0;

	m_faces = new GLint[24]; // 6 * 4
	m_faces[0] = 0; m_faces[1] = 1; m_faces[2] = 2; m_faces[3] = 3;
	m_faces[4] = 3; m_faces[5] = 2; m_faces[6] = 6; m_faces[7] = 7;
	m_faces[8] = 7; m_faces[9] = 6; m_faces[10] = 5; m_faces[11] = 4;
	m_faces[12] = 4; m_faces[13] = 5; m_faces[14] = 1; m_faces[15] = 0;
	m_faces[16] = 5; m_faces[17] = 6; m_faces[18] = 2; m_faces[19] = 1;
	m_faces[20] = 7; m_faces[21] = 4; m_faces[22] = 0; m_faces[23] = 3;

	m_vertices = new GLfloat[24]; // 8 * 3
	m_vertices[0*3+0] = m_vertices[1*3+0] = m_vertices[2*3+0] = m_vertices[3*3+0] = -1;
	m_vertices[4*3+0] = m_vertices[5*3+0] = m_vertices[6*3+0] = m_vertices[7*3+0] = 1;
	m_vertices[0*3+1] = m_vertices[1*3+1] = m_vertices[4*3+1] = m_vertices[5*3+1] = -1;
	m_vertices[2*3+1] = m_vertices[3*3+1] = m_vertices[6*3+1] = m_vertices[7*3+1] = 1;
	m_vertices[0*3+2] = m_vertices[3*3+2] = m_vertices[4*3+2] = m_vertices[7*3+2] = 1;
	m_vertices[1*3+2] = m_vertices[2*3+2] = m_vertices[5*3+2] = m_vertices[6*3+2] = -1;
}

Cube::~Cube()
{
}



void Cube::Render()
{
  for (int i = 0; i < 6; i++) {
	glBegin(GL_QUADS);
		glNormal3fv(&m_normals[i*3+0]);
		glVertex3fv(&m_vertices[m_faces[i*4+0]*3+0]);
		glVertex3fv(&m_vertices[m_faces[i*4+1]*3+0]);
		glVertex3fv(&m_vertices[m_faces[i*4+2]*3+0]);
		glVertex3fv(&m_vertices[m_faces[i*4+3]*3+0]);
	glEnd();
  }
}


void Cube::Activate()
{
  glMatrixMode(GL_MODELVIEW);
  
  gluLookAt(0.0, 0.0, 5.0,  // eye is at (0,0,5)
	0.0, 0.0, 0.0,      // center is at (0,0,0) 
	0.0, 1.0, 0.);      // up is in positive Y direction 
	
 
  // Position
  glTranslatef(0.0, 0.0, -1.0);
  glRotatef(60, 1.0, 0.0, 0.0);
  glRotatef(-20, 0.0, 0.0, 1.0);
}