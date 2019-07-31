#include <iostream>
#include <cstdlib>
using namespace std;

int broi_na_cifri_pretstaven_v_nuli(int n);

int main()
{
    int n;
    long long broi = 0;
    cin >>n;

    /*
    tui kato priznaka za delene na 16 e
    ako chisloto obrazuvano ot poslednite
    4 cifri na chisloto se deli na 16 to
    i chisloto se deli na 16
    => trqbva da gledame samo poslednite 4 cifri ne cqlata permutaciq
    */
    /*
    ako vseki edin ot sledvashtite sluchai otgovarq na uslovieto
    broqt im shte bude n*(n - 1)*(n - 2)*(n - 3)
    */
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int l = 1; l <= n; l++)
            {
                for(int m = 1; m <= n; m++)
                {
                    if(i==j || i==l || i==m || j==l || j==m || l==m) continue;
                    long num = i*broi_na_cifri_pretstaven_v_nuli(j)*
                                broi_na_cifri_pretstaven_v_nuli(l)*
                                broi_na_cifri_pretstaven_v_nuli(m) +
                                j*broi_na_cifri_pretstaven_v_nuli(l)*
                                broi_na_cifri_pretstaven_v_nuli(m) +
                                l*broi_na_cifri_pretstaven_v_nuli(m) + m;
                    /* num e chislo formirano ot slepvaneto na cheterite chisla  */

                    if(num % 16 == 0)
                    {
                        broi++;
                    }
                }
            }
        }
    }

    /* sega umnogavame broq po permutaciq ot n-4 za da stane krainiq broi permutaziq ot n */
    for(int i = 1; i <= n - 4; i++)
    {
        broi=(broi*i)%(1000000007);
    }
    cout <<broi;

    return 0;
}

int broi_na_cifri_pretstaven_v_nuli(int n)
{
    /* namira broq na cifrite i vrushta  chislo sus sushtiq broi 0 */
    if(n == 1) return 10;
    int br=0;
    int p = n;
    while(p>1)
    {
        p/=10;
        br++;
        if(p==1)
        {
            br++;
            break;
        }
    }
    int chislo = 1;
    for(int i = 0; i < br; i++)
    {
        chislo *= 10;
    }
    return chislo;
}
