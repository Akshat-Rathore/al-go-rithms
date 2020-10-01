/*Description of game:
James is a frog who is currently sitting on a rock. The rocks around him are arranged in a grid of size
A × B, with co-ordinates ranging from (0, 0) to (A − 1, B − 1). James is sitting at (Jx, Jy). James can
jump on adjacent rocks which are to the North, East, West or South of it’s current rock. Some rocks are
unstable and hence he cannot land over those rocks. A fly is sitting on a rock which is at the coordinate
(Fx, Fy). James has to reach the rock on which the fly is sitting (it is assured that the rock on which James
/ fly is sitting is stable), by jumping on only the stable rocks. Is it possible?If possible, find the path!
*/
#include <iostream>
using namespace std;
#include <string>


typedef struct {
    int x,y;
}POINT;
typedef struct{
    POINT *arr;
    int que_size,start_id,end_id;
}QUEUE;
void init(QUEUE *qP, int size);//allocates space for queue
int isempty(QUEUE qP);//returns 1 if the queue is empty, else 0
void enqueue(QUEUE *qP, POINT p);
void dequeue(QUEUE* qP);
int strategy1(int a[][200],int xm,int ym,POINT j,POINT f);
// bool strategy2(int a[][200],int xm,int ym,POINT src,POINT des,bool v[][200],STACK* path);

 struct STACK{
 POINT head;
 struct STACK* next;
}  ;
STACK* top;
void init(STACK *s); //initializes the head and next pointer
int isempty(STACK s);//returns 1 if the stack is empty, 0 otherwise
void push(STACK *s, POINT p);
POINT pop(STACK *s);
void display(STACK s);
bool strategy2(int a[][200],int xm,int ym,POINT src,POINT des,bool v[][200],STACK* path);

void init(STACK* s)
{
    s->head.x=-1;
    s->head.y=-1;
    s->next=NULL;
}

int isempty()
{
    if(top==NULL)
        return 1;
    else 
        return 0;
}

void push(STACK* s, POINT p)
{
    STACK* temp;
    temp=new STACK();
    if (!temp) 
    {  
        cout << "\nHeap Overflow";  
        exit(1);  
    }  
    temp->head.x=p.x;
    temp->head.y=p.y;
    temp->next=top;
    top=temp;
}
POINT pop(STACK* s)
{
    STACK* temp;
     if (top == NULL)  
    {  
        cout << "\nStack Underflow" << endl;  
        exit(1);  
    }  
    else
    {
        temp=top;
        top=top->next;
        temp->next=NULL;
        return(temp->head);
        
    }
    
}
void display(STACK s)
{
    STACK* t;
    t=top;
    while(t!=NULL)
    {
        cout<<"("<<t->head.x<<","<<t->head.y<<")"; 
        t=t->next;
    }
}

bool strategy2(int a[][200],int xm,int ym,POINT src,POINT des,bool v[][200],STACK* path)
{
    v[src.x][src.y]=true;
    push(path,src);
    if(src.x==des.x && src.y==des.y)
    {
        return true;
    }
    
        if(src.x==xm-1 && src.y==ym-1)
        {
            
             	int i=a[src.x-1][src.y];
            if(i!=1 && !v[src.x-1][src.y])
            {
                v[src.x-1][src.y]=true;
                POINT s;
                s.x=src.x-1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
            
             	 i=a[src.x][src.y-1];
            if(i!=1 && !v[src.x][src.y-1])
            {
                v[src.x][src.y-1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y-1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
            
            
        }
        else if(src.x==xm-1 && src.y==0)
        {
            	int i=a[src.x-1][src.y];
            if(i!=1 && !v[src.x-1][src.y])
            {
                v[src.x-1][src.y]=true;
                POINT s;
                s.x=src.x-1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
            
             	 i=a[src.x][src.y+1];
            if(i!=1 && !v[src.x][src.y+1])
            {
                v[src.x][src.y+1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y+1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        else if(src.x==0 && src.y==ym-1)
        {
            	int i=a[src.x+1][src.y];
            if(i!=1 && !v[src.x+1][src.y])
            {
                v[src.x+1][src.y]=true;
                POINT s;
                s.x=src.x+1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
            
             	 i=a[src.x][src.y-1];
            if(i!=1 && !v[src.x][src.y-1])
            {
                v[src.x][src.y-1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y-1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        else if(src.x==0 && src.y==0)
        {
            	int i=a[src.x+1][src.y];
            if(i!=1 && !v[src.x+1][src.y])
            {
                v[src.x+1][src.y]=true;
                POINT s;
                s.x=src.x+1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
            
             	 i=a[src.x][src.y+1];
            if(i!=1 && !v[src.x][src.y+1])
            {
                v[src.x][src.y+1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y+1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        else if(src.x==xm-1)
        {
            int i=a[src.x-1][src.y];
            if(i!=1 && !v[src.x-1][src.y])
            {
                v[src.x-1][src.y]=true;
                POINT s;
                s.x=src.x-1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x][src.y+1];
            if(i!=1 && !v[src.x][src.y+1])
            {
                v[src.x][src.y+1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y+1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x][src.y-1];
            if(i!=1 && !v[src.x][src.y-1])
            {
                v[src.x][src.y-1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y-1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        else if(src.x==0)
        {
             int i=a[src.x+1][src.y];
            if(i!=1 && !v[src.x+1][src.y])
            {
                v[src.x+1][src.y]=true;
                POINT s;
                s.x=src.x+1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x][src.y+1];
            if(i!=1 && !v[src.x][src.y+1])
            {
                v[src.x][src.y+1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y+1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x][src.y-1];
            if(i!=1 && !v[src.x][src.y-1])
            {
                v[src.x][src.y-1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y-1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        else if(src.y==0)
        {
             int i=a[src.x][src.y+1];
            if(i!=1 && !v[src.x][src.y+1])
            {
                v[src.x][src.y+1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y+1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x+1][src.y];
            if(i!=1 && !v[src.x+1][src.y])
            {
                v[src.x+1][src.y]=true;
                POINT s;
                s.x=src.x+1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x-1][src.y];
            if(i!=1 && !v[src.x-1][src.y])
            {
                v[src.x-1][src.y]=true;
                POINT s;
                s.x=src.x-1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        else if(src.y==ym-1)
        {
             int i=a[src.x][src.y-1];
            if(i!=1 && !v[src.x][src.y-1])
            {
                v[src.x][src.y-1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y-1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x+1][src.y];
            if(i!=1 && !v[src.x+1][src.y])
            {
                v[src.x+1][src.y]=true;
                POINT s;
                s.x=src.x+1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x-1][src.y];
            if(i!=1 && !v[src.x-1][src.y])
            {
                v[src.x-1][src.y]=true;
                POINT s;
                s.x=src.x-1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        else
        {
             int i=a[src.x+1][src.y];
            if(i!=1 && !v[src.x+1][src.y])
            {
                v[src.x+1][src.y]=true;
                POINT s;
                s.x=src.x+1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x-1][src.y];
            if(i!=1 && !v[src.x-1][src.y])
            {
                v[src.x-1][src.y]=true;
                POINT s;
                s.x=src.x-1;
                s.y=src.y;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
             i=a[src.x][src.y+1];
            if(i!=1 && !v[src.x][src.y+1])
            {
                v[src.x][src.y+1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y+1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
            i=a[src.x][src.y-1];
            if(i!=1 && !v[src.x][src.y-1])
            {
                v[src.x][src.y-1]=true;
                POINT s;
                s.x=src.x;
                s.y=src.y-1;
                if(strategy2( a, xm, ym, s,des, v, path)){return true;}
            }
        }
        POINT TY=pop(path);
        return false;
}


void init(QUEUE *qp,int size)
{
    qp->que_size=size;
    qp->arr=new POINT[40000];
    for (int i=0;i<40000;i++)
    {
        qp->arr[i].x=-1;
        qp->arr[i].y=-1;
    }
    qp->start_id=0;
    qp->end_id=0;
}
int isempty(QUEUE qp)
{
    // for(int i=start_id;i<=end_id;i++)
    // {
    //     if(qp.arr[i].x==-1 && qp.arr[i].y==-1  )
    //         continue;
    //     else 
    //         return 0;
    //     return 1;
    // }
    if(qp.start_id==qp.end_id)
        return 1;
    else
        return 0;
        
}
void enqueue(QUEUE *QP,POINT p)
{
        QP->arr[QP->end_id].x=p.x;
        QP->arr[QP->end_id].y=p.y;
        QP->end_id++;
        return;
}
void dequeue(QUEUE* qp)
{
      if(qp->start_id==qp->end_id)
      cout<<"empty";
      else
      {
          for(int i=0;i<qp->end_id-1;i++)
          {
              qp->arr[i].x=qp->arr[i+1].x;
              qp->arr[i].y=qp->arr[i+1].y;
             
          }
          qp->end_id--;
      }
      return;
}
int strategy1(int a[][200],int xm,int ym,POINT j,POINT f)
{
    
    bool v[200][200];
for(int i=0;i<200;i++)
for(int j=0;j<200;j++)
v[i][j]=false;
    QUEUE q;
    init(&q,xm*ym);
    enqueue(&q,j);
    v[j.x][j.y]=true;
    while(!isempty(q))
    {
        POINT f2=q.arr[q.start_id];
        dequeue(&q);
        if(f2.x==f.x && f2.y==f.y)
            {
                cout<<"Path Exists";
                return 1;
            }
        if(f2.x==xm-1 && f2.y==ym-1)
        {
            
             	int i=a[f2.x-1][f2.y];
            if(i!=1 && !v[f2.x-1][f2.y])
            {
                v[f2.x-1][f2.y]=true;
                POINT s;
                s.x=f2.x-1;
                s.y=f2.y;
                enqueue(&q,s);
            }
            
             	 i=a[f2.x][f2.y-1];
            if(i!=1 && !v[f2.x][f2.y-1])
            {
                v[f2.x][f2.y-1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y-1;
                enqueue(&q,s);
            }
            
            
        }
        else if(f2.x==xm-1 && f2.y==0)
        {
            	int i=a[f2.x-1][f2.y];
            if(i!=1 && !v[f2.x-1][f2.y])
            {
                v[f2.x-1][f2.y]=true;
                POINT s;
                s.x=f2.x-1;
                s.y=f2.y;
                enqueue(&q,s);
            }
            
             	 i=a[f2.x][f2.y+1];
            if(i!=1 && !v[f2.x][f2.y+1])
            {
                v[f2.x][f2.y+1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y+1;
                enqueue(&q,s);
            }
        }
        else if(f2.x==0 && f2.y==ym-1)
        {
            	int i=a[f2.x+1][f2.y];
            if(i!=1 && !v[f2.x+1][f2.y])
            {
                v[f2.x+1][f2.y]=true;
                POINT s;
                s.x=f2.x+1;
                s.y=f2.y;
                enqueue(&q,s);
            }
            
             	 i=a[f2.x][f2.y-1];
            if(i!=1 && !v[f2.x][f2.y-1])
            {
                v[f2.x][f2.y-1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y-1;
                enqueue(&q,s);
            }
        }
        else if(f2.x==0 && f2.y==0)
        {
            	int i=a[f2.x+1][f2.y];
            if(i!=1 && !v[f2.x+1][f2.y])
            {
                v[f2.x+1][f2.y]=true;
                POINT s;
                s.x=f2.x+1;
                s.y=f2.y;
                enqueue(&q,s);
            }
            
             	 i=a[f2.x][f2.y+1];
            if(i!=1 && !v[f2.x][f2.y+1])
            {
                v[f2.x][f2.y+1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y+1;
                enqueue(&q,s);
            }
        }
        else if(f2.x==xm-1)
        {
            int i=a[f2.x-1][f2.y];
            if(i!=1 && !v[f2.x-1][f2.y])
            {
                v[f2.x-1][f2.y]=true;
                POINT s;
                s.x=f2.x-1;
                s.y=f2.y;
                enqueue(&q,s);
            }
             i=a[f2.x][f2.y+1];
            if(i!=1 && !v[f2.x][f2.y+1])
            {
                v[f2.x][f2.y+1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y+1;
                enqueue(&q,s);
            }
             i=a[f2.x][f2.y-1];
            if(i!=1 && !v[f2.x][f2.y-1])
            {
                v[f2.x][f2.y-1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y-1;
                enqueue(&q,s);
            }
        }
        else if(f2.x==0)
        {
             int i=a[f2.x+1][f2.y];
            if(i!=1 && !v[f2.x+1][f2.y])
            {
                v[f2.x+1][f2.y]=true;
                POINT s;
                s.x=f2.x+1;
                s.y=f2.y;
                enqueue(&q,s);
            }
             i=a[f2.x][f2.y+1];
            if(i!=1 && !v[f2.x][f2.y+1])
            {
                v[f2.x][f2.y+1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y+1;
                enqueue(&q,s);
            }
             i=a[f2.x][f2.y-1];
            if(i!=1 && !v[f2.x][f2.y-1])
            {
                v[f2.x][f2.y-1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y-1;
                enqueue(&q,s);
            }
        }
        else if(f2.y==0)
        {
             int i=a[f2.x][f2.y+1];
            if(i!=1 && !v[f2.x][f2.y+1])
            {
                v[f2.x][f2.y+1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y+1;
                enqueue(&q,s);
            }
             i=a[f2.x+1][f2.y];
            if(i!=1 && !v[f2.x+1][f2.y])
            {
                v[f2.x+1][f2.y]=true;
                POINT s;
                s.x=f2.x+1;
                s.y=f2.y;
                enqueue(&q,s);
            }
             i=a[f2.x-1][f2.y];
            if(i!=1 && !v[f2.x-1][f2.y])
            {
                v[f2.x-1][f2.y]=true;
                POINT s;
                s.x=f2.x-1;
                s.y=f2.y;
                enqueue(&q,s);
            }
        }
        else if(f2.y==ym-1)
        {
             int i=a[f2.x][f2.y-1];
            if(i!=1 && !v[f2.x][f2.y-1])
            {
                v[f2.x][f2.y-1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y-1;
                enqueue(&q,s);
            }
             i=a[f2.x+1][f2.y];
            if(i!=1 && !v[f2.x+1][f2.y])
            {
                v[f2.x+1][f2.y]=true;
                POINT s;
                s.x=f2.x+1;
                s.y=f2.y;
                enqueue(&q,s);
            }
             i=a[f2.x-1][f2.y];
            if(i!=1 && !v[f2.x-1][f2.y])
            {
                v[f2.x-1][f2.y]=true;
                POINT s;
                s.x=f2.x-1;
                s.y=f2.y;
                enqueue(&q,s);
            }
        }
        else
        {
             int i=a[f2.x+1][f2.y];
            if(i!=1 && !v[f2.x+1][f2.y])
            {
                v[f2.x+1][f2.y]=true;
                POINT s;
                s.x=f2.x+1;
                s.y=f2.y;
                enqueue(&q,s);
            }
             i=a[f2.x-1][f2.y];
            if(i!=1 && !v[f2.x-1][f2.y])
            {
                v[f2.x-1][f2.y]=true;
                POINT s;
                s.x=f2.x-1;
                s.y=f2.y;
                enqueue(&q,s);
            }
             i=a[f2.x][f2.y+1];
            if(i!=1 && !v[f2.x][f2.y+1])
            {
                v[f2.x][f2.y+1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y+1;
                enqueue(&q,s);
            }
            i=a[f2.x][f2.y-1];
            if(i!=1 && !v[f2.x][f2.y-1])
            {
                v[f2.x][f2.y-1]=true;
                POINT s;
                s.x=f2.x;
                s.y=f2.y-1;
                enqueue(&q,s);
            }
        }
            
    }
    cout<<"Path does not exists";
    return 0;
    
}





int main()
{
  int m[200][200];
  for(int i=0;i<200;i++)
    for(int j=0;j<200;j++)
        m[i][j]=0;
  int a=0,b=0,n=0;
  cin>>a;
  cin>>b;
  cin>>n;
  int x[200],y[200];
  for(int i=0;i<200;i++)
    {
        x[i]=y[i]=-1;    
    }
    for(int i=0;i<n;i++)
    {
        cin>>x[i];    
    }
    for(int i=0;i<n;i++)
    {
        cin>>y[i];    
    }
    int jx=-1,jy=-1,fx=-1,fy=-1;
    cin>>jx;
    cin>>jy;
    cin>>fx;
    cin>>fy;
    for(int i=0;i<n;i++)
    {
        m[x[i]][y[i]]=1;    
    }
    cout<<"Grid of stones is:"<<endl;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(m[i][j]==1)
            cout<<"-"<<" ";
            else 
            cout<<"*"<<" ";
            }
            cout<<"\n";
        }
        POINT j;
        j.x=jx;
        j.y=jy;
        POINT f;
        f.x=fx;
        f.y=fy;
    strategy1(m,a,b,j,f);
     bool v[200][200];
for(int i=0;i<200;i++)
for(int j=0;j<200;j++)
v[i][j]=false;
    STACK path;
    init(&path);
    
    if(strategy2( m, a, b, j,f, v, &path))
    display(path);
}
