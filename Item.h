#ifndef ITEM_H
#define ITEM_H


#include <map>
#include <set>
#include <functional>
#include <exception>
#include "Base.h"
#include "Category.h"
#include "Order.h"


class Category;
class Order;


class Item : public Base {    
private:
    std::string itemName;
    Category* category;
    static int globalId;
    static std::set<Item*>* objectsList; 
    std::map<int, Order*>* ordersList;
public:        
	Item(Category* category, const std::string& itemName="NewItem");        
	~Item();        
	static std::set<Item*>* listObjects();
	const std::string& getItem() const;
	const int getId() const; 
	const Category* getCategory();
	void setCategory(Category* category);
	std::map<int , Order*>* getOrders() const;
	void addOrder(Order* order);
	void removeOrder(Order* order);
};

std::ostream& operator<<(std::ostream& out, Item* item);

#endif //ITEM_H