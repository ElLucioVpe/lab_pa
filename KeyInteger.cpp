#include <stddef.h>
#include <stdexcept>
#include "KeyInteger.h"

KeyInteger::KeyInteger(int i):
        val(i)
{
}

int KeyInteger::getValue() const
{
    return val;
}

ComparisonRes KeyInteger::compare(OrderedKey* k) const
{
	KeyInteger*i = dynamic_cast<KeyInteger*>(k);
    if(i == NULL) // no se puede comparar si no es entero
        throw std::invalid_argument("Invalid key k");
    if(i->val == val)
        return EQUAL;
    else if(i->val > val)
        return GREATER;
    else
        return LESSER;
}
