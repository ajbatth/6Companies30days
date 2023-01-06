class my_ds{
    
    public:
    int A,B,C;
    my_ds(int a,int b,int c){
        A=a;
        B=b;
        C=c;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int a=n,b=n,c=n;
        vector<my_ds>v;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a')a=i;
            else if(s[i]=='b')b=i;
            else c=i;
            my_ds ob(a,b,c);
            v.push_back(ob);
        }
        reverse(v.begin(),v.end());
        int count=0;
        for(int i=0;i<n;i++){
            int max_idx=max({v[i].A,v[i].B,v[i].C});
            count+=n-max_idx;
        }
        return count;
    }
};
