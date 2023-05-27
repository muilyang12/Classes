public abstract class Shape {
    private static int instanceNumber = 0;
    private int shapeId;

    protected Shape() {
        instanceNumber += 1;
        shapeId = instanceNumber;
    }

    public int getShapeId() {
        return shapeId;
    }

    abstract public double getArea();
}
