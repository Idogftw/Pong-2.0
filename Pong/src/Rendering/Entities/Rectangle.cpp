#include "Rectangle.hpp"

namespace Pong
{
	Rectangle::Rectangle()
		: m_pos(glm::vec2(0)), m_size(glm::vec2(10, 10)), m_color(glm::vec3(1, 1, 1))
	{
	}

	Rectangle::Rectangle(glm::vec2 _pos, glm::vec2 _size, glm::vec3 _color)
		: m_pos(_pos), m_size(_size), m_color(_color)
	{
	}

	Rectangle::~Rectangle()
	{
	}
}