#include <iostream>
#include <fstream>
#include <vector>

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
char map[MAX_ROWS][MAX_COLS];

void load_map(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            file >> map[i][j];
        }
    }

    file.close();
}

void draw_map() {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    load_map("map.txt");
    draw_map();
    return 0;
}