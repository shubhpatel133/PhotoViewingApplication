#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#include <iostream>
#include <string>
#include "Photo.h"

using namespace std;
class PhotoArray
{
public:
    PhotoArray();
    PhotoArray(const PhotoArray &photoArray);
    ~PhotoArray();
    bool isFull() const;
    // member functions
    bool add(Photo *photo);
    bool add(int index, Photo *photo);

    Photo *get(const string &title);
    Photo *get(int index);

    Photo *remove(const string &title);
    Photo *remove(int index);
    int size() const;

private:
    Photo **photos;
    int photoCount;
};
#endif