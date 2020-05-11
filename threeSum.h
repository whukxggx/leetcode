//15. 三数之和
#include"head.h"

//排序之后左右双指针，注意三个数可能的排除重复元素，
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<int> nums_aux = nums;
    int size = nums_aux.size();
    vector<vector<int>> vec;
    if (size < 3)return vec;

    sort(nums_aux.begin(), nums_aux.end());
    if (nums_aux[0] > 0)return vec;
    for (int i = 0; i < size && nums_aux[i] <= 0; ++i) {
        int t = nums_aux[i];
        if (i >= 1 && nums_aux[i] == nums_aux[i - 1])continue;
        int L = i + 1;
        int R = size - 1;
        while (L < R) {
            if (t + nums_aux[L] + nums_aux[R] == 0) {
                vector<int> tmp{ t,nums_aux[L],nums_aux[R] };
                vec.push_back(tmp);
                while (L<R&&nums_aux[L + 1] == nums_aux[L])L++;
                while (L<R&&nums_aux[R - 1] == nums_aux[R])R--;
                L++; R--;
            }
            else if (t + nums_aux[L] + nums_aux[R] > 0) {
                R--;
            }
            else {
                L++;
            }
        }
    }
    return vec;
}
};