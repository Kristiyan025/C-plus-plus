#include<bits/stdc++.h>
#include <fstream>
using namespace std;

using num = short;

struct circle
{
    num x, y, r;
};

struct ring
{
    circle inner, outer;
};

num sq(num a)
{
    return a * a;
}

//Checks whether c2 is inside c1 completely
bool isCompletelyInW(const circle& c1, const circle& c2)
{
    return sq(c1.x - c2.x) + sq(c1.y - c2.y) <= sq(c1.r - c2.r);
}

bool isCompletelyInWo(const circle& c1, const circle& c2)
{
    return sq(c1.x - c2.x) + sq(c1.y - c2.y) < sq(c1.r - c2.r);
}

//Checks whether c2 is outside c1 completely
bool isCompletelyOutW(const circle& c1, const circle& c2)
{
    return sq(c1.x - c2.x) + sq(c1.y - c2.y) >= sq(c1.r + c2.r);
}

bool isCompletelyOutWo(const circle& c1, const circle& c2)
{
    return sq(c1.x - c2.x) + sq(c1.y - c2.y) > sq(c1.r + c2.r);
}

bool isCompletelyIn(const ring& r1, const circle& c2)
{
    return isCompletelyOutW(r1.inner, c2) && isCompletelyInW(r1.outer, c2);
}

bool isCompletelyOut(const ring& r1, const circle& c2)
{
    return isCompletelyInWo(r1.inner, c2) || isCompletelyOutWo(r1.outer, c2);
}

ring r;
vector<circle> circles;

string A(ofstream& fs, bool isTesting = false)
{
    if(isTesting) return __func__;
    const string
        msgIn = "Affected",
        msgPrt = "Partially",
        msgOut = "Not affected";
    int
        cIn = 0,
        cPrt = 0,
        cOut = 0;
    for(int i = 0; i < circles.size(); i++)
    {
        if(isCompletelyIn(r, circles[i]))
        {
            cIn++;
            fs <<msgIn <<endl;
        }
        else if(isCompletelyOut(r, circles[i]))
        {
            cOut++;
            fs <<msgOut <<endl;
        }
        else
        {
            cPrt++;
            fs <<msgPrt <<endl;
        }
    }

    fs <<cIn <<" " <<cPrt <<" " <<cOut <<endl;
    return __func__;
}

string B(ofstream& fs, bool isTesting = false)
{
    if(isTesting) return __func__;
    circle c1 { 0, 0, -1 };
    for(const circle& c : circles)
    {
        if(c.r > c1.r) c1 = c;
    }

    fs <<c1.x <<" " <<c1.y <<" " <<c1.r <<endl;
    return __func__;
}

string C(ofstream& fs, bool isTesting = false)
{
    if(isTesting) return __func__;
    vector<int> cIn;
    for(int i = 0; i < circles.size(); i++)
    {
        if(isCompletelyIn(r, circles[i]))
        {
            cIn.emplace_back(i);
            circles.erase(circles.begin() + i--);
        }
    }

    fs <<"Erased Stars that are Completely In:\n";
    for(int i = 0; i < cIn.size(); i++)
    {
        fs <<circles[cIn[i]].x <<" " <<circles[cIn[i]].y <<" " <<circles[cIn[i]].r <<endl;
    }
    return __func__;
}

string D(ofstream& fs, bool isTesting = false)
{
    if(isTesting) return __func__;
    sort(circles.begin(), circles.end(), [](const circle& c1,const circle& c2)
         {
            return sq(c1.x) + sq(c1.y) < sq(c2.x) + sq(c2.y);
         });
    for(int i = 0; i < circles.size(); i++)
    {
        fs <<circles[i].x <<" " <<circles[i].y <<" " <<circles[i].r <<endl;
    }
    return __func__;
}

string fileName(string location, bool isInput, int index, string task = "")
{
    stringstream ss;
    ss <<location <<"point" <<index <<(task == "" ? "" : "-task" + task) <<(isInput ? ".in" : ".out");
    return ss.str();
}

void Check(string (*task)(ofstream&, bool))
{
    bool passed = true;
    ifstream reader;
    ofstream writer;
    string taskName = task(writer, true);
    cout <<"Testing Task #" <<taskName <<"!" <<endl;
    const int tests = 6;
    const string
        ExpectedLocation = ".\\Circle_test\\",
        MyLocation = ".\\My_Answers\\";
    stringstream myOutput, expectedOutput;
    string name, given, expected;
    for(int i = 1; i <= tests; i++)
    {
        /*  Read Input  */
        reader.open(fileName(ExpectedLocation, true, i).c_str());

        assert (!reader.fail());
        circles.clear();
        reader >>r.inner.x >>r.inner.y >>r.inner.r >>r.outer.r;
        r.outer.x = r.inner.x;
        r.outer.y = r.inner.y;
        num x, y, rad;
        circle inp;
        reader >>x >>y >>rad;
        while(!reader.eof())
        {
            inp = { x, y, rad };
            circles.emplace_back(inp);
            reader >>x >>y >>rad;
        }

        reader.close();

        /*  Read Expected Output  */
        reader.open(fileName(ExpectedLocation, false, i).c_str());

        expectedOutput.str(std::string());
        expectedOutput <<reader.rdbuf();
        expected = expectedOutput.str();

        reader.close();

        /*  Write My Output  */
        writer.open(fileName(MyLocation, false, i, taskName).c_str());

        task(writer, false);

        writer.close();

        /*  Read My Output  */
        reader.open(fileName(MyLocation, false, i, taskName).c_str());

        myOutput.str(std::string());
        myOutput <<reader.rdbuf();
        given = myOutput.str();

        reader.close();

        /*  Check Results  */
        passed &= given == expected;
        if(given == expected)
        {
            cout <<"Task #" <<taskName <<": Test #" <<i <<" passed!" <<endl <<endl;
        }
        else
        {
            cout <<"Task #" <<taskName <<": Test #" <<i <<" did not pass!" <<endl <<endl;
            cout <<"My Output:" <<endl;
            cout <<given <<endl;
            cout <<"Expected Output:" <<endl;
            cout <<expected <<endl;
        }
    }

    if(passed)
        cout <<"Overall, the Task #" <<taskName <<" passed!" <<endl;
    else
        cout <<"Overall, the Task #" <<taskName <<" did not pass!" <<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    Check(&A);
}
