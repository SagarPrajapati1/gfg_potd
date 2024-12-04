class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        if(s1 == s2)
          return true;
          
        string tmp = s1 + s1;
        
        if (tmp.find(s2) != std::string::npos)
           return true;
        
        return false;  
    }
};
