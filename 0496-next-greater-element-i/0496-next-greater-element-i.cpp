class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
      
            bool flag =true;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    while(j<nums2.size()){
                        if(nums1[i]<nums2[j]){
                               
                    flag=false;
                    ans.push_back(nums2[j]);
                    break;
                        }
                        j++;
                    }
                  
                 
                }
                
            }
            if(flag) ans.push_back(-1);
            
        }
        return ans;
    }
};