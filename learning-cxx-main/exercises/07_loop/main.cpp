#include "../exercise.h"

// TODO: 改正函数实现，实现正确的缓存优化斐波那契计算
// THINk: 这个函数是一个纯函数（pure function）吗？
// READ: 纯函数 <https://zh.wikipedia.org/wiki/%E7%BA%AF%E5%87%BD%E6%95%B0>
static unsigned long long fibonacci(int i) {
    static unsigned long long cache[96] = {0, 1}; // 初始化前两个斐波那契数
    static int cached = 1; // 已经缓存的斐波那契数的最大索引

    // 如果请求的索引已经在缓存中，则直接返回
    if (i <= cached) {
        return cache[i];
    }

    // 否则，从 cached + 1 开始计算并填充缓存直到索引 i
    for (int n = cached + 1; n <= i; ++n) {
        cache[n] = cache[n - 1] + cache[n - 2];
    }
    cached = i; // 更新已缓存的最大索引

    return cache[i];
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT(fibonacci(0) == 0, "fibonacci(0) should be 0");
    ASSERT(fibonacci(1) == 1, "fibonacci(1) should be 1");
    ASSERT(fibonacci(2) == 1, "fibonacci(2) should be 1");
    ASSERT(fibonacci(3) == 2, "fibonacci(3) should be 2");
    ASSERT(fibonacci(10) == 55, "fibonacci(10) should be 55");

    auto fib90 = fibonacci(90);
    std::cout << "fibonacci(90) = " << fib90 << std::endl;
    ASSERT(fib90 == 2880067194370816120, "fibonacci(90) should be 2880067194370816120");
    return 0;
}
