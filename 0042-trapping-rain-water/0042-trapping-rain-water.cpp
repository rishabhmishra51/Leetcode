class Solution {
public:
    int trap(vector<int>&arr) {
        int n = arr.size();
     vector<int>pge(n);
     vector<int>nge(n);
        pge[0]=-1;
        nge[n-1]=-1;
        
        int maxi=arr[0];
        //making pge
        for(int i=1;i<n;i++){
            pge[i] = maxi;
            if(maxi<arr[i])
            maxi=arr[i];
        }
        maxi =arr[n-1];

        for(int i=n-2;i>=0;i--){
            nge[i]=maxi;
            if(maxi<arr[i])
            maxi=arr[i];
        }    
       vector<int>crr(n);
          int sum=0;
        for(int i=1;i<n-1;i++){
           crr[i] = min(pge[i],nge[i]);
           if(arr[i]<crr[i]){
            sum +=( crr[i]-arr[i]);
           }
        }    
      return sum;
        
    }
};