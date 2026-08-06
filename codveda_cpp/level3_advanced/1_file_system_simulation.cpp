 

#include <iostream>
#include <map>
#include <string>
#include <limits>

class FileSystem {
private:
    std::map<std::string, std::string> files; // filename -> content

public:
    void createFile() {
        std::string name;
        std::cout << "Enter new file name: ";
        std::cin >> name;

        if (files.find(name) != files.end()) {
            std::cout << "Error: a file named '" << name << "' already exists.\n";
            return;
        }

        files[name] = "";
        std::cout << "File '" << name << "' created successfully.\n";
    }

    void writeFile() {
        std::string name;
        std::cout << "Enter file name to write to: ";
        std::cin >> name;

        auto it = files.find(name);
        if (it == files.end()) {
            std::cout << "Error: file '" << name << "' does not exist.\n";
            return;
        }

        std::cin.ignore();
        std::cout << "Enter content to write: ";
        std::getline(std::cin, it->second);

        std::cout << "Content written to '" << name << "'.\n";
    }

    void readFile() const {
        std::string name;
        std::cout << "Enter file name to read: ";
        std::cin >> name;

        auto it = files.find(name);
        if (it == files.end()) {
            std::cout << "Error: file '" << name << "' does not exist.\n";
            return;
        }

        std::cout << "--- Contents of '" << name << "' ---\n";
        std::cout << (it->second.empty() ? "(empty file)" : it->second) << "\n";
    }

    void deleteFile() {
        std::string name;
        std::cout << "Enter file name to delete: ";
        std::cin >> name;

        if (files.erase(name) == 0) {
            std::cout << "Error: file '" << name << "' does not exist.\n";
        } else {
            std::cout << "File '" << name << "' deleted successfully.\n";
        }
    }

    void listFiles() const {
        if (files.empty()) {
            std::cout << "No files exist.\n";
            return;
        }

        std::cout << "--- Files (" << files.size() << ") ---\n";
        for (const auto &entry : files) {
            std::cout << "  " << entry.first << " (" << entry.second.size() << " bytes)\n";
        }
    }
};

void printMenu() {
    std::cout << "\n===== Simple File System Simulation =====\n";
    std::cout << "1. Create File\n";
    std::cout << "2. Write to File\n";
    std::cout << "3. Read File\n";
    std::cout << "4. Delete File\n";
    std::cout << "5. List Files\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    FileSystem fs;
    int choice;

    do {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: invalid input, please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: fs.createFile(); break;
            case 2: fs.writeFile(); break;
            case 3: fs.readFile(); break;
            case 4: fs.deleteFile(); break;
            case 5: fs.listFiles(); break;
            case 6: std::cout << "Exiting simulation.\n"; break;
            default: std::cout << "Error: invalid option, choose 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
