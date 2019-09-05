#include "pch.h"
#include "Screen.h"


namespace GameScreen {

	Screen::Screen(unsigned int xBound, unsigned int yBound, char border[2]) {
		m_xBound = xBound;
		m_yBound = yBound;

		for (int i = 0; i < 2; i++) {
			m_border[i] = border[i];
		}

		m_screen.resize(m_yBound + 2);

		//make screen
		bool isUpperOrLower;

		for (size_t i = 0; i < (m_yBound + 2); i++) {
			std::string temp;
			temp.clear();

			if (i == 0 || i == m_yBound + 1) {
				isUpperOrLower = true;

			}
			else {
				isUpperOrLower = false;
			}

			for (unsigned int j = 0; j < (m_xBound * 2 - 1) + 2; j++) {
				if (isUpperOrLower) {
					temp.push_back(m_border[0]);
				}
				else {
					if (j == 0 || j == (m_xBound * 2 - 1) + 2 - 1) {
						temp.push_back(m_border[1]);
					}
					else {
						temp.push_back(' ');
					}
				}
			}
			m_screen[i] = (temp);
		}
	}

	void Screen::modifyPixel(unsigned int x, unsigned int y, char modifier) {
		if (x > 0 && x <= m_xBound && y > 0 && y <= m_yBound) { //if x and y are in the screen
			m_screen[y][x * 2 - 1] = modifier;
		}
	}

	void Screen::modifyPixel(unsigned int x, unsigned int y) {
		if (x > 0 && x < m_xBound && y > 0 && y < m_yBound) { //if x and y are in the screen
			m_screen[y][x * 2 - 1] = ' ';
		}
	}

	void Screen::clearScreen() {
		for (size_t i = 1; i < m_screen.size() - 1; i++) {
			for (size_t j = 1; j < m_screen[i].size() - 1; j++) {
				m_screen[i][j] = ' ';
			}
		}
	}

	void Screen::draw() {
		for (size_t i = 0; i < m_screen.size(); i++) {
			std::cout << m_screen[i] << std::endl;
		}
	}

	Screen::~Screen()
	{
	}
}