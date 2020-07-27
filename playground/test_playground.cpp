#include <iostream>  // std::cout
#include <algorithm> // std::lower_bound, std::upper_bound, std::sort
#include <vector>    // std::vector
using namespace std;

struct Node
{
    int key;
    int val;
    Node() : key(0), val(0)
    {
        cout << "default" << endl;
    }
    Node(int k, int v) : key(k),
                         val(v)
    {
        cout << "parameters" << endl;
    }
};
int main()
{
    Node n1;
    cout << "n1 " << n1.key << n1.val << endl;
    Node n2(555, 666);
    cout << "n2 " << n2.key << n2.val << endl;
    return 0;
}