import java.util.*;
import java.io.*;
class SumOfDiagonalOf2dArray
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            int[] a[],b;
            a= new int[n][n];
            b= new int[n];
            int sum=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int p=sc.nextInt();
                    a[i][j]=p;
                }
            }
            int Max=0;
            for(int i=0;i<n;i++)
            {
                int p=sc.nextInt();
                b[i]=p;
            }
            Complete obj = new Complete();
            ArrayList<Integer> ans;
            ans = obj.array(a, b, n);
            for(int i: ans)
                System.out.print(i + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends



class Complete
{
    public static ArrayList<Integer> array(int a[][], int b[], int n)
    {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(0);
        arr.add(0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j){
                    // arr[0] = arr[0] + a[i][i];
                    arr.set(0, (arr.get(0) + a[i][i]));
                }
            }
        }
        
        arr.set(1,Integer.MIN_VALUE);
        for(int i=0; i<n; i++){
            if(b[i] > arr.get(1)){
                //arr[1] = b[i];
                arr.set(1 , b[i]);
            }
        }
        
        return arr;
        
    }
}
