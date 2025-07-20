#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>

class EBO
{
public:
	GLuint ID;
	// Constructor that generates a Element Buffer Object and links it to indices
	EBO(GLuint* indices, GLsizeiptr size);

	// Function to bind the EBO
	void Bind();
	// Function to unbind the EBO
	void Unbind();
	// Function to delete the EBO
	void Delete();
};

#endif