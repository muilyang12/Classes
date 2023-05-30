public class App {
    public static void main(String[] args) throws Exception {
        Point movablePoint = new Point(0, 0);

        System.out.println(movablePoint.toString());

        movablePoint.moveRight();
        movablePoint.moveUp();

        System.out.println(movablePoint.toString());

        movablePoint.multiply(8);
        System.out.println(movablePoint.toString());
        movablePoint.divide(3);
        System.out.println(movablePoint.toString());
    }
}
