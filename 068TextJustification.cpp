class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.size() == 0) return words;
        int left = 0, width = -1;
        vector<string> res;
        for(int i = 0; i < words.size(); ++i) {
        	width = width + 1 + words[i].size();
        	if(width <= maxWidth) continue;
        	justifyLine(res, words, left, i-1, width-1-words[i].size(), maxWidth);
        	left = i;
        	width = -1;
        	i--;
        }
        string out;
        while(left != words.size()) {
        	out += words[left];
        	if(out.size() < maxWidth) out += " ";
        	left++;
        }
        while(out.size() != maxWidth) {
        	out += " ";
        }
        res.push_back(out);
        return res;
    }

    void justifyLine(vector<string>& res, vector<string>& words, int left, int right, int width, int maxWidth) {
    	int nWords = right - left + 1;
    	string out;
    	if(nWords == 1) {
    	    out += words[left];
    	    while(width != maxWidth) {
    	        out += " ";
    	        width++;
    	    }
    	    res.push_back(out);
    	    return;
    	}
    	int nSpaces = maxWidth - width + nWords -1;
    	int shortSpaceLength = nSpaces / (nWords-1);
    	int nBigSpaces = nSpaces - shortSpaceLength*(nWords-1);
    	string shortSpace(shortSpaceLength, ' '), bigSpace(shortSpaceLength+1, ' ');
    	for(int i = left; i < right; ++i) {
    	    out += words[i];
    		if(nBigSpaces) { out += bigSpace; nBigSpaces--;}
    		else out += shortSpace;
    	}
    	out += words[right];
    	res.push_back(out);
    }
};

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	vector<string> res;
    	int i = 0;
    	while(i < words.size()) {
    		int len = 0, j = i;
    		while(j < words.size() && len+words[j].size()+j-i <= maxWidth) {
    			len += words[j].size();
    			++j;
    		}
    		string out;
    		int nSpace = maxWidth - len;
    		for(int k = i; k < j; ++k) {
    			out += words[k];
    			int spaceLength = 0;
    			if(nSpace) {
    				if(j == words.size()) {
    					if(k < j-1) spaceLength = 1;
    					else spaceLength = nSpace;
    				}
    				else {
    					if(k < j-1) {
    						if(nSpace%(j-k-1) == 0) spaceLength = nSpace/(j-k-1);
    						else spaceLength = nSpace/(j-k-1) + 1;
    					}
    					else spaceLength = nSpace;
    				}
    			}
    			out.append(spaceLength, ' ');
    			nSpace -= spaceLength;
    		}
    		res.push_back(out);
    		i = j;
    	}
    	return res;
    }
};
