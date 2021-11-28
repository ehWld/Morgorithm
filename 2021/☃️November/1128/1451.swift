//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

var R: Int = 0
var C: Int = 0
var arr = [[Int]](repeating: [Int](repeating: 0, count: 52), count: 52)

func solve() {
    let input = readInt()
    R = input[0]
    C = input[1]
    for r in 0..<R {
        let input = Array(readStr()[0])
        for c in 0..<C { arr[r][c] = Int(String(input[c]))! }
    }

    for r in 0..<R {
        for c in 0..<C {
            if r == 0 && c == 0 { continue }

            if r == 0 { arr[r][c] += arr[r][c-1] }
            else if c == 0 { arr[r][c] += arr[r-1][c] }
            else { arr[r][c] += arr[r-1][c] + arr[r][c-1] - arr[r-1][c-1] }
        }
    }

    var ans = 0

    for i in 0..<(C-1) { // 세로로 나누기
        for j in (i+1)..<(C-1) {
            let sum = arr[R-1][i] * (arr[R-1][j] - arr[R-1][i]) * (arr[R-1][C-1] - arr[R-1][j])
            ans = max(ans, sum)
        }
    }

    for i in 0..<(R-1) { // 가로로 나누기
        for j in (i+1)..<(R-1) {
            let sum = arr[i][C-1] * (arr[j][C-1] - arr[i][C-1]) * (arr[R-1][C-1] - arr[j][C-1])
            ans = max(ans, sum)
        }
    }

    for r in 0..<(R-1) {
        for c in 0..<(C-1) {
            let sum1 = arr[r][c] * (arr[r][C-1] - arr[r][c]) * (arr[R-1][C-1] - arr[r][C-1])
            ans = max(ans, sum1)

            let sum2 = arr[r][c] * (arr[R-1][c] - arr[r][c]) * (arr[R-1][C-1] - arr[R-1][c])
            ans = max(ans, sum2)

            let sum3 = arr[R-1][c] * (arr[r][C-1] - arr[r][c]) * (arr[R-1][C-1] - arr[R-1][c] - arr[r][C-1] + arr[r][c])
            ans = max(ans, sum3)

            let sum4 = arr[r][C-1] * (arr[R-1][c] - arr[r][c]) * (arr[R-1][C-1] - arr[R-1][c] - arr[r][C-1] + arr[r][c])
            ans = max(ans, sum4)
        }
    }

    print(ans)
}
