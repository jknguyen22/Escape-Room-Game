#ifndef ITEM_HPP
#define ITEM_HPP

//#include <cstdlib>

#include <iostream>

using std::string;

class Item {

protected:
    bool isNote = false;
    bool isHomework = false;
    bool isSpoon = false;
    bool isSock = false;
    bool isWeed = false;
    bool isFish = false;

    int itemNumber;

public:
    Item(int itemValue);
    bool getNote();
    bool getHomework();
    bool getSpoon();
    bool getSock();
    bool getWeed();
    bool getFish();
    int getItemNumber();

    void setNote(bool val);
    void setHomework(bool val);
    void setSpoon(bool val);
    void setSock(bool val);
    void setWeed(bool val);
    void setFish(bool val);
    void setItemNumber(int val);

};


#endif //ITEM_HPP
