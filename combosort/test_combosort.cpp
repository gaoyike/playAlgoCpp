#include "combosort.cpp"
#include <iostream>
using namespace std;

int main() 
{
    int a[] = {3, 7, 4, 8, 6, 9, 2, 1, 5};
    int N = sizeof(a) / sizeof(a[0]);
    sort(a, N);
    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    return 0;
}