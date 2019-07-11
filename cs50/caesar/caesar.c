#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{   
     if(argc == 2)
     {
        int n=strlen(argv[1]); 
        int num[n];
        int factor = 1;
        int key = 0;
        bool check_int = true;

        for(int l=0; l<n; l++)
        {
            if(argv[1][l]>47 && argv[1][l]>57)
            {
                check_int = false;
            }
        }

        if(check_int == true)
        {
              
             //implicitly convert each element of argv to an ascii integer and then change
             //to regular integer by subtracting 48
             for(int i=0; i<n; i++)
             {
                num[i] = argv[1][i]-48;
             }
             //manipulating num array combine numbers into a single integer
             for(int o=strlen(argv[1]), k=o-1; k>-1; k--)
             {

                //key increases by integer in num array each iteration 
                num[k]*=factor;
                key+=num[k];
            
                //each iteration represents a different order of 10
                //so factor changes the order of 10 with each iteration
                factor*=10;
             }

             string user_str = get_string("plaintext: ");
             printf("key: %i\n",key); 
             
             for(int j = 0, m = strlen(user_str); j<m; j++)
                {
                    //check if char in string is within lower-case letter range
                    if(user_str[j]>96 && user_str[j]<123)
                    {
                        printf("%c\n%i\n",user_str[j],user_str[j]);
                        int new_val = user_str[j]+key;
                        //check if new value exceeds lower-case range
                        printf("user_str:%i\nnew_val:%i\n",user_str[j],new_val);
                        //cast j as integer
                        if(new_val>122)
                        {
                            printf("new:%i\n",new_val%26);
                           //if it does, correct key so that it 'loops back' 
                           //from beginning of character range
                           
                           printf("user_char:%c user_int:%i key:%i\n",user_str[j],user_str[j],key);
                           int diff = new_val%26;
                           user_str[j]-=diff;
                           printf("final: %i %c || diff: %i\n",user_str[j]+diff, user_str[j],diff);
                        }
                    }
                   // else if()
                    //{
                        
                    //}
                     
                }

                printf("cyphertext: %s\n", user_str);            }

            else
            {
                printf("You did not enter an integer value.\n");
            }
        }

    else 
    {
        printf("you did not enter a key\n");                     
    }            
}
