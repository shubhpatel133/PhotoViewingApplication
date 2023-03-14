#include "Photo.h"
#include "Date.h"
#include <string>
using namespace std;

Photo::Photo()
{
    this->title = "";
    this->content = "";
    this->date = Date();
}
Photo::Photo(const string &title, const Date &date, const string &content)
{
    this->title = title;
    this->content = content;
    this->date = date;
}
Photo::Photo(const Photo &photo)
{
    title = photo.title;
    content = photo.content;
    date = photo.date;
}
bool Photo::equals(const string &title)
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
// prints the info
void Photo::print() const
{
    cout << "Photo: " << title << " taken on ";
    date.print();
    cout << endl;
}
// prints the info and the content
void Photo::display() const
{
    this->print();
    cout << " Content of the photo: " << content << endl;
}