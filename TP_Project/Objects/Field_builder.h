#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "Ships.h"
#include "Field.h"

#pragma once

std::map<int, char> type_of_ship = {{1, 's'}, {2, 'd'}, {3, 'c'}, {4, 'b'}};

//Это паттерн Строитель, который поэтапно будет собирать начальное игровое поле
namespace Builder {
    void build_ship(const Ship& ship, Field& cur_field);

    void build_bomb(int a, int b, std::vector<std::pair<int, int>>& bombs);
}
