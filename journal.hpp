#include "material.hpp"

#include <string>

#pragma once

class Journal : public Material 
{
public:
    Journal(const std::string& title, const int volume, 
            const int issue, int publish_year, const std::string& subject);

    // copy operations
    Journal(const Journal& other);
    Journal& operator=(const Journal& other);

    // move operations
    Journal(Journal&& other);
    Journal& operator=(Journal&& other);

public:
    void print_details() const override; 
    bool is_borrowed() const override;
    void borrow() override;
    void return_material() override;
    //Material* create() const override;

private:
    int m_volume;
    int m_issue;
    int m_publish_year;
    std::string m_subject;
    bool m_borrowed;
};