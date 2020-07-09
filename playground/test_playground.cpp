#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    vector<int> v1 = {5,5555,3,3};
    vector<int> v2 = {5,22222,3,3};
    auto p = mismatch(v1.begin(), v1.end(), v2.begin());
    cout <<*p.first<<" "<< *p.second<< endl;
    return 0;
}