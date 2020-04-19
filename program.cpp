#include "program.h"
#include "def.h"
#include <iostream>

program::program(int m, int n, int blocks)
{
	_grid = new grid(m, n);
	_grid->add_blocks(blocks);

	pawn* p = new pawn(_grid, 0, 0);
	pawns.push_back(p);
}

program::~program()
{
	for (auto p : pawns)
		delete p;

	delete _grid;
}

void program::replicate_pawns()
{
	for (int i = 0; i < pawns.size(); i++) {
		unsigned char directions = pawns[i]->next_step();
		bool dir[8];
		bool quit = false;

		for (auto d : dir)
			d = false;
		_grid->show();
		std::cout << "\n\n" << pawns.size() << "\n" << std::endl;

		dir[0] = directions & TOP;
		dir[1] = directions & TOP_L;
		dir[2] = directions & TOP_R;
		dir[3] = directions & LEFT;
		dir[4] = directions & RIGHT;
		dir[5] = directions & BOT;
		dir[6] = directions & BOT_L;
		dir[7] = directions & BOT_R;

		if (!quit) {
			if (dir[0]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(0, -1)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(0, -1));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(0, -1)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}


			if (dir[1]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(-1, -1)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(-1, -1));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(-1, -1)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}


			if (dir[2]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(1, -1)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(1, -1));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(1, -1)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}


			if (dir[3]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(-1, 0)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(-1, 0));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(-1, 0)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}


			if (dir[4]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(1, 0)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(1, 0));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(1, 0)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}


			if (dir[5]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(0, 1)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(0, 1));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(0, 1)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}


			if (dir[6]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(-1, 1)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(-1, 1));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(-1, 1)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}


			if (dir[7]) {
				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(1, 1)) == 'o') {
					pawn* _p = new pawn(_grid, pawns[i]->get_pos() + vec2<int>(1, 1));
					_p->set_path(pawns[i]->get_path());
					pawns.push_back(_p);
				}

				if (_grid->get_val(pawns[i]->get_pos() + vec2<int>(1, 1)) == 'Z') {
					std::vector<vec2<int>> _path = pawns[i]->get_path();

					for (auto pos : _path) {
						_grid->place_x(pos);
					}
					_grid->clear();
					quit = true;
					break;
				}
			}
			pawns[i]->set_old(true);
		}
		
		try {
			for (int i = 0; i < pawns.size(); i++) {
				if ((pawns[i]) == nullptr)
					throw "nullptr";
				if ((pawns[i])->get_old()) {
					//pawns.erase(pawns.begin() + i);
				}
			}
		}
		catch(const char* except){
			std::cout << "pawns[i] is a nullptr" << std::endl;
		}
	}
}

void program::show_grid()
{
	_grid->show();
}
