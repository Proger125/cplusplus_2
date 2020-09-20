#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include "Observe.h"
#include "StackModel.h"
using namespace std;

class Screen : public Observer {
 private:
  StackModel<int> *model;
  const int smallButtonWidth = 60;
  const int smallButtonHeight = 30;
  const int bigButtonWidth = 70;
  const int bigButtonHeight = 40;
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

 public:
  Screen(string path, StackModel<int> *model);
  void SetElements(HDC hdc,const int screenWidth,const int screenHeight);
  void DestroyElements();
  void CreateViews(int type);
  void SetText(string text);
  int GetPushElement(int type);
  virtual void update(int type);
};
