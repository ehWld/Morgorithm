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
var Q: Int
var nemo = [Int]()

func lowerBound(_ target: Int) -> Int {
    var left = 0
    var right = N-1

    while left < right {
        let mid: Int = Int(ceil(Double(left + right)/2.0))
        if nemo[mid] >= target {
            left = mid
        }
        else { right = mid - 1 }
    }
    return left
}

var input = readInt()
N = input[0]
Q = input[1]

input = readInt()
input.forEach {
    nemo.append($0)
}

while Q > 0 {
    Q -= 1
    var ans = 0
    input = readInt()
    let x = input[0]
    let y = input[1]

    ans += max(nemo[y-1] - x + 1, 0)
    ans += max(lowerBound(x)+1 - y, 0)
    print(ans)
}

