
public class ScratchJNI {

   static {
      System.loadLibrary("scratchjni");
   }

   private native String callTheC(int i, String s);

   public static void main(String[] args) {
      String passToC = "https://gianlu.dev/";
      int intToC = 14;
      ScratchJNI obj = new ScratchJNI();
      String responseFromC = obj.callTheC(intToC, passToC);
      System.out.println("The response from C is: " + responseFromC);
   }

}
