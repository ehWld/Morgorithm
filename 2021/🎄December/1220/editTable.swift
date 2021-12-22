//
//  editTable.swift
//  2021
//
//  Created by Dozzing on 2021/12/20.
//

import Foundation

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var answer = ""
    var table = Set<Int>()
    for i in 0..<n {
        answer += "X"
        table.insert(i)
    }

    var current = table.firstIndex(of: k)!
    var history = [Int]()

    for command in cmd {
        let command = command.split(separator: " ")
        if command[0] == "U" || command[0] == "D" {
            let x = Int(command[1])!
            if command[0] == "U" {
                current = table.index(current, offsetBy: -x, limitedBy: table.startIndex)!
            }
            else {
                current = table.index(current, offsetBy: x, limitedBy: table.endIndex)!
            }
        }
        else if command[0] == "C" {
            history.append(table[current])
            table.remove(at: current)
        }
        else if command[0] == "Z" {

        }
        else {

        }
    }

    return ""
}
