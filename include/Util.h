//
// Created by Nun of 'yo Bidness on 2/5/24.
//

#ifndef LITHIUM_UTIL_H
#define LITHIUM_UTIL_H

#include "Common.h"
#include "PositionalError.h"
#include "ChunkError.h"

namespace Lithium::Util {
    const auto stringNotFound = std::string::npos;

    std::vector<std::string> split(const std::string &inputString, const std::string &delimiter) {
        auto startPos = size_t{0}, endPos = size_t{0}, delimiterLength = delimiter.length();
        std::vector<std::string> result;

        while ((endPos = inputString.find(delimiter, startPos)) != stringNotFound) {
            result.push_back(inputString.substr(startPos, endPos - startPos));
            startPos = endPos + delimiterLength;
        }

        result.push_back(inputString.substr(startPos));
        return result;
    }

    std::string repeat(const std::string &str, int n) {
        std::string result;
        for (int i = 0; i < n; ++i) {
            result += str;
        }
        return result;
    }
}


#endif //LITHIUM_UTIL_H