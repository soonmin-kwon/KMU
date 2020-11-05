import java.io.*;
import java.net.*;
import java.util.Scanner;

public class LocalDNS_Client {
	public static void main(String[] args) {
		Socket client = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		
		try {
			//서버에 접속, localhost를 이용해 자신의 ip에 접속 서버가 자신이기 때문에
			client = new Socket("localhost",9707);					
			System.out.println("연결 성공");		
			
			//소켓통신을 위한 데이터 입 출력, 송 수신
			in = new BufferedReader(new InputStreamReader(client.getInputStream()));
			out = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
			
			//ip나 도메인 주소를 규칙에 맞게 입력하면 도메인과 ip를 반환해주는 코드
			while(true) {
				System.out.println("IP 주소나 도메인 이름을 적어주세요");
				//스캐너를 이용해 ip나 도메인을 입력받는다.
				String input = new Scanner(System.in).nextLine();			//입력받기
				//입력받은 주소를 서버에게 보내준다.
				if(input.equalsIgnoreCase("quit")) {
					out.write(input);
					out.flush();
					break;
				}
				out.write(input+"\n");										
				out.flush();
				//보냈던 주소가 N으로 시작했으면 IP주소를 반환받고 R로 시작했으면 도메인 주소를 반환받는다.
				String message = in.readLine();
				if(input.charAt(0) == 'N') {								//normal로 요청했을 경우 IP를 return하기 때문에 ip : 
					System.out.println("IP : "+ message);
				}else if(input.charAt(0) == 'R') {							//reverse로 요청했을 경우 도메인을 return하기 때문에 도메인 :
					System.out.println("도메인  : "+ message);
				}
				
			}
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}finally {
			try {
				if(client != null) client.close();
			}catch(IOException e){
				System.out.println("오류가 발생했습니다.");
			}
		}
	}
}
