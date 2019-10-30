#ifndef ERRORFRACTION_H
#define ERRORFRACTION_H

class ErrorFraction {
public:
    ErrorFraction(char* str = "") : message(str) {}
    const char* what() const {return message;}

private:
        char* message;
};

#endif // ERRORFRACTION_H
