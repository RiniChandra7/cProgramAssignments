#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, m;
	int r, c;
	int i;
	int val = 1;
	int min, max;

	printf("Enter size of the matrix\n");
	scanf("%d", &n);
	scanf("%d", &m);
	int mat[n][m];
	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++) {
			mat[r][c] = val++;	
		}
	}

	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++) {
			printf("%d\t", mat[r][c]);	
		}
		printf("\n");	
	}

	if (m <= n) {
		min = m;
		max = n;
	} else {
		min = n;
		max = m;
	}

	r = 0; 
	c = 0; 
  
    int rowUp = 0; 
  
    int mn = min; 
    for (int len = 1; len <= mn; ++len) { 
        for (int i = 0; i < len; ++i) { 
            printf("%d\t", mat[r][c]); 
  
            if (i + 1 == len) 
                break; 

            if (rowUp == 1) 
                ++r, --c; 
            else
                --r, ++c; 
        } 
  
        if (len == mn) 
            break; 
  
        if (rowUp) 
            ++r, rowUp = 0; 
        else
            ++c, rowUp = 1; 
    } 
  
    if (r == 0) { 
        if (c == m - 1) 
            ++r; 
        else
            ++c; 
        rowUp = 1; 
    } 
    else { 
        if (r == n - 1) 
            ++c; 
        else
            ++r; 
        rowUp = 0; 
    } 
  
    int high = max - 1; 
    for (int len, diag = high; diag > 0; --diag) { 
  
        if (diag > mn) 
            len = mn; 
        else
            len = diag; 
  
        for (int i = 0; i < len; ++i) { 
            printf("%d\t", mat[r][c]); 
  
            if (i + 1 == len) 
                break; 
  
            if (rowUp) 
                ++r, --c; 
            else
                ++c, --r; 
        } 
  
        if (r == 0 || c == m - 1) { 
            if (c == m - 1) 
                ++r; 
            else
                ++c; 
  
            rowUp = 1; 
        } 
  
        else if (c == 0 || r == n - 1) { 
            if (r == n - 1) 
                ++c; 
            else
                ++r; 
  
            rowUp = 0; 
        } 
    } 


	return 0;
}
