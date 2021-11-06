//  template.swift
//  Copyright © 2021 도찡. All rights reserved.

import Foundation

func readInt() -> [Int] {readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
func readStr() -> [String] {readLine()!.split(separator: " ").map{String($0)}}

typealias pii = (Int, Int)
let INF = INT32_MAX
let MOD = 1e9 + 7

/*[😈][🔮][🦔]*/

let input1 = readInt();
let input2 = readStr();

let N = input1[0];
let K = input1[1];
let input = Array(input2[0]);

var len = 0;
var st = [Int]();

for i in 0..<N {
    let current = Int(input[i].asciiValue! - 48);

    while (!st.isEmpty) && (st.last! < current) && (len+(N-1-i) >= N-K) {
        st.removeLast();
        len -= 1;
    }

    if len < N-K {
        st.append(current);
        len += 1;
    }
}

st.forEach {
    print($0, terminator: "")
}
