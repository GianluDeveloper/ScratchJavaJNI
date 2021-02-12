class JavaFromC {
    static {
        System.loadLibrary("javafromc");
    }

    private native String intheC(int i);

    public static void testit() {
        System.out.println("ok di java");
    }

    public static void main(String[] args) {
        JavaFromC c = new JavaFromC();
        c.intheC(2);
        System.out.println("in main");
    }
}