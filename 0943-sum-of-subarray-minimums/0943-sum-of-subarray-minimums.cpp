class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        // O(n^3)
        /*long long sum=0 , n=a.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
            long long mini = a[j];
                for(int k = i ;k <j ;k++){
                    if(mini > a[k]){
                        mini = a[k];
                    }
                }
                sum +=mini;
            }
        }
        return sum % 1000000007 ;
        */
        // O(n^2)
        /*
        long long sum  = 0, n = a.size();
        for(int i = 0;i<n;i++){
            int mini = INT_MAX;
            for(int j=i;j<n;j++){
                mini = min(mini , a[j]);
                sum+=mini;
            }
        }
        return sum % 1000000007;
        */

        stack<int>st;
        int n = a.size();
        vector<int> prev(n, -1), next(n, -1);  // Fixed-size arrays
        //Calculate previous Smaller

        for(int i=0;i<n;i++){
            while(!st.empty() && a[i] <= a[st.top()] ){
                st.pop();
            }
            if(!st.empty()){
                prev[i] = st.top();
            }//else -1 already present
                st.push(i);
        }

        while(!st.empty()){
                st.pop();
        }

        // Calculating next smaller

        for(int i = n-1 ; i >=0 ; i-- ){
            while(!st.empty() && a[i] < a[st.top()]){ // why is no equal present
                st.pop();
            }
            if(!st.empty()){
                next[i] = st.top();
            }
            st.push(i);
        }
        long lower , upper,sum=0;
        for(int i=0 ;i<n;i++){
            if(prev[i]== -1){
                lower = 1+i;
            }else{
                lower = i - prev[i];
            }
            if(next[i] == -1 ){
                upper = n-i;
            }else{
                upper =  next[i] - i;
            }
            sum += (upper * lower * a[i]);
        }
        return sum % 1000000007;
    }
};