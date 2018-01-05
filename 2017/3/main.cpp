#include <iostream>
#include <vector>
#include <cstdlib>

// Directions: 0 = right, 1 = up, 2 = left, 3 = down.
enum {
    DIR_RIGHT = 0,
    DIR_UP,
    DIR_LEFT,
    DIR_DOWN,
    DIR_OUT_OF_BOUNDS
};

int main() {
    int target = 361527;

    // Start by generating the "maze".
    std::vector<std::vector<int>> matrix;
    int direction = 0;
    int cur_vector = 0;

    matrix.push_back(std::vector<int>());

    std::vector<int> *dest = &matrix.at(cur_vector);
    // Add 1 immediately since it will always be there.
    dest->push_back(1);

    int goalX = 0;
    int goalY = 0;
    int targetX = 0;
    int targetY = 0;

    int width = dest->size();

    for (int i = 2; i <= target; ++i) {
        // Get the next destination vector.
        switch (direction) {
            case DIR_UP:
                --cur_vector;
                if (cur_vector < 0) {
                    // We want a new vector at the top.
                    std::vector<std::vector<int>>::iterator iter = matrix.begin();
                    matrix.insert(iter, std::vector<int>());
                    cur_vector = 0;
                    // Next step will be to the left.
                    direction = DIR_LEFT;
                    ++goalY;
                }
                targetY = cur_vector;
            case DIR_RIGHT:
                dest = &matrix.at(cur_vector);
                dest->push_back(i);
                if (dest->size() > width) {
                    direction = DIR_UP;
                    width = dest->size();
                }
                targetX = dest->size() - 1;
                break;
            case DIR_DOWN:
                ++cur_vector;
                // Check if the vector we're after exists.
                // If not, add it to the end of the matrix.
                if (cur_vector > matrix.size() - 1) {
                    matrix.push_back(std::vector<int>());
                    direction = DIR_RIGHT;
                }
                targetY = cur_vector;
            case DIR_LEFT:
                dest = &matrix.at(cur_vector);
                std::vector<int>::iterator iter = dest->begin();
                dest->insert(iter, i);
                if (dest->size() > width) {
                    direction = DIR_DOWN;
                    width = dest->size();
                }
                if (cur_vector == goalY) {
                    ++goalX;
                }
                targetX = 0;
                break;
        }
    }

    int steps = abs((targetX - goalX)) + abs((targetY - goalY));

    std::cout << steps << std::endl;
    // 326
    return 0;
}