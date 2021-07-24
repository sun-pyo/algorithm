import java.io.*;
import java.util.*;

public class n2224{

    private static char to_ch(int num){
        if(num >= 0 && num < 26) return (char)((int)'A' + num);
        else return (char)((int)'a' + num - 26);
    }

    private static int to_num(char ch){
        if(ch >= 'A' && ch <= 'Z') return ch - 'A';
        else return 26 + ch - 'a';
    }

    private static int[][] distance = new int[52][52];

    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine().trim());
        String line;
        char front, back;

        for(int i=0;i<52;i++){
            Arrays.fill(distance[i], -1);
        }
        for(int i=0;i<N;i++){
            line = bf.readLine().trim();
            front = line.charAt(0);
            back = line.charAt(5);
            distance[to_num(front)][to_num(back)] = 1;
        }

        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                for(int k=0;k<52;k++){
                    if(distance[j][i] + distance[i][k] > 0){
                        distance[j][k] = 1;
                    }
                }
            }
        }
        
        ArrayList<String> answer = new ArrayList<>();
        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                if(i!=j && distance[i][j] > 0){
                    answer.add(String.format("%c => %c\n", to_ch(i), to_ch(j)));
                }
            }
        }
        System.out.println(answer.size());
        for(String s : answer){
            System.out.print(s);
        }
    }
}
