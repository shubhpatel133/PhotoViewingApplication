#include "PhotoGram.h"
#include "Album.h"
#include "Photo.h"
#include "AlbumArray.h"
#include <iostream>
#include <string>
using namespace std;
PhotoGram::PhotoGram()
{
    albumArray = new AlbumArray();
}
PhotoGram::~PhotoGram()
{
    for (int i = 0; i < albumArray->size(); i++)
    {
        Album *album = albumArray->get(i);
        delete album;
    }
    delete albumArray;
}
// adds the album to the server(array) based on title and discription if theres room
bool PhotoGram::addAlbum(const string &title, const string &description)
{
    Album *album = new Album(title, description);
    if (albumArray->add(album)) // if album is added
    {
        return true;
    }
    else
    {
        delete album;
        cout << "Adding album failed in PhotoGram, due to not enough space!" << endl;
        return false;
    }
}
// add photo to the album
bool PhotoGram::addPhoto(const string &albumTitle, const Photo &photo)
{
    Album *album = albumArray->get(albumTitle); // get the album
    if (album != NULL)
    {
        Photo *pointToPhoto = new Photo(photo);
        if (album->addPhoto(pointToPhoto)) // if photo is added to album
        {
            return true;
        }
        else
        {
            cout << "addPhoto Failed! Album is full!" << endl;
            return false;
        }
    }
    else
    {
        cout << "addPhoto Failed! Album wasn't found within PhotoGram!" << endl;
        return false;
    }
}
// removes the album from the server(array) based on title
bool PhotoGram::removeAlbum(const string &title)
{
    Album *album;
    if (albumArray->get(title))
    {
        album = albumArray->remove(title);
        delete album;
        return true;
    }
    else
    {
        cout << "removeAlbum Failed! Album not found within PhotoGram servers!" << endl;
        return false;
    }
}
bool PhotoGram::removePhoto(const string &albumTitle, const string &photoTitle)
{
    Album *album = albumArray->get(albumTitle);
    Photo *photo;
    if (album != NULL)
    {
        photo = album->getPhoto(photoTitle);
        if (photo != NULL)
        {
            photo = album->removePhoto(photoTitle);
            delete photo;
            return true;
        }
        else
        {
            cout << "removePhoto Failed! Photo was not found within PhotoGram servers!" << endl;
            return false;
        }
    }
    else
    {
        cout << "removePhoto Failed! Album was not found within PhotoGram servers!" << endl;
        return false;
    }
}
// downloads the album with the given title, returns pointer if exist
Album *PhotoGram::downloadAlbum(const string &albumTitle)
{
    Album *album = albumArray->get(albumTitle);
    if (album != NULL)
    {
        return album;
    }
    else
    {
        cout << "downloadAlbum Failed! Album not found within PhotoGram servers!" << endl;
        return NULL;
    }
}
// downloads the photo from the album with the given title, returns pointer if exist
Photo *PhotoGram::downloadPhoto(const string &albumTitle, const string &photoTitle)
{
    Album *album = albumArray->get(albumTitle);
    Photo *photo;
    if (album != NULL)
    {
        photo = album->getPhoto(photoTitle);
        if (photo != NULL)
        {
            return photo;
        }
        else
        {
            cout << "downloadPhoto Failed! Photo was not found within PhotoGram servers!" << endl;
            return NULL;
        }
    }
    else
    {
        cout << "downloadPhoto Failed! Album was not found within PhotoGram servers!" << endl;
        return NULL;
    }
}
// print the album
void PhotoGram::printAlbums()
{
    Album *album;
    for (int i = 0; i < albumArray->size(); i++) // loops
    {
        album = albumArray->get(i);
        album->print(); // print the album
    }
}
// display the album
void PhotoGram::displayAlbums()
{
    Album *album;
    for (int i = 0; i < albumArray->size(); i++) // loops the array
    {
        album = albumArray->get(i); // get the album
        album->display();
    }
}