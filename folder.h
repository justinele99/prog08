//  file.h
#ifndef FOLDER_H
#define FOLDER_H
#include <string>
#include <vector>
#include <iostream>
#include "parser.h"
using namespace std;
class Folder {
private:
    string path;
    vector<string> fileNames;

public:
    Folder() { path = "/"; };
    Folder(string path);

    int loadFileNames();
    string getPath() { return path; }
    string getFileName(int index) { return fileNames[index]; };
    unsigned long getNumFiles() { return fileNames.size(); };
};

#endif
