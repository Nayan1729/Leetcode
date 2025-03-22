class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& c) {
        int i , j , count = 0;
        sort(g.begin() , g.end() );
        sort(c.begin() , c.end() );
        vector<int> assigned(c.size() , 0);

        for( i=0 ; i< g.size() ; i++){
            for(j=0; j< c.size();j++ ){
                if(!assigned[j] && c[j] >= g[i]){
                    count++;
                    assigned[j] = 1;
                    break;
                }
            }
             if( j == c.size() ){
                    return count;
                }
        }
        return count;
    }
};