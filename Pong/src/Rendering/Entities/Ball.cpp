#include "Ball.hpp"

namespace Pong
{
	Ball::Ball(glm::mat4 _projection)
		: m_projection(_projection)
	{
		
	}

	Ball::Ball(Rectangle _rect, glm::mat4 _projection)
		: m_rect(_rect), m_projection(_projection)
	{
		
		
	}

	Ball::~Ball()
	{
	}

	void Ball::Create()
	{
		velocity = glm::vec2(-200, 60);

		m_shader = new Shader("assets/base_vs.glsl", "assets/base_fs.glsl");

		GLfloat vertices[] = {
			0.0f, 1.0f, m_rect.getColor().x, m_rect.getColor().y, m_rect.getColor().z,
			1.0f, 0.0f, m_rect.getColor().x, m_rect.getColor().y, m_rect.getColor().z,
			0.0f, 0.0f, m_rect.getColor().x, m_rect.getColor().y, m_rect.getColor().z,

			0.0f, 1.0f, m_rect.getColor().x, m_rect.getColor().y, m_rect.getColor().z,
			1.0f, 1.0f, m_rect.getColor().x, m_rect.getColor().y, m_rect.getColor().z,
			1.0f, 0.0f, m_rect.getColor().x, m_rect.getColor().y, m_rect.getColor().z
		};

		glGenVertexArrays(1, &m_vao);
		glGenBuffers(1, &m_vbo);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(m_vao);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
	}

	void Ball::Update(Player* player1, Player* player2, float _delta, int _width, int _height)
	{
		//Setting the velocity
		m_rect.setPos(m_rect.getPos() + velocity * _delta);

		//Player collision w/ ball
		if (CheckCollision(player1->getRect(), this->getRect()) || CheckCollision(player2->getRect(), this->getRect()))
		{
			velocity.x = -velocity.x;
		}
		//Left player gains point
		else if (this->getRect().getPos().x >= player2->getRect().getPos().x + player2->getRect().getSize().x)
		{
			player1->setScore(1);
			m_rect.setPos(glm::vec2(_width / 2, _height / 2) + (-velocity * _delta));
			std::cout << "P1: " << player1->getScore() << " | " << "P2: " << player2->getScore() << std::endl;
		}
		//Right player gains point
		else if (this->getRect().getPos().x <= player1->getRect().getPos().x - player1->getRect().getSize().x)
		{
			player2->setScore(1);
			m_rect.setPos(glm::vec2(_width / 2, _height / 2) + (-velocity * _delta));
			std::cout << "P1: " << player1->getScore() << " | " << "P2: " << player2->getScore() << std::endl;
		}

		//If the ball hits the top change its y velocity, same if it hits the bottom of the screen
		if (m_rect.getPos().y >= _height - m_rect.getSize().y)
		{
			velocity.y = -velocity.y;
		}
		else if (m_rect.getPos().y <= 0)
		{
			velocity.y = -velocity.y;
		}
	}

	void Ball::Draw()
	{
		m_shader->Use();

		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, glm::vec3(m_rect.getPos(), 0.0f));

		model = glm::scale(model, glm::vec3(m_rect.getSize(), 0.0f));

		m_shader->setMatrix4("model", model);
		m_shader->setMatrix4("projection", m_projection);

		glBindVertexArray(m_vao);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}

	bool Ball::CheckCollision(Rectangle player, Rectangle ball)
	{
		if (ball.getPos().x <= player.getPos().x + player.getSize().x &&
			ball.getPos().x + ball.getSize().x >= player.getPos().x &&
			ball.getPos().y <= player.getPos().y + player.getSize().y &&
			ball.getPos().y + ball.getSize().y >= player.getPos().y)
		{
			return true;
		}

		return false;
	}
}