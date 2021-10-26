//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

let input = readLine()!

var mod = 0
var str = ""
input.forEach { char in

    switch mod {
    case 0:
        if char == "<" {
            mod = 1
            print(String(str.reversed()), terminator: "")
            str = ""
        }
        else if char == " " {
            print(String(str.reversed()), terminator: " ")
            str = ""
        }
        else { str += String(char) }
    case 1:
        if char == ">" {
            mod = 0
            print("<\(str)>", terminator: "")
            str = ""
        }
        else { str += String(char) }
    default:
        break
    }

}

if str != "" {
    print(String(str.reversed()))
}
