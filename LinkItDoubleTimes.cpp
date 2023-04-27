// LinkItDoubleTimes.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "LinkItDoubleTimes.h"
#include "List.h"

using namespace std;

int main()
{
	List<int> data = List<int>(nullptr);
	data.add(5);
	data.add(234);
	data.add(-3);

	data.listData();


	return 0;
}
