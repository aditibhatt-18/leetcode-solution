class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);
        for(char c:s){
            if(c=='(') st.push(0);
            else {
                int current =st.top();
                st.pop();
                if(current==0){
                    current =1;
                }
                else 
                    current= 2*current;

                st.top()+= current;
            }
        }
        return st.top();
    }
};