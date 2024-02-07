//
// Created by Nun of 'yo Bidness on 2/2/24.
//

#ifndef LITHIUM_TOKEN_H
#define LITHIUM_TOKEN_H

#include "Common.h"
#include "Position.h"

namespace Lithium {
    enum TokenType {
        IDENTIFIER, NUMBER, STRING, BOOLEAN,
        BINARY_OP, EQUALS, NOT,
        RETURN_KW, IF_KW, WHILE_KW,
        COMMA, COLON, SEMICOLON, DOT,
        F_EOF
    };

    struct Token {
        std::string value;
        TokenType type;
        [[maybe_unused]] SourcePositionChunk sourcePosition;
    };

    std::string TokenTypeToString(TokenType type);

    std::string TokenToString(const Token &t);

    bool IsMutableOp(char op);

    bool IsImmutableOp(char op);

    bool IsOp(char op);
}

#endif //LITHIUM_TOKEN_H
