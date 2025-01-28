class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i,k=minutes;
        vector<int>arr=customers;
        int n=arr.size();
        int prevloss=0;
        for (i=0;i<k;i++){
            if(grumpy[i]==1){
                prevloss+=arr[i];
            }
        }
        int maxloss=prevloss;
        int maxidx=0;
        i=1;
        int j=k;
        while(j<n){
            int currentloss=prevloss;
            if(grumpy[j]==1){
                currentloss+=arr[j];
            }
            if(grumpy[i-1]==1){
                currentloss-=arr[i-1];
            }
            if(maxloss<currentloss){
                maxloss= currentloss;
                maxidx=i;
            }
            prevloss=currentloss;
            i++;
            j++;
        }
        for(i=maxidx;i<maxidx+k;i++){
            grumpy[i]=0;
        }
        int sum=0;
        for(i=0;i<n;i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        return sum;

    }
};