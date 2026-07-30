#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int counts[26]{};
        int num = 0;
        for (char c : word)
        {
            counts[c - 'a']++;
            if (counts[c - 'a'] == 1)
                num++;
        }
        sort(counts, counts + 26, [](int a, int b)
             { return a > b; });

        int ans = 0;
        for (int i = 0; i < num; i++)
        {
            ans += counts[i] * (i / 8 + 1);
        }
        return ans;
    }
};