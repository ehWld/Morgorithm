//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

func makeZero(current: Int, N: Int, arr: [String]) {
    if current == N {
        var sum = 0
        var rhs = 1
        var cur = 2

        for oper in arr {
            if oper == " " {
                if rhs > 0 { rhs = rhs * 10 + cur }
                else { rhs = rhs * 10 - cur }
            }
            else if oper == "+" {
                sum += rhs
                rhs = cur
            }
            else {
                sum += rhs
                rhs = -cur
            }
            cur += 1
        }
        sum += rhs

        if sum != 0 { return }
        for i in 0..<N-1 { print("\(i+1)\(arr[i])", terminator: "") }
        print(N)
        return
    }

    [" ", "+", "-"].forEach { oper in
        var arr2 = arr
        arr2.append(oper)
        makeZero(current: current + 1, N: N, arr: arr2)
    }
}

func solve() {
    var T = readInt()[0]
    while T > 0 {
        T -= 1
        let N = readInt()[0]
        makeZero(current: 1, N: N, arr: [])
        print("")
    }
}
