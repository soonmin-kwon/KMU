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
			//Ŭ���̾�Ʈ�� ���������� �����ִ� �ڵ��̴�. 
			// ���ῡ �����ϸ� ���Ἲ���̶�� ������ ����Ʈ�Ѵ�.
			socket = new Socket("localhost",9707);						//������ ���� , localhost�� �̿��� �ڽ��� ip�� ����
			System.out.println("���� ����!");					
			
			//�����͸� �а�, ��������, �����͸� �ް� ������ ���� �ڵ��̴�.
			in = new DataInputStream(socket.getInputStream());			//������ �����͸� ������ ����
			out = new DataOutputStream(socket.getOutputStream()); 		//�������� �����͸� �ޱ� ����
			
			//������ �̸��� �����κ��� �޾Ƽ� �Ȱ��� ������ ������ �� ���� ������ ���Ͽ� ������ ���� data�� 4KB������ �����ϴ� �ڵ�
			//������ byte[] buffer�� ũ�⸦ ���� �ؼ� �������� ������ size�� client���� ������ size�� ���� �Ѵ�.
			 while(true) {				 
				 receivedFile = in.readUTF();					//���� ������ �������� �ޱ�
				 if(receivedFile.equalsIgnoreCase("quit")) {
					 System.out.println("������ ������ �����Ͽ����ϴ�");
					 break;
				 }
				 System.out.println(receivedFile);				
				 size = in.readInt();							//������ ũ�⸦ �������� �ޱ�	
				 receive = new FileOutputStream (new File(receivedFile));			//�޾ƿ� ���ϸ��� ���� ���� ����
				 byte[] buffer = new byte[4096];									//server�� ���� ũ���� byte�迭�� ����ؼ� ���� size�� ���� ���� ������ ���� �� �ְ��Ѵ�.
				 int data = 0;
				 
				 
				 //������ ���� while���� ������� �ʴ� ������ while���� ����ߴ��� ��� �����͸� �� ��ٸ��� �־ for���� ���
				 //for���� ���� size�� �޾ƿ�
				 for(int i=0; i<size; i++) {										//size�� ũ�⸸ŭ loop�� ���� ���Ͽ� ä���ش�.
					 data = in.read(buffer);										//�ѹ��� ���۹���(��) �������� ��
					 receive.write(buffer,0,data);									//���Ͽ� ����
				 }				 
				 receive.close();													//������ �ݾƼ� �ٸ� ���ϵ� ���� �� �ְ��Ѵ�.
				 System.out.println(receivedFile + " ���� �Ϸ�!");
				 
			 }
		}catch(IOException e){
			System.out.println(e.getMessage());
			
		}finally {
			try {
				message.close();
				in.close();
				if(socket != null) socket.close();
			}catch (IOException e) {
				System.out.println("Ŭ���̾�Ʈ�� ������ �߻�");
			}
		}
		
	}
}
