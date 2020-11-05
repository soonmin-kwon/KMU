import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Simple_FTP_Server {
	public static void main(String[] args) {
		
		Socket socket = null;
		ServerSocket server = null;
		FileInputStream send = null;
		DataOutputStream out =null;
		DataInputStream in = null;
		String sendFile;		
	
		try {				// exception handling
			//서버 소켓과 클라이언트 소켓을 이용해 서버와 클라이언트간 통신이 가능하게 만든다.
			//이때 서버의 포트넘버는 9707이며, ip는 localhost(127.0.0.1)이다.
			server = new ServerSocket(9707);			//서버 열기
			System.out.println("연결중...");
			
			socket = server.accept();					//클라이언트와 매칭 대기
			System.out.println("연결 성공!");				//매칭 완료
			
			// 이 java 파일과 같은 디렉토리에 있는 파일을 클라이언트에게 전송해주는 코드이다.
			// 파일명을 입력받고, 그 파일을 열어서 파일의 데이터를 buffer의 크기, 4KB단위로 보내는 코드이다.
			 while(true) {						
				out = new DataOutputStream(socket.getOutputStream());			//서버에 데이터 보내기
				in = new DataInputStream(socket.getInputStream());				//클라이언트로 부터 데이터 받아오기
				System.out.println("전송할 파일명을 입력해주세요. ex)*.txt ");					
				sendFile = new Scanner(System.in).next();						//파일명 입력 받기
				if(sendFile.equalsIgnoreCase("quit")) {
					out.writeUTF(sendFile);
					break;
				}
				send = new FileInputStream(new File(sendFile));					//입력 받은 파일명을 토대로 파일 읽어오기
				 
				byte[] buffer = new byte[4096];									//2KB 단위로 파일 data를 받을 버퍼
				 
				int data=0;														//한번에 보내는 데이터의 양
				int size=0;														//전송하는 파일의 크기 (*4KB 하면 파일의 크기)
				out.writeUTF(sendFile);											//파일명을 클라이언트한테 보내주기
				//4KB단위로 파일의 데이터를 읽어오기 때문에 size는 파일의 원래크기/4KB이다.
				while((send.read(buffer) != -1)) {								
					size++;
				}
				//size를 client에 보내준다.
				out.writeInt(size);				
				out.flush();
				//파일을 한번 읽었기 때문에 닫고 다시열어준다.
				send.close();													
				send = new FileInputStream(new File(sendFile));
				
				//파일을 buffer의 크기만큼씩 소켓에 보내준다.
				//파일을 실제로 전송하는 단계
				while((data = send.read(buffer)) != -1) {					 		
					socket.getOutputStream().write(buffer,0,data);		//socket(client)에 출력
				
				}
				System.out.println("전송성공!");
				send.close();													//파일 닫기
				}
		}catch(IOException e){
			System.out.println(e.getMessage());
		}finally {
			try {
				out.close();
				socket.close();			
				server.close();
			}catch (IOException e) {
				System.out.println("클라이언트와 오류가 발생");
			}
		}
	}

}
			
