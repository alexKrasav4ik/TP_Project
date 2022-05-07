#include <iostream>
#include <vector>
#include <utility>
#include "../Objects/Ships.h"

int Ship::make_damage(int x, int y) {
	for (int i = 0; i < length; i++) {
            if (std::make_pair(x, y) == coordinates[i]) {
                is_alife[i] = false;
                bool life = false;
                for (bool cell : is_alife)
                    life |= cell;
                if (!life)
                    return 2;
                return 1;
            }
        }
        return 0;
}

int Ship::get_length() const {
    return length;
}

std::vector<std::pair<int, int> > Ship::get_coordinates() const {
    return coordinates;
}