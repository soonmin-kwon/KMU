import java.io.*;
import java.net.*;
import java.util.Scanner;

public class LocalDNS_Client {
	public static void main(String[] args) {
		Socket client = null;
		BufferedReader in = null;
		BufferedWriter out = null;
		
		try {
			//������ ����, localhost�� �̿��� �ڽ��� ip�� ���� ������ �ڽ��̱� ������
			client = new Socket("localhost",9707);					
			System.out.println("���� ����");		
			
			//��������� ���� ������ �� ���, �� ����
			in = new BufferedReader(new InputStreamReader(client.getInputStream()));
			out = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
			
			//ip�� ������ �ּҸ� ��Ģ�� �°� �Է��ϸ� �����ΰ� ip�� ��ȯ���ִ� �ڵ�
			while(true) {
				System.out.println("IP �ּҳ� ������ �̸��� �����ּ���");
				//��ĳ�ʸ� �̿��� ip�� �������� �Է¹޴´�.
				String input = new Scanner(System.in).nextLine();			//�Է¹ޱ�
				//�Է¹��� �ּҸ� �������� �����ش�.
				if(input.equalsIgnoreCase("quit")) {
					out.write(input);
					out.flush();
					break;
				}
				out.write(input+"\n");										
				out.flush();
				//���´� �ּҰ� N���� ���������� IP�ּҸ� ��ȯ�ް� R�� ���������� ������ �ּҸ� ��ȯ�޴´�.
				String message = in.readLine();
				if(input.charAt(0) == 'N') {								//normal�� ��û���� ��� IP�� return�ϱ� ������ ip : 
					System.out.println("IP : "+ message);
				}else if(input.charAt(0) == 'R') {							//reverse�� ��û���� ��� �������� return�ϱ� ������ ������ :
					System.out.println("������  : "+ message);
				}
				
			}
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}finally {
			try {
				if(client != null) client.close();
			}catch(IOException e){
				System.out.println("������ �߻��߽��ϴ�.");
			}
		}
	}
}
