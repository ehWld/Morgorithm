//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

var T = readInt()[0]

while T > 0 {
    T -= 1
    let input = readStr()
    input.forEach { str in
        print("\(str.reversed().reduce(""){ return String($0) + String($1)})", terminator: " ")
    }
    print("")
}

