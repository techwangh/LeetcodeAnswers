class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1, m2;
        for(auto c : ransomNote) 
            m1[c]++;
        for(auto c : magazine) 
            m2[c]++;
        for(auto pair : m1) {
            if(pair.second > m2[pair.first]) return false;
        }
        return true;
    }
};