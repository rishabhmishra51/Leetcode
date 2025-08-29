class Solution {
public:
    struct trieNode{
        trieNode *left; //for 0
        trieNode *right; // for 1
    } ;
    void insert(trieNode * root, int &num){
        trieNode* pCrawal =root;
        for(int i=31;i>=0;i--){
            int ith_bit = (num >> i)&1;
            if(ith_bit == 0){
                if(pCrawal->left==NULL){
                    pCrawal->left=new trieNode();
                }
              pCrawal =  pCrawal->left;
            }
            else{
                if(pCrawal->right==NULL){
                    pCrawal->right = new trieNode();
                }
                pCrawal = pCrawal->right;
            }
        }
    }
    int findxor(int &num , trieNode* root){
       long long maxxor=0;
        trieNode* pCrawal = root;
        for(int i=31;i>=0;i--){
            int ith_bit = (num >> i)&1;
            if(ith_bit ==1){
                if(pCrawal->left != NULL){
                    maxxor += pow(2,i);
                    pCrawal=pCrawal->left;
                }
                else{
                    pCrawal=pCrawal->right;
                }
            }
            else{
                
                    if(pCrawal->right !=NULL){
                        maxxor += pow(2,i);
                        pCrawal=pCrawal->right;
                    }
                    else{
                        pCrawal=pCrawal->left;
                    }
                }
            
        }
        return maxxor;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode();

        for(auto &num:nums){
            insert(root,num);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int temp = findxor(nums[i],root);
            maxi = max(temp,maxi);
        }
        return maxi;
    }
};