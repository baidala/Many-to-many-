#include "Category.h"

int Category::globalId = 01; 
std::set<Category*>* Category::objectsList = new std::set<Category*>(); 


Category::Category(const std::string& category): category(category) {
    this->id = globalId;
    globalId += 1;  
    objectsList->insert(this);
    itemsList = new std::list<Item*>();
}        

Category::~Category(){
    std::list<Item*>::iterator it = itemsList->begin();
    
    for(int i = itemsList->size(); i > 0; ++it, i--) {
        removeItem(*it);
        delete (*it);
    }
    itemsList->clear();	
    delete itemsList;
    objectsList->erase(this);
    if(objectsList->size() == 0) {
        delete objectsList;
    }
}        

std::set<Category*>* Category::listObjects(){
    return objectsList;
}

const std::string& Category::getName() const {
    return category;
}

const int Category::getId() const {
    return id;
}

std::list<Item*>* Category::getItems() const {
    return itemsList;
}

void Category::addItem(Item* newItem){
    itemsList->push_back(newItem);

}

void Category::removeItem(Item* item){
    itemsList->remove(item);
    
}

std::ostream& operator<<(std::ostream& out, Category* category) {
    out << "#categoryID: " << category->getId() << std::endl;
    out << "#category: " << category->getName() << std::endl;
    out << "---------------" << std::endl;
    
    return out;
}