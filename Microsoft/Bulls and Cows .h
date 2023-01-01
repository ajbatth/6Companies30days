class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int bull=0;
        map<char,int>secret_freq,guess_freq;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])bull++;
            else{
                secret_freq[secret[i]-'a']++;
                guess_freq[guess[i]-'a']++;
            }
        }
        int cow=0;
        for(auto it:secret_freq){
            cow+=min(secret_freq[it.first],guess_freq[it.first]);
        }
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};
