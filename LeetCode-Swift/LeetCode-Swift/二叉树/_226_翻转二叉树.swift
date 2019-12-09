//
//  _226_翻转二叉树.swift
//  LeetCode-Swift
//
//  Created by warden on 2019/12/7.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/invert-binary-tree/solution/czhan-dui-lie-di-gui-jie-fa-by-jian-han-qu-wan/

import Foundation

class _226_翻转二叉树 {
    func invertTree(_ root: TreeNode?) -> TreeNode? {
        guard let root = root else { return nil }
        
        var arr = [root]
        while !arr.isEmpty {
            let node = arr.removeFirst()
            let tmp = node.left
            node.left = node.right
            node.right = tmp
            if node.left != nil {
                arr.append(node.left!)
            }
            if node.right != nil {
                arr.append(node.right!)
            }
        }
        return root
    }
}
