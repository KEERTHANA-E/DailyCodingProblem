/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
GOOGLE-
level wise traversal to seralise and deseralise
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    string ans = "";
    if (root == NULL)
    {
      return "";
    }
    queue<TreeNode *> q;
    q.push(root);
    ans += to_string(root->val);
    ans += ',';
    while (!q.empty())
    {
      // cout<<ans<<"\n";
      int sz = q.size();

      for (int i = 0; i < sz; i++)
      {
        TreeNode *t = q.front();
        q.pop();
        if (t->left != NULL)
        {
          q.push(t->left);
          // cout<<q.front()<<":";
          ans += to_string(t->left->val) + ',';
        }
        else
        {
          ans += "#,";
        }
        if (t->right != NULL)
        {
          q.push(t->right);
          // cout<<q.front()<<":";
          ans += to_string(t->right->val) + ',';
        }
        else
        {
          ans += "#,";
        }
      }
    }

    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data == "")
    {
      return NULL;
    }
    stringstream s(data);
    string ss;
    getline(s, ss, ',');

    TreeNode *root = new TreeNode(stoi(ss));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

      TreeNode *t = q.front();
      q.pop();

      getline(s, ss, ',');

      if (ss == "#")
      {
        t->left = NULL;
      }
      else
      {
        TreeNode *x = new TreeNode(stoi(ss));
        t->left = x;
        q.push(t->left);
      }

      getline(s, ss, ',');

      if (ss == "#")
      {
        t->right = NULL;
      }
      else
      {
        TreeNode *x = new TreeNode(stoi(ss));
        t->right = x;
        q.push(t->right);
      }
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));