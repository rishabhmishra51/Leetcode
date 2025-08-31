class Solution {
public:
    typedef pair<int,int> P;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];

        if (originalColor == color) return image;  // avoid infinite loop

          queue<P> q;
        q.push({sr, sc});
        image[sr][sc] = color;  // paint starting pixel

        vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            P curr = q.front();  
            q.pop();
            int x = curr.first;
            int y = curr.second;

            for (auto& dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n 
                    && image[new_x][new_y] == originalColor) {
                    
                    image[new_x][new_y] = color;
                    q.push({new_x, new_y});
                }
            }
        }

        return image;
    }
};
