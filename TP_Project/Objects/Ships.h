#include <iostream>
#include <vector>
#include <utility>

/*Паттерн, не помню как он называется, но в общем что есть абстрактный класс Ship, от которого наследуются все типы кораблей, 
но при этом мой код(во всех других библиотеках) не думает с каким типом корабля он работает, просто вызывает методы а дальше
оно уже само все определяется*/
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
        else {
            for (int i = std::min(x1, x2); i <= std::max(x1, x2); i++) {
                coordinates.push_back({i, y1});
            }
        }
        length = coordinates.size();
        is_alife.resize(length, true);
    }

    Ship(const Ship& other) : length(other.length), coordinates(other.coordinates), is_alife(other.is_alife) {}

    Ship& operator=(const Ship& other) {
        length = other.length;
        coordinates = other.coordinates;
        is_alife = other.is_alife;
        return *this;
    }

    bool operator==(const Ship& other) const {
        return coordinates == other.coordinates;
    }

    int make_damage(int x, int y) {
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

    std::vector<std::pair<int, int> > get_coordinates() const {
        return coordinates;
    }

    int get_length() const {
        return length;
    }

    void fire_after_death();
};

class Battleship : Ship {
public:
    Battleship(int x1, int y1, int x2, int y2) : Ship(x1, y1, x2, y2) {}
};

class Cruiser : Ship {
public:
    Cruiser(int x1, int y1, int x2, int y2) : Ship(x1, y1, x2, y2) {}
};

class Destroyer : Ship {
public:
    Destroyer(int x1, int y1, int x2, int y2) : Ship(x1, y1, x2, y2) {}
};

class Submarine : Ship {
public:
    Submarine(int x1, int y1, int x2, int y2) : Ship(x1, y1, x2, y2) {}
};
