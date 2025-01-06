#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

struct Fibonacci {
    int numbers[11];

    // 修改方法签名以支持 constexpr
    constexpr int get(int i) const {
        // 检查索引是否在有效范围内
        if (i >= 0 && i < 11) {
            return numbers[i];
        } else {
            // 如果索引超出范围，可以抛出异常或返回一个特殊值
            // 这里我们简单地返回 -1 表示错误
            return -1; // 或者使用断言、抛出异常等更严格的方式处理错误
        }
    }
};

int main(int argc, char **argv) {
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
