import java.io.*;
import java.net.*;

public class server2{
		public static void main(String []args)throws IOException{
		ServerSocket socket2=new ServerSocket(2346);
		while(true){
			Socket socketConnect=socket2.accept();
			BufferedReader outputfromLB=new BufferedReader(new InputStreamReader(socketConnect.getInputStream()));
			String sentence=outputfromLB.readLine();
			System.out.println("Data received from Load Balancer: "+sentence);
		}
	}
}