/*
 EXAMPLE INPUT:

        N = 4 M = 4
    /|\
    3|    5   7   8
     |  5   6   7   6
    2|    3   2   5
     |  2   4   5   4
    1|    5   7   9
     |  3   2   5   2
    0|    4   6   7
     |---------------\
        0   1   2   3
 EXAMPLE OUTPUT:

        The optimal charge is: 21
        GO UP!
        GO UP!
        GO RIGHT!
        GO RIGHT!
        GO RIGHT!
        GO UP!
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int f[15][15];
/*
IN THESE GLOBAL ARRAY WILL BE SAVED THE STREET CHARGES AND
OPTIMAL CHARGE TO EVERY VERTEX
*/

void find_road(bool* road, int pos, int i, int j)
{
    /*
    A---0
        |
        B
    IF IT IS MORE OPTIMAL TO COME FROM LEFT IN THE ARRAY SHOULD GO 0
    ELSE IF IT IS MORE OPTIMAL TO COME FROM BOTTOM IN THE ARRAY SHOULD GO 1
    */
    if(i == 0 && j == 0) return;
    else if(i == 0)
    {
        road[pos] = 0;
        find_road(road, pos - 1, i, j - 2);
    }
    else if(j == 0)
    {
        road[pos] = 1;
        find_road(road, pos - 1, i - 2, j);
    }
    else if((f[i][j - 2] + f[i][j - 1]) <= (f[i - 2][j] + f[i - 1][j]))
    {
        road[pos] = 0;
        find_road(road, pos - 1, i, j - 2);
    }
    else
    {
        road[pos] = 1;
        find_road(road, pos - 1, i - 2, j);
    }
}

int main()
{
     int n,m;
     cin >>n >>m;
     /*
     WE WILL USE ONLY THESE SQUARE:
     -------------
     |          /| f[(m - 1) * 2 + 1][(n - 1) * 2 + 1]
     |        /  |
     |      /    |
     |    /      |
     |  /        |
     |/          |
     -------------
     f[0][0]
     */
     /*
     THE ARRAY LOOKS LIKE THAT:

     0---0---0---0---0
     | X | X | X | X |
     0---0---0---0---0
     | X | X | X | X |
     0---0---0---0---0
     | X | X | X | X |
     0---0---0---0---0

     0        - VERTEX
     -- AND | - STREET
     X        - CLEAR
     */

     /*  GET THE STREET CHARGE  */
     for(int j = 1; j < (n - 1) * 2; j += 2)
     {
         cin >>f[(m - 1) * 2][j];
     }
     for(int i = (m - 2) * 2; i >=0 ; i -= 2)
     {
         for(int j = 0; j <= (n - 1) * 2; j += 2)
         {
             cin >>f[i + 1][j];
         }
         for(int j = 1; j < (n - 1) * 2; j += 2)
         {
             cin >>f[i][j];
         }
     }

     /*  THE START VALUES */
     f[0][0] = 0;
     /*  OF THE FIRST ROW  */
     for(int i = 2; i <= (n - 1) * 2; i += 2)
     {
         f[0][i] = f[0][i - 1]       +       f[0][i - 2];
                  /*PREVIOUS STREET*/ /*PREVIOUS VERTEX*/
     }
     /*  AND COLUMN  */
     for(int i = 2; i <= (m - 1) * 2; i += 2)
     {
         f[i][0] = f[i - 1][0]       +       f[i - 2][0];
                  /*PREVIOUS STREET*/ /*PREVIOUS VERTEX*/
     }

     /*  INITIALIZATION OF THE OPTIMAL VALUES OF THE OTHER VERTEX UNTIL IT COMES TO THE WANTED */
     for(int i = 2; i <= (m - 1) * 2; i += 2)
     {
         for(int j = 2; j <= (n - 1) * 2; j += 2)
         {
             /*
             A---0
                 |
                 B
             THE OPTIMAL CHARGE OF 0 IS THE SMALLER FROM:
                 (VALUE OF A + THE CHARGE OF THE STREET A0) AND
                 (VALUE OF B + THE CHARGE OF THE STREET B0)
             */
             f[i][j] = min((f[i][j - 2] + f[i][j - 1]), (f[i - 2][j] + f[i - 1][j]));
         }
     }
     /*  PRINTING THE OPTIMAL CHARGE  */
     cout <<"The optimal charge is: " <<f[(m - 1) * 2][(n - 1) * 2] <<endl;

     /*  FINDING THE OPTIMAL ROAD  */
     bool road[n + m - 2];
     find_road(road, (n + m - 3), ((m - 1) * 2), ((n - 1) * 2));

     /*  PRINTING THE RIGHT DIRECTION THROUGH THE OPTIMAL ROAD  */
     for(int i = 0; i < sizeof(road); i++)
     {
         if(road[i] == 0) cout <<"GO RIGHT!" <<endl;
          else cout <<"GO UP!" <<endl;
     }

     return 0;
}


