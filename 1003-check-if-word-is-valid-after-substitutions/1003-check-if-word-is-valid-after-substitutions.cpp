class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char ch :s){
            st.push(ch);

            if (st.size()>=3){
                // c
                // b
                // a
                // remove it off   so abc is removed from the stack 

                char c =st.top();st.pop();
                char b=st.top(); st.pop();
                char a=st.top();st.pop();

                if(!(a=='a' && b =='b' && c =='c') ){
                    // if not abc together exists PUSH the eachchar to stack
                    // if not abc push 
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
            
        }
        return st.empty();
        
    }
};