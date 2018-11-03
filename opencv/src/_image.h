//
// Created by colin on 2018/11/3.
//

#ifndef OPENCVTEST_IMAGE_H
#define OPENCVTEST_IMAGE_H

#include <string>

#define _IMAGE_DIR "/Users/colin/workSpace/realzhangm/play/_images/"

static inline const char* _IMAGE(const char* file) {
    static std::string dir;
    dir = std::string(_IMAGE_DIR);
    dir += file;
    return dir.c_str();
}

#endif //OPENCVTEST_IMAGE_H
