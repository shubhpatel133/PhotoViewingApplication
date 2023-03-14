#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include <iostream>
#include <string>

#include "Album.h"
#include "defs.h"
using namespace std;
class AlbumArray
{
public:
    // constructor
    AlbumArray();
    AlbumArray(const AlbumArray &albumArray);

    // Destructor
    ~AlbumArray();
    // member function
    bool add(Album *newAlbum);
    bool isFull() const;
    Album *get(const string &title);
    Album *get(int index) const;
    Album *remove(const string &title);
    Album *remove(int index);
    int size() const;

private:
    Album **albumArray;
    int albumCount;
};
#endif