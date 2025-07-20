#include"VAO.h"

VAO::VAO()
{
	// Generate a Vertex Array Object (VAO) and get its reference
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, GLvoid* offset)
{
	// Bind the VAO
	VBO.Bind();
	// Specify the layout of the vertex data in the VBO
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	// Enable the vertex attribute array for this layout
	glEnableVertexAttribArray(layout);
	// Unbind the VBO
	VBO.Unbind();
}

void VAO ::Bind()
{
	// Bind the VAO to the GL_ARRAY_BUFFER target
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	// Unbind the VAO by binding 0 to the GL_ARRAY_BUFFER target
	glBindVertexArray(0);
}

void VAO::Delete()
{
	// Delete the VAO
	glDeleteVertexArrays(1, &ID);
}