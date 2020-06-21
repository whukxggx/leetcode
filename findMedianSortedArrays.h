#include "head.h"

//4. 寻找两个正序数组的中位数
//时间复杂度O(log(m+n))
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2)
        {
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
            swap(size1, size2);
        }
        int imin = 0, imax = size1;
        int half = (size1 + size2 + 1) / 2;
        while (imin <= imax)
        {
            int i = (imin + imax) / 2;
            int j = half - i;
            if (i > imin && nums1[i - 1] > nums2[j])
            {
                imax = i - 1;
            }
            else if (i < imax && nums2[j - 1] > nums1[i])
            {
                imin = i + 1;
            }
            else
            {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j - 1];
                else if (j == 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);

                if ((size1 + size2) % 2 == 1)
                    return maxLeft;
                int minRight = 0;
                if (i == size1)
                    minRight = nums2[j];
                else if (j == size2)
                    minRight = nums1[i];
                else
                    minRight = min(nums1[i], nums2[j]);
                return (minRight + maxLeft) / 2.0;
            }
        }
        return 0.0;
    }
};n