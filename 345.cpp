//Reverse Vowels of a String
class Solution {
public:
    string reverseVowels(string s) {
        int b = 0, e = s.size() - 1;
        while (b < e) {
            for (;!isVowel(s[b]);b++);
            for (;!isVowel(s[e]);e--);
            if (b < e) {
                swap(s[b],s[e]);
                b++;
                e--;
            }
        }
        return s;
    }
private:
    bool isVowel(char c) {
        switch(tolower(c)) {
            case 'a':;
            case 'e':;
            case 'i':;
            case 'o':;
            case 'u':return true;
            default:return false;
        }
    }
};
