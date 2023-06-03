#include "library.hpp"
#include <iostream>

Library::~Library() 
{
    for (auto elem : m_materials) {
        delete elem;
    }
}

void Library::add_material(Material* material)
{
    m_materials.push_back(material);
}

void Library::remove_material(Material* material)
{
    for (auto it = m_materials.begin(); it != m_materials.end(); ++it) {
        if (*it == material) {
            delete *it;
            *it = nullptr;
            break;
        }
    }
}

bool Library::has_material(Material* material) const 
{
    return !(material->is_borrowed());
}

Material* Library::find_material_by_title(const std::string& title) const 
{
    for (Material* material : m_materials) {
        if (material->get_title() == title) {
            return material;
        }
    }
    return nullptr;
}

void Library::borrow_material(Material* material) 
{
    if (material->is_borrowed()) {
        std::cout << "The material is already borrowed." << std::endl;
    } else {
        material->borrow();
        std::cout << "Successfully borrowed the material: " << material->get_title() << std::endl;
    }
}

void Library::return_material(Material* material) 
{
    if (!material->is_borrowed()) {
        std::cout << "The material is not currently borrowed." << std::endl;
    } else {
        material->return_material();
        std::cout << "Successfully returned the material: " << material->get_title() << std::endl;
    }
}