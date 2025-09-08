class Solution {
private:
    bool check(int num) {
        while (num > 0) {
            if (num % 10 == 0) return false;
            num /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int i, j; // declare outside the loop
        for (i = 1; i < n; i++) { // start from 1 (0 has 0 digit)
            j = n - i;
            if (check(i) && check(j)) break;
        }
        return {i, j};
    }
};
