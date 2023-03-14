#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Photo.h"
#include "PhotoArray.h"
using namespace std;
class Album
{
public:
    // constructor
    Album(const string &title, const string &description);
    // deep copy constructor
    Album(const Album &album);
    // Destructor
    ~Album();
    string getTitle() const;
    bool equals(string title) const;
    bool lessThan(Album &alb) const;
    bool addPhoto(Photo *photo);
    bool addPhoto(int index, Photo *photo);
    Photo *getPhoto(const string &title);
    Photo *getPhoto(int index);
    Photo *removePhoto(const string &title);
    Photo *removePhoto(int index);
    void print() const;
    void display() const;

private:
    PhotoArray *photos;
    string title;
    string description;
};
#endif
