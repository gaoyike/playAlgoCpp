#include <iostream>
using namespace std;

void sort (int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int temp;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (a[i - 1] > a[i])
            {
                temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
        }
        left++;
    }   
}