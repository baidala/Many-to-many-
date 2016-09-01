#ifndef ORDER_H
#define ORDER_H


#include <set>
#include <list>
#include "Base.h"
#include "Customer.h"
#include "Item.h"

class ZeroSizeOrderException {};
class Item;
class Customer;

class Order : public Base {    
private:
    static int globalId;
    static std::set<Order*>* objectsList; 
    std::list<Item*>* itemsList;
    Customer* customer;
    Item* item;
public:        
	Order(Customer* customer, Item* item);        
	~Order();        
	static std::set<Order*>* listObjects();
	const int getId() const; 
	const Customer* getCustomer();
	std::list<Item*>* getItems() const;
	void addItem(Item* newItem);
	void removeItem(Item* item);

};

std::ostream& operator<<(std::ostream& out, Order* order);

#endif //ORDER_H