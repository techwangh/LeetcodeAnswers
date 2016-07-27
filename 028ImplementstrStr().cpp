class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int end = haystack.size() - needle.size();
        for(int start = 0; start <= end; ++start) {
        	int i = start, j = 0;
        	while(haystack[i] == haystack[j]) {
        		++i; ++j;
        		if(i == needle.size()) return start;
        	}
        }
        return -1;
    }
};