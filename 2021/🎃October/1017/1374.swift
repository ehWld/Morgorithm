//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

func upperBound(with arr: [Int], _ target: Int) -> Int {
    var left = 0
    var right = arr.count - 1
    var mid = (left + right) / 2

    while left <= right {
        mid = (left + right) / 2
        if arr[mid] > target { right = mid - 1 }
        else { left = mid + 1 }
    }

    return left
}

let N = readInt()[0]
var startTime = [Int]()
var endTime = [Int]()

for _ in 0..<N {
    let input = readInt()
    startTime.append(input[1])
    endTime.append(input[2])
}

startTime.sort()
endTime.sort()
var ans = 0

for i in 0..<startTime.count {
    let upper = upperBound(with: endTime, startTime[i])
    ans = max(ans, i+1-upper)
}

print(ans)
