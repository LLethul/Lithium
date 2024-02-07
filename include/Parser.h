//
// Created by Nun of 'yo Bidness on 2/6/24.
//

#ifndef LITHIUM_PARSER_H
#define LITHIUM_PARSER_H

#include "Lexer.h"

namespace Lithium {

    class Parser {
    private:
        Lexer lexer;
        Token last;

        Token eat();

        Token at();

        Token expect(TokenType type);

        bool match(TokenType type);

        bool match(const std::string &value);

    public:
        explicit Parser(const std::string &source) : lexer(source), last(lexer.next()) {};
    };

} // Lithium

#endif //LITHIUM_PARSER_H
