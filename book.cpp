#include "book.hpp"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, const int publish_year, const std::string& genre, const int pages)
    : Material(title)
    , m_author(author)
    , m_publish_year(publish_year)
    , m_genre(genre)
    , m_pages(pages)
    , m_borrowed(false)
{
}

Book::Book(const Book& other)
    : Material(other.m_title)
    , m_author(other.m_author)
    , m_publish_year(other.m_publish_year)
    , m_genre(other.m_genre)
    , m_pages(other.m_pages)
    , m_borrowed(other.m_borrowed)  
{
}

Book& Book::operator=(const Book& other)
{
    if (this != &other) {
        m_title = other.m_title;
        m_author = other.m_author;
        m_publish_year = other.m_publish_year;
        m_genre = other.m_genre;
        m_pages = other.m_pages;
        m_borrowed = other.m_borrowed;
    }
    return *this;
}

Book::Book(Book&& other)
    : Material(std::move(other.m_title))
    , m_author(std::move(other.m_author))
    , m_publish_year(other.m_publish_year)
    , m_genre(std::move(other.m_genre))
    , m_pages(other.m_pages)
    , m_borrowed(other.m_borrowed) 
{
}

Book& Book::operator=(Book&& other)
{
    if (this != &other) {
        m_title = std::move(other.m_title);
        m_author = std::move(other.m_author);
        m_publish_year = other.m_publish_year;
        m_genre = std::move(other.m_genre);
        m_pages = other.m_pages;
        m_borrowed = other.m_borrowed;
    }
    return *this;
}

void Book::print_details() const 
{
    std::cout << "Book: " << m_title << std::endl;
    std::cout << "Author: " << m_author << std::endl;
    std::cout << "Publish Year: " << m_publish_year << std::endl;
    std::cout << "Genre: " << m_genre << std::endl;
    std::cout << "Number of Pages: " << m_pages << std::endl;
    std::cout << "Borrowed: " << (m_borrowed ? "Yes" : "No") << std::endl;
}

bool Book::is_borrowed() const  
{
    return m_borrowed;
}

void Book::borrow() 
{
    m_borrowed = true;
}

void Book::return_material() 
{
    m_borrowed = false;
}

/*Material* Book::create() const 
{
    return new Book(*this);
}*/