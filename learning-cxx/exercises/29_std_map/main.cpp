#include "../exercise.h"
#include <map>
#include <string>

// READ: `std::map` <https://zh.cppreference.com/w/cpp/container/map>
// READ: `std::unordered_map` <https://zh.cppreference.com/w/cpp/container/unordered_map>

template<class K, class V>
bool key_exists(const std::map<K, V> &map, const K &key) {
    // 使用 `find` 方法检查键是否存在
    return map.find(key) != map.end();
}

template<class K, class V>
void set(std::map<K, V> &map, K key, V value) {
    // 使用 `operator[]` 插入或更新键值对
    map[key] = value;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    using namespace std::string_literals;

    std::map<std::string, std::string> secrets;

    set(secrets, "hello"s, "world"s);
    ASSERT(key_exists(secrets, "hello"s), "\"hello\" should be in `secrets`");
    ASSERT(!key_exists(secrets, "foo"s), "\"foo\" should not be in `secrets`");

    set(secrets, "foo"s, "bar"s);
    set(secrets, "Infini"s, "Tensor"s);
    ASSERT(secrets["hello"] == "world", "hello -> world");
    ASSERT(secrets["foo"] == "bar", "foo -> bar");
    ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

    set(secrets, "hello"s, "developer"s);
    ASSERT(secrets["hello"] == "developer", "hello -> developer");

    return 0;
}