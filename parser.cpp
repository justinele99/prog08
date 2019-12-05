//  parser.cpp
#include "parser.h"
#include <fstream>
#include <string>
#include <deque>
#include <cctype>

Parser::Parser() { chunkSize = 6; }
Parser::Parser(int size) { chunkSize = size; }

void Parser::loadWords(const string& path){
    ifstream file;
    file.open(path);
    string word;

    while (!file.eof()){
        file >> word;
        words.push_back(word);
    }
}

void Parser::makeChunks() {
    while(words.size() > chunkSize) {
        string chunk;
        string word;
        
        for (int i = 0; i < chunkSize; ++i) {
            word = words.at(i);
            for (string::iterator j = word.begin(); j < word.end(); j++) {
                if(!isalnum(*j)){
                    word.erase(j);
                }
            }
            chunk += word;
        }
        words.erase(words.begin());
        chunks.push_back(chunk);
    }
}

string Parser::getChunk(){
    string chunk = chunks.front();
    chunks.pop_front();
    return chunk;
}

void Parser::clearWords() { words.clear(); }
bool Parser::isHashingDone() { return chunks.empty(); }
