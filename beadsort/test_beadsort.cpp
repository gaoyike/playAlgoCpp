#include <iostream>
#include "beadsort.cpp"

using namespace std;

int main()
{
    int a[] = {6,3,2,1,6,3,4,7,5,5,5,2,1,10,2,2,6,4};
    int size = sizeof(a) / sizeof(a[0]);
    beadsort(a, size);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}