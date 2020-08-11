//
// Created by Jens Klimke on 2019-04-14.
//

#ifndef PARSE_XSD_FUNCTIONS_H
#define PARSE_XSD_FUNCTIONS_H

#include <string>
#include <sstream>
#include <vector>

/**
 * String formatter
 * @tparam Args
 * @param format Format string
 * @param args Inputs
 * @return Formatted string
 */
template<typename ... Args>
std::string string_format(const std::string &format, Args ... args) {
    auto size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    char *buf(new char[size]);
    snprintf(buf, size, format.c_str(), args ...);
    return std::string(buf, buf + size - 1); // We don't want the '\0' inside
}




//std::vector<std::string> split(const std::string& str, char delim = ' ')
//{
//    std::vector<std::string> cont;
//
//    std::stringstream ss(str);
//    std::string token;
//    while (std::getline(ss, token, delim))
//        cont.push_back(token);
//
//    return cont;
//
//}


#endif //PARSE_XSD_FUNCTIONS_H
