웹 클라이언트



# HTTP 프로토콜

TCP 상에서 돌아가는 텍스트 기반의 프로토콜. 80번 포트 사용.

HTTP는 암호화되지 않음. 따라서 패킷을 열어보면 평문으로 저장되어 있고 쉽게 도청이 가능함.

TLS (Transport Layer Security)를 적용하여 암호화된 버전을 HTTPS라고 함.



### HTTP request

HTTP request types

* GET : resource를 다운로드하고자 할 때
* HEAD : resource에 대한 정보를 알고자 할 때 (ex. 파일의 크기 정보)
* POST : 클라이언트가 서버에 정보를 보내고자 할 때
* PUT : POST랑 비슷하지만 update하는 데에 최적화되어있음. 업데이트하고자 하는 자원의 위치를 정확하게 명시해줘야 함.
* DELETE : URI로 지정된 리소스를 삭제하고자 할 때



HTTP 요청 메시지 예시

```http
GET /page1.htm HTTP/1.1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36
Accept-Language: en-US
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Host: example.com
Connection: Keep-Alive		// 이 메시지는 GET이므로 헤더만 있고 body는 없음.
```

개행할 때에는 `/r/n`을 함

헤더의 끝부분에는 빈 줄을 하나 두어서 헤더의 끝임을 표시함.

Connection을 Keep-Alive로 설정하면 서버는 이 요청에 대한 답변 메시지를 보낸 후에도 TCP 연결을 끊지 않고 다음 통신을 위해 대기함.



### HTTP response

요청 메시지와 마찬가지로 헤더와 body로 이루어져 있음.



HTTP response codes

* 200 OK
* 301 Moved Permanently
  * 대상 리소스가 다른 곳으로 이동되었으므로 다시 요청을 보내라는 뜻
  * 이동된 위치는 HTTP 헤더에 Location 필드에 명시됨.
* 400 Bad request
  * 서버가 요청을 이해할 수 없음
* 401 Unauthorized
  * 클라이언트가 해당 리소스에 접근 가능한 권한이 없음
* 403 Forbidden
  * 해당 리소스에 대한 접근이 차단됨
* 404 Page Not Found  / 404 File Not Found
* 500 Internal Server Error
  * 클라이언트의 요청을 수행하려고 하는 도중에 에러 발생



HTTP 응답 메시지 예시

```http
HTTP/1.1 200 OK
Cache-Control: max-age=604800
Content-Type: text/html; charset=UTF-8
Date: Fri, 14 Dec 2018 16:46:09 GMT
Etag: "1541025663+gzip"
Expires: Fri, 21 Dec 2018 16:46:09 GMT
Last-Modified: Fri, 09 Aug 2013 23:54:35 GMT
Server: ECS (ord/5730)
Vary: Accept-Encoding
X-Cache: HIT
Content-Length: 1270

<!doctype html>
<html>
<head>
	<title>Example Domain</title>
...
```

헤더에는 웹 페이지가 유효한 기간, 마지막으로 편집된 날짜, body의 길이 등 여러 정보가 담겨있음.

서버가 HTTP 메시지를 생성하는 시간에 body의 길이를 모를 경우에는 chunk로 쪼개서 메시지를 보냄

```http
HTTP/1.1 200 OK
Content-Type: text/plain; charset=ascii
Transfer-Encoding: chunked 			<- chunk 단위로 쪼개서 보낸다는 의미

44			<- 각 청크의 길이 (16진수)
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eius
37
mod tempor incididunt ut labore et dolore magna aliqua
0			<- 마지막에는 청크의 길이를 0으로 줘서 메시지가 끝남을 알림.
```



### URL

Uniform Resource Locator의 약자

아래와 같은 구조로 이루어짐

* 프로토콜 (http://)
* 호스트 이름 (www.example.com)
* 포트 (:80)
* 경로 (/res/page1.php?user=bob)
  * 쿼리 스트링 포함
* 해시 (#account)

합치면 아래와 같이 됨

```
http://www.example.com:80/res/page1.php?user=bob#account
```

