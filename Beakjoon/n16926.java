package Beakjoon;

import java.io.*;
import java.util.StringTokenizer;


public class n16926 {
    
    public static void main(String args[]) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine().trim());
        int N, M, R;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        int arr[][] = new int[N][M];

        for(int i=0;i<N;i++){
            st = new StringTokenizer(bf.readLine().trim());
            for(int j=0;j<M;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int iter = Math.min(N, M)/2;
        int r, c, temp, next;
        for(int k=0;k<R;k++){
            for(int i=0;i<iter;i++){
                // down
                next = arr[i][i];
                for(int j=i;j<N-i-1;j++){
                    temp = arr[j+1][i];
                    arr[j+1][i] = next;
                    next = temp;
                }
                // right
                for(int j=i;j<M-i-1;j++){
                    temp = arr[N-i-1][j+1];
                    arr[N-i-1][j+1] = next;
                    next = temp;
                }
                // // up
                for(int j=N-i-1;j>i;j--){
                    temp = arr[j-1][M-i-1];
                    arr[j-1][M-i-1] = next;
                    next = temp;
                }
                // left
                for(int j=M-i-1;j>i;j--){
                    temp = arr[i][j-1];
                    arr[i][j-1] = next;
                    next = temp;
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
}
