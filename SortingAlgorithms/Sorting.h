#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <thread>
#include <random>

#include "Drawing.h"

using namespace sf;
using namespace std;

void BubbleSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height);
void InsertionSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height);
void SelectionSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height);
void BogoSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height);
void MergeSort(vector<int>& numbers, vector<RectangleShape>& squares, int left, int right, Sound sound, RenderWindow& window, const int width, const int height);