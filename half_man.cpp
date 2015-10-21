#include<iostream>

using namespace std;


bool Tyrion(string s)
{
    bool boolean1 = false;
    string stringbuilder = "";
    int i = 0;
    while (i < s.size()) 
    {
        char c1 = s[i];
        char c;
        if (c1 >= 'a' && c1 <= 'm')
        {
            c = (char)(c1 + 13);
        } else
        if (c1 >= 'A' && c1 <= 'M')
        {
            c = (char)(c1 + 13);
        } else
        if (c1 >= 'n' && c1 <= 'z')
        {
            c = (char)(c1 - 13);
        } else
        {
            c = c1;
            if (c1 >= 'N')
            {
                c = c1;
                if (c1 <= 'Z')
                {
                    c = (char)(c1 - 13);
                }
            }
        }
        stringbuilder += c;
        i++;
    }
    cout<<"value: "<<s<<endl;
    cout<<"value: "<<stringbuilder<<endl;
    if ("1_pbhcba" == stringbuilder)
    {
        boolean1 = true;
    }
    return boolean1;
}

int main(){
	cout<<Tyrion("1_pbhcba")<<endl;
	string s = "1_pbhcba";
	for (int i=0; i<s.size(); i++){
		char c1 = s[i];
		char c;
		if (c1 >= 'n' && c1 <= 'z')
            {
                c = (char)(c1 - 13);
            } else
            if (c1 >= 'N' && c1 <= 'Z')
            {
                c = (char)(c1 - 13);
            } else
            if (c1 >= 'a' && c1 <= 'm')
            {
                c = (char)(c1 + 13);
            } else
            {
                c = c1;
                if (c1 <= 'M')
                {
                    c = c1;
                    if (c1 >= 'A')
                    {
                        c = (char)(c1 + 13);
                    }
                }
            }
            cout<<c;
	}
	
	return 0;
}

