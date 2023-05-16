// LinkItDoubleTimes.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "LinkItDoubleTimes.h"
#include "List.h"
#include "List.cpp"				// when using templates - it is necessary to include also .cpp files!

using namespace std;

int main()
{
	// equivalent of "Create()" function that creates an empty list
	List<int> data = List<int>();
	data.add(5);
	data.add(234);
	data.add(-3);
	data.add_at(1532, 2);
	data.add_at(32, 0);
	printf("%d\n", data.get());
	
	data.display();
	printf("Pop element.");
	//data.listData();
	data.pop();
	//data.listData();
	data.display();
	
	printf("Remove at pos 2.\n");
	data.remove_at(2);
	
	printf("Pushing element 124\n");
	data.push(124);
	
	printf("Pushing element -523\n");
	data.push(-523);	

	data.display();
	data.sort();
	printf("After sorting:\n:");
	data.display();

	return 0;
}
