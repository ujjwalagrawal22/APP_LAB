#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <stack>
#include <unordered_set>

using namespace std;
int main()
{
    vector <int> vec;
    array <int,10> arr;
    set <int> s;
    stack <int> n;
    vector <int> vec2(5,22);
    unordered_set <int> b;

    for(int a:vec2)
    {
        cout<< a <<" ";
    }


    return 0;
}