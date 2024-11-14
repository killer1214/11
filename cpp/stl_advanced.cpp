#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <bitset>
#include <forward_list>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// 自定义类型示例
struct Person {
    string name;
    int age;
    
    // 用于排序的比较运算符
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

int main() {
    // 1. unordered_map示例
    cout << "\n=== Unordered Map 示例 ===\n";
    unordered_map<string, int> hashMap;
    hashMap["apple"] = 1;
    hashMap["banana"] = 2;
    hashMap["orange"] = 3;
    
    for(const auto& [key, value] : hashMap) {
        cout << key << ": " << value << endl;
    }
    
    // 2. array示例
    cout << "\n=== Array 示例 ===\n";
    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "数组大小: " << arr.size() << endl;
    cout << "第一个元素: " << arr.front() << endl;
    cout << "最后一个元素: " << arr.back() << endl;
    
    // 3. bitset示例
    cout << "\n=== Bitset 示例 ===\n";
    bitset<8> bits(string("10101010"));
    cout << "位集合: " << bits << endl;
    cout << "置位数: " << bits.count() << endl;
    
    // 4. forward_list（单向链表）示例
    cout << "\n=== Forward List 示例 ===\n";
    forward_list<int> flist = {1, 2, 3, 4, 5};
    flist.push_front(0);
    cout << "单向链表内容: ";
    for(const auto& item : flist) {
        cout << item << " ";
    }
    cout << endl;
    
    // 5. 多重集合示例
    cout << "\n=== Multiset 示例 ===\n";
    multiset<int> mset = {1, 3, 3, 7, 9, 3};
    cout << "3的出现次数: " << mset.count(3) << endl;
    
    // 6. 自定义类型的容器使用
    cout << "\n=== 自定义类型容器示例 ===\n";
    vector<Person> people = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20}
    };
    
    sort(people.begin(), people.end()); // 使用自定义的<运算符
    for(const auto& p : people) {
        cout << p.name << ": " << p.age << endl;
    }
    
    return 0;
} 