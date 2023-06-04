public class App {
    public static void main(String[] args) throws Exception {
        // String Class
        final String tempString = "abcde"; 
        long start, end;

        String string = new String( ); // Immutable Class
        StringBuffer stringBuffer = new StringBuffer( ); // Mutable Class

        start = System.nanoTime( );
        for(int i = 0; i < 10000; i++) {
            string = string + tempString;
        }
        end = System.nanoTime( );
        System.out.println((end - start) / 1_000_000.0 + " msecs");

        start = System.nanoTime( );
        for(int i = 0; i < 10000; i++) {
            stringBuffer.append(tempString);
        }
        end = System.nanoTime( );
        System.out.println((end - start) / 1_000_000.0 + " msecs");

        // ==================================================
        // ==================================================

        Long number1 = 100L;
        Short number2 = number1.shortValue();
        System.out.println(number1.getClass());
        System.out.println(number2.getClass());

        // ==================================================
        // ==================================================

        // Wrapper Class
        Double radius1 = new Double(3.21); // Deprecated
        Double radius2 = Double.valueOf(3.21);
        Double radius3 = 3.21; // Auto Boxing

        double radius4 = radius2; // Auto unboxing
        double radius5 = radius3.doubleValue();
    }
}
