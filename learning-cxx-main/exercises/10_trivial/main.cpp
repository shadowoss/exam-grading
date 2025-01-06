#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 如果请求的索引小于等于已经缓存的最大索引，则直接返回缓存值
    if (i <= cache.cached && i >= 0 && i < 16) {
        return cache.cache[i];
    }

    // 如果索引超出了缓存大小，我们只能返回最大缓存的值
    if (i >= 16) {
        return cache.cache[15];
    }

    // 否则，从 cached + 1 开始填充缓存直到索引 i
    for (int n = cache.cached + 1; n <= i; ++n) {
        cache.cache[n] = cache.cache[n - 1] + cache.cache[n - 2];
    }
    // 更新已缓存的最大索引
    cache.cached = i;

    return cache.cache[i];
}

// 初始化缓存结构体
void init_cache(FibonacciCache &cache) {
    // 设置前两个斐波那契数
    cache.cache[0] = 0;
    cache.cache[1] = 1;
    // 设置已缓存的最大索引
    cache.cached = 1;
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    // 初始化缓存结构体
    FibonacciCache fib;
    init_cache(fib);
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
