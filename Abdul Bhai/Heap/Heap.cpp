#include<iostream>
using namespace std;
class heap{
    int heapSize,arrSize;
    int *arr;
public:
    heap(int a){
        arrSize=a;
        heapSize=0;
        arr=new int[a+1];
    }
    ~heap(){
        delete [] arr;
    }
    void Insert(int);
    void display();
    int del();
    void Sort();
};
/*Insertion is done level wise from left to right, as Heap is Complete
Binary Tree. Then we check if newly inserted element follows heap condition
, if not we heapify, ie we exchange with parent until it satisfies */
void heap::Insert(int d){
    if(heapSize==arrSize) {
        cout<<"\nHEAP FULL."<<endl;return;
    }
    else if(heapSize==0)
        arr[++heapSize]=d;
    else{
        arr[++heapSize]=d;
        int tmp=d,i=heapSize;
        while(i>1&&tmp>arr[i/2]){
            arr[i]=arr[i/2];//parent and child swapping
            i/=2;
        }
        arr[i]=tmp;

    }
}
void heap::display(){
    cout<<"\nHEAP DATA :";
    for(int i=1;i<=heapSize;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void heap::Sort(){
    while(heapSize)
        del();
    cout<<"\nSORTED DATA :";
    for(int i=1;i<=arrSize;i++)
        cout<<arr[i]<<" ";
}
int heap::del(){
    int i,j,val,tmp;
    val=arr[1];
    arr[1]=arr[heapSize]; //delete root element
    arr[heapSize]=val; //storing deleted element in free space
    heapSize--; //after delete
    i=1;j=2*i; //root node;
    while(j<heapSize){ //arranging root element
        if(arr[j+1]>arr[j]) //max of two children
            j=j+1;
        if(arr[i]<arr[j]){
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i=j;
            j=i*2;
        }
        else break;
    }
    return val;
}
int main(){
    int opt,d,n;
    cout<<"\nENTER NO OF ELEMENTS :";
    cin>>n;
    heap h(n);
    while(1){
        cout<<"\n1.Insert\n2.Display\n3.Delete\n4.Heap Sort\nOption :";
        cin>>opt;
        if(opt>4) break;
        switch(opt){
        case 1:
            cout<<"Enter Value :";cin>>d;
            h.Insert(d);break;
        case 2:
            h.display();break;
        case 3:
            cout<<"\nDeleted Element :"<<h.del()<<endl;break;
        case 4:
            h.Sort();break;
        }
    }


}
