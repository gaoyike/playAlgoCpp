#include <algorithm>
#include <math.h>
using namespace std;

int jumpsearch(int arr[], int x, int n)
{
    int step = sqrt(n);
    // jump
    while (arr[min(step, n) - 1] < x)
    {
        step += sqrt(n);
    }
    int prev = step - sqrt(n); // previous step 
    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
        {
            return -1;
        }       
    }
    
    if (arr[prev] == x)
    {
        return prev;
    }
    return -1;
}