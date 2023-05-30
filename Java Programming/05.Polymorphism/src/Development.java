public class Development extends Employee {
    public Development() {
        this.department = "Development";
    }

    public void doJob() {
        System.out.println("Doing development");
    }

    public void doJob(String className) {
        System.out.println("Developing " + className + " class");
    }
}
