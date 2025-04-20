class Solution {
public:
    int numRabbits(vector<int>& answer) {
        unordered_map<int, int> m;
        int result = 0;

        for (int i = 0; i < answer.size(); i++) {
            if (m[answer[i]] == 0) {
                result += answer[i] + 1;
                if (answer[i] == 0) continue;
                m[answer[i]] = 1;
            } else {
                m[answer[i]]++;
                int key = answer[i];
                int val = m[key];
                if (val == key + 1) {
                    m.erase(key);
                }
            }
        }

        return result;
    }
};
