//  folder.cpp
#include "folder.h"
#include <dirent.h>
#include <string>
#include <algorithm>
#include <iostream>

Folder::Folder(string path) {
    if(path.back() != '/') {
        this->path = path + "/";
    } else {
        this->path = path;
    }
}

int Folder::loadFileNames() {
    DIR *direct;
    struct dirent *dirent;

    if((direct  = opendir(path.c_str())) == nullptr) {
        cout << "Error(" << errno << "): " << this->path << endl;
        return errno;
    }
    while ((dirent = readdir(direct)) != nullptr) {
        this->fileNames.emplace_back(dirent->d_name);
    }

    closedir(direct);
    fileNames.erase(fileNames.begin());
    fileNames.erase(fileNames.begin());
    return 0;
}
