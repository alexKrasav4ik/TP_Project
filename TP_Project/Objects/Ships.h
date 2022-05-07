#include <iostream>
#include <vector>
#include <utility>

#pragma once

class Ship {
protected:
    size_t length;
    std::vector<std::pair<int, int> > coordinates;
    std::vector<bool> is_alife;
public:
    Ship() {}

    Ship(int x1, int y1, int x2, int y2) {
    	if (x1 == x2) {
            for (int i = std::min(y1, y2); i <= std::max(y1, y2); i++) {
                coordinates.push_back({x1, i});
            }
        }
        else if (y1 == y2) {
            for (int i = std::min(x1, x2); i <= std::max(x1, x2); i++) {
                coordinates.push_back({i, y1});
            }
        }
        else {
        	throw -1;
        }
        length = coordinates.size();
        if (length >= 5) throw -1;
        is_alife.resize(length, true);
    }

    bool operator==(const Ship& other) const {
        return coordinates == other.coordinates;
    }
	
    //проверяет, нанесет ли выстрел в точку (x, y) урон данному кораблю
    int make_damage(int x, int y);

    std::vector<std::pair<int, int> > get_coordinates() const;

    int get_length() const;
};

