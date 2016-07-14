//TLE
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> res;
        for(auto str : strs) {
        	int index = getIndex(res, str);
        	if(index != -1)
        		res[index].push_back(str);
        	else {
        		string tmpStr = str;
        		sort(tmpStr.begin(), tmpStr.end());
        		vector<string> out{tmpStr, str};
        		res.push_back(out);
        	}
        }
        for(auto &vec : res) {
        	vec.erase(vec.begin());
        }
     	return res;
    }

    int getIndex(vector<vector<string>>& vec, string s) {
        sort(s.begin(), s.end());
    	for(int i = 0; i < vec.size(); ++i) {
    		if(s == vec[i][0]) return i;
    	}
    	return -1;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> res;
    	map<string, vector<string>> m;
    	map<string, vector<string>>::iterator it;
    	for(auto &str : strs) {
    		// string tmpStr = str;
    		// sort(tmpStr.begin(), tmpStr.end());
    		string sortedStr = strSort(str);
    		m[sortedStr].push_back(str);
    	}
    	for(auto &pair : m) {
    		res.push_back(pair.second);
    	}
    	return res;
    }

    string strSort(string& s) {	//s只由26个小写字母组成，可以用计数排序，时间复杂度为O(n)
    	vector<int> count(26, 0);
    	for(char letter : s) {
    		count[letter-'a']++;
    	}
    	int k = 0;
    	string res(s.size(), 'a');
    	for(int i = 0; i < 26; ++i) {
    		for(int j = 0; j < count[i]; ++j) {
    			res.[k++] += i;
    		}
    	}
    	return t;
    }
};


