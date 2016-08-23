class Solution {
public:
    string reverseVowels(string s) {
        vector<int> indices;
        for(int i = 0; i < s.size(); ++i) {
        	if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
        	   s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
        		indices.push_back(i);
        	}
        }
        int left = 0, right = indices.size()-1;
        while(left < right) {
        	swap(s[indices[left++]], s[indices[right--]]);
        }
        return s;
    }
};