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

	data.listData();
	data.pop();
	data.listData();


	return 0;
}
