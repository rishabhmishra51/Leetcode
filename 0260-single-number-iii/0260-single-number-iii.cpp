class Solution {
public:
    vector<int> singleNumber(vector<int>& Arr) {
        int x = 0, bucket1 = 0, bucket2 = 0;
        
        // Step 1: XOR all elements → Get XOR = a ⊕ b
        for (int num : Arr) {
            x ^= num;
        }

        // Step 2: Find the rightmost set bit (fixing potential overflow)
        unsigned int mask = x & -(unsigned int)x;

        // Step 3: Divide numbers into two groups
        for (int num : Arr) {
            if (num & mask)
                bucket1 ^= num;  // XOR Group 1
            else
                bucket2 ^= num;  // XOR Group 2
        }

        // Step 4: Return the unique numbers in sorted order
        return {min(bucket1, bucket2), max(bucket1, bucket2)};
    }
};
