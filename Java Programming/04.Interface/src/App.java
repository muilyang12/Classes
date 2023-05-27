public class App {
    public static void main(String[] args) throws Exception {
        MovablePoint movablePoint = new MovablePoint(0, 0);

        System.out.println(movablePoint.toString());

        movablePoint.moveRight();
        movablePoint.moveUp();

        System.out.println(movablePoint.toString());
    }
}
