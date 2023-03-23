#include "seqList.h"
#include <iostream>
using namespace std;

int main()
{
	SeqList SEQ1(MAXSIZE), SEQ2(MAXSIZE);
	SEQ1.InsertRear(10);
	SEQ1.InsertRear(11);
	SEQ1.InsertRear(12);
	SEQ1.Insert(3 , 13);
	/*SEQ1.Erase(3);
	SEQ1.Erase(2);*/
	SEQ1.Erase(SEQ1.GetPoint(1));
	long a = SEQ1.Getdate(0);
	long b = SEQ1.Getdate(1);
	long c = SEQ1.Getdate(2);
	long d = SEQ1.Getdate(3);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	return 0;
}
