//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

struct Pos {
    var r: Int
    var c: Int
}

func main() {
    let dr = [0, 1, 0, -1]
    let dc = [1, 0, -1, 0]

    var input = readInt()
    let R = input[0]
    let C = input[1]
    let T = input[2]
    var arr = [[Int]]()
    var visited = [[Bool]](repeating: [Bool](repeating: false, count: C), count: R)

    for r in 0..<R {
        input = readInt()
        arr.append(input)
    }

    var ans = 10001
    var qu = [(pos: Pos, time: Int)]()
    var front = 0
    qu.append((Pos(r: 0, c: 0), 0))

    while qu.count > front {
        let time = qu[front].time
        let current = qu[front].pos
        front += 1

        if current.r == R-1 && current.c == C-1 {
            ans = min(ans, time)
            break
        }

        if arr[current.r][current.c] == 2 {
            ans = min(ans, time + R - current.r + C - current.c - 2)
        }

        for i in 0..<4 {
            let next = Pos(r: current.r + dr[i], c: current.c + dc[i])

            if next.r < 0 || next.r >= R || next.c < 0 || next.c >= C { continue }
            if visited[next.r][next.c] || arr[next.r][next.c] == 1 { continue }

            visited[next.r][next.c] = true
            qu.append((next, time+1))
        }
    }

    if ans > T { print("Fail") }
    else { print(ans) }
}
