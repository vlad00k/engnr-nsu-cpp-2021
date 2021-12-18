Интрукция по запуску утилиты Hasher:
cmake {-G "something generator if you need"} -S <path-to-source> -B <path-to-build>
cmake --build <path-to-build>
Утилита может считать 2 варианта хеша:
Adler32
Sum64

Утилита принимает имя файла и вариант расчета хеша как аргументы командной строки.

Результат печатается в стандартный поток вывода в шестнадцатеричном виде.

Варианты запуска программы:
./hasher -h - вывести справочную информацию об использовании и завершить работу;
./hasher <filename> -m <mode> - посчитать переданный вариант хеша переданного файла;
./hasher -m <mode> <filename> - посчитать переданный вариант хеша переданного файла;

Где <mode> ∈ { adler32, sum64 }.