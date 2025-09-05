#include "getRandomInRange.h"
#include <random>

// ���������� ��������� � �������������
static std::mt19937 gen(std::random_device{}());

int getRandomInRange(int min, int max) {
    if (min > max)
    {
        std::uniform_int_distribution<> distrib(max, min);
        return distrib(gen);
    }
    else
    {
        std::uniform_int_distribution<> distrib(min, max);
        return distrib(gen);
    }
    
}

