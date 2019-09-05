// Nic Ballesteros. Console Snake Game
// Version 1 - Exploring how to use the console

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#include <conio.h>

#include "Food.h"
#include "Snake.h"
#include "Screen.h"

bool gameOver;
unsigned int x = 40; //a 20 X 20 play area // maybe multiply x value by two, the snake accelerates when it changes direction.
unsigned int y = 40;
//std::vector<std::string> playArea;
int score = 0;

char border[2] = { '#', '|' };

GameScreen::Screen playArea = GameScreen::Screen(x, y, border);

Food::Food foodObj = Food::Food(x, y); //food object
GameOBJ::Snake snake = GameOBJ::Snake(x, y); //snake


void setup() {
	gameOver = false;
	snake.setImDedFalse();

	score = 0;



	/*playArea.clear();
	playArea.resize(y + 2);

	bool isUpperOrLower = false;

	for (size_t i = 0; i < y + 2; i++) {
		std::string temp;
		temp.clear();

		if (i == 0 || i == y + 1) {
			isUpperOrLower = true;

		}
		else {
			isUpperOrLower = false;
		}

		for (size_t j = 0; j < x + 2; j++) {
			if (isUpperOrLower) {
				temp.push_back('#');
			}
			else {
				if (j == 0 || j == x + 1) {
					temp.push_back('#');
				}
				else {
					temp.push_back(' ');
				}
			}
		}
		playArea[i] = (temp);
	}*/

	foodObj.reset();
	std::vector<size_t> pos = foodObj.getPosition();
	playArea.modifyPixel(pos[0], pos[1], 'F');

	snake.reset();
	std::vector<size_t> posHead = snake.getSnakeHead();
	playArea.modifyPixel(posHead[0], posHead[1], 'O');
}

void draw() {
	/*for (size_t i = 0; i < playArea.size(); i++) {
		std::cout << playArea[i] << std::endl;
	}*/
	std::cout << "Score: " << score << std::endl;
}

//void deleteSnakeFromScreen() {
//	for (size_t i = 1; i < playArea.size() - 1; i++) {
//		for (size_t j = 0; j < playArea[i].size(); j++) {
//			if (playArea[i][j] == 'O' || playArea[i][j] == 'o') {
//				playArea[i][j] = ' ';
//			}
//		}
//	}
//}

int getDirection() {
	int dir = 0;
	//if (kbhit()) {
		switch (_getch()) {
		case 'w':
			dir = 3;
			break;
		case 'a':
			dir = 2;
			break;
		case 'd':
			dir = 1;
			break;
		case 's':
			dir = 4;
			break;
		default:
			dir = 1;
		}
	//}
	return dir;
}

void printSnakeAndFood(std::vector<std::vector<size_t>> body) {
	for (size_t i = 0; i < body.size(); i++) {
		if (i == 0) {
			playArea.modifyPixel(body[i][0], body[i][1], 'O');
		}
		else {
			playArea.modifyPixel(body[i][0], body[i][1], 'o');
		}
	}

	playArea.modifyPixel(foodObj.getPosition()[0], foodObj.getPosition()[1], 'F');

	if (body[0][0] == foodObj.getPosition()[0] && body[0][1] == foodObj.getPosition()[1]) {
		snake.addToBodyLength();
		score++;
		foodObj.makeNewFoodPos();
	}
}

void check() {
	//read the key and set direction
	//move snake
	//check if it has hit the food or one of the sides
	if (_kbhit()) {
		int dir = getDirection();
		snake.setDirection(dir);
	}
	snake.moveSnake();
	std::vector<std::vector<size_t>> body = snake.getSnakeBody();
	//deleteSnakeFromScreen();
	playArea.clearScreen();
	if (!snake.isDed()) {
		printSnakeAndFood(body);
	}
	else {
		gameOver = true;
	}
}

void runGame() {
	setup();

	while (!gameOver) {
		//run program
		check();
		playArea.draw();
		draw();
		//for (int i = 0; i < 10; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			//draw();
			//system("cls");
		//}
		system("cls");
		//gameOver = true;
	}

	std::string line;

	std::cout << "You died!!!" << std::endl;
	std::cout << "Final Score: " << score << std::endl;
	std::cout << "Press space and then enter to play again!" << std::endl;

	std::getline(std::cin, line);

	if (line == " ") {
		runGame();
	}
	else {
		system("cls");
		std::cout << "Thank you for playing!!" << std::endl;
	}
}
//make the snake move faster
int main()
{
	srand(time(0));

    std::cout << "Hello! Welcome to snake game\n"; 
	std::cout << "Press Space and then Enter to start!\n";

	std::string line;
	std::getline(std::cin, line);

	if (line == " ") {
		runGame();
	}
}


