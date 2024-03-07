#pragma once
#include<iostream>
#include <vector>

class RepositoryException : public std::exception {
private:
	std::string _message;
public:
	//constructor
	RepositoryException(std::string message) : _message{ message } {}
	//getter function for the message

	std::string message() const {
		return _message;
	}
};

class ValidatorException : public std::exception {
private:
	std::string message;

public:
	ValidatorException(const std::string& message) : message{ message } {}
	const char* what() const noexcept override { return message.c_str(); }
};


class InputException {
private:
	std::string _message;
public:
	//constructor
	InputException(std::string message) : _message{ message } {}

	//getter function for the message
	std::string message() const {
		return _message;
	}
};