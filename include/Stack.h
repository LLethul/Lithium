//
// Created by Nun of 'yo Bidness on 2/5/24.
//

#ifndef LITHIUM_STACK_H
#define LITHIUM_STACK_H

#include "Common.h"

namespace Lithium {
    template<typename T>
    class Stack {
    private:
        std::vector<T> stack;
        size_t idx;

    public:
        Stack() : stack(), idx(-1) {};

        T pop();

        void push(T item);
    };
}

#endif