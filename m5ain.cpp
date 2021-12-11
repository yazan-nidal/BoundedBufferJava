#include<iostream>
using namespace std;

template<typename T>
class BoundedBuffer
{
private :

	T *A;
	int size;
	int n;

	int front;
	int rear;


public :

BoundedBuffer(int mc=100) //BoundedBuffer (int mc) && BoundedBuffer()instal Initial size :100
{
	front = rear = -1; 
	size=mc+1;
	n=0;
	A=new T[size];
}

bool isempty(){ return (n <= 0)||(front == -1); } //is buffer empty

bool isfull(){ return (n >= size)||((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))); }
// is buffer full?

void put(T t) 
{
	if(isfull())
	{
		cout<<"\nBuffer is Full \n";
		return; 
	}

	n++;

	if(isempty())
	{
		front = rear = 0; 
        A[rear] = t; 
	}

	else

		if (rear == size-1 && front != 0) 
		{
			rear = 0; 
			A[rear] = t; 
		}

		else
		{
			rear++; 
			A[rear] = t; 
		}

}// add t to buffer

		T get()
		{

		if(isempty())
			 { 
				cout<<"\nBuffer is Empty : "; 
					return '\0'; 
			 }

			n--;

		   T data = A[front]; 
			A[front] = '\0'; 

			    if (front == rear) 
				 { 
					   front = -1; 
					   rear = -1; 
				 }

				else 
					if (front == size-1) 
							front = 0; 
								else
								  front++; 
  
			 return data; 

		} // remove element from buffer

~BoundedBuffer() 
{

	delete []A;
	A=NULL;
	n=front=rear=0;
}



};

void main()
{
	/*
	BoundedBuffer<int> a;
	a.put(5);
	a.put(4);
	a.put(3);
	cout<<a.get()<<endl;
	cout<<a.get()<<endl;
	cout<<a.get()<<endl;
	cout<<a.get()<<endl;

	cout<<"\n--------------------------------------------------------\n\n";


	BoundedBuffer<char> b;
	b.put('r');
	b.put('a');
	b.put('j');
	b.put('a');
	b.put('i');
	cout<<b.get();
	cout<<b.get();
	cout<<b.get();
	cout<<b.get();
	cout<<b.get()<<endl;
	cout<<b.get()<<endl<<endl;
	*/

	BoundedBuffer<int> d;

	int se=0;
	cout<<"menu : \n";
	cout<<"1-put data \n";
	cout<<"2-get data \n";
	cout<<"3-isempty \n";
	cout<<"4-isfull \n";
	cout<<"5-exit \n\n";
	while(se != 5){
	cout<<" enter option : ";
	cin>>se;
	cout<<"\n";
	switch(se)
	{
	case 1:{cout<<"\nEnter data : ";
		int n;
		cin>>n;
		d.put(n);
		cout<<"\n\n";
		break;}

		   case 2:{if(!d.isempty())cout<<"\ndata = "<<d.get()<<"\n\n"; else cout<<d.get()<<"\n\n";
			   break;}
		   case 3:{if(d.isempty()){cout<<"\nis empty\n\n";}else{cout<<"\nis not empty\n\n";}
					  break;}
						 case 4:{if(d.isfull()){cout<<"\nis full\n\n";}else{cout<<"\nis not full\n\n";}
							 break;}
								case 5:{break;}
	default :{cout<<"re";}
	}

	}
	cout<<"\n\n end of programe \n";
	
}