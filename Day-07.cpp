/*
https://leetcode.com/problems/decode-ways/
Facebook-medium
using bactracking - time limit exceed
optimizing the backtracking logic by storing the possible substring results
memorization dp is used in the problem

we can even slove this problem by simply traversing the array in o(n)space &o(n) time complexity
 start traversing the array from end 
 -if the character is not 0 then we can choose one way of choosing alphabets
 - by using approriate condition like 2 digit number is strictly less than 27 another way of choosing alphabets
 by using these 2 conditions / way of choosing alphabets
 we create an array prefix sum 
 the last element is the possible ways
*/

class Solution {
public:
    map<string, int> mp;
    int backtrack(string s,int idx){
        // safety
        if(idx>=s.size()){
            return 1;
        }
        //base
        if(s[idx]=='0'){
            return 0;
        }
        
        string cur = s.substr(idx, s.length()-idx+1);
        if(mp.count(cur)){
            return mp[cur];
        }
        
        if(s[idx]=='1' && idx+1<s.size()){
           return mp[cur]=backtrack(s,idx+1)+ backtrack(s,idx+2); 
        }
        if(s[idx]=='2' && idx+1<s.size() && s[idx+1]<='6'){
           return mp[cur]=backtrack(s,idx+1)+ backtrack(s,idx+2); 
        }
        return mp[cur]=backtrack(s,idx+1);
    }
    int numDecodings(string s) {
        mp.clear();
        return backtrack(s,0);
    }
};

// second approach
class Solution
{
public:
  int numDecodings(string s)
  {
    int n = s.size();
    vector<int> rs(n + 1, 0);
    rs[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] != '0')
      {
        rs[i] += rs[i + 1];
      }
      if (i + 2 <= n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
      {
        rs[i] += rs[i + 2];
      }
    }
    return rs[0];
  }
};