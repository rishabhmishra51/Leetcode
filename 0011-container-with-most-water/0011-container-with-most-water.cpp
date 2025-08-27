class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int height = (arr[left] < arr[right]) ? arr[left] : arr[right]; 
            int width = right - left;
            int area = height * width;
            if (area > maxArea) {
                maxArea = area;
            }
          
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};