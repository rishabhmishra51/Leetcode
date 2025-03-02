class Solution {
public:
    vector<int> getRow(int numRow) {
        vector<vector<int>>ans(numRow+1,vector<int>(numRow+1,0));
        vector<vector<int>>result;
        for(int i=0;i<=numRow;i++){
            vector<int>row;
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    ans[i][j]=1;
                }
                else{
                    ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
                    
                }
                row.push_back(ans[i][j]);
                
            }
            result.push_back(row);
        }
       vector<int>give=result[numRow];
     
      return give;
    }
};