//
// Created by colin on 2018-12-17.
//

//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
//示例:
//
//输入: "25255511135"
//输出: ["255.255.11.135", "255.255.111.35"]

#include "leetcode.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        if (s.size() < 4 || s.size() > 12) return res;
        FindIpAddresses(s, 0, ip, res);
        return res;
    }
private:
    void FindIpAddresses(string s, int index, vector<string>& ip, vector<string>& res) {
        if (index == s.size()) {
            if (ip.size() == 4) {
                string ip_addr = ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3];
                res.push_back(ip_addr);
            }
            return;
        }
        for (int step = 1; step <= 3; step++) {
            string ip_addr_qtr = s.substr(index, step);
            if (index + step > s.size()) break;
            if (ip_addr_qtr.size() > 1 && ip_addr_qtr[0] == '0') continue;
            int ip_qtr_num = stoi(ip_addr_qtr);
            if (ip_qtr_num >= 0 && ip_qtr_num <=255) {
                ip.push_back(ip_addr_qtr);
                FindIpAddresses(s, index + step, ip, res);
                ip.pop_back();
            }
        }
    }
};

int main() {
    auto res = Solution().restoreIpAddresses("25525511135");
    auto res1 = Solution().restoreIpAddresses("010010");
    PrintVector(res);
    PrintVector(res1);
}