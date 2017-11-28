
import java.io.*;
import java.net.*;

public class client{
		public static void main(String []args)throws IOException{
		Socket Client=new Socket("192.168.189.128",1234);
		DataOutputStream Output=new DataOutputStream(Client.getOutputStream());
		System.out.println("Choice(Student/Lecturer): ");
		BufferedReader Input=new BufferedReader(new InputStreamReader(System.in));
		String sentence=Input.readLine();
		Output.writeBytes(sentence);
		Client.close();
		}
}