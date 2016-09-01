#include "Order.h"

int Order::globalId = 01; 
std::set<Order*>* Order::objectsList = new std::set<Order*>(); 


Order::Order(Customer* customer, Item* item): customer(customer) {
    this->id = globalId;
    globalId += 1;  
    objectsList->insert(this);
    itemsList = new std::list<Item*>();
    addItem(item);
    item->addOrder(this);
    customer->addOrder(this);
}        

Order::~Order(){
    std::list<Item*>::iterator it = itemsList->begin();
    
    for(int i = itemsList->size(); i > 0; ++it, i--) {
        (*it)->removeOrder(this);
    } 
    itemsList->clear();	
    delete itemsList;
    customer->removeOrder(this);
    objectsList->erase(this);
    if(objectsList->size() == 0) {
        delete objectsList;
    }
}        

std::set<Order*>* Order::listObjects(){
    return objectsList;
}

const int Order::getId() const {
    return id;
}

const Customer* Order::getCustomer(){
    return customer;
}

std::list<Item*>* Order::getItems() const {
    return itemsList;
}

void Order::addItem(Item* newItem){
    itemsList->push_back(newItem);
    newItem->addOrder(this);
}

void Order::removeItem(Item* item){
    item->removeOrder(this);
    itemsList->remove(item);
    if ( itemsList->size() == 0 ) {
        throw new ZeroSizeOrderException();
    }
    
}

std::ostream& operator<<(std::ostream& out, Order* order) {
    std::list<Item*>* itemsList = order->getItems();
    out << "#orderID: " << order->getId() << std::endl;
    out << "#customer name: " << order->getCustomer()->getName() << std::endl; 
    out << "#customer surname: " << order->getCustomer()->getSurname() << std::endl;
    out << "#items: " << itemsList->size() << std::endl; 
    out << "---------------" << std::endl;
    
    return out;
}
