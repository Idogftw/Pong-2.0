#pragma once

#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <map>

#include "IEntity.hpp"
#include "Rectangle.hpp"
#include "Rendering/Shader/Shader.hpp"
#include "Manager/InputManager.hpp"

#include <ext.hpp>

namespace Pong
{
	enum PlayerNum
	{
		PLAYER1,
		PLAYER2
	};

	class Player : public IEntity
	{
	public:
		Player(glm::mat4 _projection, PlayerNum _playerType);
		Player(Rectangle _rect, glm::mat4 _projection, PlayerNum _playerType);
		~Player();

		void Create();
		void Update(float _delta, int _width, int _height);
		void Draw();
	public:
		Rectangle getRect() { return m_rect; }
		int getScore() { return m_score; }
		void setScore(int _score) { m_score = m_score + _score; }
	private:
		Rectangle m_rect;
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ebo;
		Shader* m_shader;
		glm::mat4 m_projection;
		PlayerNum m_playerType;
		int m_score;
	};
}

#endif // !_PLAYER_HPP
