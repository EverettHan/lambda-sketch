
#ifndef CATSystemErrorStdException_H
#define CATSystemErrorStdException_H

#include <system_error> // C++11

class CATSystemErrorStdException : public std::system_error
{
public:
    using std::system_error::system_error;
    virtual ~CATSystemErrorStdException() {}
};

#endif  // CATSystemErrorStdException_H
