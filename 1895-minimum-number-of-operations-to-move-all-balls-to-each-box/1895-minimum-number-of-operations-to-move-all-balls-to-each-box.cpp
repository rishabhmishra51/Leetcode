class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>distances(n,0);
        int prefixCount=0;
        int prefixSum =0;
        for(int i=0;i<n;i++){
            distances[i] = prefixCount*i - prefixSum ;
            if(boxes[i]=='1'){
                prefixCount++;
                prefixSum += i;
            }
        }

        int suffixSum =0;
        int suffixCount =0;
        for(int i=n-1;i>=0;i--){
            distances[i] += suffixSum - suffixCount*i;
            if(boxes[i]=='1'){
                suffixSum +=i;
                suffixCount++;
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=distances[i];
        }
        return ans;
    }
};