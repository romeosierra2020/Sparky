#include "window.h"
void windowResize(GLFWwindow* window, int width, int height); 
sparky::graphics::Window::Window(const char* title, int width, int height)
{
	m_Title = title;
	m_Width = width;
	m_Height = height;
	if (!init())
	{
		glfwTerminate();
	}
}


bool sparky::graphics::Window::init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialise GLFW!\n";
		return false;
	}

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_Window)
	{
		glfwTerminate();
		std::cout << "Failed to create GLFW window!\n";
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowSizeCallback(m_Window, windowResize);
	return true;
}

void sparky::graphics::Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void sparky::graphics::Window::update() 
{
	glfwPollEvents();
	
	glfwSwapBuffers(m_Window);

}

bool sparky::graphics::Window::closed() const
{
	return glfwWindowShouldClose(m_Window);
}

void windowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int sparky::graphics::Window::getWidth() const
{
	return m_Width;
}

int sparky::graphics::Window::getHeight() const
{
	return m_Height;
}

sparky::graphics::Window::~Window()
{
	glfwTerminate();
}