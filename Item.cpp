#include "Item.h"

int Item::globalId = 01; 
std::set<Item*>* Item::objectsList = new std::set<Item*>(); 


Item::Item(Category* category, const std::string& itemName): category(category), itemName(itemName) {
    this->id = globalId;
    globalId += 1;  
    objectsList->insert(this);
    ordersList = new std::map<int, Order*>();
}        

Item::~Item(){
    std::map<int, Order*>::iterator it = ordersList->begin();
    
    for(int i = ordersList->size(); i > 0; ++it, i--) {
        it->second->removeItem(this);
    }
    ordersList->clear();	
    delete ordersList;
    objectsList->erase(this);
    if( objectsList->size() == 0 ) {
        delete objectsList;
    }
}        

std::set<Item*>* Item::listObjects(){
    return objectsList;
}

const std::string& Item::getItem() const {
    return itemName;
}

const int Item::getId() const {
    return id;
}

const Category* Item::getCategory(){
    return category;
}

void Item::setCategory(Category* category) {
    this->category = category;
}

std::map<int , Order*>* Item::getOrders() const {
    return ordersList;
}

void Item::addOrder(Order* order){
    ordersList->insert( std::pair<int, Order*>(order->getId(), order) );
}

void Item::removeOrder(Order* order){
    ordersList->erase(order->getId());
}

std::ostream& operator<<(std::ostream& out, Item* item) {
    out << "#itemID: " << item->getId() << std::endl;
    out << "#name: " << item->getItem() << std::endl; 
    out << "#category: " << item->getCategory()->getName() << std::endl;
    out << "---------------" << std::endl;
    
    return out;
}
