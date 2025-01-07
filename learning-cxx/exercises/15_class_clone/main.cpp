#include "../exercise.h"

// READ: 复制构造函数 <https://zh.cppreference.com/w/cpp/language/copy_constructor>
// READ: 函数定义（显式弃置）<https://zh.cppreference.com/w/cpp/language/function>


class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // 构造函数，动态设置容量
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(1) {
        cache[0] = 0;  // Fibonacci(0) = 0
        if (capacity > 1) {
            cache[1] = 1;  // Fibonacci(1) = 1
            cached = 1;
        }
    }

    // 复制构造函数，进行深拷贝
    DynFibonacci(DynFibonacci const &other) : cache(new size_t[other.cached + 1]), cached(other.cached) {
        for (int i = 0; i <= cached; ++i) {
            cache[i] = other.cache[i];
        }
    }

    // 析构函数，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 非 const 版本的 get 方法，允许扩展缓存
    size_t get(int i) {
        if (i < 0) {
            throw std::invalid_argument("Index cannot be negative");
        }
        if (i <= cached) {
            return cache[i];
        }

        // 扩展缓存直到 i
        for (int j = cached + 1; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];  // 斐波那契递推关系
        }
        cached = i;  // 更新缓存的最后索引
        return cache[i];
    }

    // const 版本的 get 方法，不允许修改缓存
    size_t get(int i) const {
        if (i < 0) {
            throw std::invalid_argument("Index cannot be negative");
        }
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
        return 0;  // 这一行不会被执行，因为 ASSERT 会终止程序
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = fib;
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}
