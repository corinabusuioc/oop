#include <iostream>
using namespace std;
int cmp(char c1[20], char c2[20])
{
    int l1=0, l2=0, i;
    for(i=0;c1[i]!='\0';i++)
        l1++;
    for(i=0;c2[i]!='\0';i++)
        l2++; 
    if(l1<l2)
        return 1;
    if(l1>l2)
        return 0;
    for(i=0;i<l1;i++)
        if(c1[i]>c2[i])
            return 0;
    return 1;
}
int main()
{
    char s[201], m[20][20];
    int i=0, ok=1, in=0, sf, j=0;
    scanf("%[^\n]s",s);
    while(s[i]!='\0')
    {
        if(s[i]==' ')
            if(ok==1)
            {
                ok=0;
                sf=i-1;
                i++;
                for(int k=in;k<=sf;k++)
                    m[j][k-in]=s[k];
                j++;
                if(s[i]!=' ' && s[i]!='\0')
                {
                    ok=1;
                    in=i;
                }
            }    
            else
            {
                i++;
                if(s[i]!=' ' && s[i]!='\0')
                {
                    ok=1;
                    in=i;
                }
            }
        else
            i++;
    }
    int k, l;
    for(k=in;k<i;k++)
        m[j][k-in]=s[k];
    for(k=0;k<j;k++)
        for(l=k+1;l<=j;l++)
            if(cmp(m[k],m[l])==1)
                swap(m[k],m[l]);
    for(k=0;k<=j;k++)
        printf("%s\n", m[k]);
} 