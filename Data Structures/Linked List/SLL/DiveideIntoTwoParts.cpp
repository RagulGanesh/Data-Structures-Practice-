#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Sll{
    public:
    void append(int newData){
        Node *newAppendNode=new Node();
        newAppendNode->data=newData;
        newAppendNode->next=NULL;
        if(head==NULL){
            head=newAppendNode;
        }
        else{
            Node *q;
            q=head;
            while(q->next!=NULL){
                q=q->next;
            }
            q->next=newAppendNode;
        }
    }

    void printList(){
        Node *p;
        for(p=head;p!=NULL;p=p->next){
            cout<<p->data<<" ";
        }
    }

    int count(){
        int count=0;
        Node *q;
        for(q=head;q!=NULL;q=q->next){
            count++;
        }
        return count;
    }

    void divide(Sll a){
        int k=a.count();
        int mid=k/2;
        int i,j;
        Sll a1,a2;
        Node *p=a.head;
        for(i=1;i<=mid;i++){
            a1.append(p->data);
            p=p->next;
        }
        for(j=i;j<=k;j++){
            a2.append(p->data);
            p=p->next;
        }
        a1.printList();
        cout<<"\n";
        a2.printList();
    }

    Node *head=NULL;
};
int main(){
    Sll a;
    int n,data;
    cout<<"Enter size of the list : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        a.append(data);
    }
    a.divide(a);
}
