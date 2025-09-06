class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        
int s=0;
int e= v.size()-1;
int mid = s+(e-s)/2;
while (s <= e)
{
 if (s==e)
 {   //for single element
       return v[s];

 }
 //2cases mid is even or odd
 //even-odd
 if(mid%2==0){
   if (v[mid]==v[mid+1])
   {
       s=mid+2;

   }
   else{
       e=mid;
   }
   
 }
 // odd-even
 else{
     if (v[mid]==v[mid-1])
     {
       s=mid+1;
     }
     else{
       e=mid-1;
     }
 }
  mid = s+(e-s)/2;
}
return -1;

    }
};