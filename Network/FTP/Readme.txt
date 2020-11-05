1. Simple_FTP_Server를 먼저 실행하고 Simple_FTP_Client를 서로 다른 디렉터리에서 실행하여야 한다.

2. Simple_FTP_Server를 실행하면 ‘연결중...’ 이라는 문구가 프린트 되고 이 때 Simple_FTP_Client를 실행하면 server와 client모두 ‘연결 성공!’ 이라는 문구를 프린트한다.

3.  2가 끝나면 server는 전송할 파일명을 입력받을 준비를 마친다.

4. 이 때 전송할 파일명은 확장자명 까지 꼭 같이 입력해야하며, Simple_FTP_Server.java와 같은 디렉터리에 있어야만 한다. 하지만 꼭 txt파일이 아니어도 된다.

5. 파일명을 입력하면 server는 파일을 전송하고 파일 전송이 끝나면 ‘전송성공!’ 이라는 문구를 프린트하며, client는 ‘파일명 수신완료!’를 프린트한다.

6. 4에서 파일명이 아닌 quit을 입력하면 연결을 종료하고 프로그램을 종료한다.         
(이 때 대소문자는 구분하지 않는다.)

7. Sample file은 00_cats.jpg와 01_frame.jpg, 02_london.jpg이다.
