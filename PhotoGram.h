#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H
#include <iostream>
#include <string>
#include "Photo.h"
#include "Album.h"
#include "AlbumArray.h"
using namespace std;
class PhotoGram
{

public:
    // constructor
    PhotoGram();
    ~PhotoGram();
    // add & remove
    bool addAlbum(const string &title, const string &description);
    bool addPhoto(const string &albumTitle, const Photo &photo);
    bool removeAlbum(const string &title);
    bool removePhoto(const string &albumTitle, const string &photoTitle);
    // Client services
    Album *downloadAlbum(const string &albumTitle);
    Photo *downloadPhoto(const string &albumTitle, const string &photoTitle);
    // print
    void printAlbums();
    void displayAlbums();

private:
    // AlbumArray pointer
    AlbumArray *albumArray;
};
#endif