import java.io.*;
import java.util.*;
 
public class Main {
 
 
	public static void main(String[] args) throws IOException {
 
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		long a = sc.nextLong();
		long b = sc.nextLong();
		if(b - a >= 10)out.print(0);
		else {
			int ans = 1;
			for(long i=a + 1; i<=b; i++) {
				ans = ((int)(i%10) * ans)%10;
			}
			out.print(ans);
		}
		out.close();
	}
 
	static class Scanner
	{
		StringTokenizer st;
		BufferedReader br;
 
		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}
 
		public Scanner(String s) throws FileNotFoundException {	br = new BufferedReader(new FileReader(s));}
 
		public String next() throws IOException
		{
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
 
		public int nextInt() throws IOException {return Integer.parseInt(next());}
 
		public long nextLong() throws IOException {return Long.parseLong(next());}
 
		public String nextLine() throws IOException {return br.readLine();}
 
		public double nextDouble() throws IOException { return Double.parseDouble(next()); }
 
		public boolean ready() throws IOException {return br.ready();}

	}
}