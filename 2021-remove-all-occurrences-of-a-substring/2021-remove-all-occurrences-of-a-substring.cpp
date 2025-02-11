class Solution {
public:

    void removeOcc(string& s,string&part){
       
     

        int pos = s.find(part);
        if(pos != string::npos){
            //part found 
            // remove part 
            // s.erase(pos,part.length());
            //other way without erase function O(n^2)
           string left_part = s.substr(0,pos);
           string right_part = s.substr(pos+part.size(),s.size());
           s = left_part+right_part; 
            removeOcc(s,part);
        }
        else{
            //all the occurences of s as part is removed
            return;
        }
        
    }
    string removeOccurrences(string s, string part) {
    //   int pos =s.find(part);
    //   while(pos != string::npos){
    //       s.erase(pos,part.length());
    //       pos =s.find(part);
    //   }
    //    return s;

        removeOcc(s,part);
        return s;
    }
};