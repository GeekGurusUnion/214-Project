#ifndef WAITER__STATE_AVAILABLE_H
#define WAITER__STATE_AVAILABLE_H

// ConcreteState (State)

#include "WaiterState.h"

class WaiterStateAvailable : public WaiterState {
    public:
        WaiterStateAvailable(Waiter* waiter);
        bool isAvailable();
        bool isUnavailable();
        void setAvailable();
        void setUnavailable();

        // * testing * //
        Waiter* getWaiter() const;
        WaiterState* getThis();
        std::string currState = "WaiterStateAvailable";
        // * end of testing * //
};

#endif // WAITER__STATE_AVAILABLE_H