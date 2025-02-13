#define GLEW_DLL
#define GLFW_DLL

#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	if (!glfwInit()) {
		fprintf(stderr, "error\n");
		return 1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Rectangle", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	GLenum ret = glewInit();
	if (GLEW_OK != ret) {
		fprintf(stderr, "error\n", glewGetErrorString(ret));
		return 1;
	}
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.1f, 0.7f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.8f, 0.3f, 0.4f);
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}



