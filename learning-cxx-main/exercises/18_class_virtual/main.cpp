#include "../exercise.h"

// READ: 虚函数 <https://zh.cppreference.com/w/cpp/language/virtual>

struct A {
    virtual char virtual_name() const {
        return 'A';
    }
    char direct_name() const {
        return 'A';
    }
};
struct B : public A {
    // READ: override <https://zh.cppreference.com/w/cpp/language/override>
    char virtual_name() const override {
        return 'B';
    }
    char direct_name() const {
        return 'B';
    }
};
struct C : public B {
    // READ: final <https://zh.cppreference.com/w/cpp/language/final>
    char virtual_name() const final {
        return 'C';
    }
    char direct_name() const {
        return 'C';
    }
};
struct D : public C {
    char direct_name() const {
        return 'D';
    }
};

int main(int argc, char **argv) {
    constexpr auto MSG = "Replace '?' with its correct name.";

    A a;
    B b;
    C c;
    D d;

    // 直接调用
    ASSERT(a.virtual_name() == 'A', MSG); // 虚函数调用 A::virtual_name
    ASSERT(b.virtual_name() == 'B', MSG); // 虚函数调用 B::virtual_name
    ASSERT(c.virtual_name() == 'C', MSG); // 虚函数调用 C::virtual_name
    ASSERT(d.virtual_name() == 'C', MSG); // 虚函数调用 C::virtual_name (因为 C::virtual_name 是 final)
    ASSERT(a.direct_name() == 'A', MSG);  // 非虚函数调用 A::direct_name
    ASSERT(b.direct_name() == 'B', MSG);  // 非虚函数调用 B::direct_name
    ASSERT(c.direct_name() == 'C', MSG);  // 非虚函数调用 C::direct_name
    ASSERT(d.direct_name() == 'D', MSG);  // 非虚函数调用 D::direct_name

    A &rab = b;
    B &rbc = c;
    C &rcd = d;

    ASSERT(rab.virtual_name() == 'B', MSG); // 虚函数调用 B::virtual_name
    ASSERT(rbc.virtual_name() == 'C', MSG); // 虚函数调用 C::virtual_name
    ASSERT(rcd.virtual_name() == 'C', MSG); // 虚函数调用 C::virtual_name (因为 C::virtual_name 是 final)
    ASSERT(rab.direct_name() == 'A', MSG);  // 非虚函数调用 A::direct_name
    ASSERT(rbc.direct_name() == 'B', MSG);  // 非虚函数调用 B::direct_name
    ASSERT(rcd.direct_name() == 'C', MSG);  // 非虚函数调用 C::direct_name

    A &rac = c;
    B &rbd = d;

    ASSERT(rac.virtual_name() == 'C', MSG); // 虚函数调用 C::virtual_name
    ASSERT(rbd.virtual_name() == 'C', MSG); // 虚函数调用 C::virtual_name (因为 C::virtual_name 是 final)
    ASSERT(rac.direct_name() == 'A', MSG);  // 非虚函数调用 A::direct_name
    ASSERT(rbd.direct_name() == 'B', MSG);  // 非虚函数调用 B::direct_name

    A &rad = d;

    ASSERT(rad.virtual_name() == 'C', MSG); // 虚函数调用 C::virtual_name (因为 C::virtual_name 是 final)
    ASSERT(rad.direct_name() == 'A', MSG);  // 非虚函数调用 A::direct_name

    return 0;
}

// READ: 扩展阅读-纯虚、抽象 <https://zh.cppreference.com/w/cpp/language/abstract_class>
// READ: 扩展阅读-虚继承 <https://zh.cppreference.com/w/cpp/language/derived_class>
