#pragma once
#include <vector>
#include <random>
#include <iostream>

class Maze
{
public:
	Maze(int x, int y)
		: width(x), height(y)
	{}

	void make();
	void print() const;

	int getWidth() const noexcept { return width; }
	int getHeight() const noexcept { return height; }
	std::pair<int, int> getStartPoint() const { return startPoint; }
	std::pair<int, int> getEndPoint() const { return endPoint; }
private:
	int width, height;
	std::pair<int, int> startPoint, endPoint;
	std::vector<std::vector<bool>> grid;
	
	void mazeMaker(int x, int y);;
};

