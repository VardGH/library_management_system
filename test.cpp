#include "test.hpp"

void test_library()
{
    Library library;

    // Create example materials
    Book* book1 = new Book("Dune", "Frank Herbert", 1965, "Science fiction", 896);
    Book* book2 = new Book("The Lord of the Rings", "Tolkien", 1968, "Adventure", 1178);
    Journal* journal1 = new Journal("Journal of Neuroscience", 38, 22, 2018, "Neuroscience");
    Journal* journal2 = new Journal("Journal of Applied Mathematics", 27, 4, 2023, "Applied Mathematics");
    DVD* dvd1 = new DVD("Inception", 2010, "Christopher Nolan", 148);
    DVD* dvd2 = new DVD("The Lion King", 1994, "Roger Allers", 88);

    // Add materials to the library
    library.add_material(book1);
    library.add_material(book2);
    library.add_material(journal1);
    library.add_material(journal2);
    library.add_material(dvd1);
    library.add_material(dvd2);

    // Borrow and return materials
    library.borrow_material(book1);
    library.borrow_material(dvd2);
    library.return_material(book1);
    library.return_material(dvd1);

    // Check if materials are in the library
    std::cout << "Dune in library: " << (library.has_material(book1) ? "Yes" : "No") << std::endl;
    std::cout << "DVD2 in library: " << (library.has_material(dvd2) ? "Yes" : "No") << std::endl;

    // Find materials by title
    Material* found_material = library.find_material_by_title("Dune");
    if (found_material != nullptr) {
        found_material->print_details();
    } else {
        std::cout << "Material not found." << std::endl;
    }

    // Remove materials from the library
    library.remove_material(book2);
    library.remove_material(journal1);
    library.remove_material(dvd2);

    // Clean up remaining materials
    delete journal2;
}
