class Counter {
    int number;
public:
    Counter(int n = 0);
    ~Counter();

    Counter& operator ++ ();
    Counter operator ++ (int);
    Counter& operator += (const Counter& c);
    Counter& operator += (int n);
    Counter operator + (const Counter& c) const;
    Counter operator + (int n) const;
    operator int() const;

    int getCounterNum() const;
};