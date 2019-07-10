#pragma once

#ifndef _IENTITY_HPP
#define _IENTITY_HPP

#include "Rectangle.hpp"

namespace Pong
{
	class IEntity
	{
	public:
		virtual void Create() = 0;
		virtual void Update(float _delta, int _width, int _height) = 0;
		virtual void Draw() = 0;
	};
}

#endif // !_IENTITY_HPP
