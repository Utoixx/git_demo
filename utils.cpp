#include "utils.h"

std::vector<std::string> utils::split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delilen = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delilen;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}
