public class MovablePoint implements Movable {
    private int x, y;

    public MovablePoint(int x, int y) {
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
}
