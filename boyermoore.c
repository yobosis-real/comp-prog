#include<stdio.h>
#include<string.h>  

#define NO 256

int max(int a,int b)
{
    return (a>b)?a:b;
}

void badcharheu(char *str,int size,int badchar[NO])
{
    int i;
    for(i=0;i<NO;i++)
        badchar[i]=-1;
    
    for(i=0;i<size;i++)
        badchar[(int)str[i]]=1;
}

void search(char* txt,char* pat)
{
    int m=strlen(pat);
    int n=strlen(txt);

    int badchar[NO];
    badcharheu(pat,m,badchar);

    int s=0;

    while(s<=(n-m))
    {
        int j=m-1;
        while(j>=0&&pat[j]==txt[s+j])
            j--;
        if(j<0)
        {
            printf("\n pattern occurs at shift=%d",s);           
        
            s+=(s+m<n)?m-badchar[txt[s+m]]:1;
        }
        else
        {
            s+=max(1,j-badchar[txt[s+j]]);
        }
    }
}
int main()
{
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    search(txt, pat);
    return 0;
}