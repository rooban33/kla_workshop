#include<iostream>
#include <vector>
#include <fstream>
#include<string>
#include <cmath>
#include <set>


using namespace std;


int dist(int x1,int y1,int x2 , int y2)
{
    return (sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
}

void move_right(int d,int r,pair<int,int> c,pair<int,int> start,pair<int,int> id,vector<pair<int,int>> &ans,vector<pair<int,int>> &ind)
{
    int check=0;
    int x=start.first,y=start.second,yi=id.second;
    while(check<=(r+d))
    {
        
        ans.push_back({x,y});
        ind.push_back({id.first,yi++});
        check=dist(c.first,c.second,x,y);
        x+=d;
    }
}

void move_left(int d,int r,pair<int,int> c,pair<int,int> start,pair<int,int> id,vector<pair<int,int>> &ans,vector<pair<int,int>> &ind)
{
    int check=0;
    int x=start.first,y=start.second,yi=id.second;
    while(check<=(r+d))
    {
        x-=d;
        ans.push_back({x,y});
        ind.push_back({id.first,--yi});
        check=dist(c.first,c.second,x,y);
    }
}

int main()
{
    fstream file;
    int sum,l=0;
    vector<int> data;

    file.open("Input/Testcase1.txt",ios::in);
    if(file)
    {
        string s;
        sum=0;

        while(!file.eof())
        {
            getline(file,s);
            l++;
            for(auto i:s)
            {
                if(i>='0' && i<='9')
                {
                    sum=sum*10+(i-'0');
                }
                if(i==',' || i=='x')
                {
                    data.push_back(sum);
                    sum=0;
                }
            }
            data.push_back(sum);
            cout<<"x="<<sum<<endl;
            sum=0;
            if(l==4)
            {
                break;
            }
        }
        file.close();
    }
    else
        cout<<"File not found!";


        int wd=data[0];
        pair<int,int> ds;
        ds.first=data[1];ds.second=data[2];
        pair<int,int> shv;
        shv.first=data[3];shv.second=data[4];
        int dist=data[5];

        vector<pair<int,int>> ans;
        vector<pair<int,int>> ind;

        int limit_up=(wd/2)*sin(90*0.0174533),r=wd/2;

        int y=shv.first,i=0,x=shv.second;
         cout<<"moving up\n";
        int uy=y,ux=x;
        while(uy<=(limit_up+r))
        {
            move_right(ds.first,wd/2,{0,0},{ux,uy},{0+i,0},ans,ind);
            move_left(ds.first,wd/2,{0,0},{ux,uy},{0-i-1,0},ans,ind);
            uy+=ds.first;
            i++;
        }

    //move down
    i=0;
    cout<<"moving down\n";
    int dy=y,dx=x;
    while(dy>=(limit_up-wd-r))
        {
        	move_right(ds.first,wd/2,{0,0},{dx,dy},{0+i,0},ans,ind);
            move_left(ds.first,wd/2,{0,0},{dx,dy},{0-i-1,0},ans,ind);
            dy-=ds.first;
            i--;
        }

        cout<<"over\n";
       

        fstream wfile;
        wfile.open("output.txt",ios::app);
        for(int i=0;i<ans.size();i++)
        {
            wfile<<"("<<ind[i].first<<","<<ind[i].second<<")"<<" :"<<"("<<ans[i].first<<","<<ans[i].second<<")\n";
        }




}
