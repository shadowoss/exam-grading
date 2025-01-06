#include "../exercise.h"
#include <cstring>

// READ: 模板非类型实参 <https://zh.cppreference.com/w/cpp/language/template_parameters#%E6%A8%A1%E6%9D%BF%E9%9D%9E%E7%B1%BB%E5%9E%8B%E5%AE%9E%E5%8F%82>

// 多维张量模板
template<unsigned int N, class T>
struct Tensor {
    unsigned int shape[N];  // 形状
    T *data;                // 数据

    // 构造函数
    Tensor(unsigned int const shape_[N]) {
        unsigned int size = 1;
        // 计算总大小
        for (unsigned int i = 0; i < N; ++i) {
            shape[i] = shape_[i];
            size *= shape[i];
        }
        // 为数据分配空间，并初始化为0
        data = new T[size];
        std::memset(data, 0, size * sizeof(T));
    }

    // 析构函数
    ~Tensor() {
        delete[] data;
    }

    // 禁止复制和移动
    Tensor(Tensor const &) = delete;
    Tensor(Tensor &&) noexcept = delete;

    // 根据索引访问元素
    T &operator[](unsigned int const indices[N]) {
        return data[data_index(indices)];
    }

    T const &operator[](unsigned int const indices[N]) const {
        return data[data_index(indices)];
    }

private:
    // 计算数据索引
    unsigned int data_index(unsigned int const indices[N]) const {
        unsigned int index = 0;
        unsigned int product = 1;  // 用于计算乘积
        // 从最后一个维度开始计算索引
        for (unsigned int i = N; i > 0; --i) {
            unsigned int dim = i - 1;
            ASSERT(indices[dim] < shape[dim], "Invalid index");
            index += indices[dim] * product;
            product *= shape[dim];  // 更新乘积
        }
        return index;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    {
        unsigned int shape[]{2, 3, 4, 5};
        auto tensor = Tensor<4, int>(shape);

        unsigned int i0[]{0, 0, 0, 0};
        tensor[i0] = 1;
        ASSERT(tensor[i0] == 1, "tensor[i0] should be 1");
        ASSERT(tensor.data[0] == 1, "tensor[i0] should be 1");

        unsigned int i1[]{1, 2, 3, 4};
        tensor[i1] = 2;
        ASSERT(tensor[i1] == 2, "tensor[i1] should be 2");
        ASSERT(tensor.data[119] == 2, "tensor[i1] should be 2");
    }
    {
        unsigned int shape[]{7, 8, 128};
        auto tensor = Tensor<3, float>(shape);

        unsigned int i0[]{0, 0, 0};
        tensor[i0] = 1.f;
        ASSERT(tensor[i0] == 1.f, "tensor[i0] should be 1");
        ASSERT(tensor.data[0] == 1.f, "tensor[i0] should be 1");

        unsigned int i1[]{3, 4, 99};
        tensor[i1] = 2.f;
        ASSERT(tensor[i1] == 2.f, "tensor[i1] should be 2");
        ASSERT(tensor.data[3683] == 2.f, "tensor[i1] should be 2");
    }
    return 0;
}
