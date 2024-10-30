#include<stdio.h>

int getLength(char *a){
    int c=0;
    while(a[c]!='\0')  c++;
    return c;
}

void reverseString(char *s){
    int len = getLength(s);
    char temp;
    for(int i=0; i<len/2; i++){
        temp = *(s+i);
        *(s+i)= *(s + (len-i-1));
        *(s+(len-i-1)) = temp;
    }
}

void copyString(char *sfrom, char *sto){
    int len = getLength(sfrom);
    for(int i=0; i<len; i++){
        //sto[i] = sfrom[i];
        *(sto+i) = *(sfrom+i);
    }
}

void concatString(char *dest, char *s){
    int slen, dlen;
    slen = getLength(s);
    dlen = getLength(dest);
    for(int i=dlen, j=0; i<dlen+slen; i++, j++){
        //dest[i] = s[j];
        *(dest+i) = *(s+j);
    }
}

int main(){
    char s[]="Helloworld, welcome to C code.";
    char c[100], d[100];
    printf("Original: %s\n", s);
    copyString(s, c);
    printf("Copied: %s\n", c);
    reverseString(s);
    printf("Reversed: %s\n", s);
    concatString(d, "Hi");
    concatString(d, " Maridaru\x21");
    printf("Concatenated: %s\n", d);
}
