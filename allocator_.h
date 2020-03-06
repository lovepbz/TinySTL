#ifndef ALLOCATOR_H
#define ALLOCATOR_H 1
#include<cstdlib>

class allocator_
{
public:
#define LEN 16
	allocator_() { for (int i = 0; i < LEN; ++i)arr[i] = nullptr; };
	struct obj { obj* p; };
	void* allocate(size_t size)
	{
		int index = size / 8 +(size%8>0)-1;
		if (index >= LEN)return malloc(size);
		else
		{
			if (arr[index] == nullptr)
			{
				arr[index] = (obj*)malloc(index * 8 * chunk);
				obj* ptr = arr[index];
				int add = 8 / sizeof(ptr);
				for (int i = 0; i < LEN - 1; ++i)
				{
					ptr->p = ptr + add;
					ptr = ptr->p;
				}
				ptr->p = nullptr;
			}
			void* res = arr[index];
			arr[index] = arr[index]->p;
			return res;
		}
	}
	void deallocate(obj* p,size_t size)
	{
		int index = size / 8 + (size % 8 > 0) - 1;
		if (index >= LEN)
		{
			free(p);
		}
		else
		{
			obj* t = arr[index];
			arr[index] = p;
			arr[index]->p = t;
		}
	}
private:

	obj* arr[LEN];
	const int chunk = 16;

};

#endif // !ALLOCATOR_H
