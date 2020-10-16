#include "List.h"
int main()
{
	LinkedList* List = new LinkedList;
	LinkedList* List1 = new LinkedList;
	List->get_size(); 
	List->isEmpty();
	List->push_back(2);
	List->push_front(5);
	List->push_back(1);
	List->print_to_console();// output list items to the console using a separator
	List->pop_back(); 
	List->pop_front();
	List->print_to_console();
	List->push_front(5);
	List->push_back(1);
	List->print_to_console();
	List->insert(0, 1); 
	List->print_to_console();
	List->at(2); 
	List->remove(2);
	List->print_to_console();
	List->get_size();
	List->set(0, -1);
	List->print_to_console();
	List->isEmpty(); 
	List->push_back(2);
	List->push_back(3);
	List->push_back(4);
	List->push_back(5);
	List1->push_back(3);
	List1->push_back(4);
	List->contains(List1);
	List->clear();
	List1->clear();
	return 0;
}