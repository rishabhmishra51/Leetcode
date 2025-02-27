class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>preSum(n,0);
        preSum[0] = arr[0];
        int M=1e9+7;
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+arr[i];
        }
        int count=0;
        int odd=0;
        int even=1;
        for(int i=0;i<n;i++){
           if(preSum[i]%2 ==0){
            count = (count+odd)%M;
            even++;
           }
           else{
            count =(count+even)%M;
            odd++;
           }
        }
  return count;
    }
};