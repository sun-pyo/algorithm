import java.io.*;
import java.util.*;

public class Main{

    static List<List<Integer>> edge = new ArrayList<>();

    private static int[] dfs(int start, int N){
        Stack<Integer> stack = new Stack<>();
        stack.push(start);
        int[] visit = new int[N];
        Arrays.fill(visit, 0);
        int curr, next;
        while(!stack.empty()){
            curr = stack.pop();
            for(int i=0;i<edge.get(curr).size();i++){
                next = edge.get(curr).get(i);
                if(visit[next] == 0){
                    visit[next] = 1;
                    stack.push(next);
                }
            }
        }
        return visit;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int num, N;
        N = Integer.parseInt(bf.readLine().trim());
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(bf.readLine().trim());
            List<Integer> arr = new ArrayList<>();
            for(int j=0;j<N;j++){
                num = Integer.parseInt(st.nextToken());
                if(num == 1) arr.add(j);
            }
            edge.add(arr);
        }
        int[] arr;

        for(int i=0;i<N;i++){
            arr = dfs(i, N);
            for(int j=0;j<N;j++){
                System.out.print(arr[j] + " ");
            }
            System.out.println();
        }
    }
}