import java.util.Scanner;
 public class in
{
     class base
    {
        
        int gear;
        base(int gear)
        {
            this.gear=gear;
        }
    }
     class derived extends base
    {
        

    }
    public static Scanner sc=new Scanner(System.in);
    public static void main(String [] args)
    {
        base obj=new derived(10);
        System.out.println("HI JAVA");
    }
}