//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

let input = Array(readStr()[0])
let N = input.count
var st = [Int]()
var len = 0

for i in 0..<N {
    switch input[i] {
    case "(":
        st.append(-1)
    case ")":
        len = 0
        while st.last! >= 0 {
            len += st.last!
            st.removeLast()
        }
        st.removeLast() // ( 제거
        len *= st.last!
        st.removeLast()
        st.append(len)
    default:
        if (i<N-1 && input[i+1] == "(") {
            st.append(Int(input[i].asciiValue!) - 48)
        }
        else { st.append(1) }
    }
}

let ans = st.reduce(0) { return $0 + $1 }
print(ans)
