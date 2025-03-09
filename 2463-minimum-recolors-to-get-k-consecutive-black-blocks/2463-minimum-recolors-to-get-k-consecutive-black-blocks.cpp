class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = INT_MAX;
        int count =0;
        for(int i =0;i<n-k+1;i++){
            count = 0;
            for(int j =i;j<k+i;j++){
                if(blocks[j] == 'W') count++;
            }
            ans = min(ans,count);
        }
        return ans;
    }
};