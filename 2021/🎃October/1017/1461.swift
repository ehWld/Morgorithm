//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

let input = readInt()
let N = input[0]
let M = input[1]
var books = readInt()
var pos = books.filter { $0 > 0 }.sorted(by: >)
var neg = books.filter { $0 < 0 }.map{ return abs($0) }.sorted(by: >)
var ans = 0

var i = 0
while i < pos.count {
    ans += 2 * pos[i]
    i += M
}
i = 0
while i < neg.count {
    ans += 2 * neg[i]
    i += M
}

ans -= max(pos.first ?? 0, neg.first ?? 0)

print(ans)
