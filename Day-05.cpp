/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Jane Street-medium
customize pair 
*/
#include<bits/stdc++.h>
using namespace std;
using ll =long long;
class CustomPair{
  public:
  int x;
  int y;
  CustomPair(int a, int b)
  {
    x=a;
    y=b;
  }
  int car(CustomPair p)
  {
    return p.x;
  }
  int cad(CustomPair p)
  {
    return p.y;
  }
};
int main(){
  int a,b;
  cout<<"enter 2 integers to make a pair : ";
  cin>>a>>b;
  CustomPair obj(a,b);
  cout << obj.car(obj) << ":"<< obj.cad(obj);

  return 0;
}