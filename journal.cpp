#include "journal.hpp"
#include <iostream>

Journal::Journal(const std::string& title, const int volume, const int issue, int publish_year, const std::string& subject)
    : Material(title)
    , m_volume(volume)
    , m_issue(issue)
    , m_publish_year(publish_year)
    , m_subject(subject)
    , m_borrowed(false)
{
}

Journal::Journal(const Journal& other)
    : Material(other.m_title)
    , m_volume(other.m_volume)
    , m_issue(other.m_issue)
    , m_publish_year(other.m_publish_year)
    , m_subject(other.m_subject)
    , m_borrowed(other.m_borrowed)   
{
}

Journal& Journal::operator=(const Journal& other)
{
    if (this != &other) {
        m_title = other.m_title;
        m_volume = other.m_volume;
        m_issue = other.m_issue;
        m_publish_year = other.m_publish_year;
        m_subject = other.m_subject;
        m_borrowed = other.m_borrowed;
    }
    return *this;
}

Journal::Journal(Journal&& other)
    : Material(std::move(other.m_title))
    , m_volume(std::move(other.m_volume))
    , m_issue(std::move(other.m_issue))
    , m_publish_year(other.m_publish_year)
    , m_subject(std::move(other.m_subject))
    , m_borrowed(other.m_borrowed)
{
}

Journal& Journal::operator=(Journal&& other)
{
    if (this != &other) {
        m_title = std::move(other.m_title);
        m_volume = std::move(other.m_volume);
        m_issue = std::move(other.m_issue);
        m_publish_year = other.m_publish_year;
        m_subject = std::move(other.m_subject);
        m_borrowed = other.m_borrowed;
    }
    return *this;
}

void Journal::print_details() const  
{
    std::cout << "Journal: " << m_title << std::endl;
    std::cout << "Volume: " << m_volume << std::endl;
    std::cout << "Issue: " << m_issue << std::endl;
    std::cout << "Publish Year: " << m_publish_year << std::endl;
    std::cout << "Subject: " << m_subject << std::endl;  
    std::cout << "Borrowed: " << (m_borrowed ? "Yes" : "No") << std::endl;  
}

bool Journal::is_borrowed() const  
{
    return m_borrowed;
}

void Journal::borrow() 
{
    m_borrowed = true;
}

void Journal::return_material() 
{
    m_borrowed = false;
}

Material* Journal::create() const  
{
    return new Journal(*this);
}