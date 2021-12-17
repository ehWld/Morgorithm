//
//  pathFindGame.swift
//  2021
//
//  Created by Dozzing on 2021/12/17.
//

import Foundation

var nodes = [[(x: Int, node: Int)]](repeating: [(x: Int, node: Int)](), count: 1002)

func upperBound(_ x: Int, level: Int) -> (x: Int, node: Int) {
    var left = 0
    var right = nodes[level].count - 1

    while left < right {
        var mid = (left + right) / 2
        if x > nodes[level][mid].x { left = mid + 1 }
        else { right = mid - 1 }
    }
    return nodes[level][left]
}

func findChild(level: Int, leftX: Int, rightX: Int) -> Int {
    if nodes[level].isEmpty { return 0 }
    let child = upperBound(leftX, level: level)
    if child.x > rightX { return 0 }
    return child.node
}

func preorder(_ n: Int, level: Int, ret: inout [Int]) {
    let left = findChild
}

func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    var index = 0
    var nodeinfo: [(Int, [Int])] = nodeinfo.map { pos in
        index += 1
        return (index, pos)
    }
    var sortedNodeinfo = nodeinfo.sorted { $0.1[1] > $1.1[1] }
    var preY = -1
    var level = -1
    for node in sortedNodeinfo {
        if node.1[1] != preY { level += 1; preY = node.1[1] }
        nodes[level].append((node.1[0], node.0))
    }



    return []
}
