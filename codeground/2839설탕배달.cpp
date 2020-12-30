#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int count=-1;
    int nam; //몫

    nam=n/5;

    if(n%5==0)
    {
        count=nam;
    }
    else
    {
        while(nam>=0)
        {
            if((n-5*nam)%3==0)
            {
                count=nam+(n-5*nam)/3;
                break;   
            }
            nam--;
        }
    }
    printf("%d",count);
    return 0;
}