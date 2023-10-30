#pragma once
#include <string>

class dish {
public:
    virtual ~dish() {}
    virtual std::string getDescription() const = 0;
    virtual void addComponent(const std::string& component) =0;
    virtual void removeComponent(const std::string& component) =0;
};
