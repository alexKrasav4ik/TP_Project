#include <iostream>
#include <vector>
#include "Objects/Field_builder.h"
#include "My_Bot/bot.h"

Field user_field;
std::vector<Ship> user_fleet;

Bot krasav4ik;
Field bot_field;
std::vector<Ship> bot_fleet;

Ship cin_coords_of_ship() {
	char a, b, c, d;
	std::cin >> a >> b >> c >> d;
	return Ship(b - '0', a - 'A', d - '0', c - 'A');
}

void cout_cur_field() {
	for (int i = 0; i <= 9; i++) {
		for (char j = 'A'; j <= 'J'; j++) {
			if (user_field.field[i][j - 'A'] == '.')
				std::cout << j << i << " ";
			else
				std::cout << ".. ";
		}
		std::cout << "\n";
	}
}

namespace prebattle {
	void inserting_new_ship() {
		cout_cur_field();
		std::cout << "Введите координаты двух крайних клеток какого-нибудь корабля:\n";
		Ship ship(cin_coords_of_ship());
		user_fleet.push_back(ship);
		Builder::build_ship(ship, user_field);
		for (int i = 0; i < 50; i++)
			std::cout << "\n";
	}

	void prebattle_activities() {
		std::cout << "Привет! Это игра морской бой! Надеюсь, что правила именно этой версии Вам известны, поэтому сразу приступим к заполнению поля:\n";
		for (int step = 0; step < 3; step++)
			inserting_new_ship();
		std::cout << "Отлично! Теперь Ваше поле выглядит так:\n";
		std::cout << user_field;

		std::cout << "Сейчас бот krasav4ik построит свой флот! Одну секундочку...\n";
		bot_fleet = krasav4ik.build_fleet();
		for (Ship ship : bot_fleet)
			Builder::build_ship(ship, bot_field);
		std::cout << "Есть! Бот построил свой флот!\n";
	}
}

namespace battle {
	Field battle_field;

	void user_iteration() {
		while (true) {
			std::cout << "Ваш ход, выберите клетку для удара:\n\n" << battle_field << "\n\n";
			char a, b;
			std::cin >> a >> b;
			int row = a - 'A';
			int col = b - '0';
			int max_damage = 0;
			Ship killed_ship;
			for (size_t i = 0; i < bot_fleet.size(); i++) {
				int damage = bot_fleet[i].make_damage(row, col);
				max_damage = std::max(max_damage, damage);
				if (damage == 2)
					killed_ship = bot_fleet[i];
			}
			if (max_damage == 2) {
				for (std::vector<Ship>::iterator it = bot_fleet.begin(); it != bot_fleet.end(); ++it) {
					if (*it == killed_ship) {
						bot_fleet.erase(it);
						break;
					}
				}
				if (bot_fleet.empty())
					return;

				std::cout << "Так держать! Вы потопили вражеский корабль, продолжайте атаку!";
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (battle_field.field[i][j] == '+')
							battle_field.field[i][j] = 'X';
					}
				}
				battle_field.field[row][col] = 'X';
				for (int x0 = 0; x0 < 10; x0++) {
					for (int y0 = 0; y0 < 10; y0++) {
						if (battle_field.field[x0][y0] == 'X')
							continue;
						for (int dx = -1; dx <= 1; dx++) {
							for (int dy = -1; dy <= 1; dy++) {
								int nx = x0 + dx;
								int ny = y0 + dy;
								if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
									continue;
								if (battle_field.field[nx][ny] == 'X')
									battle_field.field[x0][y0] = '-';
							}
						}
					}
				}
			}
			else if (max_damage == 1) {
				std::cout << "Вражеский корабль ранен!\n";
				battle_field.field[row][col] = '+';
			}
			else {
				std::cout << "Упс, промах!\n";
				battle_field.field[row][col] = '-';
				return;
			}
		}
	}

	void bot_iteration() {
		while (true) {
			std::pair<int, int> attack = krasav4ik.fire(user_field);
			int row = attack.first;
			int col = attack.second;
			std::cout << "Враг атакует в клетку " << static_cast<char>('A' + row) << col << "\n";
			int max_damage = 0;
			Ship killed_ship;
			for (size_t i = 0; i < user_fleet.size(); i++) {
				int damage = user_fleet[i].make_damage(row, col);
				max_damage = std::max(max_damage, damage);
				if (damage == 2)
					killed_ship = user_fleet[i];
			}
			if (max_damage == 2) {
				for (std::vector<Ship>::iterator it = user_fleet.begin(); it != user_fleet.end(); ++it) {
					if (*it == killed_ship) {
						user_fleet.erase(it);
						break;
					}
				}
				if (user_fleet.empty())
					return;

				std::cout << "Наш корабль потоплен(!\n";
			}
			else if (max_damage == 1) {
				std::cout << "Бот ранил наш корабль!\n";
			}
			else {
				std::cout << "Он был очень близок, но промахнулся!\n";
				return;
			}
		}
	}	

	void battle_activities() {
		while (!bot_fleet.empty() && !user_fleet.empty()) {
			user_iteration();
			if (bot_fleet.empty()) {
				std::cout << "Ура! Весь вражеский флот уничтожен, это победа!\n";
				return;
			}
			bot_iteration();
		}
		std::cout << "О нет, все наши корабли уничтожены:( Ну ладно, повезет в другой раз\n";
	}
}

int main() {
	prebattle::prebattle_activities();
	std::cout << "Стадия подготовки к бою закончена, теперь пора приступать к самому бою!\n";
	battle::battle_activities();
	return 0;
}