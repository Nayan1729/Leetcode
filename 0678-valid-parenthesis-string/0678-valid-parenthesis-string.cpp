class Solution {
public:
    bool checkValidString(string s) {
        int i , n =  s.length();
        stack<char> st1, st2;
        for ( i = 0 ; i < n ; i++){
            if(s[i] == '(' || s[i] == '*' ){
                st1.push(s[i]);
            }else if(s[i] == ')'){
                while( !st1.empty() && st1.top() == '*'){
                    st2.push(st1.top());
                    st1.pop();
                }
                if(!st1.empty()){ // Meaning we have  a '('
                    st1.pop();
                }else if(!st2.empty()){
                    st2.pop();
                }else{
                    return false;
                }
                while(!st2.empty()){
                    st1.push(st2.top());
                    st2.pop();
                }
            }
        }
        while(!st1.empty()){
            while(!st1.empty() && st1.top() == '*' ){
                st2.push('*');
                st1.pop();
            }
            if( !st1.empty()){
                if(st2.empty()){
                    return false;
                }else{
                    st1.pop();
                    st2.pop();
                }
            }
        }
        return true;
    }
};