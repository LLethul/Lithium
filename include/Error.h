//
// Created by Nun of 'yo Bidness on 2/5/24.
//

#ifndef LITHIUM_ERROR_H
#define LITHIUM_ERROR_H

#include <utility>

#include "Common.h"

namespace Lithium {

    class Error {
    public:
        std::string message;

        explicit Error(std::string message) : message(std::move(message)) {};

        virtual void spit() const;
    };

} // Lithium

#endif //LITHIUM_ERROR_H
