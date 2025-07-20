#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"


// Vertices coordinates
GLfloat vertices[] =
{ // Vertex positions (x, y, z) and colors (r, g, b)
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Upper triangle
	5, 4, 1 // Lower right triangle
};


int main() {

	// Initialize GLFW
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// Set GLFW window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(800, 800, "FPS Game", nullptr, nullptr);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Make the window's context current
	glfwMakeContextCurrent(window);
	
	// Load OpenGL functions using glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	// Set viewport size
	glViewport(0, 0, 800, 800); // Set the viewport to the size of the window

	// Create a shader program
	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1; // Create a Vertex Array Object
	VAO1.Bind(); // Bind the VAO

	VBO VBO1(vertices, sizeof(vertices)); // Create a Vertex Buffer Object
	EBO EBO1(indices, sizeof(indices)); // Create an Element Buffer Object
	
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (GLvoid*)0); // Link the VBO to the VAO at layout 0
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float))); // Link the color data to the VAO at layout 1
	VAO1.Unbind(); // Unbind the VAO
	VBO1.Unbind(); // Unbind the VBO
	EBO1.Unbind(); // Bind the EBO

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale"); // Get the uniform location for the color

	// Main loop
	while (!glfwWindowShouldClose(window)) {
		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);
		// Clean the back buffer and assign the new colour to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Activate the shader program
		shaderProgram.Activate();
		glUniform1f(uniID, 0.5f); // Set the scale uniform variable to 0.5

		// Bind the VAO
		VAO1.Bind();
		// Draw the triangles using the EBO
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
		// Swap buffers
		glfwSwapBuffers(window);
		// Poll for and process events
		glfwPollEvents();
	}

	// Delete the shader program and buffers
	VAO1.Delete(); // Delete the VAO
	VBO1.Delete(); // Delete the VBO
	EBO1.Delete(); // Delete the EBO
	shaderProgram.Delete(); // Delete the shader program

	// Clean up and exit
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}