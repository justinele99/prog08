//  hash.cpp
#include "hashTable.h"

unsigned int HashTable::hash(string key){
    unsigned int sum = 0;
    for(int i = 0; i < key.length(); i++) {
        sum += ((int)key.at(i))*i;
    }
    return sum%TABLE_SIZE;
}

void HashTable::addHashedKey(unsigned int index, int fileIndex){
    if (t[index] == nullptr){
        t[index] = new TableNode;
        t[index]->fileIndex = fileIndex;
        t[index]->next = nullptr;
    } else {
        TableNode* temp = t[index];

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = new TableNode;
        temp->next->fileIndex = fileIndex;
        temp->next->next = nullptr;
    }
}

void HashTable::clear() {
    for (int i = 0; i < TABLE_SIZE; i++){
        TableNode* temp = t[i];
        clearHelper(temp);
    }
}

void HashTable::clearHelper(TableNode* t){
    if (t != nullptr){
        clearHelper(t->next);
        delete t;
    }
}

HashTable::~HashTable() { clear(); }
