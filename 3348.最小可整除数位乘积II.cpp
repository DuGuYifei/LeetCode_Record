#include <string>
using namespace std;

// class Solution
// {
// private:
//     int len;
//     int factoring[10]{};
//     int count[10]{};
//     string increaseOne(string num)
//     {
//         if (num[len - 1] != '9')
//         {
//             count[num[len - 1] - '0']--;
//             num[len - 1]++;
//             count[num[len - 1] - '0']++;
//         }
//         else
//         {
//             num[len - 1] = '1';
//             count[9]--;
//             count[1]++;
//             for (int i = len - 2; i >= 0; i--)
//             {
//                 count[num[i] - '0']--;
//                 if (num[i] != '9')
//                 {
//                     num[i]++;
//                     count[num[i] - '0']++;
//                     break;
//                 }
//                 else
//                 {
//                     num[i] = '1';
//                     count[1]++;
//                     if (i == 0)
//                     {
//                         len++;
//                         count[1]++;
//                         return "1" + num;
//                     }
//                 }
//             }
//         }
//         return num;
//     }

//     bool isNeedMore(string num)
//     {
//         int extra8 = factoring[8] - count[8];
//         if (extra8 < 0)
//         {
//             extra8 = 0;
//         }
//         int extra4 = factoring[4] + extra8 - count[4];
//         if (extra4 < 0)
//         {
//             extra4 = 0;
//         }
//         int extra6 = factoring[6] - count[6];
//         if (extra6 < 0)
//         {
//             extra6 = 0;
//         }
//         int extra9 = factoring[9] - count[9];
//         if (extra9 < 0)
//         {
//             extra9 = 0;
//         }
//         int need2 = factoring[2] + extra4 * 2 + extra6 + extra8 * 3 - count[2];
//         int need3 = factoring[3] + extra6 + extra9 * 2 - count[3];
//         int need5 = factoring[5] - count[5];
//         int need7 = factoring[7] - count[7];
//         return (need2 > 0 || need3 > 0 || need5 > 0 || need7 > 0);
//     }

// public:
//     string smallestNumber(string num, long long t)
//     {
//         for (int i = 9; i > 1; i--)
//         {
//             while (t % i == 0)
//             {
//                 t /= i;
//                 factoring[i]++;
//             }
//         }
//         if (t != 1)
//         {
//             return "-1";
//         }
//         len = num.length();
//         for (int i = 0; i < len; i++)
//         {
//             if (num[i] == 0)
//             {
//                 num[i] = 1;
//                 for (; i < len; i++)
//                 {
//                     num[i] = 1;
//                 }
//             }
//         }

//         while (isNeedMore(num))
//         {
//             num = increaseOne(num);
//         }
//         return num;
//     }
// };