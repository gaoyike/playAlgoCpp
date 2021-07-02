#include "exponentialsearch.cpp"

using namespace std;

int main()
{
    
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int N = sizeof(a) / sizeof(a[0]);
    cout << exponentialsearch(a,  N, 6) << endl;
}