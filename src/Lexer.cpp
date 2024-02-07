//
// Created by Nun of 'yo Bidness on 2/2/24.
//

#include "Lexer.h"
#include "PositionalError.h"
#include "ChunkError.h"

namespace Lithium {
    // Checking if end of file has been reached
    bool Lexer::isEof() {
        return (idx + 1) > source.size();
    }

    // Method to move to the next character in the source
    void Lexer::advance() {
        if (!isEof()) idx++;
    }

    Token Lexer::advance_with(Token t) {
        advance();
        return t;
    }

    char Lexer::peek() {
        if (isEof()) return '\0';
        return source.at(idx);
    }

    Token Lexer::next() {
        if (isEof()) return createToken("", F_EOF);

        while (isspace(peek()) && !isEof()) advance();
        if (isalpha(peek())) return readIdentifier();
        if (isdigit(peek())) return readNumber();
        if (peek() == '"' || peek() == '\'') return readString();
        if (IsOp(peek())) return readOp();

        switch (peek()) {
            case '.':
                return advance_with({
                                            .value = std::string(1, peek()),
                                            .type = DOT
                                    });

            case '!':
                return advance_with({
                                            .value = std::string(1, peek()),
                                            .type = NOT
                                    });

            default:
                PositionalError("Unexpected character", crawlForPosition(), source).spit();
                return advance_with(createToken("", F_EOF));
        }
    }

    Token Lexer::readWhile(bool (*condition)(char), TokenType type) {
        std::stringstream ss;
        while (condition(peek())) {
            ss << peek();
            advance();
        }
        return createToken(ss.str(), type);
    }

    Token Lexer::readIdentifier() {
        return readWhile(reinterpret_cast<bool (*)(char)>(isalnum), IDENTIFIER);
    }

    Token Lexer::readNumber() {
        return readWhile(reinterpret_cast<bool (*)(char)>(isdigit), NUMBER);
    }

    Token Lexer::readString() {
        // Transition Logic respect to previous implementation
        advance();
        return readWhile([](char c) { return c != '"' && c != '\''; }, STRING);
    }

    Token Lexer::createToken(const std::string &value, TokenType type,
                             SourcePositionChunk chunk) {
        return Token{
                .value = value,
                .type = type,
                .sourcePosition = chunk == SourcePositionChunk{(size_t) -1, (size_t) -1} ? SourcePositionChunk{idx, idx}
                                                                                         : chunk
        };
    }

    Token Lexer::readOp() {
        char peekChar = peek();

        if (peekChar == '=') {
            advance();
            char nextCharAfterEqual = peek();
            if (IsImmutableOp(nextCharAfterEqual) || nextCharAfterEqual == '=') {
                return advance_with(createToken(std::string("=") + nextCharAfterEqual, BINARY_OP));
            } else {
                return createToken("=", EQUALS);
            }
        }

        if (IsImmutableOp(peekChar))
            return advance_with(createToken(std::string(1, peekChar), BINARY_OP));

        if (IsMutableOp(peekChar)) {
            advance();
            if (peek() == '=') {
                return advance_with(createToken(std::string(1, peekChar) + "=", EQUALS));
            } else {
                return createToken(std::string(1, peekChar), BINARY_OP);
            }
        }

        return createToken(std::string(1, peekChar), F_EOF);
    }

    Position Lexer::crawlForPosition() {
        size_t line = 1;
        size_t col = 1;
        for (int i = 0; i < idx; i++) {
            if (source[i] == '\n') {
                line++;
                col = 1;
            } else col++;
        }
        return {line, col};
    }

    Position Lexer::crawlForPosition(size_t index) {
        size_t line = 1;
        size_t col = 1;
        for (int i = 0; i < index; i++) {
            if (source[i] == '\n') {
                line++;
                col = 1;
            } else col++;
        }
        for (size_t i = index; i < this->idx; i++) {
            if (source[i] == '\n') {
                line++;
                col = 1;
            } else col++;
        }
        return {line, col};
    }
}