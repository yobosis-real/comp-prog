#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSarray(char *pat, int M, int *lps)
{
	int len = 0;	
	int i ;
	
	lps[0] = 0 ;	
	i = 1;

	while(i <  M)	
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else	//pat[i] != pat[len]
		{
			if(len != 0)
			{
				len = lps[len - 1];
			}
			else	//if len == 0
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int *lps = (int*)malloc(M*sizeof(int));
	int j = 0;

	computeLPSarray(pat, M, lps);
	
	int i = 0;
	while(i < N)
	{
		if(pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if(j == M)
		{
			printf("Found pattern at index %d\n",i - j);
			j = lps[j-1];
		}
		else if(pat[j] != txt[i])
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
	free(lps);
}

int main()
{
	char *txt = "ABABDABACDABDABABCABAB";
	char *pat = "ABABCABAB";
	
	KMPSearch(pat, txt);
	return 0;
}

