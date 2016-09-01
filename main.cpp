#include <iostream>
#include "Base.h"
#include "Customer.h"
#include "Item.h"
#include "Category.h"
#include "Order.h"




int main() 
{
    Customer* cust = new Customer("john","dou");
    Customer* cust1 = new Customer("woou","chan");
    Customer* cust2 = new Customer("max","blanco");
    Customer* cust3 = new Customer("tony","dja");
    
	
    Category* smartphone = new Category("SMARTPHONE");
    Category* notebook = new Category("NOTEBOOK");
    Category* tv = new Category("TV");
    Category* games = new Category("GAMES");
    
    Item* smart = new Item(smartphone, "Sumsung smart1");
    Item* smart2 = new Item(smartphone, "Sumsung smart2");
    Item* note = new Item(notebook, "Sumsung note1");
    Item* note2 = new Item(notebook, "Sumsung note2");
    
    Order* order1 = new Order(cust, smart);
    Order* order2 = new Order(cust, smart);
    


    /*
    std::cout << order1;
    
    std::list<Item*>* listitems = order1->getItems();
    std::list<Item*>::iterator it = listitems->begin();
    
    //std::cout << "----order1 Item-----" << listitems->size() << std::endl; 
    
    
    for ( int i = listitems->size(); i > 0; ++it, i-- ){
    std::cout << "---- Item-----" << std::endl;
    std::cout << *it << '\n';
    }
     */
     
    /*
    
    order1->addItem(smart2);
    order1->addItem(note);
    order1->addItem(note2);
    std::cout << "----add 3 Items-----" << std::endl;
    
    listorder = order1->getItems();
    for (it=listorder->begin(); it!=listorder->end(); ++it)
    std::cout << *it << '\n';
    
    order1->addItem(note2);
    std::cout << "----add 1 Items-----" << std::endl;
    listorder = order1->getItems();
    for (it=listorder->begin(); it!=listorder->end(); ++it){
    std::cout << *it << '\n';
    }
    */
    
    /*
    std::cout << "----------smart in Orders -----------" << '\n';
    std::map<int , Order*>* orderlist = smart->getOrders(); 
    std::map<int , Order*>::iterator itorders = orderlist->begin();
    
    std::cout << "----orders: " << orderlist->size() << std::endl;
    
    for (int i = orderlist->size(); i > 0; ++itorders, i--){
    std::cout << itorders->second << '\n';
    }
    
    
    
    std::cout << "----------Delete Order1 -----------" << '\n';
    
    orderlist = smart->getOrders(); 
    itorders = orderlist->begin();
    
    std::cout << "----orders: " << orderlist->size() << std::endl;
    
    for (int i = orderlist->size(); i > 0; ++itorders, i--){
    std::cout << itorders->second << '\n';
    }
     */
   
      
    /*
    std::set<Category*>* catlist = Category::listObjects();
    std::set<Category*>::iterator it;
    for (it=catlist->begin(); it!=catlist->end(); ++it)
    std::cout << *it << '\n';

    
    std::set<Customer*>* objlist = Customer::listObjects();
    std::set<Customer*>::iterator it1;
    for (it1 = objlist->begin(); it1 !=objlist->end(); ++it1)
    std::cout << *it1 << '\n';
    
    std::set<Order*>* ordlist = Order::listObjects();
    std::set<Order*>::iterator it2;
    for (it2 = ordlist->begin(); it2 !=ordlist->end(); ++it2)
    std::cout << *it2 << '\n';
    
    std::set<Item*>* itemlist = Item::listObjects();
    std::set<Item*>::iterator it3;
    for (it3 =itemlist->begin(); it3 !=itemlist->end(); ++it3)
    std::cout << *it3 << '\n';
      */

    
    std::map<int , Order*>* orderlist = cust->getOrders(); 
    std::map<int , Order*>::iterator itorders = orderlist->begin();
    
    std::cout << "----Customer orders: " << orderlist->size() << std::endl;
    
    for (int i = orderlist->size(); i > 0; ++itorders, i--){
    std::cout << itorders->second << '\n';
    }
    
    std::cout << "----------1Delete Order1 -----------" << '\n';
    delete order1;
    std::cout << "----------2Delete Order1 -----------" << '\n';


    orderlist = cust->getOrders(); 
    itorders = orderlist->begin();
    
    std::cout << "----Customer orders: " << orderlist->size() << std::endl;
    
    for (int i = orderlist->size(); i > 0; ++itorders, i--){
    std::cout << itorders->second << '\n';
    }
    
    
      
    delete cust;
    delete cust1;
    delete cust2;
    delete cust3;
    
	
    delete smartphone;
    delete notebook;
    delete tv;
    delete games;
    
    delete smart;
    delete smart2;
    delete note;
    delete note2;
    
    
    delete order2;

    return 0;
}
