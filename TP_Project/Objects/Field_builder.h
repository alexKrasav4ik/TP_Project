#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "Ships.h"
#include "Field.h"

std::map<int, char> type_of_ship = {{1, 's'}, {2, 'd'}, {3, 'c'}, {4, 'b'}};

//Это паттерн Строитель, который поэтапно будет собирать начальное игровое поле
namespace Builder {
    void build_ship(const Ship& ship, Field& cur_field) {
        char current_type = type_of_ship[ship.get_length()];
        std::vector<std::pair<int, int> > coordinates_of_current_ship = ship.get_coordinates();
        for (std::pair<int, int> cell : coordinates_of_current_ship) {
            cur_field.field[cell.first][cell.second] = current_type;
        }
    }

    /*
    Здесь будет построение бомб и выставление шпиона - это стадия игры до начала
    void build_bombs(std::vector<std::pair<int, int> > bombs) {
    }
    
    void build_spy(std::pair<int, int> spy) {
    }
    */
}
