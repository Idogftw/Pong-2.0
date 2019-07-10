#pragma once

#ifndef _BALL_HPP
#define _BALL_HPP

#include <ctime>
#include <cstdlib>

#include "Rectangle.hpp"
#include "Player.hpp"

namespace Pong
{
	class Ball
	{
	public:
		Ball(glm::mat4 _projection);
		Ball(Rectangle _rect, glm::mat4 _projection);
		~Ball();

		void Create();
		void Update(Player* player, Player* player2, float delta, int _width, int _height);
		void Draw();

		bool CheckCollision(Rectangle rect1, Rectangle rect2);
	public:
		//@TODO: Change to ball with rectangle bounding box
		Rectangle getRect() { return m_rect; }
	private:
		Rectangle m_rect;
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ebo;
		Shader* m_shader;
		glm::mat4 m_projection;
		glm::vec2 velocity;
	};
}

#endif // !_BALL_HPP