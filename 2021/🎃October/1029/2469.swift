//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

extension String {
    subscript(offset: Int) -> Character {
        get {
            let index = self.index(self.startIndex, offsetBy: offset)
            return self[index]
        }
        set {
            let index = self.index(self.startIndex, offsetBy: offset)
            replaceSubrange(index...index, with: String(newValue))
        }
    }
}

let k = readInt()[0]
let N = readInt()[0]
let order = readStr()[0]
var unknown = 0

var ladder = [String]()
for i in 0..<N {
    ladder.append(readStr()[0])
    if ladder[i][0] == "?" { unknown = i }
}

func move(from column: Int ,dir: Int) -> Int {
    var row = 0
    var col = column
    if dir < 0 { row = N-1 }

    while row != unknown {
        if col<k-1 && ladder[row][col] == "-" { col += 1 }
        else if col>0 && ladder[row][col-1] == "-" { col -= 1 }
        row += dir
    }

    return col
}

var answer = ""
var flag = true
for _ in (0..<k-1) { answer += " " }

for i in 0..<k {
    let fore = move(from: Int(order[i].asciiValue!)-65, dir: 1)
    let back = move(from: i, dir: -1)

    if fore == back {
        if fore<k-1 && answer[fore] == "-" { flag = false }
        if fore>0 && answer[fore-1] == "-" { flag = false }
        if fore<k-1 { answer[fore] = "*" }
        if fore>0 { answer[fore-1] = "*" }
    }
    else if abs(fore-back) == 1 {
        let col = min(fore, back)
        if answer[col] == "*" { flag = false }
        if col>0 && answer[col-1] == "-" { flag = false }
        answer[col] = "-"
        if col>0 { answer[col-1] = "*" }
    }
    else { flag = false }

    if flag == false { break }
}

if flag == true { print(answer) }
else {
    for _ in (0..<k-1) { print("x", terminator: "") }
}

