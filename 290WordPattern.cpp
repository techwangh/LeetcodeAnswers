class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream in(str);
        map<char, int> m1;
        map<string, int> m2;
        string word;
        for(int i = 0; i < pattern.size(); ++i) {
        	if(!(in >> word)) return false;
        	if(m1[pattern[i]] != m2[word]) return false;
        	m1[pattern[i]] = i+1;
        	m2[word] = i+1;
        }
        
        return in >> word ? false : true;
    }
};