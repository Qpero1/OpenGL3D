#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include"VBO.h"

class VAO
{
public:
	GLuint ID;
	// Constructor that generates a Vertex Array Object and links it to VBO
	VAO();

	// Function to link a VBO to the VAO
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, GLvoid* offset);

	// Function to bind the VAO
	void Bind();
	// Function to unbind the VAO
	void Unbind();
	// Function to delete the VAO
	void Delete();
};

#endif