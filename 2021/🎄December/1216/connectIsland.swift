//
//  connectIsland.swift
//  2021
//
//  Created by Dozzing on 2021/12/17.
//

import Foundation

var root = [Int](repeating: 0, count: 102)

func find(_ n: Int) -> Int {
    if root[n] == n { return n }
    root[n] = find(root[n])
    return root[n]
}

func union(_ a: Int, _ b: Int) -> Bool {
    let rootA = find(a)
    let rootB = find(b)
    if rootA == rootB { return false }
    root[rootA] = rootB
    return true
}

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var answer = 0
    var count = 0
    var costs = costs.sorted{ return $0[2] < $1[2] }
    for i in 0..<n { root[i] = i }

    for edge in costs {
        if !union(edge[0], edge[1]) { continue }
        count += 1
        answer += edge[2]
        if count == n-1 { break }
    }

    return answer
}
