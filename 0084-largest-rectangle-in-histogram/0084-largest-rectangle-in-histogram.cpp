class Solution {
public:
    vector<int>psi(vector<int>& arr){
        stack<int>st;
        vector<int>ans(arr.size());
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            int curr=arr[i];
          while(st.top() != -1 && arr[st.top()] >= arr[i])
{
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
        vector<int>nsi(vector<int>& arr){
        stack<int>st;
        vector<int>ans(arr.size());
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int curr=arr[i];
          while(st.top() != -1 && arr[st.top()] >= arr[i])
{
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        vector<int>prev=psi(arr);
        vector<int>next = nsi(arr);
        int size=arr.size();
        int maxArea=INT_MIN;
        for(int i=0;i<arr.size();i++){
         int length=arr[i];
         if(next[i]==-1){
            next[i]=size;
         }
         int width = next[i]-prev[i]-1;
        int area=length*width;
        maxArea=max(area,maxArea);
        
        }
        return maxArea;
    }
};