#pragma once


// Uncomment to perform the tests

#define TEST_EX2

class Circle {

public:
	Circle() {}
	Circle(int radius) {
		this->radius = radius;		
	}

	int getRadius() const {
		return radius;
	}

private:
	int radius;
};

void selectionSort(Circle* array, unsigned int size) 
{
	Circle* temp = new Circle[size];
	int min_index;

	for (int i = 0; i < size; i++)
	{
		//find min
		min_index = 0;
		for (int j = 0; j < size; j++)
		{
			if (array[j].getRadius() < array[min_index].getRadius()) {
				min_index = j;
			}
		}

		temp[i] = array[min_index];
		array[min_index] = 99999;
	}
	for (size_t i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	delete[] temp;
}



