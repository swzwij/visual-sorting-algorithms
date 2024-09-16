#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

#include <iostream>
#include <thread>

#include "SoundSample.h"
#include "Drawing.h"
#include "Sorting.h"

using namespace sf;
using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 600;

int main()
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Sorting Algorithms");

	vector<int> numbers;

	for (int i = 1; i < 101; i++)
		numbers.push_back(i);

	random_shuffle(numbers.begin(), numbers.end());

	vector<RectangleShape> squares;

	for (int i = 0; i < numbers.size(); i++)
	{
		RectangleShape square(Vector2f(WIDTH / 100, numbers[i] * 5));
		square.setFillColor(Color(225, 225, 225));
		square.setPosition(i * WIDTH / 100, HEIGHT - numbers[i] * 5);
		squares.push_back(square);
	}

	SoundBuffer buffer = CreateBuffer();
	Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(10);

	bool canSort = false;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed) 
				window.close();

		if (Keyboard::isKeyPressed(Keyboard::Space) && !canSort)
			canSort = true;

		DrawSquares(squares, window, numbers, WIDTH, HEIGHT);

		if (canSort)
			BubbleSort(numbers, squares, sound, window, WIDTH, HEIGHT);
	}

	return 0;
}