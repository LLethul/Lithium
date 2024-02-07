#include "Token.h"

namespace Lithium {
    std::string TokenTypeToString(TokenType type) {
        switch (type) {
            case IDENTIFIER:
                return "identifier";
            case NUMBER:
                return "number";
            case STRING:
                return "string";
            case BOOLEAN:
                return "boolean";
            case BINARY_OP:
                return "binary operation";
            case EQUALS:
                return "equals";
            case RETURN_KW:
                return "return keyword";
            case IF_KW:
                return "if keyword";
            case WHILE_KW:
                return "while keyword";
            case COMMA:
                return "comma";
            case COLON:
                return "colon";
            case SEMICOLON:
                return "semicolon";
            case DOT:
                return "dot";
            case F_EOF:
                return "end of file";
            default:
                return "unknown token";
        }
    }

    std::string TokenToString(const Token &t) {
        std::stringstream ss{};
        ss << "Token<" << '"' << t.value << '"' << ", " << TokenTypeToString(t.type) << ">";

        return ss.str();
    }

    bool IsMutableOp(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

    bool IsImmutableOp(char op) {
        return op == '<' || op == '>';
    }

    bool IsOp(char op) {
        return IsMutableOp(op) || IsImmutableOp(op) || op == '=';
    }
}