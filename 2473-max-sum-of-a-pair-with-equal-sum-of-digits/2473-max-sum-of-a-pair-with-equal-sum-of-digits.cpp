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

        unordered_map<int,int>mp;
        
       for(int i=0;i<n;i++){
        int numSum =getdigitSum(nums[i]);
        if(mp.count(numSum)){
            ans = max(ans,nums[i]+mp[numSum]);
        }

            mp[numSum] = max(nums[i],mp[numSum]);
        
       } 
       return ans;
    }
};