#include <iostream>

#ifndef __UTILS_H__
#define __UTILS_H__

inline void UpdateProgress(double progress) {
    int bar_width = 70;

    std::clog << "[";
    int pos = bar_width * progress;
    for (int i = 0; i < bar_width; i++) {
        if (i < pos) std::clog << "=";
        else if (i == pos) std::clog << ">";
        else std::clog << " ";
    }
    std::clog << "] " << (int)(progress * 100) << " %\r";
    std::clog.flush();
}

#endif // __UTILS_H__
