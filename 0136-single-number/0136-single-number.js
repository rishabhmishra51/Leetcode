/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
      let n=nums.length;
        let xorr=0;
        for(let i=0;i<n;i++){
            xorr = xorr^nums[i];
        }
        return xorr;
};