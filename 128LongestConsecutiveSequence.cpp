class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i : nums) {
        	if(m[i]) continue;
        	m[i] = m[i-m[i-1]] = m[i+m[i+1]] = m[i-1] + m[i+1] + 1;
        	res = max(res, m[i]);
        }
        return res;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
  		for(auto num : nums) {
  			m[num] = 1;
  		}
  		for(auto num : nums) {
  			int n = 1;
  		 	m.erase(num);
  			int tmp = num;
  			while(m.find(num-1) != m.end()) {
  				n++;
  				m.erase(num);
  				num--;
  			}
  			num = tmp;
  			while(m.find(num+1) != m.end()) {
  				n++;
  				m.erase(num);
  				num++;
  			}
  			res = max(res, n);
  		}
  		return res;
    }
};