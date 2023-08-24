#include<iostream>

using namespace std;

int listEmpty(int last)
{
	if(last < 0)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int listFull(int last)
{
	if(last == 5-1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int countPos(int list[], int items)
{
	int i = 0;
	
	while(i <= items)
	{
		i++;
	}
	
	return i;
}

void addItems(int list[], int newItem, int pos, int *ptrLast)
{
	int index;
	
	if(listFull(*ptrLast - 1) == 1)
	{
		cout << "The List is Full!" << endl << endl;
	}
	else
	{
		for(index = *ptrLast; index >= pos; --index)
		{
			list[index+1] = list[index];
		}
		
		list[pos] = newItem;
		++(*ptrLast);
		cout << "Item Successfully Added!" << endl << endl;
	}
}

void deleteItems(int list[], int pos, int *ptrLast)
{
	int index;
	
	for(index = pos+1; index <= *ptrLast; ++index)
	{
		list[index-1] = list[index];
	}
	--(*ptrLast);
	cout << "Item Successfully Deleted!" << endl << endl;
}

void locateItem(int list[], int searchItem, int *ptrLast)
{
	int index = 0;
	
	while(index != *ptrLast + 1 && list[index] != searchItem)
	{
		++index;
	}
		
	if(index != *ptrLast + 1)
	{
		cout << "Item Requested is Item " << index << "."  << endl << endl;
	}
	else
	{
		cout << "Item Does Not Exist." << endl << endl;
	}
}

void printItems(int list[], int *ptrLast)
{
	int index;
	
	if(listEmpty(*ptrLast - 1) == 1)
	{
		cout << "The List is Empty!" << endl;
	}
	else
	{
		for(index = 0; index < *ptrLast; ++index)
		{
			cout << "The value of item " << index + 1 << " = " << list[index + 1] << "." << endl;
		}
	}
}

int main()
{
	int items = 0;
	int list[items];
	int choice;
	int newItem;
	int searchItem;
	int pos;
	int *ptrLast = &items;
	
	while(choice != 5)
	{	
		cout << "LIST (ARRAY) PROGRAM" << endl;
		cout << "--------------------" << endl;
		cout << "There are currently " << items << " item/s in the list." << endl;
		cout << "Options: " << endl;
		cout << " 1. Add Item To The List" << endl;
		cout << " 2. Delete Item From The List" << endl;
		cout << " 3. Locate Item In The List" << endl;
		cout << " 4. Print Items In The List" << endl;
		cout << " 5. Exit Program" << endl;
		cout << "Enter the number of your choice: ";
		cin >> choice;
		cout << endl;
		
		if(choice == 1)
		{
			cout << "ADD ITEM TO THE LIST" << endl;
			int numberPos = countPos(list, items);
			cout << "There is " << numberPos << " number of position/s available." << endl;
			cout << "Enter the position of where to put the new item: ";
			cin >> pos;
			
			if(pos <= numberPos && pos != 0)
			{
				cout << "Enter the item to be added: ";
				cin >> newItem;
				addItems(list, newItem, pos, ptrLast);
			}
			else
			{
				cout << "The position entered is out of range!" << endl << endl;
			}
		}
		
		else if(choice == 2)
		{
			cout << "DELETE ITEM FROM THE LIST" << endl;
			int numberOfItems = countPos(list, items) - 1;
			cout << "There is " << numberOfItems << " number of item/s available." << endl;
			
			if(numberOfItems == 0)
			{
				cout << "The List is Empty!" << endl << endl;
			}
			else
			{
				cout << "Enter the position of the item to be deleted: ";
				cin >> pos;
			
				if(pos <= numberOfItems)
				{
					deleteItems(list, pos, ptrLast);
				}
				else
				{
					cout << "The position entered is out of range!" << endl << endl;
				}
			}
		}
		
		else if(choice == 3)
		{
			cout << "LOCATE ITEM IN THE LIST" << endl;
			int numberOfItems = countPos(list, items) - 1;
			
			if(numberOfItems == 0)
			{
				cout << "The List is Empty!" << endl << endl;
			}
			else
			{
				cout << "Enter the value to be searched: ";
				cin >> searchItem;
			
				locateItem(list, searchItem, ptrLast);
			}
		}
		
		else if(choice == 4)
		{
			cout << "PRINT THE ITEMS IN THE LIST" << endl;
			printItems(list, ptrLast);
			cout << endl;

		}
		
		else if(choice == 5)
		{
			cout << "Program Exiting..." << endl;
		}
		
		else
		{
			cout << "INPUT ERROR!" << endl << endl;
		}
	}
}
