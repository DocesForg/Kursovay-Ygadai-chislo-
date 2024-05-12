//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h>
#include <iostream.h>
#include <time.h>
#include <cstdlib> // Для функций rand() и srand()
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
// Функция для подсчета количества угаданных цифр и их позиций
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
            // Преобразование цифры в строку
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
int numbers[9]; // Массив для хранения чисел
int i = 0; // Текущий индекс массива
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
     Application->Title="Осторожно!";
     ShowMessage("Пожалуйста, придумайте число."); // Вывод предупреждения
        Edit2->SetFocus(); // Возвращение фокуса на Edit поле
                Memo1->Lines->Clear();
                Memo2->Lines->Clear();
                Edit1->Clear();
                Edit2->Clear();
   }
   else if(Edit1->Text == "")
   {
     Application->Title="Осторожно!";
     ShowMessage("Пожалуйста, заполните поле."); // Вывод предупреждения
        Edit1->SetFocus(); // Возвращение фокуса на Edit поле
   }
   else
   {

   guess = StrToInt(Edit1->Text);
// Получаем число из Edit1
    int num = StrToIntDef(Edit1->Text, 0); // Используем StrToIntDef, чтобы избежать исключения при вводе нечисловых символов
    if (i<10)
    {
        if (guess >= 1 && guess <= 1000)
    {
        // Добавляем число в массив
        numbers[i] = num;

        // Увеличиваем индекс для следующего числа
        i++;
     }
        // Очищаем Edit1
        Edit1->Clear();
         // Очищаем текущий текст в Memo1
    Memo1->Lines->Clear();

    // Выводим числа из массива в Memo1
    for (int j = 0; j < i; j++)
    {
        Memo1->Lines->Add(IntToStr(numbers[j]));
    }


    if (guess >= 1 && guess <= 1000 && secretNumber>= 1 && secretNumber <= 1000)
    {
       countMatches(secretNumber, guess, correctDigits, correctPositions);
        AnsiString correctPositionsStr(correctPositions.c_str());
        Memo2->Lines->Add("Угадано цифр: " + IntToStr(correctDigits) + ", правильные позиции: " + correctPositionsStr);
     if (secretNumber == guess)
    {
         Application->Title="Победа";
         ShowMessage("Поздравляем, вы победили!");

            // ?????? ?? ?????? ????? ????
            int choice = MessageBox(NULL, "Хотите начать новую игру?", "Новая игра", MB_YESNO | MB_ICONQUESTION);

            if (choice == IDYES)
            {
                Memo1->Lines->Clear();
                Memo2->Lines->Clear();
                Edit1->Clear();
                Edit2->Clear();
                // Очищает массив numbers
    memset(numbers, 0, sizeof(numbers));

                 // Сбрасывает индекс в 0
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
        Application->Title="Внимание!";
        ShowMessage("Пожалуйста, введите число от 1 до 1000.");
        Edit1->SetFocus(); // Устанавливаем фокус обратно на Edit1

    }
     }
    else
    {
        Application->Title="Проигрыш";
        ShowMessage("Вы проиграли! Создайте новое число");

            // ?????? ?? ?????? ????? ????
            int choice = MessageBox(NULL, "Хотите начать новую игру?", "Новая игра", MB_YESNO | MB_ICONQUESTION);

            if (choice == IDYES)
            {
                Memo1->Lines->Clear();
                Memo2->Lines->Clear();
                Edit1->Clear();
                Edit2->Clear();
                // Очищает массив numbers
    memset(numbers, 0, sizeof(numbers));

                 // Сбрасывает индекс в 0
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
         if (Edit2->Text == "" ) // Проверка на пустое поле
    {
        Application->Title="Осторожно!";
        ShowMessage("Пожалуйста, заполните поле."); // Вывод предупреждения
        Edit2->SetFocus(); // Возвращение фокуса на Edit поле
    }


        else {
        secretNumber = StrToInt(Edit2->Text);
        if(secretNumber>= 1 && secretNumber <= 1000)
        {
        Edit2->Text = "Число создано";
        Timer1->Enabled = true;
        // Очищает массив numbers
    memset(numbers, 0, sizeof(numbers));

    // Сбрасывает индекс в 0
    i = 0;

        Memo1->Lines->Clear();
        }
        else{
        Application->Title="Осторожно!";
        ShowMessage("Пожалуйста, введите число от 1 до 1000.");
        Edit2->SetFocus(); // Устанавливаем фокус обратно на Edit1
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

