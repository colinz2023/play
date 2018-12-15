//
// Created by colin on 2018-12-13.
//

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//         2(ABC) 3(DEF)
// 4(GHI)  5(JKL) 6(MNO)
// 7(PQRS) 8(TUV) 9(WXYZ)
//示例:
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include "leetcode.h"

class Solution {


public:
    vector<string> letterCombinations(string digits) {

    }
};

int main() {
    vector<string> v1 = Solution().letterCombinations("23");

    PrintVector(v1);
}