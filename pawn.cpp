#include "pawn.h"
#include "def.h"
#include <iostream>

pawn::pawn(grid* g, int m, int n)
{
	_grid = g;
	position = new vec2<int>(m, n);
	directions = 0x0;
	path = std::vector<vec2<int>>();
	_grid->place_pawn(*position);
	old = false;
}

pawn::pawn(grid* g, vec2<int> v)
{
	_grid = g;
	position = new vec2<int>();
	position->setX(v.getX());
	position->setY(v.getY());
	directions = 0x0;
	path = std::vector<vec2<int>>();
	_grid->place_pawn(*position);
	old = false;
}

pawn::~pawn()
{
}

char pawn::next_step()
{
	//std::cout << position->getX() << "   " << position->getY() << std::endl;
	if (_grid->get_val(*position + vec2<int>(0, -1)) == 'o' || _grid->get_val(*position + vec2<int>(0, -1)) == 'Z')
		directions |= TOP;

	if (_grid->get_val(*position + vec2<int>(1, -1)) == 'o' || _grid->get_val(*position + vec2<int>(1, -1)) == 'Z')
		directions |= TOP_R;

	if (_grid->get_val(*position + vec2<int>(-1, -1)) == 'o' || _grid->get_val(*position + vec2<int>(-1, -1)) == 'Z')
		directions |= TOP_L;

	if (_grid->get_val(*position + vec2<int>(-1, 0)) == 'o' || _grid->get_val(*position + vec2<int>(-1, 0)) == 'Z')
		directions |= LEFT;

	if (_grid->get_val(*position + vec2<int>(1, 0)) == 'o' || _grid->get_val(*position + vec2<int>(1, 0)) == 'Z')
		directions |= RIGHT;

	if (_grid->get_val(*position + vec2<int>(0, 1)) == 'o' || _grid->get_val(*position + vec2<int>(0, 1)) == 'Z')
		directions |= BOT;

	if (_grid->get_val(*position + vec2<int>(-1, 1)) == 'o' || _grid->get_val(*position + vec2<int>(-1, 1)) == 'Z')
		directions |= BOT_L;

	if (_grid->get_val(*position + vec2<int>(1, 1)) == 'o' || _grid->get_val(*position + vec2<int>(1, 1)) == 'Z')
		directions |= BOT_R;

	return directions;
}

std::vector<vec2<int>>& pawn::get_path()
{
	return path;
}

void pawn::set_path(std::vector<vec2<int>>& _path)
{
	for (auto p : _path) {
		path.push_back(p);
	}
	path.push_back(*position);
}

void pawn::set_old(bool value)
{
	old = value;
}

bool pawn::get_old()
{
	return old;
}

vec2<int> pawn::get_pos()
{
	return *position;
}
