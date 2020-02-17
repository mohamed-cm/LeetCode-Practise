//
//  main.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include <iostream>
#include <queue>
#include <limits.h>

#include "_509_斐波那契数.hpp"
#include "_21_合并两个有序链表.hpp"
#include "_23_合并K个排序链表.hpp"
#include "_150_逆波兰表达式求值.hpp"
#include "_98_验证二叉搜索树.hpp"
#include "_124_二叉树中的最大路径和.hpp"
#include "_114_二叉树展开为链表.hpp"
#include "_198_打家劫舍.hpp"
#include "_36_有效的数独.hpp"
#include "_347_前K个高频元素.hpp"
#include "_237_删除链表中的节点.hpp"
#include "_206_反转链表.hpp"
#include "_88_合并两个有序数组.hpp"
#include "_141_环形链表.hpp"
#include "_203_移除链表元素.hpp"
#include "_83_删除排序链表中的重复元素.hpp"
#include "_876_链表的中间结点.hpp"
#include "_20_有效的括号.hpp"
#include "_856_括号的分数.hpp"
#include "_225_用队列实现栈.hpp"
#include "_232_用栈实现队列.hpp"
#include "_224_基本计算器.hpp"
#include "_226_翻转二叉树.hpp"
#include "_144_二叉树的前序遍历.hpp"
#include "_94_二叉树的中序遍历.hpp"
#include "_145_二叉树的后序遍历.hpp"
#include "_102_二叉树的层次遍历.hpp"
#include "_104_二叉树的最大深度.hpp"
#include "_105_从前序与中序遍历序列构造二叉树.hpp"
#include "_106_从中序与后序遍历序列构造二叉树.hpp"
#include "_889_根据前序和后序遍历构造二叉树.hpp"
#include "_101_对称二叉树.hpp"
#include "_450_删除二叉搜索树中的节点.hpp"
#include "_700_二叉搜索树中的搜索.hpp"
#include "_530_二叉搜索树的最小绝对差.hpp"
#include "_783_二叉搜索树结点最小距离.hpp"
#include "_701_二叉搜索树中的插入操作.hpp"
#include "_108_将有序数组转换为二叉搜索树.hpp"
#include "_938_二叉搜索树的范围和.hpp"
#include "_235_二叉搜索树的最近公共祖先.hpp"
#include "_230_二叉搜索树中第K小的元素.hpp"

using namespace std;

#pragma mark - 数组

/// 509-斐波那契数
void test_509() {
    /**
     输入：2
     输出：1
     解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
     
     输入：3
     输出：2
     解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
     
     输入：4
     输出：3
     解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
     */
    _509_斐波那契数 solution = _509_斐波那契数();
    cout << solution.fib(0) << endl;
    cout << solution.fib(1) << endl;
    cout << solution.fib(2) << endl;
    cout << solution.fib(3) << endl;
    cout << solution.fib(4) << endl;
    cout << solution.fib(5) << endl;
    cout << solution.fib(6) << endl;
    cout << solution.fib(7) << endl;
}

/// 88-合并两个有序数组
void test_88() {
    /**
     输入:
     nums1 = [1,2,3,0,0,0], m = 3
     nums2 = [2,5,6],       n = 3

     输出: [1,2,2,3,5,6]
     */
    _88_合并两个有序数组 solution = _88_合并两个有序数组();
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    for (int num: nums1) {
        cout << num << " ";
    }
    cout << endl;

    nums1 = {1, 2, 4, 5, 6, 0};
    nums2 = {3};
    solution.merge(nums1, 5, nums2, 1);
    for (int num: nums1) {
        cout << num << " ";
    }
    cout << endl;

    nums1 = {2, 0};
    nums2 = {1};
    solution.merge(nums1, 1, nums2, 1);
    for (int num: nums1) {
        cout << num << " ";
    }
    cout << endl;
}

#pragma mark - 链表

ListNode* creatNodeList(vector<int> nodes) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int node:nodes) {
        p->next = new ListNode(node);
        p = p->next;
    }
    return head->next;
}

void printNodeList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        node = node->next;
        if (node != nullptr) {
            cout << "->";
        }
    }
    cout << endl;
}

/// 21-合并两个有序链表
void test_21() {
    // 1->2->4, 1->3->4
    ListNode* node1 = creatNodeList({1, 2, 4});
    ListNode* node2 = creatNodeList({1, 3, 4});

    _21_合并两个有序链表 solution = _21_合并两个有序链表();
    ListNode *result = solution.mergeTwoLists(node1, node2);
    printNodeList(result);
}

/// 23-合并K个有序链表
void test_23() {
    /**
     [
        1->4->5,
        1->3->4,
        2->6
     ]
     */
    ListNode *node1 = creatNodeList({1, 4, 5});
    ListNode *node2 = creatNodeList({1, 3, 4});
    ListNode *node3 = creatNodeList({2, 6});
    
    _23_合并K个排序链表 solution = _23_合并K个排序链表();
    vector<ListNode *> tokens = {node1, node2, node3};
    ListNode *result = solution.mergeKLists(tokens);
    printNodeList(result);
}

/// 237-删除链表中的节点
void test_237() {
    /**
     输入: head = [4,5,1,9], node = 5
     输出: [4,1,9]
     解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

     输入: head = [4,5,1,9], node = 1
     输出: [4,5,9]
     解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
     */

    ListNode *node1 = creatNodeList({4, 5, 1, 9});
    _237_删除链表中的节点 solution = _237_删除链表中的节点();
//    solution.deleteNode(node1->next);
    solution.deleteNode(node1->next->next);
    printNodeList(node1);
}

/// 206-反转链表
void test_206() {
    /**
     输入: 1->2->3->4->5->NULL
     输出: 5->4->3->2->1->NULL
     */
//    ListNode *node1 = creatNodeList({1, 2, 3, 4, 5});
    ListNode *node1 = creatNodeList({5, 4, 3, 2, 1});
    _206_反转链表 solution = _206_反转链表();
    node1 = solution.reverseList(node1);
    printNodeList(node1);
}

/// 141-环形链表
void test_141() {
    /**
     输入：head = [3,2,0,-4], pos = 1
     输出：true
     解释：链表中有一个环，其尾部连接到第二个节点。
     
     输入：head = [1,2], pos = 0
     输出：true
     解释：链表中有一个环，其尾部连接到第一个节点。
     
     输入：head = [1], pos = -1
     输出：false
     解释：链表中没有环。
     */
    ListNode* node1 = creatNodeList({3, 2, 0, -4});
    node1->next->next->next->next = node1->next;
//    ListNode* node1 = creatNodeList({1, 2});
//    node1->next->next = node1;
//    ListNode* node1 = creatNodeList({1});
    _141_环形链表 solution = _141_环形链表();
    cout << solution.hasCycle(node1) << endl;
}

/// 203-移除链表元素
void test_203() {
    /**
     输入: 1->2->6->3->4->5->6, val = 6
     输出: 1->2->3->4->5
     */
    ListNode *node1 = creatNodeList({1, 2, 6, 3, 4, 5, 6});
    _203_移除链表元素 solution = _203_移除链表元素();
    node1 = solution.removeElements(node1, 6);
    printNodeList(node1);
}

/// 83-删除排序链表中的重复元素
void test_83() {
    /**
     示例 1:
     输入: 1->1->2
     输出: 1->2
     
     示例 2:
     输入: 1->1->2->3->3
     输出: 1->2->3
     */
    ListNode *node1 = creatNodeList({1, 1, 2, 3, 3});
    _83_删除排序链表中的重复元素 solution = _83_删除排序链表中的重复元素();
    node1 = solution.deleteDuplicates(node1);
    printNodeList(node1);
}

/// 876-链表的中间结点
void test_876() {
    /**
     输入：[1,2,3,4,5]
     输出：此列表中的结点 3 (序列化形式：[3,4,5])
     返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
     注意，我们返回了一个 ListNode 类型的对象 ans，这样：
     ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

     输入：[1,2,3,4,5,6]
     输出：此列表中的结点 4 (序列化形式：[4,5,6])
     由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
     */
    ListNode *node1 = creatNodeList({1, 2, 3, 4, 5, 6});
    _876_链表的中间结点 solution = _876_链表的中间结点();
    cout << solution.middleNode(node1)->val << endl;
}

#pragma mark - 栈

/// 150-逆波兰表达式求值
void test_150() {
//    vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    _150_逆波兰表达式求值 solution = _150_逆波兰表达式求值();
    cout << solution.evalRPN(tokens) << endl;
}

/// 20-有效的括号
void test_20() {
    /**
     输入: "()"
     输出: true
     
     输入: "()[]{}"
     输出: true
     
     输入: "(]"
     输出: false
     
     输入: "([)]"
     输出: false
     
     输入: "{[]}"
     输出: true
     */
    _20_有效的括号 solution = _20_有效的括号();
    cout << solution.isValid("{[]}") << endl;
}

/// 856-括号的分数
void test_856() {
    /**
     () 得 1 分。
     AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
     (A) 得 2 * A 分，其中 A 是平衡括号字符串。
     
     输入： "()"
     输出： 1
     
     输入： "(())"
     输出： 2
     
     输入： "()()"
     输出： 2
     
     输入： "(()(()))"
     输出： 6
     */
    _856_括号的分数 solution = _856_括号的分数();
    cout << solution.scoreOfParentheses("(()(()))") << endl;
}

/// 225-用队列实现栈
void test_225() {
    /**
     MyStack* obj = new MyStack();
     obj->push(x);
     int param_2 = obj->pop();
     int param_3 = obj->top();
     bool param_4 = obj->empty();
     */
    _225_用队列实现栈* obj = new _225_用队列实现栈();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
    delete obj;
}

/// 232-用栈实现队列
void test_232() {
    /**
     MyQueue* obj = new MyQueue();
     obj->push(x);
     int param_2 = obj->pop();
     int param_3 = obj->peek();
     bool param_4 = obj->empty();
     */
    _232_用栈实现队列* obj = new _232_用栈实现队列();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
    delete obj;
}

/// 224-基本计算器
void test_224() {
    /**
     输入: "1 + 1"
     输出: 2
     
     输入: " 2-1 + 2 "
     输出: 3
     
     输入: "(1+(4+5+2)-3)+(6+8)"
     输出: 23
     
     输入: "2-(5-6)"
     输出: 3
     */
    _224_基本计算器* obj = new _224_基本计算器();
    cout << obj->calculate("1 + 1") << endl;
    cout << obj->calculate(" 2-1 + 2 ") << endl;
    cout << obj->calculate("(1+(4+5+2)-3+(6+8)") << endl;
    cout << obj->calculate("2-(5-6)") << endl;
    delete obj;
}

#pragma mark - 二叉树

/// 创建二叉搜索树
TreeNode* generateBinaryTree(vector<int> trees) {
    if (trees.size() == 0) return nullptr;
    TreeNode *root = new TreeNode(trees[0]);
    for (int i = 1; i < trees.size(); i++) {
        int value = trees[i];
        TreeNode *parent = root;
        TreeNode *node = root;
        do {
            parent = node;
            if (value < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        } while (node != nullptr);
        
        if (value < parent->val) {
            parent->left = new TreeNode(value);
        } else {
            parent->right = new TreeNode(value);
        }
    }
    return root;
}

/// 按照层序遍历生成二叉树
TreeNode* generateTreeByLevel(vector<int> trees) {
    if (trees.size() == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(trees[0]);
    queue<TreeNode*> q;
    q.push(root);
    bool isLeft = true;
    for (int i = 1; i < trees.size(); i++) {
        TreeNode *parent = q.front();
        if (trees[i] != INT_MAX) {
            TreeNode *child = new TreeNode(trees[i]);
            if (isLeft) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            q.push(child);
        }
        if (!isLeft) {
            q.pop();
        }
        
        isLeft = !isLeft;
    }
    return root;
}

/// 98-验证二叉搜索树
void test_98() {
    TreeNode* root = generateBinaryTree({2, 1, 3});
    _98_验证二叉搜索树 solution = _98_验证二叉搜索树();
    cout << solution.isValidBST(root) << endl;
}

/// 114-二叉树展开为链表
void test_114() {
    /**
    输入：
           1
           / \
          2   5
          / \    \
         3   4    6
    输出：
      1
       \
        2
         \
          3
           \
            4
             \
              5
               \
                6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    _114_二叉树展开为链表 solution = _114_二叉树展开为链表();
    solution.flatten(root);
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

/// 124-二叉树中的最大路径和
void test_124() {
//    TreeNode* root = new TreeNode(-10);
//    root->left = new TreeNode(9);
//    TreeNode *right = new TreeNode(20);
//    root->right = right;
//    right->left = new TreeNode(15);
//    right->right = new TreeNode(7);
    
//    TreeNode* root = new TreeNode(3);
//    root->left = new TreeNode(-1);
//    root->right = new TreeNode(-1);
    
    TreeNode* root = generateBinaryTree({10, 9, 20, 15, 35});
    
    _124_二叉树中的最大路径和 solution = _124_二叉树中的最大路径和();
    cout << solution.maxPathSum(root) << endl;
}

/// 226-翻转二叉树
void test_226() {
    /**
     输入：

          4
        /   \
       2     7
      / \   / \
     1   3 6   9
     输出：

          4
        /   \
       7     2
      / \   / \
     9   6 3   1
     */
    TreeNode* root = generateBinaryTree({4,2,1,3,7,6,9});
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    _226_翻转二叉树 solution = _226_翻转二叉树();
    root = solution.invertTree(root);
}

/// 144-二叉树的前序遍历
void test_144() {
    /**
     输入: [1,null,2,3]
        1
         \
          2
         /
        3

     输出: [1,2,3]
     */
    TreeNode* root = generateTreeByLevel({1, INT_MAX, 2, 3});
    _144_二叉树的前序遍历* solution = new _144_二叉树的前序遍历();
    vector<int> result = solution->preorderTraversal(root);
    for (auto n:result) {
        cout << n << " ";
    }
    cout << endl;
}

/// 94-二叉树的终须遍历
void test_94() {
    /**
     输入: [1,null,2,3]
        1
         \
          2
         /
        3

     输出: [1,3,2]
     */
    TreeNode* root = generateTreeByLevel({1, INT_MAX, 2, 3});
    _94_二叉树的中序遍历* solution = new _94_二叉树的中序遍历();
    vector<int> result = solution->inorderTraversal(root);
    for (auto n:result) {
        cout << n << " ";
    }
    cout << endl;
}

/// 145-二叉树的后序遍历
void test_145() {
    /**
     输入: [1,null,2,3]
        1
         \
          2
         /
        3

     输出: [3,2,1]
     */
    TreeNode* root = generateTreeByLevel({1, INT_MAX, 2, 3});
    _145_二叉树的后序遍历* solution = new _145_二叉树的后序遍历();
    vector<int> result = solution->postorderTraversal(root);
    for (auto n:result) {
        cout << n << " ";
    }
    cout << endl;

}

/// 102-二叉树的层次遍历
void test_102() {
    /**
     给定二叉树: [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    返回其层次遍历结果：

    [
      [3],
      [9,20],
      [15,7]
    ]
     */
    TreeNode* root = generateTreeByLevel({3, 9, 20, INT_MAX, INT_MAX, 15, 7});
//    TreeNode* root;
    _102_二叉树的层次遍历* solution = new _102_二叉树的层次遍历();
    vector<vector<int>> result = solution->levelOrder(root);
    cout << "[\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "\t[";
        for (int j = 0; j < result[i].size() - 1; j++) {
            cout << result[i][j] << ",";
        }
        cout << result[i][result[i].size() - 1];
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

/// 104-二叉树的最大深度
void test_104() {
    /**
     示例：
     给定二叉树 [3,9,20,null,null,15,7]，

         3
        / \
       9  20
         /  \
        15   7
     返回它的最大深度 3
     */
    TreeNode* root = generateTreeByLevel({3, 9, 20, INT_MAX, INT_MAX, 15, 7});
    _104_二叉树的最大深度* solution = new _104_二叉树的最大深度();
    cout << solution->maxDepth(root) << endl;
}

/// 105-从前序与中序遍历序列构造二叉树
void test_105() {
    /**
     例如，给出
     
     前序遍历 preorder = [3,9,20,15,7]
     中序遍历 inorder = [9,3,15,20,7]
     返回如下的二叉树：

            3
           / \
          9  20
            /  \
           15   7
     */
    _105_从前序与中序遍历序列构造二叉树* solution = new _105_从前序与中序遍历序列构造二叉树();
    vector<int> preorder = {3, 9, 2, 20, 15, 7};
    vector<int> inorder = {9, 2, 3, 15, 20, 7};
    TreeNode* root = solution->buildTree(preorder, inorder);
    cout << root->val << endl;
}

/// 106-从中序与后序遍历序列构造二叉树
void test_106() {
    /**
     例如，给出

     中序遍历 inorder = [9,3,15,20,7]
     后序遍历 postorder = [9,15,7,20,3]
     返回如下的二叉树：

            3
           / \
          9  20
            /  \
           15   7
     */
    _106_从中序与后序遍历序列构造二叉树* solution = new _106_从中序与后序遍历序列构造二叉树();
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = solution->buildTree(inorder, postorder);
    cout << root->val << endl;
}

/// 889-根据前序和后序遍历构造二叉树
void test_889() {
    /**
     输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
     输出：[1,2,3,4,5,6,7]
     */
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    _889_根据前序和后序遍历构造二叉树* solution = new _889_根据前序和后序遍历构造二叉树();
    TreeNode* root = solution->constructFromPrePost(preorder, postorder);
    cout << root->val << endl;
}

/// 101-对称二叉树
void test_101() {
    /**
     例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

         1
        / \
       2   2
      / \ / \
     3  4 4  3
     但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

         1
        / \
       2   2
        \   \
        3    3
     */
    vector<int> levels = {1, 2, 2, 3, 4, 4, 3};
//    vector<int> levels = {1, 2, 2, INT_MAX, 3, INT_MAX, 3};
    TreeNode* root = generateTreeByLevel(levels);
    _101_对称二叉树* solution = new _101_对称二叉树();
    cout << solution->isSymmetric(root) << endl;
}

/// 450-删除二叉搜索树中的节点
void test_450() {
    /**
     root = [5,3,6,2,4,null,7]
     key = 3

         5
        / \
       3   6
      / \   \
     2   4   7

     给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

     一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

         5
        / \
       4   6
      /     \
     2       7

     另一个正确答案是 [5,2,6,null,4,null,7]。

         5
        / \
       2   6
        \   \
         4   7
     */
    vector<int> nodes = {5, 3, 6, 2, 4, INT_MAX, 7};
    TreeNode* root = generateTreeByLevel(nodes);
    _450_删除二叉搜索树中的节点* solution = new _450_删除二叉搜索树中的节点();
    root = solution->deleteNode(root, 3);
}

/// 700-二叉搜索树中的搜索
void test_700() {
    /**
     给定二叉搜索树:

             4
            / \
           2   7
          / \
         1   3

     和值: 2
     */
    vector<int> nodes = {4, 2, 7, 1, 3};
    TreeNode* root = generateTreeByLevel(nodes);
    _700_二叉搜索树中的搜索* solution = new _700_二叉搜索树中的搜索();
    root = solution->searchBST(root, 5);
    if (root) {
        cout << root->val << endl;
    } else {
        cout << endl;
    }
}

/// 530-二叉搜索树的最小绝对差
void test_530() {
    /**
     输入:

        1
         \
          3
         /
        2

     输出:
     1
     */
//    vector<int> nodes = {5, INT_MAX, 10, 13};
//    vector<int> nodes = {236, 104, 701, INT_MAX, 227, INT_MAX, 911};
    vector<int> nodes = {0, INT_MAX, 2236, 1277, 2776, 519};
    TreeNode* root = generateTreeByLevel(nodes);
    _530_二叉搜索树的最小绝对差* solution = new _530_二叉搜索树的最小绝对差();
    cout << solution->getMinimumDifference(root) << endl;
}

/// 783-二叉搜索树结点最小距离
void test_783() {
    /**
     输入: root = [4,2,6,1,3,null,null]
     输出: 1
     解释:
     注意，root是树结点对象(TreeNode object)，而不是数组。

     给定的树 [4,2,6,1,3,null,null] 可表示为下图:

               4
             /   \
           2      6
          / \
         1   3

     最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
     */
    vector<int> nodes = {4, 2, 6, 1, 3};
    TreeNode* root = generateTreeByLevel(nodes);
    _783_二叉搜索树结点最小距离* solution = new _783_二叉搜索树结点最小距离();
    cout << solution->minDiffInBST(root) << endl;
}


/// 701-二叉搜索树中的插入操作
void test_701() {
    /**
     给定二叉搜索树:

             4
            / \
           2   7
          / \
         1   3

     和 插入的值: 5
     你可以返回这个二叉搜索树:

              4
            /   \
           2     7
          / \   /
         1   3 5
     或者这个树也是有效的:

              5
            /   \
           2     7
          / \
         1   3
              \
               4
     */
    vector<int> nodes = {4, 2, 7, 1, 3};
    TreeNode* root = generateTreeByLevel(nodes);
    _701_二叉搜索树中的插入操作* solution = new _701_二叉搜索树中的插入操作();
    root = solution->insertIntoBST(root, 5);
    cout << endl;
}

/// 108-将有序数组转换为二叉搜索树
void test_108() {
//    _108_将有序数组转换为二叉搜索树
    /**
     给定有序数组: [-10,-3,0,5,9],

     一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

           0
          / \
        -3   9
        /   /
      -10  5
     */
    _108_将有序数组转换为二叉搜索树* solution = new _108_将有序数组转换为二叉搜索树();
    vector<int> nodes = {-10, -3, 0, 5, 9};
    TreeNode* root = solution->sortedArrayToBST(nodes);
    cout << root->val << endl;
}

/// 938-二叉搜索树的范围和
void test_938() {
    /**
     示例 1：

     输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
     输出：32
     示例 2：

     输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
     输出：23
     */
    
    _938_二叉搜索树的范围和* solution = new _938_二叉搜索树的范围和();
    vector<int> nodes = {10, 5, 15, 3, 7, 13, 18, 1, INT_MAX, 6};
    TreeNode* root = generateTreeByLevel(nodes);
    cout << solution->rangeSumBST(root, 6, 10) << endl;

}

/// 235-二叉搜索树的最近公共祖先
void test_235() {
    /**
     示例 1:

     输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
     输出: 6
     解释: 节点 2 和节点 8 的最近公共祖先是 6。
     示例 2:

     输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
     输出: 2
     解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身
     */
    vector<int> nodes = {6, 2, 8, 0, 4, 7, 9, INT_MAX, INT_MAX, 3, 5};
    TreeNode *root = generateTreeByLevel(nodes);
    _235_二叉搜索树的最近公共祖先 solution = _235_二叉搜索树的最近公共祖先();
    TreeNode *p = new TreeNode(7);
    TreeNode *q = new TreeNode(9);
    TreeNode *node = solution.lowestCommonAncestor(root, p, q);
    cout << node->val << endl;
}

/// 230-二叉搜索树中第K小的元素
void test_230() {
    /**
     输入: root = [3,1,4,null,2], k = 1
        3
       / \
      1   4
       \
        2
     输出: 1
     示例 2:

     输入: root = [5,3,6,2,4,null,null,1], k = 3
            5
           / \
          3   6
         / \
        2   4
       /
      1
     输出: 3
     */
    vector<int> nodes = {5, 3, 6, 2, 4, INT_MAX, INT_MAX, 1};
    TreeNode *root = generateTreeByLevel(nodes);
    _230_二叉搜索树中第K小的元素 solution = _230_二叉搜索树中第K小的元素();
    cout << solution.kthSmallest(root, 3) << endl;
}

#pragma mark - 动态规划

/// 198-打家劫舍
void test_198() {
    /**
     输入: [1,2,3,1]
     输出: 4
     
     输入: [2,7,9,3,1]
     输出: 12
     */
    _198_打家劫舍 solution = _198_打家劫舍();
//    vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << solution.rob(nums) << endl;
}

#pragma mark - 哈希

/// 36-有效的数独
void test_36() {
    /**
    输入:
    [
      ["5","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: true

    输入:
    [
      ["8","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: false
    */
    _36_有效的数独 solution = _36_有效的数独();
//    vector<vector<char>> board = {
//        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
//    };
    vector<vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    cout << solution.isValidSudoku(board) << endl;

}

#pragma mark - 堆

/// 347-前K个高频元素
void test_347() {
    /**
     输入: nums = [1,1,1,2,2,3], k = 2
     输出: [1,2]
     
     输入: nums = [1], k = 1
     输出: [1]
     */
//    vector<int> nums = {1, 1, 1, 2, 2, 3};
//    vector<int> nums = {1};
    vector<int> nums = {3, 1, 2, 1, 3, 2, 1, 3};

    _347_前K个高频元素 solution = _347_前K个高频元素();
    vector<int> result = solution.topKFrequent(nums, 2);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}

#pragma mark - Test

int main(int argc, const char * argv[]) {
    // insert code here...
//    cout << "Hello, World!\n";
    
    test_230();

    return 0;
}
