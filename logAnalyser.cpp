#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Page {
public:
    int id;
    string path;
    int counter;
    Page(int id, string path)
    {
        this->id=id;
        this->path=path;
    };
    friend bool operator<(const Page & a, const Page & b);
};

bool operator<(const Page & a, const Page & b)
{
        if(a.counter<b.counter)
            return false;
        if(a.counter>b.counter)
            return true;
        else
            return (a.path<b.path);
}
vector<Page> pages;

class User {
public:
    int id;
    vector<string> visits;
    User(int id)
    {
        this->id=id;
    };
    void add_visit(int page_id)
    {
        vector<Page>::iterator itr;
        for(itr=pages.begin(); itr!=pages.end(); itr++)
        {
            if((*itr).id == page_id)
            {
                (*itr).counter++;
                visits.push_back((*itr).path);
            }
        }
    };
    int size() const
    {
        return visits.size();
    };
    void print_visits()
    {
        sort(visits.begin(),visits.end());
        for(int i=0; i<visits.size(); i++)
        {
            cout<<"- "<<visits[i]<<endl;
        }
    };
    friend bool operator<(const User & a, const User & b);
};

bool operator<(const User & a, const User & b)
{
    if(a.size()<b.size())
        return false;
    if(a.size()>b.size())
        return true;
    else
        return (a.id<b.id);
}

vector<User> users;

int main()
{
    string type;
    User u = User(0);
    while (cin >> type) {
        if (type == "PAGE") {
            // read page ID, page path, create and add page to vector
            int id;
            string path;
            cin >> id >> path;
            Page p = Page(id, path);
            p.counter = 0;
            pages.push_back(p);
        }
        else if (type == "USER") {
            // read user ID, create and add user to vector
            if(u.id!=0)
                users.push_back(u);
            int i;
            cin>>i;
            u = User(i);
        }
        else if (type == "VISIT") {
            // read page ID, search for page with that page ID, add its counter, add visit to the last user
            int id;
            cin>>id;
            u.add_visit(id);
            }
        
    }
    users.push_back(u);
    
    sort(pages.begin(),pages.end());
    sort(users.begin(),users.end());
    cout<<"*** 5 most popular pages ***"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<pages[i].counter<<":"<<pages[i].path<<endl;
    }
    cout<<"*** 5 most active users ***" << endl;
    vector<User>::iterator itr1;
    vector<User>::iterator itr2=users.begin()+5;
    sort(users.begin(),users.end());
    for(itr1=users.begin(); itr1<itr2; itr1++)
    {
        cout<<(*itr1).size()<<":"<<(*itr1).id<<endl;
        (*itr1).print_visits();
    }
}
