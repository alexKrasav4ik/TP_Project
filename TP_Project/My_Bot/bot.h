#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <set>

std::mt19937 rnd(time(nullptr));

class Bot {
private:
	std::set<std::pair <int, int> > history;

public:
	std::vector<Ship> build_fleet() {
		std::vector<int> need = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
		std::vector<Ship> fleet;
		for (int length : need) {
			while (true) {
				int x1 = rnd() % 10;
				int y1 = rnd() % 10;
				int x2;
				int y2;
				if (rnd() % 2) {
					x2 = x1;
					if (rnd() % 2)
						y2 = y1 + (length - 1);
					else
						y2 = y1 - (length - 1);
				}
				else {
					y2 = y1;
					if (rnd() % 2)
						x2 = x1 + (length - 1);
					else
						x2 = x1 - (length - 1);
				}
				if (x2 < 0 || y2 < 0 || x2 >= 10 || y2 >= 10)
					continue;
				bool contact_with_other_ships = false;
				for (int x0 = 0; x0 < 10; x0++) {
					for (int y0 = 0; y0 < 10; y0++) {
						if (!(std::min(x1, x2) <= x0 && x0 <= std::max(x1, x2) && std::min(y1, y2) <= y0 && y0 <= std::max(y1, y2)))
							continue;
						for (Ship sh : fleet) {
							std::vector<std::pair<int, int> > forbidden_cells = sh.get_coordinates();
							for (std::pair <int, int> coord : forbidden_cells) {
								if (abs(coord.first - x0) + abs(coord.second - y0) <= 2 && std::max(abs(coord.first - x0), abs(coord.second - y0)) <= 1)
									contact_with_other_ships = true;
							}
						}
					}
				}
				if (!contact_with_other_ships) {
					fleet.push_back(Ship(x1, y1, x2, y2));
					break;
				}
			}
		}
		return fleet;
	}

	std::pair<int, int> fire(const Field& user_field) {
		while (true) {
			int x0 = rnd() % 10;
			int y0 = rnd() % 10;
			if (history.find(std::make_pair(x0, y0)) == history.end()) {
				history.insert(std::make_pair(x0, y0));
				return std::make_pair(x0, y0);
			}
		}
	}
};
