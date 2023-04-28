#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace exceptions {

class ForbiddenMove : public std::exception {
    const char* what() const throw() {
        return "Cannot move to that cell as it is not in allowed cells";
    }
};

}  // namespace exceptions

#endif  // EXCEPTIONS_H
