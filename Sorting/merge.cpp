#include <iostream>

using namespace std;

void merge(int *, int *, int, int, int);
void mergesort(int *a, int *b, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = (low + high)/2;
        mergesort(a, b, low, pivot);
        mergesort(a, b, pivot + 1, high);
        merge(a, b, low, pivot, high);
    }
}
void merge(int *a, int *b, int low, int pivot, int high)
{
    int h, i, j, k;
    h = low;
    i = low;
    j = pivot + 1;

    while ((h <= pivot) && (j <= high)) // Traverse both halves of the array
    {
        if (a[h] <= a[j]) // if an element of left half is less than element of right half
        {
            b[i] = a[h]; // store element of left half in the temporary array
            h++; // shift the index of the array from which the element was copied to temporary 
        }
        else // otherwise store the element of the right half in the temporary array
        {
            b[i] = a[j];
            j++; // shift the index of the array from which the element was copied to temporary 
        }
        i++;
    }
    if (h > pivot) // If traversal of left half is done, 
                   // copy remaining elements from right half to temporary
    {
        for (k = j; k <= high; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else // otherwise copy remaining elements from left half to temporary
    {
        for (k = h; k <= pivot; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++) a[k] = b[k]; // recopy the values from temporary to original array.
}

int main()
{
    int a[] = {44,5003,22,12, 10, 43, 23, -78, 45, 123, 56, 98, 41, 90, 24};
    int num;

    num = sizeof(a)/sizeof(int);

    int b[num]; // temporary array to be used for merging

    mergesort(a, b, 0, num-1);

    for (int i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;
}
