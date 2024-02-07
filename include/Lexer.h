//
// Created by Nun of 'yo Bidness on 2/2/24.
//

#ifndef LITHIUM_LEXER_H
#define LITHIUM_LEXER_H

#include "Common.h"
#include "Token.h"
#include "Position.h"

namespace Lithium {
    class Lexer {
    private:
        std::string source;
        size_t idx;

        bool isEof();

        void advance();

        Token advance_with(Token t);

        char peek();

        Token
        createToken(const std::string &value, TokenType type, SourcePositionChunk chunk = {(size_t) -1, (size_t) -1});

        Token readWhile(bool (*condition)(char), TokenType type);

        Token readString();

        Token readIdentifier();

        Token readNumber();

        Token readOp();

        Position crawlForPosition();

        Position crawlForPosition(size_t i);

    public:
        explicit Lexer(std::string source) : source(std::move(source)), idx(0) {};

        Token next();
    };
}

#endif //LITHIUM_LEXER_H
