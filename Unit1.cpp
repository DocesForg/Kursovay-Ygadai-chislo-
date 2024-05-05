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
            // �������������� ����� � ������ ��� ������������� to_string
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
   if(Edit1->Text == "")
   {
     ShowMessage("����������, ��������� ����."); // ����� ��������������
        Edit1->SetFocus(); // ����������� ������ �� Edit ����
   }
   else
   {

   guess = StrToInt(Edit1->Text);
// �������� ����� �� Edit1
    int num = StrToIntDef(Edit1->Text, 0); // ���������� StrToIntDef, ����� �������� ���������� ��� ����� ���������� ��������
    if (i<=9)
    {
    // ���������, ��������� �� ����� � ��������� �� 1 �� 1000
    if (guess >= 1 && guess <= 1000)
    {
        // ��������� ����� � ������
        numbers[i] = num;

        // ����������� ������ ��� ���������� �����
        i++;

        // ������� Edit1
        Edit1->Clear();

    }
    else
    {
        ShowMessage("����������, ������� ����� �� 1 �� 1000.");
        Edit1->SetFocus(); // ������������� ����� ������� �� Edit1
    }
        // ������� ������� ����� � Memo1
    Memo1->Lines->Clear();

    // ������� ����� �� ������� � Memo1
    for (int j = 0; j < i; j++)
    {
        Memo1->Lines->Add(IntToStr(numbers[j]));
    }

    }
    else
    {
        ShowMessage("�� ���������! �������� ����� �����");
        Edit1->SetFocus(); // ������������� ����� ������� �� Edit1
    }

       countMatches(secretNumber, guess, correctDigits, correctPositions);
        AnsiString correctPositionsStr(correctPositions.c_str());
        Memo2->Lines->Add("������� ����: " + IntToStr(correctDigits) + ", ���������� �������: " + correctPositionsStr);
     if (secretNumber == guess)
    {
        Memo2->Lines->Add("�����������! �� ������� �����!");
    }
    }
    }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

         if (Edit2->Text == "") // �������� �� ������ ����
    {
        ShowMessage("����������, ��������� ����."); // ����� ��������������
        Edit2->SetFocus(); // ����������� ������ �� Edit ����
    }

        else {
        secretNumber = StrToInt(Edit2->Text);
        Edit2->Text = "����� �������";
        Timer1->Enabled = true;
        // ������� ������ numbers
    memset(numbers, 0, sizeof(numbers));

    // ���������� ������ � 0
    i = 0;

        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Timer1->Enabled = false;
        Edit2->Text = "";
}
//---------------------------------------------------------------------------



