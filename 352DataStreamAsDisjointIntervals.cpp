//TLE
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
    	int i = 0;
    	auto cmp = [](Interval a, Interval b) {return a.end < b.end};
    	auto it = upper_bound(vec.begin(), vec.end(), Interval(val, val), cmp);

    	int i = it - vec.begin();
        if(it == vec.end()) {
        	vec.emplace(vec.end(), val, val);
        }
        else {
        	if(val >= vec[i].start) return;
        	else if(i > 0 && val == vec[i-1].end+1 && val == vec[i].start-1) {
        		vec[i-1].end = vec[i].end;
        		vec.erase(vec.begin()+i);
        	}
        	else if(val == vec[i].start-1) {
        		vec[i].start--;
        	}
        	else if(i > 0 && val == vec[i-1].end+1) {
        		vec[i-1].end++;
        	}
        	else {
        		vec.emplace(vec.begin()+i);
        	}
        }
    }
    
    vector<Interval> getIntervals() {
        return vec;
    }

private:
	vector<Interval> vec;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */



class SummaryRanges {
public:
    void addNum(int val) {
        auto cmp = [] (Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), cmp);
        if(it != vec.begin() && (it-1)->end >= val-1) --it;
        int start = val, end = val;
        while(it != vec.end() && val >= it->start-1 && val <= it->end+1) {
        	start = min(start, it->start);
        	end = max(end, it->end);
        	it = vec.erase(it);
        }
        vec.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vec;
    }

private:
	vector<Interval> vec;
};

//follow up: lots of merges and the number of disjoint intervals are small compared to the data stream's size
//set::insert() : O(log(n))
class SummaryRanges {
public:
    void addNum(int val) {
        auto cmp = [] (Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), cmp);
        if(it != vec.begin() && (--it)->end < val-1) ++it;
        int start = val, end = val;
        while(it != vec.end() && val >= it->start-1 && val <= it->end+1) {
        	start = min(start, it->start);
        	end = max(end, it->end);
        	it = vec.erase(it);
        }
        vec.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(vec.begin(), vec.end());
    }

private:
	struct Cmp {
		bool operator() (Interval a, Interval b) { return a.start < b.start; };
	};
	set<Interval, Cmp> vec;
};