class Solution {
public:
    bool lemonadeChange(vector<int>& a) {

        int i,j, currentBill;
        int fives=0 , tens =0 ;
        for(i=0;i<a.size();i++){
            int currentBill = a[i];
            if(currentBill == 5){
                fives++;
            }else if(currentBill == 10){
                if(!fives)return false;
                else{
                    tens++;
                    fives--;
                }
            }else{
                if(tens ){
                    if(fives){
                        tens--;
                        fives--;
                    }else{
                        return false;
                    }
                }else{
                    if(fives >=3){
                        fives-=3;
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};