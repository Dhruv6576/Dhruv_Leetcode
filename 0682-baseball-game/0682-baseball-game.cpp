class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        st.push(stoi(operations[0]));
        for(int i=1; i<operations.size(); i++){
            if(operations[i]=="+"){
                int temp = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp);
                st.push(temp+temp2);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int temp = st.top();
                st.push(temp*2);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum +=  st.top();
            st.pop();
        }
        return sum;
    }
};