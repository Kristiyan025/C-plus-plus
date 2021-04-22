#include <iostream>
using namespace std;
typedef struct BSTree
{long long n;
 BSTree *l,*r;
};
int a[20],n;
long cnt=0;
BSTree *t=NULL;
void inp(istream &is)
{int i;
 is>>n;
 for (i=0;i<n;i++) cin>>a[i];
}
void add(BSTree **b, long long a)
{if (!*b) {*b=new BSTree;
	   (*b)->n=a;
	   (*b)->l=(*b)->r=NULL;
	   cnt++;
	   return;
	  }
 BSTree *p=*b,*q;
 while (p)
 {if (p->n==a) return;
  q=p;
  if (a<p->n) p=p->l;
  else p=p->r;
 }
 p=new BSTree;
 p->n=a;
 p->l=p->r=NULL;
 cnt++;
 if (a<q->n) q->l=p;
 else q->r=p;
}
void FreeTree(BSTree **p)
{if ((*p)->l) FreeTree (&(*p)->l);
 if ((*p)->r) FreeTree (&(*p)->r);
 delete *p;
 *p=NULL;
}
void makeExpr(int lev,long long s,long long last,char prOp)
{if (lev>n-1){add(&t,s);
              return;
             }
 makeExpr(lev+1,s+a[lev],a[lev],'+');
 makeExpr(lev+1,s-a[lev],a[lev],'-');
 if (prOp=='+') makeExpr(lev+1,s-last+last*a[lev],last*a[lev],'+');
 else if (prOp=='-') makeExpr(lev+1,s+last-last*a[lev],last*a[lev],'-');
      else makeExpr(lev+1,s*a[lev],a[lev],'*');
}
int main(void)
{inp(cin);
 makeExpr(1,a[0],a[0],'+');
 FreeTree(&t);
 cout<<cnt<<endl;
 return 0;
}
