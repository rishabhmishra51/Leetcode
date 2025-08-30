class Solution {
public:
    int find(vector<int>& arr){
        int n=arr.size();
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<e){
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=(s+e)/2;
        }
        return e;
    }
    int findPeakElement(vector<int>& nums) {
       return find(nums);
    }
};