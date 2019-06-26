/* 
 * File:   Integer.h
 * Author: igui
 *
 * Created on 28 de mayo de 2011, 08:55 PM
 */

#include "interfaces/ICollectible.h"
#include "interfaces/OrderedKey.h"


#ifndef _KEYINTEGER_H
#define	_KEYINTEGER_H

// datatype para representar un entero
class KeyInteger: public ICollectible, public OrderedKey
{
private:
    const int val;
public:
	KeyInteger(int i);
    int getValue() const;
    ComparisonRes compare(OrderedKey *k) const;
};


#endif	/* _INTEGER_H */

