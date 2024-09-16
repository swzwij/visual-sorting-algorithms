#include "Drawing.h"

void DrawSquares(vector<RectangleShape>& squares, RenderWindow& window, vector<int>& numbers, const int width, const int height)
{
	window.clear(Color::Black);

	for (int i = 0; i < squares.size(); i++)
	{
		squares[i].setSize(Vector2f(width / 100, numbers[i] * 5));
		squares[i].setPosition(i * width / 100, height - numbers[i] * 5);
		window.draw(squares[i]);
	}

	window.display();
}