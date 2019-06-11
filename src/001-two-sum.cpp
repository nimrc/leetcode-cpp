#include <leetcode.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];
            if (map[need])
                return vector<int>{map[need] - 1, i};

            map[nums[i]] = i + 1;
        }

        return vector<int>{};
    }
};

int main(int argc, char **argv)
{
    vector<int> nums = {2, 7, 11, 15};

    vector<int> res = (new Solution)->twoSum(nums, 9);

    assert(res.size() == 2);
    assert(res[0] == 0);
    assert(res[1] == 1);

    return 0;
}
