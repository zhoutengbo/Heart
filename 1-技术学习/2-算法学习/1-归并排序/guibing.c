#include <stdio.h>

static int list[] = {3,4,23,123,235,4,5,234,23,42,34,23,5,23,5,23,23,5,234,23,4};

void swap(int* a,int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int merge(int* list,int size)
{
	int sl = 0,sr = 0;
 	if (size > 2)
        {	
		int pl = 0,pr = 0,tm_size = 0;
		int * tmp_list = NULL,*ll = NULL,*lr = NULL;
		sl = size/2;
		sr = size - sl;
		ll = list;
		lr = list + sl;
		merge(ll,sl);
		merge(lr,sr);
		tmp_list = (int*)malloc(sizeof(int) * size);
		while(pl < sl || pr < sr)
		{
			if (pr >= sr)
				tmp_list[tm_size++] = ll[pl++];
			else if (pl >= sl)
				tmp_list[tm_size++] = lr[pr++];
			else if(ll[pl] < lr[pr]) 
			{
				tmp_list[tm_size++] = ll[pl++];
			}
			else		
				tmp_list[tm_size++] = lr[pr++];
		}
		memcpy(list,tmp_list,sizeof(int) * size);
		free(tmp_list);
	}else if (size == 2)
	{
		if(list[0] > list[1])
		{
			swap(list,list + 1);
		}
	} 
}

int main()
{
	int len = sizeof(list)/sizeof(list[0]);
	        for(int i = 0;i < len;i++)
        {
                printf("%d ,",list[i]);
        }
	printf("\n");
	merge(list,len);
	for(int i = 0;i < len;i++)
	{
		printf("%d ,",list[i]);
	}
	printf("\n");
	return 	0;
}
