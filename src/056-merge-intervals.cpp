//
// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged{};

        for (vector<int> &interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<int> x = {1, 2, 3};

    auto res = (new Solution)->merge(intervals);

    assert_equal(res, vector<vector<int>>({{1, 6}, {8, 10}, {15, 18}}));

    return 0;
}
