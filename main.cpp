#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int quantity;
    float price;
};

vector<Book> inventory;

void addBook() {
    Book book;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter Author Name: ";
    getline(cin, book.author);
    cout << "Enter Quantity: ";
    cin >> book.quantity;
    cout << "Enter Price: ";
    cin >> book.price;
    inventory.push_back(book);
    cout << "Book added successfully!\n";
}

void displayBooks() {
    cout << "\n--- Book Inventory ---\n";
    for (const auto& book : inventory) {
        cout << "Title: " << book.title << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "Quantity: " << book.quantity << "\n";
        cout << "Price: " << book.price << "\n";
        cout << "--------------------------\n";
    }
}

void searchBook() {
    string searchTitle;
    cout << "Enter title to search: ";
    cin.ignore();
    getline(cin, searchTitle);
    bool found = false;
    for (const auto& book : inventory) {
        if (book.title == searchTitle) {
            cout << "Found: " << book.title << " by " << book.author << "\n";
            cout << "Quantity: " << book.quantity << ", Price: " << book.price << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Bookshop Management ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
