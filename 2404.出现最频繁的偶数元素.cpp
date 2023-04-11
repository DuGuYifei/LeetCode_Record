/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 *
 * https://leetcode.cn/problems/most-frequent-even-element/description/
 *
 * algorithms
 * Easy (54.91%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 22.4K
 * Testcase Example:  '[0,1,2,2,4,4,1]'
 *
 * 给你一个整数数组 nums ，返回出现最频繁的偶数元素。
 * 
 * 如果存在多个满足条件的元素，只需要返回 最小 的一个。如果不存在这样的元素，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1,2,2,4,4,1]
 * 输出：2
 * 解释：
 * 数组中的偶数元素为 0、2 和 4 ，在这些元素中，2 和 4 出现次数最多。
 * 返回最小的那个，即返回 2 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [4,4,4,9,2,4]
 * 输出：4
 * 解释：4 是出现最频繁的偶数元素。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [29,47,21,41,13,37,25,7]
 * 输出：-1
 * 解释：不存在偶数元素。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2000
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int maxi = 0;
        int ans = -1;
        unordered_map<int, int> cnts;
        for(const int& i : nums){
            if(i%2 == 0){
                cnts[i]++;
                if(cnts[i] > maxi){
                    maxi = cnts[i];
                    ans = i;
                }else if(cnts[i] == maxi && ans > i){
                    ans = i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

