﻿#define CLS system("cls")
#include <iostream>
#include <Windows.h>
//#include <math.h>
//#include <stdio.h>
#include <conio.h>
#include <string>
//#include <stdio.h>
//#include <cmath>
///Менюшка разделена по пунктам
///Она переключается как стрелосками там и колесиком мыши
/// нажатие левой кнопки мыши = энтеру
/// эскейп = выход или назад

using namespace std;
double Pi = 3.1415926535; 
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwnd = GetConsoleWindow(); //Descripter of Window
HDC dc = GetDC(hwnd);//Device context - for drawing
const int Hight = 30; // Высота консоли
const int With = 120; // Ширина консоли

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}//Moving carriage to coordinates (x,y)

void ConsoleCursorVisible(bool show, short size) // единственная функция которая реально убирает курсор
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
} //Visible of Console Cursor

class Loading_and_others_functions
{
private:
    void scan(int s = 2, int PointWidth2 = 10)
    {
        ConsoleCursorVisible(FALSE, 1);
        int PointWidth1 = 0, PointHigh1 = 0, PointHigh2 = 20;
        int x = 0, y = 0, N = 1450, R = 63, G = 6, B = 70; // RGB is color, x,y - coordination
        COLORREF rgb = RGB(R, G, B);
        for (int i = 0; i < N; i += s)
            for (int j = 0; j < N; j += s)
            {
                //Sleep(1);
                if (true)
                {
                    SelectObject(dc, GetStockObject(DC_BRUSH));
                    SetDCBrushColor(dc, rgb);
                    Ellipse(dc, PointWidth1 + j, PointHigh1 + i - j, PointWidth2 + j, PointHigh2 + i - j);
                }
            }
    }

    void scanG(int s = 2, int PointWidth2 = 10)
    {
        ConsoleCursorVisible(FALSE, 1);
        int PointWidth1 = 0, PointHigh1 = 0, PointHigh2 = 20;
        int x = 0, y = 0, N = 1450, R = 0, G = 255, B = 0; // RGB is color, x,y - coordination
        COLORREF rgb = RGB(R,G,B);
        for (int i = 0; i < N; i += s)
            for (int j = 0; j < N; j += s)
            {
                //Sleep(1);
                if (true)
                {
                    SelectObject(dc, GetStockObject(DC_BRUSH));
                    SetDCBrushColor(dc, rgb);
                    Ellipse(dc, PointWidth1 + j, PointHigh1 + i - j, PointWidth2 + j, PointHigh2 + i - j);
                }
            }
    }

    void pizzaDraw(int r = 20000, int sleepTime = 25)
    {
        ConsoleCursorVisible(FALSE, 1); // на всякий пусть будет
        int PointWidth1 = 0, PointHigh1 = 0,   //(х,у) верхнего левого угла
            PointWidth2 = 10, PointHigh2 = 10, //(х,у) нижнего правого угла
            s = 7, // ход переменных в цикле
            x = 0, y = 0, // пусть будут
            N = 1450 / 2, // размер окна?
            R = 63, G = 15, B = 80, // RGB is color, x,y - coordination
            count = 220, // нужен, для смещения круга от центра осей к центру окна по всем координатам
            countOnlyX = 250; //смещения круга только по Х
        COLORREF rgb = RGB(R, G, B);

        for (int i = 0; i < N; i += s)
            for (int j = 0; j < N; j += s)
            {
                //Sleep(1);
                if (i * i + j * j <= r && i * i + j * j >= r - 8000)
                {
                    Sleep(sleepTime);

                    SelectObject(dc, GetStockObject(DC_BRUSH));
                    SetDCBrushColor(dc, rgb);
                    Ellipse(dc,  // правая нижняя четверть
                        i + count + PointWidth1 + countOnlyX,  //(х,у) верхнего левого угла
                        j + count + PointHigh1,
                        i + count + PointWidth2 + countOnlyX,  //(х,у) нижнего правого угла
                        j + count + PointHigh2);
                    Ellipse(dc, // левая верхняя четверть
                        -i + count + countOnlyX + PointWidth1,	//(х,у) верхнего левого угла
                        -j + count + PointHigh1,
                        -i + count + PointWidth2 + countOnlyX,	//(х,у) нижнего правого угла
                        -j + count + PointHigh2);
                    Ellipse(dc, // хз
                        i + count + PointWidth1 + countOnlyX,	//(х,у) верхнего левого угла
                        -j + count + PointHigh1,
                        i + count + PointWidth2 + countOnlyX,	//(х,у) нижнего правого угла
                        -j + count + PointHigh2);
                    Ellipse(dc, // не помню
                        -i + count + PointWidth1 + countOnlyX,	//(х,у) верхнего левого угла
                        j + count + PointHigh1,
                        -i + count + PointWidth2 + countOnlyX,	//(х,у) нижнего правого угла
                        j + count + PointHigh2);
                    //тут 4 почти одинаковых метода потому что 1 отрисовывает только четверть круга, 
                    //наверное можно сделать так,
                    //что бы один метод все сделал, но мне некогда сейчас это делать
                }
            }
    }

    

public: // надо написать нормальную графическую заставку
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
    void NotIdealFunction()
    {
        scan(3, 10);
        pizzaDraw();
        for (int i = 20000; i <= 72000; i += 8000)
            pizzaDraw(i, 10);
        scanG(1, 10);
    }
    void Loading_line(int sleepTime) 
    {
        ///
        /// надо сделать линию прогресса, которая постепенно заполняется
        ///
         
    }
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
            CLS;
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
    
            int time = 60; // в милисекундах
           // выводит крутящуюся шнягу у пункта
            if (Punckt == 1) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 6); // перемещаемся к 1 пункту и на 2 символа левее
                l.Loading_spinning_stick(time);
                gotoxy(0, 0);
                printf(" "); // это надо для того что бы курсор все таки переместился, иначе он остается на месте
            }
            //else             
            else if (Punckt == 2) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 5); // перемещаемся к 2 пункту и на 2 символа левее            
                l.Loading_spinning_stick(time);
                gotoxy(0, 0);
                printf(" ");
            }
            //else             
            else if (Punckt == 3) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 4); 
                l.Loading_spinning_stick(time);
                gotoxy(0, 0);
                printf(" ");
            }
            //else             
            else if (Punckt == 4) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 3); 
                l.Loading_spinning_stick(time);
                gotoxy(0, 0);
                printf(" ");
            }
            //else             
            else if (Punckt == 5) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 2); 
                l.Loading_spinning_stick(time);
                gotoxy(0, 0);
                printf(" "); 
            }
            //else             
            else if (Punckt == 6) 
            {
                gotoxy(With / 2 - 13, Hight / 2 - 1); // перемещаемся к последнему пункту и на 2 символа левее
                l.Loading_spinning_stick(time);
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
            return pow(exp(1), -(num + 5.0));
        }
    
        const int n = 20; // колличество итераций
        const double a = -Pi; // от куда
        const double b = Pi; // до куда
        double razn = 2 * Pi / n; // длинна самой итерации
     
        void tablica() // отрисовка таблицы
        {
            system("color 2"); //Color of text
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
                SetConsoleTextAttribute(hStdOut, 2);
                printf("|%3d|%8.3f|", i, x1[i - 1]);
                if (F1[i - 1] == minF1) {
                    SetConsoleTextAttribute(hStdOut, 1);
                    printf("%8.4f", F1[i - 1]);
                }
                else if (F1[i - 1] == maxF1) {
                    SetConsoleTextAttribute(hStdOut, 4);
                    printf("%8.4f", F1[i - 1]);
                }
                else
                {
                    SetConsoleTextAttribute(hStdOut, 2);
                    printf("%8.4f", F1[i - 1]);
                }
                SetConsoleTextAttribute(hStdOut, 2);
                printf("|");
                if (F2[i - 1] == minF2) {
                    SetConsoleTextAttribute(hStdOut, 1);
                    printf("%8.4f", F2[i - 1]);
                }
                else if (F2[i - 1] == maxF2) {
                    SetConsoleTextAttribute(hStdOut, 4);
                    printf("%8.4f", F2[i - 1]);
                }
                else
                {
                    if (F2[i - 1] == -INFINITY) {
                        SetConsoleTextAttribute(hStdOut, 2);
                        printf("%8s", "ERROR");
                    }
                    else {
                        SetConsoleTextAttribute(hStdOut, 2);
                        printf("%8.4f", F2[i - 1]);
                    }
                }
                SetConsoleTextAttribute(hStdOut, 2);
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
                LPCWSTR w1 = L"(x ^ 4 + 4) ^ 1 / 2";
                LPCWSTR w2 = L"e^-(x+5)";

                LPCWSTR xS = L"Ось Х";
                LPCWSTR yS = L"Ось Y";

                TextOut(hdc, 100, 80, w2, 8);
                TextOut(hdc, 250, 60, w1, 19); 

                TextOut(hdc, 900, 360, xS, 5);
                TextOut(hdc, 430, 30, yS, 5); 
            }
        }
        // тута переменные
    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
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
    { // 0.5 + cos(x) -2x*sin(x) = 0
      // интервал а и б рассчитать самостоятельно
    private:
        // тута переменные
        double e = 0.001, a = -100, b = 100; // e - точность [a,b] отрезок в котором проводим табуляцию
        double x[100]; // сначала заполняем массив значениями а потом выводим
        int count = 0; // счетчик
        
        double f(double x) // функция 6 вариант
        {
            return 0.5 + cos(x) - 2 * x * sin(x);
        }
    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
                       
           // printf("Тут могло быть ваше уравнение");
            printf("\tРешение уравнения\n\tОтрезок [-100,100]\n\tС точностью: 0.001\n\tКорни уравнгения:\n\n\n");
            for (double i = a; i < b; i += e)  // в отрезке от а до б с точностью е находятся корни функции
                if (abs(f(i)) / e < 10)
                    x[count] = i, count++;
                        
            for (int i = 0; i < count; i++)             
                if (i % 2 == 0) printf("\t%3.03f\t", x[i]);
                else printf("%3.3f\n", x[i]);
            
            //printf("%f", x);
            count = 0;
        }
    };
    class Integral // интеграл 4
    {
    private:
        // тута переменные
        double f(double x) {
            return cos(x)/(x*x+1);
        }// Function of Integral
        double trapezoidalIntegral(double a, double b, int n) {
            const double width = (b - a) / n;
            double trapezoidal_integral = 0;
            for (int i = 0; i < n; i++) {
                const double x1 = a + i * width;
                const double x2 = a + (i + 1) * width;

                trapezoidal_integral += 0.5 * (x2 - x1) * (f(x1) + f(x2));
            }
            return trapezoidal_integral;
        } //Solving the Integral by the trapezoid method    
        double rectangelIntegral(double a, double b, double n) {
            double h = (b - a) / n;
            double sum = f(a) + f(b);
            int k;
            for (int i = 1; i <= n - 1; i++) {
                k = 2 + 2 * (i % 2);
                sum += k * f(a + i * h);
            }
            sum *= h / 3;
            return sum;
        } // Sympson's method // not need
    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
            //printf("Тут мог быть ваш интеграл");

            gotoxy(6, 1);
            printf("Решение определенного интеграла");
            gotoxy(4, 3);
            printf("Предложенный интеграл: cos(x) / (x*x+1) ");
            gotoxy(4, 4);
            printf("Верхний и нижний пределы соответственно 5 и 2");         
            gotoxy(4, 5);
            printf("Цена приращения: 3/200");
            gotoxy(4, 6);
            printf("Точность определения: 0.001");
            gotoxy(4, 7);
            printf("Результат, методом трапеций: %.5f", trapezoidalIntegral(2, 5, 200));
            gotoxy(4, 8);
            printf("Результат, методом прямоугольников: %.5f", rectangelIntegral(2, 5, 200));
        }
    };
    class Author // автор 5
    {
    private:
        // тута переменные
        string s1 = "Выполнил расчетно графическую работу";
        string s2 = "Студент группы ПИН-221";
        string s3 = "Кафедры Автоматизированные системы обработки информации и устройств";
        string s4 = "Факультета информационных технологий и компьютерных систем";
        string s5 = "Омского Государственного технического университета";
        string s6 = "Шадчнев Георгий Алексеевич";
        string s7 = "Дата выполнения работы: с 01.03.23 по 15.04.23";

    public:
        // тута главная функция или вывода или просто подсчета
        void draw()
        {
            //printf("Тут могла быть ваша информация об авторе");
            gotoxy(With / 2 - s1.length()/2, Hight / 2 - 7);
            cout << s1;
            gotoxy(With / 2 - s2.length()/2, Hight / 2 - 6);
            cout << s2;
            gotoxy(With / 2 - s3.length()/2, Hight / 2 - 5);
            cout << s3;
            gotoxy(With / 2 - s4.length()/2, Hight / 2 - 4);
            cout << s4;
            gotoxy(With / 2 - s5.length()/2, Hight / 2 - 3);
            cout << s5;
            gotoxy(With / 2 - s6.length()/2, Hight / 2 - 2);
            cout << s6;
            gotoxy(With / 2 - s7.length()/2, Hight / 2 - 1);
            cout << s7;      
        }
    };



int main()
{
    //system("color 2");
    ConsoleCursorVisible(FALSE, 2);
    setlocale(LC_ALL, "rus");
    Loading_and_others_functions IDontKnow;
    Menu menu;
    Table tabl;
    Graf graf;
    Yravn yravn;
    Integral integ;
    Author author;   
    gotoxy(60,15);
    IDontKnow.Loading_title(3,70); // чёто типо анимации
    IDontKnow.NotIdealFunction();
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
                CLS;
                graf.draw();
                break;
            case 3:
                //printf("3");
                // функция уравнения
                CLS;
                yravn.draw();
                break;
            case 4:
                //printf("4");
                // функция интеграла
                CLS;
                integ.draw();
                break;
            case 5:
                //printf("5");
                // функция автора
                CLS;
                author.draw();
                break;
            case 6:
                //printf("5");
                // функция автора
                CLS;
                exit(0);
                break;
            default:
                break;
            }
        }
        else if (menu.Num == 27) menu.draw(menu.Num); // нажатие ескейпа возвращает к менюшке        
    }         
}