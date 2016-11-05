#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    long time;
    int id;
    node *next;
};
typedef node* nodeptr;
class queue
{
public:
    queue ();
    queue (const queue& a);
    ~queue();
    bool empty () const;
    void add (long time);
    void remove ();
    void help (long time);
    int estime ();
private:
    nodeptr front;
    nodeptr back;
    int dtime[3];
    int totalid;
};
queue::queue()
{
    front=back=NULL;
    dtime[0]=dtime[1]=dtime[2]=0;
    totalid=0;
}
queue::queue(const queue& a)
{
    if (a.empty())
        front=back=NULL;
    else
    {
        nodeptr tpold=a.front;
        nodeptr temp_ptr_new;
        back=new node;
        back->id=tpold->id;
        back->time=tpold->time;
        back->next=NULL;
        front=back;
        tpold=tpold->next;
        while (tpold!=NULL)
        {
            temp_ptr_new=new node;
            temp_ptr_new->id=tpold->id;
            temp_ptr_new->time=tpold->time;
            back->next=temp_ptr_new;
            back=temp_ptr_new;
            tpold=tpold->next;
        }
    }
}
queue::~queue()
{
    while (!empty())
        remove ();
}
bool queue::empty () const
{
    return (back==NULL);
}
void queue::add (long time)
{
    if (empty())
    {
        front=new node;
        front->id=totalid+1;
        totalid++;
        front->time=time;
        front->next=NULL;
        back=front;
    }
    else
    {
        nodeptr temp_ptr;
        temp_ptr=new node;
        temp_ptr->id=totalid+1;
        totalid++;
        temp_ptr->time=time;
        temp_ptr->next=NULL;
        back->next=temp_ptr;
        back=temp_ptr;
    }
}
void queue::remove ()
{
    if (empty()) exit(1);
    front=front->next;
    if (front==NULL)
    back=NULL;
}
void queue::help (long time)
{
    int o_id=front->id;
    long o_time=front->time;
    dtime[0]=dtime[1];
    dtime[1]=dtime[2];
    dtime[2]=time-o_time;
    remove();
    if (!empty())
        cout << "Customer " << o_id
             << " is being helped at time " << time
             << ". Wait time = " << time-o_time
             << " seconds. The estimated wait time for customer "
             << o_id+1 << " is " << estime()
             << " seconds." << endl;
}
int queue::estime ()
{
    double temp;
    if (dtime[0]==0 && dtime[1]==0) temp=dtime[2]+0.5;
    else if (dtime[0]==0) temp=(dtime[1]+dtime[2])/2+0.5;
    else temp=(dtime[0]+dtime[1]+dtime[2])/3+0.5;
    int esti_time=(int) temp;
    return esti_time;
}

int main ()
{
    int n,type;
    cin >> n;
    long time;
    queue q;
    for (int i=1; i<=n; i++)
    {
        cin >> time >> type;
        switch (type)
        {
            case 1:{q.add (time); break;}
            case 2:{q.help (time); break;}
            default: cout<<"wrong input"<<endl;
        }
    }
    return 0;
}
