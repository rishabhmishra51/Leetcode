class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * 2; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                ans.push_back(i);
            }
        }
        
        int diff = INT_MAX;
        vector<int> result = {-1, -1};  
        
        for (int i = 1; i < ans.size(); i++) {
            int d = ans[i] - ans[i - 1];
            if (d < diff) {
                diff = d;
                result = {ans[i - 1], ans[i]};
            }
        }
        
        return result;
    }
};
