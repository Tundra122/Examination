void printArray(int* array, int size);
int indexOfTheMinimalElement(const int* array, int r, int c);
int sumOfElements(const int* array, int r, int c);
void transformArray(int* array, int r, int c);
#include <iostream>
int main() {
    const int ARRAY_SIZE = 10;
    // Create array with random values with the size of 100
    int array[ARRAY_SIZE];
    // Fill the array with random values (-100-100)
    for (int & i : array) {
        i = rand() % 201 - 100;
    }

    // Create a pointer to the array
    int *p = array;

    printArray(p, ARRAY_SIZE);
    std::cout << "The index of the minimal element is: " << indexOfTheMinimalElement(p, 10, 10) << std::endl;
    std::cout << "The sum of the elements is: " << sumOfElements(p, 10, 10) << std::endl;
    transformArray(p, 10, 10);
    printArray(p, ARRAY_SIZE);
}


void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int indexOfTheMinimalElement(const int *array, int r, int c) {
    int min = array[0];
    int index = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (array[i * c + j] < min) {
                min = array[i * c + j];
                index = i * c + j;
            }
        }
    }
    return index;
}

int sumOfElements(const int *array, int r, int c) {
    // Sum of elements between the first and the second negative elements
    int sum = 0;
    int firstNegativeIndex = 0;
    int secondNegativeIndex = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (array[i * c + j] < 0) {
                firstNegativeIndex = i * c + j;
                break;
            }
        }
    }
    for (int i = firstNegativeIndex + 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (array[i * c + j] < 0) {
                secondNegativeIndex = i * c + j;
                break;
            }
        }
    }
    for (int i = firstNegativeIndex + 1; i < secondNegativeIndex; i++) {
        for (int j = 0; j < c; j++) {
            sum += array[i * c + j];
        }
    }
    return sum;
}



void transformArray(int* array, int r, int c) {
    int* newArray = new int[r * c];
    int index = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (abs(array[i * c + j]) < 1) {
                newArray[index] = array[i * c + j];
                index++;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (abs(array[i * c + j]) >= 1) {
                newArray[index] = array[i * c + j];
                index++;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            array[i * c + j] = newArray[i * c + j];
        }
    }
    delete[] newArray;
}