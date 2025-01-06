#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value.");
        // `std::vector` 的大小是指向量中元素的数量。
        // 它与容器内存储的元素个数有关，不包括容量（capacity）。
        // sizeof(vec) 返回的是 vector 对象本身的大小，不是它的内容。
        ASSERT(sizeof(vec) != sizeof(int) * 5, "Size of the vector object is not the size of its contents.");
        int ans[]{1, 2, 3, 4, 5};
        // 使用 data() 方法来获取指向内部数组的指针
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) != sizeof(double) * 5, "Size of the vector object is not the size of its contents.");
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value.");
            // sizeof(vec) 不会改变，因为它表示的是 vector 对象本身的大小
            ASSERT(sizeof(vec) == sizeof(vec), "Size of the vector object remains unchanged.");
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == sizeof(vec), "Size of the vector object remains unchanged.");
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
        }
        {
            // 插入和删除的时间复杂度：
            // - 在末尾插入或删除是常数时间 O(1)，如果需要重新分配内存则是线性时间 O(n)。
            // - 在中间插入或删除是线性时间 O(n)，因为需要移动后面的元素。
            vec.insert(vec.begin() + 1, 1.5);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            vec.erase(vec.begin() + 1);
            ASSERT((vec == std::vector<double>{1, 2, 3, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();
            // shrink_to_fit 是一个提示，它可能不会改变 capacity，这取决于实现。
            // 因此我们不能确定地预测 capacity 的值。
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value.");
            // clear 不会影响 capacity
            ASSERT(vec.capacity() >= 0, "Capacity may remain unchanged or be reduced.");
        }
    }
    {
        // 调用正确的构造函数：初始化列表构造函数
        std::vector<char> vec(48, 'z'); // 创建一个包含 48 个 'z' 的向量
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) != 48 * sizeof(char), "Size of the vector object is not the size of its contents.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            // resize 可能不会改变 capacity
            ASSERT(vec.capacity() >= capacity, "Capacity may remain unchanged or be reduced.");
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() >= 256, "Fill in the correct value.");
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value.");
            ASSERT(vec.capacity() >= 256, "Fill in the correct value.");
            // resize 后新添加的元素在最后，所以 15 仍然是 'z'
            ASSERT(vec[15] == 'z', "Fill in the correct value.");
            // 新添加的元素索引为 16, 17, 18, 19
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}