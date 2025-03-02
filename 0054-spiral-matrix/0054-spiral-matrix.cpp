class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {

  vector<int> ans;
 
  int m = mat.size();
  int n = mat[0].size(); 
  

  int minr = 0, maxr = m-1, minc =0, maxc = n - 1;

  
  while (minr <= maxr && minc <= maxc) {
      
    // For moving left to right
    for (int i = minc; i <= maxc; i++)
      ans.push_back(mat[minr][i]);

     minr++;
   
    // For moving top to bottom.
    for (int i = minr; i <= maxr; i++)
      ans.push_back(mat[i][maxc]);

    maxc--;
    if(minr>maxr|| minc>maxc) break;
    // For moving right to left.
   
      for (int i = maxc; i >= minc; i--)
       ans.push_back(mat[maxr][i]);

     maxr--;
    
if(minr>maxr || minc>maxc) break;
    // For moving bottom to top.

      for (int i = maxr; i >= minr; i--)
        ans.push_back(mat[i][minc]);

      minc++;
    
  }
       return ans;
    }
};