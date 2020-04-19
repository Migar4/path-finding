#include"vec2.h"
#include "program.h"
#include "grid.h"
#include "pawn.h"

int main() {
	program p(10, 10, 25);
	
	p.replicate_pawns();
	p.show_grid();

	return 0;
}