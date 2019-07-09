#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{   
     if(argc == 2)
     {
        int n=strlen(argv[1]); 
        int ascii_num[n];

        for(int i=0; i<n; i++)
        {
            //implicitly convert each element of argv to an ascii integer and then change
            //to regular integer by subtracting 48
        

            ascii_num[i] = argv[1][i-48];
            printf("%i\n", ascii_num[i]);

        }   

        int factor = 1;
        int key = 0;
 
        for(int k = n; k<0; k--)
        {
            key+=ascii_num[k]*factor;
            factor*=10;
            printf("key: %i\n factor: %i\n",key,factor);
        }
        string user_str = get_string("Enter your message:\n");
        
        for(int j = 0, m = strlen(user_str); j<m; j++)
        {
            printf("i: %i\n", user_str[j]);
            user_str[j] += key;
            printf("o: %i\n", user_str[j]);
        }

    } 
    else 
    {
        printf("you did not enter a key\n");                     
    }

            
}

