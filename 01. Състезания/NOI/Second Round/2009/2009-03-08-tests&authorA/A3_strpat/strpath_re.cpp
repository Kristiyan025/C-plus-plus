#include <stdio.h>
#include <string.h>

int N,M; char lab[1005],gr[1001][1001];
char pat[25]; int plen;
int q[20000000][2],qb,qe;
int rec_br(int v,int h)
{
   int br=0,x; 
   if(h==plen) return 1;
   for(int i=1;i<=gr[v][0];i++)
       if(lab[gr[v][i]]==pat[h+1])
       {
           x=rec_br(gr[v][i],h+1); br += x;
       }
    return br;    
}    

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
    int s=0;
    for(i=1;i<=N;i++)
    {   
       if(lab[i]==pat[1]) {x=rec_br(i,1);s=s+x;}
     }
    
    printf("%d\n",s);
}   
     
    
     
