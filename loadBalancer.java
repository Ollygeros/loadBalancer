import java.net.*;

public class loadbalancer{
		public static void main(String []args)throws IOException{
		ServerSocket socket1=new ServerSocket(1234);
		while(true){
			Socket connect_socket=socket1.accept();
			BufferedReader clientInput=new BufferedReader(new InputStreamReader(connect_socket.getInputStream()));
			String sentence=clientInput.readLine();

			if(clientsentence.contains("Student")){
			Socket sender=new Socket("192.168.92.128",2345);
			DataOutputStream serverOutput=new DataOutputStream(sender.getOutputStream());
			System.out.println("Data receive from client");
			serverOutput.writeBytes(sentence+"\n");
			sender.close();
			}

			else if(sentence.contains("Lecturer")){
			Socket sender2=new Socket("192.168.92.129",2346);
			DataOutputStream serverOutput2=new DataOutputStream(sender2.getOutputStream());
			System.out.println("Data receive from client");
			serverOutput2.writeBytes(sentence+"\n");
			sender2.close();
			}

			else{System.out.println(ERROR!!);}
			}
		}
}
