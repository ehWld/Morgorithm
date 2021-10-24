//
//  main.swift
//  2021
//
//  Created by Dozzing on 2021/10/19.
//

import Foundation

let string = "hello"
let subPattern = "[a-zA-Z]"
let pattern = "^[a-zA-Z]$"

// 일부 매칭 (첫번째 일치 부분)
let subMatchRange = string.range(of: subPattern, options: .regularExpression)

// 전체 매칭 (첫번째 일치 부분)
let totalMatchSimple = string.range(of: pattern, options: .regularExpression)

// 전체 매칭 (첫번째 일치 부분)
let regex = try? NSRegularExpression(pattern: pattern)
let totalMatch = regex?.firstMatch(in: string, options: [], range: NSRange(location: 0, length: string.count))

// 일치하는 모든 범위
let subMatches = regex?.matches(in: string, options: [], range: NSRange(location: 0, length: string.count))
let resultStrings = subMatches?.map { (element) -> String in
    guard let range = Range(element.range, in: string) else { return "" }
    return String(string[range])
}

let capturedPattern = "(?<name>az[0-9]{1, })asdfe(?<name1>[0-1][0-2])"
