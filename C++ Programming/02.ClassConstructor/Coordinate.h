class Coordinate {
    double x;
    double y;

public:
    Coordinate(double x, double y);
    Coordinate(const Coordinate& coordinate);
    Coordinate(Coordinate&& coordinate);
    ~Coordinate();

    Coordinate moveToX(double dx);
    Coordinate moveToY(double dy);

    void print();
};
