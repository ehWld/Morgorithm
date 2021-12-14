//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

var N = 0
var K = 0
var belt = [Int]()

func solve() {
    var input = readInt()
    N = input[0]
    K = input[1]

    input = readInt()
    for i in input {
        belt.append(i)
    }

    var count = 0
    var ans = 1
    while count < K {

        ans += 1
    }
}
