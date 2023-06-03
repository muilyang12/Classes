public class App {
    public static void main(String[] args) throws Exception {
        Pair<String, Integer> pair1;
        pair1 = new OrderedPair<>("Age", 28);
        System.out.println(pair1.toString());

        Pair<String, String> pair2;
        pair2 = new OrderedPair<>("Full Name", "Muil Yang");
        System.out.println(pair2.toString());
    }
}
