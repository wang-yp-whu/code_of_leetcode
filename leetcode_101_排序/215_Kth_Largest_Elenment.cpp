#include "m.h"

class Solution 
{
private:
    vector<int> h = vector<int> (200001, 0);
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int len = nums.size();
        int sum = 0;
        if(len == 1)
        {
            return nums[0];
        }
        for(int i = 0;i < len;i++)
        {
            h[nums[i] + 10000]++;
        }
        for(int i = 200001;i >= 0;i--)
        {
            if(h[i] > 0)
            {
                sum += h[i];
            }
            if(sum >= k)
            {
                return i - 10000;
            }
        }
        return 0;
    }
};

//其实这种叫做桶排序思想
//下面是基于快排的快速选择算法

class Solution 
{
public:
    int quickselect(vector<int> &nums, int l, int r, int k) 
    {
        if (l == r)
        {
            return nums[k];//此时已经无法再继续下去，也就是找到了我们需要的那一个元素
        }    
        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) 
        {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }
        //i == j，到达了下一次分界的起点
        if (k <= j)
        {
            return quickselect(nums, l, j, k);//每一次都进入序号K所在的那个地方进行递归，无需像qsort一样
        }
        else 
        {
            return quickselect(nums, j + 1, r, k);
        }
    }

    int findKthLargest(vector<int> &nums, int k) 
    {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
};