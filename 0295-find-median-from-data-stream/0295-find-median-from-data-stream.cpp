class MedianFinder {
public:
    /* This gives TLE
    vector<int> a; 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        a.push_back(num);
    }
    
    double findMedian() {
        sort(a.begin(),a.end());
        int size = a.size();
        int n = size / 2;
        if((size & 1) == 0){ // Even
            return  (a[n - 1 ] + a[n] )/2.0;
        }else{ // Odd
            return a[n];
        }
        return 0;
    }
    */
    // Use heap
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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */