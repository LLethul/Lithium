//
// Created by Nun of 'yo Bidness on 2/5/24.
//

#include <sstream>
#include "Error.h"
#include "PositionalError.h"
#include "ChunkError.h"
#include "Util.h"

namespace Lithium {

    // Error logic is the same for both Error and PositionalError
    void Error::spit() const {
        throw std::runtime_error(message);
    }

    void PositionalError::spit() const {
        const auto line = Util::split(source, "\n").at(at.line - 1);
        const auto spaces = Util::repeat(" ", at.column - 1);
        std::cout << line << "\n" << spaces << "^" << std::endl;
        throw std::runtime_error(message);
    }

    void ChunkError::spit() const {
        auto line = Util::split(source, "\n").at(at.start.line - 1);
        const auto spaces = Util::repeat(" ", at.end.column - 1);
        std::cout << line << "\n" << spaces << "^" << std::endl;
        throw std::runtime_error(message);
    }

} // namespace Lithium