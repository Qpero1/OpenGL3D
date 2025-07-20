#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	// Generate a Vertex Buffer Object (VBO) and get its reference
	glGenBuffers(1, &ID);
	// Bind the VBO to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	// Copy the vertices data into the VBO
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::Bind()
{
	// Bind the VBO to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
	// Unbind the VBO by binding 0 to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	// Delete the VBO
	glDeleteBuffers(1, &ID);
}

// Note: The VBO class is used to manage a Vertex Buffer Object in OpenGL, which is used to store vertex data for rendering.