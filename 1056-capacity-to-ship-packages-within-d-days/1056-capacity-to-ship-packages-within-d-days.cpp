class Solution {
public:
    int findDays(vector<int> a , int capacity ){
        int localCapacity = 0 , days = 1;
        for ( int i = 0 ; i < a.size() ; i++ ){
            if(localCapacity  + a[i] <= capacity  ){
                localCapacity += a[i]; // Add in the capacity
            }else{
                localCapacity = a[i] ; // Add it to the next days' slot
                days++;
            }
        }
        return days;
    }

    int bs(vector<int>a , int l , int r  ,int daysToFinish ){ // Intially l = maxNum and r = sum
        while(l <= r ){
            int mid = l + ( r - l )/2;
            int daysTakenForMid = findDays( a , mid );
            if( daysTakenForMid <= daysToFinish ){ // We are using more capacity so decrease the higher value
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return l; 
    }

    int shipWithinDays(vector<int>& a, int days) {
        int i , j , k , maxNum = a[0] , sum = 0 , n = a.size(); 
        // The min capacity should be atleast the max element else that package wont even be loaded
        for( i = 0 ; i < n ; i++ ){
            maxNum = max(maxNum , a[i]);
            sum += a[i];
        }
        // And sum is the max capacity we need (ena thi vadhare toh matlab waste aj che ne)\
        // With capacity = sum we can fill it in one day
        // Now use bs to get the least value of capacity
        return bs(a , maxNum , sum , days );
    }
};