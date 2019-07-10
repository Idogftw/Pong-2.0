#pragma once

#ifndef _INPUTMANAGER_HPP
#define _INPUTMANAGER_HPP

#include "GLFW/glfw3.h"
#include <string.h>

namespace Pong
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void keyCallback(int key, int scancode, int action, int mods);
		bool keyPressed(int keycode);

		void mouseCallback(int button, int action, int mods);
		bool mouseClicked(int button);
	public:
		static InputManager* Instance();
	private:
		static bool m_keys[256];
		static bool m_buttons[32];
		static InputManager* m_instance;
	};
}

#endif // !_INPUTMANAGER_HPP
