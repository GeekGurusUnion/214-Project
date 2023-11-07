#include "Complaints.h"

Complaints::Complaints(Waiter* w) : Command(w) {}

void Complaints::execute(RestaurantTable *rt, std::string complaint) {
    std::cout << "Complaint (" << complaint << ") has been filed." << std::endl;
}