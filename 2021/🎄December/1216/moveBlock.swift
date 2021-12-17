//
//  moveBlock.swift
//  2021
//
//  Created by Dozzing on 2021/12/17.
//

import Foundation

typealias Pos = (r: Int, c: Int)
let dr = [-2, -1, 0, 1, 2, 1, 0, -1]
let dc = [0, 1, 2, 1, 0, -1, -2, -1]
var R = 0, C = 0
var myBoard = [[Int]]()
var visited = [[Bool]](repeating: [Bool](repeating: false, count: 202), count: 202)

func isMovable(from: Pos, to: Pos) -> Bool {
    if to.r < 0 || to.r > 2*(R-1) || to.c < 0 || to.c > 2*(C-1) { return false }
    if visited[to.r][to.c] { return false }
    if to.r % 2 == 0 {
        if myBoard[to.r/2][to.c/2] == 1 || myBoard[to.r/2][to.c/2 + 1] == 1 { return false }
    }
    else if myBoard[to.r/2][to.c/2] == 1 || myBoard[to.r/2 + 1][to.c/2] == 1 { return false }

    if from.r != to.r && from.c != to.c {
        let row = min(from.r, to.r) / 2
        let col = min(from.c, to.c) / 2
        if myBoard[row][col] == 1 || myBoard[row+1][col] == 1 || myBoard[row][col+1] == 1 || myBoard[row+1][col+1] == 1 {
            return false
        }
    }

    return true
}

func solution(_ board:[[Int]]) -> Int {
    myBoard = board
    R = board.count
    C = board[0].count
    let last = [(2 * (R-1), 2 * (C-1) - 1), (2 * (R-1) - 1, 2 * (C-1))]
    var qu = [(pos: Pos, lv: Int)]()
    var front = 0
    qu.append((Pos(0, 1), 0))
    visited[0][1] = true

    while front < qu.count {
        let current = qu[front]
        front += 1
        if current.pos == last[0] || current.pos == last[1] { return current.lv }

        for i in 0..<8 {
            let next = Pos(current.pos.r + dr[i], current.pos.c + dc[i])
            if !isMovable(from: current.pos, to: next) { continue }

            visited[next.r][next.c] = true
            qu.append((next, current.lv + 1))
        }
    }

    return 0
}
