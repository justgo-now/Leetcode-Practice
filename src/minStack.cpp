/*************************************************************************
	> File Name: minStack.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 May 2015 02:40:15 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        st.push(x);
        sortedArray.push_back(x);
        sort(sortedArray.begin(), sortedArray.end());
    }

    void pop() {
        int val = top();
        st.pop();
        remove_if(sortedArray.begin(), sortedArray.end(), bind2nd(equal_to<int>(), val));
    }

    int top() {
        return st.top();
    }

    int getMin() {
        if (!sortedArray.empty())
          return sortedArray[0];
        else return 0;
    }
private:
    vector<int> sortedArray;
    stack<int> st;
    int minVal;
};

int main()
{
  MinStack ms;
  ms.push(-1);
  cout << ms.top() << " " << ms.getMin() << endl;
}
