#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <thread>

#include "Drawing.h"

using namespace sf;
using namespace std;

void BubbleSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height);