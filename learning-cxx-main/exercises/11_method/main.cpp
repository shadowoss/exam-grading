#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算

    // 构造函数初始化缓存结构体
    Fibonacci() : cached(1) {
        cache[0] = 0;
        cache[1] = 1;
    }

    unsigned long long get(int i) {
        // 如果请求的索引小于等于已经缓存的最大索引，则直接返回缓存值
        if (i <= cached && i >= 0 && i < 128) {
            return cache[i];
        }

        // 如果索引超出了缓存大小，抛出错误或采取其他措施
        if (i >= 128) {
            throw std::out_of_range("Index out of cache range");
        }

        // 否则，从 cached + 1 开始填充缓存直到索引 i
        for (int n = cached + 1; n <= i; ++n) {
            cache[n] = cache[n - 1] + cache[n - 2];
        }
        // 更新已缓存的最大索引
        cached = i;

        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
