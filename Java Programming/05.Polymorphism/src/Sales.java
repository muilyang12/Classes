public class Sales extends Employee {
    public Sales() {
        this.department = "Sales";
    }

    public void doJob() {
        System.out.println("Doing sales");
    }

    public void doJob(String item) {
        System.out.println("Selling " + item);
    }
}
