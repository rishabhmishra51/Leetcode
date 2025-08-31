class Solution {
public:
     typedef pair<int,int>P;
     vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       int freshCount=0;
      queue<P>q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1){
                freshCount++;
            }
        }
       }
       if(freshCount==0) return 0;
        int mintues=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                P curr = q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;
            
            for(vector<int>&dir:directions){
                int new_x = x+ dir[0];
                int new_y = y+dir[1];

                if(new_x >=0 && new_x <m && new_y>=0 && new_y<n && grid[new_x][new_y]==1){
                    grid[new_x][new_y]=2;
                    q.push({new_x,new_y});
                    freshCount--;
                }
            }
            }
            mintues++;
        }
        return freshCount==0 ? mintues-1:-1;
    }
};