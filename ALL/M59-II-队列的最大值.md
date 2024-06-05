### 思路
先标记以下，这道题要求三个函数全部$O(1)$，感觉不太行
```cpp
class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() 
    {
        //d为空，直接返回-1
        return d.empty() ? -1 : d.front();
    }
    
    void push_back(int value) 
    {
        while (!d.empty() && d.back() < value)
        {
            d.pop_back();
        }
        q.push(value);
        d.push_back(value);
    }
    
    int pop_front() 
    {
        if (q.empty()) return -1;
        int temp = q.front();
        q.pop();
        if (temp == d.front())
        {
            d.pop_front();
        }    
        return temp;
    }
public:
    //存放输入的序列
    queue<int> q;
    //存放一个递减的最大值序列
    deque<int> d;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```