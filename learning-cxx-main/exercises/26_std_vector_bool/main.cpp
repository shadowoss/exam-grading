#include "../exercise.h"
#include <vector>
#include <iostream>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

int main(int argc, char **argv) {
    // 构造函数：创建一个含有 100 个 true 的 bool 向量
    std::vector<bool> vec(100, true);
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");

    // 注意：sizeof(std::vector<bool>) 的结果是平台相关的，并且由于内部优化，可能不会直观反映实际占用的空间。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    // 对于大多数平台来说，这个大小通常是一个固定的小数值（如8或16），因为它只表示向量对象本身的开销，而不包括实际数据存储。
    // 因此，这里我们不使用断言来检查其具体值，因为它是实现定义的。

    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }

    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");
    }

    {
        // 获取第30个元素的引用（实际上是代理对象）
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`");
        ref = false; // 修改代理对象会影响原始向量中的元素
        ASSERT(!ref, "Fill in `ref` or `!ref`");

        // 由于 std::vector<bool>::reference 是一个代理类，修改它会改变原始向量中的值
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`.");
    }

    return 0;
}