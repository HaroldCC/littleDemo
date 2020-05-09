#include <vector>
class MyQueue
{
private:
    std::vector<int> inStack;
    std::vector<int> outStack;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        inStack.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push_back(inStack.back());
                inStack.pop_back();
            }
        }
        int num = outStack.back();
        outStack.pop_back();
        return num;
    }

    /** Get the front element. */
    int peek()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push_back(inStack.back());
                inStack.pop_back();
            }
        }

        return outStack.back();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */