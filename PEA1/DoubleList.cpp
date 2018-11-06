#include "stdafx.h"
#include "DoubleList.h"


void DoubleList::clear(int key)
{
	Link *help = head;
	while (help)
	{
		if (help->key == key)
		{
			if (size == 0)
			{
				break;
			}
			if (size==1)
			{
				head = tail = NULL;
				size--;
				break;
			}
			else if(head->key==key)
			{
				head = head->next;
				head->prev = NULL;
				size--;
				break;
			}
			else if (tail->key == key)
			{
				tail = tail->prev;
				tail->next = NULL;
				size--;
				break;
			}
			else
			{
				help->next->prev = help->prev;
				help->prev->next = help->next;
				size--;
				break;
			}
		}
	help = help->next;
	}
}

void DoubleList::add(int position, int key2, Task task[])
{

if (position < size)
{
	if (position == 0)
	{
		if (head)
		{
			head->prev = new Link(task,key2);
			head->prev->next = head;
			head = head->prev;
		}
		else
		{
			head = new Link(task,key2);
			tail = head;
		}
		size++;
	}
	else if (position <= size / 2)
	{
		Link *help = head;
		for (int i = 1; i < position; i++)
		{
			help = help->next;
		}
		Link *newlink = new Link(task,key2);
		newlink->next = help->next;
		newlink->prev = help;
		help->next = newlink;
		newlink->next->prev = newlink;
		size++;
	}
	else
	{
		Link *help = tail;
		for (int i = size - 1; i > position; i--)
		{
			help = help->prev;
		}
		Link *helper;
		helper = new Link(task,key2);
		helper->next = help;
		helper->prev = help->prev;
		help->prev = helper;
		helper->prev->next = helper;
		size++;
	}
}
else
{
	if (tail)
	{
		tail->next = new Link(task,key2);
		tail->next->prev = tail;
		tail = tail->next;
	}
	else
	{
		head = new Link(task,key2);
		tail = head;
	}
	size++;
}
}


void DoubleList::show()
{
	cout << endl << "-------------------------------" << endl;
	Link *element = head;
	while (element)
	{
		cout << element->result<<endl;
		cout << element->key;
		element = element->next;
	}
}

void DoubleList::test()
{}
