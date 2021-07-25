import java.io.*;
import java.util.*;

public class Main {

    private static int[][] dist = new int[501][501];

    private static void Floyd(int N){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=1;k<=N;k++){
                    if(dist[j][i] + dist[i][k] < dist[j][k]){
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }
    }

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        for(int i=1;i<=N;i++){
            StringTokenizer token = new StringTokenizer(br.readLine().trim());
            for(int j=1;j<=N;j++){
                dist[i][j] = Integer.parseInt(token.nextToken());
            }
        }
        Floyd(N);
        int A,B,C;
        for(int i=0;i<M;i++){
            StringTokenizer token = new StringTokenizer(br.readLine().trim());
            A = Integer.parseInt(token.nextToken());
            B = Integer.parseInt(token.nextToken());
            C = Integer.parseInt(token.nextToken());
            if(dist[A][B] <= C){
                bw.write("Enjoy other party\n");
            }
            else{
                bw.write("Stay here\n");
            }
        }
        bw.flush();
        bw.close();
    }
    
}
