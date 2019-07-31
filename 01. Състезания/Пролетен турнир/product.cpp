#include <iostream>

#include <vector>

using namespace std;





int main()

{

	vector<int> chisla;

	vector<int> maxi; //The biggest number before the current
	vector<int> i11;
	int a;

	int counter = 0;

	while(cin >>a)

	{

		chisla.push_back(a);

		maxi.push_back(-1);
		i11.push_back(-1);

		cout <<a <<" ";

		for(int j= 0; j < counter; j++)

		{

		    if(chisla[j] < chisla[counter])

		    {

		        maxi[counter] = j;

		        break;

	       }

	   }
        if(maxi[counter] != -1)
        {
            for(int i = maxi[counter]+1; i < counter; i++)

            {

               if(chisla[i] > chisla[maxi[counter]] && chisla[i] < a)

               {

                  maxi[counter] = i;

              }

           }
           i11[counter] = maxi[counter];
           maxi[counter] = chisla[counter] * chisla[maxi[counter]];
           cout <<maxi[counter];
        }


	   cout <<endl;

	   counter++;

	}

	int n = counter;

	unsigned long long product = 0;

   int i1 = -1;

	for(int i = 0; i < n; i++)

	{

		if(maxi[i] != -1)

		{

			int currProd = chisla[i] * maxi[i];

			if(currProd > product)

			{

			   product = currProd;

			   i1 = i;

		   }

		}

	}





   cout <<product <<endl;

	if(i1 != -1)

	{

	int j1,j2,j3;
	j1 = i11[i11[i1]];
	j2 = i11[i1];
	j3 = i1;
		cout <<++j1 <<" " <<++j2 <<" " <<++j3 <<endl;

	}



	return 0;

}
