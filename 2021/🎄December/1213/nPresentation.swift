//
//  nPresentation.swift
//  2021
//
//  Created by Dozzing on 2021/12/13.
//

import Foundation

let mxn = 100000000
var set = [Set<Int>](repeating: Set<Int>(), count: 10)

func check(_ n: Int, _ lv: Int) {
    if n > mxn || n < -mxn { return }
    set[lv].insert(n)
}

func solution(_ N:Int, _ number:Int) -> Int {
    var sum = 0
    for i in 1...8 {
        sum = sum * 10 + N
        set[i].insert(sum)
    }

    for i in 1...8 {
        for j in 1...8 {
            if i + j > 8 { break }
            for a in set[i] {
                for b in set[j] {
                    check(a+b, i+j)
                    check(a-b, i+j)
                    check(a*b, i+j)
                    if b != 0 { check(a/b, i+j) }
                }
            }
        }

        if set[i].contains(number) { return i }
    }

    return -1
}
