# Red’s makefile

## 파일 구조
```
project_name
      ├-Makefile
      └-src
         ├-main
         │  └--*.c
         ├-study
         │  └--*.c
         └-test
            ├--*Test.c
            └--unity
                └--src
```

## 다운로드
```
curl -L -O https://github.com/parkchu/study-C/raw/lotto/lotto/Makefile
```
위 명령어를 통해 Makefile 을 다운받아 사용한다.

## 사용 방법

### use test ver
1. Makefile 을 프로젝트 폴더 하위에 다운받는다.
2. make init 을 통해 하위 폴더들을 만든다.
3. src/main, src/test 에 코드를 구현한다.
4. make 또는 make all 을 입력해 코드를 컴파일하고 실행한다.

### use only main ver
1. Makefile 을 프로젝트 폴더 하위에 다운받는다.
2. make initM 을 통해 하위 폴더들을 만든다.
3. src/main에 코드를 구현한다.
4. make main 을 입력해 코드를 컴파일하고 실행한다.

### use study
* study 폴더는 학습 코드들을 작성하는 공간 입니다.
* 학습 코드들은 main 함수를 가지고 있어야 하며 구분하기 위해 *.c.out 으로 실행 파일이 만들어집니다.
1. study 파일에 코드를 구현한다.
2. make study 를 입력해 코드를 컴파일하고 실행한다.

## 규칙
1. 파일 구조는 꼭지켜야 한다. (폴더명도 똑같아야 한다.)
2. main 함수는 main, test 폴더에 하나씩만 존재해야 한다.
3. 실행 파일은 main.out 으로 만들어진다. (실행은 ./main.out 또는 make run 으로 한다.)
4. 처음 실행할땐 make init (테스트 코드를 구현하지 않을거면 make initM) 을 실행한다.
5. build 할때 작성한 코드가 없다면 컴파일 에러가 발생하지만 'build complete !' 라는 문구가 뜨면 빌드는 성공한것이다.
6. build 를 했다면 다음부턴 make 또는 make all (컴파일만 하고 싶다면 make compile, 테스트 코드를 구현하지 않을거면 make main) 을 실행한다.
7. 테스트 코드의 파일명은 내가 테스트하려는 파일 이름에 Test 를 추가하여 작성한다. ex) pikachu.c 파일을 테스트 하는 테스트 코드 파일명은 pikachuTest.c 가 되어야한다.
8. 테스트 코드를 작성할땐 unity 로 작성해야한다.
9. unity 폴더는 test 폴더 하위에 있어야한다.
10. unity 파일들은 공식 사이트에서 다운 받은 src 폴더를 unity 폴더 하위로 넣어서 사용한다.
11. study 는 학습 코드를 작성하는 폴더 로써 모든 파일은 main 함수가 있어야한다.

## 사용할 수 있는 명령어
* 명령어는 기본적으로 앞에 make 를 붙여 사용합니다.

|명령어|기능|
|:------:|-----------------------------------|
|all|모든 파일을 컴파일하고 테스트하고 실행합니다.|
|compile|모든 파일을 컴파일하고 테스트합니다.|
|main|main 폴더 내의 파일들만 컴파일하고 실행합니다.|
|study|study 폴더 내의 파일들을 컴파일하고 실행합니다.|
|studyR|예전에 컴파일한 *.c.out 파일들을 실행합니다.|
|build|main, test 의 build 폴더를 만들며 모든 파일을 컴파일하고 테스트하고 실행합니다.|
|buildM|main 의 build 폴더를 만들며 main 폴더 내의 파일들만 컴파일하고 실행합니다.|
|run|에전에 컴파일한 main.out 을 실행합니다.|
|test|에전에 컴파일한 test.out 을 실행합니다.|
|clean|build폴더와 실행 파일을 삭제합니다.|
