#include "Linked_link.cpp"
#include <stdio.h>
#include <conio.h>

int main()
{
	list_linked<int> L;
	
	L.add(1);
	
	iterator<list_linked<int>, int> i;
	
	for(i.bind(&L) ; i.check ; i.next())
		printf("%d\n",i.get);
		
	L.freeme();
	
	getch();
}
