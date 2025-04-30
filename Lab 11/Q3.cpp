#include<iostream>
using namespace std;


class FileException {
public:
    virtual const char* what() const{
        return "FileException occurred";
    }
    virtual ~FileException() {}
};


class FileNotFound : public FileException {
public:
    const char* what() const override {
        return "FileNotFoundException - File not found!";
    }
};


class PermissionDenied : public FileException {
public:
    const char* what() const override {
        return "PermissionDeniedException - Access denied!";
    }
};


void read(const string& filename) {
    if (filename == "missing.txt")
        throw FileNotFound();
    else if (filename == "secret.txt")
        throw PermissionDenied();
    else
        cout << "Reading '" << filename << "': File read successfully!" << endl;
}


int main() {
    string files[3] = { "secret.txt", "missing.txt", "example.txt" };

    for (int i = 0; i < 3; i++) {
        try {
            read(files[i]);
        }
        catch (const FileNotFound& e) {
            cout << "Reading '" << files[i] << "': " << e.what() << endl;
        }
        catch (const PermissionDenied& e) {
            cout << "Reading '" << files[i] << "': " << e.what() << endl;
        }
        catch (const FileException& e) {
            cout << "Reading '" << files[i] << "': " << e.what() << endl;
        }
    }

    return 0;
}
