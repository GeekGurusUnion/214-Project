#pragma once
#include <string>

class dish {
public:
    virtual ~dish() {}
    virtual std::string getDescription() const = 0;
};
