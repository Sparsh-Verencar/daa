#include <iostream>
#include <vector>
using namespace std;

/* void merge(int arr[], int l, int mid, int h)
{
    vector<int> temp;
    int left = l;
    int right = mid + 1;

    while (left <= mid && right <= h)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (right <= h)
    {
        temp.push_back(arr[right]);
        right++;
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i-l];
    }

}

void mergeSort(int arr[], int l, int h)
{
    int mid = 0;
    if (l >= h)
        return;
    mid = (l + h) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);
    merge(arr, l, mid, h);
} */

void merge(int arr[], int l, int mid, int h)
{
    int left = l;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= h)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (right <= h)
    {

        temp.push_back(arr[right]);
        right++;
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    for (int i = l; i <= h; i++)
    {
        arr[i]= temp[i-l];
    }
    
}

void mergeSort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    int mid = (l + h) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);
    merge(arr, l, mid, h);
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
    mergeSort(arr, 0, n - 1);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}