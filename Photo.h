#ifndef PHOTO_H
#define PHOTO_H
#include "Date.h"

#include <iostream>
#include <string>

using namespace std;
class Photo
{
public:
    Photo();
    Photo(const string &title, const Date &date, const string &content);
    Photo(const Photo &photo);

    // other
    bool equals(const string &title);
    void print() const;
    void display() const;

private:
    string title;
    string content;
    Date date;
};
#endif
