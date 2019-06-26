/*
 * File:   String.h
 * Author: igui
 *
 * Created on 29 de mayo de 2011, 06:53 PM
 */

#include "interfaces/ICollectible.h"
#include "interfaces/OrderedKey.h"

#ifndef KEYSTRING_H
#define	KEYSTRING_H
/**
 *  Implementación simple del datatype String que hereda tanto de ICollectible
 *  como de HashedKey
 */
class KeyString : public ICollectible, public OrderedKey
{
private:
	std::string s;
public:
    // construye el Datatype a partir de un puntero a caracter
	KeyString(std::string );
    
    // da el valor del string
    std::string getValue() const;
    
    ComparisonRes compare(OrderedKey *k) const;
    
    virtual ~KeyString();
    
};

#endif	/* KEYSTRING_H */

