#include <iostream>
using namespace std;

/* void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
           if(arr[j]<arr[j-1]){
               swap(arr[j], arr[j-1]);
           }
        }
    }
} */

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int smallest = arr[i];
        int smallIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                smallIndex = j;
            }
        }
        swap(arr[i], arr[smallIndex]);
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {2, 5, 3, 6, 4, 87, 5, 8, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    selectionSort(arr, n);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}