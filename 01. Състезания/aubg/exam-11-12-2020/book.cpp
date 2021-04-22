#include<bits/stdc++.h>
using namespace std;

class Book
{
private:
    string name, author;
public:
    Book();
    Book(string name, string author);
    Book(const Book &book);
    string getName();
    string setName(string value);
    string getAuthor();
    string setAuthor(string value);
};

Book::Book()
{
    setName("");
    setAuthor("");
}

Book::Book(string name, string author)
{
    setName(name);
    setAuthor(author);
}

Book::Book(const Book &book)
{
    setName(book.name);
    setAuthor(book.author);
}

string Book::getName()
{
    //TODO: possible check for the value
    return name;
}
string Book::setName(string value)
{
    name = value;
}
string Book::getAuthor()
{
    return author;
}
string Book::setAuthor(string value)
{
    //TODO: possible check for the value
    author = value;
}

int main()
{
    Book b1;
    cout <<"Book1's name: " <<b1.getName() <<endl;
    cout <<"Book1's author: " <<b1.getAuthor() <<endl;

    Book b2("Harry Potter", "Daniel Shmitt");
    cout <<"Book2's name: " <<b2.getName() <<endl;
    cout <<"Book2's author: " <<b2.getAuthor() <<endl;

    Book b3(b2);
    cout <<"Book3's name: " <<b3.getName() <<endl;
    cout <<"Book3's author: " <<b3.getAuthor() <<endl;
}
