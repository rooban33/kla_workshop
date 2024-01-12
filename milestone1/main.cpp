#include<iostream>
#include <vector>
#include <fstream>
#include<string>
#include <cmath>


using namespace std;

int main()
{
    fstream file;
    int x=0,l=0;
    vector<int> data;

    file.open("Testcase4.txt",ios::in);
    if(file)
    {
        string s;
        x=0;

        while(!file.eof())
        {
            getline(file,s);
            l++;
            for(auto i:s)
            {
                if(i>='0' && i<='9')
                {
                    x=x*10+(i-'0');
                }
            }
            data.push_back(x);
            cout<<"x="<<x<<endl;
            x=0;
            if(l==3)
            {
                break;
            }
        }
        file.close();
    }
    else
        cout<<"File not found!";


    float r=data[0]/2;
    int n=data[1];
    float angle=data[2];
    float en=n-1;
     float d=data[0]/en;


    vector<pair<float,float>> ans;

    angle=0.0174533*angle;
    float a=r*cos(angle);
    float b=r*sin(angle);
    while(n>0)
    {
          n--;
            ans.push_back({a,b});
            r-=d;
            a=r*cos(angle);
            b=r*sin(angle);
            if(b==-0)
            {
                b=0;
            }
          
    }
    fstream wfile;
    wfile.open("output.txt",ios::app);
    for(auto i:ans)
    {
        wfile<<"("<<i.first<<","<<i.second<<")\n";
    }
    wfile.close();

}