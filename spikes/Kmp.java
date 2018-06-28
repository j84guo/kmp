public class Kmp{

  // pattern and text
  private char[] p;
  private char[] t;

  // pattern and text length
  private int m;
  private int n;

  // prefix table
  private int[] b;

  // todo : what are these
  private String matches;
  private char[] showMatches;

  public void search(String t, String p){
    setText(t);
    setPattern(p);
    kmpSearch();
  }

  private void setText(String t){
    this.n = t.length();
    this.t = t.toCharArray();
    initMatches();
  }

  private void setPattern(String p){
    this.m = p.length();
    this.p = p.toCharArray();
    this.b = new int[this.m + 1];
    kmpPreprocess();
  }

  private void initMatches(){
    matches = "";
    showMatches = new char[this.n];

    for(int i=0; i<this.n; ++i){
      showMatches[i] = ' ';
    }
  }

  private void kmpPreprocess(){
    int i=0;
    int j=-1;

    // length 0 prefix has border -1
    this.b[i] = j;

    // we've set the border length for a length 0 prefix, now do 1 to m
    // note that the value of i going into the loop means: given the longest
    // border for a length i prefix... compute the border for length i+1
    while(i < this.m){

      // the previous border can be extended if p[i] (character i + 1 for base
      // zero) is equal to p[j] (the j + 1 character for the previous border)
      // when j == -1 we know the last possible border had length 0
      while(j >= 0 && this.p[i] != this.p[j]){
        j = this.b[j];
      }

      ++j; // extend the border
      ++i; // extend the index

      this.b[i] = j;

    }
  }

  private void kmpSearch(){
    int i=0;
    int j=0;

    // the pre process algorithm can also be applied on the concatenation p + t
    // in this case, we slide the suffix p down t and the finding of a length m
    // border indicates a match with the pattern
    // notice that after a match we reset the value of j to the widest border of
    // the pattern itself, in order to not extend the border past m
    while(i < n){

      while(j >= 0 && t[i] != p[j]){
        j = b[j];
      }

      ++j;
      ++i;

      if(j == m){
        // i is the first character off the end of the match
        // there fore the match begins at (i-1) - m + 1 == i - m
        report(i - m);

        // reset the previous border to the widest border of the pattern
        j = b[j];
      }
    }
  }

  private void report(int i){
    matches += i + " ";
    showMatches[i] = '^';
  }

  public String getMatches(){
    return matches;
  }
}
