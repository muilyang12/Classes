public class App {
    public static void main(String[] args) throws Exception {
        Circle circle01 = new Circle(10);
        Circle circle02 = new Circle(5);
        Circle circle03 = new Circle(3);

        System.out.println(circle01.getRadius());
        System.out.println(circle01.getArea());
        System.out.println(circle01.getShapeId());

        System.out.println(circle02.getShapeId());
        System.out.println(circle03.getShapeId());

        // =========================

        // Cannot instantiate abstract class
        // Shape shape = new Shape();
    }
}
