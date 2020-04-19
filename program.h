#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include "pawn.h"
#include "grid.h"

class program {
	
private:
	std::vector<pawn*> pawns;
	grid* _grid;

public:
	program(int m, int n, int blocks);
	virtual ~program();

	void replicate_pawns();
	void show_grid();
};

#endif