#pragma once
#include <ctime>
#include <iostream>
#include <vector>

namespace Food {

	class Food
	{
	public:
		Food(size_t xBound, size_t yBound);
		std::vector<size_t> getPosition();
		void makeNewFoodPos();
		void reset();
		~Food();
	private:
		size_t m_x;
		size_t m_y;
		size_t m_xBound;
		size_t m_yBound;
	};
}
