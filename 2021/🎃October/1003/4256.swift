//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

var T = readInt()[0]
var n = 0, top = 0
var preorder = [Int]()
var inorder = [Int]()

func divide(left: Int, right: Int) {
    if left > right { return }

    if left == right {
        print("\(inorder[left]) ", terminator: "")
        top += 1
        return
    }

    for i in left...right {
        if inorder[i] != preorder[top] { continue }

        top += 1
        divide(left: left, right: i-1)
        divide(left: i+1, right: right)
        print("\(inorder[i]) ", terminator: "")
        break
    }
}

while T > 0 {
    T -= 1
    n = readInt()[0]
    preorder = readInt()
    inorder = readInt()
    top = 0

    divide(left: 0, right: n-1)
    print(" ")
}
