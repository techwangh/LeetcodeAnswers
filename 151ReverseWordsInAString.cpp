class Solution {
public:
    void reverseWords(string &s) {
        
        istringstream in(s);
        string word, res;
        while(in >> word) {
            res = " " + word + res;
        }
        if(!res.empty()) 
            s = res.substr(1);
        else 
            s = "";
    }
};