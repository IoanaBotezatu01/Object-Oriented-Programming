#pragma once
#include <string>
class List
{private:
	std::string category;
	std::string name;
	int quantity;
public:
	List();
	List(const std::string& category, const std::string& name, const int quantity);
	List(const List& list);
	std::string getCategory() const ;
	std::string getName() const;
	int getQuantity() const;
	std::string toString();
	~List() = default;
};

