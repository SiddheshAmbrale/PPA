/* Write a program which accept one number from user and off 7th bit of that number if it is on . Return modified number.

Input : 79

Output : 15

*/

import java.util.*;

class program161
{
    public static int OffBit(int ino)
    {
        int imask = 0x00000040;
        int result=0;

        result = ino & imask;

        if(result==imask)
        {
            return ino ^ imask;
        }
        else
        {
            return ino;
        }
    }

    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        int ino=0;
        int iret = 0;

        System.out.println("Enter the number : ");
        ino = sobj.nextInt();

        iret = OffBit(ino);

        System.out.println("Updated bit is : "+iret);

    }
}