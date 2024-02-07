//
// Created by Nun of 'yo Bidness on 2/6/24.
//

#include "Parser.h"
#include "ChunkError.h"

namespace Lithium {
    Token Parser::at() {
        return last;
    }

    Token Parser::eat() {
        last = lexer.next();
        return at();
    }

    Token Parser::expect(Lithium::TokenType type) {
        Token ate = eat();
        if (!ate.type == type) ChunkError("Unexpected " + TokenTypeToString(ate.type), {lexer.crawlForPosition(ate.sourcePosition.start)), }.spit();
    }
} // Lithium