class Solution {
public:
  int getdigitSum(int n){
    int sum=0;
    while(n>0){
        sum+= n%10;
        n /=10;
    }
    return sum;
  }
    int maximumSum(vector<int>& nums) {
       int ans=-1;
       int n=nums.size();

        int mp[82]={0};
        
       for(int i=0;i<n;i++){
        int numSum =getdigitSum(nums[i]);
        if(mp[numSum] >0){
            ans = max(ans,nums[i]+mp[numSum]);
        }

            mp[numSum] = max(nums[i],mp[numSum]);
        
       } 
       return ans;
    }
};