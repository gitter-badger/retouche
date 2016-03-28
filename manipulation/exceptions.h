#ifndef MANIPULATION_UNKNOWN_MANIPULATION_EXCEPTION_H
#define MANIPULATION_UNKNOWN_MANIPULATION_EXCEPTION_H

#include <string>
#include <exception>

namespace manipulation {

// Represents an illegal manipulation name error.
class UnknownManipulationException : public std::exception {
public:
    UnknownManipulationException(const std::string &name);
    virtual const char* what() const throw();

private:
    std::string _name;
};
}

#endif
