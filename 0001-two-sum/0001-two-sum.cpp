class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force method
    //      for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         if (nums[i] + nums[j] == target) {
    //             return {i, j};
    //         }
    //     }
    // }
    // return {};
    
//     int n=nums.size();
//  unordered_map<int, int> mpp;
//     for (int i = 0; i < n; i++) {
//         int num = nums[i];
//         int moreNeeded = target - num;
//         if (mpp.find(moreNeeded) != mpp.end()) {
//             return "YES";
//         }
//         mpp[num] = i;
//     }
//     return "NO";

//optimize two pointer
//       int i=0,j=nums.size()-1;
//       sort(nums.begin(),nums.end());
//       while(i<j){
//         int sum =nums[i]+nums[j];
//         if(sum==target){
//          return {i,j};
//         }
//         else if(sum<target){
//             i++;
//         }
//         else{
//             j--;
//         }
//       }
//    return {};



// vector<int>ans;
// int n=nums.size();
// unordered_map<int,int>m;
// for(int i=0;i<n;i++){
//     int rem = target- nums[i];
//     if(m.find(rem)!= m.end()){
//         ans.push_back(m[rem]);
//         ans.push_back(i);
//     }
//     else m[nums[i]]=i;
// }

// return ans;


//revision

int n=nums.size();
map<int,int>mp;

for(int i=0;i<n;i++){
    int remaining = target-nums[i];
    if(mp.find(remaining)!=mp.end()){
        return {mp[remaining],i};
    }
    else{
        mp[nums[i]]=i;
    }
}
return {};
    }
};