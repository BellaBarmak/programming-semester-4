# Работа на ЭВМ и программирование, семестр 4

Материалы занятий.

# Задачи

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

