#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    std::vector<std::string> ans(val.size()); // 预先分配空间

    std::transform(val.begin(), val.end(), ans.begin(),
                   [](int n) -> std::string { return std::to_string(n * 2); });

    // 断言检查结果是否符合预期
    assert(ans.size() == val.size() && "ans size should be equal to val size");
    assert(ans[0] == "16" && "ans[0] should be 16");
    assert(ans[1] == "26" && "ans[1] should be 26");
    assert(ans[2] == "42" && "ans[2] should be 42");
    assert(ans[3] == "68" && "ans[3] should be 68");
    assert(ans[4] == "110" && "ans[4] should be 110");

    return 0;
}