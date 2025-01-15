class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int cnt = __builtin_popcount(num2);
        int x = 0, ones = 0;
        
        for(int i = 31; i >= 0; --i) {
            if(ones < cnt && (num1 & (1 << i)) != 0) {
                
                ++ones;
                x |= (1 << i);
            }
        }
        
        for(int i = 0; i <= 31; ++i) {
            if(ones < cnt && (x & (1 << i)) == 0) {
                
                ++ones;
                x |= (1 << i);
            }
        }
        
        return x;
    }
};