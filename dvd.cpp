#include "dvd.hpp"
#include <iostream>

DVD::DVD(const std::string& title, int release_year, const std::string& director, int duration)
    : Material(title)
    , m_release_year(release_year)
    , m_director(director)
    , m_duration(duration)
    , m_borrowed(false)
{
}

DVD::DVD(const DVD& other)
    : Material(other.m_title)
    , m_release_year(other.m_release_year)
    , m_director(other.m_director)
    , m_duration(other.m_duration)
    , m_borrowed(other.m_borrowed)
{
}

DVD& DVD::operator=(const DVD& other)
{
    if (this != & other) {
        m_title = other.m_title;
        m_release_year = other.m_release_year;
        m_director = other.m_director;
        m_duration = other.m_duration;
        m_borrowed = other.m_borrowed;
    }
    return *this;
}

DVD::DVD(DVD&& other)
    : Material(std::move(other.m_title))
    , m_release_year(other.m_release_year)
    , m_director(std::move(other.m_director))
    , m_duration(other.m_duration)
    , m_borrowed(other.m_borrowed)
{
}

DVD& DVD::operator=(DVD&& other)
{
    if (this != &other) {
        m_title = other.m_title;
        m_release_year = other.m_release_year;
        m_director = std::move(other.m_director);
        m_duration = other.m_duration;
        m_borrowed = other.m_borrowed;
    }
    return *this;
}

void DVD::print_details() const  
{
    std::cout << "DVD: " << m_title << std::endl;
    std::cout << "Release Year: " << m_release_year << std::endl;
    std::cout << "Director: " << m_director << std::endl;
    std::cout << "Duration (in minutes): " << m_duration << std::endl;
    std::cout << "Borrowed: " << (m_borrowed ? "Yes" : "No") << std::endl;  
}

bool DVD::is_borrowed() const  
{
    return m_borrowed;
}

void DVD::borrow() 
{
    m_borrowed = true;
}

void DVD::return_material() 
{
    m_borrowed = false;
}

Material* DVD::create() const 
{
    return new DVD(*this);
}