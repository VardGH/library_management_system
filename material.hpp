#include <string>

#pragma once

class Material 
{
public:
    Material(const std::string& title) 
        : m_title(title) 
    {
    }

    virtual ~Material() 
    {
    }

public:
    const std::string& get_title() const {
        return m_title;
    }

    virtual void print_details() const = 0;
    virtual bool is_borrowed() const = 0;
    virtual void borrow() = 0;
    virtual void return_material() = 0;
    //virtual Material* create() const = 0;

protected:
    std::string m_title;
};