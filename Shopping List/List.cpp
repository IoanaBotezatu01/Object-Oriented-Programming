#include "List.h"

List::List() :category{ "" }, name{ "" }, quantity{ 0 }
{
}

List::List(const std::string& _category, const std::string& _name, const int _quantity) :category{ _category }, name{ _name }, quantity{ _quantity }
{
}

List::List(const List& list)
{
	this->category = list.category;
	this->name = list.name;
	this->quantity = list.quantity;
}

std::string List::getCategory() const
{
	return this->category;
}

std::string List::getName()const
{
	return this->name;
}

int List::getQuantity()const
{
	return this->quantity;
}

std::string List::toString()
{
	auto strQ = std::to_string(this->quantity);
	return this->category + "|" + this->name + "|" + strQ;
}
