class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2==1) return false;
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{                
                if (st.empty()) return false;
                char c = st.top();
                st.pop();
                if(s[i]==')' && c!='(') return false;
                if(s[i]=='}' && c!='{') return false;
                if(s[i]==']' && c!='[') return false;
            }
             
        }
        return st.empty();
    }
};