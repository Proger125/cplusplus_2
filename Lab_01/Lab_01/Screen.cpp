#include "Screen.h"
void Screen::SetElements(HDC hdc,const int screenWidth,const int screenHeight) {
  for (int i = 0; i < buttonNames.size(); i++) {
    HWND hwnd1;
    HWND hwnd2;
    hwnd1 =
        CreateWindowA("button", buttonNames[i].data(), WS_CHILD | WS_VISIBLE,
                      20, 50 + i * 60, 60, 20, GetActiveWindow(),
                      (HMENU)(1000 + i), GetModuleHandle(NULL), NULL);
    firstStackButtons.push_back(hwnd1);
    hwnd2 =
        CreateWindowA("button", buttonNames[i].data(), WS_CHILD | WS_VISIBLE,
                      screenWidth - 80, 50 + i * 60, 60, 20, GetActiveWindow(),
                      (HMENU)(1000 + 10 + i), GetModuleHandle(NULL), NULL);
    secondStackButtons.push_back(hwnd2);
  }
  firstStackLabel = CreateWindowA("static", "", WS_CHILD | WS_VISIBLE, 120, 50,
                                  150, 60, GetActiveWindow(), (HMENU)(998),
                                  GetModuleHandle(NULL), NULL);
  secondStackLabel = CreateWindowA("static", "", WS_CHILD | WS_VISIBLE, screenWidth - 270, 50,
                                  150, 60, GetActiveWindow(), (HMENU)(999),
                                  GetModuleHandle(NULL), NULL);
  hSumButton =
      CreateWindowA("button", "Sum", WS_CHILD | WS_VISIBLE,
                    screenWidth / 2 - 30, 50, 60, 30, GetActiveWindow(),
                    (HMENU)(996), GetModuleHandle(NULL), NULL);
  hSwapButton = CreateWindowA(
      "button", "Swap", WS_CHILD | WS_VISIBLE, screenWidth / 2 - 30, 90, 60, 30,
      GetActiveWindow(), (HMENU)(997), GetModuleHandle(NULL), NULL);
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