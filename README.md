# Работа на ЭВМ и программирование, семестр 4

Материалы занятий.

# Задачи

Общее количество баллов: 95,
задачами и подзадачами по 1-2 балла
можно набрать порядка 45 баллов.

1. (1 балл+) Дописать тесты до уровня покрытия,
близкого к 100% строк всех файлов в каталоге `src`,
и сохранить изменения в репозиторий.
Далее по материалу каждого из следующих занятий
аналогичный набор изменений
с тестами нового/изменённого кода
с уровнем покрытия 100% строк — по 1 дополнительному баллу.

2. (1 балл+) Переписать код на язык C++
с использованием объектно-ориентированного программирования,
сохранить новый код в репозиторий.
Аналогично задаче 1.1 — по 1 дополнительному баллу
за ту же работу с материалами следующих занятий.
Можно использовать другой язык программирования, отличный от C,
но в общей сложности за эту задачу
можно получить не более 1 балла за занятие.

3. (2 балла) Добавить обработку файлов из аргументов командной строки.
Через аргументы командной строки можно передать имена файлов.
Нужно сделать, чтобы при наличии аргументов командной строки
интепретатор последовательно считывал эти файлы,
а затем, если последним аргументом указан "-",
переходил бы к чтению из стандартного ввода.
Если аргументов нет, считываем из стандартного ввода.

4. (1-4 баллов) Добавить слово `key`,
которое считывает следующий символ из forth->input
и кладёт его на стек.
- +1 балл: добавить "комментарии до конца строки".
    В Forth они задаются символом `\`
- +2 балла: добавить "блочные комментарии".
    В Forth они задаются сбалансированными парами скобок:
```
( это комментарий ( ) 
    и это всё ещё комментарий,
    в отличие от C) \ а здесь предыдущий комментарий уже закончился
```

5. (3 балла) Заменить assert на вывод ошибки и выход в интерактивный режим.

6. (2 балла) Добавить внутренний режим профилирования по счётчикам
(сколько раз вызывано каждое слово)
и слова для вывода результатов
(по одному слову и по всем словам с сортировкой по количеству).

7. (2 балла) Добавить внутренний режим профилирования по таймеру
(аналогично предыдущему, но считается время).

8. (1 балл) Задача: хранить флаги в старших битах длины. Оценить влияние на производительность.

9. (1 балл) Написать декомпилятор: слово see на языке C, которое по текущему слову выводит слова в его составе (или сообщает, что это codeword ивыводит адрес).

10. (2 балла) Написать слова `save` и `load` на языке C, которые по имени файла (в следующем слове) сохраняют/загружают в текстовом виде все составные слова, которые определены в системе в настоящее время. Пример: `save my-system.fth`, `load my-system.fth`.

11. (4 балла) Добавить immediate-слова `break` и `unbreak` — установка и снятие точки останова на заданном слове. Команда `break myword` «перехватывает» все вызовы `myword` (в том числе в уже скомпилированном коде) и возвращает вас в интерактивный режим. Команда `unbreak myword` отменяет действие `break`. Команды `break` и `unbreak` должны быть идемпотентны.

12. (4 балла) Сделать 32-битный forth: заменить указатели на смещения относительно memory. Оценить влияние на производительность.

13. (4 балла) Сделать 16-битный forth: заменить указатели на смещения, выравненные по модулю 2 (1 бит — таким образом, адресуется 17 бит или 128КБайт, чего вполне достаточно для наших задач). Оценить влияние на производительность.

14. (6 баллов) Убрать флаг компилируемых слов — сделать так, чтобы компилируемые слова тоже начинались с функции-обработчика (это называется direct threaded code, наш вариант — indirect threaded code). Получится ли избавиться от стоп-слова, добавляя в стек адресов возврата интерпретатор? Как в этом случае реализовать выход в интерактивный режим?

15. (2 + 5 баллов) Вместо «процессорных» операций branch, branch0,
    которые существенно используют смещения,
    условные операторы и циклы можно было бы реализовать с использованием следующих,
    более «высокоуровневых» слов:

    - latest: возвращает указатель на latest в forth
    - recurse: immediate-слово, которое в режиме компиляции записывает вызов определяемого в настоящее время слова (рекурсивный вызов)
    - exec — слово, которое выполняет вызов по адресу на вершине стека (т.е. `latest , ' exec ,` , вообще говоря, то же самое, что и recurse)
    - lambda — слово, которое создаёт слово без имени.

    В этом случае одно слово для пользователя может представляться несколькими словами внутри машины.
    Например, "IF A ELSE B THEN" (на стеке — условие, в зависимости от которого IF выбирает ветвь)
    может компилироваться в следующий код:

    ```
    DUP ' A AND ( 0, если условие ложно, и указатель на A, если истинно )
    NOT ' B AND (0, если условие истинно, и указатель на B, если ложно)
    OR EXEC (вызываем одно из A, B).
    ```

    На 2 балла нужно написать только вышеперечисленные базовые слова
    и программы, иллюстрирующие их работу.
    На 5 баллов — написать на Forth с использованием этих слов 
    управляющие слова `IF`, `THEN`, `ELSE`, `BEGIN`, `UNTIL`, `WHILE`, `REPEAT`, `DO`, `LOOP`.

16. (6 баллов) С помощью слов `branch`, `branch0` и стека вызовов
реализовать обработку исключений
(можно смотреть существующие реализации:
https://github.com/AlexandreAbreu/jonesforth/blob/master/jonesforth.f#L1193 ).
А именно, нужны слова:
TRY{ ... CATCH ... }TRY
и RAISE.
RAISE берёт аргумент с вершины стека как код исключения. При вызове RAISE где-то внутри TRY-блока (в том числе, из другого вызванного слова) управление должно быть передано в CATCH с кодом исключения. Если RAISE не вызван, CATCH-блок пропускается.

17. (6 баллов) При наличии арифметических операций, если добавить 1 новое слово:
    - `c,` (`emit-byte`) — записать 1 байт по указателю `memory_free` и сдвинуть его на 1; отличается от слова `,` тем, что последнее записывает 1 машинное слово (8 или 4 байт)
    — и дать возможность (аналогично задаче 14) выполнять слова, написанные в машинном коде,
    наша реализация Forth станет полностью самодостаточной.
    Мы сможем написать слова для любых машинных инструкций ( https://software.intel.com/en-us/articles/intel-sdm , краткая справка по командам: https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-sdm-combined-volumes-2a-2b-2c-and-2d-instruction-set-reference-a-z  ),
    или даже написать ассемблер на Forth ( https://github.com/AlexandreAbreu/jonesforth/blob/master/jonesforth.f#L1628 ).
    Задача: реализовать слово `c,` и выполнение слов в машинном коде,
    продемонстрировать на какой-нибудь арифметической инструкции.


18. (1-5 баллов) Инфиксная нотация.

    Слово `word` позволяет считывать следующее слово.
    С помощью этого слова можно писать `immediate`-слова,
    реализующие инфиксный (привычный нам на примере математических выражений) синтаксис.
    Слово должно сопровождаться примерами его использования.
    Если слово реализовано на C, нужно добавить тесты.
    Нужно написать инфиксные слова:

    - (1 балл) `<-` : на стеке адрес, следующее слово показывает как положить на стек значение.
        Вызов `here <- 0` должен быть эквивалентен `here 0 swap !`
    - (1 балл) `+`, `-` : инфиксное сложение и вычитание (`a + b` соответствует `a b +`)
    - (2 + 1 балл) `*`, `/`: инфиксное умножение и деление,
        с учётом приоритета операторов
        (`a + b * c` в инфиксной записи должно соответствовать,
        например, `a b c * +` в стековой).

19. (2-3 балла) Добавить слова `hex` и `dec` (2 балла), `bin` и `oct` (+ 1 балл),
    которые меняют основание системы счисления,
    в котором считываются и выводятся числа.

    Пример использования:
    
    ```
    (ввод) hex A 10 show
    (вывод) A 10
    (ввод) dec show
    (вывод) 10 16
    ```

    Хорошо сочетается с задачей 17.

20. (до 12 баллов; максимум, на мой взгляд, недостижим,
    но если получится — «автомат»)
    Уменьшить количество слов, которые реализованы на языке C
    (перенести больше слов в стандартную библиотеку Forth).
    Сейчас на языке C реализованы 42 слова.
    Реализацию части этих слов можно перенести в Forth.
    За каждые 3 слова, которые удалены из `words.c` и перенесены в `stdlib.fth` — 1 балл.
    Минимальный набор может состоять совсем не из тех слов,
    которые сейчас есть в `words.c` (см., например, задачу 15),
    но объём кода на языке C в итоге не должен увеличиться
    (ни в строках кода, ни в байтах, ни в количестве объявленных функций).

21. (2 балла) Реализовать интерактивный режим с использованием библиотеки readline (чтобы работали стрелки и история).

22. (1 + 1 балл) Баллы за демонстрацию скорости набора текста слепым десятипальцевым методом (200 знаков в минуту на русском языке с ошибками < 3% и 180 знаков в минуту на английском языке с ошибками < 4%, соответственно).

23. (1 + 2 балла) Реализовать на Python решение задачи «интегральное уравнение с параметром» из списка задач второго семестра. Дополнительные баллы — за сопровождающие графики в Jupyter Notebook.

24. (1 + 2 балла) Реализовать на Python решение задачи «ряд Тейлора» из списка задач второго семестра. Дополнительные баллы — за сопровождающие графики в Jupyter Notebook.

25. (1 + 1 + 2 балл) Реализовать на Python решение задачи на работу с матрицами из списка задач второго семестра. Дополнительный балл — за реализацию с использованием NumPy. Дополнительные 2 балла — за сравнение производительности трёх вариантов (ваше исходное решение на C, решение на Python, решение на Python с NumPy). Если решение на C не сохранилось, за сравнение производительности Python vs NumPy дополнительно даётся 1 балл.

26. (1 балл) Реализовать на Python пирамидальную сортировку.

27. (1 балл) Реализовать на Python алгоритмы сортировки QuickSort и Bubble sort.

28. (1 балл) Реализовать на Python алгоритм Дейкстры поиска кратчайшего пути в графе.

29. (3 + 1 + 1 баллов) Реализовать многопоточное умножение матрицы на вектор.
Программа должна принимать с командной строки размер матрицы и количество потоков,
генерировать матрицу и выполнять умножение.
Дополнительный балл: проанализировать производительность с разным количеством потоков.
Дополнительный балл: реализация на C++ с использованием std::threads, а не на pthreads.
Но рекомендуется использовать pthreads.

30. (3 балла) Реализовать многопоточный BBP-алгоритм вычисления цифр числа π.

<!--31. (4 балла) Реализовать work-stealing-queue и продемонстрировать его работоспособность.-->

31. (5 баллов) Добавить в forth команду parallel, которая считывает со стека число n и n указателей на слова, выполняет слова параллельно и записывает результаты на стек в правильном порядке.

<!-- 33. (многопоточность с вводом-выводом?) -->

# Заметки

## typedef — задать псевдоним для типа.

https://en.cppreference.com/w/c/language/typedef

```c
typedef исходный-тип псевдоним;
// cell — это то же самое, что и intptr_t
typedef intptr_t cell;
```

Для указателей на функции синтаксис немного другой:

```c
typedef тип-результата (*псевдоним)(аргументы);
```

См. также: https://cdecl.org/

Но эта программа не работает на примере из кода:

```c
typedef void (*function)(struct forth *forth);
```

Доп. задание (7 баллов): исправить программу cdecl и отправить исправления автору.

## enum — перечисление целочисленных констант

https://en.cppreference.com/w/c/language/enum

```c
enum forth_result {
    FORTH_OK,
    FORTH_EOF,
    FORTH_WORD_NOT_FOUND,
    FORTH_BUFFER_OVERFLOW,
};
```
Определяет 4 константы. Первая: `FORTH_OK = 0`, далее — последовательно увеличивается на 1. 

# Проект

Для сборки: `make`

В каталоге build появится исполнимый файл `cforth`,
запустить его можно командой `build/cforth`. 
Выйти — по `Ctrl+C` или `Ctrl+D`.

Для запуска тестов: `make check`

В тестах используется библиотека minunit: https://github.com/siu/minunit

Для анализа покрытия кода тестами: `make coverage`

# Команды

В каталоге `bin` находятся команды,
которые предназначены только для использования
в дисплейных классах.

## Запуск редактора VSCodium

    ./bin/codium.sh .

Скачивает во временный каталог в оперативную память
переносимую версию редактора VSCodium,
устанавливает несколько расширений
и запускает его в текущем каталоге.

На других компьютерах этот редактор
можно скачать и установить обычным способом.

Неофициальная сборка без телеметрии,
распространяемая по свободной лицензии:

https://vscodium.com/

Официальная сборка VSCode от Microsoft
с телеметрией и проприетарной лицензией:

https://code.visualstudio.com/

Команда устанавливает расширения:

- C/C++
- GitLens

## Запуск анализатора уровня покрытия кода тестами GCovr

    ./bin/gcovr.sh

Документация:
https://gcovr.com/en/stable/

Команда предназначена только для использования в дисплейных классах.
На других компьютерах без дисковой квоты это средство можно установить
командой:

    pip install --user gcovr

После этого в Makefile нужно закомментировать первую строчку
в командах coverage и раскомментировать вторую

    # cd build && ../bin/gcovr.sh -r .. --html --html-details -o coverage.html
	gcovr -r . --html --html-details -o build/coverage.html

Более удобное средство,
которое поддерживает любые компиляторы,
генерирующие отладочную информацию — kcov:
http://simonkagstrom.github.io/kcov/index.html

Для его использования нужно его установить
(с помощью стандартных команд установки
в вашем дистрибутиве Linux / WSL / Homebrew)
и в инструкциях coverage оставить только третью строчку:

    # cd build && ../bin/gcovr.sh -r .. --html --html-details -o coverage.html
	# gcovr -r . --html --html-details -o build/coverage.html
	kcov --include-path=./src build/coverage $<

Kcov можно использовать без флагов CFLAGS_COVERAGE.

## Очистка кэша 

    ./bin/clear-cache.sh

Использовать только в дисплейных классах
в случае, когда исчерпана дисковая квота
(файлы не открываются или не сохраняются).

# Git

## Регистрация и копирование репозитория

Материалы:

- вводный курс (можно смотреть теорию без регистрации):
    https://ru.hexlet.io/courses/intro_to_git
- книга https://www.git-scm.com/book/ru/v2

По-английски:

- http://rogerdudler.github.io/git-guide/ (в стиле презентации — мало текста, много примеров)
- https://www.atlassian.com/git/tutorials
- https://git-scm.com/docs/gittutorial


Основные команды.

Перед первым использованием нужно указать имя и email:

    git config --global user.name "Maxim Krivchikov"
    git config --global user.email "maxim.krivchikov@gmail.com"

Чтобы скачать этот репозиторий:

    git clone https://github.com/maxxk/programming-semester-4.git

Чтобы было удобнее синхронизировать изменения дома,
лучше будет зарегистрироваться на [GitHub], [GitLab], [BitBucket] или другом аналогичном сервисе и скопировать туда репозиторий.

[GitHub]: https://github.com/
[GitLab]: https://about.gitlab.com/
[BitBucket]: https://bitbucket.org/

Удобнее это будет делать на GitHub, т.к. там есть кнопка «Fork» для того, чтобы создать свою копию репозитория.
На GitLab и BitBucket есть кнопки Import в меню Create Repository. Там достаточно вставить URL в форму:

    https://github.com/maxxk/programming-semester-4.git

После того, как вы создадите репозиторий, где-то в правом верхнем углу экрана вы сможете найти URL, по которому можно скачать вашу копию репозитория.

Чтобы в дальнейшем не вводить каждый раз при отправке изменений имя пользователя и пароль, можно добавить авторизацию по SSH-ключам.

Более-менее адекватное краткое описание того, что такое SSH, можно посмотреть здесь: 
- https://docs.microsoft.com/ru-ru/azure/virtual-machines/linux/ssh-from-windows
- https://wiki.archlinux.org/index.php/SSH_keys_(%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9)

Для этого нужно создать ключ на том компьютере, с которого вы хотите открыть доступ (один раз для вашей учётной записи, если будете делать ещё раз, ключ перезапишется и доступ к тем сервисам, на которые вы записали старый ключ, пропадёт).

    ssh-keygen -b 4096 -t rsa

Вывод:

    Generating public/private rsa key pair.
    Enter file in which to save the key (/home/maxxk/.ssh/id_rsa): (оставлям по умолчанию)
    Enter passphrase (empty for no passphrase):
    
На своём личном компьютере я пароль не ввожу, на «общественных» / «рабочих» желательно вводить.

По умолчанию мы генерируем ключ алгоритма RSA. Есть и другие алгоритмы, подробнее на английском: https://security.stackexchange.com/questions/5096/rsa-vs-dsa-for-ssh-authentication-keys/46781#46781



## Работа с изменениями

Все команды выполняются из каталога репозитория

    cd programming-semester-4

Команда для просмотра изменений:

    git status

Добавить изменения в файлах file1, file2 к набору изменений (коммиту):

    git add file1 file2

Можно кратко (но это добавит все файлы из текущего каталога, будьте осторожны):

    git add .

Убрать случайно попавший file3 из набора изменений:

    git reset file3

Запомнить набор изменений с комментарием
«main: исправлено падение при вызове без аргументов»:

    git commit -m "main: исправлено падение при вызове без аргументов"

Или:

    EDITOR=nano git commit

— откроется текстовый редактор, в котором вы должны прокоментировать изменения, сохранить комментарий (Ctrl+O) и выйти (Ctrl+X). Без `EDITOR=nano` вызывается vim. Про vim по-русски: https://ru.wikibooks.org/wiki/Vim . Кратко: по умолчанию редактор в командном режиме, для ввода нужно нажать `i`, для выхода с записью `:wq`, для выхода без записи `:q!`.

Список сохранённых изменений можно посмотреть командой

    git log

Посмотреть, что вы изменили с момента последнего коммита, можно командой

    git diff

Посмотреть, какие изменения были в последнем коммите:

    git diff HEAD^..HEAD

Очень полезная команда по сравнению любых файлов в файловой системе:

    git diff --no-index --word-diff=color file1 file2

## Синхронизация

Отправить на сервер новые наборы изменений:

    git push

Загрузить с сервера новые наборы изменений с других компьютеров:

    git pull

## USB-накопитель

Для синхронизации git-репозиториев
необязательно использовать централизованный сервер.
Копию репозитория можно держать на USB-накопителе.
Но в этом случае редактировать файлы в этой копии вручную нельзя.

Как скопировать новый репозиторий,
который находится в каталоге `~/programming-semester-4`
на внешний накопитель.

1. Перейти в каталог накопителя в терминале. Варианты:
    - набрать в термнале `cd ` с пробелом и
        перетащить каталог накопителя
        из файлового менеджера
        в окно терминала;
    - набрать `cd /run/media/`
        и нажать несколько раз `Tab`,
        чтобы автодополнение предложило нужный каталог;
    - зайти в каталог накопителя в Dolphin,
        вызвать контекстное меню правой кнопкой мыши
        и выбрать
        «Действия → Открыть в терминале / Konsole».

2. В этом примере путь к накопителю будет
    `/run/media/Krivchikov_MA/TRANSCEND/`

3. Скопировать репозиторий и настроить его на отображение актуальных изменений.

        git clone ~/programing-semester-4
        cd programming-semester-4
        git config receive.denyCurrentBranch updateInstead

3. Указать в исходной копии репозитория
    путь к репозиторию на внешнем накопителе
    (`usb` — это метка, можно использовать другую):

        cd ~/programming-semester-4/
        git remote set-url origin /run/media/Krivchikov_MA/TRANSCEND/

Далее для синхронизации изменений можно пользоваться командами, как выше.

Отправить изменения на накопитель:

    git push

Забрать изменения с накопителя:

    git pull

Чтобы скопировать репозиторий с накопителя
достаточно использовать команду:

    git clone /run/media/Krivchikov_MA/TRANSCEND/programming-semester-4/

