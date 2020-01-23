//package lightoj;
 
import java.util.*;
 
public class Main {
     public static void main(String [] args)
     {
         Scanner input= new Scanner (System.in);
         
         int t;
         t=input.nextInt();
         for(int ii=1;ii<=t;ii++)
         {
             
         long n;
         
         n=input.nextLong();
         
           System.out.print("Case "+ii+": ");
           
           long re=n+n/9-1;
           
           if(n%9==0)
           {
               
               System.out.println(re+" "+ ++re);
           }
           else
               System.out.println(re+1);
         
         }
         
         
         
     }
}
