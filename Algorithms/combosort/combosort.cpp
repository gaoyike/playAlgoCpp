#include <iostream>
using namespace std;


int findgap(int x)
{
    x = (x * 10) / 13;
    return max(1, x);
}
void combosort(int a[], int l, int r)
{
    int gap = r;
    bool swapped = true;
    while (gap != 1 || swapped)
    {
        gap = findgap(gap);
        swapped = false;
        for (int i = l; i < r - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
            
        }
        
    }
}
void sort(int a[], int n)
{
   combosort(a, 0, n); 
}
