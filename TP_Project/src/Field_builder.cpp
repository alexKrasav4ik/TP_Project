#include "../Objects/Field_builder.h"

void Builder::build_ship(const Ship& ship, Field& cur_field) {
	char current_type = type_of_ship[ship.get_length()];
    std::vector<std::pair<int, int> > coordinates_of_current_ship = ship.get_coordinates();
    for (std::pair<int, int> cell : coordinates_of_current_ship) {
        cur_field.field[cell.first][cell.second] = current_type;
    }
}

void Builder::build_bomb(int a, int b, std::vector<std::pair<int, int>>& bombs) {
	bombs.push_back({a, b});
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			bool fl = false;
			for (auto el : bombs) {
				if (el.first == i && el.second == j)
					fl = true;
			}
			if (!fl)
				std::cout << ".";
			else
				std::cout << "b";
		}
		std::cout << "\n";
	}
}