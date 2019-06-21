#include "ColCines.cpp"

ColCines::ColCines() {
    cines = new List();
}

void ColCines::add(Usuario * u) {
    cines->add(u);
}

void ColCines::remove(Usuario * u) {
    cines->remove(u);
}

bool ColCines::member(Usuario * u) {
    return cines->member(u);
}

int ColCines::getSize() const {
    return cines->getSize();
}

bool ColCines::isEmpty() const {
    if (this->getSize() == 0){ 
        return true;
    }
    else{
        return false;
    }
}

IIterator* ColCines::getIterator() {
	return cines->getIterator();
}

ColCines::~ColCines() {
    IIterator* it = cines->getIterator();
    while (it->hasCurrent()) {
        Cine* temp = dynamic_cast<Cine*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete cines;
}