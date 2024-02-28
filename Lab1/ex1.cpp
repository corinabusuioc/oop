#include <iostream>
#include <fstream>
int conv(const char *s)
{
    int nr=0, i;
    for(i=0;s[i]!='\0';i++)
        nr=nr*10+s[i]-'0';
    return nr;
}
int main()
{
    FILE * fin;
    char sir[100];
    int s=0;
    fin = fopen("in.txt", "r");
    if(fin==NULL)
    {
        printf("Nu s-a deschis fisierul");
        return 0;
    }
    while(fgets(sir,sizeof(sir),fin))
    {
        int nr = conv(sir);
        s+=nr;
    }
    printf("%d", s);
}