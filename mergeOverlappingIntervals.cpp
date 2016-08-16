#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
 
 bool compareFunc(const Interval& lhs, const Interval& rhs) {
    return lhs.start < rhs.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    if (A.size() <= 1) return A;
    
    vector<Interval> copy = A;
    sort(copy.begin(), copy.end(), compareFunc);
    
    vector<Interval> out;
    out.push_back(copy[0]);
    
    for (int i = 1; i < copy.size(); ++i) {
        if (copy[i].start > out[out.size() - 1].end) {
            out.push_back(copy[i]);
        } else if (copy[i].end > out[out.size() - 1].end) {
            out[out.size() - 1].end = copy[i].end;
        }
    }
    
    return out;
}