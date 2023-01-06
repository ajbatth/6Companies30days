//                                 https://leetcode.com/problems/factorial-trailing-zeroes/description/
class Solution {
public:
    int trailingZeroes(int n) {
        int num=n;
        int two=0;
        while(num>1){
            two+=num/2;
            num/=2;
        }
        num=n;
        int five=0;
        while(num>1){
            five+=num/5;
            num/=5;
        }
        return min(two,five);
    }
};
