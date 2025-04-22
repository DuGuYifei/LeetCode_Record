#include <unordered_map>
/*
 * @lc app=leetcode.cn id=2338 lang=cpp
 *
 * [2338] 统计理想数组的数目
 */

// @lc code=start
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e4;
class Solution
{
public:
    long long factorial[MAXN * 2 + 5];
    long long invFactorial[MAXN * 2 + 5];
    Solution()
    {
        factorial[0] = 1;
        for (int i = 1; i < MAXN * 2 + 5; i++)
        {
            factorial[i] = factorial[i - 1] * i % MOD;
        }
        invFactorial[MAXN * 2 + 5 - 1] = modPow(factorial[MAXN * 2 + 5 - 1], MOD - 2);
        for (int i = MAXN * 2 + 5 - 2; i >= 0; i--)
        {
            invFactorial[i] = invFactorial[i + 1] * (i + 1) % MOD;
        }
    }

    inline long long modPow(long long x, long long y)
    {
        long long res = 1;
        while (y)
        {
            if (y & 1)
                res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    inline long long comb(int n, int k)
    {
        if (k > n || k < 0)
            return 0;
        return factorial[n] * invFactorial[k] % MOD * invFactorial[n - k] % MOD;
    }

    int idealArrays(int n, int maxValue)
    {
        long long ans = 0;
        for (int i = 1; i <= maxValue; i++)
        {
            int num = i;
            std::unordered_map<int, int> primeFactors;
            for (int j = 2; j * j <= num; j++)
            {
                while (num % j == 0)
                {
                    primeFactors[j]++;
                    num /= j;
                }
            }
            if (num > 1)
            {
                primeFactors[num]++; // 因为num现在是不停除以j的结果，所以num>1时，num就是一个质数
            }
            long long cnt = 1;
            for (auto &pair : primeFactors)
            {
                int exponent = pair.second;
                cnt = cnt * comb(n - 1 + exponent, exponent) % MOD; // 组合数
            }
            ans = (ans + cnt) % MOD; // 这里的cnt是每个质数的组合数乘积
        }
        return ans;
    }
};
// @lc code=end
