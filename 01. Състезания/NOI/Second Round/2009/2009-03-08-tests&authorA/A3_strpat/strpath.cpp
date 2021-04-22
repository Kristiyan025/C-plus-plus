#include <stdio.h>
#include <string.h>

int N,M; char lab[1005],last[1005],gr[1001][1001];
char pat[25]; int plen;
int q[25000000][2],qb,qe;
int main()
{
    
    int i,b,e,x,xl,le,y,j;
    scanf("%d %d",&N,&M);  
    scanf("%s",lab+1);
    for(i=1;i<=N;i++) gr[i][0]=0;
    for(i=1;i<=M;i++)
    {   scanf("%d %d",&b,&e);
        gr[b][++gr[b][0]]=e;
        if(b!=e) gr[e][++gr[e][0]]=b;
    }
    scanf("%s",pat+1);plen=strlen(pat+1);
    for(i=1;i<=N;i++)
    {
       if(lab[i]!=pat[plen-1]) continue;
       b=0;
       for(j=1;j<=gr[i][0];j++)
          if(lab[gr[i][j]]==pat[plen]) b++;
       last[i]=b;                     
    }
    qb=0; qe=0;le=1;
    for(i=1;i<=N;i++)
       if(lab[i]==pat[1]) {q[qe][0]=i;q[qe][1]=le;qe++;}
    while(qb<qe&&q[qb][1]<plen-1)
    {
       x=q[qb][0];xl=q[qb][1];qb++;
       j=gr[x][0];le=xl+1;
       for(i=1;i<=j;i++)
       { y=gr[x][i];
         if(lab[y]==pat[le]){q[qe][0]=y;q[qe][1]=le;qe++;}
       }
    }
    if(qb==qe) printf("0\n");
    else
    {  b=0;for(i=qb;i<qe;i++) b+=last[q[i][0]];
       printf("%d\n",b);
    }
    return 0; 
}   
     
    
     
