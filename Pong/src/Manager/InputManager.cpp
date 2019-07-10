#include "InputManager.hpp"

namespace Pong
{
	InputManager* InputManager::m_instance = nullptr;

	bool InputManager::m_keys[256];
	bool InputManager::m_buttons[32];

	InputManager* InputManager::Instance()
	{
		if (m_instance == nullptr)
			m_instance = new InputManager();

		return m_instance;
	}

	InputManager::InputManager()
	{
		memset(m_keys, 0, sizeof(bool) * 256);
		memset(m_buttons, 0, sizeof(bool) * 32);
	}

	InputManager::~InputManager()
	{
	}

	void InputManager::keyCallback(int keycode, int scancode, int action, int mod)
	{
		m_keys[keycode] = action != GLFW_RELEASE;
	}

	bool InputManager::keyPressed(int keycode)
	{
		if (keycode < 0 || keycode > 1024)
			return false;

		return m_keys[keycode];
	}
	void InputManager::mouseCallback(int button, int action, int mods)
	{
		m_buttons[button] = action != GLFW_RELEASE;
	}
	bool InputManager::mouseClicked(int button)
	{
		if (button < 0 || button > 32)
			return false;

		return m_buttons[button];
	}
}