#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        unordered_map<int, queue<int>> indexMap;
        int right = 0, left = 0;
        int maxLength = 1;
        for (; right < nums.size(); right++)
        {
            freq[nums[right]]++;
            indexMap[nums[right]].push(right);
            if (freq[nums[right]] > k)
            {
                maxLength = max(maxLength, right - left);
                int leftIndex = indexMap[nums[right]].front();
                for (int i = left; i <= leftIndex; i++)
                {
                    freq[nums[i]]--;
                    indexMap[nums[i]].pop();
                }
                left = leftIndex + 1;
            }
        }
        maxLength = max(maxLength, right - left);
        return maxLength;
    }
};