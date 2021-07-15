class Solution {
    int z_cnt, o_cnt;
    int map[][];
    
    private boolean check(int s_x, int s_y, int N){
        int pre = map[s_y][s_x];
        for(int i=s_y;i<N+s_y;i++){
            for(int j=s_x;j<N+s_x;j++){
                if(pre != map[i][j]) return false;
            }
        }
        if(pre == 1) o_cnt++;
        else if(pre == 0) z_cnt++;
        return true;
    }
    
    private void sol(int s_x, int s_y, int N){
        if(check(s_x, s_y, N)) return;
        
        sol(s_x, s_y, N/2);
        sol(s_x+N/2, s_y, N/2);
        sol(s_x, s_y+N/2, N/2);
        sol(s_x+N/2, s_y+N/2, N/2);
    }
    
    public int[] solution(int[][] arr) {
        int[] answer = {};
        answer = new int[2];
        map = arr;
        z_cnt = 0;
        o_cnt = 0;
        sol(0, 0, arr.length);
        answer[0] = z_cnt;
        answer[1] = o_cnt;
        return answer;
    }
}