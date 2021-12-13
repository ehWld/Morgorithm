//
//  farthestNode.swift
//  2021
//
//  Created by Dozzing on 2021/12/13.
//

import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {

    var adj = [[Int]](repeating: [Int](), count: n+2)

    edge.forEach { e in
        adj[e[0]].append(e[1])
        adj[e[1]].append(e[0])
    }

    var visited = [Bool](repeating: false, count: n+2)
    var count = [Int](repeating: 0, count: n+2)
    var qu = [(Int, Int)]()
    var front = 0

    visited[1] = true
    qu.append((1, 0))

    while front < qu.count {
        let current = qu[front].0
        let lv = qu[front].1
        front += 1
        count[lv] += 1

        for next in adj[current] {
            if visited[next] == true { continue }

            visited[next] = true
            qu.append((next, lv + 1))
        }
    }

    for lv in count.reversed() {
        if lv > 0 { return lv }
    }

    return 0
}
