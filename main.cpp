#include <iostream>
#include "program.h"


int main() {
	int m = 0, n = 0, blocks = 0;

	std::cout << "number of rows >>  ";
	std::cin >> m;

	if (m <= 0) {
		do {
			std::cout << "number of rows should be more than 0 >>  ";
			std::cin >> m;
		} while (m <= 0);
	}

	std::cout << "number of columns >>  ";
	std::cin >> n;

	if (n <= 0) {
		do {
			std::cout << "number of columns should be more than 0 >>  ";
			std::cin >> n;
		} while (n <= 0);
	}

	std::cout << "number of blocks >>  ";
	std::cin >> blocks;

	if (blocks < 0) {
		do {
			std::cout << "number of blocks should be more than -1 >>  ";
			std::cin >> blocks;
		} while (blocks < 0);
	}

	program p(m, n, blocks);
	
	p.replicate_pawns();
	p.show_grid();

	return 0;
}
