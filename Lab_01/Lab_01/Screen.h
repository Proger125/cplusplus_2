#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include "Controller.h"

using namespace std;

class Screen {
 private:
  Controller controller;
  vector<string> buttonNames;
  vector<HWND> firstStackButtons;
  vector<HWND> secondStackButtons;
  HWND firstStackLabel;
  HWND secondStackLabel;
  HWND firstStackPushEdit;
  HWND secondStackPushEdit;
  HWND hSumButton;
  HWND hSwapButton;
  HWND bothLable;
  const int smallButtonWidth = 60;
  const int smallButtonHeight = 30;
  const int bigButtonWidth = 70;
  const int bigButtonHeight = 40;
 public:
  Screen(string path);
  void SetElements(HDC hdc,const int screenWidth,const int screenHeight);
  void DestroyElements();
  void ButtonClick(int clickType);
};
