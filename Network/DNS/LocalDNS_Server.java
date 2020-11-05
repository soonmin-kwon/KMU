import java.io.*;
import java.net.*;

public class LocalDNS_Server {
	public static void main(String[]args) {
		
		Socket client = null;
		ServerSocket server = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		String[][] table = new String[100][2];		//도메인과 ip를 저장해놓을 배열
		String address;
		InetAddress ip = null;
		String check;
		int idx = 0;
		
		
		try {				//exception handling
			//서버 소켓을 이용해 서버를 열고 포트넘버는 9707이며 ip는 localhost(127.0.0.1)이다.
			server = new ServerSocket(9707);					//서버 열기
			System.out.println("연결중..");						
			client = server.accept();							//클라이언트 접속 대기
			System.out.println("연결 성공!");
			
			//소켓통신간 데이터 입력 출력, 전송 수신
			in = new BufferedReader(new InputStreamReader(client.getInputStream()));			//서버에 데이터 전송
			out = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));			//서버에서 데이터 수신
			
			//클라이언트로부터 주소를 받아서 변환해주는 코드이다.
			while(true) {
				//클라이언트로부터 입력값 읽어오기
				address = in.readLine();
				if(address.equalsIgnoreCase("quit")) {
					System.out.println("클라이언트에서 연결을 끊었습니다.");
					break;
				}
				//클라이언트로부터 주소를 입력받고 그 주소의 첫 글자에 따라 요구가 바뀌기 때문에 첫 글자에따라 조건문을 수행한다.
				//첫번째 문자열이 N이면 normal
				//도메인을 이용해 ip주소를 받고 도메인과 ip를 table에 저장한다.
				//그리고 그렇게 변환한 ip주소를 클라이언트에게 보내준다.
				if( address.charAt(0) == 'N' ) {										
					//substring(4)를 해서 N : 를 제외한 나머지 문자열만 추출한다.
					ip = InetAddress.getByName(address.substring(4));							//도메인 이름으로 ip주소 받아오기
					String ipAddress = ip.getHostAddress();										// ip주소를 string으로 전환
					table[idx][0] = address.substring(4);										//테이블에 도메인과 ip주소를 같이 저장
					table[idx][1] = ipAddress;
					out.write(ipAddress+"\n");													//ip주소를 클라이언트에게 전송
					out.flush();
					idx++;																		//다음 테이블을 위해 idx 증가						
							
					//R로 들어오면 reverse
					//ip주소를 입력받아 도메인 주소로 변환해주는 코드이다. 
					//ip주소를 입력받았을때 그 ip가 table에 있다면 도메인을, 없으면 Not Found를 출력한다.
				}else if(address.charAt(0) == 'R') {											
					int counter=0;																//일치하는 데이터를 세는 카운터					
					for(int i=0; i<100; i++) {													//table의 1차원 만큼 loop을 돌아서 table에 맞는 ip가 있으면 그 결과를 전송해주고 break;
						//substring(4)를 해서 N : 를 제외한 나머지 문자열만 추출한다.
						if(table[i][1] !=null) {
							if(table[i][1].equals(address.substring(4)) ) {							//table에 일치하는 ip가 있는지 찾는다.							
								out.write(table[i][0]+"\n");										//있으면 그 도메인을 출력한다.
								counter++;															//찾으면 카운터를 늘려서 not found에 걸리지 않게한다.
								out.flush();
								break;
							}
						}
					}
					//counter가 없으면 not found
					if(counter ==0 ) {
						out.write("Not Found"+"\n");
						out.flush();
					}
				}
			}
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}finally {
			try {
				client.close();
				server.close();
			}catch (IOException e) {
				System.out.println("문제가 발생했습니다!");
			}
		}
	}
}
