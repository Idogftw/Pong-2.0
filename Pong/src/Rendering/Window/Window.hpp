#pragma once

#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Manager/InputManager.hpp"

namespace Pong {

	static InputManager m_Input;

	class Window
	{
	public:
		Window(int _width, int _height);
		~Window();

		//Create Window
		void Create();
		//Set Callbacks for GLFW
		void setCallbacks();
		//Clear Screen/Color
		void Clear(float r = 0.f, float g = 0.f, float b = 0.f, float a = 1.f);
		//Poll GLFW Events and Swap GL Buffers
		void Swap();
		//Return if window is closed
		inline bool Closed() { return glfwWindowShouldClose(m_window); }
		//Terminate GLFW
		void Exit();
	public:
		GLFWwindow* getWindow() const { return m_window; };
		Window* Instance();
		int getWidth() { return m_width; }
		int getHeight() { return m_height; }
	private:
		static Window* m_instance;
		GLFWwindow* m_window;
		int m_width, m_height;
	};
}

#endif // !_WINDOW_H_
