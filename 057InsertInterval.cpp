/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        for(int i = 0; i < intervals.size(); ++i) {
        	if(newInterval.start <= intervals[i].end) {
        		if(newInterval.end >= intervals[i].start) {
	        		newInterval.start = min(newInterval.start, intervals[i].start);
	        		newInterval.end = max(newInterval.end, intervals[i].end);
	        		if(i == intervals.size()-1)
	        		    res.push_back(newInterval);
        		}
        		else {
        			res.push_back(newInterval);
        			for(int j = i; j < intervals.size(); ++j) {
        				res.push_back(intervals[j]);
        			}
        			break;
        		}
        	}
        	else {
        		res.push_back(intervals[i]);
        		if(i == intervals.size()-1)
	                res.push_back(newInterval);
        	}
        }
        return res;
    }
};


//another solution, more concise
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0, n = intervals.size();
        int overlappingTimes = 0;
        while(i < n) {
        	if(newInterval.start > intervals[i].end) {}
        	else if(newInterval.end < intervals[i].start) break;
        	else {
        		newInterval.start = min(newInterval.start, intervals[i].start);
        		newInterval.end = max(newInterval.end, intervals[i].end);
        		++overlappingTimes;
        	}
        	++i;
        }
        if(overlappingTimes > 0) {
        	intervals.erase(intervals.begin() + i - overlappingTimes, intervals.begin()+i);
        }
        intervals.insert(intervals.begin() + i - overlappingTimes, newInterval);
        return intervals;
    }
};

//use iterator
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  		vector<Interval>::iterator it = intervals.begin();
  		int overlappingTimes = 0;
  		while(it != intervals.end()) {
  			if(newInterval.start > it->end) {}
        	else if(newInterval.end < it->start) break;
        	else {
        		newInterval.start = min(newInterval.start, it->start);
        		newInterval.end = max(newInterval.end, it->end);
        		++overlappingTimes;
        	}
        	++it;
  		}
  		if(overlappingTimes > 0) {
        	intervals.erase(it - overlappingTimes, it);
        }
        intervals.insert(it - overlappingTimes, newInterval);
        return intervals;
    }
};