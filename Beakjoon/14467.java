import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException{
        int[] arr = new int[10];
        Arrays.fill(arr, -1);
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine().trim());
        int num1, num2, answer = 0;
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(bf.readLine().trim());
            num1 = Integer.parseInt(st.nextToken()) - 1;
            num2 = Integer.parseInt(st.nextToken());
            if(arr[num1] != -1 && arr[num1] != num2){
                answer++;
            }
            arr[num1] = num2;
        }
        System.out.println(answer);
    }
}