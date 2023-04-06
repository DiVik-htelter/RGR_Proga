#include <iostream>
#include <Windows.h>
#include <math.h>
//#include <stdio.h>
#include <conio.h>
#include <string>
//#include <stdio.h>
#include <cmath>
///Менюшка разделена по пунктам
///Она переключается как стрелосками там и колесиком мыши
/// нажатие левой кнопки мыши = энтеру
/// эскейп = выход или назад

using namespace std;
long double e = 2.71828182845904523536; 
double Pi = 3.1415926535; 
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
const int Hight = 30; // Высота консоли
const int With = 120; // Ширина консоли

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}//Moving carriage to coordinates (x,y)


class Loading_and_others_functions
{
public:
    void Loading_title(int iteration, int sleepTime) // Надпись "Loading..." которая меняет регистр буквв течении sleepTime и iteration раз
    {
        for (int i = 0; i < iteration; i++) {

            std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
            Sleep(sleepTime);
            std::cout << "\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
            Sleep(sleepTime);
        }
    }
    void Loading_spinning_stick(int sleepTime)
    {
        printf("\b\\");
        Sleep(sleepTime);
        printf("\b|");
        Sleep(sleepTime);
        printf("\b/");
        Sleep(sleepTime);
        printf("\b-");
        Sleep(sleepTime);
    }
    void Loading_line(int sleepTime) 
    {
        ///
        /// надо сделать линию прогресса, которая постепенно заполняется
        ///
         
    }
    
private:

};


    class Menu
    {
    private:
        
    public:
        Loading_and_others_functions l;
        int Num = 0; // номер нажатой клавиши 
        int Punckt = 0; // пункты 1-5
        void draw(int num)
        {
    
            switch (num)
            {
            case 80: // стрелка вниз
                if (Punckt >= 6) Punckt = 1;
                else Punckt++;
                break;
            case 72: // стрелка вверх
                if (Punckt <= 1) Punckt = 6;
                else Punckt--;
                break;
            default:
                break;
            }
            // рисуем менюшку
            system("cls");
            system("color 2");
            //printf("\n\n\n\n\n\n\n\n\n\n");        
            // выводит все пункты меню
            gotoxy(With / 2 - 11, Hight / 2 - 6); // перемещает курсор в центр консоли и смещает так, что бы менюшка была по центру
            if (Punckt == 1) printf("Таблица\n");
            else             printf("Таблица\n"); 
            gotoxy(With / 2 - 11, Hight / 2 - 5);
            if (Punckt == 2) printf("График\n");
            else             printf("График\n");
            gotoxy(With / 2 - 11, Hight / 2 - 4);
            if (Punckt == 3) printf("Уравнение\n");
            else             printf("Уравнение\n");
            gotoxy(With / 2 - 11, Hight / 2 - 3);
            if (Punckt == 4) printf("Интеграл\n");
            else             printf("Интеграл\n");
            gotoxy(With / 2 - 11, Hight / 2 - 2);
            if (Punckt == 5) printf("Об авторе\n");
            else             printf("Об авторе\n");
            gotoxy(With / 2 - 11, Hight / 2 - 1);
            if (Punckt == 6) printf("Выход\n");
            else             printf("Выход\n");
    
    
           // выводит крутящуюся шнягу у пункта
            if (Punckt == 1) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 6); // перемещаемся к 1 пункту и на 2 символа левее
                l.Loading_spinning_stick(70);
                gotoxy(0, 0);
                printf(" "); // это надо для того что бы курсор все таки переместился, иначе он остается на месте
            }
            //else             
            else if (Punckt == 2) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 5); // перемещаемся к 2 пункту и на 2 символа левее            
                l.Loading_spinning_stick(70);
                gotoxy(0, 0);
                printf(" ");
            }
            //else             
            else if (Punckt == 3) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 4); 
                l.Loading_spinning_stick(70);
                gotoxy(0, 0);
                printf(" ");
            }
            //else             
            else if (Punckt == 4) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 3); 
                l.Loading_spinning_stick(70);
                gotoxy(0, 0);
                printf(" ");
            }
            //else             
            else if (Punckt == 5) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 2); 
                l.Loading_spinning_stick(70);
                gotoxy(0, 0);
                printf(" "); 
            }
            //else             
            else if (Punckt == 6) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 1); // перемещаемся к последнему пункту и на 2 символа левее
                l.Loading_spinning_stick(70);
                gotoxy(0, 0);
                printf(" ");
            }
            //else             
        }
    };
    class Table  // таблица 1
    {
    private:
        // тута переменные
        
       // double stolb1[20];
       // double stolb2[20];
        int count = 0; // просто счетчик
        double min1 = INT_MAX; // соответственно минимум
        double max1 = INT_MIN; // максимум
        double min2 = INT_MAX;
        double max2 = INT_MIN;

    public:
        double count_V_1(double num) { // первое уравнение
            return sqrt(num * num * num * num + 4.0);
        }

        double count_V_2(double num) { // второе уравнение
            return pow(e, -(num + 5.0));
        }
    
        const int n = 20; // колличество итераций
        const double a = -Pi; // от куда
        const double b = Pi; // до куда
        double razn = 2 * Pi / n; // длинна самой итерации
      /* void draw() // функция воспроизвадимая в методе main 
        {
            system("cls");
            printf("Тут могла быть ваша таблица\n\n");
            for (double i = a; i < b; i += razn) // i это собственно х который мы должны подставить в уравнение
            {
                stolb1[count] = count_V_1(i);
                stolb2[count] = count_V_2(i);
                count++;
                //printf("%4.3lg %4.3lg\n",count_V_1(i),count_V_2(i));
               
                // потом отоюрать индексы минимума и максимума
                // и при выводе на экран в цикле поменять цвет
               
                // а еще нормально отрисовать таблицу, или спиздить откуда то
            }
            for (int i = 0; i < n; i++) 
            {
                if (stolb1[i] <= min1)
                    min1 = stolb1[i];
                if (stolb1[i] >= max1)
                    max1 = stolb1[i];
                
                if (stolb2[i] <= min2)
                    min2 = stolb2[i];
                if (stolb2[i] >= max2)
                    max2 = stolb2[i];
            }
            for (int i = 0; i < n; i++)  // просто перекрашивает минимум и максимум в таблице в разные цвета
            {
                if (stolb1[i] == min1) 
                {
                    //system("color 3");
                    printf("\x1b[32m%4.3lg\x1b[0m ", stolb1[i]);
                    //system("color 2");
                }
                else if (stolb1[i] == max1) 
                {
                    //system("color 1");
                    printf("\x1b[31m%4.3lg\x1b[0m ", stolb1[i]);
                    //system("color 2");
                }
                else
                    printf("%4.3lg ", stolb1[i]);
                if (stolb2[i] == min2)
                {
                    //system("color 3");
                    printf("\x1b[32m%4.3lg\x1b[0m\n", stolb2[i]);
                    //system("color 2");
                }
                else if (stolb2[i] == max2)
                {
                    //system("color 1");
                    printf("\x1b[31m%4.3lg\x1b[0m\n", stolb2[i]);
                    //system("color 2");
                }
                else
                    printf("%4.3lg\n", stolb2[i]);

            }
        }
        */
        void tablica() // отрисовка таблицы
        {
            system("cls");
            system("color 4"); //Color of text
            int x2 = 5, y2 = 0; //x2,y2 - coordinates of position the table
            double F1[20], F2[20], x, x1[20], minF1 = INT_MAX, maxF1 = INT_MIN, minF2 = INT_MAX, maxF2 = INT_MIN;
            
            x = x1[0] = a;
            gotoxy(x2, y2);
            printf(" ______________________________\n");
            gotoxy(x2, y2 + 1);
            printf("| I |    X   |Функция1|Функция2| \n"); //drawing the table
            gotoxy(x2, y2 + 2);
            printf("|___|________|________|________|\n");
            for (int i = 0; i < n; i++) {
                F1[i] = count_V_1(x); //Funtion #1
                F2[i] = count_V_2(x); //Function #2
                x1[i] = x;
                x += razn;
            }
            for (int i = 0; i < n; i++) { //seeking min and max of functions
                minF1 = min(F1[i], minF1);
                maxF1 = max(F1[i], maxF1);
                if (F2[i] != -INFINITY) {
                    minF2 = min(F2[i], minF2);
                }
                maxF2 = max(F2[i], maxF2);
            }

            for (int i = 1; i <= n; i++) {
                gotoxy(x2, y2 + 2 + i);
                SetConsoleTextAttribute(hStdOut, 4);
                printf("|%3d|%8.3f|", i, x1[i - 1]);
                if (F1[i - 1] == minF1) {
                    SetConsoleTextAttribute(hStdOut, 1);
                    printf("%8.4f", F1[i - 1]);
                }
                else if (F1[i - 1] == maxF1) {
                    SetConsoleTextAttribute(hStdOut, 2);
                    printf("%8.4f", F1[i - 1]);
                }
                else
                {
                    SetConsoleTextAttribute(hStdOut, 4);
                    printf("%8.4f", F1[i - 1]);
                }
                SetConsoleTextAttribute(hStdOut, 4);
                printf("|");
                if (F2[i - 1] == minF2) {
                    SetConsoleTextAttribute(hStdOut, 1);
                    printf("%8.4f", F2[i - 1]);
                }
                else if (F2[i - 1] == maxF2) {
                    SetConsoleTextAttribute(hStdOut, 2);
                    printf("%8.4f", F2[i - 1]);
                }
                else
                {
                    if (F2[i - 1] == -INFINITY) {
                        SetConsoleTextAttribute(hStdOut, 4);
                        printf("%8s", "ERROR");
                    }
                    else {
                        SetConsoleTextAttribute(hStdOut, 4);
                        printf("%8.4f", F2[i - 1]);
                    }
                }
                SetConsoleTextAttribute(hStdOut, 4);
                printf("|\n");
            }
            gotoxy(x2, y2 + 3 + n);
            cout << "|___|________|________|________| \n";


            gotoxy(48, 7);
            cout << "Таблица иттераций:";
            gotoxy(44, 9);
            cout << "В таблице представлены значения функций:";            
            gotoxy(44, 11);
            cout << "Функция 1: (x^4 + 4)^1/2";
            gotoxy(44, 12);
            cout << "Функция 2: e^-(x+5)";
            gotoxy(44, 13);
            cout << "Интервал функций: [-П,П]";
            gotoxy(44, 15);
            cout << "Синим цветом отмечены минимальные значения функций";
            gotoxy(44, 16);
            cout << "Зеленым цветом отмечены максимальные значения функций";
        }
    };
    class Graf //график 2
    {
    private:
        Table t;
        const int d = 400, k = 50, x0 = 500, y0 = 400, c = 500; 
        // d - смещение по оси у графика
        // с - смещение по оси хграфика
        // х0 - смещение ццифорок
        // у0 - смещение цифарок
        void grid() // отрисовывает сетку координат
        {
            HWND hwn = GetConsoleWindow();
            COLORREF lineColor = RGB(0, 0, 0);
            HDC hdc = GetDC(hwn);
            
            // d = 350 - good. Grafic is upper because that better looking functions
            SelectObject(hdc, CreatePen(0, 1, RGB(255, 255, 255)));
            MoveToEx(hdc, 0, d, NULL);
            LineTo(hdc, c * k, d);
            MoveToEx(hdc, c, 0, NULL);
            LineTo(hdc, c, 3 * d);
            for (int i = 0; i < 30; i++) {
                MoveToEx(hdc, x0 - 10, y0 - k * i, NULL);
                LineTo(hdc, x0 + 10, y0 - k * i);
                MoveToEx(hdc, x0 - 10, y0 + k * i, NULL);
                LineTo(hdc, x0 + 10, y0 + k * i);
                MoveToEx(hdc, x0 + k * i, y0 - 10, NULL);
                LineTo(hdc, x0 + k * i, y0 + 10);
                MoveToEx(hdc, x0 - k * i, y0 - 10, NULL);
                LineTo(hdc, x0 - k * i, y0 + 10);
                string s = to_string(i);
                LPCWSTR w;
                wstring ste = wstring(s.begin(), s.end());
                w = ste.c_str();
                if (i < 10) { // Drawing marks
                    TextOut(hdc, x0 - 10, y0 - k * i, w, 1);
                    TextOut(hdc, x0 + k * i, y0 + 10, w, 1);
                }
                else {
                    TextOut(hdc, x0 - 10, y0 - k * i, w, 2);
                    TextOut(hdc, x0 + k * i, y0 + 10, w, 2);
                }
                LPCWSTR w1 = L"5-3cos(x)";
                LPCWSTR w2 = L"sqrt(e^x - 1)";
                //TextOut(hdc, 100, 80, w1, 11);
                //TextOut(hdc, 300, 60, w2, 15); // drawing eqution
            }
        }
        // тута переменные
    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
            system("cls");
            //printf("Тут мог быть ваш график");
            HWND hwn = GetConsoleWindow();
            COLORREF lineColor = RGB(0, 0, 0);
            HDC hdc = GetDC(hwn);
            
            // d = 350 - good. Grafic is upper because that better looking functions

            const int n = 4000; // количество точек? мбмб
            long double F1[n], F2[n], x1[n], x, dx = t.razn*0.01, a = t.a, b = t.b, 
                minF1 = 20000, maxF1 = -20000, minF2 = 20000, maxF2 = -20000;
            x = a-5; // расчет начинается с -Pi по Pi и графики отрисовываются в этом отрезке
            //drawing both funtion
            grid();
            for (int i = 0; i < n; i++) {
                F1[i] = t.count_V_1(x);//Function of Grafic #1
                F2[i] = t.count_V_2(x);//Function of Grafic #2
                x1[i] = x;
                x += dx;
            }
            for (int i = 0; i < n; i++) { // тут как я понял рисуется график
                SetPixel(hdc, c + k * x1[i], d - k * F2[i], RGB(64, 224, 208));
                MoveToEx(hdc, c + k * x1[i], d - k * F2[i], NULL);
                SetPixel(hdc, c + k * x1[i], d - k * F1[i], RGB(0, 255, 127));
                MoveToEx(hdc, c + k * x1[i], d - k * F1[i], NULL);
            }
        }
    };
    class Yravn //уравнение 3
    {
    private:
        // тута переменные
    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
            system("cls");
            printf("Тут могло быть ваше уравнение");
        }
    };
    class Integral // интеграл 4
    {
    private:
        // тута переменные
    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
            system("cls");
            printf("Тут мог быть ваш интеграл");
        }
    };
    class Author // автор 5
    {
    private:
        // тута переменные
    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
            system("cls");
            printf("Тут могла быть ваша информация об авторе");
        }
    };



int main()
{
    //system("color 2");
    setlocale(LC_ALL, "rus");
    ShowCursor(FALSE);
    Loading_and_others_functions IDontKnow;
    Menu menu;
    Table tabl;
    Graf graf;
    Yravn yravn;
    Integral integ;
    Author author;
    gotoxy(60,15);
    IDontKnow.Loading_title(3,70);
    menu.draw(menu.Num);
    
    while (true)
    {
       
       menu.Num = _getch();
       menu.draw(menu.Num);        
        if (menu.Num == 13) // нажатие энтера
        {
            switch (menu.Punckt)
            {
            case 1:
                // функция таблицы после нажатия энтер и остальное так же
                //printf("1");
                
                tabl.tablica();
                break;
            case 2:
                //printf("2");
                // функция графикa
                
                graf.draw();
                break;
            case 3:
                //printf("3");
                // функция уравнения
                
                yravn.draw();
                break;
            case 4:
                //printf("4");
                // функция интеграла
                
                integ.draw();
                break;
            case 5:
                //printf("5");
                // функция автора
                
                author.draw();
                break;
            case 6:
                //printf("5");
                // функция автора

                exit(0);
                break;
            default:
                break;
            }
        }
        else if (menu.Num == 27) menu.draw(menu.Num); // нажатие ескейпа возвращает к менюшке        
    }         
}
