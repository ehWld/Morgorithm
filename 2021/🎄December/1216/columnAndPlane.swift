//
//  columnAndPlane.swift
//  2021
//
//  Created by Dozzing on 2021/12/17.
//

import Foundation

var board = [[[Bool]]]()  // x, y, 0/1
var N = 0

func install(_ x: Int, _ y: Int, _ a: Int) -> Bool {
    if a == 0 { // 기둥
        if y == 0 { return true }
        if board[x][y][1] || ((x > 0) && board[x-1][y][1]) { return true }
        if (y > 0) && board[x][y-1][0] { return true }
    } else { // 보
        if (y > 0) && (board[x][y-1][0] || board[x+1][y-1][0]) { return true }
        if (x > 0) && board[x-1][y][1] && board[x+1][y][1] { return true }
    }
    return false
}

func delete(_ x: Int, _ y: Int, _ a: Int) -> Bool {
    if a == 0 { // 기둥
        board[x][y][0] = false
        if board[x][y+1][0] && !install(x, y+1, 0) { board[x][y][0] = true; return false }
        if board[x][y+1][1] && !install(x, y+1, 1) { board[x][y][0] = true; return false }
        if (x > 0) && board[x-1][y+1][1] && !install(x-1, y+1, 1) { board[x][y][0] = true; return false }
        board[x][y][0] = true
    } else { // 보
        board[x][y][1] = false
        if board[x+1][y][1] && !install(x+1, y, 1) { board[x][y][1] = true; return false }
        if (x > 0) && board[x-1][y][1] && !install(x-1, y, 1) { board[x][y][1] = true; return false }
        if board[x][y][0] && !install(x, y, 0) { board[x][y][1] = true; return false }
        if board[x+1][y][0] && !install(x+1, y, 0) { board[x][y][1] = true; return false }
        board[x][y][1] = true
    }
    return true
}

func solution(_ n:Int, _ build_frame:[[Int]]) -> [[Int]] {
    N = n
    board = [[[Bool]]](repeating: [[Bool]](repeating: [Bool](repeating: false, count: 2), count: n+1), count: n+1)

    for query in build_frame {
        if query[3] == 0 {
            if delete(query[0], query[1], query[2]) {
                board[query[0]][query[1]][query[2]] = false
            }
        }
        else if install(query[0], query[1], query[2]) {
            board[query[0]][query[1]][query[2]] = true
        }
    }

    var ans = [[Int]]()
    for x in 0...N {
        for y in 0...N {
            if board[x][y][0] { ans.append([x, y, 0]) }
            if board[x][y][1] { ans.append([x, y, 1]) }
        }
    }

    return ans
}
