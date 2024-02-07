//
// Created by Nun of 'yo Bidness on 2/5/24.
//

#ifndef LITHIUM_CHUNKERROR_H
#define LITHIUM_CHUNKERROR_H

#include "Error.h"
#include "Position.h"

namespace Lithium {
    class ChunkError : public Error {
    public:
        Chunk at;
        std::string source;

        ChunkError(std::string message, Chunk at, std::string source) : Error(message), at(at), source(source) {};

        void spit() const;
    };
}

#endif //LITHIUM_CHUNKERROR_H
