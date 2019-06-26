#include <stddef.h>
#include <stdexcept>
#include <string.h>
#include "KeyString.h"


KeyString::KeyString(std::string str){
    if(str == "")
        throw std::invalid_argument("str es NULL");
        
	s = str;
}

ComparisonRes KeyString::compare(OrderedKey* k) const
{
	KeyString* str = dynamic_cast<KeyString *>(k);
    if(str == NULL) 
        throw std::invalid_argument("Invalid key k");
    
    int cmp = strcmp(s.c_str(), str->getValue().c_str());
    if(cmp == 0)
        return EQUAL;
    else if(cmp > 0)
        return GREATER;
    else
        return LESSER;
}

std::string KeyString::getValue() const
{
    return s;
}

KeyString::~KeyString(){

}