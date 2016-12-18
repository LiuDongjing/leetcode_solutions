//Factorial Trailing Zeroes
class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0)
            return 0;
        int n2 = log2(n);
        int n5 = log(n)/log(5);
        int x2 = 0;
        int x5 = 0;
        for(int i = 1;i <= n2;i++)
            x2 += n/pow(2, i);
        for(int i = 1;i <= n5;i++)
            x5 += n/pow(5, i);
        return min(x2, x5);
    }
};
