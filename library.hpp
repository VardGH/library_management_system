#include <vector>
#include "material.hpp"

#pragma once

class Library 
{
public:
    Library() {}
    ~Library();

public:
    void add_material(Material* material);  // Add materials to the library
    void remove_material(Material* material); // Remove materials from the library
    bool has_material(Material* material) const; // Check if materials are in the library
    void borrow_material(Material* material); // Borrow materials
    void return_material(Material* material); // Return materials
    Material* find_material_by_title(const std::string& title) const; // Find materials by title

private:
    std::vector<Material*> m_materials;
};