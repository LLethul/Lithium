//
// Created by Nun of 'yo Bidness on 2/5/24.
//


#pragma once
#ifndef LITHIUM_POSITION_H
#define LITHIUM_POSITION_H

#include "Common.h"

namespace Lithium {
    struct Position {
        size_t line;
        size_t column;

        Position(size_t line, size_t column) : line(line), column(column) {};

        Position() : line(1), column(1) {};

        bool operator==(const Position &) const = default;
    };

    struct Chunk {
        Position start, end;

        Chunk(Position start, Position end) : start(start), end(end) {};

        Chunk() : start(), end() {};

        bool operator==(const Chunk &) const = default;
    };

    struct SourcePositionChunk {
        size_t start, end;

        SourcePositionChunk(size_t start, size_t end) : start(start), end(end) {};

        SourcePositionChunk() : start(0), end(0) {};

        bool operator==(const SourcePositionChunk &) const = default;
    };
}

#endif //LITHIUM_POSITION_H
