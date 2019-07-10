#include "Entity.hpp"

namespace Pong
{
	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::Create()
	{
		for (entityListIt it = m_entity.begin(); it != m_entity.end(); ++it)
		{
			(*it)->Create();
		}
	}

	void Entity::Update(float _delta, int _width, int _height)
	{
		for (entityListIt it = m_entity.begin(); it != m_entity.end(); ++it)
		{
			(*it)->Update(_delta, _width, _height);
		}
	}

	void Entity::Draw()
	{
		for (entityListIt it = m_entity.begin(); it != m_entity.end(); ++it)
		{
			(*it)->Draw();
		}
	}

	void Entity::AddEntity(IEntity* entity)
	{
		m_entity.push_back(entity);
	}
}