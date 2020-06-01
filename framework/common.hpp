#ifndef _COMMON_H_
#define _COMMON_H_
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <algorithm>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

ListNode *genList(std::initializer_list<int> vals)
{
    auto dumy_head = new ListNode(0);
    auto p = dumy_head;
    for(auto i = vals.begin(); i != vals.end(); ++i){
        p->next = new ListNode(*i);
        p = p->next;
    }
    return dumy_head->next;
}

bool equalList(ListNode *l1, ListNode *l2)
{
    while(l1 && l2){
        if(l1->val != l2->val)
            return false;
        l1 = l1->next, l2 = l2->next;
    }
    return (l1 || l2)? false: true;
}

void printList(ListNode *l)
{ 
    cout << '[';
    while(l){
        cout << l->val << ", ";
        l = l -> next;
    }
    cout << ']' << endl;
}

TreeNode* gen_tree(vector<int> input, TreeNode *node, int i, int n)
{
    if (i >= n || input[i] == INT_MIN)
        return nullptr;
    node = new TreeNode(input[i]);
    node->left = gen_tree(input, node->left, 2 * i + 1, n);
    node->right = gen_tree(input, node->right, 2 * i + 2, n);
    return node;
}

TreeNode* gen_binary_tree(vector<int> input)
{
    if (input.empty())
        return nullptr;
    TreeNode *root = nullptr;
    return gen_tree(input, root, 0, input.size() - 1);
}

TreeNode* gen_b_tree(vector<int> input)
{
    if (input.empty())
        return nullptr;
    TreeNode *root = nullptr;
    return gen_tree(input, root, 0, input.size() - 1);
}

void preorder(TreeNode* root, vector<int>& result)
{
    if (root == nullptr)
        return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

void inorder(TreeNode* root, vector<int>& result) 
{
    if (root == nullptr)
        return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

void print_json()
{
    json j = "{\"x\":[null,3,7,true,9,true,15,false,20,false]}"_json;
    cout << j["x"].size() << endl;
    string s = j.dump();
    cout << s << endl;
}
#endif //_COMMON_H_
