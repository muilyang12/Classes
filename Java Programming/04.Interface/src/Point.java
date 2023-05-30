public class Point implements Movable, Scalable {
    private int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "Point at (" + x + ", " + y + ")";
    }

    public void moveUp() { y++; }
    public void moveDown() { y--; }
    public void moveLeft() { x--; }
    public void moveRight() { x++; }

    public void multiply(double scale) {
        this.x *= scale;
    }
    public void divide(double scale) {
        this.x /= scale;
    }
}
