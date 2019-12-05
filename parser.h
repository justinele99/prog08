//  parser.h
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
class Parser {
private:
    int chunkSize;
    vector<string> words;
    deque<string> chunks;
    
public:
    Parser();
    Parser(int size);

    // Function: loadWords
    // Fills words vector<string> with words from file
    void loadWords(const string& path);

    // Function: makeChunks()
    // Makes chunks from words and pushes into que
    void makeChunks();

    // Function: getChunk()
    // Pops chunks from que to compare
    string getChunk();

    void clearWords();
    bool isHashingDone();
};

#endif
