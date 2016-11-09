class Solution {
public:
    void push(int value) {
        m_list.push_back(value);
    }
    void pop() {
        if (m_list.empty())
            return;
        m_list.erase(m_list.end()-1);
    }
    int top() {
        if (m_list.empty()) {
            return -1;
        }
        return *m_list.rbegin();
    }
    int min() {
        if (m_list.empty()) {
            return -1;
        }
        int m = m_list[0];
        for (int i=1; i<m_list.size(); ++i) {
            if (m_list[i] < m)
                m = m_list[i];
        }
        return m;
    }
private:
    vector<int> m_list;
};
