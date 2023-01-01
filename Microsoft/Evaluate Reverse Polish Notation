class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        
        for(auto s:tokens){
            if(s=="-" || s=="+"||s=="*"||s=="/"){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                if(s=="+"){
                st.push(num1+num2);
                }
                else if(s=="-"){
                    st.push(num2-num1);
                }
                else if(s=="*"){
                    st.push(1LL*num1*num2);
                }
                else if(s=="/"){
                    st.push(num2/num1);
                }
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
