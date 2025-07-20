#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(GLfloat* vertices, GLsizeiptr size);

	// Function to bind the VBO
	void Bind();
	// Function to unbind the VBO
	void Unbind();
	// Function to delete the VBO
	void Delete();
};

#endif