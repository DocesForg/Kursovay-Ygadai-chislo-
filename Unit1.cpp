//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h>
#include <iostream.h>
#include <time.h>
#include <cstdlib> // ��� ������� rand() � srand()
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
// ������� ��� �������� ���������� ��������� ���� � �� �������
void countMatches(int secret, int guess, int& correctDigits, string& correctPositions) {
    correctDigits = 0;
    correctPositions = "";
    int secretCopy = secret;
    int guessCopy = guess;
    while (secretCopy > 0 && guessCopy > 0) {
        int secretDigit = secretCopy % 10;
        int guessDigit = guessCopy % 10;
        if (secretDigit == guessDigit) {
            correctDigits++;
            // �������������� ����� � ������
            char digitChar = '0' + secretDigit;
            correctPositions = digitChar + correctPositions;
        }
        secretCopy /= 10;
        guessCopy /= 10;
    }
}
int secretNumber;
    int guess;
    int correctDigits;
    string correctPositions;
int numbers[9]; // ������ ��� �������� �����
int i = 0; // ������� ������ �������
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   if(secretNumber==0)
   {
     Application->Title="���������!";
     ShowMessage("����������, ���������� �����."); // ����� ��������������
        Edit2->SetFocus(); // ����������� ������ �� Edit ����
                Memo1->Lines->Clear();
                Memo2->Lines->Clear();
                Edit1->Clear();
                Edit2->Clear();
   }
   else if(Edit1->Text == "")
   {
     Application->Title="���������!";
     ShowMessage("����������, ��������� ����."); // ����� ��������������
        Edit1->SetFocus(); // ����������� ������ �� Edit ����
   }
   else
   {

   guess = StrToInt(Edit1->Text);
// �������� ����� �� Edit1
    int num = StrToIntDef(Edit1->Text, 0); // ���������� StrToIntDef, ����� �������� ���������� ��� ����� ���������� ��������
    if (i<10)
    {
        if (guess >= 1 && guess <= 1000)
    {
        // ��������� ����� � ������
        numbers[i] = num;

        // ����������� ������ ��� ���������� �����
        i++;
     }
        // ������� Edit1
        Edit1->Clear();
         // ������� ������� ����� � Memo1
    Memo1->Lines->Clear();

    // ������� ����� �� ������� � Memo1
    for (int j = 0; j < i; j++)
    {
        Memo1->Lines->Add(IntToStr(numbers[j]));
    }


    if (guess >= 1 && guess <= 1000 && secretNumber>= 1 && secretNumber <= 1000)
    {
       countMatches(secretNumber, guess, correctDigits, correctPositions);
        AnsiString correctPositionsStr(correctPositions.c_str());
        Memo2->Lines->Add("������� ����: " + IntToStr(correctDigits) + ", ���������� �������: " + correctPositionsStr);
     if (secretNumber == guess)
    {
         Application->Title="������";
         ShowMessage("�����������, �� ��������!");

            // ?????? ?? ?????? ????? ????
            int choice = MessageBox(NULL, "������ ������ ����� ����?", "����� ����", MB_YESNO | MB_ICONQUESTION);

            if (choice == IDYES)
            {
                Memo1->Lines->Clear();
                Memo2->Lines->Clear();
                Edit1->Clear();
                Edit2->Clear();
                // ������� ������ numbers
    memset(numbers, 0, sizeof(numbers));

                 // ���������� ������ � 0
                 i = 0;
                 guess=0;
                 secretNumber=0;
            }
            else
            {
                // ????????? ??????????
                Application->Terminate();
            }
    }
    }
     else
    {
        Application->Title="��������!";
        ShowMessage("����������, ������� ����� �� 1 �� 1000.");
        Edit1->SetFocus(); // ������������� ����� ������� �� Edit1

    }
     }
    else
    {
        Application->Title="��������";
        ShowMessage("�� ���������! �������� ����� �����");

            // ?????? ?? ?????? ????? ????
            int choice = MessageBox(NULL, "������ ������ ����� ����?", "����� ����", MB_YESNO | MB_ICONQUESTION);

            if (choice == IDYES)
            {
                Memo1->Lines->Clear();
                Memo2->Lines->Clear();
                Edit1->Clear();
                Edit2->Clear();
                // ������� ������ numbers
    memset(numbers, 0, sizeof(numbers));

                 // ���������� ������ � 0
                 i = 0;
                 guess=0;
                 secretNumber=0;
            }
            else
            {
                // ????????? ??????????
                Application->Terminate();
            }
    }
    }
    }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
         if (Edit2->Text == "" ) // �������� �� ������ ����
    {
        Application->Title="���������!";
        ShowMessage("����������, ��������� ����."); // ����� ��������������
        Edit2->SetFocus(); // ����������� ������ �� Edit ����
    }


        else {
        secretNumber = StrToInt(Edit2->Text);
        if(secretNumber>= 1 && secretNumber <= 1000)
        {
        Edit2->Text = "����� �������";
        Timer1->Enabled = true;
        // ������� ������ numbers
    memset(numbers, 0, sizeof(numbers));

    // ���������� ������ � 0
    i = 0;

        Memo1->Lines->Clear();
        }
        else{
        Application->Title="���������!";
        ShowMessage("����������, ������� ����� �� 1 �� 1000.");
        Edit2->SetFocus(); // ������������� ����� ������� �� Edit1
         Memo1->Lines->Clear();
         Memo2->Lines->Clear();
         Edit1->Clear();
         Edit2->Clear();
         secretNumber = 0;
         guess=0;
        }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Timer1->Enabled = false;
        Edit2->Text = "";
}

void __fastcall TForm1::PhoneKeyPress(TObject *Sender, char &Key)
{
   if(!((Key >= '0' && Key <= '9') || Key == VK_BACK )) Key = 0x00;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
Key=0;        
}
//---------------------------------------------------------------------------

