#ifndef SEQLIST
#define SEQLIST
#include<iostream>

#define MAXSIZE 100

typedef long Type;

class SeqList
{
public:
	SeqList(int n = MAXSIZE);   //创建有一定容量的空表
	SeqList(const SeqList& l);  //深拷贝
	~SeqList() { delete[] date; };
	SeqList& operator=(const SeqList& l); //深赋值
	int InsertRear(const Type& item);   //在末尾插入元素,返回状态
	int Insert(int id, const Type& item);
	void Erase(int id);
	void Erase(Type* itr);
	void Clear() { size = 0; };
	Type& operator[](int id);
	const Type& operator[](int id)const;
	const Type& Getdate(int id)const;
	int Size()const { return size; }
	int Empty()const { return size == 0; }
	int Full()const { return size == max; }
	Type* Begin() { return date; }
	const Type* Begin()const { return date; }
	Type* End() { return date + size; }
	const Type* End()const { return date + size; }
	void Swap(int id1, int id2);
	void Replace(int id, const Type&item);
	Type* GetPoint(int id);
private:
	int size;
	int max;
	Type* date;  //这一块如果直接用指针来指向一段内存来表示数组的话，编译器可能会报错，因为编译器无法确定这段内存的大小
	            //本处由于老师在出题时给出的类声明如此于是得以保留
};


SeqList::SeqList(int n)
{
	date = new Type[n];
	size = 0;
	max = n;
}


SeqList::SeqList(const SeqList& l)
{
	date = NULL;
	*this = l;
}

Type& SeqList::operator[](int id)
{
	return date[id];
}

const Type& SeqList::operator[](int id) const
{
	return date[id];
}

SeqList& SeqList::operator=(const SeqList& l)
{
	size = l.size;
	max = l.max;
	if (date != NULL)
		delete[] date;
	date = new Type[max];
	for (int i = 0; i < l.size; i++)
		date[i] = l.date[i];
	return *this;
}



int SeqList::InsertRear(const Type& item)
{
	if (size == max)
		return 0;
	else
	{
		date[size] = item;
		size++;
		return 1;
	}
}

int SeqList::Insert(int id, const Type& item)
{
	if (size == max)
		return 0;
	else if (id < 0 || id > max - 1)
		return 0;
	else
	{
		for (int j = size - 1; j >= id; j--)
			date[j + 1] = date[j];
		date[id] = item;
		size++;
		return 1;
	}
}

void SeqList::Erase(int id)
{
	if (id < max && id >= 0)
	{
		for (int i = id; i < max - 1; i++)
		{
			date[i] = date[i + 1];
		}
		size--;
	}
}


void SeqList::Erase(Type* itr)
{
	int i = 0;
	while (&date[i] != itr)
	{
		i++;
	}
	(*this).Erase(i);
	/*Erase(i);*/
}

const Type& SeqList::Getdate(int id)const
{
	return date[id];
}

void SeqList::Swap(int id1, int id2)
{
	Type temp = date[id1];
	date[id1] = date[id2];
	date[id2] = temp;
}

void SeqList::Replace(int id, const Type& item)
{
	date[id] = item;
}

Type* SeqList::GetPoint(int id)
{
	return &date[id];
}
#endif
