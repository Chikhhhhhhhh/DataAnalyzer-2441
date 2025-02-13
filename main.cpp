Ось базовий приклад коду для обробки даних у C++. Цей код читає дані з файлу, обробляє їх і записує результати у інший файл.

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Data {
    int id;
    string name;
    double value;
};

vector<Data> loadData(const string& filename) {
    ifstream file(filename);
    vector<Data> data;

    if (!file) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }

    while (!file.eof()) {
        Data d;
        file >> d.id >> d.name >> d.value;
        data.push_back(d);
    }

    file.close();
    return data;
}

void printData(const vector<Data>& data) {
    for (const auto& d : data) {
        cout << "ID: " << d.id << ", Name: " << d.name << ", Value: " << d.value << "\n";
    }
}

void processAndSaveData(const vector<Data>& data, const string& filename) {
    ofstream file(filename);

    if (!file) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }

    for (const auto& d : data) {
        double processedValue = d.value * 2;  // An example of data processing
        file << d.id << " " << d.name << " " << processedValue << "\n";
    }

    file.close();
}

int main() {
    string inputFilename = "input.txt";
    string outputFilename = "output.txt";

    vector<Data> data = loadData(inputFilename);

    cout << "Loaded data:\n";
    printData(data);

    processAndSaveData(data, outputFilename);

    cout << "Data has been processed and saved to " << outputFilename << "\n";

    return 0;
}
```
Цей код завантажує дані з файлу `input.txt`, виводить їх на екран, потім обробляє (у цьому прикладі просто помножує значення на 2) і зберігає результат в `output.txt`.