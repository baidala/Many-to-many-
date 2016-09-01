#include "Customer.h"


int Customer::globalId = 01; 
std::set<Customer*>* Customer::objectsList = new std::set<Customer*>(); 

Customer::Customer(const std::string& name, const std::string& surname): name(name), surname(surname) {
    this->id = globalId;
    globalId += 1;  
    objectsList->insert(this);
    ordersList = new std::map<int, Order*>();
}        

Customer::~Customer(){
    std::map<int, Order*>::iterator it = ordersList->begin();
    
    for(int i = ordersList->size(); i > 0; ++it, i--) {
        delete it->second;
    }
    ordersList->clear();	
    delete ordersList;
    objectsList->erase(this);
    if( objectsList->size() == 0 ) {
        delete objectsList;
    }
}        

std::set<Customer*>* Customer::listObjects(){
    return objectsList;
}

const std::string& Customer::getName() const {
    return name;
}
const std::string& Customer::getSurname() const{
    return surname;
}
const int Customer::getId() const{
    return id;
} 

std::map<int , Order*>* Customer::getOrders() const{
    return ordersList;
}

void Customer::addOrder(Order* newOrder){
    ordersList->insert( std::pair<int, Order*>(newOrder->getId(), newOrder) );
}

void Customer::removeOrder(Order* order){
    ordersList->erase(order->getId());
}


std::ostream& operator<<(std::ostream& out, Customer* customer) {
    out << "#customerID: " << customer->getId() << std::endl;
    out << "#name: " << customer->getName() << std::endl; 
    out << "#surname: " << customer->getSurname() << std::endl; 
    out << "---------------" << std::endl;
    
    return out;
}
