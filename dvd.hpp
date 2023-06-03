#include "material.hpp"

#include <string>

class DVD : public Material 
{
public:
    DVD(const std::string& title, int release_year, const std::string& director, int duration);

    // copy operations
    DVD(const DVD& other);
    DVD& operator=(const DVD& other);

    // move operations
    DVD(DVD&& other);
    DVD& operator=(DVD&& other);

public:
    void print_details() const override;
    bool is_borrowed() const override;
    void borrow() override;
    void return_material() override;
    Material* create() const override;

private:
    int m_release_year;
    std::string m_director;
    int m_duration;
    bool m_borrowed;
};