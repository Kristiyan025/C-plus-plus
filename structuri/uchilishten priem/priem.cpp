/*
курсова: Да се състави програма, която работи с меню и извършва следните операции:

-        създава файл “Kandidat.pmg”, съдържащ информация за учениците кандидатстващи в ПМГ ( входящ номер, трите имена, оценки по български език и математика от дипломата).

-        въвежда резултатите на учениците от проведения изпит по български език и литература;

-        въвежда резултатите на учениците от проведения изпит по математика;

-        сортира учениците в низходящ ред според бала им ( 3* оценката от изпита по математика + оценката от изпита по български език + оценките от дипломата по бълг. език и по математика);

-        създава 2  нови файла –единият съдържащ имената на учениците приети в ПМГ (минимален бал –30)р а другия тези, които не са приети;

-        извежда съдържанието на файл по избор
*/
#include <bits/stdc++.h>
#include<string>
using namespace std;

struct uchenik
{
    string nomer; /// vhodqsht_nomer ///
    string ime; /// trite imena ///
    double math_diploma; /// ocenka ot diplomata po matematika ///
    double bel_diploma; /// ocenka ot diplomata po bel ///
    double math_izpit; /// ocenka ot izpita po matematika ///
    double bel_izpit; /// ocenka ot izpita po bel ///
};

vector<uchenik> uchenici; /// database for all students ///

double stod (const string&  str, size_t* idx = 0);
double stod (const wstring& str, size_t* idx = 0);

/*void izvajdane_veche_zapisanite() /// Gets all students from the file Kandidat.pmg.txt ///
{
    ifstream input(".\\files\\Kandidat.pmg.txt");
    string s;
    double d;
    getline(input,s); //// for the first line "         Kandidatstvane 2019" ////
    getline(input,s); //// for the second empty line ////
    uchenik u;
    while (getline(input,s)) //// here s gets the value "Student: <ime>" ////
    {
        u.ime = s.substr(9); //// from these position begin the name ////

        getline(input,s); //// here s gets the value "  -Incoming number: <nomer>" ////
        u.nomer = s.substr(20); //// from these position begin the nomer ////

        input >>s; //// here s gets the value "  -BEL's note from the diploma:" ////
        input >>d;
        u.bel_diploma = d;

        input >>s; //// here s gets the value "  -Math's note from the diploma:" ////
        input >>d;
        u.math_diploma = d; //// from these position begin the math_diploma ////

        input >>s; //// here s gets the value "  -BEL's note from the test:" ////
        input >>d;
        u.bel_izpit = d; //// from these position begin the bel_test ////

        input >>s; //// here s gets the value "  -Math's note from the test:" ////
        input >>d;
        u.math_izpit = d; //// from these position begin the math_test ////

        getline(input,s); //// for the empty space of the end of the line ////
        getline(input,s); //// for the empty line after each student ////
    }
    input.close();
    uchenici.push_back(u);
}*/ //don't use

void vuvejdane() /// Reads a student from the console ///
{
    uchenik u;
    cout <<"Enter the student's incoming number: ";
    cin >>u.nomer;
    cout <<"Enter the student's three names: ";
    string temp;
    for (int i = 0; i < 3; i++) // tui kato imeto e ot tri chasti trqbva da chetem s cin 3 puti
    {
        cin >>temp;
        u.ime += temp + " ";
    }
    cout <<"Enter the Math's note from the diploma: ";
    cin >>u.math_diploma;
    cout <<"Enter the BEL's note from the diploma: ";
    cin >>u.bel_diploma;
    cout <<"Enter the Math's note from the test: ";
    cin >>u.math_izpit;
    cout <<"Enter the BEL's note from the test: ";
    cin >>u.bel_izpit;
    uchenici.push_back(u);
}

double bal(uchenik u) /// Calculates the bal of  student ///
{
    return 3 * u.math_izpit +
               u.bel_izpit +
               u.math_diploma +
               u.bel_diploma;
}

bool cmp(uchenik a, uchenik b) /// The way, by which the students are compared for the sort ///
{
    double bal_a = bal(a);
    double bal_b = bal(b);
    if(bal_a != bal_b) return bal_a > bal_b;
    else if(a.ime != b.ime) return a.ime < b.ime;
    return true;
}

void zapisvane(string firstLine) /// Save all students in ".\\files\\Kandidat.pmg.txt" ///
{
    ofstream output(".\\files\\Kandidat.pmg.txt");
    output <<firstLine <<endl <<endl;
    for (int i = 0; i < uchenici.size(); i++)
    {
        output <<"Student: " <<uchenici[i].ime <<endl;
        output <<"  -Incoming number: " <<uchenici[i].nomer <<endl;
        output <<"  -BEL's note from the diploma: " <<uchenici[i].bel_diploma <<endl;
        output <<"  -Math's note from the diploma: " <<uchenici[i].math_diploma <<endl;
        output <<"  -BEL's note from the test: " <<uchenici[i].bel_izpit <<endl;
        output <<"  -Math's note from the test: " <<uchenici[i].math_izpit <<endl <<endl;
    }
    output.close();
}

void zapisvane_prieti(string firstLine) /// Save all accepted students in ".\\files\\prieti.txt" ///
{
    ofstream output(".\\files\\prieti.txt");
    output <<firstLine <<endl <<endl;
    for (int i = 0; i < uchenici.size(); i++)
    {
        if(bal(uchenici[i]) >= 30.0)
        {
            output <<"Student: " <<uchenici[i].ime <<endl;
            output <<"  -Incoming number: " <<uchenici[i].nomer <<endl;
            output <<"  -BEL's note from the diploma: " <<uchenici[i].bel_diploma <<endl;
            output <<"  -Math's note from the diploma: " <<uchenici[i].math_diploma <<endl;
            output <<"  -BEL's note from the test: " <<uchenici[i].bel_izpit <<endl;
            output <<"  -Math's note from the test: " <<uchenici[i].math_izpit <<endl <<endl;
        }
    }
    output.close();
}

void zapisvane_othvurleni(string firstLine) /// Save all rejected students in ".\\files\\othvurleni.txt" ///
{
    ofstream output(".\\files\\othvurleni.txt");
    output <<firstLine <<endl <<endl;
    for (int i = 0; i < uchenici.size(); i++)
    {
        if(bal(uchenici[i]) < 30.0)
        {
            output <<"Student: " <<uchenici[i].ime <<endl;
            output <<"  -Incoming number: " <<uchenici[i].nomer <<endl;
            output <<"  -BEL's note from the diploma: " <<uchenici[i].bel_diploma <<endl;
            output <<"  -Math's note from the diploma: " <<uchenici[i].math_diploma <<endl;
            output <<"  -BEL's note from the test: " <<uchenici[i].bel_izpit <<endl;
            output <<"  -Math's note from the test: " <<uchenici[i].math_izpit <<endl <<endl;
        }
    }
    output.close();
}

void print_prieti_file() /// Prints the file on the console ///
{
    ifstream input(".\\files\\prieti.txt");
    string s;
    while(getline(input,s))
    {
        cout <<s <<endl;
    }
    input.close();
}

int main()
{
    //izvajdane_veche_zapisanite();
    cout <<"Enter the number of students you want to save: ";
    int n;
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        vuvejdane();
    }
    sort(uchenici.begin(), uchenici.end(), cmp);

    string obshtFirstLine = "                         Kandidatstvane 2019";
    zapisvane(obshtFirstLine);
    zapisvane_prieti(obshtFirstLine + " - PRIETI");
    zapisvane_othvurleni(obshtFirstLine + " - OTHVURLENI");
    print_prieti_file();
    return 0;
}
