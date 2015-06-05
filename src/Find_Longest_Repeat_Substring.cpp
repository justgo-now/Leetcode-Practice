//jobdu-1555-ac
#include <iostream>
#include <string>
#include <set>
using namespace std;
string str;
set<string> m_set;
//集合中不允许重复元素，故插入两次一样的数与插入一次效果相同
void f_init()
{
  m_set.clear();
}
int main( )
{
  while (cin >> str)
  {
    f_init();

    for (int i = 0; i < str.size(); i++)
      for (int j = 1; j <= str.size() / 2 && i + j <= str.size(); j++)
      {
        string tmp(str.begin() + i, str.begin() + i + j);
        string tmp_2(str.begin() + i + j, str.end());

        if (tmp_2.find(tmp) != string::npos)
        {
          m_set.insert(tmp);
        }
        else
        {
          break;    //注意这里的剪枝，若给定字符串abaaaaaa
        }

        //i=0，j=2时 ab 不为aaaaaa的字串，故不必再令j=3
      }//for

    cout << m_set.size() << endl;
    str.clear();
  }

  return 0;
}
