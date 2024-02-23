#include "report.h"
#include <fstream>
#include <string>

void Report::get_text(size_t task_num)
{
    Logger::log_current_event(task_num, "Step 1 | Start");

    std::string line;
    std::ifstream in(Filename); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            Text += line;
        }
    }
    else
    {
        printf("Error. Could not open the file \'%s\' to read.\n", Filename.c_str());
        return;
    }
    in.close();

    Logger::log_current_event(task_num, "Step 1 | End  ");
}

void Report::find_subst(size_t task_num)
{
    Logger::log_current_event(task_num, "Step 2 | Start");

    Answer = BM(Text, Substring);

    Logger::log_current_event(task_num, "Step 2 | End  ");
}

void Report::output_res(size_t task_num)
{
    Logger::log_current_event(task_num, "Step 3 | Start");

    // Дамп результатов
    std::ofstream out;          // поток для записи
    std::string out_filename = Filename;
    out.open(out_filename.replace(out_filename.length()-4, 4, "_out.txt"));      // открываем файл для записи
    if (out.is_open())
    {
        out << Filename << ";" << Substring << ";";
        for (auto& elem : Answer)
	        out << elem << ";";
        out << "\n";
    }
    else
    {
        printf("Error. Could not open the file \'%s\' to record the results\n", Filename.c_str());
        return;
    }
    out.close(); 

    Logger::log_current_event(task_num, "Step 3 | End  ");
}

 // Получение расстояния перемещения суффиксного правила
int GoodSuffix(int j, string& pat) {
	int terminal = pat.length() - 1;
	int index = -1;
	j--;
	while (j >= 0) {
		if (pat[j] == pat[terminal]) {
			index = j;
			break;
		}
		else j--;
	}
	return terminal - index;
}


 // Получаем расстояние перемещения правила плохого символа
int BadChar(int j,char temp,string str)
{

	int index = -1;
	for (int i = j - 1; i >= 0; --i)
	{
		if (str[i] == temp)
		{
			index = i;
			break;
		}
	}
	return j - index;
}


vector<int> BM(string source, string target)
{
    vector<int> answer;
	int i = 0, j = 0, soulen = source.length (), tarlen = target.length (); // инициализация
	int badvalue = 0, distance = 0;
	 if (soulen <tarlen) {// Сравните длину
		 //printf ("Длина строки меньше длины поискового запроса \n");
		return answer;
	}

	i = tarlen-1; j = tarlen-1; // совпадение с конца

	while (i < soulen) {
		 if (source [i] == target [j]) {// совпадение символов успешно
			if (j == 0) {
				//printf ("A successful match \n");
				answer.push_back(i);
			}

			i--; j--;
		}
		 else {// Не найдено успешно
			 if (j == tarlen-1) {// Если последний символ не соответствует успешно, "правило плохого символа"
				badvalue = BadChar(j, source[i],target);
				 //cout << "Плохое движение символа: " << badvalue << endl;
				i = i + tarlen - 1 - j + badvalue;
				j = tarlen - 1;
			}
			 else {// имеет суффикс, сравните "правила плохих символов" и "правила суффиксов"
				badvalue = BadChar(j, source[i], target);
				if (badvalue == -1)
				badvalue = target.length();
				distance = badvalue > GoodSuffix(j,target) ? badvalue : GoodSuffix(j, target);
				 //cout << "Good suffix: " << GoodSuffix (j, target) << "\nПлохой символ: " << badvalue << "\nПереместить после сравнения " << distance << endl;
				 i = i + tarlen-1-j + distance; // Обновляем позицию i
				 j = tarlen-1; // Обновляем позицию j
			}
		}
	}
    return answer;
}


void Report::get_text_meassure(size_t task_num)
{
    std::string line;
    std::ifstream in(Filename); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            Text += line;
        }
    }
    else
    {
        cout <<"Error. Could not open the file " << Filename << " to read.\n";
        return;
    }
    in.close();
}

void Report::find_subst_meassure(size_t task_num)
{
    Answer = BM(Text, Substring);
}

void Report::output_res_meassure(size_t task_num)
{
    // Дамп результатов
    std::ofstream out;          // поток для записи
    std::string out_filename = Filename;
    out.open(out_filename.replace(out_filename.length()-4, 4, "_out.txt"));      // открываем файл для записи
    if (out.is_open())
    {
        out << Filename << ";" << Substring << ";";
        for (auto& elem : Answer)
	        out << elem << ";";
        out << "\n";
    }
    else
    {
        cout << "Error. Could not open the file " << Filename << " to record the results\n";
        return;
    }
    out.close(); 
}

