#include "Item.hpp"
Item::Item(int itemValue){
    bool isNote = false;
    bool isHomework = false;
    bool isSpoon = false;
    bool isSock = false;
    bool isWeed = false;
    bool isFish = false;

    if (itemValue == 1){
        setNote(true);
        itemNumber = itemValue;
    }
    else if (itemValue == 2){
        setHomework(true);
        itemNumber = itemValue;

    }
    else if (itemValue == 3){
        setSpoon(true);
        itemNumber = itemValue;

    }
    else if (itemValue == 4){
        setSock(true);
        itemNumber = itemValue;

    }
    else if (itemValue == 5){
        setWeed(true);
        itemNumber = itemValue;

    }
    else if (itemValue == 6){
        setFish(true);
        itemNumber = itemValue;

    }
}
bool Item::getNote(){
    return isNote;
}
bool Item::getHomework(){
    return isHomework;
}
bool Item::getSpoon(){
    return isSpoon;
}
bool Item::getSock(){
    return isSock;
}
bool Item::getWeed(){
    return isWeed;
}
bool Item::getFish(){
    return isFish;
}
int Item::getItemNumber(){
    return itemNumber;
}
void Item::setNote(bool val){
    isNote = val;
}
void Item::setHomework(bool val){
    isHomework = val;
}
void Item::setSpoon(bool val){
    isSpoon = val;
}
void Item::setSock(bool val){
    isSock = val;
}
void Item::setWeed(bool val){
    isWeed = val;
}
void Item::setFish(bool val){
    isFish = val;
}
void Item::setItemNumber(int val) {
    itemNumber = val;
}