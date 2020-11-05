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
			//���� ���ϰ� Ŭ���̾�Ʈ ������ �̿��� ������ Ŭ���̾�Ʈ�� ����� �����ϰ� �����.
			//�̶� ������ ��Ʈ�ѹ��� 9707�̸�, ip�� localhost(127.0.0.1)�̴�.
			server = new ServerSocket(9707);			//���� ����
			System.out.println("������...");
			
			socket = server.accept();					//Ŭ���̾�Ʈ�� ��Ī ���
			System.out.println("���� ����!");				//��Ī �Ϸ�
			
			// �� java ���ϰ� ���� ���丮�� �ִ� ������ Ŭ���̾�Ʈ���� �������ִ� �ڵ��̴�.
			// ���ϸ��� �Է¹ް�, �� ������ ��� ������ �����͸� buffer�� ũ��, 4KB������ ������ �ڵ��̴�.
			 while(true) {						
				out = new DataOutputStream(socket.getOutputStream());			//������ ������ ������
				in = new DataInputStream(socket.getInputStream());				//Ŭ���̾�Ʈ�� ���� ������ �޾ƿ���
				System.out.println("������ ���ϸ��� �Է����ּ���. ex)*.txt ");					
				sendFile = new Scanner(System.in).next();						//���ϸ� �Է� �ޱ�
				if(sendFile.equalsIgnoreCase("quit")) {
					out.writeUTF(sendFile);
					break;
				}
				send = new FileInputStream(new File(sendFile));					//�Է� ���� ���ϸ��� ���� ���� �о����
				 
				byte[] buffer = new byte[4096];									//2KB ������ ���� data�� ���� ����
				 
				int data=0;														//�ѹ��� ������ �������� ��
				int size=0;														//�����ϴ� ������ ũ�� (*4KB �ϸ� ������ ũ��)
				out.writeUTF(sendFile);											//���ϸ��� Ŭ���̾�Ʈ���� �����ֱ�
				//4KB������ ������ �����͸� �о���� ������ size�� ������ ����ũ��/4KB�̴�.
				while((send.read(buffer) != -1)) {								
					size++;
				}
				//size�� client�� �����ش�.
				out.writeInt(size);				
				out.flush();
				//������ �ѹ� �о��� ������ �ݰ� �ٽÿ����ش�.
				send.close();													
				send = new FileInputStream(new File(sendFile));
				
				//������ buffer�� ũ�⸸ŭ�� ���Ͽ� �����ش�.
				//������ ������ �����ϴ� �ܰ�
				while((data = send.read(buffer)) != -1) {					 		
					socket.getOutputStream().write(buffer,0,data);		//socket(client)�� ���
				
				}
				System.out.println("���ۼ���!");
				send.close();													//���� �ݱ�
				}
		}catch(IOException e){
			System.out.println(e.getMessage());
		}finally {
			try {
				out.close();
				socket.close();			
				server.close();
			}catch (IOException e) {
				System.out.println("Ŭ���̾�Ʈ�� ������ �߻�");
			}
		}
	}

}
			
