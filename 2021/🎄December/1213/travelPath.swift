//
//  travelPath.swift
//  2021
//
//  Created by Dozzing on 2021/12/13.
//

import Foundation

var ans = [String]()
var visited = [Bool](repeating: false, count: 10002)

func compare(_ lhs: [String], _ rhs: [String]) throws -> Bool {
    if lhs.first! < rhs.first! { return true }
    if (lhs.first! == rhs.first!) && (lhs.last! < rhs.last!) { return true}
    return false
}

func dfs(current: String, count: Int, tickets: [[String]]) -> Bool {
    if count == tickets.count { return true }

    for i in 0..<tickets.count {
        if tickets[i][0] != current || visited[i] { continue }

        visited[i] = true
        ans.append(tickets[i][1])
        if dfs(current: tickets[i][1], count: count+1, tickets: tickets) { return true }
        visited[i] = false
    }
    ans.removeLast()
    return false
}

func solution(_ tickets:[[String]]) -> [String] {
    var tickets = tickets
    try! tickets.sort(by: compare(_:_:))

    ans.append("ICN")
    dfs(current: "ICN", count: 0, tickets: tickets)
    return ans
}
