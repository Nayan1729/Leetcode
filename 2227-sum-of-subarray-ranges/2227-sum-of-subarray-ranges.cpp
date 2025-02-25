class Solution {
public:
    stack<int> emptyStack(stack<int>s){
        while(!s.empty()){
            s.pop();
        }
        return s;
    }
    long long subArrayRanges(vector<int>& a) {
        // O(n^2)
        /* int n = a.size() ;
        long long sum=0; 
        for(int i=0;i<n;i++){
            int maxx = a[i] , minn  = a[i];
            for(int j = i ; j < n ;j++){
                    maxx = max(maxx , a[j]);
                    minn = min(minn , a[j]);
                    sum += (maxx - minn);
            }
        }
        return sum;
        */
        int n = a.size();
        stack<int>s;
        vector<int>prevSmall(n,-1),nextSmall(n,-1),prevGreat(n,-1) , nextGreat(n,-1);

        //prev Smaller find
        for(int i=0;i<n;i++){
            while(!s.empty() && a[i] <= a[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                prevSmall[i] = s.top();
            }
            s.push(i);
        }
        s = emptyStack(s);
        // prev Greater find
        for(int i=0;i<n;i++){
            while(!s.empty() && a[i] >= a[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                prevGreat[i] = s.top();
            }
            s.push(i);
        }
        s = emptyStack(s);

         // next Smaller find use < only
         for(int i = n-1 ; i >= 0 ; i--){
            while(!s.empty() && a[i] < a[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                nextSmall[i] = s.top();
            }
            s.push(i);
        }
        s = emptyStack(s);
        for(int i = n-1 ; i >= 0 ; i--){
            while(!s.empty() && a[i] > a[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                nextGreat[i] = s.top();
            }
            s.push(i);
        }
        long long maxContriubtionsSum = 0 , minContriubtionsSum = 0;
        long long lowerSmall , upperSmall , lowerGreat , upperGreat;
        for(int i = 0; i < n ; i++ ){
            if(prevSmall[i] == -1){
                lowerSmall = 1 + i ;
            }else{
                lowerSmall = i - prevSmall[i];
            }

            if(nextSmall[i] == -1){
                upperSmall = n-i ;
            }else{
                upperSmall =  nextSmall[i] - i ;
            }

            if(prevGreat[i] == -1){
                lowerGreat = 1 + i ;
            }else{
                lowerGreat = i - prevGreat[i];
            }

            if(nextGreat[i] == -1){
                upperGreat = n - i ;
            }else{
                upperGreat =  nextGreat[i] - i ;
            }
            maxContriubtionsSum += (long long)upperGreat * lowerGreat * a[i] ;
            minContriubtionsSum += (long long)upperSmall * lowerSmall * a[i] ;
        }
        return maxContriubtionsSum - minContriubtionsSum;
    }
};