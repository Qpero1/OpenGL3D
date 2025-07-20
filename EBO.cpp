#include "EBO.h"

#include <glad/glad.h>

EBO::EBO(GLuint* indices, GLsizeiptr size)
{
	// Generate a Element Buffer Object (EBO) and get its reference
	glGenBuffers(1, &ID);
	// Bind the EBO to the GL_ELEMENT_ARRAY_BUFFER target
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	// Copy the indices data into the EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
	// Bind the EBO to the GL_ELEMENT_ARRAY_BUFFER target
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	// Unbind the EBO by binding 0 to the GL_ELEMENT_ARRAY_BUFFER target
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	// Delete the EBO
	glDeleteBuffers(1, &ID);
}

// Note: The EBO class is used to manage an Element Buffer Object in OpenGL, which is used to store indices for indexed drawing.