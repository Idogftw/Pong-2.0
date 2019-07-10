#include "GameManager.hpp"

namespace Pong
{
	GameManager::GameManager()
	{
		//Set width and height of window
		m_width = 800;
		m_height = 600;

		//Setup projection matrix for Players shader matrix
		m_projection = glm::ortho(0.0f, static_cast<float>(m_width), 0.0f, static_cast<float>(m_height), -1.0f, 1.0f);
		
		//Create pointers to objects
		m_entity = std::make_shared<Entity>();

		m_window = new Window(m_width, m_height);

		m_player1 = new Player(Rectangle(glm::vec2(10, (m_height / 2) - 25), glm::vec2(15, 100), glm::vec3(1, 1, 1)), m_projection, false);
		m_player2 = new Player(Rectangle(glm::vec2(m_width - 25, (m_height / 2) - 25), glm::vec2(15, 100), glm::vec3(1, 0, 1)), m_projection, true);

		m_ball = new Ball(Rectangle(glm::vec2(m_width / 2, (m_height / 2)), glm::vec2(25, 25), glm::vec3(1, 1, 1)), m_projection);

		//Add Players and Ball to entities array
		m_entity->AddEntity(m_player1);
		m_entity->AddEntity(m_player2);
	}

	GameManager::~GameManager()
	{
	}

	void GameManager::Init()
	{
		m_window->Create();

		m_entity->Create();

		m_ball->Create();
	}

	void GameManager::Run()
	{
		while (!m_window->Closed())
		{
			//Calculate the delta of the frams
			m_currentFrame = glfwGetTime();
			m_delta = m_currentFrame - m_lastFrame;
			m_lastFrame = m_currentFrame;

			//Clear the screen
			m_window->Clear();

			//Rendering
			//Draw the entities
			m_entity->Draw();
			m_ball->Draw();

			//Update the entities
			m_entity->Update(m_delta, m_width, m_height);
			m_ball->Update(m_player1, m_player2, m_delta, m_width, m_height);

			//Swap the buffers and poll events
			m_window->Swap();
		}
		//Exit window
		m_window->Exit();
	}
}