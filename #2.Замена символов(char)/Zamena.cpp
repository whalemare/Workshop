#include <iostream>
using namespace::std;

int main()
{
   char str[50];
   cin >> str;
   for (int i=0; i<=50; i++){
    if (str[i]>=48 && str[i]<=57)
        str[i]+=21;
    if (str[i]=='*') // *
        str[i]=117;
        else
            if (str[i]==43) // +
            str[i]=112;
            else
                if (str[i]==45) // -
                str[i]=109;
                else
                    if (str[i]==47) // /
                    str[i]=100;
   }


   cout << str;
    return 0;
}
