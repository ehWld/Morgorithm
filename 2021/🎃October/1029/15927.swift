//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

let input = Array(readStr()[0])
let N = input.count

var left = 0
var right = N-1

var allFlag = true
for i in 0..<N {
    if input.first != input[i] {
        allFlag = false
        break
    }
}

while left < right {
    if input[left] != input[right] { break }
    left += 1
    right -= 1
}

if allFlag == true { print(-1) }
else if left >= right { print(N-1) }
else { print(N) }
