class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> group;
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        freq[val]++;

        int f = freq[val];

        group[f].push_back(val);

        maxFreq = max(maxFreq, f);
    }

    int pop() {
        int val = group[maxFreq].back();

        group[maxFreq].pop_back();

        freq[val]--;

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};