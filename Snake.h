#pragma once
#include <iostream>
#include <vector>

namespace GameOBJ {

	class Snake
	{
	public:
		Snake(size_t xBound, size_t yBound);
		void setImDedFalse();
		bool isDed();
		void addToBodyLength();
		void setDirection(int in);
		void moveSnake();
		std::vector<size_t> getSnakeHead();
		std::vector<std::vector<size_t>> getSnakeBody();
		int getDirection();
		void reset();

		~Snake();
	private:
		std::vector<std::vector<size_t>> m_body; //head is always m_body[0]
		int m_direction; // 1 is right, 2 is left, 3 is up, 4 is down
		bool m_imded;
		size_t m_xBound;
		size_t m_yBound;
	};

}
/*
1) a head
2) body position
3) a direction
*/
