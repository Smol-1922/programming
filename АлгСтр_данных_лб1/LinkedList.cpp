#include"List.h"
#include <stdexcept>
#include<iostream>
LinkedList::LinkedList() 
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
LinkedList::~LinkedList() 
{
	clear();
}
void LinkedList::reset_list()
{
	tail=nullptr;
	head = nullptr;
}
unsigned int LinkedList::get_size()
{
	return size;
}
void LinkedList::push_back(int date) 
{
	if (size == 0) {
		head = new Node(date);
		tail = head;
	}
	else {
		tail->next = new Node(date);
		tail = tail->next;
	}
	size++;
}
void LinkedList::push_front(int date)
{
	if (size == 0) {
		head = new Node(date);
		tail = head;
	}
	else {
		head = new Node(date,head);
	}
	size++;
}
void LinkedList::pop_back(){
	if (size == 0) return;
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}
void LinkedList::pop_front() {
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = head;
		head = head->next;
		delete current;
	}
	size--;
}
void LinkedList::insert(int date, unsigned int index) {
	if (index >= size) {
		throw std::out_of_range("Index is greater than list size");
	}
	else {
		if (index == 0) {
			push_front(date);
		}
		else {
			unsigned int i = 0;
			Node* current = head;
			while (i < index-1) {
				current = current->next;
				i++;
			}
			current->next = new Node(date, current->next);
			size++;
		}
		
	}
}
void LinkedList::remove(unsigned int index)
{
	if (index >= size) {
		throw std::out_of_range("Index is greater than list size");
	}
	else {
		if (index == 0) {
			return pop_front();
		}
		if (index == size - 1) {
			return pop_back();
		}
		else {
			unsigned int i = 0;
			Node* current = head;
			while (i < index-1) {
				current = current->next;
				i++;
			}
			Node* receding =current;
			current->next = current->next->next;
			receding= nullptr;
			size--;
		}
		
	}
}
int LinkedList::at(unsigned int index)
{
	if (index >= size) {
		throw std::out_of_range("Index is greater than list size");
	}
	else {
		Node* current = head;
		unsigned int counter = 0;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}
void LinkedList::print_to_console() {
	if (size == 0) {
		return;
	}
	else {
		unsigned int index = get_size();
		Node* current = head;
		while (index != 0) {
			std::cout << current->data<< " ";
			current = current->next;
			index--;
		}
		std::cout << std::endl;
	}
}
void LinkedList::clear() 
{
	while (size != 0)
	{
		pop_front();
	}
}
void LinkedList::set(unsigned int index, int date)
{
	if (index >= size) {
		throw std::out_of_range("Index is greater than list size");
	}
	else {
			Node* current = head;
			int i = 0;
			while (index != i) {
				current = current->next;
				i++;
			}
			current->data = date;
	}
}
bool LinkedList::isEmpty() {
	if (size != 0) {
		return 0;
	}
	return 1;
}
bool LinkedList::contains(LinkedList* List2)
{
	if (size < List2->size) {
		return false;
	}
	else {
		unsigned int i = 0,match=0;
		Node* current = List2->head;
		while (i != size) {
			if (at(i) == current->data) {
				current = current->next;
				match++;
				if (match == List2->size) {
					return true;
				}
			}
			else {
				current = List2->head;
				match=0;
			}
			i++;
		}
		return false;
	}
}

