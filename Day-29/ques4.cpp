#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product(int i, string n, int q, double p) : id(i), name(n), quantity(q), price(p) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }

    void display() const {
        cout << setw(10) << id 
             << setw(20) << name 
             << setw(15) << quantity 
             << setw(15) << fixed << setprecision(2) << price << "\n";
    }

    string toFileData() const {
        return to_string(id) + "," + name + "," + to_string(quantity) + "," + to_string(price);
    }
};

class InventorySystem {
private:
    vector<Product> inventory;
    const string filename = "inventory.txt";

    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) return;

        inventory.clear();
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);

            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) continue;

            int id = stoi(line.substr(0, pos1));
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            int quantity = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            double price = stod(line.substr(pos3 + 1));

            inventory.push_back(Product(id, name, quantity, price));
        }
        file.close();
    }

    void saveToFile() const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error saving data to file!\n";
            return;
        }
        for (const auto& prod : inventory) {
            file << prod.toFileData() << "\n";
        }
        file.close();
    }

public:
    InventorySystem() {
        loadFromFile();
    }

    void addProduct() {
        int id, qty;
        string name;
        double price;

        cout << "\nEnter Product ID: ";
        cin >> id;
        
        for (const auto& prod : inventory) {
            if (prod.getId() == id) {
                cout << "Error: Product ID already exists!\n";
                return;
            }
        }

        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Price: ";
        cin >> price;

        inventory.push_back(Product(id, name, qty, price));
        saveToFile();
        cout << "Product added successfully!\n";
    }

    void viewInventory() const {
        if (inventory.empty()) {
            cout << "\nInventory is empty.\n";
            return;
        }

        cout << "\n" << setfill('-') << setw(62) << "" << setfill(' ') << "\n";
        cout << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Quantity" << setw(15) << "Price ($)" << "\n";
        cout << setfill('-') << setw(62) << "" << setfill(' ') << "\n";

        for (const auto& prod : inventory) {
            prod.display();
        }
        cout << setfill('-') << setw(62) << "" << setfill(' ') << "\n";
    }

    void updateProduct() {
        int id, newQty;
        double newPrice;
        cout << "\nEnter Product ID to update: ";
        cin >> id;

        for (auto& prod : inventory) {
            if (prod.getId() == id) {
                cout << "Enter New Quantity: ";
                cin >> newQty;
                cout << "Enter New Price: ";
                cin >> newPrice;
                
                prod.setQuantity(newQty);
                prod.setPrice(newPrice);
                saveToFile();
                cout << "Product updated successfully!\n";
                return;
            }
        }
        cout << "Product ID not found.\n";
    }

    void deleteProduct() {
        int id;
        cout << "\nEnter Product ID to delete: ";
        cin >> id;

        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getId() == id) {
                inventory.erase(it);
                saveToFile();
                cout << "Product deleted successfully!\n";
                return;
            }
        }
        cout << "Product ID not found.\n";
    }
};

int main() {
    InventorySystem ims;
    int choice;

    do {
        cout << "\n=== INVENTORY MANAGEMENT SYSTEM ===\n";
        cout << "1. Add New Product\n";
        cout << "2. View All Products\n";
        cout << "3. Update Product Stock/Price\n";
        cout << "4. Delete a Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ims.addProduct(); break;
            case 2: ims.viewInventory(); break;
            case 3: ims.updateProduct(); break;
            case 4: ims.deleteProduct(); break;
            case 5: cout << "\nExiting system. Goodbye!\n"; break;
            default: cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
