import java.io.*;
import java.net.*;

public class LocalDNS_Server {
	public static void main(String[]args) {
		
		Socket client = null;
		ServerSocket server = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		String[][] table = new String[100][2];		//�����ΰ� ip�� �����س��� �迭
		String address;
		InetAddress ip = null;
		String check;
		int idx = 0;
		
		
		try {				//exception handling
			//���� ������ �̿��� ������ ���� ��Ʈ�ѹ��� 9707�̸� ip�� localhost(127.0.0.1)�̴�.
			server = new ServerSocket(9707);					//���� ����
			System.out.println("������..");						
			client = server.accept();							//Ŭ���̾�Ʈ ���� ���
			System.out.println("���� ����!");
			
			//������Ű� ������ �Է� ���, ���� ����
			in = new BufferedReader(new InputStreamReader(client.getInputStream()));			//������ ������ ����
			out = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));			//�������� ������ ����
			
			//Ŭ���̾�Ʈ�κ��� �ּҸ� �޾Ƽ� ��ȯ���ִ� �ڵ��̴�.
			while(true) {
				//Ŭ���̾�Ʈ�κ��� �Է°� �о����
				address = in.readLine();
				if(address.equalsIgnoreCase("quit")) {
					System.out.println("Ŭ���̾�Ʈ���� ������ �������ϴ�.");
					break;
				}
				//Ŭ���̾�Ʈ�κ��� �ּҸ� �Է¹ް� �� �ּ��� ù ���ڿ� ���� �䱸�� �ٲ�� ������ ù ���ڿ����� ���ǹ��� �����Ѵ�.
				//ù��° ���ڿ��� N�̸� normal
				//�������� �̿��� ip�ּҸ� �ް� �����ΰ� ip�� table�� �����Ѵ�.
				//�׸��� �׷��� ��ȯ�� ip�ּҸ� Ŭ���̾�Ʈ���� �����ش�.
				if( address.charAt(0) == 'N' ) {										
					//substring(4)�� �ؼ� N : �� ������ ������ ���ڿ��� �����Ѵ�.
					ip = InetAddress.getByName(address.substring(4));							//������ �̸����� ip�ּ� �޾ƿ���
					String ipAddress = ip.getHostAddress();										// ip�ּҸ� string���� ��ȯ
					table[idx][0] = address.substring(4);										//���̺� �����ΰ� ip�ּҸ� ���� ����
					table[idx][1] = ipAddress;
					out.write(ipAddress+"\n");													//ip�ּҸ� Ŭ���̾�Ʈ���� ����
					out.flush();
					idx++;																		//���� ���̺��� ���� idx ����						
							
					//R�� ������ reverse
					//ip�ּҸ� �Է¹޾� ������ �ּҷ� ��ȯ���ִ� �ڵ��̴�. 
					//ip�ּҸ� �Է¹޾����� �� ip�� table�� �ִٸ� ��������, ������ Not Found�� ����Ѵ�.
				}else if(address.charAt(0) == 'R') {											
					int counter=0;																//��ġ�ϴ� �����͸� ���� ī����					
					for(int i=0; i<100; i++) {													//table�� 1���� ��ŭ loop�� ���Ƽ� table�� �´� ip�� ������ �� ����� �������ְ� break;
						//substring(4)�� �ؼ� N : �� ������ ������ ���ڿ��� �����Ѵ�.
						if(table[i][1] !=null) {
							if(table[i][1].equals(address.substring(4)) ) {							//table�� ��ġ�ϴ� ip�� �ִ��� ã�´�.							
								out.write(table[i][0]+"\n");										//������ �� �������� ����Ѵ�.
								counter++;															//ã���� ī���͸� �÷��� not found�� �ɸ��� �ʰ��Ѵ�.
								out.flush();
								break;
							}
						}
					}
					//counter�� ������ not found
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
				System.out.println("������ �߻��߽��ϴ�!");
			}
		}
	}
}
