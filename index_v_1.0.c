#include <stdio.h>

#include <string.h>

#define MAX_USERNAME_LENGTH 8
#define MAX_PASSWORD_LENGTH 8

struct UserCredential {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main()
{
    struct UserCredential user1;
    
    int n,op;
    
    char uname[100],password[50];
    
    char username[100] = "agent007tg", pasword[100] = "12345678";
    
    printf("-------------- Password Manager --------------- \n");
    
    printf("1. Login\n2. Accounts\n3. Exit\n");
    
    printf("Enter your choice: ");
    
    scanf("%d",&n);

    if(n == 1)
    {
        printf("Enter your Credentials: \n");
        
        printf("Username: ");
        
        scanf("%s",&uname[0]);
        
        printf("Password: ");
        
        scanf("%s",&password[0]);
        
        if(uname == "agent007tg" && password == "12345678")
        {
            printf("Welcome PAVAN TEJA \nHere are your passwords \n");
            
            printf("1. Google\n2. Youtube\n3. Instagram\n");
            
            printf("Enter your choice: ");
            
            scanf("%d",&op);
            
            if(op == 1)
            {
                printf("Your Username is %s",username);
                printf("Your Password is %s",pasword);
            }
            
        }
    }
    else if(n == 2)
    {
        printf("Accounts Session: \n");
        
        printf("1. Accounts\n2. Add\n3. Delete\n4. Edit\n5. Back\n");
        
        printf("Enter your Choice: ");
        
        scanf("%d",&op);
        
        if(op == 1)
        {
            printf("Welcome, \nHere are all your accounts \n");
            
            for(int i=1;i<6;i++)
            {
                printf("%d. Account_%d\n",i,i);
            }
        }
        else if(op == 2)
        {
            printf("Hello User,\n");
            
            printf("What do we call you?\nEnter your Username: \n");
            
            
            printf("Enter your UI Password: \n");
            
            
        }
    }
    
    
    return 0;
}
