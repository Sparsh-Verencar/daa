#include <iostream>
using namespace std;

int qs(int arr[], int l, int h)
{
    int pivot = l;
    int i = l + 1;
    int j = h;

    while (i <= j)
    {
        while (arr[i] <= arr[pivot])
        {
            i++;
        }
        while (arr[j] > arr[pivot])
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[pivot]);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    int pIndex = qs(arr, l, h);
    quickSort(arr, l, pIndex - 1);
    quickSort(arr, pIndex + 1, h);
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
    quickSort(arr, 0, n - 1);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}