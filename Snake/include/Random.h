#pragma once
#include <random>

class Random
{
public:
	static int randomIntInRange(int low, int high)
	{
		std::random_device device;
		std::mt19937 eng(device());

		std::uniform_int_distribution<int> dist(low, high);

		return dist(eng);
	}
};