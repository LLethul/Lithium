#include <iostream>
#include "Lexer.h"

int main() {
    Lithium::Lexer lexeme{"let kw = 1 + 7"};
    Lithium::Token last = lexeme.next();

    while (last.type != Lithium::F_EOF) {
        std::cout << Lithium::TokenToString(last) << std::endl;
        last = lexeme.next();
    }
    return 0;
}
