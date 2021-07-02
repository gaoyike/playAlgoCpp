#include <bits/stdc++.h> 
using namespace std;
int binarySearch(int a[], int l, int r, int key)
{
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (a[m] == key)
        {
            return m;
        }
        else if (a[m] > key)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int exponentialsearch(int a[], int size, int key)
{
    if (a[0] == key)
    {
        return 0;
    }
    int i = 1;
    while (i < size && a[i] < key)
    {
        i = i * 2;
    }
    return binarySearch(a, i/2, min(i, size), key);
}

