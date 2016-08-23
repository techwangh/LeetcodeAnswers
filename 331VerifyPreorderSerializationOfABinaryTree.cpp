class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return false;
        int count = 0;
        istringstream in(preorder);
        vector<string> vec;
        string s;
        while(getline(in, s, ',')) vec.push_back(s);
        for(int i = 0; i < vec.size()-1; ++i) {
        	if(vec[i] == "#") {
        		if(count == 0) return false;
        		else --count;
        	}
        	else
        		++count;
        }
        return count != 0 ? false : (vec.back() == "#");
    }
};