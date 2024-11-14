# C++ STL 使用指南

## 1. STL容器

### 1.1 序列容器

#### vector（动态数组）
- 特点：连续内存，随机访问，尾部插入删除效率高
- 常用操作：
  ```cpp
  vector<int> vec;           // 创建空vector
  vec.push_back(element);    // 在尾部添加元素
  vec.pop_back();           // 删除尾部元素
  vec[index];               // 随机访问
  vec.size();              // 获取大小
  ```

#### list（双向链表）
- 特点：非连续内存，双向链表实现，任意位置插入删除效率高
- 常用操作：
  ```cpp
  list<int> lst;            // 创建空list
  lst.push_front(elem);     // 在头部插入
  lst.push_back(elem);      // 在尾部插入
  lst.sort();              // 排序
  ```

#### deque（双端队列）
- 特点：两端都能快速插入和删除
- 常用操作：
  ```cpp
  deque<int> dq;           // 创建空deque
  dq.push_front(elem);     // 头部插入
  dq.push_back(elem);      // 尾部插入
  dq.pop_front();         // 头部删除
  dq.pop_back();          // 尾部删除
  ```

### 1.2 关联容器

#### map（映射）
- 特点：键值对存储，自动排序（按键）
- 常用操作：
  ```cpp
  map<string, int> mp;     // 创建空map
  mp[key] = value;         // 插入/修改
  mp.find(key);           // 查找
  mp.erase(key);          // 删除
  ```

#### set（集合）
- 特点：不重复元素集合，自动排序
- 常用操作：
  ```cpp
  set<int> s;             // 创建空set
  s.insert(element);      // 插入元素
  s.erase(element);       // 删除元素
  s.find(element);        // 查找元素
  ```

### 1.3 容器适配器

#### stack（栈）
- 特点：LIFO（后进先出）
- 常用操作：
  ```cpp
  stack<int> st;          // 创建空栈
  st.push(element);       // 压栈
  st.pop();              // 出栈
  st.top();              // 查看栈顶
  ```

#### queue（队列）
- 特点：FIFO（先进先出）
- 常用操作：
  ```cpp
  queue<int> q;           // 创建空队列
  q.push(element);        // 入队
  q.pop();               // 出队
  q.front();             // 查看队首
  ```

#### priority_queue（优先队列）
- 特点：自动保持最大/最小元素在顶部
- 常用操作：
  ```cpp
  priority_queue<int> pq;  // 创建优先队列
  pq.push(element);       // 插入元素
  pq.pop();              // 删除顶部元素
  pq.top();              // 查看顶部元素
  ```

## 2. STL算法

### 2.1 常用算法
- sort(): 排序
- find(): 查找元素
- count(): 计数
- reverse(): 反转
- min_element()/max_element(): 最小/最大元素
- binary_search(): 二分查找
- accumulate(): 累加
- for_each(): 遍历执行

### 2.2 使用示例
```cpp
vector<int> v = {4,2,5,1,3};
sort(v.begin(), v.end());                    // 排序
auto it = find(v.begin(), v.end(), 3);       // 查找
int cnt = count(v.begin(), v.end(), 2);      // 计数
reverse(v.begin(), v.end());                 // 反转
auto minIt = min_element(v.begin(), v.end()); // 最小值
```

## 3. 迭代器
- 输入迭代器：只读，单遍扫描
- 输出迭代器：只写，单遍扫描
- 前向迭代器：可读写，多遍扫描，只能向前
- 双向迭代器：可读写，多遍扫描，可前后移动
- 随机访问迭代器：可读写，随机访问

### 3.1 迭代器使用示例
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
// 正向迭代器
for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " ";
}
// 反向迭代器
for(vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
    cout << *rit << " ";
}
```

## 4. 高级特性

### 4.1 无序容器
```cpp
unordered_map<string, int> umap;  // 哈希表实现的map
unordered_set<int> uset;          // 哈希表实现的set
```

### 4.2 自定义比较器
```cpp
struct Compare {
    bool operator()(const int& a, const int& b) {
        return a > b;  // 降序排序
    }
};
set<int, Compare> customSet;
priority_queue<int, vector<int>, Compare> customPQ;
```

### 4.3 lambda表达式
```cpp
auto cmp = [](int a, int b) { return a > b; };
sort(vec.begin(), vec.end(), cmp);
```

## 5. 最佳实践

### 5.1 性能优化
1. 合理选择容器
   - 频繁随机访问：vector
   - 频繁插入删除：list
   - 快速查找：unordered_map/set
   
2. 避免不必要的拷贝
   - 使用引用参数
   - 使用emplace代替push_back
   - 合理使用移动语义

### 5.2 常见陷阱
1. 迭代器失效
   ```cpp
   vector<int> v = {1,2,3};
   for(auto it = v.begin(); it != v.end(); ++it) {
       v.push_back(4);  // 错误：可能导致迭代器失效
   }
   ```

2. 容器修改注意事项
   - 插入/删除操作后更新迭代器
   - 确保迭代器在有效范围内
   - 注意容器的size变化

### 5.3 调试技巧
1. 使用 `at()` 代替 `operator[]` 进行边界检查
2. 使用 `assert` 验证迭代器有效性
3. 定期检查容器大小和容量

## 6. 实用工具

### 6.1 算法复杂度
- vector: 随机访问O(1)，尾部插入平均O(1)
- list: 插入/删除O(1)，查找O(n)
- map/set: 查找/插入/删除O(log n)
- unordered_map/set: 平均O(1)，最差O(n)

### 6.2 内存管理
```cpp
vector<int> vec;
vec.reserve(1000);    // 预分配空间
vec.shrink_to_fit();  // 释放多余空间
```

### 6.3 线程安全
- STL容器本身不是线程安全的
- 需要使用互斥锁保护共享容器
- 考虑使用并发容器库

## 7. 进阶技巧

### 7.1 容器适配器的底层容器修改
```cpp
// 使用list作为stack的底层容器
stack<int, list<int>> lst_stack;

// 使用vector作为priority_queue的底层容器
priority_queue<int, vector<int>, greater<int>> min_heap;  // 小顶堆
```

### 7.2 自定义类型在容器中的使用
```cpp
struct Person {
    string name;
    int age;
    
    // 用于set/map的排序
    bool operator<(const Person& other) const {
        return age < other.age;
    }
    
    // 用于unordered容器的哈希
    struct Hash {
        size_t operator()(const Person& p) const {
            return hash<string>()(p.name) ^ hash<int>()(p.age);
        }
    };
};

// 使用示例
set<Person> personSet;
unordered_set<Person, Person::Hash> personHashSet;
```

### 7.3 高级算法应用

#### 7.3.1 排列组合
```cpp
vector<int> v = {1, 2, 3};
do {
    // 处理当前排列
} while (next_permutation(v.begin(), v.end()));
```

#### 7.3.2 局部排序
```cpp
// 部分排序
partial_sort(v.begin(), v.begin() + 3, v.end());  // 只排序前3个元素

// nth_element：快速选择
nth_element(v.begin(), v.begin() + n, v.end());   // 第n个元素就位
```

### 7.4 内存优化技巧

#### 7.4.1 容器大小控制
```cpp
vector<int> v;
v.reserve(1000);              // 预分配空间
v.shrink_to_fit();           // 释放多余空间
vector<int>(v).swap(v);      // 强制释放多余内存
```

#### 7.4.2 自定义分配器
```cpp
template <typename T>
class CustomAllocator {
    // 自定义内存分配策略
};
vector<int, CustomAllocator<int>> custom_vec;
```

## 8. 实战技巧

### 8.1 容器选择指南

| 需求 | 推荐容器 | 原因 |
|------|----------|------|
| 频繁随机访问 | vector | 连续内存，O(1)访问 |
| 频繁插入删除 | list | O(1)插入删除 |
| 两端操作 | deque | 两端O(1)操作 |
| 关联查找 | map/set | O(log n)查找 |
| 哈希查找 | unordered_map/set | 平均O(1)查找 |

### 8.2 异常安全
```cpp
// RAII方式使用容器
class ResourceManager {
    vector<Resource> resources;
public:
    void addResource() {
        Resource temp;  // 临时对象
        // ... 初始化temp
        resources.push_back(std::move(temp));  // 移动语义
    }
};
```

### 8.3 性能优化实例

#### 8.3.1 避免不必要的拷贝
```cpp
// 不好的做法
for (auto elem : container) {  // 拷贝元素
    process(elem);
}

// 好的做法
for (const auto& elem : container) {  // 使用引用
    process(elem);
}
```

#### 8.3.2 预留空间
```cpp
vector<string> words;
words.reserve(expectedSize);  // 预分配空间
while (getline(file, word)) {
    words.push_back(std::move(word));  // 移动而不是拷贝
}
```

### 8.4 调试助手
```cpp
template<typename Container>
void debugContainer(const Container& c, const string& name) {
    cout << "Container " << name << " contains " << c.size() 
         << " elements:" << endl;
    for (const auto& elem : c) {
        cout << elem << " ";
    }
    cout << endl;
}
```

## 9. 注意事项总结

1. 容器选择
   - 需要随机访问时优先使用vector
   - 需要频繁插入删除时使用list
   - 需要快速查找时使用unordered容器

2. 迭代器使用
   - 保存end()迭代器避免重复计算
   - 注意迭代器失效的场景
   - 优先使用范围for循环

3. 内存管理
   - 合理使用reserve()避免重新分配
   - 及时释放不需要的内存
   - 考虑使用移动语义优化性能

4. 线程安全
   - 多线程环境下需要额外同步
   - 避免多线程同时修改容器
   - 考虑使用并发容器