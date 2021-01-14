#include <iostream>
#include <cmath>

using namespace std;

void fillArray(int* arr, int size)
{
    if (size > 0)
        fillArray(arr, size - 1);
    cout << size << " > ";
    cin >> arr[size];
}

void printArray(int* arr, int size)
{
    if (size > 0)
        printArray(arr, size - 1);
    cout << arr[size] << " ";
}

int findAbsMinEl(int* arr, int size)
{
    if (size == 0)
        return arr[0];

    int min = findAbsMinEl(arr, size - 1);

    if (min > arr[size])
        return arr[size];
    return min;
}

int indexOfFirstNegativeElement(int* arr, int from, int to)
{
    if (from > to)
        return -1;

    if (arr[from] < 0)
        return from;

    return indexOfFirstNegativeElement(arr, from + 1, to);
}

int sumOfAbsValuesFromIndex(int* arr, int size, int index)
{
    if (size == -1)
        return 0;

    if (size < index)
        return 0;

    return arr[size] + sumOfAbsValuesFromIndex(arr, size - 1, index);
}

void removeElement(int* arr, int size, int index)
{
    if (index == size)
    {
        arr[size] = 0;
    }

    if (index < size)
    {
        arr[index] = arr[index + 1];
        removeElement(arr, size, index + 1);
    }
}

void removeElementsInRange(int* arr, int size, int pos, int a, int b)
{
    if (pos <= size)
    {
        if (arr[pos] >= a && arr[pos] <= b)
        {
            removeElement(arr, size, pos);
            removeElementsInRange(arr, size - 1, pos, a, b);
        }
        else
        {
            removeElementsInRange(arr, size, pos + 1, a, b);
        }
    }
}

int main()
{
    int n;

    cout << "N > ";
    cin >> n;

    int* arr = new int[n];

    fillArray(arr, n);

    cout << "Array: ";
    printArray(arr, n - 1);
    cout << endl;

    cout << "Min abs value: " << findAbsMinEl(arr, n - 1) << endl;

    int index = indexOfFirstNegativeElement(arr, 0, n - 1);

    cout << "Index of first negative element: " << index << endl;

    if (index != -1)
    {
        cout << "Sum of abs elements after first negative el: " << sumOfAbsValuesFromIndex(arr, n - 1, index + 1) << endl;
    }

    int a, b;

    cout << "Deleting range from > ";
    cin >> a;

    cout << "Deleting range to > ";
    cin >> b;

    removeElementsInRange(arr, n - 1, 0, a, b);

    cout << "Result array: ";
    printArray(arr, n - 1);
    cout << endl;

    return 0;
}
