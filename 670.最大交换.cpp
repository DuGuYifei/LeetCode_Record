#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while(num != 0)
        {
            nums.push_back(num % 10);
            num /= 10;
        }
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(),idx.end(),0);

        sort(idx.begin(),idx.end(), [r=nums.data()](const int& a, const int &b){return r[a] > r[b]? true:a > b;});
        n--;
        for(auto& i : idx)
        {
            if(nums[i] >= nums[n])
            {
                if(i == n)
                {
                    n--;
                }
                else
                {
                    swap(nums[i], nums[n]);
                    break;
                }
            }
        }

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            num *= 10;
            num += nums[i];
        }
        return num;
    }
};
// @lc code=end

