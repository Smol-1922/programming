#ifndef List_H
#define List_H
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void reset_list();
	void push_back(int); // adding to the end of the list
	void push_front(int); // adding to the top of the list
	void pop_back(); // deleting the last element
	void pop_front(); // deleting the first element
	void insert(int, unsigned int); // adding an item by index (inserting before an item that was previously available by this index)
	int at(unsigned int); // getting an item by index.
	void remove(unsigned int); // deleting an item by index
	unsigned int get_size(); // getting the list size
	void print_to_console(); // output list items to the console using a separator
	void clear(); // deleting all list items
	void set(unsigned int, int); // replacing an element by index with the passed element
	bool isEmpty(); // checking if the list is empty
	bool contains(LinkedList*); // checking for the content of another list in the list
	
private:
	class Node {
	public:
		int data;
		Node* next;

		Node(int data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~Node() 
		{

		}

	};
	Node* tail;
	Node* head;
	unsigned int size;
};
#endif