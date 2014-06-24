import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ayush1617
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		ARRAYSUB solver = new ARRAYSUB();
		solver.solve(1, in, out);
		out.close();
	}
}

class ARRAYSUB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n=in.nextInt();
        int arr[]=new int[n+1];
        for(int i=1;i<=n;i++){
            arr[i]=in.nextInt();
        }
        int k=in.nextInt();

        //DQ=Double Ended Queue
        LinkedList<Integer> DQ=new LinkedList<Integer>();

        for(int i=1;i<=k;i++){
            while(DQ.peekFirst()!=null && DQ.peekLast()< arr[i] ){
                DQ.pollLast();
            }
            DQ.addLast(arr[i]);
        }
        out.print(DQ.peekFirst()+" ");
        for(int i=k+1;i<=n;i++){
               while(DQ.peekFirst()!=null && DQ.peekLast()< arr[i] ){
                   DQ.pollLast();
               }
            DQ.addLast(arr[i]);
            if(DQ.peekFirst()==arr[i-k]){
                DQ.pollFirst();
            }
            out.print(DQ.peekFirst()+" ");
        }

    }
}

class InputReader
{
    BufferedReader in;
    StringTokenizer tokenizer=null;

    public InputReader(InputStream inputStream)
    {
        in=new BufferedReader(new InputStreamReader(inputStream));
    }
    public String next()
    {
        String temp;
        try{
            while (tokenizer==null||!tokenizer.hasMoreTokens())
            {

                tokenizer=new StringTokenizer(in.readLine());

            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
    public Long nextLong(){
        return Long.parseLong(next());
    }

    public Double nextDouble(){
        return Double.parseDouble(next());
    }
    public BigInteger nextBig(){
        return new BigInteger(next());
    }

}

class OutputWriter {
     public PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer= new PrintWriter(writer);
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }
}

