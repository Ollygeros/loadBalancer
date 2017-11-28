import java.io.*;
import java.net.*;

public class server1{
		public static void main(String []args)throws IOException{
		ServerSocket socket1=new ServerSocket(2345);
		while(true){
			Socket socketConnect=socket1.accept();
			BufferedReader outputfromLB=new BufferedReader(new InputStreamReader(socketConnect.getInputStream()));
			String sentence=outputfromLB.readLine();
			System.out.println("Data received from Load Balancer: "+sentence);
		}
	}
}