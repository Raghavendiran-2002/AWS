#ifndef secrets_h
#define secrets_h

const char AWS_IOT_ENDPOINT[] = "afl1q7n7v0eaz-ats.iot.ap-south-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAKDA3kRozFl6WfCByO8Tf0QC1//CMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA3MjYxNjE3
MTFaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDPKnKbeGcSst7Eb8mh
tgM9fPjWI01gPnJf4l+8JjJtLLyALfb6AqYQjFpa5zvOlKgKKzC5j5uIo8rCT+dL
3/Z8svEpCQwm3yafDWX8MXG8OE1Ofd6JHUS0ulWR7OwEGrEteVIZF+wxRaZKC5yW
n5NcccZXs3GylCv1Wsp7yM1UWBdYVckpKvlyWk/eSroMaX3ySoUXXD4i3i3lgM53
a4cCuizDAk20LfdpQUBqEWn+ZnxWnuwCe5wuJlhwPsTUsK5rlS7VSoJ6X7fk/DME
B+tPhObjRpIichi7PEqRvAXCXybxPWTnAKdpqw6BFbpTqs7IsaEsvQXp5IMcQU3B
/L8FAgMBAAGjYDBeMB8GA1UdIwQYMBaAFHvcv+x/W4xsCuoJtVaea8RyK/07MB0G
A1UdDgQWBBTpAxLpXWHt6nQnXmddN4dTqJRfvDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAyY5vQHpYSI7QiSKUQAQQMZiz
KV6oGBobkKMfC9zyABgAJs9x92jR4QxLtRR8FxemxW9p68qirn/D3mTtYLJH9YaA
2U65NvJRLi4at7SuMeNLmrP8JalwFiw3h9m5G4RuKn3htNvq4AEn5jh2QS7QQXSR
3bdLcJmbVqepL5MXeaHmWrjvn9ZA80yT6obk+8h6ut95ZfPU6oOheWWsp/H7CKc0
AoDZwZF6VU+qwzE7NlEmN7E8Vlj8y/AiuGCvf5VnN7jI80ZjE4DeCLkS66HHFrPc
W6jTA+RqJgZgHBcYSH0yxvYblOI8jouXrt8EC1r37/GigcBzLubjKPFIHyvucw==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAzypym3hnErLexG/JobYDPXz41iNNYD5yX+JfvCYybSy8gC32
+gKmEIxaWuc7zpSoCiswuY+biKPKwk/nS9/2fLLxKQkMJt8mnw1l/DFxvDhNTn3e
iR1EtLpVkezsBBqxLXlSGRfsMUWmSguclp+TXHHGV7NxspQr9VrKe8jNVFgXWFXJ
KSr5clpP3kq6DGl98kqFF1w+It4t5YDOd2uHAroswwJNtC33aUFAahFp/mZ8Vp7s
AnucLiZYcD7E1LCua5Uu1UqCel+35PwzBAfrT4Tm40aSInIYuzxKkbwFwl8m8T1k
5wCnaasOgRW6U6rOyLGhLL0F6eSDHEFNwfy/BQIDAQABAoIBAFW6SxLrEDw8qNLB
L78rgsu/G3oBwdNCBDKJivRhGhzzlk20t69dyTqv2fQkHCuweJk8pj0joEk6/nzK
c/yCAY44vnMsu0qarXDEKp/iFh69bcA9dglngzcGpMJuOHy6TvdybPbVX3hESjv5
8iKihmiK7Hj+WN59UnOFzqTKw61SyBeGIUKjAzmqI5OicwfRmE8pxCXm/0BP78tc
39TrT6JbNZa+psolAefHxZvpWAQmqag0PAcz+yiBieajQ9+cyqxjK+z/l27J4HSf
IblmooeWtpkK47nlarAYCnTAbHfDrf7Q7+gbpE92OXtuiGFFW2bHJ33wLJg924aE
6a7+sAECgYEA74V+KIA2YPT6bK263clDeSbb8KSyah9ERig6ifMhTv8rd5ewprVh
7nUyCFcDwQUz+fO9YKtf3ZAbv69vQyi0r7Yo2Jw4O+SoNUxqMya/K9kCiN6oMMyb
UqEBbpDfd0gWYemSTyfLOUekcPHJcDwVVX/WzlC4BTU1iXx+Sf7nDUECgYEA3WsZ
i7wYoxfn17t0deqZjq4csGRcc29yLsTbiHbk1UK82T9dwhkdx+OBbJlUwl7ax7iJ
TShwc5ZesvSkNkeKn59kjkEeUQV37r/Xt3B2P0DOM+Hd/tElayEAKMIUk/0Ts/CS
Bo7rm/EkliS+lcLgRChb0lu4ex0ZattqW1LwjMUCgYEAkOZiRuAhhZBOezayiH+8
aOuAPNl18ctOg17M4y2Jpf+qbSQAQyoRv694gCEb7UZXhkvU8klaqnAGyXS5S5ix
jmcV2MzRHDKdK/k5eg5jsoQLC4Afob317QvoENplxgR/PeaOk4JQaCuWKJmtMk+2
3E2FRrUATm49IBqHT/58CsECgYBkEKzg28b+niUm+A6v47A2LTXF+fVWLf2aaVkV
mTXds2WJgPusZpFw7r5lB/6oQRn6vMlAV5BKjKCLm8hCx548eVqGd6Nt1lzXR1gE
DQ1DlNQb2m3rZTXV7noV8XA/WVZ4MbasxBZyyU5RlJWVNRcJdnvY257J9OKxyiuM
zjTsSQKBgDlFaMUqDqNnHFwFcRB7czYlgGiv4ca9RGrX0nN3uA+Q2rGtF2JvO7YL
Be1RmQHE9KufuHDmDGlqAYDMr1C8J0BSNBBihLCsBwviL/6dwPagOhQTpRbJj95h
3pf7NGyt+by1U5qnGkQ6ioRuD0i2Q2iWG0iE8kke1Kn09Am+16Et
-----END RSA PRIVATE KEY-----
)KEY";

#endif