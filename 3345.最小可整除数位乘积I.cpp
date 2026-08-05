class Solution
{
private:
    int multiplyDigits(int n)
    {
        int product = 1;
        while (n)
        {
            product *= n % 10;
            n /= 10;
        }
        return product;
    }

public:
    int smallestNumber(int n, int t)
    {
        for (;; n++)
        {
            if (multiplyDigits(n) % t == 0)
            {
                return n;
            }
        }
        return -1;
    }
};