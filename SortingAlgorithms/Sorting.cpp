#include "Sorting.h"

const int DELAY = 10;

void BubbleSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height)
{
	int n = numbers.size();
	bool swapped;

	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				swap(numbers[j], numbers[j + 1]);
				swap(squares[j], squares[j + 1]);

				squares[j + 1].setFillColor(Color::Red);
				DrawSquares(squares, window, numbers, width, height);
				squares[j + 1].setFillColor(Color(225, 225, 225));

				sound.setPitch(1 + numbers[j] / 100.0);
				sound.play();

				this_thread::sleep_for(chrono::milliseconds(DELAY));
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}