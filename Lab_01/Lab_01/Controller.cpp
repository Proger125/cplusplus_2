#include "Controller.h"
Controller::Controller(StackModel<int>* model, Screen* screen) {
  this->model = model;
  this->screen = screen;
}
void Controller::ButtonClick(int clickType) {
  int type = (clickType / 10) % 10;
  switch (clickType) {
    case 996: {
      model->StacksSum();
      break;
    }
    case 997: {
      model->StacksSwap();
      break;
    }
    case 1000: {
      model->StackConstructor(0);
      screen->CreateViews(0);
      break;
    }
    case 1010: {
      model->StackConstructor(1);
      screen->CreateViews(1);
      break;
    }
    case 1001: {
      model->StackClear(0);
      break;
    }
    case 1011: {
      model->StackClear(1);
      break;
    }
    case 1002: {
      bool IsEmpty = model->StackIsEmpty(0);
      string text;
      if (IsEmpty) {
        text = "true";
      } else {
        text = "false";
      }
      screen->SetText(text);
      break;
    }
    case 1012: {
      bool IsEmpty = model->StackIsEmpty(1);
      string text;
      if (IsEmpty) {
        text = "true";
      } else {
        text = "false";
      }
      screen->SetText(text);
      break;
    }
    case 1003: {
      int size = model->StackSize(0);
      string text = to_string(size);
      screen->SetText(text);
      break;
    }
    case 1013: {
      int size = model->StackSize(1);
      string text = to_string(size);
      screen->SetText(text);
      break;
    }
    case 1004: {
      int element = model->StackTop(0);
      string text = to_string(element);
      screen->SetText(text);
      break;
    }
    case 1014: {
      int element = model->StackTop(1);
      string text = to_string(element);
      screen->SetText(text);
      break;
    }
    case 1005: {
      model->StackPop(0);
      break;
    }
    case 1015: {
      model->StackPop(1);
      break;
    }
    case 1006: {
      int element = screen->GetPushElement(0);
      model->StackPush(0, element);
      break;
    }
    case 1016: {
      int element = screen->GetPushElement(1);
      model->StackPush(1, element);
      break;
    }
    case 1007: {
      int sumOfElements = model->SumOfElements(0);
      string text = to_string(sumOfElements);
      screen->SetText(text);
      break;
    }
    case 1017: {
      int sumOfElements = model->SumOfElements(1);
      string text = to_string(sumOfElements);
      screen->SetText(text);
      break;
    }
    default:
      break;
  }
}
  