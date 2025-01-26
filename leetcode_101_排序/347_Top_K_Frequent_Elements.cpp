#include "m.h"

class Solution 
{
public:
    // 定义排序函数，根据频率排序
    static bool compare(pair<int, int> a, pair<int, int> b) 
    {
        return a.second > b.second;  // 频率高的排在前面
    }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // 创建哈希表统计每个数字的频率
        unordered_map<int, int> h;
        for (int num : nums) 
        {
            h[num]++;
        }
        // 将unordered_map转换为vector<pair<int, int>>，用于排序
        vector<pair<int, int>> freqVec(h.begin(), h.end());
        // 根据频率进行排序
        sort(freqVec.begin(), freqVec.end(), compare);
        // 获取频率前 k 高的元素
        vector<int> res;
        for (int i = 0; i < k; ++i) 
        {
            res.push_back(freqVec[i].first);  // 将频率前k高的元素加入结果
        }
        return res;
    }
};

//下面这种方法无需排序，实现了O(N)的时间复杂度
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> counts;
        // 统计每个数字的频率
        for (int num : nums) 
        {
            ++counts[num];
        }
        // 创建桶：按频率分组
        unordered_map<int, vector<int>> buckets;
        for (auto [num, count] : counts) 
        {
            buckets[count].push_back(num);
        }
        // 存放结果的向量
        vector<int> top_k;
        // 从高频到低频遍历桶（最高频也就是数组长度了）
        for (int count = nums.size(); count >= 1; --count) 
        {
            if (buckets.find(count) != buckets.end()) 
            {
                // 遍历当前频率的桶
                for (int num : buckets[count]) 
                {
                    top_k.push_back(num);
                    if (top_k.size() == k) 
                    {
                        return top_k;  // 如果已经找到了前 k 个元素，返回结果
                    }
                }
            }
        }
        return top_k;
    }
};