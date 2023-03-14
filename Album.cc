#include "Album.h"
#include "Photo.h"
#include "PhotoArray.h"
#include "defs.h"
using namespace std;
Album::Album(const string &title, const string &description)
{
    this->title = title;
    this->description = description;
    this->photos = new PhotoArray();
}
Album::Album(const Album &alb)
{
    this->title = alb.title;
    this->description = alb.description;
    this->photos = new PhotoArray(*alb.photos);
}
Album::~Album()
{
    delete photos;
}
// returns title
string Album::getTitle() const
{
    return title;
}
// sees if the album title matches
bool Album::equals(string title) const
{
    if (this->title == title)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Compares calling album and given album based title
bool Album::lessThan(Album &alb) const
{
    if (this->title < alb.title) // if the title is less in alhpabetical order
    {
        return true;
    }
    else
    {
        return false; // otherwise return false
    }
}
// if the photo aaray is full it returns false otherwise it adds photo to the array
bool Album::addPhoto(Photo *photo)
{
    if (photos->isFull())
    {
        return false;
    }
    else
    {
        return photos->add(photo);
    }
}
// same thing as function above but this time its via index.
bool Album::addPhoto(int index, Photo *photo)
{
    if (photos->isFull())
    {
        return false;
    }
    else
    {
        return photos->add(index, photo);
    }
}
// uses method from PhotoArray class
Photo *Album::getPhoto(const string &title)
{
    return photos->get(title);
}
////uses method from PhotoArray class
Photo *Album::getPhoto(int index)
{
    return photos->get(index);
}
////uses method from PhotoArray class
Photo *Album::removePhoto(const string &title)
{
    return photos->remove(title);
}
////uses method from PhotoArray class
Photo *Album::removePhoto(int index)
{
    return photos->remove(index);
}
// prints the metadata
void Album::print() const
{
    cout << "Album title: " << title << endl;
    cout << "Album description: " << description << endl;
}
// displats the photo by going through the array, getting it and then displaying
void Album::display() const
{
    this->print();
    cout << "photo within this album: " << endl;
    for (int i = 0; i < photos->size(); i++)
    {
        photos->get(i)->display();
    }
}