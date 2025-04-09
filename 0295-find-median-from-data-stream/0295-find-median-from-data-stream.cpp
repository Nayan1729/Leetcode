/*class MedianFinder {
public:
    
    // Use heaps but the complex approach
    priority_queue<int>  maxpq;
    priority_queue<int , vector<int>,greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxpq.push(num);
        int m = maxpq.size() , n = minpq.size();
        int maxTop = maxpq.top() , minTop = minpq.empty() ? INT_MAX :  minpq.top(); 
        if(m - n == 0){
            if(maxTop > minTop){
                maxpq.pop(); minpq.pop();
                maxpq.push(minTop);
                minpq.push(maxTop);
            }
        }else if ( m - n == 1){
            if(maxTop > minTop){
                // Push the maxTop in larger heap
                minpq.push(maxTop);
                // Pop from the max
                maxpq.pop();
            }
        }else{
             // Push the maxTop in larger heap
                minpq.push(maxTop);
                // Pop from the max
                maxpq.pop();
        }
    }
    
    double findMedian() {
        int m = maxpq.size() , n = minpq.size();
        if( m == n){
            return (maxpq.top() + minpq.top())/2.0;
        }else if (m > n ){
            return maxpq.top();
        }else{
            return minpq.top();
        }
        return 0;
    }
};
*/
class MedianFinder {
public:
    priority_queue<int>  maxpq;
    priority_queue<int , vector<int>,greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.empty() || maxpq.top() > num){
            maxpq.push(num);
        }else{
            minpq.push(num);
        }
        int m = maxpq.size() , n = minpq.size();
        if( m > n + 1){
            // Pop from max and push its top in the min to balance
            minpq.push(maxpq.top());
            maxpq.pop();
        }else if ( n > m + 1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        int m = maxpq.size() , n = minpq.size();
        if( m == n){
            return (maxpq.top() + minpq.top())/2.0;
        }else if (m > n ){
            return maxpq.top();
        }else{
            return minpq.top();
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */