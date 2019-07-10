#pragma once

#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "Entity.hpp"

namespace Pong
{
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(glm::vec2 _pos, glm::vec2 _size, glm::vec3 _color);
		~Rectangle();
		
		void setPos(glm::vec2 _pos) {  m_pos = _pos; }

		glm::vec2 getPos() { return m_pos; }
		glm::vec2 getSize() { return m_size; }
		glm::vec3 getColor() { return m_color; }

	private:
		glm::vec2 m_pos;
		glm::vec2 m_size;
		glm::vec3 m_color;
	};
}

#endif // !_RECTANGLE_HPP


//Code for future portion of project, ignore

/*std::filebuf fb;

		std::string line, read;

		if (fb.open("yo.txt", std::ios::in))
		{
			std::istream is(&fb);
			while (!is.eof())
			{
				std::stringstream lStream;
				std::getline(is, line, '}');
				lStream << line;

				lStream << read;

				if (read.find("{") != std::string::npos)
					continue;
				else
					std::cout << line;

				if (read == "}")
					std::cout << "yo";
			}
		}*/