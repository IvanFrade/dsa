#include <iostream>
#include <chrono>
using namespace std;

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++)
        cout << array[i] << "; ";
}

void insertionSort(int* values, int length) {
    for (int i = 1; i < length; i++) {
        int key = values[i];
        int j = i - 1;

        while (j > 0 && values[j] > key) {
            values[j + 1] = values[j];
            j--;
        }

        values[j + 1] = key;
    }
}

int main() {
    int values[] = {1, 5, 2, 8, 112, 4, 5, 3, 55, 12};
    int length = 10;

    cout << "Unordered array: ";
    printArray(values, length);

    cout << endl << "Ordering..." << endl;

    auto start = chrono::high_resolution_clock::now();
    insertionSort(values, length);    
    auto stop = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Ordered array: ";
    printArray(values, length);
    cout << endl << "Ordered " << length << " elements in " << elapsed.count() << " ms.";
    return 0;
}