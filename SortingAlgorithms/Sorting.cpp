#include "Sorting.h"

const int DELAY = 10;

bool isSorted(vector<int>& numbers)
{
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < numbers[i - 1])
        {
			return false;
		}
	}
	return true;
}

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

void InsertionSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height) 
{
    int n = numbers.size();
    for (int i = 1; i < n; i++) 
    {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key) 
        {
            numbers[j + 1] = numbers[j];
            swap(squares[j], squares[j + 1]);

            squares[j + 1].setFillColor(Color::Red);
            DrawSquares(squares, window, numbers, width, height);
            squares[j + 1].setFillColor(Color(225, 225, 225));

            sound.setPitch(1 + numbers[j] / 100.0);
            sound.play();

            this_thread::sleep_for(chrono::milliseconds(DELAY));

            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

void SelectionSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height) 
{
    int n = numbers.size();

    for (int i = 0; i < n - 1; i++) 
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (numbers[j] < numbers[min_idx]) 
            {
                min_idx = j;
            }
        }

        swap(numbers[min_idx], numbers[i]);
        swap(squares[min_idx], squares[i]);

        squares[i].setFillColor(Color::Red);
        DrawSquares(squares, window, numbers, width, height);
        squares[i].setFillColor(Color(225, 225, 225));

        sound.setPitch(1 + numbers[i] / 100.0);
        sound.play();

        this_thread::sleep_for(chrono::milliseconds(DELAY));
    }
}

void BogoSort(vector<int>& numbers, vector<RectangleShape> squares, Sound sound, RenderWindow& window, const int width, const int height) 
{
    std::random_device rd;
    std::mt19937 g(rd());

    while (!isSorted(numbers)) 
    {
        std::shuffle(numbers.begin(), numbers.end(), g);
        std::shuffle(squares.begin(), squares.end(), g);

        DrawSquares(squares, window, numbers, width, height);

        sound.play(); 

        this_thread::sleep_for(chrono::milliseconds(DELAY * 10));
    }
}

void Merge(vector<int>& numbers, vector<RectangleShape>& squares, int left, int mid, int right, Sound sound, RenderWindow& window, const int width, const int height) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    vector<RectangleShape> L_squares(n1), R_squares(n2);

    for (int i = 0; i < n1; i++) 
    {
        L[i] = numbers[left + i];
        L_squares[i] = squares[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R[j] = numbers[mid + 1 + j];
        R_squares[j] = squares[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            numbers[k] = L[i];
            squares[k] = L_squares[i];
            i++;
        }
        else 
        {
            numbers[k] = R[j];
            squares[k] = R_squares[j];
            j++;
        }

        squares[k].setFillColor(Color::Red);
        DrawSquares(squares, window, numbers, width, height);
        squares[k].setFillColor(Color(225, 225, 225));

        sound.setPitch(1 + numbers[k] / 100.0);
        sound.play();

        this_thread::sleep_for(chrono::milliseconds(DELAY));

        k++;
    }

    while (i < n1) 
    {
        numbers[k] = L[i];
        squares[k] = L_squares[i];

        squares[k].setFillColor(Color::Red);
        DrawSquares(squares, window, numbers, width, height);
        squares[k].setFillColor(Color(225, 225, 225));

        sound.setPitch(1 + numbers[k] / 100.0);
        sound.play();

        this_thread::sleep_for(chrono::milliseconds(DELAY));

        i++;
        k++;
    }

    while (j < n2) 
    {
        numbers[k] = R[j];
        squares[k] = R_squares[j];

        squares[k].setFillColor(Color::Red);
        DrawSquares(squares, window, numbers, width, height);
        squares[k].setFillColor(Color(225, 225, 225));

        sound.setPitch(1 + numbers[k] / 100.0);
        sound.play();

        this_thread::sleep_for(chrono::milliseconds(DELAY));

        j++;
        k++;
    }
}

void MergeSort(vector<int>& numbers, vector<RectangleShape>& squares, int left, int right, Sound sound, RenderWindow& window, const int width, const int height) 
{
    if (left >= right) 
    {
        return;
    }

    int mid = left + (right - left) / 2;

    MergeSort(numbers, squares, left, mid, sound, window, width, height);
    MergeSort(numbers, squares, mid + 1, right, sound, window, width, height);
    Merge(numbers, squares, left, mid, right, sound, window, width, height);
}