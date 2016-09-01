#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <map>
#include "Base.h"
#include "Order.h"

class Order;

class Customer : public Base {    
private:
    static int globalId;
    std::string name;
    std::string surname;  
    static std::set<Customer*>* objectsList; 
    std::map<int, Order*>* ordersList;
public:        
    Customer(const std::string& name="", const std::string& surname="");        
    ~Customer();        
    static std::set<Customer*>* listObjects();
    const std::string& getName() const;
    const std::string& getSurname() const;
    const int getId() const; 
    std::map<int , Order*>* getOrders() const;
    void addOrder(Order* newOrder);
    void removeOrder(Order* order);
};

std::ostream& operator<<(std::ostream& out, Customer* customer);

#endif //CUSTOMER_H
