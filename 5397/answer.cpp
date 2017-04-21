#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void)
{
	int i;
	string input;
	list<char> clist;
	list<char>::iterator index;

	cin >> i;
	while(i--)
	{
		cin >> input;
		index = clist.begin();
		for(char c: input)
		{
			if(clist.empty()) index = clist.begin();
			switch(c)
			{
				case '<':
					if(index != clist.begin()) index--;
					break;
				case '>':
					if(index != clist.end()) index++;
					break;
				case '-':
					if(!clist.empty())
					{
						if(index == clist.end()) { clist.erase(--index);}
						else index = clist.erase(index--);
					}
					break;
				default:
					clist.insert(index, c);
					break;
			}
		}
		for(char c: clist) cout << c;
		cout << '\n';
		clist.clear();
	}
}

