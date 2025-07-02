#include <iostream>
using namespace std;

void linearSearch(int arr[], int key, int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            cout << key << " found at index " << i << endl;
        }
    }
    if (!found)
    {
        cout << key << " not found" << endl;
    }
}

void binarySearch(int arr[], int key, int n)
{
    int low = 0;
    int high = n - 1;
    int found = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            cout << key << " found at index " << mid << endl;
            found = 1;
            break;
        }
        else if(arr[mid] > key){
            high = mid-1;
            continue;
        }
        else{
            low = mid+1;
            continue;          
        }
    }
    if (!found)
    {
        cout << key << " not found" << endl;
    }
}
void binarySearchR(int arr[], int key, int l, int h)
{
    if(l>h)
    {
        cout << key << " not found" << endl;
        return;
    }
    else
    {
        int mid = (l + h) / 2;
        if (arr[mid] == key)
        {
            cout << key << " found at index " << mid << endl;
            return;
        }
        else if(arr[mid] > key){
            binarySearchR(arr, key, l, mid-1);
        }
        else{
            binarySearchR(arr, key, mid+1, h);
        }
    }
}

int main()
{
    int arr[] = {3, 4, 2, 6, 3, 56, 2, 89};
    int sortedarr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    linearSearch(arr, key, n);
    binarySearch(sortedarr, key, n);
    binarySearchR(sortedarr, key, 0, n - 1);
}