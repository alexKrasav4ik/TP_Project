#include <iostream>
#include <vector>

//Это игровое поле
struct Field {
    std::vector<std::vector<char> > field = std::vector<std::vector<char> >(10, std::vector<char>(10, '.'));

    Field() {}

    friend std::ostream& operator<<(std::ostream& os, const Field& f) {
        os << "  ";
        for (int i = 0; i < 10; i++)
            os << i;
        os << "\n\n";
        for (int i = 0; i < 10; i++) {
            os << static_cast<char>('A' + i) << " ";
            for (int j = 0; j < 10; j++)
                os << f.field[i][j];
            os << "\n";
        }
        return os;
    }
};



