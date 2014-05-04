//	Sender Bit stuff

#include<stdio.h>
#include<sys/fcntl.h>
#include<string.h>

int main()
{
        int cnt=0,val,i,j=0;
        char bits[9],stufd_bit[10];

        val = open("Bitpipe",O_WRONLY);
        printf("\n Enter 8 bits String (0 Or 1) : ");
        scanf("%s",bits);

        for(i=0;i<strlen(bits);i++)
        {
                if(bits[i] == '1')
                        cnt++;
                else
                        cnt=0;
                stufd_bit[j++] = bits[i];
                if(cnt == 5)
                {
                        stufd_bit[j++] = '0';
                }
        }
        stufd_bit[j]='\0';
        printf("\n Original String = %s \n After Stuffing = %s \n\n",bits,stufd_bit);
        write(val,&stufd_bit,sizeof(stufd_bit));
        return 0;
}
