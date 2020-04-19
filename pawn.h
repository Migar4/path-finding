#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "vec2.h"
#include "grid.h"

class pawn {

private:
	std::vector<vec2<int>> path;
	grid* _grid;

	vec2<int>* position;

	unsigned char directions;
	bool old;

public:
	pawn(grid* g, int m, int n);
	pawn(grid* g, vec2<int> v);

	virtual ~pawn();

	char next_step();

	std::vector<vec2<int>>& get_path();

	void set_path(std::vector<vec2<int>>& _path);

	void set_old(bool value);
	bool get_old();

	vec2<int> get_pos();

};

#endif