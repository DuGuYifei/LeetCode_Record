#include <string>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        // int div = word.length() / 8;
        // int rem = word.length() % 8;
        // int ans = 0;
        // for (int i = 1; i <= div; i++)
        // {
        //     ans += i * 8;
        // }
        // return ans + rem * (div + 1);
        int n = word.size();
        int m = (n - 1) / 8 + 1;
        return m * (m - 1) * 4 + (n - (m - 1) * 8) * m;
    }
};