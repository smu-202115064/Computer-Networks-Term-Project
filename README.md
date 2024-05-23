# Term Project

## Problem Statement

* Client 에서 보내는 문자열을 Server에서 그대로 다시 Client로 보내주는 프로그램을 작성하세요.
* 예외 case - Client에서 입력받는 특수문자
    * c or C: server에서 여태까지 받은 메시지의 개수를 client로 넘겨줌
    * q or Q: client와 server측에서 접속종료
* 결과는 아래와 같이 출력되어야 합니다.

```
/2024_실습/컴퓨터네트워크과제# ./server_win
Waiting...
[Client Connected]
Received Message: Hello
Received Message: Computer
Received Message: Networks
[Message Cnt Response (cnt: 3) ]
[Message Cnt Response (cnt: 3) ]
Received Message: GoodBye!!
[Message Cnt Response (cnt: 4) ]
[Client Disconnected]
```

```
/2024_실습/컴퓨터네트워크과제# ./client_win
Input message: Hello
[Text From Server : Hello ]
Input message: Computer
[Text From Server : Computer ]
Input message: Networks
[Text From Server : Networks ]
Input message: c
[Message Cnt Request]
[Text From Server : 3 ]
Input message: c
[Message Cnt Request]
[Text From Server : 3 ]
Input message: GoodBye!!
[Text From Server : GoodBye!! ]
Input message: c
[Message Cnt Request]
[Text From Server : 4 ]
Input message: q
[Disconnection Request]
```

## 결과보고서

* 서버(server.c)와 클라이언트(client.c) 두 개의 소스코드와 아래의 문제를 해결한 결과보고서 총 세 개의 파일을 압축하여 제출하세요.
* 문제
    1. 문제의 화면과 같은 형태의 양측 출력화면 캡처
    2. Client의 포트번호는 무엇인가?
    3. 서버에 클라이언트가 접속하는 것과 관계된 wireshark 패킷캡처
    4. 클라이언트가 문자열을 보내는 것과 보낸 문자열을 되돌려주는 것과 관계된 wireshark 패킷캡처
    5. 문자열의 개수를 세는 것과 관계된 wireshark 패킷캡처
    6. 접속 종료와 관계된 wireshark 패킷캡처

    주의사항) 패킷캡처는 해당패킷을 클릭 후 wireshark 전체화면을 캡처하여 제출하세요.
