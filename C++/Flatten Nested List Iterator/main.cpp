/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    // My solution. But I find that an iterator shouldn't copy all the data. Thus, my solution is not a good solution.
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto i : nestedList) {
            if (i.isInteger()) {
                list.push_back(i.getInteger());
            } else {
                NestedIterator iterator = NestedIterator(i.getList());
                for (int num : iterator.list) {
                    list.push_back(num);
                }
            }
        }
        
        count = list.size();
        index = 0;
    }

    int next() {
        return list[index++];
    }

    bool hasNext() {
        return index < count;
    }
    
    int count;
    int index;
    vector<int> list;
};

class NestedIterator {
private:
    stack<NestedInteger> nodes;
    
public:
    // A better solution, don't need to store all data at initialization.
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            nodes.push(nestedList[i]);
        }
    }

    int next() {
        int res = nodes.top().getInteger();
        nodes.pop();
        return res;
    }

    bool hasNext() {
        while (nodes.size()) {
            if (nodes.top().isInteger()) {
                return true;
            }
            
            NestedInteger topInt = nodes.top();
            nodes.pop();
            
            auto list = topInt.getList();
            
            for (int i = list.size() - 1; i >= 0; i--) {
                nodes.push(list[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */