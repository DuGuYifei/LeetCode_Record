#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
private:
    int n;
    string itos(int num)
    {
        string res = "";
        while (num)
        {
            res.push_back('0' + num % 2);
            num /= 2;
        }
        for (int i = res.size(); i < n; i++)
        {
            res.push_back('0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        n = nums[0].size();
        int count = nums.size();
        unordered_map<int, bool> numCount;
        for (int i = 0; i < count; i++)
        {
            numCount[stoi(nums[i], nullptr, 2)] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (!numCount[i])
                return itos(i);
        }
        return itos(n);
    }
};