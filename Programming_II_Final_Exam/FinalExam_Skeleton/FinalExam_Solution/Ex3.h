#ifndef EX3_H
#define EX3_H

// Uncomment to test
#define TEST_EX3

void circularShift(int* vec, unsigned int size, unsigned int shift)
{
	int end = size - 1;
		for (unsigned int i = 0; i < shift; i++) {
			int temp = vec[0];
			for (unsigned int j = 0; j < size; j++) {
				vec[j] = vec[j + 1];
				if (j = size - 1) {
					vec[end] = temp;
				}
			}
		}
}

#endif