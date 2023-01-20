//                             https://leetcode.com/problems/magical-string/description/

class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int j=2;
        for(int i=0;s.size()<n+10;i++){
            if(s[j]=='1'){
                if(s.back()=='1')s.push_back('2');
                else s.push_back('1');
            }
            else{
                if(s.back()=='1'){
                    s.push_back('2');
                    s.push_back('2');
                }
                else{
                    s.push_back('1');
                    s.push_back('1');
                }
            }
            j++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')count++;
        }
        return count;
    }
};
