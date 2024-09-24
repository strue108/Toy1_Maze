#include "Maze.h"

std::vector<std::pair<int, int>> setDirections() {
	// 상하좌우 벡터
	std::vector<std::pair<int, int>> directions{ { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

	// 난수 생성
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(directions.begin(), directions.end(), gen);

	// 무작위로 섞은 상하좌우를 담은 벡터
	return directions;
}


void Maze::make()
{
	std::vector<std::vector<bool>> tmp(getHeight(), std::vector<bool>(getWidth(), false));
	grid = tmp;
	startPoint = { 0,0 };
	grid[startPoint.first][startPoint.second] = true;
	mazeMaker(startPoint.first, startPoint.second);

	startPoint = getBlankSpace();
	std::cout << startPoint.first << " " << startPoint.second << std::endl;
	endPoint = getBlankSpace();
	std::cout << endPoint.first << " " << endPoint.second << std::endl;
}

void Maze::print() const
{
	for (auto row : grid) {
		for (auto element : row) {
			if (element)
				std::cout << "□";
			else
				std::cout << "■";
		}
		std::cout << std::endl;
	}
}

std::pair<int, int> Maze::getBlankSpace() const
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dist(0, getWidth() * getHeight() - 1);
	int x, y;

	while (1) {
		int rd = dist(gen);
		
		x = (rd) % getWidth();
		y = (rd) / getWidth();
		if (grid[y][x])
			break;
	}

	return { x,y };
}

//재귀적으로 구현한 dfs
void Maze::mazeMaker(int x, int y)
{
	for (auto& dir : setDirections()) {
		int nx = x + 2 * dir.first;
		int ny = y + 2 * dir.second;

		if (nx >= 0 && ny >= 0
			&& nx < getHeight() && ny < getWidth()
			&& grid[nx][ny] == false) {
			grid[(x + nx) / 2][(y + ny) / 2] = true;
			grid[nx][ny] = true;

			mazeMaker(nx, ny);
		}
	}
}