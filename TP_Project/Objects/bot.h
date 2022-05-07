#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <set>
#include "Ships.h"
#include "Field.h"
#include "Field_builder.h"

#pragma once

std::mt19937 rnd(time(nullptr));

class Bot {
private:
	std::set<std::pair <int, int> > history;
	
public:
	std::vector<Ship> build_fleet();
	
	std::pair<int, int> fire(const Field& user_field);
};
