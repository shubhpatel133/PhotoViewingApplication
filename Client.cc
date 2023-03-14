#include "Client.h"
Client::Client()
{
    albumArray = new AlbumArray();
}
Client::~Client()
{
    for (int i = 0; i < albumArray->size(); i++)
    {
        Album *album;
        album = albumArray->get(i);
        delete album;
    }
    delete albumArray;
}
bool Client::downloadAlbum(PhotoGram *pg, const string &albumTitle)
{
    Album *album;
    album = pg->downloadAlbum(albumTitle);
    if (album != NULL)
    {
        Album *newAlbum = new Album(*album); // create a new album object
        albumArray->add(newAlbum);
        return true;
    }
    else
    {
        cout << "download Failed!: Album not found within the given Songify server!" << endl;
        return false;
    }
}
bool Client::displayOnlinePhoto(PhotoGram *pg, const string &albumTitle, const string &photoTitle)
{
    Photo *photo;
    photo = pg->downloadPhoto(albumTitle, photoTitle); // download the photo
    if (photo != NULL)                                 // if the photo is downloaded
    {
        photo->display(); // display it
        return true;
    }
    else
    {
        cout << "displayOnlinePhoto Failed!: Photo not found within the given PhotoGram server!" << endl; // error if not downloaded
        return false;
    }
}
bool Client::displayLocalPhoto(const string &albumTitle, const string &photoTitle)
{
    Album *album;
    Photo *photo;
    album = albumArray->get(albumTitle); // get the album
    if (album != NULL)
    {
        photo = album->getPhoto(photoTitle); // get the photo
        if (photo != NULL)
        {
            photo->display(); // display the photo
            return true;
        }
    }
    cout << "displayLocalPhoto Failed!: Photo not found within downloaded catalog!" << endl;
    return false;
}
// goes through the album array and prints all the albums
void Client::printLocalAlbums() const
{
    Album *album;
    for (int i = 0; i < albumArray->size(); i++)
    {
        album = albumArray->get(i);
        album->print();
    }
}
// goes through the album array and displays all the albums
void Client::displayLocalAlbums() const
{
    Album *album;
    for (int i = 0; i < albumArray->size(); i++)
    {
        album = albumArray->get(i);
        album->display();
    }
}
