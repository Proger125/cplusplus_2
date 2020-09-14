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
  secondStackPushEdit =
      CreateWindowA("edit", "0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                    screenWidth - 150, 410, 30, 30, GetActiveWindow(),
                    (HMENU)(995), GetModuleHandle(NULL), NULL);
  hSumButton = CreateWindowA("button", "Sum", WS_CHILD | WS_VISIBLE,
                             screenWidth / 2 - 30, 50, bigButtonWidth,
                             bigButtonHeight, GetActiveWindow(), (HMENU)(996),
                             GetModuleHandle(NULL), NULL);
  hSwapButton = CreateWindowA("button", "Swap", WS_CHILD | WS_VISIBLE,
                              screenWidth / 2 - 30, 110, bigButtonWidth,
                              bigButtonHeight, GetActiveWindow(), (HMENU)(997),
                              GetModuleHandle(NULL), NULL);
}
Screen::Screen(string path, StackModel *model) {
  ifstream fin(path);
  string line;
  while (!fin.eof()) {
    fin >> line;
    buttonNames.push_back(line);
  }
  fin.close();
  this->model = model;
  this->model->addObserver(this);
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
void Screen::CreateViews(int type) {
  if (type == 0) {
    for (int i = 0; i < firstStackButtons.size(); i++) {
      EnableWindow(firstStackButtons[i], true);
    }
    EnableWindow(firstStackButtons[0], false);
  } else {
    for (int i = 0; i < secondStackButtons.size(); i++) {
      EnableWindow(secondStackButtons[i], true);
    }
    EnableWindow(secondStackButtons[0], false);
  }
}
void Screen::SetText(string text) {
  SetWindowTextA(this->bothLable, text.data());
}
int Screen::GetPushElement(int type) {
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
  return element;
}
void Screen::update(int type) {
  if (type == 0) {
    SetWindowTextA(firstStackLabel, model->ToString(0).data());
  } else {
    SetWindowTextA(secondStackLabel, model->ToString(1).data());
  }
}