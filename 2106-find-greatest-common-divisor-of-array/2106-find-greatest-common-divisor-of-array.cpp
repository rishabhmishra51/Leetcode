class Solution {
public:
  int gcd(int a,int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    return a;
  }
    int findGCD(vector<int>& arr) {
        int mini=arr[0];
        int maxi=arr[0];
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                maxi = max(maxi,arr[i]);
            }
            else if(arr[i]<arr[i-1]){
                mini = min(mini,arr[i]);
            }
        }
       return gcd(mini,maxi);
    }
};