#include <iostream>
#include "pugixml.hpp"

int main(int argc, char* argv[]) {
    // Ensure the XML file path is provided as an argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <XML file path>" << std::endl;
        return 1;
    }

    // Load the XML document
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(argv[1]);

    // Handle errors if the XML file cannot be loaded
    if (!result) {
        std::cerr << "Failed to load XML file: " << result.description() << std::endl;
        return 1;
    }

    // Parse and display book information
    std::cout << "Books in Catalog:\n";
    for (pugi::xml_node book : doc.child("catalog").children("book")) {
        std::string title = book.child("title").child_value();
        std::string author = book.child("author").child_value();
        std::string genre = book.child("genre").child_value();
        std::string price = book.child("price").child_value();
        std::string publish_date = book.child("publish_date").child_value();
        std::string description = book.child("description").child_value();

        // Print book details
        std::cout << "----------------------------------\n";
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Genre: " << genre << "\n";
        std::cout << "Price: $" << price << "\n";
        std::cout << "Publish Date: " << publish_date << "\n";
        std::cout << "Description: " << description << "\n";
    }

    return 0;
}
