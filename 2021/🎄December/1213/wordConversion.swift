//
//  wordConversion.swift
//  2021
//
//  Created by Dozzing on 2021/12/13.
//

import Foundation

func isAdjacent(_ first: String, _ second: String) -> Bool {
    var count = 0
    let first = Array(first)
    let second = Array(second)

    for i in 0..<first.count {
        if first[i] != second[i] { count += 1}
    }

    if count == 1 { return true }
    return false
}

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    guard let targetIndex = words.firstIndex(of: target) else { return 0 }
    let N = words.count
    var adj = [[Int]](repeating: [Int](), count: N+2)

    for i in 0..<N {
        if isAdjacent(begin, words[i]) {
            adj[N].append(i)
            adj[i].append(N)
        }

        for j in (i+1)..<N {
            if isAdjacent(words[i], words[j]) {
                adj[i].append(j)
                adj[j].append(i)
            }
        }
    }

    var visited = [Bool](repeating: false, count: N+2)
    var qu = [(Int, Int)]()
    var front = 0
    var ans = 0

    visited[N] = true
    qu.append((N, 0))

    while front < qu.count {
        let current = qu[front].0
        let lv = qu[front].1
        front += 1

        if current == targetIndex {
            ans = lv
            break
        }

        for next in adj[current] {
            if visited[next] { continue }
            visited[next] = true
            qu.append((next, lv+1))
        }
    }

    return ans
}
