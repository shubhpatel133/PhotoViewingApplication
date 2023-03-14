#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Photo.h"
#include "Album.h"
#include "AlbumArray.h"
#include "PhotoGram.h"

using namespace std;
class Client
{
public:
    // constructor
    Client();
    ~Client();
    // Client Services
    bool downloadAlbum(PhotoGram *pg, const string &albumTitle);
    bool displayOnlinePhoto(PhotoGram *pg, const string &albumTitle, const string &photoTitle);
    bool displayLocalPhoto(const string &albumTitle, const string &photoTitle);
    // print
    void printLocalAlbums() const;
    void displayLocalAlbums() const;

private:
    // AlbumArray Pointer
    AlbumArray *albumArray;
};
#endif