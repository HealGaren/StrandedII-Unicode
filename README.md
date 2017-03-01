# ENG

# Stranded II Unicode Mode (for Korean)


<Stranded II> is based on bitmap font, so I learned about blitz3d and added the DLL: it draw text to Stranded II Directx Surface.


## Problem
- Work Only GUI Button Now.
- It Use GDI DrawText, So it's performance is so bad :(

## TODO
- Apply to Diary Text, Chatting Text, etc.
- Make Better Performance
   1. Use bitmap font
   2. Or make pre-draw sprite on program start
- Translate

## How To?

- Make "Output" folder in project root directory.
- Compile Source Folder. Use compile IDE such as IDEal, Blitz3D.
- Compile LibDll Folder. Use Visual Studio 2015.
- Add "core" and "mods" folder with resources into "Output" folder.
- Run "StrandedII.exe"!


# KOR

# Stranded II 유니코드 모드 (한국어)


<Stranded II>는 비트맵 폰트 기반이기 때문에 Blitz3D를 공부해 GDI 기반으로 유니코드 폰트를 Stranded Directx Surface에 출력하는 DLL 라이브러리를 작성했습니다.

## 문제
- 메인 메뉴와 같은 GUI 버튼에만 동작합니다.
- GDI의 텍스트 출력 코드를 사용해 퍼포먼스가 좋지 않습니다. (프레임 드랍 현상이 보임)

## TODO
- 일기장, 채팅창 등의 텍스트도 유니코드 기반으로 변경
- 퍼포먼스 개선
   1. 유니코드를 지원하는 비트맵 폰트 방식을 개발
   2. 혹은 미리 폰트를 그려놓은 스프라이트를 프로그램 시작 시 생성
- 번역 작업


## 사용법?

- 프로젝트 최상위 경로에 "Output" 폴더를 만듭니다.
- Source 폴더를 컴파일합니다. IDEal, Blitz3D와 같은 컴파일 지원 IDE를 사용하면 됩니다.
- LibDll 폴더를 컴파일합니다. Visual Studio 2015를 사용하세요.
- 스트랜디드 리소스가 있는 "core", "mods" 폴더를 "Output" 폴더 내에 추가합니다.
- "StrandedII.exe"를 실행합니다!