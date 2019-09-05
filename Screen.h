#pragma once

#include <vector>
#include <iostream>
#include <string>

namespace GameScreen {

	class Screen
	{
	public:
		Screen(unsigned int xBound, unsigned int yBound, char border[2]);
		void modifyPixel(unsigned int x, unsigned int y, char modifier);
		void modifyPixel(unsigned int x, unsigned int y);
		void clearScreen();
		void draw();
		~Screen();
	private:
		unsigned int m_xBound;
		unsigned int m_yBound;
		std::vector<std::string> m_screen;
		char m_border[2];
		int m_addToX;
		int m_addToY;
	};
}

