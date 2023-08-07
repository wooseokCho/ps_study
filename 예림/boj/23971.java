import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String args[]) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        double H = Integer.parseInt(st.nextToken());
        double W = Integer.parseInt(st.nextToken());
        double N = Integer.parseInt(st.nextToken());
        double M = Integer.parseInt(st.nextToken());

        int width = (int) Math.ceil(W / (M + 1));
        int height = (int) Math.ceil(H / (N + 1));

        System.out.println(width * height);
    }
}