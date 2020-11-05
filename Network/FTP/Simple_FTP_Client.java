import java.io.* ;
import java.net.*;
import java.util.Scanner;

public class Simple_FTP_Client  {
	public static void main(String[] args) {

		Socket socket = null;
		FileOutputStream receive = null;
		DataInputStream in = null;
		DataOutputStream out = null;
		String receivedFile;
		int size;
		String check;
		
		Scanner message = new Scanner(System.in);
	
		try {
			//클라이언트의 서버연결을 보여주는 코드이다. 
			// 연결에 성공하면 연결성공이라는 문구를 프린트한다.
			socket = new Socket("localhost",9707);						//서버에 연결 , localhost를 이용해 자신의 ip로 접속
			System.out.println("연결 성공!");					
			
			//데이터를 읽고, 쓰기위한, 데이터를 받고 보내기 위한 코드이다.
			in = new DataInputStream(socket.getInputStream());			//서버에 데이터를 보내기 위함
			out = new DataOutputStream(socket.getOutputStream()); 		//서버에서 데이터를 받기 위함
			
			//파일의 이름을 서버로부터 받아서 똑같은 파일을 생성한 후 새로 생성한 파일에 서버의 파일 data를 4KB단위로 저장하는 코드
			//서버와 byte[] buffer의 크기를 같게 해서 서버에서 측정된 size와 client에서 측정된 size가 같게 한다.
			 while(true) {				 
				 receivedFile = in.readUTF();					//파일 제목을 서버에서 받기
				 if(receivedFile.equalsIgnoreCase("quit")) {
					 System.out.println("서버가 연결을 종료하였습니다");
					 break;
				 }
				 System.out.println(receivedFile);				
				 size = in.readInt();							//파일의 크기를 서버에서 받기	
				 receive = new FileOutputStream (new File(receivedFile));			//받아온 파일명을 토대로 파일 생성
				 byte[] buffer = new byte[4096];									//server와 같은 크기의 byte배열을 사용해서 같은 size를 갖고 같은 파일을 받을 수 있게한다.
				 int data = 0;
				 
				 
				 //서버와 같이 while문을 사용하지 않는 이유는 while문을 사용했더니 계속 데이터를 더 기다리고 있어서 for문을 사용
				 //for문을 위해 size를 받아옴
				 for(int i=0; i<size; i++) {										//size의 크기만큼 loop을 돌아 파일에 채워준다.
					 data = in.read(buffer);										//한번에 전송받을(쓸) 데이터의 양
					 receive.write(buffer,0,data);									//파일에 쓰기
				 }				 
				 receive.close();													//파일을 닫아서 다른 파일도 받을 수 있게한다.
				 System.out.println(receivedFile + " 수신 완료!");
				 
			 }
		}catch(IOException e){
			System.out.println(e.getMessage());
			
		}finally {
			try {
				message.close();
				in.close();
				if(socket != null) socket.close();
			}catch (IOException e) {
				System.out.println("클라이언트와 오류가 발생");
			}
		}
		
	}
}
