class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        if(start==goal) return 0;
        else{
        int c=1;

       while(ans&ans-1){
       c++;
       ans= ans&ans-1;
       }
       return c;}
    }
};