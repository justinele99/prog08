//  main.cpp
//  prog08: Cheater
//  Justine Le
//  JL65773
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "folder.h"
#include "parser.h"
#include "matrix.h"
#include "hashTable.h"

using namespace std;
void checkCollisions(TableNode* ptr, Matrix &matrix);
struct result{
    int file1;
    int file2;
    int collisions;
    bool operator < (const result &rhs) {
        return collisions < rhs.collisions;
    }
};

int main(int argc, char *argv[]) {

    //Folder folder("sm_doc_set");
    Folder folder(argv[1]);
    folder.loadFileNames();
    Matrix m(folder.getNumFiles());

    //Parser parse(6);
    Parser parse(atoi(argv[2]));
    HashTable table;

    cout << "Processing files..." << endl;

    for (int i = 0; i < folder.getNumFiles(); i++) {
        parse.loadWords(folder.getPath() + folder.getFileName(i));
        parse.makeChunks();
        parse.clearWords();
        while (!parse.isHashingDone()) {
            table.addHashedKey(HashTable::hash(parse.getChunk()), i);
        }
    }

    for (int i = 0; i < HashTable::getTableSize(); i++) {
        TableNode* ptr = table.getPointerAt(i);
        if (ptr != NULL)
            checkCollisions(ptr, m);
    }
    
    vector<result> results;
    for (int i = 1; i < folder.getNumFiles(); i++) {
        for (int j = i; j < folder.getNumFiles(); j++) {
            int numCollisions = m.getValueAt(i, j);
            if (numCollisions > atoi(argv[3])){
                result temp{};
                temp.file1 = i;
                temp.file2 = j;
                temp.collisions = numCollisions;
                results.push_back(temp);
            }
        }
    }
    cout << endl;
    std::sort(results.begin(), results.end());
    for (int i = ((int)results.size() - 1); i >= 0; i--) {
        cout << results[i].collisions << ": " << folder.getFileName(results[i].file1);
        cout << ", " << folder.getFileName(results[i].file2) << endl;
    }
    cout << endl;
    return 0;
}

void checkCollisions(TableNode* ptr, Matrix &matrix) {
    if(ptr->next == NULL) {
        return;
    } else {
        while (ptr->next != NULL) {
            TableNode* temp = ptr->next;
            int tempRow = ptr->fileIndex;
            while (temp != NULL) {
                int tempCol = temp->fileIndex;
                if(tempRow != tempCol)
                    matrix.incrementbyOne(tempRow, tempCol);
                temp = temp->next;
            }
            ptr = ptr->next;
        }
    }
}
