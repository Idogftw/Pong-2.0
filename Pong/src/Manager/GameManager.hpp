#pragma once

#ifndef _GAMEMANAGER_HPP
#define _GAMEMANAGER_HPP

#include <memory>

#include "Rendering/Window/Window.hpp"
#include "Rendering/Entities/Entity.hpp"
#include "Rendering/Entities/Player.hpp"
#include "Rendering/Entities/Ball.hpp"
#include "Utils/Utils.hpp"

namespace Pong
{
	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		void Init();
		void Run();
	public:
		int getWidth() { return m_width; }
		int getHeight() { return m_height; }
	private:
		Window* m_window = nullptr;
		Player* m_player1 = nullptr;
		Player* m_player2 = nullptr;
		Ball* m_ball = nullptr;
		std::shared_ptr<Entity> m_entity;
		glm::mat4 m_projection;
		int m_width, m_height;
		GLfloat m_delta, m_lastFrame, m_currentFrame;
	};
}

#endif // !_GAMEMANAGER_H_