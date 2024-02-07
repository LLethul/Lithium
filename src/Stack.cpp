#include "Stack.h"

namespace Lithium {

    template<typename T>
    T Stack<T>::pop() {
        if (this->idx == -1) throw std::out_of_range("Stack is empty. Cannot pop.");
        return this->stack[this->idx--];
    }

    template<typename T>
    void Stack<T>::push(T item) {
        ++this->idx;
        this->stack.insert(this->stack.begin() + this->idx, item);
    }
}