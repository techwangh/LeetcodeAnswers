/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct cmp {
	bool operator() (Interval left, Interval right) {
		return left.start < right.start;
	}
}comObject;

//比较函数的第二种写法
bool lessThan(Interval left, Interval right) {
		return left.start < right.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), lessThan);
        int posStart = intervals[0].start;
        int posEnd = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i) {
        	if(intervals[i].start <= posEnd) {
        		posEnd = max(posEnd, intervals[i].end);
        		continue;
        	} else {
        		res.push_back(Interval(posStart, posEnd));
        		posStart = intervals[i].start;
        		posEnd = intervals[i].end;
        	}
        }
        res.push_back(Interval(posStart, posEnd));
        return res;
    }

};


//more concise one
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), lessThan);
  		res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i) {
        	if(intervals[i].start <= res.back().end) {
        		res.back().end = max(res.back().end, intervals[i].end);
        	} else {
        		res.push_back(Interval(intervals[i]));
        	}
        }
        return res;
    }
};
