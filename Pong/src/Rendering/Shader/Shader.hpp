#pragma once

#ifndef _SHADER_HPP
#define _SHADER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ext.hpp>

#include <iostream>
#include <string>
#include <fstream>

namespace Pong
{
	class Shader {
	public:
		Shader(const char* vFile, const char* fFile)
		{
			//Load files and return the file in text
			std::string vSource = loadFile(vFile);
			std::string fSource = loadFile(fFile);
			//Convert the text from a string to const char
			const char* vCode = vSource.c_str();
			const char* fCode = fSource.c_str();

			if (vSource == "")
				std::cout << "no vert" << std::endl;
			else if (fSource == "")
				std::cout << "no frag" << std::endl;


			//Debugging to check if it prints the correct file contents
			//std::cout << vCode << std::endl << std::endl;
			//std::cout << fCode << std::endl << std::endl;

			//Create shader from both sources
			GLuint vProg = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vProg, 1, &vCode, NULL);
			glCompileShader(vProg);

			GLuint fProg = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fProg, 1, &fCode, NULL);
			glCompileShader(fProg);

			//Create the program and link, then delete shaders
			m_id = glCreateProgram();
			glAttachShader(m_id, vProg);
			glAttachShader(m_id, fProg);
			glLinkProgram(m_id);

			glDeleteShader(vProg);
			glDeleteShader(fProg);

		}

		std::string loadFile(const char* file)
		{
			std::ifstream sFile(file);
			std::string sString;

			if (sFile)
				sString.assign((std::istreambuf_iterator<char>(sFile)), std::istreambuf_iterator<char>());

			return sString;
		}

		void Use()
		{
			glUseProgram(m_id);
		}

		void setMatrix4(const GLchar *name, const glm::mat4 &matrix)
		{
			glUniformMatrix4fv(glGetUniformLocation(m_id, name), 1, GL_FALSE, glm::value_ptr(matrix));
		}
	private:
		GLuint m_id;

	};
}

#endif // !_SHADER_HPP
