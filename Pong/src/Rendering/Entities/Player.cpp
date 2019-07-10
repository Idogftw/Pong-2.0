#include "Player.hpp"

namespace Pong
{
	Player::Player(glm::mat4 _projection, bool _ai)
		: m_rect(Rectangle(glm::vec2(0, 0), glm::vec2(15, 100), glm::vec3(1, 1, 1))), m_projection(_projection), m_ai(_ai)
	{
	}

	Player::Player(Rectangle _rect, glm::mat4 _projection, bool _ai)
		: m_rect(_rect), m_projection(_projection), m_ai(_ai)
	{
	}

	Player::~Player()
	{
	}

	void Player::Create()
	{
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

	void Player::Update(float _delta, int _width, int _height)
	{
			if (InputManager::Instance()->keyPressed(GLFW_KEY_W))
			{
				if (m_rect.getPos().y >= _height - m_rect.getSize().y)
					m_rect.setPos(glm::vec2(m_rect.getPos().x, _height - m_rect.getSize().y));

				m_rect.setPos(m_rect.getPos() + glm::vec2(0, 8));
			}

			if (InputManager::Instance()->keyPressed(GLFW_KEY_S))
			{
				if (m_rect.getPos().y <= 0)
					m_rect.setPos(glm::vec2(m_rect.getPos().x, 0));

				m_rect.setPos(m_rect.getPos() + glm::vec2(0, -8));
			}
	}

	void Player::Draw()
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
}