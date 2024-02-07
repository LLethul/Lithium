//
// Created by Nun of 'yo Bidness on 2/5/24.
//

#ifndef LITHIUM_POSITIONALERROR_H
#define LITHIUM_POSITIONALERROR_H

#include "Error.h"
#include "Position.h"

namespace Lithium {
    class PositionalError : public Error {
    public:
        Position at;
        std::string source;

        PositionalError(std::string message, Position at, std::string source) : Error(message), at(at),
                                                                                source(source) {};

        void spit() const;
    };
}

#endif //LITHIUM_POSITIONALERROR_H
