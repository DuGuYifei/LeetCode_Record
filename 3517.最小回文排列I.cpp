#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int count[26]{};
        for (const auto &c : s)
        {
            count[c - 'a']++;
        }
        string ans = s;
        int len = s.length();
        int id = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2)
            {
                ans[len / 2] = i + 'a';
                count[i]--;
            }
            while (count[i] > 0)
            {
                count[i] -= 2;
                ans[id++] = ans[len - id - 1] = i + 'a';
            }
        }
        return ans;
    }
};