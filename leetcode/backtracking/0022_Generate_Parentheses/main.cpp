//
// Created by colin on 2018-12-12.
//

//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
//例如，给出 n = 3，生成结果为：
//
//[
//    "((()))",
//    "(()())",
//    "(())()",
//    "()(())",
//    "()()()"
//]

#include "leetcode.h"

class Solution {

public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        return res;
    }
};




int main() {
    auto res = Solution().generateParenthesis(3);

    PrintVector(res);
}