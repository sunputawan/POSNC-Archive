#include <stdio.h>
#include <string.h>
int len,count=0;
int ispalindrome(char a[], int n){
    if(n==0){
        if(count==len)
            return 1;
        else
            return 0;
    }
    if(a[n-1]<=90){
        if(a[n-1]==a[len-n]||a[n-1]+32==a[len-n])
            count++;
    }
    else if(a[n-1]>=97){
        if(a[n-1]==a[len-n]||a[n-1]-32==a[len-n])
            count++;
    }
    return ispalindrome(a,n-1);
}
int main(){
    char str[100];
    scanf("%s", str);
    len=strlen(str);
    if(ispalindrome(str,len))
        printf("It is palindrome");
    else
        printf("It's not palindrome");
}
