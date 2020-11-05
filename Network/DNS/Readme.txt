1. LocalDNS_Server를 먼저 실행하고 LocalDNS_Client를 실행하여야 한다.

2. LocalDNS_Server를 실행하면 ‘연결중...’ 이라는 문구가 프린트 되고 이 때 LocalDNS_Client를 실행하면 server와 client모두 ‘연결 성공!’ 이라는 문구를 프린트한다.

3. client는 ‘IP 주소나 도메인 이름을 적어주세요’라는 문구를 볼 수 있고 이제 입력을     할 수 있다.

4. 입력 형식은 Pdf파일에 나온 “N : domain name” (예: N : www.naver.com)과       “R : IP address” (예: R : 210.89.164.90)을 지키며 입력해야만 한다.

5. N을 이용해 도메인 이름을 입력하면 그 도메인의 IP주소를 반환받을 수 있고 그 도메인과 IP주소는 Server의 table에 저장된다. 

6. 도메인 이름이 정확하지 않으면 프로그램이 정상적으로 작동하지 않기 때문에 정확하게 입력하여야만 한다.

7. R을 이용해 IP 주소를 입력하면 5를 통해 저장된 table을 참조해 도메인의 주소를 반환해준다. 프로그램을 실행하면 table이 빈 상태이므로 원하는 도메인의 주소를 정확하게 반환 받으려면 프로그램 실행 중에 입력한 도메인의 IP 주소여야만 한다. 그렇지 않으면 Not Found를 반환한다.

8. 클라이언트는 도메인과 IP주소가 아닌 quit을 입력하면 연결을 종료할 수 있다. 이 때 quit의 대소문자는 구분하지 않는다.

9. 테스트 케이스는 N : www.naver.com , N : www.daum.net , N : www.google.co.kr 등이 있다.