package main

import "fmt"

func checkRecord(s string) bool {
    l, a := 0, 0
    for i := 0; i < len(s); i++ {
        c := s[i]
        if (c == 'L') {
            l += 1
            if (l > 2) {
                return false 
            }
        } else if (c == 'A') {
            l = 0;
            a += 1
            if (a > 1) {
                return false
            }
        } else {
            l = 0;
        }
    }
    return true
}

func main() {
    fmt.Println(checkRecord("PPALLP"))
}