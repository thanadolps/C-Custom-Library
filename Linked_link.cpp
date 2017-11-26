#include<stdlib.h>


template <class T>
struct list_linked
{
	T data;
	list_linked *next = NULL;
	
	void add(T data_)
	{
		if(next == NULL)
		{
			this -> data = data_;
			this -> next = (list_linked*)(malloc(sizeof(list_linked)));
			
			
			this -> next -> next = NULL;
		}
		else
		{
			//printf("Adding new next\n");
			this -> next -> add(data_);
		}
	};
	
	void freeme()
	{
		if(next)
			this -> next -> freeme();
		
		
		free(this -> next);
	}
	
	T get(int n)
	{	
		if(n == 0)
			return this -> data;
		else
			return this -> next -> get(n-1);
	}
	
};

template <typename T, class V>
struct iterator
{
	list_linked<V> *iterating;
	bool check = true;
	V get;
	
	void bind(list_linked<V> *iterating_)
	{
		this -> iterating = iterating_;
		
		this -> get = this -> iterating -> data;
		
	}
	
	void checker()
	{
		if(this -> iterating -> next == NULL)
		{
			this -> check = false;
			return;
		}
	}
	
	void next()
	{
		checker();
		
		if(this -> check)
		{
			this -> iterating = this -> iterating -> next;
			this -> get = this -> iterating -> data;
		}
		
		checker();
	}
	
	
};

/*int main()
{
	
	list_linked<float> ll;
	
	puts("Prepare To Add!!!");
	
	ll.add(1.0);
	ll.add(2.0);
	ll.add(3.0);
	
	iterator<list_linked<float>, float> iter;
	
	iter.bind(&ll);
	
	while(true)
	{
		if(iter.check)
			printf("%f\n",iter.get);
		else
			break;
		iter.next();
	}

	ll.freeme();
	
	getch();
	
}*/
