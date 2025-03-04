class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams=0;
        int n=rating.size();
        for(int j=1;j<n-1;j++){
           int leftsmallercount=0;
           int rightsmallercount=0;
           int leftlargercount=0;
           int rightlargercount=0;
           for(int i=0;i<j;i++){
            if(rating[j]>rating[i]){
                leftsmallercount++;
            }
            else{
                leftlargercount++;
            }
           }
           for(int k=j+1;k<n;k++){
            if(rating[k]<rating[j]){
                rightsmallercount++;
            }
            else{
                rightlargercount++;
            }
           }
           teams+= ((leftsmallercount*rightlargercount) +(leftlargercount*rightsmallercount));
        }
        return teams;
    }
};