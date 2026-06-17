import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String a = s.next();
         String b = s.next();
         int dp[][]= new int[a.length()+1][b.length()+1];
         int m=0;
         for(int i=1;i<=a.length();i++){
             for(int j=1;j<=b.length();j++){
                 if(a.charAt(i-1) == b.charAt(j-1))
                 dp[i][j]=dp[i-1][j-1]+1;
                 else
                 dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);

             }
         }
         String t="";
         int i = a.length(),j=b.length();
         while(i>0 && j>0){
             if(a.charAt(i-1) == b.charAt(j-1)){
                 t+=a.charAt(i-1);
                 i--;
                 j--;
             }else {
                 if(dp[i-1][j]>dp[i][j-1])
                 i--;
                 else
                 j--;
             }
         }
         System.out.println("Length " +dp[a.length()][b.length()]);
         System.out.println("Longest Subsequence "+(new StringBuilder(t).reverse()));
    }
}
