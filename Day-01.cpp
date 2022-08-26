/*
leetCoode-https://leetcode.com/problems/two-sum/submissions/
GOOGLE
hashmap approach
*/
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int i, k;
    map<int, vector<int>> mp;
    for (i = 0; i < nums.size(); i++)
    {
      mp[nums[i]].push_back(i);
    }
    for (i = 0; i < nums.size(); i++)
    {
      if (mp.find(target - nums[i]) != mp.end())
      {
        if (nums[i] == target - nums[i])
        {
          if (mp[nums[i]].size() > 1)
          {
            k = mp[nums[i]][1];
            break;
          }
        }
        else
        {
          k = mp[target - nums[i]][0];
          break;
        }
      }
    }
    return {i, k};
  }
};