#include <stdio.h>
#include <string.h>
 
int blocks[100002];
int main(void)
{
    int T, test_case;
 
    freopen("input.txt", "r", stdin);
 
    setbuf(stdout, NULL);
 
    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {
        int Answer = 0, N, i;
        scanf("%d", &N);
 
        memset(blocks, 0, sizeof(blocks));
 
        for (i = 1; i <= N; i++)
        {
            scanf("%d", &blocks[i]);
        }
 
        for (i = 1; i <= N; ++i)
        {
            if (blocks[i - 1] + 1 < blocks[i])
            {
                blocks[i] = blocks[i - 1] + 1;
            }
        }
        for (i = N; i >= 1; --i)
        {
            if (blocks[i + 1] + 1 < blocks[i])
            {
                blocks[i] = blocks[i + 1] + 1;
            }
        }
 
        for (i = 1; i < N; ++i)
        {
            if (Answer < blocks[i])
                Answer = blocks[i];
        }
 
        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
 
    return 0; //Your program should return 0 on normal termination.
}