#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        vector<int> input(n);
        for(int i = 0; i < n; ++i)    cin >> input[i];
        stable_sort(input.begin(), input.end());
        for(int i = 0; i < k-1; ++i)    cout << input[i] << " ";
        cout << input[k-1] << endl;
    }
    return 0;
}