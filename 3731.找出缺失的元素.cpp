#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int count[101]{};
        vector<int> ans;
        int smallest = 100;
        int biggest = 1;
        for (const int n : nums)
        {
            count[n] = 1;
            if (n > biggest)
            {
                biggest = n;
            }
            if (n < smallest)
            {
                smallest = n;
            }
        }
        for (int i = smallest; i < biggest; i++)
        {
            if (count[i] == 0)
            {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};