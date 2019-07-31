#include <iostream>

#include <vector>

using namespace std;





int main()

{

	vector<int> chisla;

	vector<int> maxi; //The biggest number before the current

	int a;

	int counter = 0;

	while(cin >>a)

	{

		chisla.push_back(a);

		maxi.push_back(-1);

		cout <<a <<" ";

		for(int j= 0; j < counter; j++)

		{

		    if(chisla[j] < chisla[counter])

		    {

		        maxi[counter] = j;

		        break;

	       }

	   }

		for(int i = 0; i < counter; i++)

		{

		   if(maxi[counter] != -1 && chisla[i] > chisla[maxi[counter]] && chisla[i] < a)

		   {

		      maxi[counter] = i;

	      }

	   }

	   cout <<chisla[maxi[counter]] <<endl;

	   counter++;

	}

	int n = counter;

	unsigned long long product = 0;

   int i1 = -1, i2 = -1, i3 = -1;

	for(int i = 0; i < n; i++)

	{

		if(maxi[i] != -1 && maxi[maxi[i]] != -1)

		{

			int currProd = chisla[i] * chisla[maxi[i]] * chisla[maxi[maxi[i]]];

			if(currProd > product)

			{

			   product = currProd;

			   i1 = maxi[maxi[i]];

			   i2 = maxi[i];

			   i3 = i;

		   }

		}

	}

	

	

   cout <<product <<endl;

	if(i1 != -1)

	{

		cout <<++i1 <<" " <<++i2 <<" " <<++i3 <<endl;

	}

	

	return 0;

}