//
// Created by Nun of 'yo Bidness on 2/6/24.
//

#ifndef LITHIUM_ASTNODE_H
#define LITHIUM_ASTNODE_H

#include <utility>

#include "Position.h"

namespace Lithium {

    enum AstKind {
        IDENTIFIER, NUMERIC_LITERAL, STRING_LITERAL, BOOLEAN_LITERAL,
        BINARY_EXPRESSION, RETURN_STMT, VAR_DECLARATION, VAR_ASSIGN,
        PROGRAM, CLOSURE
    };

    class AstNode {
        AstKind kind;
    public:
        explicit AstNode(AstKind kind) : kind(kind) {}
    };

    class IdentifierNode : public AstNode {
        std::string symbol;
    public:
        explicit IdentifierNode(std::string symbol) : AstNode(IDENTIFIER), symbol(std::move(symbol)) {};
    };

    class NumericLiteralNode : public AstNode {
        float value;
    public:
        explicit NumericLiteralNode(float value) : AstNode(NUMERIC_LITERAL), value(value) {}
    };

    class StringLiteralNode : public AstNode {
        std::string value;
    public:
        explicit StringLiteralNode(std::string value) : AstNode(STRING_LITERAL), value(std::move(value)) {};
    };

    class BooleanLiteralNode : public AstNode {
        bool value;
    public:
        explicit BooleanLiteralNode(bool value) : AstNode(BOOLEAN_LITERAL), value(value) {}
    };

    class BinaryExpressionNode : public AstNode {
        std::shared_ptr<AstNode> LHS, RHS;
    public:
        BinaryExpressionNode(std::shared_ptr<AstNode> LHS, std::shared_ptr<AstNode> RHS) : AstNode(BINARY_EXPRESSION),
                                                                                           LHS(std::move(LHS)),
                                                                                           RHS(std::move(RHS)) {}
    };

    class ProgramNode : public AstNode {
        std::vector<AstNode> body;
    public:
        explicit ProgramNode(std::vector<AstNode> body) : AstNode(PROGRAM), body(std::move(body)) {};
    };

    class ClosureNode : public AstNode {
        std::vector<AstNode> body;
    public:
        explicit ClosureNode(std::vector<AstNode> body) : AstNode(CLOSURE), body(std::move(body)) {};
    };

} // Lithium

#endif //LITHIUM_ASTNODE_H
