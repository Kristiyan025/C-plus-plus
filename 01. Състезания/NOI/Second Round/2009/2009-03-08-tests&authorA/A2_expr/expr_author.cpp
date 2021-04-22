#include <iostream>
using namespace std;
typedef struct 
{long long value,mulBase;
}Node;
typedef struct BSTree
{Node n;
 BSTree *l,*r;
};
typedef struct List
{BSTree *tp;
 List *next;
};
typedef struct 
{List *First,*Last;
}Queue;
int a[24],n;
long cnt=0;
BSTree *t[2]={NULL,NULL};
Queue Q={NULL,NULL};
void inp(istream &is)
{int i;
 is>>n;
 for (i=0;i<n;i++) cin>>a[i];
}
void add(BSTree **b, long long val,long long mB,bool isLast)
{if (!*b) {*b=new BSTree;
           (*b)->n.value=val;
	       (*b)->n.mulBase=mB;
	       (*b)->l=(*b)->r=NULL;
	       cnt++;
	       return;
	      }
 BSTree *p=*b,*q;
 while (p)
 {if (p->n.value==val && (isLast || p->n.mulBase==mB)) return;
  q=p;
  if (val<p->n.value) p=p->l;
  else p=p->r;
 }
 p=new BSTree;
 p->n.value=val;
 p->n.mulBase=mB;
 p->l=p->r=NULL;
 cnt++;
 if (val<q->n.value) q->l=p;
 else q->r=p;
}
void Qput(Queue *q,BSTree *a)
{if (!q->First){q->First=new List;
		q->First->tp=a;
		q->First->next=NULL;
		q->Last=q->First;
		return;
	       }
 List *t=new List;
 t->tp=a;
 t->next=NULL;
 q->Last->next=t;
 q->Last=t;
 return;
}
bool Qget(Queue *q, BSTree **r)
{if (!q->First) return false;
 *r=q->First->tp;
 List *t=q->First;
 q->First=q->First->next;
 delete t;
 return true;
}
void MakeQ(BSTree *b)
{List *p;
 if (b) Qput(&Q,b);
 else return;
 p=Q.First;
 while (p)
 {if (p->tp->l) Qput(&Q,p->tp->l);
  if (p->tp->r) Qput(&Q,p->tp->r);
  p=p->next;
 }
}
void NextTree(int lev,int *a,bool isLast,BSTree **Curr,BSTree **Next)
{BSTree *p;
 MakeQ(*Curr);
 while (Qget(&Q,&p))
 {add(Next,p->n.value+a[lev],a[lev],isLast);
  add(Next,p->n.value-a[lev],-a[lev],isLast);
  add(Next,p->n.value-p->n.mulBase+p->n.mulBase*a[lev],
	   p->n.mulBase*a[lev],isLast);
  delete p;
 }
 *Curr=NULL;
}
void FreeTree(BSTree **p)
{if ((*p)->l) FreeTree (&(*p)->l);
 if ((*p)->r) FreeTree (&(*p)->r);
 delete *p;
 *p=NULL;
}

int main(void)
{inp(cin);
 int ind=0;
 add(&t[ind],a[0],a[0],1);
 cnt=1;
 for (int l=1;l<n;l++)
 {cnt=0;
  NextTree(l,a,l==n-1,&t[ind],&t[ind^1]);
  ind^=1;
 }
 cout<<cnt<<endl;
 FreeTree(&t[ind]);
 return 0;
}
