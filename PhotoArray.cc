#include "PhotoArray.h"
#include "defs.h"
using namespace std;
PhotoArray::PhotoArray()
{
    photos = new Photo *[MAX_ARRAY];
    photoCount = 0;
}
PhotoArray::PhotoArray(const PhotoArray &photoArray)
{
    photos = new Photo *[MAX_ARRAY];
    photoCount = photoArray.photoCount;
    for (int i = 0; i < photoArray.photoCount; i++)
    {
        photos[i] = new Photo(*photoArray.photos[i]);
    }
}
PhotoArray::~PhotoArray()
{
    for (int i = 0; i < photoCount; i++)
    {
        delete photos[i];
    }
    delete[] photos;
}
// returns if array is full
bool PhotoArray::isFull() const
{
    return (photoCount == MAX_ARRAY);
}
// adds to back of array
bool PhotoArray::add(Photo *photo)
{
    if (photoCount < MAX_ARRAY)
    {
        photos[photoCount] = photo;
        photoCount++;
        return true;
    }
    else
    {
        return false;
    }
}
// adds to index
bool PhotoArray::add(int index, Photo *photo)
{
    if (photoCount < MAX_ARRAY && photoCount >= index && index >= 0) // Checks if array is full and if index is valid
    {
        for (int i = photoCount; i > index; i--) //
        {
            photos[i] = photos[i - 1];
        }
        photos[index] = photo;
        photoCount++;
        return true;
    }
    else
    {
        return false;
    }
}
// gets photo pointer with title
Photo *PhotoArray::get(const string &title)
{
    for (int i = 0; i < photoCount; i++)
    {
        if (photos[i]->equals(title))
        {
            return photos[i];
        }
    }
    return NULL;
}
// gets photo pointer at the index
Photo *PhotoArray::get(int index)
{
    if (index >= 0 && index < photoCount)
    {
        return photos[index];
    }
    else
    {
        return NULL;
    }
}
// removes photo with title and returns the pointer
Photo *PhotoArray::remove(const string &title)
{
    for (int i = 0; i < photoCount; i++)
    {
        if (photos[i]->equals(title))
        {
            Photo *tempPhoto = photos[i];
            for (int j = i; j < photoCount; j++)
            {
                photos[j] = photos[j + 1];
            }
            photoCount--;
            return tempPhoto;
        }
    }
    return NULL;
}
// removes photo at index and returns the pointer
Photo *PhotoArray::remove(int index)
{
    if (index >= 0 && index < photoCount)
    {
        Photo *tempPhoto = photos[index];
        for (int i = index; i < photoCount; i++)
        {
            photos[i] = photos[i + 1];
        }
        photoCount--;
        return tempPhoto;
    }
    else
    {
        return NULL;
    }
}
// returns the number of photos in the array
int PhotoArray::size() const
{
    return photoCount;
}
