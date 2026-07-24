import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] last = new int[N + 1];
        long ans = 0;
        for (int i = 1; i <= N; i++) {
            int x = Integer.parseInt(st.nextToken());
            ans += 1L * (i - last[x]) * (N - i + 1);
            last[x] = i;
        }
        System.out.println(ans);
    }
}
