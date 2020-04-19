#ifndef GRID_H
#define GRID_H

#include "vec2.h"

class grid {

private:
	char** matrix;
	vec2<int> size;

public:
	grid(int m, int n);
	virtual ~grid();

	void add_blocks(int num);

	void place_pawn(int m, int n);
	void place_pawn(vec2<int> pos);

	void place_x(int m, int n);
	void place_x(vec2<int> pos);

	char get_val(int m, int n);
	char get_val(vec2<int> pos);

	void show();
	vec2<int> get_size();
	void clear();
};

#endif