#ifndef INVALID_H
#define INVALID_H

#include <string>

class Invalid {
    public:
        Invalid(std::string str) : what(str) {}
        std::string what;
};

#endif // INVALID_H
