#include "m.h"

//一种非常妙的思路，真正意义上的反其道而行之
//从末尾开始合并两个升序数组，这样不会申请多余空间
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m - 1, j = n - 1;
        int p = m + n - 1;
        while(p >= 0)
        {
            if(i < 0)
            {
                nums1[p--] = nums2[j--];
            }
            else if(j < 0)
            {
                nums1[p--] = nums1[i--];
            }
            else
            {
                if(nums1[i] < nums2[j])
                {
                    nums1[p--] = nums2[j--];
                }
                else
                {
                    nums1[p--] = nums1[i--];
                }
            }
        }
    }
};