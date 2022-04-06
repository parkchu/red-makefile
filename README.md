### Joohan’s makefile rules

# 파일 구조
```
|----project_name
   |----Makefile
   |
   |----src
      |----main
      |  |----*.c
      |----test
         |----*Test.c
         |----unity
```

1. 파일 구조는 꼭지켜야 한다.
2. main.c 파일에 main 함수가 있어야 한다.
3. 실행 파일은 main.out 으로 만들어진다. (실행은 ./main.out 으로 한다.)
4. 처음 실행할땐 make build (테스트 코드를 작성하지 않았으면 make buildM) 를 실행한다.
5. build를 했다면 다음부턴 make 또는 make all (테스트 코드를 작성하지 않았으면 make compile) 을 실행한다.
6. 테스트 코드의 파일명은 내가 테스트하려는 파일 이름에 Test 를 추가하여 작성한다. ex) pikachu.c 파일을 테스트 하는 테스트 코드 파일명은 pikachuTest.c 가 되어야한다.
7. 테스트만 실행하고 싶다면 make test 를 입력한다.
8. 테스트 코드를 작성할땐 unity 로 작성해야한다.
9. unity 폴더는 test 폴더 하위에 있어야한다.
10. unity 파일들은 공식 사이트에서 다운 받은 src 폴더를 unity 폴더 하위로 넣어서 사용한다.

