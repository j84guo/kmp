// Kmp class is in the default package
public class KmpTest
{

  // in java arrays are a class type with fields, e.g. length
  public static int[] buildPrefixTable(char[] p)
  {
    // prefix table is one longer than the pattern length (0 to m)
    int m = p.length;
    int[] b = new int[m + 1];

    // setup border for the length 0 prefix
    b[0] = -1;
    int j = -1;

    // given the border for the length i prefix
    for(int i=0; i<m; ++i)
    {
      // try to extend all borders of the length i prefix, descending
      while(j >= 0 && p[j] != p[i]) j = b[j];

      // extend border, note the empty string's border -1 can even be extended
      ++j;
      b[i+1] = j;
    }

    return b;
  }

  public static void find(String text, String pattern)
  {
    // text
    char[] t = text.toCharArray();
    int n = t.length;

    // pattern
    char[] p = pattern.toCharArray();
    int m = p.length;

    // prefix table and previous border
    // we initialize j to 0 because we want comparisons to begin at i=0
    int[] b = buildPrefixTable(p);
    int j = 0;

    // examine each character of text
    for(int i=0; i<n; ++i)
    {
      while(j >= 0 && p[j] != t[i]) j = b[j];
      ++j;

      if(j == m)
      {
        System.out.println("Match at: " + (i - j + 1));
        j = b[j];
      }
    }
  }

  public static void main(String[] args)
  {
    /*
    * class implementation
    */
    Kmp kmp = new Kmp();
    String t = "sgjfaljgfnalekfna";
    String p = "fna";
    kmp.search(t, p);
    System.out.println(kmp.getMatches());

    /*
    * function implementation
    */
    String text = "asdljaabacdabaaldnabacdabaasdalmabacdaba";
    String pattern = "abacdaba";
    find(text, pattern);

    // int[] b = buildPrefixTable(pattern.toCharArray());
    // System.out.println(pattern);
    // for(int i : b) System.out.print(i + " ");
    // System.out.println();

    // int[] a = new int[0];
    // int[] b = new int[0];
    // System.out.println(a == b);
  }
}
