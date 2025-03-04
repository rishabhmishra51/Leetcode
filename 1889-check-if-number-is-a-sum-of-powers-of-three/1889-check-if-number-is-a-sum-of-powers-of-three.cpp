class Solution {
public:
    bool checkPowersOfThree(int n) {
         //All the digits of base-3 number must be either 0 or 1
        while(n){
            if(n%3==2)
                return false;
            n/=3;
        }
        return true;
    }
};