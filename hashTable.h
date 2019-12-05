//  hashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <sys/types.h>
#include <dirent.h>
#include <cerrno>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TableNode{
    int fileIndex;
    TableNode *next;
};

class HashTable {
private:
    const static unsigned int TABLE_SIZE = 100000;
    TableNode* t[TABLE_SIZE] = {};
    static void clearHelper(TableNode* t);
    
public:
    /* Function: hash()
     * input: key to compare
     * output: new key
     */
    static unsigned int hash(string key);

    static int getTableSize() { return TABLE_SIZE; }
    void addHashedKey(unsigned int index, int fileIndex);
    TableNode* getPointerAt(int index) { return t[index]; };
    void clear();
    ~HashTable();
};

#endif
