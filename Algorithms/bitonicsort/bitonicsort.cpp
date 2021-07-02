#include <stdio.h>
#include <algorithm>
using namespace std;
void comp(int a[], int i, int j, int asc)
{
    if(asc == (a[i] > a[j])) 
    // low <= i < j < low + k, 
    //if a[i] > a[j](descending) and asc = 1(ascending), we need to swap 
    {
        swap(a[i], a[j]);
    }
}
void merge(int a[], int left, int n, int asc)
{
    if (n > 1)
    {
        int k = n / 2;
        for (int i = left; i < left + k; i++)
        {
            comp(a, i, i+k, asc);
        }
        merge(a, left, k, asc);
        merge(a, left + k, k, asc);        
    }
    
}
void rec(int a[], int left, int n, int asc) 
{
    if(n > 1)
    {
        int k = n / 2;
        rec(a, left, k, 1); // ascending
        rec(a, left + k, k, 0); //decending
        merge(a, left, n, asc); //merge two bitnoic sort
    }
}

void sort(int a[], int n, int ascending) 
{
    rec(a, 0, n, ascending);
}
