#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

// 打印容器的辅助函数
template<typename Container>
void printContainer(const Container& c, const string& title) {
    cout << "\n=== " << title << " ===\n";
    for(const auto& item : c) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    // 1. vector的使用
    cout << "\n=== Vector 示例 ===\n";
    vector<int> vec = {1, 5, 3, 7, 2};
    vec.push_back(6);                    // 添加元素
    vec.pop_back();                      // 删除最后一个元素
    sort(vec.begin(), vec.end());        // 排序
    printContainer(vec, "Sorted Vector");
    
    // 2. list的使用
    cout << "\n=== List 示例 ===\n";
    list<int> lst = {3, 1, 4, 1, 5};
    lst.push_front(0);                   // 在前面添加
    lst.push_back(9);                    // 在后面添加
    lst.sort();                          // list自带排序
    printContainer(lst, "Sorted List");
    
    // 3. map的使用
    cout << "\n=== Map 示例 ===\n";
    map<string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 89;
    scores["Charlie"] = 92;
    
    for(const auto& [name, score] : scores) {
        cout << name << ": " << score << endl;
    }
    
    // 4. set的使用
    cout << "\n=== Set 示例 ===\n";
    set<int> numSet = {5, 2, 8, 2, 1, 9}; // 自动去重和排序
    numSet.insert(3);
    printContainer(numSet, "Sorted Set");
    
    // 5. STL算法示例
    cout << "\n=== STL算法示例 ===\n";
    vector<int> nums = {4, 1, 8, 5, 3, 7, 9};
    
    // 查找
    auto it = find(nums.begin(), nums.end(), 5);
    if(it != nums.end())
        cout << "找到数字 5 在位置: " << (it - nums.begin()) << endl;
    
    // 计数
    int count3 = count(nums.begin(), nums.end(), 3);
    cout << "数字 3 出现次数: " << count3 << endl;
    
    // 最大最小值
    auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
    cout << "最小值: " << *minIt << ", 最大值: " << *maxIt << endl;
    
    // 6. priority_queue（优先队列）示例
    cout << "\n=== Priority Queue 示例 ===\n";
    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    
    cout << "优先队列内容: ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // 7. stack的使用
    cout << "\n=== Stack 示例 ===\n";
    stack<string> st;
    st.push("First");
    st.push("Second");
    st.push("Third");
    
    cout << "栈顶元素: " << st.top() << endl;
    st.pop();
    cout << "弹出后栈顶: " << st.top() << endl;
    
    // 8. 自定义比较器示例
    cout << "\n=== 自定义比较器示例 ===\n";
    vector<int> customSort = {1, 5, 2, 8, 3};
    sort(customSort.begin(), customSort.end(), 
         [](int a, int b) { return a > b; }); // 降序排序
    printContainer(customSort, "降序排序");
    
    return 0;
} 