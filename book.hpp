#include "material.hpp"

#include <string>

class Book : public Material 
{
public:
    Book(const std::string& title, const std::string& author, 
            const int publish_year, const std::string& genre, const int pages);

    // copy operations   
    Book(const Book& other);
    Book& operator=(const Book& other); 

    // move operations
    Book(Book&& other);
    Book& operator=(Book&& other);

public:
    void print_details() const override;
    bool is_borrowed() const override;
    void borrow() override;
    void return_material() override;
    Material* create() const override;

private:
    std::string m_author;
    int m_publish_year;
    std::string m_genre;
    int m_pages;
    bool m_borrowed;
};