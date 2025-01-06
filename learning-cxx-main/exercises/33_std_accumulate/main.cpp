#include "../exercise.h"
#include <numeric>
#include <cstddef> // For std::size_t

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    std::size_t num_elements = std::accumulate(std::begin(shape) + 1, std::end(shape), 1, std::multiplies<>());
    std::size_t size = num_elements * sizeof(DataType);

    ASSERT(size == 602112, "3x224x224 * sizeof(float) should be 602112");
    return 0;
}