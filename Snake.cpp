#include "pch.h"
#include "Snake.h"

namespace GameOBJ {

	Snake::Snake(size_t xBound, size_t yBound)
	{
		size_t x = xBound / 2;//(rand() % xBound) + 1;
		size_t y = yBound / 2;//(rand() % yBound) + 1;
		std::vector<size_t> temp = { x,y };
		m_body.clear();
		m_body.push_back(temp);
		m_direction = 1;
		m_imded = false;
		m_xBound = xBound;
		m_yBound = yBound;
	}

	bool Snake::isDed() {
		return m_imded;
	}
	// 1 is right, 2 is left, 3 is up, 4 is down
	void Snake::addToBodyLength() {
		std::vector<size_t> temp(2);
		temp = m_body.back();
		switch (m_direction) {
		case 1:
			temp[0]++;
			break;
		case 2:
			temp[0]--;
			break;
		case 3:
			temp[1]++;
			break;
		case 4:
			temp[1]--;
			break;
		default:
			temp[0]++;
		}
		m_body.push_back(temp);
	}

	void Snake::setImDedFalse() {
		m_imded = false;
	}

	// 1 is right, 2 is left, 3 is up, 4 is down
	void Snake::setDirection(int in) {
		if (in == 1 || in == 2 || in == 3 || in == 4) {
			switch (in) {
			case 1:
				if (m_direction != 2)
					m_direction = in;
				break;
			case 2:
				if (m_direction != 1)
					m_direction = in;
				break;
			case 3:
				if (m_direction != 4)
					m_direction = in;
				break;
			case 4:
				if (m_direction != 3)
					m_direction = in;
				break;
			default:
				m_direction = 1;
			}
		}
		else
		{
			std::cout << "ERROR: direction does not mean anything" << std::endl;
		}
	}

	void Snake::moveSnake() {

		std::vector<std::vector<size_t>> temp = m_body;

		switch (m_direction) { //m_body[0] is always the head
		case 1:
			m_body[0][0]++;
			break;
		case 2:
			m_body[0][0]--;
			break;
		case 3:
			m_body[0][1]--;
			break;
		case 4:
			m_body[0][1]++;
			break;
		default:
			m_body[0][1]++;
		}
		//std::vector<size_t> temp2(2);

		for (size_t i = 1; i < m_body.size(); i++) {
			m_body[i] = temp[i - 1];
		}

		if (m_body[0][0] == 0 || m_body[0][0] == m_xBound + 1 || m_body[0][1] == 0 || m_body[0][1] == m_yBound + 1) {
			m_imded = true; //if it hits the side of the play area it dies.
		}

		for (size_t i = 0; i < m_body.size(); i++) {
			for (size_t j = 0; j < m_body.size(); j++) {
				if (i != j && m_body[i] == m_body[j]) {
					m_imded = true; //if the snake runs into its self it is ded.
				}

			}
		}
	}

	std::vector<size_t> Snake::getSnakeHead() {
		return m_body[0];
	}

	std::vector<std::vector<size_t>> Snake::getSnakeBody() {
		return m_body;
	}

	int Snake::getDirection() {
		return m_direction;
	}

	void Snake::reset() {
		size_t x = m_xBound / 2;
		size_t y = m_yBound / 2;
		m_body.clear();
		std::vector<size_t> temp = { x,y };
		m_body.push_back(temp);
	}


	Snake::~Snake()
	{
	}

}