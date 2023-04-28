// LinkItDoubleTimes.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "LinkItDoubleTimes.h"
#include "List.h"
#include "List.cpp"				// when using templates - it is necessary to include also .cpp files!

using namespace std;

int main()
{
	List<int> data = List<int>();
	data.add(5);
	data.add(234);
	data.add(-3);
	data.addAt(1532, 2);
	data.addAt(32, 0);
	printf("%d", data.get());

	//data.listData();


	return 0;
}
