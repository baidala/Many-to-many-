#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <set>
#include <list>
#include "Base.h"
#include "Item.h"

class Item;

class Category : public Base {    
private:
    static int globalId;
    std::string category;  
    static std::set<Category*>* objectsList; 
    std::list<Item*>* itemsList;
public:        
	Category(const std::string& category="");        
	~Category();        
	static std::set<Category*>* listObjects();
	const std::string& getName() const;
	const int getId() const; 
	std::list<Item*>* getItems() const;
	void addItem(Item* newItem);
	void removeItem(Item* item);
};

std::ostream& operator<<(std::ostream& out, Category* category);

#endif //CATEGORY_H
