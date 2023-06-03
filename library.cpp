#include "library.hpp"
#include <iostream>

Library::~Library() 
{
    for (auto elem : materials) {
        delete elem;
    }
}

void Library::add_material(Material* material)
{
    materials.push_back(material->create());
}

void Library::remove_material(Material* material)
{
    for (auto it = materials.begin(); it != materials.end(); ++it) {
        if (*it == material) {
            delete *it;
            materials.erase(it);
            break;
        }
    }
    delete material;  // Delete the material object passed as the argument
}

bool Library::has_material(Material* material) const 
{
    for (const Material* m : materials) {
        if (m == material) {
            return true;
        }
    }
    return false;
}

Material* Library::find_material_by_title(const std::string& title) const 
{
    for (Material* material : materials) {
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