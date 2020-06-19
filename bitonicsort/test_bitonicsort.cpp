#include <iostream>
#include "bitonicsort.cpp"
using namespace std;
int main()
{
    int a[] = {3, 7, 4, 8, 6, 2, 1, 5};
    int N = sizeof(a) / sizeof(a[0]);

    int up = 1; // means sort in ascending order
    sort(a, N, up);

    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    return 0;
}
