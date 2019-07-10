#pragma once

#ifndef _BUTTON_HPP
#define _BUTTON_HPP

#include <glad/glad.h>
#include <glm.hpp>

#include "Rendering/Entities/Rectangle.hpp"

namespace Pong
{
	class Button
	{
	public:
		Button(Rectangle rect, glm::mat4 _projection);
		~Button();

		void Create();
		void Update(float _delta, int _width, int _height, int _mouseX, int _mouseY);
		void Draw();
	};
}

#endif // !_BUTTON_HPP
