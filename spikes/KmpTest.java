// Kmp class is in the default package
public class KmpTest{

  public static void main(String[] args){
    Kmp kmp = new Kmp();

    String t;
    String p;

    t = "sgjfaljgfnalekfna";
    p = "fna";
    kmp.search(t, p);
    System.out.println(kmp.getMatches());
  }
}
