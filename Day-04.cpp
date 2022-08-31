/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Stripe-hard
insertion sort approach is used to achieve tc - o(n) and space -o(1)

*/
class Solution
{
public:
  int firstMissingPositiveHelper(vector<int> v)
  {
    for (int i = 0; i < v.size(); i++)
    {
      if (abs(v[i]) - 1 < v.size() && v[abs(v[i]) - 1] > 0)
      {
        v[abs(v[i]) - 1] = -v[abs(v[i]) - 1];
      }
    }
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i] > 0)
      {
        return i + 1;
      }
    }
    return v.size() + 1;
  }
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] <= 0)
      {
        int t = nums[i];
        nums[i] = nums[idx];
        nums[idx] = t;
        idx++;
      }
    }
    return firstMissingPositiveHelper(vector<int>(nums.begin() + idx, nums.end()));
  }
};