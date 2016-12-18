//Palindrome Number
//关键在于用log10求出数字有多少位，然后可以分别提出最高位和最低位。
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if (x == 0)
            return true;
        int t = x;
        int n = log10(t);
        bool f = true;
        while(t) {
            int w = pow(10, n);
            int h = t / w;
            int l = t % 10;
            if(h != l) {
                f = false;
                break;
            }
            t %= w;
            t /= 10;
            n-=2;
        }
        return f;
    }
};
