#include "../exercise.h"

// READ: 析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>
// READ: RAII <https://learn.microsoft.com/zh-cn/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170>

/// @brief 任意缓存容量的斐波那契类型。
/// @details 可以在构造时传入缓存容量，因此需要动态分配缓存空间。
class DynFibonacci {
    size_t *cache;
    int capacity;
    int cached;

public:
    // 实现动态设置容量的构造器
    DynFibonacci(int cap) : capacity(cap), cached(1) {
        cache = new (std::nothrow) size_t[capacity];
        if (!cache) {
            throw std::bad_alloc();
        }
        // 初始化前两个斐波那契数
        cache[0] = 0;
        cache[1] = 1;
    }

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        // 如果请求的索引小于等于已经缓存的最大索引，则直接返回缓存值
        if (i <= cached && i >= 0 && i < capacity) {
            return cache[i];
        }

        // 如果索引超出了缓存大小，抛出错误或采取其他措施
        if (i >= capacity) {
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
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
