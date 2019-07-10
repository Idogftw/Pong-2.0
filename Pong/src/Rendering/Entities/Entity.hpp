#pragma once

#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <list>

#include <glad/glad.h>
#include <glm.hpp>

#include "IEntity.hpp"

namespace Pong
{
	class IEntity;

	typedef std::list<IEntity*> entityList;
	typedef entityList::iterator entityListIt;

	class Entity
	{
	public:
		Entity();
		~Entity();

		void Create();
		void Update(float _delta, int _width, int _height);
		void Draw();

		void AddEntity(IEntity* entity);
	
	private:
		entityList m_entity;
	};
}

#endif // !_ENTITY_HPP
