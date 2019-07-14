#include "Window.hpp"

namespace Pong
{
	Window* Window::m_instance = nullptr;

	Window* Window::Instance()
	{
		if (m_instance == nullptr)
			m_instance = new Window(m_width, m_height);

		return m_instance;
	}

	Window::Window(int _width, int _height)
		: m_width(_width), m_height(_height)
	{
	}

	Window::~Window()
	{
	}

	void Window::Create()
	{
		if (!glfwInit())
		{
			Exit();
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		m_window = glfwCreateWindow(m_width, m_height, "Pong Clone - Idogftw", NULL, NULL);
		if (!m_window)
		{
			Exit();
			return;
		}

		glfwMakeContextCurrent(m_window);

		if (!gladLoadGL())
		{
			Exit();
			return;
		}

		glViewport(0, 0, m_width, m_height);

		setCallbacks();
	}

	void Window::setCallbacks()
	{
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			glfwSetWindowShouldClose(window, true);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			m_Input.keyCallback(key, scancode, action, mods);

			if (key == GLFW_KEY_ESCAPE)
				glfwSetWindowShouldClose(window, true);
		});
	}

	void Window::Clear(float r, float g, float b, float a)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(r, g, b, a);
	}

	void Window::Swap()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void Window::Exit()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}
}
