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

# Stranded II �����ڵ� ��� (�ѱ���)


<Stranded II>�� ��Ʈ�� ��Ʈ ����̱� ������ Blitz3D�� ������ GDI ������� �����ڵ� ��Ʈ�� Stranded Directx Surface�� ����ϴ� DLL ���̺귯���� �ۼ��߽��ϴ�.

## ����
- ���� �޴��� ���� GUI ��ư���� �����մϴ�.
- GDI�� �ؽ�Ʈ ��� �ڵ带 ����� �����ս��� ���� �ʽ��ϴ�. (������ ��� ������ ����)

## TODO
- �ϱ���, ä��â ���� �ؽ�Ʈ�� �����ڵ� ������� ����
- �����ս� ����
   1. �����ڵ带 �����ϴ� ��Ʈ�� ��Ʈ ����� ����
   2. Ȥ�� �̸� ��Ʈ�� �׷����� ��������Ʈ�� ���α׷� ���� �� ����
- ���� �۾�


## ����?

- ������Ʈ �ֻ��� ��ο� "Output" ������ ����ϴ�.
- Source ������ �������մϴ�. IDEal, Blitz3D�� ���� ������ ���� IDE�� ����ϸ� �˴ϴ�.
- LibDll ������ �������մϴ�. Visual Studio 2015�� ����ϼ���.
- ��Ʈ����� ���ҽ��� �ִ� "core", "mods" ������ "Output" ���� ���� �߰��մϴ�.
- "StrandedII.exe"�� �����մϴ�!