//
// Created by user on 25.05.2023.
//

#ifndef T3_BOTEZATU_IOANA_DOCUMENT_H
#define T3_BOTEZATU_IOANA_DOCUMENT_H
#include <vector>
#include "string"

class Document {
private:
    std::string  name;
    std::vector<std::string> keywords;
    std::string content;
public:
    Document():name{""},keywords{[]},content{""};
    Document(std::string _name,std::vector<std::string> _keywords,std::string _content):name{_name},keywords{_keywords},content{_content};
    std::string getName(){return this->name;}
    std::vector<std::string> getKeywords(){ this->keywords;}
    std::string  getContent(){ this->content;}
    std::string toString(){return this->name+" | "+ this->keywords+" | "+ this->content};
    ~Document()=default;
};


#endif //T3_BOTEZATU_IOANA_DOCUMENT_H
