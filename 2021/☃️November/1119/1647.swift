//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.split(separator: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

typealias Road = (first: Int, second: Int, cost: Int)

var N: Int = 0
var M: Int = 0
var road = [Road]()
var root = [Int]()

func initRoot() {
    for index in 0...N { root.append(index) }
}

func find(_ n: Int) -> Int {
    if root[n] == n { return n }
    root[n] = find(root[n])
    return root[n]
}

func union(_ a: Int, _ b: Int) -> Bool {
    let rootA = find(a);
    let rootB = find(b);
    if rootA == rootB { return false }

    root[rootB] = rootA
    return true
}

func main() {
    var input = readInt()

    N = input[0]
    M = input[1]

    for _ in 0..<M {
        input = readInt()
        road.append(Road(first: input[0], second: input[1], cost: input[2]))
    }

    initRoot()
    road.sort(by: { $0.cost < $1.cost })
    var selectCount = 0
    var ans = 0

    for current in road {
        if selectCount >= N-2 { break }
        if !union(current.first, current.second) { continue }

        ans += current.cost
        selectCount += 1
    }

    print(ans)
}
