// Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int a1 = 1, a2 = 2, a;
        for (int i = 3;i <= n;i++)
        {
            a = a1 + a2;
            a1 = a2;
            a2 = a;
        }
        return a;
    }
};
