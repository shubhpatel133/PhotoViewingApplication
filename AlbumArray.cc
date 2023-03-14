#include "AlbumArray.h"

AlbumArray::AlbumArray()
{
    albumArray = new Album *[MAX_ARRAY];
    albumCount = 0;
}
AlbumArray::AlbumArray(const AlbumArray &albumArray)
{
    this->albumArray = new Album *[MAX_ARRAY];
    this->albumCount = albumArray.albumCount;
    for (int i = 0; i < albumArray.albumCount; i++)
    {
        this->albumArray[i] = new Album(*albumArray.albumArray[i]);
    }
}
AlbumArray::~AlbumArray()
{
    delete[] albumArray;
}
bool AlbumArray::add(Album *newAlbum)
{
    if (albumCount >= MAX_ARRAY)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < albumCount; i++)
        {
            if (newAlbum->lessThan(*albumArray[i]))
            {
                albumCount += 1; // Increase album count by one so everything can be shifted

                for (int j = albumCount; j > i; j--)
                {
                    albumArray[j] = albumArray[j - 1]; // Shifts all the album to the right
                }
                albumArray[i] = newAlbum; // Adds the new album to the array
                return true;
            }
        }
        // If no album exist in array or newAlbum is bigger than all albums in array, we add one to the array
        albumArray[albumCount] = newAlbum;
        albumCount += 1;
        return true;
    }
}
bool AlbumArray::isFull() const
{
    return (albumCount >= MAX_ARRAY);
}
// takes the title and and returns pointer to the album with that title, otherwise null
Album *AlbumArray::get(const string &title)
{
    for (int i = 0; i < albumCount; i++)
    {
        if (albumArray[i]->equals(title))
        {
            return albumArray[i];
        }
    }
    return NULL;
}
// similar to function above but with index, returns the pointer at the index
Album *AlbumArray::get(int index) const
{
    if (index >= 0 && index < albumCount)
    {
        return albumArray[index]; // Returns the album at the index
    }
    else
    {
        return NULL;
    }
}
// removes the album with the title and returns the pointer
Album *AlbumArray::remove(const string &title)
{
    for (int i = 0; i < albumCount; i++)
    {
        if (albumArray[i]->equals(title)) // If the album at the index has the same title as the title we are looking for
        {
            return this->remove(i); // Removes the album at the index with that title
        }
    }
    return NULL;
}
// removes the album at the index and returns the pointer
Album *AlbumArray::remove(int index)
{
    if (index >= 0 && index < albumCount)
    {
        Album *temp = albumArray[index];
        for (int i = index; i < albumCount; i++)
        {
            albumArray[i] = albumArray[i + 1];
        }
        albumCount -= 1; // Decreases the album count by one
        return temp;
    }
    else
    {
        return NULL;
    }
}
// returns the number of albums in the array
int AlbumArray::size() const
{
    return albumCount;
}