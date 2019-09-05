#include "pch.h"
#include "Food.h"

namespace Food {

	Food::Food(size_t xBound, size_t yBound)
	{
		m_xBound = xBound;
		m_yBound = yBound;
		m_x = (rand() % m_xBound) + 1;
		m_y = (rand() % m_yBound) + 1;
	}

	std::vector<size_t> Food::getPosition() {
		std::vector<size_t> temp = { m_x, m_y };
		return temp;
	}

	void Food::makeNewFoodPos() {
		m_x = (rand() % m_xBound) + 1; //1 - 40
		m_y = (rand() % m_yBound) + 1;
		if (m_x > m_xBound || m_x == 0 || m_y > m_yBound || m_y == 0) {
			std::cout << "Help";
		}
		
	}

	void Food::reset() {
		makeNewFoodPos();
	}

	Food::~Food()
	{
	}
}
