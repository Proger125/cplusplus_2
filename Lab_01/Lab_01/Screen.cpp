#include "Screen.h"
void Screen::SetElements(HDC hdc, const int screenWidth,
                         const int screenHeight) {
  for (int i = 0; i < buttonNames.size(); i++) {
    HWND hwnd1;
    HWND hwnd2;
    hwnd1 = CreateWindowA(
        "button", buttonNames[i].data(), WS_CHILD | WS_VISIBLE, 20, 50 + i * 60,
        smallButtonWidth, smallButtonHeight, GetActiveWindow(),
        (HMENU)(1000 + i), GetModuleHandle(NULL), NULL);
    if (i != 0) {
      EnableWindow(hwnd1, false);
    }
    firstStackButtons.push_back(hwnd1);
    hwnd2 = CreateWindowA(
        "button", buttonNames[i].data(), WS_CHILD | WS_VISIBLE,
        screenWidth - 80, 50 + i * 60, smallButtonWidth, smallButtonHeight,
        GetActiveWindow(), (HMENU)(1000 + 10 + i), GetModuleHandle(NULL), NULL);
    if (i != 0) {
      EnableWindow(hwnd2, false);
    }
    secondStackButtons.push_back(hwnd2);
  }
  firstStackLabel = CreateWindowA("static", "", WS_CHILD | WS_VISIBLE, 120, 50,
                                  150, 60, GetActiveWindow(), (HMENU)(998),
                                  GetModuleHandle(NULL), NULL);
  secondStackLabel = CreateWindowA(
      "static", "", WS_CHILD | WS_VISIBLE, screenWidth - 270, 50, 150, 60,
      GetActiveWindow(), (HMENU)(999), GetModuleHandle(NULL), NULL);
  bothLable =
      CreateWindowA("static", "", WS_CHILD | WS_VISIBLE, screenWidth / 2 - 20,
                    screenHeight / 2 - 10, 40, 20, GetActiveWindow(),
                    (HMENU)(994), GetModuleHandle(NULL), NULL);
  firstStackPushEdit = CreateWindowA(
      "edit", "0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 120, 410, 30,
      30, GetActiveWindow(), (HMENU)(995), GetModuleHandle(NULL), NULL);
  secondStackPushEdit = CreateWindowA(
      "edit", "0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, screenWidth - 150, 410, 30,
      30, GetActiveWindow(), (HMENU)(995), GetModuleHandle(NULL), NULL);
  hSumButton = CreateWindowA("button", "Sum", WS_CHILD | WS_VISIBLE,
                             screenWidth / 2 - 30, 50, bigButtonWidth,
                             bigButtonHeight, GetActiveWindow(), (HMENU)(996),
                             GetModuleHandle(NULL), NULL);
  //EnableWindow(hSumButton, false);
  hSwapButton = CreateWindowA("button", "Swap", WS_CHILD | WS_VISIBLE,
                              screenWidth / 2 - 30, 110, bigButtonWidth,
                              bigButtonHeight, GetActiveWindow(), (HMENU)(997),
                              GetModuleHandle(NULL), NULL);
  //EnableWindow(hSwapButton, false);
}
Screen::Screen(string path) {
  ifstream fin(path);
  string line;
  while (!fin.eof()) {
    fin >> line;
    buttonNames.push_back(line);
  }
  fin.close();
}
void Screen::DestroyElements() {
  for (int i = 0; i < firstStackButtons.size(); i++) {
    DestroyWindow(firstStackButtons[i]);
  }
  for (int i = 0; i < secondStackButtons.size(); i++) {
    DestroyWindow(firstStackButtons[i]);
  }
  DestroyWindow(hSumButton);
  DestroyWindow(hSwapButton);
}
void Screen::ButtonClick(int clickType) {
  int type = (clickType / 10) % 10;
  switch (clickType) {
    case 996: {
      controller.StacksSum();
      string StackToString = controller.ToString(0);
      ShowStackText(StackToString, 0);
      break;
    }
    case 997: {
      controller.StacksSwap();
      string Stack1ToString = controller.ToString(0);
      string Stack2ToString = controller.ToString(1);
      ShowStackText(Stack1ToString, 0);
      ShowStackText(Stack2ToString, 1);
      break;
    }
    case 1000:
    case 1010: {
      controller.StackConstructor(type);
      for (int i = 0; i < firstStackButtons.size(); i++) {
        if (type == 0) {
          EnableWindow(firstStackButtons[i], true);
          EnableWindow(firstStackButtons[0], false);
        } else {
          EnableWindow(secondStackButtons[i], true);
          EnableWindow(secondStackButtons[0], false);
        }
      }
      break;
    }
    case 1001:
    case 1011: {
      controller.StackClear(type);
      string StackToString = controller.ToString(type);
      ShowStackText(StackToString, type);
      break;
    }
    case 1002:
    case 1012: {
      bool IsEmpty = controller.StackIsEmpty(type);
      string result;
      if (IsEmpty) {
        result = "true";
      } else {
        result = "false";
      }
      SetWindowTextA(this->bothLable, result.data());
      UpdateWindow(GetActiveWindow());
      break;
    }
    case 1003:
    case 1013: {
      int size = controller.StackSize(type);
      char buf[10];
      _itoa_s(size, buf, 10);
      SetWindowTextA(this->bothLable, buf);
      break;
    }
    case 1004:
    case 1014: {
      int element = controller.StackTop(type);
      char buf[10];
      _itoa_s(element, buf, 10);
      SetWindowTextA(this->bothLable, buf);
      break;
    }
    case 1005:
    case 1015: {
      controller.StackPop(type);
      string StackToString = controller.ToString(type);
      ShowStackText(StackToString, type);
      break;
    }
    case 1006:
    case 1016:{
      int len;
      char str[20];
      int element;
       if (type == 0) {
        len = GetWindowTextA(firstStackPushEdit, str, 20);
        element = atoi(str);
       } else {
         len = GetWindowTextA(secondStackPushEdit, str, 20);
         element = atoi(str);
       }
      controller.StackPush(type, element);
       string StackToString = controller.ToString(type);
       ShowStackText(StackToString, type);
      break;
    }
    default:
      break;
  }
}
void Screen::ShowStackText(string text, int type) {
  if (type == 0) {
    SetWindowTextA(firstStackLabel, text.data());
  } else {
    SetWindowTextA(secondStackLabel, text.data());
  }
}