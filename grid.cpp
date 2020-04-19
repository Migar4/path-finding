#include "grid.h"
#include <random>
#include <time.h>
#include <stdio.h>

grid::grid(int m, int n)
{
	srand(time(NULL));
	size = vec2<int>(m, n);

	matrix = new char*[size.getX()];
	for (int i = 0; i < size.getX(); i++)
		matrix[i] = new char[size.getY()];

	for (int i = 0; i < size.getX(); i++)
		for (int j = 0; j < size.getY(); j++)
			matrix[i][j] = 'o';

	matrix[0][0] = 'A';
	matrix[m - 1][n - 1] = 'Z';

}

grid::~grid()
{
	for (int i = 0; i < size.getY(); i++)
		delete[] matrix[i];
	delete[] matrix;
}

void grid::add_blocks(int num)
{
	if (num > size.getX()* size.getY())
		return;

	int n = 0, m = 0;

	for (int i = 0; i < num; i++) {
		do {
			m = rand() % size.getX();
			n = rand() % size.getY();

			if (matrix[m][n] == 'o') {
				matrix[m][n] = 'B';
				break;
			}
		} while (true);
	}
}

void grid::place_pawn(int m, int n)
{
	if (m < 0 || m > size.getX() - 1)
		return;

	if (n < 0 || n > size.getY() - 1)
		return;
	matrix[m][n] = 'p';
}

void grid::place_pawn(vec2<int> pos)
{
	if (pos.getX() < 0 || pos.getX() > size.getX() - 1)
		return;

	if (pos.getY() < 0 || pos.getY() > size.getY() - 1)
		return;

	matrix[pos.getX()][pos.getY()] = 'p';
}

void grid::place_x(int m, int n)
{
	if (m < 0 || m > size.getX() - 1)
		return;

	if (n < 0 || n > size.getY() - 1)
		return;
	matrix[m][n] = 'X';
}

void grid::place_x(vec2<int> pos)
{
	if (pos.getX() < 0 || pos.getX() > size.getX() - 1)
		return;

	if (pos.getY() < 0 || pos.getY() > size.getY() - 1)
		return;
	matrix[pos.getX()][pos.getY()] = 'X';
}

char grid::get_val(int m, int n)
{
	return matrix[m][n];
}

char grid::get_val(vec2<int> pos)
{
	if (pos.getX() < 0 || pos.getX() > size.getX() - 1)
		pos.setX(0);

	if (pos.getY() < 0 || pos.getY() > size.getY() - 1)
		pos.setY(0);

	return matrix[pos.getX()][pos.getY()];
}

void grid::show()
{
	for (int y = 0; y < size.getY(); y++) {
		for (int x = 0; x < size.getX(); x++)
			printf(" %c ", matrix[x][y]);
		printf("\n");
	}

}

vec2<int> grid::get_size()
{
	return size;
}

void grid::clear()
{
	for (int x = 0; x < size.getX(); x++)
		for (int y = 0; y < size.getY(); y++)
			if (matrix[x][y] == 'p')
				matrix[x][y] = 'o';
	matrix[0][0] = 'A';
	matrix[size.getX() - 1][size.getY() - 1] = 'Z';
}
